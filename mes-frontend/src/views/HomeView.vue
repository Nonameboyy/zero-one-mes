<template>
	<div class="layout-container">
		<el-container class="sec-container">
			<el-aside width="221px">
				<!-- 侧边栏菜单 -->
				<div class="menu-wrap">
					<el-scrollbar max-height="100vh">
						<el-menu
							default-active="/home"
							class="el-menu-vertical-demo"
							active-text-color="#409EFF"
							text-color="#fff"
							background-color="#545c64"
							unique-opened
							router
						>
							<el-menu-item index="/home">
								<el-icon>
									<icon-menu />
								</el-icon>
								<span>首页</span>
							</el-menu-item>
							<el-sub-menu v-for="item in menus" :key="item.id" :index="item.id + ''">
								<template #title>
									<el-icon>
										<component :is="item.icon" />
									</el-icon>
									<span>{{ item.text }}</span>
								</template>
								<el-menu-item-group>
									<el-menu-item v-for="i in item.children" :key="i.id" :index="i.href">
										<el-icon>
											<component :is="i.icon" />
										</el-icon>
										{{ i.text }}
									</el-menu-item>
								</el-menu-item-group>
							</el-sub-menu>
						</el-menu>
					</el-scrollbar>
				</div>
			</el-aside>
			<el-container>
				<!-- 导航栏 -->
				<el-header>
					<!-- 面包屑功能未完成 -->
					<div class="breadcrumb">
						<el-breadcrumb :separator-icon="ArrowRight">
							<el-breadcrumb-item :to="{ path: '/dashboard' }">homepage</el-breadcrumb-item>
							<el-breadcrumb-item>
								<a href="/">promotion management</a>
							</el-breadcrumb-item>
							<el-breadcrumb-item>promotion list</el-breadcrumb-item>
							<el-breadcrumb-item>promotion detail</el-breadcrumb-item>
						</el-breadcrumb>
					</div>
					<!-- 右侧快捷功能+用户中心 -->
					<div class="header-nav">
						<el-icon size="25">
							<Search />
						</el-icon>
						<el-icon size="25">
							<QuestionFilled />
						</el-icon>
						<el-icon size="25">
							<FullScreen />
						</el-icon>
						<router-link to="/user/profile">
							<el-text style="color: #f8f8f8; font-size: large; font-size: 25px">{{ userInfo }}</el-text>
						</router-link>
					</div>
				</el-header>
				<el-main>
					<!-- 布局路由 -->
					<router-view />
				</el-main>
			</el-container>
		</el-container>
	</div>
</template>

<style lang="scss" scoped>
.sec-container {
	height: 100vh;
}
.el-aside {
	background-color: #545c64;
	.menu-wrap {
		height: 100vh;
		width: 220px;
		position: fixed;
		top: 0;
		left: 0;
	}
}
.el-menu {
	border: 0;
}
.el-menu-item-group .el-menu-item {
	text-indent: 1.5em;
}
.el-main {
	padding: 20px;
}
.el-header {
	background-color: #fff;
	display: flex;
	justify-content: space-between;
	padding: 0;

	.breadcrumb {
		padding: 20px;
		background-color: #6c777f;
		width: 100%;
		color: #f8f8f8;
		text-align: left;
	}
	// 右侧常用导航功能
	.header-nav {
		padding: 20px;
		background-color: #6c777f;
		width: 100%;
		color: #f8f8f8;
		display: flex;
		align-items: center;
		justify-content: flex-end;
		.el-icon {
			margin-right: 5px;
		}
	}
}
</style>

<script setup>
import { ref } from "vue";
import { userStore } from "../stores/user";
import { ArrowRight } from "@element-plus/icons-vue";
const store = userStore();

// 用户信息提示
const userInfo = ref("" + (store.getUser === null ? "游客" : store.getUser.username));

// 菜单数据
const menus = store.getMenus;
</script>
