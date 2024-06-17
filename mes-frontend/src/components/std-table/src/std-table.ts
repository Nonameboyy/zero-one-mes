import type { ButtonProps, ComponentSize, TableProps } from "element-plus";
import type { Prettify } from "utils/Prettify";

/**
 * 通用的按钮配置
 */
interface CommonButton extends Partial<ButtonProps> {
	/** 按钮名称 */
	buttonName: string;
}

/**
 * 导航栏的按钮组配置
 */
export interface Buttons extends CommonButton {
	/** 点击按钮回调函数 */
	clickCallBack?(): void;
}

/**
 * 操作栏配置
 */
export interface Operations<T> extends CommonButton {
	/** 点击按钮回调函数 */
	clickCallBack?(
		/** 当前行数据 */
		row: T,
	): void;
}

// FIXME: 经过 Prettify 修饰过的类型 被提示出错误 不使用时即可
// export type TablePropsWithoutContext<T> = Prettify<Omit<TableProps<T>, "context">>;
/**
 * 特殊移除掉类型不兼容的 context 属性
 *
 * @description
 * ### *设计理由*
 * 为了处理类型识别报错的情况 移除掉报错的 context 属性即可
 *
 * 对于`element-plus`的`table`组件而言，我们传递的`props`属性是不包含`context`属性的
 *
 * 但是类型系统又报错，所以此处就移除掉无意义的，报错的属性即可
 *
 * @author f1-阮喵喵
 */
export type TablePropsWithoutContext<T> = Omit<TableProps<T>, "context">;

/**
 * 标准表格的 props 类型
 * @author f1-阮喵喵
 */
export interface StdTableProps<T> extends TablePropsWithoutContext<T> {
	/**
	 * 人工覆盖掉该内容
	 * @description
	 * 设置该类型不存在，且不传递
	 */
	// context?: undefined;

	/** 按钮栏 */
	buttons?: Buttons[];

	/** 操作栏 */
	operations?: Operations<T>[];

	/**
	 * 统一组件尺寸
	 * @description
	 * 整个组件的统一组件尺寸配置。
	 */
	unifySize?: ComponentSize;

	/**
	 * 初始化函数
	 * @description
	 * 表格组件默认执行一次初始化函数 一般可以设置成请求异步接口函数，获取表格数据
	 */
	init?(): void;
}
