import { createApp } from "vue";
import { createPinia } from "pinia";

import App from "./App.vue";
import router from "./router";
import "element-plus/dist/index.css";
import ElementPlus from "element-plus";
import zhCn from "element-plus/es/locale/lang/zh-cn"; //配置 Element Plus 的国际化
import "./assets/main.css";
import * as ElementPlusIconsVue from "@element-plus/icons-vue";
// 添加了图标

// 定义特性标志
/* 解决__VUE_PROD_HYDRATION_MISMATCH_DETAILS__警告
/ 禁用对hydration不匹配的详细警告2。 */
// window.__VUE_PROD_DEVTOOLS__ = false;
// window.__VUE_PROD_HYDRATION_MISMATCH_DETAILS__ = false;

// 配置 Element Plus 的国际化
const app = createApp(App);

app.use(ElementPlus, {
	locale: zhCn,
});
for (const [key, component] of Object.entries(ElementPlusIconsVue)) {
	app.component(key, component);
}
//注册全局图标
app.use(createPinia());
app.use(router);
app.mount("#app");

// 安装HTTP中间件
import installHttp from "./plugins/http";
installHttp(router);

// 安装ElIcon
import installElIcon from "./plugins/el-icon";
installElIcon(app);
