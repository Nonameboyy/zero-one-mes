import path from "node:path";
import { createDefineMock } from "vite-plugin-mock-dev-server";

// 尝试不做拼接了 直接使用api？
// export const defineMock = createDefineMock((mock) => {
// 	// 拼接url
// 	mock.url = path.join("/api", mock.url);
// });
