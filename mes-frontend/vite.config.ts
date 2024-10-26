import { dirname, resolve } from "node:path";
import { fileURLToPath, URL } from "node:url";
import * as fs from "node:fs";

import { upperFirst } from "lodash-es";
import { type UserConfig, type ConfigEnv, defineConfig, loadEnv } from "vite";
import vue from "@vitejs/plugin-vue";
import AutoImport from "unplugin-auto-import/vite";
import Components from "unplugin-vue-components/vite";
import VueRouter from "unplugin-vue-router/vite";
import { VueRouterAutoImports } from "unplugin-vue-router";
import { ElementPlusResolver } from "unplugin-vue-components/resolvers";
import { createHtmlPlugin } from "vite-plugin-html";
import vueDevTools from "vite-plugin-vue-devtools";
import { visualizer } from "rollup-plugin-visualizer";
import { createPlugin, getName } from "vite-plugin-autogeneration-import-file";
import mockDevServerPlugin from "vite-plugin-mock-dev-server";

import { getRouteName } from "./src/plugins/unplugin-vue-router";

/**
 * 用全量导入的方式 获取类型
 * 这些类型不能写成export导入的形式，会导致全局类型声明失效
 *
 * 也可以等效地用 三斜线表达式 实现全量导入
 * <reference types="./types/env.shim.d.ts" />
 */
import "./types/env.shim.d.ts";

// import {} from "@ruan-cat/utils";

const { autoImport } = createPlugin();

const __filename = fileURLToPath(import.meta.url);
const __dirname = dirname(__filename);
function pathResolve(dir: string) {
	const resPath = resolve(__dirname, ".", dir);
	return resPath;
}

/**
 * 获得环境变量
 * @deprecated
 * 不推荐 环境变量的类型声明文件 现在包含了vite的客户端拓展
 *
 * 客户端的拓展类型 包含一个索引类型
 *
 * 故无法准确推断key值的类型了
 *
 * 该函数效果不佳 故不推荐使用
 */
function getViteEnv(mode: ConfigEnv["mode"], target: keyof ImportMetaEnv) {
	return loadEnv(mode, process.cwd())[target];
}

// https://vitejs.dev/config/
export default function ({ mode }: ConfigEnv) {
	const VITE_app_target_url = getViteEnv(mode, "VITE_app_target_url");
	const VITE_MOCK_DEV_SERVER = getViteEnv(mode, "VITE_MOCK_DEV_SERVER");

	// 提供类型声明 便于得到使用提示
	//
	const env = loadEnv(mode, process.cwd()) as unknown as ImportMetaEnv;
	const VITE_proxy_prefix = env.VITE_proxy_prefix;
	const VITE_APP_API_URL = env.VITE_base_url;
	const VITE_app_port = env.VITE_app_port;

	const res = defineConfig({
		define: {
			// 启用生产环境构建下激活不匹配的详细警告
			__VUE_PROD_HYDRATION_MISMATCH_DETAILS__: "true",
		},
		server: {
			host: "0.0.0.0",
			port: Number(VITE_app_port),
			// @ts-ignore 暂不处理此类型报错
			https: false,
			proxy: {
				[VITE_proxy_prefix]: {
					changeOrigin: true,
					// 接口地址
					target: VITE_APP_API_URL,
					rewrite: (path) => path.replace(new RegExp("^" + VITE_proxy_prefix), ""),
				},

				"/captcha": {
					changeOrigin: true,
					target: "http://localhost:10680",
					rewrite: (path) => path.replace(/^\/captcha/, ""),
				},
			},
		},
		build: {
			assetsDir: "static",
			chunkSizeWarningLimit: 1000,
			rollupOptions: {
				output: {
					manualChunks(id) {
						if (id.includes("node_modules")) {
							const regex = /.pnpm\/(.*?)\//;
							// const res = id.toString().split("node_modules/")[1].split("/")[0].toString();
							const ids = id.toString().split("node_modules/");
							const targetId = ids[1];
							const chunkNames = targetId.split("/");
							// 如果等于pnpm，说明是pnpm的包，需要取第二个
							if (chunkNames[0] === ".pnpm") {
								// console.log("in  chunkNames[0]", chunkNames[0]);
								return chunkNames[1];
							} else {
								return chunkNames[0];
							}
						}
					},
				},
			},
		},

		plugins: [
			/**
			 * 类型化路由插件
			 * @description
			 * 其定义位置必须在 `@vitejs/plugin-vue` 插件之前。
			 *
			 * @see https://uvr.esm.is/introduction.html#installation
			 */
			VueRouter({
				dts: "./types/typed-router.d.ts",
				routesFolder: [
					{
						/**
						 * 在我们项目中，页面放在 views 文件夹下。
						 *
						 * 文档建议是写在pages内
						 * src: "src/pages",
						 */
						src: "src/views",
						// 下面的配置暂时不使用
						// override globals
						// exclude: (excluded) => excluded,
						// filePatterns: (filePatterns) => filePatterns,
						// extensions: (extensions) => extensions,
					},
				],
				getRouteName,
			}),

			/**
			 * 打包体积分析插件
			 */
			visualizer({
				filename: "./dist/visualizer/index.html",
				title: "visualizer打包分析报告",
				template: "network",
			}),

			vue(),

			/**
			 * 自动生成类型声明文件插件
			 */
			autoImport([
				{
					pattern: ["**/*.vue"],

					// 监听的文件夹
					dir: pathResolve("src/components"),

					// 生成的文件
					// FIXME: 当不包含文件路径时，就出现错误 如果没有预先准备好文件夹，就会生成失败。
					toFile: pathResolve("types/components-instance.d.ts"),

					// 文件生成模板
					template: fs.readFileSync(pathResolve("template/components.template.d.ts"), "utf-8"),

					codeTemplates: [
						{
							key: "//typeCode",
							template: 'type {{name}}Instance = InstanceType<typeof import("{{path}}")["default"]>;\n  ',
						},
					],

					/**
					 * 组件名命名规则支持字符串模板和函数
					 * @description
					 * 设置首字母为大写
					 */
					name(fileName) {
						const resFileName = getName(fileName);
						const upperFirstFileName = upperFirst(resFileName);
						// console.log(" in name", upperFirstFileName);
						return upperFirstFileName;
					},
				},
			]),

			AutoImport({
				imports: [
					VueRouterAutoImports,
					"vue",
					"@vueuse/core",
					"pinia",
					{
						"@vueuse/integrations/useAxios": ["useAxios"],
					},
					{
						"@ruan-cat/utils": ["isConditionsEvery", "isConditionsSome"],
					},
					{
						from: "@ruan-cat/utils",
						imports: ["Prettify", "ToNumberLike"],
						type: true,
					},
				],
				ignore: ["vue-router"],
				dirs: ["src/**/*"],
				dts: "./types/auto-imports.d.ts",
				resolvers: [ElementPlusResolver()],
			}),

			Components({
				version: 3,
				dirs: ["src/components", "src/views"],
				dts: "./types/components.d.ts",
				directoryAsNamespace: true,
				resolvers: [ElementPlusResolver()],
			}),

			/**
			 * vueDevTools 必须在 createHtmlPlugin 的前面导入
			 * @see https://github.com/vuejs/devtools-next/issues/278#issuecomment-2021745201
			 */
			vueDevTools(),

			createHtmlPlugin({
				inject: {
					data: {
						title: getViteEnv(mode, "VITE_APP_TITLE"),
					},
				},
			}),

			/**
			 * 本地 mock 服务接口插件
			 */
			getViteEnv(mode, "VITE_MOCK_DEV_SERVER") === "true" ? mockDevServerPlugin() : null,
			// mockDevServerPlugin({
			// 	build: true,
			// }),
		],

		resolve: {
			alias: {
				"@": fileURLToPath(new URL("./src", import.meta.url)),
				components: fileURLToPath(new URL("./src/components", import.meta.url)),
				types: fileURLToPath(new URL("./src/types", import.meta.url)),
				views: fileURLToPath(new URL("./src/views", import.meta.url)),
				apis: fileURLToPath(new URL("./src/apis", import.meta.url)),
				stores: fileURLToPath(new URL("./src/stores", import.meta.url)),
				router: fileURLToPath(new URL("./src/router", import.meta.url)),
				utils: fileURLToPath(new URL("./src/utils", import.meta.url)),
			},
		},
	});

	return res;
}
