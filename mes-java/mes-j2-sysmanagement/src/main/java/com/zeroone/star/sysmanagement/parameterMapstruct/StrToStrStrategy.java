package com.zeroone.star.sysmanagement.parameterMapstruct;


import com.zeroone.star.sysmanagement.constants.ParameterConstant;
import org.springframework.stereotype.Component;

/**
 * @Author: 40斤
 * @CreateTime: 2024-05-24  11:27
 * @Description: TODO
 * @Version: 1.0
 */
@Component
public class StrToStrStrategy {
    public String strToStr(String configType){
        if (configType.equals(ParameterConstant.YES)){
            return "是";
        }else if (configType.equals(ParameterConstant.NO)){
            return "否";
        }else {
            return configType;
        }
    }
}
