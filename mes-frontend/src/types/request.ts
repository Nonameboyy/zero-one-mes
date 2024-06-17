import type { AxiosRequestConfig } from "axios";
import type { PartialPick } from "type-plus";
import type { Prettify } from "utils/Prettify";

import type { HttpConfig } from "../../typings/expand-axios";

export type HttpConfigExtraKey = Prettify<keyof HttpConfig>;

export type RequestMethods = HttpConfig["requestMethod"];
export type RequestMethod = RequestMethods[keyof RequestMethods];

export type UpTypes = HttpConfig["upType"];
export type UpType = UpTypes[keyof UpTypes];

export type AxiosRequestConfigSimple = Prettify<PartialPick<AxiosRequestConfig, HttpConfigExtraKey>>;

export interface Request extends RequestMethods {}
