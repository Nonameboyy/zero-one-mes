package com.zeroone.star.customer.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.customer.entity.MdClient;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j6.customer.dto.ClientDTO;
import com.zeroone.star.project.j6.customer.dto.ClientPageDTO;
import com.zeroone.star.project.j6.customer.dto.ClientUpdateDTO;
import com.zeroone.star.project.j6.customer.query.ClientQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.http.ResponseEntity;
import org.springframework.web.multipart.MultipartFile;

import java.io.IOException;
import java.util.List;

public interface IMdClientService extends IService<MdClient> {
    /**
     * @return com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.j6.customer.dto.ClientDTO>
     * @Description 新增客户业务流程
     * @Param clientDTO [client]
     **/
    int addClient(ClientDTO client);

    /**
     * @return com.zeroone.star.project.vo.JsonVO<java.lang.String>
     * @Description 删除客户业务流程
     * @Param List<Long> [ids]
     **/
    boolean deleteClient(List<Long> ids);

    /**
     * @return com.zeroone.star.project.vo.JsonVO<com.zeroone.star.project.j6.customer.dto.ClientDTO>
     * @Description 更新客户
     * @Param clientDTO [client]
     **/
    int updateClient(ClientUpdateDTO client);

    /**
     * @return 查询结果
     * @Description 分页查询客户数据
     * @Param query 查询条件
     **/
    PageDTO<ClientPageDTO> listAll(ClientQuery query);

    /**
     * @return 查询结果
     * @Description 通过id查询客户数据
     * @Param id
     **/
    ClientDTO getById(Long id);

    /**
     * @param ids 导出条件
     * @return 导出结果
     */
    ResponseEntity<byte[]> queryClientExportByExcel(List<Long> ids) throws IOException;

    /**
     * @param customer 数据集
     * @return 导入结果
     */
    JsonVO<String> importClientByExcel(MultipartFile customer);

    /**
     * @return 返回下载模板情况
     */
    ResponseEntity<byte[]> DownloadTemplate();

}
