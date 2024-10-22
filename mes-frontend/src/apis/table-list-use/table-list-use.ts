import { type UseAxiosOptions } from "@vueuse/integrations/useAxios";

const defOptions: UseAxiosOptions = {
	immediate: false,
};

export function getTableListUseApi(options = defOptions) {
	return useAxios("/logs/page", axiosStaticInstance, options);
}
