export interface ImportMetaEnv {
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
}

export interface ImportMeta {
	readonly env: ImportMetaEnv;
}
