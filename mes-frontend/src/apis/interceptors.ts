/**
 * 本文件专门提供axios拦截器配置
 *
 * 是强业务相关的配置
 *
 * 为不同的axios实例提供不同的拦截器配置
 *
 * 并且共享通用的拦截器配置
 */

import type {
	AxiosRequestConfig,
	Method,
	AxiosInstance,
	InternalAxiosRequestConfig,
	AxiosResponse,
	AxiosInterceptorManager,
	Axios,
} from "axios";

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
}

type _interceptors_request = Axios["interceptors"]["request"];
type _interceptors_response = Axios["interceptors"]["response"];

export type RequestOnFulfilled = _interceptors_request["use"];

onFulfilled;

onRejected;

export interface SetInterceptors {
	/** 具体要被添加拦截器的示例对象 */
	instance: AxiosInstance;

	/** 拦截器配置对象 */
	interceptors: {
		/** 请求 */
		request: {};

		/** 响应 */
		response: {};
	};
}

/**
 * 设置拦截器
 * @description
 * 业务强关联的拦截器 会包含很多专属 特殊地拦截器配置
 */
export function setInterceptors(params: SetInterceptors) {}
