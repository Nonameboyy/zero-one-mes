import { createPlugin, getName } from "vite-plugin-autogeneration-import-file";

const { autoImport, resolver } = createPlugin();

export { resolver };

import {
	createAutoImportTemplate,
	createDirOptionNameFunction,
	defaultAutoImportTemplate,
	defaultAutoImportTemplateFilename,
	defaultAutoImportTemplatePath,
	pathResolve,
} from "@ruan-cat/utils/vite-plugin-autogeneration-import-file";

export default autoImport([
	// components 目录
	{
		// 文件命名规则
		name: function name(fileName) {
			/** 从生成函数内获取的文件名称 */
			const fileNameOrigin = getName(fileName);
			const keyword = "Src";
			// 截断字符串，遇到指定子串后删除其后的内容
			function cutStringByKeyword(str: string, keyword: string): string {
				const idx = str.indexOf(keyword);
				if (idx === -1) return str;
				return str.substring(0, idx);
			}
			const resFileName = cutStringByKeyword(fileNameOrigin, keyword);
			return <const>`${resFileName}`;
		},
		// name: createDirOptionNameFunction("Components"),
		pattern: [
			// 忽略全部的test组件
			"!**/*.test.vue",
			"!**/*-example.vue",
			"**/*.vue",
		],
		// 监听的文件夹
		dir: pathResolve("./src/components"),
		// 生成的文件
		toFile: "./types/components-in-components-path.d.ts",
		// 文件生成模板
		template: defaultAutoImportTemplate,
		codeTemplates: [
			{
				key: "//code",
				template: '{{name}}: typeof import("{{path}}")["default"];\n    ',
			},
		],
	},
]);
