// 这里导入你要使用的图标
// 写成多行避免解决冲突麻烦
import { Folder, Menu, Setting, Tickets, UploadFilled, User } from "@element-plus/icons-vue";

export default (app) => {
	app.component("IconMenu", Menu);
	app.component("IconSetting", Setting);
	app.component("IconUser", User);
	app.component("IconTickets", Tickets);
	app.component("IconUpload", UploadFilled);
	app.component("IconFolder", Folder);
};
