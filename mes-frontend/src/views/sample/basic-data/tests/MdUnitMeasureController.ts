import http from "axios";
import type { AxiosResponse } from "axios";
import Request from "api/request";

import type { SimpleBaseController } from "types/SimpleBaseController";
import type { JsonVO } from "types/JsonVO";
import type { PageDTO } from "types/PageDTO";
// import Request from "@/apis/request.js";

export interface UnitMeasureDTO {
	/** 与主单位换算比例 */
	changeRate: number;

	/** 创建者 */
	createBy: string;
}

/** 单位相关操作 */
export interface MdUnitMeasureController extends SimpleBaseController {
	/** 删除单位 */
	deleteUnitMeasure(measureIds: number[]): Promise<AxiosResponse<JsonVO<string>>>;

	/** 根据单位ID获取单位信息 */
	getInfo(measureId: number): Promise<AxiosResponse<JsonVO<string>>>;

	list(unitMeasureDTO: UnitMeasureDTO): Promise<AxiosResponse<JsonVO<PageDTO<UnitMeasureDTO>>>>;

	addUnitMeasure(unitMeasureDTO: UnitMeasureDTO): Promise<AxiosResponse<JsonVO<string>>>;
}

export const mdUnitMeasureController: MdUnitMeasureController = {
	RequestMapping: "/basicdata/md-unit-measure",

	deleteUnitMeasure(measureIds) {
		return Request.request(Request.DELETE, mdUnitMeasureController.RequestMapping, { measureIds }, http.upType.json);
	},

	getInfo(measureId) {
		return Request.request(
			Request.GET,
			`${mdUnitMeasureController.RequestMapping}/${measureId}`,
			// `${this.RequestMapping}`,
			{ measureId },
			http.upType.json,
		);
	},

	list(unitMeasureDTO) {
		return new Promise((resolve) => {
			const pageDTO: PageDTO<UnitMeasureDTO> = {
				pageIndex: 1,
				pages: 1,
				pageSize: 1,
				total: 10,
				rows: [
					{
						changeRate: 100,
						createBy: "sdddfd",
					},
				],
			};

			const axiosResponse: AxiosResponse = {
				data: pageDTO,
				// @ts-expect-error
				config: {},
				headers: {},
				status: 200,
				statusText: "",
			};

			setTimeout(() => {
				resolve(axiosResponse);
			}, 1000);
		});
	},

	// @ts-ignore
	addUnitMeasure(unitMeasureDTO) {},
};
