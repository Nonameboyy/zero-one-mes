import { type Options } from "unplugin-vue-router";

type GetRouteName = NonNullable<Options["getRouteName"]>;

/**
 * 自主生成路由名称
 * @description
 * 对插件自动生成的路由名称，很不满意，不好看，容易引起阅读歧义。
 *
 * 故自定义。
 *
 * unplugin-vue-router 插件的 getRouteName 配置项
 */
export const getRouteName: GetRouteName = function _getRouteName(node): ReturnType<GetRouteName> {
	// 如果是根节点 那么没有对应的文件夹名称 返回空字符串
	if (!node.parent) {
		return "";
	}

	/** 上一次递归产生的字符串 */
	const last = _getRouteName(node.parent);

	/**
	 * 路由名称链接符
	 * @description
	 * 如果上一次递归产生的字符串为空，则不需要链接符
	 */
	const connector = last === "" ? "" : "-";

	/** 当前节点的路由名称 */
	const current = node.value.rawSegment === "index" ? "" : `${connector}${node.value.rawSegment}`;

	// 返回上一次递归产生的字符串和当前节点的路由名称的拼接
	// 从后面逐步拼接
	return last + current;
};

// import { getRouteName } from "@ruan-cat/utils";
// export { getRouteName } from "@ruan-cat/utils";
