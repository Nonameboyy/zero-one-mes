const routes = [
	// 基础数据主菜单
	{
		path: "/un-0",
		name: "UN0",
		component: () => import("@/views/home-system-page/home-system-page.vue"),
	},
	{
		path: "/un-1",
		name: "UN1",
		component: () => import("@/views/status/404.vue"),
	},
	{
		path: "/un-2",
		name: "UN2",
		component: () => import("@/views/basic-data/material-admin.vue"),
	},
	{
		path: "/un-3",
		name: "UN3",
		component: () => import("@/views/sample/basic-data/unit-of-account.vue"),
	},
	{
		path: "/un-4",
		name: "UN4",
		component: () => import("@/views/basedata/Clientdemo.vue"),
	},
	{
		path: "/un-5",
		name: "UN5",
		component: () => import("@/views/basedata/supplier.vue"),
	},
	{
		path: "/un-6",
		name: "UN6",
		component: () => import("@/views/sample/workshop/WorkshopSettings.vue"),
	},
	{
		path: "/un-7",
		name: "UN7",
		component: () => import("@/views/sample/Productionreport/Productionreport.vue"),
	},
	{
		path: "/un-8",
		name: "UN8",
		component: () => import("@/views/sample/productionmanagement/Processsetting.vue"),
	},
	{
		path: "/un-9",
		name: "UN9",
		component: () => import("@/views/sample/technologicalprocess/technologicalprocess.vue"),
	},
	// 仓库管理页面
	{
		path: "/un-31",
		name: "UN31",
		component: () => import("@/views/warehouse-management/warehouse-management.vue"),
	},
	// 采购入库页面
	{
		path: "/un-32",
		name: "UN32",
		component: () => import("@/views/warehouse-management/purchase-in.vue"),
	},
	// 采购退货页面
	{
		path: "/un-33",
		name: "UN33",
		component: () => import("@/views/warehouse-management/PurchaseReturn.vue"),
	},
	{
		path: "/un-51",
		name: "UN51",
		component: () => import("@/views/quality-control/defect.vue"),
	},
	{
		path: "/un-52",
		name: "UN52",
		component: () => import("@/views/sample/detection/Detection.vue"),
	},
	{
		path: "/un-53",
		name: "UN53",
		component: () => import("@/views/status/404.vue"),
	},
	{
		path: "/un-54",
		name: "UN54",
		component: () => import("@/views/status/404.vue"),
	},
	// 来料检验
	{
		path: "/un-55",
		name: "UN55",
		component: () => import("@/views/quality-control/incoming.vue"),
	},
	// 过程检验
	{
		path: "/un-56",
		name: "UN56",
		component: () => import("@/views/quality-control/process.vue"),
	},
	{
		path: "/un-57",
		name: "UN57",
		component: () => import("@/views/status/404.vue"),
	},
	// 生产领料页面
	{
		path: "/un-34",
		name: "UN34",
		component: () => import("@/views/warehouse-management/Material.vue"),
	},
	// 生产退料页面
	{
		path: "/un-35",
		name: "UN35",
		component: () => import("@/views/warehouse-management/ProductionReturn.vue"),
	},
	// 产品入库页面
	{
		path: "/un-36",
		name: "UN36",
		component: () => import("@/views/warehouse-management/Productrecpt.vue"),
	},
	// 组织架构主菜单
	{
		path: "/orgstructure",
		name: "Orgstructure",

		children: [
			// 所有组织架构的相关页面 在这里添加路由映射
			{
				path: "/dept",
				name: "dept",
				component: () => import("@/views/status/404.vue"),
			},
			{
				path: "/postManage",
				name: "postManage",
				component: () => import("@/views/orgstructure/postmanage/postmanage.vue"),
			},
			{
				path: "/role",
				name: "role",
				component: () => import("@/views/status/404.vue"),
			},
			{
				path: "/user",
				name: "user",
				component: () => import("@/views/status/404.vue"),
			},
		],
	},

	// 工艺流程页面
	{
		path: "/un-514",
		name: "UN514",
		component: () => import("@/views/sample/process-flow/ProcessFlow.vue"),
	},

	// 车间设置
	{
		path: "/un-114",
		name: "WorkshopSettings",
		component: () => import("@/views/sample/workshop/WorkshopSettings.vue"),
	},
	// 采购系统管理的消息通知页面
	{
		path: "/un-41",
		name: "UN41",
		component: () => import("@/views/system-management/announcement-management.vue"),
	},
	// 采购系统管理的消息通知页面
	{
		path: "/un-606",
		name: "UN51",
		component: () => import("@/views/organizational-structure/organizational-structure.vue"),
	},
	// 采购系统管理的消息通知页面
	{
		path: "/un-45",
		name: "UN45",
		component: () => import("@/views/system-management/CodeRules.vue"),
	},
	// 班组设置
	{
		path: "/un-101",
		name: "UN101",
		component: () => import("@/views/workforce-management/working-schedule.vue"),
	},
	// 节假日设置
	{
		path: "/un-102",
		name: "UN102",
		component: () => import("@/views/status/404.vue"),
	},
	// 排班日历
	{
		path: "/un-103",
		name: "UN103",
		component: () => import("@/views/status/404.vue"),
	},
	// 排班计划
	{
		path: "/un-104",
		name: "UN104",
		component: () => import("@/views/workforce-management/team-group.vue"),
	},
	// 工装夹具管理/类型设置
	{
		path: "/un-607",
		name: "UN607",
		component: () => import("@/views/frockClamp/typeSetting.vue"),
	}, // 工装夹具管理/工装夹具台账
	{
		path: "/un-608",
		name: "UN608",
		component: () => import("@/views/frockClamp/equipmentLedger.vue"),
	},
];

export default routes;
