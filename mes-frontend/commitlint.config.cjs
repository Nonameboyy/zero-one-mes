// @ts-check

/**
 * 其他范围配置
 * @description
 * 该配置是为了提供更多的范围配置，以便于更好的管理提交范围。
 *
 * 这里罗列一些高频更改配置的文件，并定位为专门的提交范围。
 */
const otherScopesConfigs = [
	{
		code: "config",
		value: "config",
		desc: "各种配置文件",
	},
	{
		code: "turbo",
		value: "turbo",
		desc: "任务调度器",
	},
	{
		code: "root",
		value: "root",
		desc: "根目录",
	},
	{
		code: "package.json",
		value: "package.json",
		desc: "包配置",
	},
	{
		code: "vite.config.js/ts",
		value: "vite",
		desc: "vite打包工具配置",
	},
	{
		code: "vitepress",
		value: "文档配置",
		desc: "vitepress文档工具配置",
	},
	{
		code: "commitlint.config.cjs",
		value: "commitlint",
		desc: "cz配置，即git提交工具的配置",
	},
	{
		code: "tsconfig",
		value: "tsc",
		desc: "typescript项目配置",
	},
	{
		code: "router",
		value: "router",
		desc: "路由配置",
	},
	{
		code: "vscode/settings.json",
		value: "vsc",
		desc: "vscode配置",
	},
];

module.exports = require("@ruan-cat/commitlint-config").getUserConfig(otherScopesConfigs);
