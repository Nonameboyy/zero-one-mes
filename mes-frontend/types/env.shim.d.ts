/// <reference types="vite/client" />

/**
 * 这个是之前01星球项目用的环境变量配置
 * @description
 * 不做进一步的拓展了 保留原有的配置
 *
 * 不做外部导出 要求外部以全量导入的形式使用本类型
 */
interface ImportMetaEnv {
	/** 应用端口 */
	VITE_APP_PORT: number;

	/** API 基础路径(代理前缀) */
	VITE_APP_BASE_API: string;

	/** API 地址 */
	VITE_APP_API_URL: string;

	/** api地址 */
	VITE_API_URL: string;

	/** 验证码url */
	VITE_CAPTCHA_URL: string;

	/** 验证码前缀 */
	VITE_CAPTCHA_PREFIX: string;

	/** 前端应用 客户端id */
	VITE_CLIENT_ID: string;

	/** 应用标题 */
	VITE_APP_TITLE: string;

	/** 是否开启mock开发服务器？ */
	VITE_MOCK_DEV_SERVER: string;

	/** 反向代理的target目标 即真实的 有意义的接口地址。 */
	VITE_app_target_url: string;
}

/** 在其他项目内 基本共享的拓展 */
interface ImportMetaEnv {
	/**
	 * 应用端口
	 * @example
	 * "8080"
	 */
	VITE_app_port: `${number}`;

	/**
	 * API 基础路径(代理前缀)
	 * @example
	 * "/dev-api"
	 */
	VITE_proxy_prefix: string;

	/**
	 * API 地址。即接口请求最终的服务器地址。
	 * @example
	 * "https://pcapi-xiaotuxian-front-devtest.itheima.net"
	 */
	VITE_base_url: string;

	/** 是否开启 Mock 服务 */
	VITE_MOCK_DEV_SERVER: `${boolean}`;
}

interface ImportMeta {
	readonly env: ImportMetaEnv;
}
