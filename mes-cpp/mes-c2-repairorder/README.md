# 维修单模块

## 简介
这个模块完成：

1、获取维修单列表（条件+分页） 2、获取维修单详情 3、添加维修单 4、修改维修单 5、获取维修内容列表（条件+分页） 6、添加维修内容 7、修改维修内容 8、删除维修内容（支持批量删除） 9、删除维修单（支持批量删除）

的接口与领域模型定义

## 目录结构说明
> `arch-demo`
>
> > `conf` -- Windows平台需要的配置文件
> >
> > `controller` -- `MVC`中Controller实现，用于接收用户请求
> >
> > `service` -- 业务逻辑服务层
> >
> > `dao` -- 数据库访问层
> >
> > `domain`  -- 领域模型实体
> >
> > `public` -- 测试访问网页案例
> >
> > `CMakeLists.txt` -- `Cmake`跨平台编译配置文件
> >
> > `Macros.h` -- 通用宏定义
> >
> > `ServerInfo.h` -- 服务器信息缓存单例
> >
> > `stdafx.h` -- 预编译标头文件
> >
> > `main.cpp` -- 程序入口
> >
> > `public.pem` -- `RSA`公钥
> >
> > `zh-dict.yaml` -- 中文词典配置



## 各层命名规范

- `Controller/Service/DAO` 层方法命名规约
  - 获取单个对象的方法用 `query/get/select` 做前缀。
  - 获取多个对象的方法用 `query/list/select` 做前缀。
  - 获取统计值的方法用 `count/count/count` 做前缀。
  - 插入的方法用 `add/save/insert` 做前缀。
  - 删除的方法用 `remove/remove/delete` 做前缀。
  - 修改的方法用 `modify/update/update` 做前缀。
  - `Controller`执行逻辑处理方法使用`exec`作前缀。
    - 如接口端点方法名称为`queryByName`，对应的执行方法名则为`execQueryByName`。
  - `API`请求路径命名，前缀（如：功能模块名称）+ 功能名称（多个单词使用-连接），比如下面的示例：
    - `/sys/query-by-name`、`/user/add-user`、`/user/modify-password`。
- 领域模型命名规约
  - DO：`xxxDO`，`xxx` 即为数据表名。
  - DTO：`xxxDTO`，`xxx` 为业务领域相关的名称。
  - Query：`xxxQuery`，`xxx`为业务领域相关的名称。
  - VO：`xxxVO`，`xxx` 一般为网页名称。
  - `POJO` 是 `DO/DTO/BO/VO/Query` 的统称，禁止命名成 `xxxPOJO`。