export interface PageDTO<T> {
	pageIndex: number;
	pageSize: number;
	total: number;
	pages: number;
	rows: T[];
}
