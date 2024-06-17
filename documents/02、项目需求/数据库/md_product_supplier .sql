USE `zo_mes`;
create table md_product_supplier
(
    id          bigint auto_increment comment '主键id'
        primary key,
    product_id  bigint not null comment '物料id',
    supplier_id bigint not null comment '供应商id'
);