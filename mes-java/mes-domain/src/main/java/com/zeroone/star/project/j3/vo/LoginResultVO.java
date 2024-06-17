package com.zeroone.star.project.j3.vo;

import com.zeroone.star.project.vo.ResultStatus;
import io.swagger.annotations.ApiModel;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("登录结果")
public class LoginResultVO {
    /**
     * 登录结果
     */
    private ResultStatus resultStatus;

    /**
     * 登录结果信息
     */
    private LoginVO loginVO;
}
