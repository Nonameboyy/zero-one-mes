package com.zeroone.star.customer.service.impl;

import cn.hutool.core.date.DateTime;
import com.alibaba.excel.EasyExcel;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.customer.entity.MdClient;
import com.zeroone.star.customer.entity.MdClientExcel;
import com.zeroone.star.customer.mapper.MdClientMapper;
import com.zeroone.star.customer.service.IMdClientService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;

import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j6.customer.dto.ClientDTO;
import com.zeroone.star.project.j6.customer.dto.ClientPageDTO;
import com.zeroone.star.project.j6.customer.dto.ClientUpdateDTO;
import com.zeroone.star.project.j6.customer.query.ClientQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import lombok.SneakyThrows;

import org.mapstruct.Mapper;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.PostConstruct;
import javax.annotation.Resource;
import java.io.BufferedInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;


@Mapper(componentModel = "spring")
interface msClientMapper {
    /**
     * @return com.zeroone.star.project.j6.customer.dto.clientDTO
     * @Description 将MdClient对象转换为clientDTO对象
     **/
    ClientDTO clientToClientDTO(MdClient client);

    /**
     * @return com.zeroone.star.customer.entity.MdClient
     * @Description 将clientDTO对象转换为MdClient对象
     **/
    MdClient clientDTOToMdClient(ClientDTO clientDTO);

    /**
     * @return com.zeroone.star.customer.entity.MdClient
     * @Description 将clientUpdateDTO对象转换为MdClient对象
     **/
    MdClient clientUpdateDTOToMdClient(ClientUpdateDTO clientUpdateDTO);

    /**
     * @return com.zeroone.star.project.j6.customer.dto.ClientPageDTO
     * @Description 将MdClient对象转换为clientPageDTO对象
     **/
    ClientPageDTO clientToClientPageDTO(MdClient client);

}

@Service
@Transactional
public class MdClientServiceImpl extends ServiceImpl<MdClientMapper, MdClient> implements IMdClientService {

    @Resource
    EasyExcelComponent easyExcelComponent;
    @Resource
    FastDfsClientComponent dfs;

    @Value("${fastdfs.nginx-servers}")
    String urlPrefix;
    QueryWrapper<MdClient> queryWrapper;
    @Resource
    private MdClientMapper mdClientMapper;
    @Resource
    private msClientMapper msClientMapper;

    @Override
    public int addClient(ClientDTO client) {
        // 将ClientDTO对象转换为DO
        MdClient mdClient = msClientMapper.clientDTOToMdClient(client);

        // 判断客户名称是否存在
        QueryWrapper<MdClient> nameQueryWrapper = new QueryWrapper<>();
        nameQueryWrapper.eq("client_name", client.getClientName());
        MdClient existingNameClient = mdClientMapper.selectOne(nameQueryWrapper);

        // 判断客户编码是否存在
        QueryWrapper<MdClient> codeQueryWrapper = new QueryWrapper<>();
        codeQueryWrapper.eq("client_code", client.getClientCode());
        MdClient existingCodeClient = mdClientMapper.selectOne(codeQueryWrapper);

        // 如果已存在同名客户，亦或是客户编码已存在，则不执行添加操作
        if (existingNameClient != null && existingCodeClient != null) {
            return 23;
        }else if (existingNameClient != null) {
            return 2;
        } else if (existingCodeClient != null) {
            return 3;
        }

        // 保存到数据库并返回操作结果
        return mdClientMapper.insert(mdClient);

    }

    @Override
    public boolean deleteClient(List<Long> ids) {
        // (批量)删除客户数据
        return mdClientMapper.deleteBatchIds(ids) > 0;
    }

    @Override
    public int updateClient(ClientUpdateDTO client) {
        // 查询客户是否存在
        MdClient existingClient = mdClientMapper.selectById(client.getClientId());
        if (existingClient == null) {
            return 0;
        }

        // 判断客户名称是否存在（排除当前客户）
        QueryWrapper<MdClient> nameQueryWrapper = new QueryWrapper<>();
        nameQueryWrapper.eq("client_name", client.getClientName()).ne("client_id", client.getClientId());
        MdClient existingNameClient = mdClientMapper.selectOne(nameQueryWrapper);

        // 判断客户编码是否存在（排除当前客户）
        QueryWrapper<MdClient> codeQueryWrapper = new QueryWrapper<>();
        codeQueryWrapper.eq("client_code", client.getClientCode()).ne("client_id", client.getClientId());
        MdClient existingCodeClient = mdClientMapper.selectOne(codeQueryWrapper);

        // 如果已存在同名客户或同编码客户，则不执行修改操作
        if (existingNameClient != null && existingCodeClient != null) {
            return 23;
        } else if (existingNameClient != null) {
            return 2;
        } else if (existingCodeClient != null) {
            return 3;
        }

        // 将DTO对象转换为DO
        MdClient updatedClient = msClientMapper.clientUpdateDTOToMdClient(client);

        // 更新数据库中的客户信息
        return mdClientMapper.updateById(updatedClient);
    }


    @Override
    public PageDTO<ClientPageDTO> listAll(ClientQuery query) {
        // 构造分页对象
        Page<MdClient> clientPage = new Page<>(query.getPageNum(), query.getPageSize());

        // 构建查询条件
        QueryWrapper<MdClient> queryWrapper = new QueryWrapper<>();

        // 根据客户名称进行模糊查询
        if (query.getClientName() != null && !query.getClientName().isEmpty()) {
            queryWrapper.like("client_name", query.getClientName());
        }

        // 根据客户编码查询客户
        if (query.getClientCode() != null && !query.getClientCode().isEmpty()) {
            queryWrapper.eq("client_code", query.getClientCode());
        }

        // 根据客户简称查询客户
        if (query.getClientNick() != null && !query.getClientNick().isEmpty()) {
            queryWrapper.eq("client_nick", query.getClientNick());
        }

        // 根据客户英文名称查询客户
        if (query.getClientEn() != null && !query.getClientEn().isEmpty()) {
            queryWrapper.eq("client_en", query.getClientEn());
        }

        // 根据客户是否启用查询客户
        if (query.getEnableFlag() != null && !query.getEnableFlag().isEmpty()) {
            queryWrapper.eq("enable_flag", query.getEnableFlag());
        }

        // 查询客户列表数据
        Page<MdClient> clients = mdClientMapper.selectPage(clientPage, queryWrapper);

        // 返回封装分页信息和客户列表数据的PageDTO对象
        return PageDTO.create(clients, client -> msClientMapper.clientToClientPageDTO(client));
    }

    @Override
    public ClientDTO getById(Long id) {
        // 根据id查询数据库中的客户信息
        MdClient mdClient = mdClientMapper.selectById(id);

        // 将客户信息转换为DTO对象并返回
        return msClientMapper.clientToClientDTO(mdClient);
    }

    @SneakyThrows
    @Override
    public ResponseEntity<byte[]> queryClientExportByExcel(List<Long> ids)  {
        List<MdClient> clientList = new ArrayList<>();
        for (Long id : ids) {
            MdClient mdClient = mdClientMapper.selectById(id);
            if (mdClient != null) {
                clientList.add(mdClient);
            }
        }

        // 判断客户列表是否为空
        if (clientList.isEmpty()) {
            // 返回无可导出数据的提示
            return ResponseEntity.status(HttpStatus.NO_CONTENT).body("没有可导出的客户数据".getBytes());
        }

        ByteArrayOutputStream out = new ByteArrayOutputStream();

        // 导出数据到输出流
        easyExcelComponent.export("客户列表", out, MdClient.class, clientList);
        // 获取字节数据
        byte[] bytes = out.toByteArray();
        try {
            out.close();
        } catch (IOException e) {
            // 处理关闭流时的异常
            e.printStackTrace();
        }
        HttpHeaders headers = new HttpHeaders();
        String filename = "report-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        headers.setContentDispositionFormData("attachment", filename);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        // 响应文件给客户端
        return new ResponseEntity<>(bytes, headers, HttpStatus.CREATED);
    }


    @Override
    public JsonVO<String> importClientByExcel(MultipartFile customer) {
        List<MdClient> mdClients;
        int successNum = 0;
        int failureNum = 0;
        StringBuilder successMsg = new StringBuilder();
        StringBuilder failureMsg = new StringBuilder();
        StringBuilder failureNameMsg = new StringBuilder();

        // 验证文件类型
        String contentType = customer.getContentType();
        if (!"application/vnd.openxmlformats-officedocument.spreadsheetml.sheet".equals(contentType)) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), "不支持的文件类型");
        }

        try (BufferedInputStream inputStream = new BufferedInputStream(customer.getInputStream())) {
            mdClients = EasyExcel.read(inputStream).head(MdClient.class).sheet().doReadSync();
        } catch (IOException e) {
            // 记录异常信息到日志
            log.error("读取Excel文件失败", e);
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), "读取Excel文件失败");
        }

        if (mdClients == null || mdClients.isEmpty()) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), "Excel文件中无数据");
        }

        for (MdClient mdClient : mdClients) {
            try {
                // 对数据进行进一步校验和清洗
                if (isValid(mdClient)) {
                    if (!mdClientMapper.checkMdClientCodeUnique(mdClient.getClientCode())) {
                        mdClientMapper.insert(mdClient);
                    } else {
                        mdClientMapper.update(mdClient);
                    }
                    successNum++;
                } else {
                    failureNum++;
                    failureNameMsg.append(failureNum).append("、").append(mdClient.getClientCode()).append(";");
                }
            } catch (Exception e) {
                // 记录异常信息到日志
                log.error("导入数据出现异常", e);
                failureNum++;
                failureNameMsg.append(failureNum).append("、").append(mdClient.getClientCode()).append(";");
            }
        }

        if (failureNum > 0) {
            failureMsg.append("成功导入").append(successNum).append("条数据，共").append(failureNum).append("条数据格式不正确，错误如下：").append(failureNameMsg);
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), failureMsg.toString());
        } else {
            successMsg.append("导入成功！共 ").append(successNum).append(" 条");
            return JsonVO.create(null, ResultStatus.SUCCESS.getCode(), successMsg.toString());
        }
    }
    // 数据校验方法完善示例
    private boolean isValid(MdClient mdClient) {
        if (mdClient.getClientCode() == null || mdClient.getClientCode().isEmpty()) {
            return false; // 客户代码不能为空
        }
        if (mdClient.getClientName() == null || mdClient.getClientName().isEmpty()) {
            return false; // 客户名称不能为空
        }
        return true;
    }


    //初始化参考客户模板
    @PostConstruct
    public MdClientExcel initMdClient(){
        MdClientExcel mdClient = new MdClientExcel();
        mdClient.setClientCode("必填");
        mdClient.setClientName("必填"); // 添加这一行，给客户名称赋值
        mdClient.setClientNick("");
        mdClient.setClientEn("");
        mdClient.setClientDes("");
        mdClient.setClientLogo("");
        mdClient.setClientType("");
        mdClient.setAddress("");
        mdClient.setWebsite("");
        mdClient.setEmail("");
        mdClient.setTel("");
        mdClient.setContact1("");
        mdClient.setContact1Tel("");
        mdClient.setContact1Email("");
        mdClient.setContact2("");
        mdClient.setContact2Tel("");
        mdClient.setContact2Email("");
        mdClient.setCreditCode("");
        mdClient.setEnableFlag("");
        mdClient.setRemark("");
        mdClient.setAttr1("");
        mdClient.setAttr2("");
        mdClient.setAttr3(null);
        mdClient.setAttr4(null);
        mdClient.setCreateBy("");
        mdClient.setCreateTime(null);
        mdClient.setUpdateBy("");
        mdClient.setUpdateTime(null);
        return mdClient;
    }


    @SneakyThrows
    @Override
    public ResponseEntity<byte[]> DownloadTemplate() {
        List<MdClientExcel> mdClients = new ArrayList<>();
        mdClients.add(initMdClient());
        // 构建一个输出流
        ByteArrayOutputStream out = new ByteArrayOutputStream();

        // 导出数据到输出流
        easyExcelComponent.export("客户列表", out, MdClientExcel.class, mdClients);
        // 获取字节数据
        byte[] bytes = out.toByteArray();
        try {
            out.close();
        } catch (IOException e) {
            // 处理关闭流时的异常
            e.printStackTrace();
        }
        HttpHeaders headers = new HttpHeaders();
        String filename = "report-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        headers.setContentDispositionFormData("attachment", filename);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        // 响应文件给客户端
        return new ResponseEntity<>(bytes,headers,HttpStatus.CREATED);
    }
}

