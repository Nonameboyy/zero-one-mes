// @ts-check
import http from "axios";

import { isNull, merge } from "lodash-es";

/**
 * 封装一个Http请求工具类
 * @type { import("types/request").Request }
 */
export default class Request {
	/** @returns { import("types/request").RequestMethods['GET'] } 返回具体数值 1 */
	static get GET() {
		return 1;
	}

	/** @returns { import("types/request").RequestMethods['POST'] } 返回具体数值 2 */
	static get POST() {
		return 2;
	}

	/** @returns { import("types/request").RequestMethods['PUT'] } 返回具体数值 3 */
	static get PUT() {
		return 3;
	}

	/** @returns { import("types/request").RequestMethods['DELETE'] } 返回具体数值 4 */
	static get DELETE() {
		return 4;
	}

	/**
	 * 发送请求
	 * @param { import("types/request").RequestMethod } method  请求方式，如Request.GET
	 * @param { string } url 请求地址
	 * @param { unknown } data 上传数据
	 * @param { import("types/request").UpType } upType 上传数据方式，如http.upType.form
	 * @param options [可选]其他配置选项
	 * @returns 请求发送后的Promise对象
	 */
	static request(method, url, data, upType, options = null) {
		// 组装参数
		/** @type { import("types/request").AxiosRequestConfigSimple } */
		// @ts-ignore
		const config = merge(
			{
				url,
				upType,
			},
			isNull(options) ? {} : options,
		);

		switch (method) {
			case Request.GET:
				config.method = "get";
				config.params = data;
				break;
			case Request.POST:
				config.method = "post";
				config.data = data;
				break;
			case Request.PUT:
				config.method = "put";
				config.data = data;
				break;
			case Request.DELETE:
				config.method = "delete";
				config.data = data;
				break;
		}

		// @ts-ignore
		return http.request(config);
	}

	/**
	 * 发送表单请求
	 * @param { import("types/request").RequestMethod } method 请求方式，如Request.GET
	 * @param { string } url 请求地址
	 * @param { unknown } data 上传数据
	 * @param options [可选]其他配置选项
	 * @returns { Promise<unknown> } 请求发送后的Promise对象
	 */
	static requestForm(method, url, data, options = null) {
		return Request.request(method, url, data, http.upType.form, options);
	}

	/**
	 * 发送JSON请求
	 * @param { import("types/request").RequestMethod } method 请求方式，如Request.GET
	 * @param { string } url 请求地址
	 * @param { unknown } data 上传数据
	 * @param options [可选]其他配置选项
	 * @returns { Promise<unknown> } 请求发送后的Promise对象
	 */
	static requestJson(method, url, data, options = null) {
		return Request.request(method, url, data, http.upType.json, options);
	}

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
