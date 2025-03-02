// TODO: 改造项目的 axios 请求方式

import http from "axios";
import { ElMessage } from "element-plus";
import { userStore } from "../stores/user";

export default (router) => {
	// 请求拦截处理
	http.interceptors.request.use(
		function onFulfilled(config) {
			// 提交的时候携带登录凭证
			let store = userStore();
			let token = store.getToken;
			if (token) {
				// 不理解 可能是 axios 1版本没有提供 common 属性
				// config.headers.common.Authorization = `Bearer ${token}`;
				config.headers.Authorization = `Bearer ${token}`;
			}
			return config;
		},

		function onRejected(error) {
			return Promise.reject(error);
		},
	);

	// 响应拦截处理
	http.interceptors.response.use(
		async function onFulfilled(response) {
			// HTTP响应状态码正常
			if (response.status === 200) {
				if ("code" in response.data) {
					let store = userStore();
					const data = response.data;
					switch (data.code) {
						case http.httpcode.SUCCESS:
							// 将数据继续传递下去
							return Promise.resolve(data);
						case http.httpcode.FORBIDDEN:
							// 权限不足
							ElMessage.error("权限不够，请联系管理员");
							// 将数据继续传递下去
							return Promise.reject(data);
						case http.httpcode.UNAUTHORIZED:
							// 判断是否是超时
							if (typeof data.data === "string" && data.data.includes("Jwt expired at")) {
								// 刷新凭证
								await store.reloadToken();
								// 设置为未加载
								store.setLoaded(false);
								// 跳转到主页
								router.push("/home");
							} else {
								// 没有登录或登录已失效
								router.push("/");
								// 重置数据
								store.resetSaveData();
							}
							// 将数据继续传递下去
							return Promise.reject(data);
						case http.httpcode.NOT_FOUND:
							ElMessage.warning(data.message || "404访问页面不存在");
							return Promise.reject(data);
						case http.httpcode.CONTENT_TYPE_ERR:
						case http.httpcode.PARAMS_INVALID:
							ElMessage.warning(data.message || "请求参数或请求头错误");
							return Promise.reject(response);
						default:
							// 显示操作失败提示
							// ElMessage.error(data.message || '操作失败!!!')
							return Promise.reject(response);
					}
				}
				return Promise.resolve(response);
			} else if (response.status === 404) {
				ElMessage.warning("404访问页面不存在");
				return Promise.resolve(response);
			} else {
				return Promise.reject(response);
			}
		},

		function onRejected(error) {
			if (error.code === "ECONNABORTED" || error.code === "ERR_NETWORK") ElMessage.error("连接服务器失败!!!");
			return Promise.reject(error);
		},
	);
};
