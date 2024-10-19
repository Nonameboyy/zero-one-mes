import { defineConfig, loadEnv } from "vite";
import vue from "@vitejs/plugin-vue";
import AutoImport from "unplugin-auto-import/vite";
import Components from "unplugin-vue-components/vite";
import { ElementPlusResolver } from "unplugin-vue-components/resolvers";
import { createHtmlPlugin } from "vite-plugin-html";
import vueDevTools from "vite-plugin-vue-devtools";
import { fileURLToPath, URL } from "node:url";

const getViteEnv = (mode, target) => {
	return loadEnv(mode, process.cwd())[target];
};

// https://vitejs.dev/config/
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
			vue(),
			AutoImport({
				resolvers: [ElementPlusResolver()],
			}),
			Components({
				dts: true,
				version: 3,
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
