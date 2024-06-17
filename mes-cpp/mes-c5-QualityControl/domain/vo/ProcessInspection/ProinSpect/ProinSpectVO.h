#ifndef _PROINSPECTVO_H_
#define  _PROINSPECTVO_H_

#include "../../../GlobalInclude.h"
#include "../../../dto/ProcessInspection/ProinSpect/ProinSpectDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class ProinspectJsonVO : public JsonVO<ProinspectDTO::Wrapper> {
	DTO_INIT(ProinspectJsonVO, JsonVO<ProinspectDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class ProinspectPageJsonVO : public JsonVO<ProinspectPageDTO::Wrapper> {
	DTO_INIT(ProinspectPageJsonVO, JsonVO<ProinspectPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_