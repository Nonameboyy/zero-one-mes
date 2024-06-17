package com.zeroone.star.login.controller;

import com.anji.captcha.model.common.ResponseModel;
import com.anji.captcha.model.vo.CaptchaVO;
import com.anji.captcha.service.CaptchaService;
import com.zeroone.star.login.service.CurrUserInfoService;
import com.zeroone.star.login.service.IMenuService;
import com.zeroone.star.login.service.OauthService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.constant.AuthConstant;
import com.zeroone.star.project.dto.login.LoginDTO;
import com.zeroone.star.project.dto.login.Oauth2TokenDTO;
import com.zeroone.star.project.j1.syslogin.vo.CurrentUserInfoVO;
import com.zeroone.star.project.login.LoginApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.login.MenuTreeVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.cloud.context.config.annotation.RefreshScope;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.data.redis.core.StringRedisTemplate;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.context.request.RequestContextHolder;
import org.springframework.web.context.request.ServletRequestAttributes;

import javax.annotation.Resource;
import javax.imageio.ImageIO;
import javax.servlet.ServletOutputStream;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.awt.image.BufferedImage;
import java.io.ByteArrayOutputStream;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.concurrent.TimeUnit;

/**
 * <p>
 * 描述：登录接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */

@RestController
@RequestMapping("login")
@Api(tags = "登录系统")
@Slf4j
@RefreshScope
public class LoginController implements LoginApis {
    @Resource
    private OauthService oAuthService;
    @Resource
    private UserHolder userHolder;
    @Resource
    RedisTemplate<String, Object> redisTemplate;
    @Resource
    private CaptchaService captchaService;

    @Value("${secure.opencaptcha}")
    private boolean isOpenCaptcha;

    private static final long CAPTCHA_EXPIRATION = 5; // 验证码有效期（分钟）

    private static final long TOKEN_EXPIRATION = 60*24; // token有效期（分钟）

    private static final long REFRESH_TOKEN_EXPIRATION = 7; // refresh_token有效期（天)


    @ApiOperation(value = "授权登录")
    @PostMapping("auth-login")
    @Override
    public JsonVO<Oauth2TokenDTO> authLogin(LoginDTO loginDTO) {
        if (isOpenCaptcha) {
            //创建CaptchaVO对象，用于封装验证码验证信息
            CaptchaVO captchaVO = new CaptchaVO();
            // 设置验证码字符串
            captchaVO.setCaptchaVerification(loginDTO.getCode());
            // 调用验证码服务进行验证
            ResponseModel response = captchaService.verification(captchaVO);
            if (!response.isSuccess()) {
                return JsonVO.create(null,
                        ResultStatus.FAIL.getCode(),
                        response.getRepCode()+":"+response.getRepMsg());
            }
        }
        //账号密码认证
        Map<String, String> params = new HashMap<>(5);
        params.put("grant_type", "password");  //授权模式
        params.put("client_id", loginDTO.getClientId());  //登录客户端ID
        params.put("client_secret", AuthConstant.CLIENT_PASSWORD);  //客户端密码
        params.put("username", loginDTO.getUsername());  //用户名
        params.put("password", loginDTO.getPassword());  //密码
        JsonVO<Oauth2TokenDTO> oauth2TokenDTOJsonVO = oAuthService.postAccessToken(params);
        if (oauth2TokenDTOJsonVO.getCode() != ResultStatus.FAIL.getCode()) {
            redisTemplate.opsForValue().set(oauth2TokenDTOJsonVO.getData().getToken(), "1", TOKEN_EXPIRATION, TimeUnit.MINUTES);
            redisTemplate.opsForValue().set(oauth2TokenDTOJsonVO.getData().getRefreshToken(), "1", REFRESH_TOKEN_EXPIRATION, TimeUnit.DAYS);
        }
        return oauth2TokenDTOJsonVO;
    }

    @ApiOperation(value = "刷新登录")
    @PostMapping("refresh-token")
    @Override
    public JsonVO<Oauth2TokenDTO> refreshToken(Oauth2TokenDTO oauth2TokenDTO) {
        if (Boolean.FALSE.equals(redisTemplate.hasKey(oauth2TokenDTO.getRefreshToken()))) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), "刷新凭证无效");
        }
        Map<String, String> params = new HashMap<>(4);
        params.put("grant_type", "refresh_token");
        params.put("client_id", oauth2TokenDTO.getClientId());
        params.put("client_secret", AuthConstant.CLIENT_PASSWORD);
        params.put("refresh_token", oauth2TokenDTO.getRefreshToken());
        JsonVO<Oauth2TokenDTO> oauth2TokenDTOJsonVO = oAuthService.postAccessToken(params);
        //刷新token存储到redis中
        if (oauth2TokenDTOJsonVO.getCode() != ResultStatus.FAIL.getCode()) {
            redisTemplate.opsForValue().set(oauth2TokenDTOJsonVO.getData().getToken(), "1", TOKEN_EXPIRATION, TimeUnit.MINUTES);
        }
        return oauth2TokenDTOJsonVO;
    }

    @ApiOperation(value = "退出登录")
    @GetMapping("logout")
    @Override
    public JsonVO<String> logout() {
        ServletRequestAttributes servletRequestAttributes = (ServletRequestAttributes) RequestContextHolder.getRequestAttributes();
        if (servletRequestAttributes == null) {
            return null;
        }
        HttpServletRequest request = servletRequestAttributes.getRequest();
        String token = request.getHeader("Authorization");
        String realToken = token.replace("Bearer ", "");
        if (Boolean.TRUE.equals(redisTemplate.hasKey(realToken))){

            Boolean delete = redisTemplate.delete(realToken);
            if (delete) {
                return JsonVO.success("登出成功");
            }else {
                return JsonVO.fail("登出失败");
            }
        }
        return JsonVO.fail("登录已失效");
    }


    @Resource
    CurrUserInfoService currUserInfoService;

    @ApiOperation(value = "获取当前用户")
    @GetMapping("current-user")
    @Override
    public JsonVO<CurrentUserInfoVO> getCurrUser() { //UserHolder包含当前用户ID了，所以不用传入ID
        UserDTO currentUser;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), e.getMessage());
        }
        if (currentUser == null) {
            return JsonVO.fail(null);
        } else {
            CurrentUserInfoVO currentUserInfo = currUserInfoService.getCurrentUserInfo(currentUser);
            return JsonVO.success(currentUserInfo);
        }
    }

    @Resource
    IMenuService menuService;

    @ApiOperation(value = "获取菜单")
    @GetMapping("get-menus")
    @Override
    public JsonVO<List<MenuTreeVO>> getMenus() throws Exception {
        //获取当前用户
        UserDTO currentUser = userHolder.getCurrentUser();
        //获取当前用户拥有的菜单
        List<MenuTreeVO> menus = menuService.listMenuByRoleName(currentUser.getRoles());
        return JsonVO.success(menus);
    }
}

