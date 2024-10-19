import { fileURLToPath, URL } from "node:url";

import { defineConfig, loadEnv } from "vite";
import vue from "@vitejs/plugin-vue";
import AutoImport from "unplugin-auto-import/vite";
import Components from "unplugin-vue-components/vite";
import VueRouter from "unplugin-vue-router/vite";
import { VueRouterAutoImports } from "unplugin-vue-router";
import { ElementPlusResolver } from "unplugin-vue-components/resolvers";
import { createHtmlPlugin } from "vite-plugin-html";
import vueDevTools from "vite-plugin-vue-devtools";
import { visualizer } from "rollup-plugin-visualizer";

import { getRouteName } from "./src/plugins/unplugin-vue-router";

// @ts-ignore
const getViteEnv = (mode, target) => {
	return loadEnv(mode, process.cwd())[target];
};

// https://vitejs.dev/config/
// @ts-ignore
export default ({ mode }) =>
	defineConfig({
		define: {
			// 启用生产环境构建下激活不匹配的详细警告
			__VUE_PROD_HYDRATION_MISMATCH_DETAILS__: "true",
		},
		server: {
			host: "0.0.0.0",
			port: 3000,
			https: false,
			proxy: {
				"/api": {
					changeOrigin: true,
					// target: 'http://localhost:10100',
					// rewrite: (path) => path.replace(/^\/api/, '')

					//TODO[TEST_CODE]:使用ApiPost云MOCK
					target: "https://console-mock.apipost.cn/mock/99738a62-8857-4bb2-8010-c92424b03584",
					rewrite: (path) => path.replace(/^\/api/, ""),
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

			AutoImport({
				imports: [VueRouterAutoImports],
				ignore: ["vue-router"],
				resolvers: [ElementPlusResolver()],
				dts: "./types/auto-imports.d.ts",
			}),

			Components({
				version: 3,
				resolvers: [ElementPlusResolver()],
				dts: "./types/components.d.ts",
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
		],

		resolve: {
			alias: {
				"@": fileURLToPath(new URL("./src", import.meta.url)),
				components: fileURLToPath(new URL("./src/components", import.meta.url)),
				types: fileURLToPath(new URL("./src/types", import.meta.url)),
				views: fileURLToPath(new URL("./src/views", import.meta.url)),
				api: fileURLToPath(new URL("./src/apis", import.meta.url)),
				stores: fileURLToPath(new URL("./src/stores", import.meta.url)),
				router: fileURLToPath(new URL("./src/router", import.meta.url)),
				utils: fileURLToPath(new URL("./src/utils", import.meta.url)),
			},
		},
	});
