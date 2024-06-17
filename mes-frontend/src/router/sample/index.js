const routes = [
	{
		path: "/sample",
		name: "Sample",
		redirect: { path: "/sample/file" },
		component: () => import("@/views/sample/SampleView.vue"),
		children: [
			{
				path: "/sample/file",
				component: () => import("@/views/sample/file/FileUpload.vue"),
			},
			{
				path: "/sample/excel",
				component: () => import("@/views/sample/excel/Excel.vue"),
			},
			{
				path: "/sample/print",
				component: () => import("@/views/sample/print/Print.vue"),
			},
			{
				path: "/sample/editor",
				component: () => import("@/views/sample/editor/Editor.vue"),
			},
			{
				path: "/sample/pdfobject",
				component: () => import("@/views/sample/pdfobject/PdfObject.vue"),
			},
			// 表格组件
			{
				path: "/sample/table-list-use",
				component: () => import("@/views/sample/table-list-use/table.vue"),
			},

			// 阮喵喵 标准表格组件 演示页
			{
				path: "/sample/table-list-use-demo-page",
				component: () => import("views/sample/table-list-use/table-list-use-demo-page.vue"),
			},

			// 搜索栏演示页
			{
				path: "/sample/search-bar",
				component: () => import("@/views/sample/search-bar/search-bar-page.vue"),
			},
			// 计算单位演示页
			{
				path: "/sample/unit-account",
				component: () => import("@/views/sample/basic-data/unit-of-account.vue"),
			},
			// 车间设置
			{
				path: "/sample/workshop-settings",
				component: () => import("@/views/sample/workshop/WorkshopSettings.vue"),
			},
			// 工艺流程
			{
				path: "/sample/process-flow",
				component: () => import("@/views/sample/process-flow/ProcessFlow.vue"),
			},
			// 表单弹窗演示页
			{
				path: "/sample/public-form",
				component: () => import("@/views/sample/public-form/public-form-page.vue"),
			},
			{
				path: "/sample/detection",
				component: () => import("@/views/sample/detection/Detection.vue"),
			},
		],
	},
];

export default routes;
