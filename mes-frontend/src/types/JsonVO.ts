/**
 * 前后端数据对接数据对象
 * @author f1-阮喵喵
 * @description
 * 后端 JsonVO 泛型类的前端翻译
 */
export interface JsonVO<T> {
	/** 状态码 */
	code: number;

	/** 提示消息 */

	message: string;

	/** 数据对象 */
	data: T;
}
