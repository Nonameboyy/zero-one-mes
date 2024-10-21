import path from "node:path";
import { createDefineMock } from "vite-plugin-mock-dev-server";

export const defineMock = createDefineMock((mock) => {
	// 拼接url
	mock.url = path.join("/api", mock.url);
});
