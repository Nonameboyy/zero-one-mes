// TODO: 改造项目的 axios 请求方式
/**
 * 关于axios的实例封装，以及常见请求类型工具的封装
 *
 * @description
 * 本文件封装以下内容
 *
 * - axios接口请求实例
 * - 常见请求类型的请求函数
 * - 常见请求返回值的处理函数
 */

import axios from "axios";
import type { AxiosRequestConfig, Method, AxiosInstance, AxiosResponse } from "axios";
export { axios as axiosStaticInstance };

import { type UseAxiosOptions, type StrictUseAxiosReturn, useAxios } from "@vueuse/integrations/useAxios";

import { isNull, merge, isUndefined, isNil } from "lodash-es";
import qs from "qs";
import { type RequiredPick } from "type-plus";
import { isConditionsEvery } from "@ruan-cat/utils";

import { type JsonVO } from "types/JsonVO";
import { type PageDTO } from "types/PageDTO";

/** 数据上传数据类型 */
export enum UpType {
	/** 表单类型 */
	form = 0,

	/** json类型 */
	json = 1,

	/** 文件类型 */
	file = 3,

	/** 文件流类型 */
	stream = 4,
}

/** HTTP状态码 */
export enum HttpCode {
	/** 暂未登录或TOKEN已经过期 */
	UNAUTHORIZED = 401,
	/** 没有相关权限 */
	FORBIDDEN = 403,
	/** 访问页面未找到 */
	NOT_FOUND = 404,
	/** 服务器错误 */
	SERVER_ERROR = 9994,
	/** 上传参数异常 */
	PARAMS_INVALID = 9995,
	/** ContentType错误 */
	CONTENT_TYPE_ERR = 9996,
	/** 功能尚未实现 */
	API_UN_IMPL = 9997,
	/** 服务器繁忙 */
	SERVER_BUSY = 9998,
	/** 操作失败 */
	FAIL = 9999,
	/** 操作成功 */
	SUCCESS = 10000,
}

export enum MapContentType_UpType {
	"application/json;charset=UTF-8" = UpType.json,
	"multipart/form-data" = UpType.file,
	"application/octet-stream" = UpType.stream,
	"application/x-www-form-urlencoded;charset=UTF-8" = UpType.form,
}

type ContentType = keyof typeof MapContentType_UpType;

/**
 * url必填的axios请求配置
 */
// export type AxiosRequestConfigUrl<D = any> = RequiredPick<AxiosRequestConfig<D>, "url">;
export interface AxiosRequestConfigUrl<D = any> extends AxiosRequestConfig<D> {
	/** 必填的url地址 */
	url: string;
}
// export interface AxiosRequestConfigUrlData<D = any> extends AxiosRequestConfigUrl<D> {
// 	/** 必填的data传参对象 */
// 	data: D;
// }
// export interface AxiosRequestConfigUrlData<D = any> extends AxiosRequestConfigUrl<D> {
// 	/** 必填的data传参对象 */
// 	data: D;
// }

/** 针对 useAxios 传参的，接口请求函数的参数类型 */
export interface RequestForUseAxiosParameter<
	Type_AxiosRequestConfig extends AxiosRequestConfigUrl = AxiosRequestConfigUrl,
> {
	/**
	 * axios的配置类型
	 * 默认为 必填url请求地址的 config 请求配置
	 */
	config: Type_AxiosRequestConfig;
	instance: AxiosInstance;
	options?: UseAxiosOptions;
}

/**
 * 创建axios实例
 */
export function createAxiosInstance() {
	const instance = axios.create({
		// TODO: 配置axios基本属性
		// http.defaults.baseURL = import.meta.env.VITE_API_URL;
		// baseURL: "https://pcapi-xiaotuxian-front-devtest.itheima.net",
		// 请求超时时间
		timeout: 10000,
	});

	// 使用qs序列化参数params参数
	instance.defaults.paramsSerializer = function (params) {
		return qs.stringify(params);
	};

	return instance;
}

/** 接口请求的默认实例 */
export const axiosInstance = createAxiosInstance();

/**
 * 接口请求对象
 * @description
 * 仅仅只是 axiosInstance 的别名
 *
 * @alias axiosInstance
 */
export const request = axiosInstance;

/**
 * 执行axios请求
 * @description
 * 最纯粹的请求方法，只负责发送请求，不做任何处理
 *
 * 应该由其他的函数 整理好参数 交给此函数执行
 *
 * 这是细粒度最低最小的 单一职责的函数
 *
 * 不接受任何拓展
 */
export function doAxiosRequest<T>(config: AxiosRequestConfig, instance: AxiosInstance = axiosInstance) {
	return instance<any, JsonVO<T>>(config);
}

/**
 * 根据数据上传类型 重设请求头类型
 * @description
 * 不同的数据上传数据类型 要使用不同的接口请求方式
 */
export function handleHeadersByUpType(config: AxiosRequestConfig, upType: UpType) {
	const contentType = <ContentType>MapContentType_UpType[upType];

	if (contentType) {
		config = merge<AxiosRequestConfig, AxiosRequestConfig>(config, {
			headers: {
				"Content-Type": contentType,
			},
		});
	}

	if (!isNil(config.data)) {
		config.data = qs.stringify(config.data, { arrayFormat: "repeat" });
	}

	return config;
}

/**
 * 是否是 axios的实例对象？
 * @see https://github.com/axios/axios/issues/737
 */
export function isAxiosInstance(p: any): p is AxiosInstance {
	return !!p?.request;
}

/** 该对象是否是专用于 useAxios 的参数对象？ */
export function isRequestForUseAxiosParameter(p: any): p is RequestForUseAxiosParameter {
	const config = <AxiosRequestConfigUrl | undefined>p?.config;
	const url = <AxiosRequestConfigUrl["url"] | undefined>config?.url;
	const instance = <AxiosInstance | undefined>p?.instance;

	return isConditionsEvery([
		// 存在配置对象
		() => !isUndefined(config),
		// 必填的url地址
		() => !isUndefined(url),
		// 有填写axios实例
		() => isAxiosInstance(instance),
	]);
}

export type RequestForUseAxiosReturn<T = any, R = AxiosResponse<T>, D = any> = StrictUseAxiosReturn<T, R, D> &
	Promise<StrictUseAxiosReturn<T, R, D>>;

export function getSimple<T>(
	/** url 请求地址 */
	url: string,
	/** params 请求参数 */
	params?: string | object,
	/** config 请求配置 */
	config?: AxiosRequestConfig,
) {
	config = {
		// `method` 是创建请求时使用的方法
		method: "get",
		// `url` 是用于请求的服务器 URL
		url,
		...config,
	};
	if (params) {
		config.params = params;
	}
	return doAxiosRequest<T>(config);
}

/**
 * @description
 * 传参要传递 config.params
 */
export function getUseAxios<T>(requestForUseAxiosParameter: RequestForUseAxiosParameter) {
	const {
		config: { url },
		config,
		instance,
		options,
	} = requestForUseAxiosParameter;
	config.method = "get";
	return useAxios<JsonVO<T>>(url, config, instance, options);
}

/**
 * 封装get请求方法
 * @description
 * 仅仅是为get请求和传参做了封装
 *
 * @deprecated 硬着头皮做的函数重载 并不是一个好的设计
 */
export function get<T>(
	/** url 请求地址 */
	url: string,
	/** params 请求参数 */
	params?: string | object,
	/** config 请求配置 */
	config?: AxiosRequestConfig,
): Promise<JsonVO<T>>;

/**
 * 封装get请求方法（带有响应式数据的）
 * @description
 * 对 useAxios 做封装
 *
 * @deprecated 硬着头皮做的函数重载 并不是一个好的设计
 */
export function get<T>(p: RequestForUseAxiosParameter): RequestForUseAxiosReturn<JsonVO<T>>;

/**
 * @description
 * 下次不要硬着头皮弄这个函数重载了 心智负担很重 代码也非常诡异混乱
 *
 * @deprecated 硬着头皮做的函数重载 并不是一个好的设计
 */
export function get<T>(...args: any[]): RequestForUseAxiosReturn<JsonVO<T>> | Promise<JsonVO<T>> {
	const p = args[0];
	if (isRequestForUseAxiosParameter(p)) {
		const requestForUseAxiosParameter = <RequestForUseAxiosParameter>args[0];
		return getUseAxios<T>(requestForUseAxiosParameter);
	} else {
		const url = <string>args[0];
		const params = <string | object | undefined>args[1];
		let config = <AxiosRequestConfig | undefined>args[2];
		return getSimple<T>(url, params, config);
	}
}

/**
 * 封装post请求方法
 * @description
 * 仅仅是为post请求和传参做了封装
 */
export function postSimple<T>(
	/** url 请求地址 */
	url: string,
	/** 请求参数 */
	data?: string | object,
	/** 请求配置 */
	config?: AxiosRequestConfig,
) {
	config = {
		method: "post",
		url,
		...config,
	};
	if (data) {
		config.data = data;
	}
	return doAxiosRequest<T>(config);
}

/**
 * @description
 * 传参要传递 config.data
 */
export function postUseAxios<T>(requestForUseAxiosParameter: RequestForUseAxiosParameter) {
	const {
		config: { url },
		config,
		instance,
		options,
	} = requestForUseAxiosParameter;
	config.method = "post";
	return useAxios<JsonVO<T>>(url, config, instance, options);
}

/**
 * 封装patch请求方法
 * @description
 * 仅仅是为patch请求和传参做了封装
 */
export function patch<T>(
	/** url 请求地址 */
	url: string,
	/** 请求参数 */
	data?: string | object,
	/** 请求配置 */
	config?: AxiosRequestConfig,
) {
	config = {
		method: "patch",
		url,
		...config,
	};
	if (data) {
		config.data = data;
	}
	return doAxiosRequest<T>(config);
}

/**
 * 封装delete请求方法
 * @description
 * 仅仅是为delete请求和传参做了封装
 */
export function remove<T>(
	/** url 请求地址 */
	url: string,
	/** params 请求参数 */
	params?: string | object,
	/** config 请求配置 */
	config?: AxiosRequestConfig,
) {
	config = {
		// `method` 是创建请求时使用的方法
		method: "delete",
		// `url` 是用于请求的服务器 URL
		url,
		...config,
	};

	if (params) {
		/**
		 * 有疑惑 在 https://sankeyangshu.top/posts/react-axios.html 中，
		 * 用的是 params 参数，
		 *
		 * 但是我们08mes之前用的是 data 参数
		 *
		 * 这是否会有差异？
		 *
		 * TODO: 对于axios， delete请求到底是怎么传参的？是 params 还是 data ？
		 */
		// case Request.DELETE:
		// 	config.method = "delete";
		// 	config.data = data;
		// 	break;
		config.params = params;
	}

	return doAxiosRequest<T>(config);
}

/**
 * 发送表单请求
 * @description
 * 仅仅是为form请求和传参做了封装
 */
export function requestForm<T>(
	/** url 请求地址 */
	url: string,
	/** data 请求参数 */
	data: string | object,
	/** 请求方法 */
	method: Method,
	/** config 请求配置 */
	config?: AxiosRequestConfig,
) {
	config = {
		method,
		url,
		data,
		...config,
	};
	config = handleHeadersByUpType(config, UpType.form);
	return doAxiosRequest<T>(config);
}

export type AxiosRequestConfig_requestForm<D = any> = RequiredPick<AxiosRequestConfig<D>, "url" | "method" | "data">;

/**
 * @description
 * 传参要传递 config.params
 */
export function requestFormUseAxios<T>(p: RequestForUseAxiosParameter<AxiosRequestConfig_requestForm>) {
	const {
		config: { url, data, method },
		// 重命名为中间变量的配置对象
		config: _config,
		instance,
		options,
	} = p;
	// 经过加工后最终参与的配置对象
	const config = handleHeadersByUpType(_config, UpType.form);
	return useAxios<JsonVO<T>>(url, config, instance, options);
}

/** 发送JSON请求 */
export function requestJson<T>(
	/** url 请求地址 */
	url: string,
	/** data 请求参数 */
	data: string | object,
	/** 请求方法 */
	method: Method,
	/** config 请求配置 */
	config?: AxiosRequestConfig,
) {
	config = {
		method,
		url,
		data,
		...config,
	};
	config = handleHeadersByUpType(config, UpType.json);
	return doAxiosRequest<T>(config);
}

export type AxiosRequestConfig_requestJson<D = any> = AxiosRequestConfig_requestForm<D>;
/**
 * @description
 * 传参要传递 config.data
 */
export function requestJsonUseAxios<T>(p: RequestForUseAxiosParameter<AxiosRequestConfig_requestJson>) {
	const {
		config: { url, data, method },
		// 重命名为中间变量的配置对象
		config: _config,
		instance,
		options,
	} = p;
	// 经过加工后最终参与的配置对象
	const config = handleHeadersByUpType(_config, UpType.json);
	return useAxios<JsonVO<T>>(url, config, instance, options);
}

/**
 * 封装一个Http请求工具类
 * @type { import("types/request").Request }
 */
export default class Request {
	// TODO: 待封装迁移
	/**
	 * 发送带文件上传的请求，该方法会完成js数据对象转换成FormData对象操作
	 * 请求方式以post方式发送
	 * @param { string } url 请求地址
	 * @param { any } data 包括file数据的js数据对象
	 * @param options [可选]其他配置选项
	 * @returns { Promise<unknown> } 请求发送后的Promise对象
	 */
	static postFile(url, data, options = null) {
		// 将data转换成FormData对象
		const formData = new FormData();
		for (const key in data) {
			formData.append(key, data[key]);
		}
		// 发送请求
		return Request.request(Request.POST, url, formData, http.upType.file, options);
	}

	// TODO: 待封装迁移
	/**
	 * 以二进制的方式上传文件
	 * @param { string } url 上传地址
	 * @param file 文件域选择的文件对象
	 * @param success 上传成功回调
	 * @param fail 上传失败回调
	 * @param options [可选]其他配置选项
	 */
	static postFileStream(url, file, success, fail, options = null) {
		// 读取文件
		let reader = new FileReader();
		reader.readAsArrayBuffer(file);
		reader.onloadend = function () {
			// 读取文件失败
			if (reader.error) {
				fail("文件读取失败");
				return;
			}
			// 上传文件
			Request.request(Request.POST, url, reader.result, http.upType.stream, options)
				.then((res) => {
					success(res);
				})
				.catch((err) => {
					fail(err);
				});
		};
	}
}
