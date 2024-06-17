-- ----------------------------
--  Change database
-- ----------------------------
USE `zo_mes`;

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Records of md_client
-- ----------------------------
INSERT INTO `md_client` VALUES (2, 'C00001', '比亚迪股份有限公司', '比亚迪', 'BYD', '比亚迪品牌诞生于深圳，于1995年成立，业务横跨汽车、轨道交通、新能源和电子四大产业。', '12222', 'ENTERPRISE', '深圳南山区无名路12号', 'https://www.bydglobal.com/cn/index.html', 'salse@bydglobal.com', '123432222', '张三', '122212312', 's1@bydglobal.com', '李四', '1132323232', 's2@bydglobal.com', '11212121', 'Y', '', NULL, NULL, 0, 0, NULL, NULL, NULL, NULL);
INSERT INTO `md_client` VALUES (3, 'C00002', '张伟', NULL, NULL, '身份证号码：61032619851111', NULL, 'PERSON', '陕西省宝鸡市金台区', NULL, 'zhangwei@163.com', '122827263633', NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'Y', '', NULL, NULL, 0, 0, NULL, NULL, NULL, NULL);
INSERT INTO `md_client` VALUES (4, 'C00003', '博世', '博世', 'BOSCH', NULL, NULL, 'ENTERPRISE', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'Y', '', NULL, NULL, 0, 0, NULL, NULL, NULL, NULL);
INSERT INTO `md_client` VALUES (5, 'C00004', '德力西电气', '德力西', 'DELIXI', NULL, NULL, 'ENTERPRISE', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'Y', '', NULL, NULL, 0, 0, NULL, NULL, NULL, NULL);

INSERT INTO `sys_auto_code_result` (`rule_id`, `gen_date`, `gen_index`, `last_result`, `last_serial_no`) VALUES (2, '20220729122036', 4, 'C00004', 4);

-- ----------------------------
-- Records of md_product_sop
-- ----------------------------
INSERT INTO `md_product_sop` VALUES (1, 5, 1, 1, 'PROCESS1' , '注塑', '步骤1', '产品为自动生产，产品自动落入胶框内。', 'http://101.43.244.58:9000/ktg-mes/2022/08/28/微信图片_20211217104237_20220828091132A001.jpg', '', NULL, NULL, 0, 0, NULL, NULL, NULL, NULL);
INSERT INTO `md_product_sop` VALUES (2, 5, 2, 1, 'PROCESS1' , '注塑', '步骤2', '作业人员把产品和料头分开', 'http://101.43.244.58:9000/ktg-mes/2022/08/28/微信图片_20220512183640_20220828091246A002.jpg', '', NULL, NULL, 0, 0, NULL, NULL, NULL, NULL);
INSERT INTO `md_product_sop` VALUES (3, 5, 3, 1, 'PROCESS1' , '注塑', '步骤3', '操作首检核对SIP要求', 'http://101.43.244.58:9000/ktg-mes/2022/08/28/微信图片_20211208112600_20220828091332A003.jpg', '', NULL, NULL, 0, 0, NULL, NULL, NULL, NULL);

-- ----------------------------
-- Records of md_vendor
-- ----------------------------
INSERT INTO `md_vendor` VALUES (1, 'V00001', '江苏南通塑有为塑料制品有限公司', '南通有为', NULL, NULL, NULL, 'B', 6, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'Y', '', NULL, NULL, 0, 0, NULL, NULL, NULL, NULL);
INSERT INTO `md_vendor` VALUES (2, 'V00002', 'DUOMU', 'DUOMU', 'DUOMU', NULL, NULL, 'A', 5, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'Y', '', NULL, NULL, 0, 0, NULL, NULL, NULL, NULL);
INSERT INTO `md_vendor` VALUES (3, 'V00003', '乙方工厂', '1', '2', '3', '3', 'B', 2, '4', '1', '2', '3', '3', '3', '3', '3', '3', '3', '3', 'Y', '3', NULL, NULL, 0, 0, NULL, NULL, NULL, NULL);

INSERT INTO `sys_auto_code_result` (`rule_id`, `gen_date`, `gen_index`, `last_result`, `last_serial_no`) VALUES (3, '20220729122036', 3, 'V00003', 3);

-- ----------------------------
-- Records of md_workshop
-- ----------------------------
INSERT INTO `md_workshop` VALUES (1, 'WS001', '注塑车间', 0.00, NULL, 'Y', '', NULL, NULL, 0, 0, '', '2022-08-24 21:56:31', '', NULL);
INSERT INTO `md_workshop` VALUES (2, 'WS002', '五金车间', 0.00, NULL, 'Y', '', NULL, NULL, 0, 0, '', '2022-08-24 21:56:42', '', NULL);
INSERT INTO `md_workshop` VALUES (3, 'WS003', '组装车间', 0.00, NULL, 'Y', '', NULL, NULL, 0, 0, '', '2022-08-24 22:22:13', '', NULL);

INSERT INTO `sys_auto_code_result` (`rule_id`, `gen_date`, `gen_index`, `last_result`, `last_serial_no`) VALUES (4, '20220729122036', 3, 'WS003', 3);

-- ----------------------------
-- Records of md_workstation
-- ----------------------------
INSERT INTO `md_workstation` VALUES ( 1, 'WS0001', '0#注塑工作站', NULL, 1, 'WS001', '注塑车间', 1, 'PROCESS1', '注塑', 1, 'XBK_VIRTUAL', '线边库-虚拟', 1, 'XBKKQ_VIRTUAL', '线边库库区-虚拟', 1, 'XBKKW_VIRTUAL', '线边库库位-虚拟', 'Y', '', NULL, NULL, 0, 0, NULL, NULL, NULL, NULL);
INSERT INTO `md_workstation` VALUES ( 2, 'WS0002', '1#注塑工作站', NULL, 1, 'WS001', '注塑车间', 1, 'PROCESS1', '注塑', 1, 'XBK_VIRTUAL', '线边库-虚拟', 1, 'XBKKQ_VIRTUAL', '线边库库区-虚拟', 1, 'XBKKW_VIRTUAL', '线边库库位-虚拟', 'Y', '', NULL, NULL, 0, 0, NULL, NULL, NULL, NULL);
INSERT INTO `md_workstation` VALUES ( 3, 'WS0003', '2#注塑工作站', NULL, 1, 'WS001', '注塑车间', 1, 'PROCESS1', '注塑', 1, 'XBK_VIRTUAL', '线边库-虚拟', 1, 'XBKKQ_VIRTUAL', '线边库库区-虚拟', 1, 'XBKKW_VIRTUAL', '线边库库位-虚拟', 'Y', '', NULL, NULL, 0, 0, NULL, NULL, NULL, NULL);
INSERT INTO `md_workstation` VALUES ( 4, 'WS0004', '1#去浇口工作站', NULL, 1, 'WS001', '注塑车间', 2, 'PROCESS2', '去浇口', 1, 'XBK_VIRTUAL', '线边库-虚拟', 1, 'XBKKQ_VIRTUAL', '线边库库区-虚拟', 1, 'XBKKW_VIRTUAL', '线边库库位-虚拟', 'Y', '', NULL, NULL, 0, 0, NULL, NULL, NULL, NULL);
INSERT INTO `md_workstation` VALUES ( 5, 'WS0005', '1#去毛刺工作站', NULL, 1, 'WS001', '注塑车间', 3, 'PROCESS3', '去毛刺', 1, 'XBK_VIRTUAL', '线边库-虚拟', 1, 'XBKKQ_VIRTUAL', '线边库库区-虚拟', 1, 'XBKKW_VIRTUAL', '线边库库位-虚拟', 'Y', '', NULL, NULL, 0, 0, NULL, NULL, NULL, NULL);
INSERT INTO `md_workstation` VALUES ( 6, 'WS0006', '1#五金切割工作站', NULL, 2, 'WS002', '五金车间', 4, 'PROCESS4', '板材剪贴', 1, 'XBK_VIRTUAL', '线边库-虚拟', 1, 'XBKKQ_VIRTUAL', '线边库库区-虚拟', 1, 'XBKKW_VIRTUAL', '线边库库位-虚拟', 'Y', '', NULL, NULL, 0, 0, NULL, NULL, NULL, NULL);
INSERT INTO `md_workstation` VALUES ( 7, 'WS0007', '2#五金切割工作站', NULL, 2, 'WS002', '五金车间', 4, 'PROCESS4', '板材剪贴', 1, 'XBK_VIRTUAL', '线边库-虚拟', 1, 'XBKKQ_VIRTUAL', '线边库库区-虚拟', 1, 'XBKKW_VIRTUAL', '线边库库位-虚拟', 'Y', '', NULL, NULL, 0, 0, NULL, NULL, NULL, NULL);
INSERT INTO `md_workstation` VALUES ( 8, 'WS0008', '1#冲压工作站', NULL, 2, 'WS002', '五金车间', 5, 'PROCESS5', '冲压', 1, 'XBK_VIRTUAL', '线边库-虚拟', 1, 'XBKKQ_VIRTUAL', '线边库库区-虚拟', 1, 'XBKKW_VIRTUAL', '线边库库位-虚拟', 'Y', '', NULL, NULL, 0, 0, NULL, NULL, NULL, NULL);
INSERT INTO `md_workstation` VALUES ( 9, 'WS0009', '2#冲压工作站', NULL, 2, 'WS002', '五金车间', 5, 'PROCESS5', '冲压', 1, 'XBK_VIRTUAL', '线边库-虚拟', 1, 'XBKKQ_VIRTUAL', '线边库库区-虚拟', 1, 'XBKKW_VIRTUAL', '线边库库位-虚拟', 'Y', '', NULL, NULL, 0, 0, NULL, NULL, NULL, NULL);
INSERT INTO `md_workstation` VALUES (10, 'WS0010', '0#喷涂工作站', NULL, 2, 'WS002', '五金车间', 6, 'PROCESS6', '喷涂', 1, 'XBK_VIRTUAL', '线边库-虚拟', 1, 'XBKKQ_VIRTUAL', '线边库库区-虚拟', 1, 'XBKKW_VIRTUAL', '线边库库位-虚拟', 'Y', '', NULL, NULL, 0, 0, NULL, NULL, NULL, NULL);
INSERT INTO `md_workstation` VALUES (11, 'WS0011', '1#组装工作站', NULL, 3, 'WS003', '组装车间', 7, 'PROCESS7', '组装', 1, 'XBK_VIRTUAL', '线边库-虚拟', 1, 'XBKKQ_VIRTUAL', '线边库库区-虚拟', 1, 'XBKKW_VIRTUAL', '线边库库位-虚拟', 'Y', '', NULL, NULL, 0, 0, NULL, NULL, NULL, NULL);
INSERT INTO `md_workstation` VALUES (12, 'WS0012', '2#组装工作站', NULL, 3, 'WS003', '组装车间', 7, 'PROCESS7', '组装', 1, 'XBK_VIRTUAL', '线边库-虚拟', 1, 'XBKKQ_VIRTUAL', '线边库库区-虚拟', 1, 'XBKKW_VIRTUAL', '线边库库位-虚拟', 'Y', '', NULL, NULL, 0, 0, NULL, NULL, NULL, NULL);
INSERT INTO `md_workstation` VALUES (13, 'WS0013', '1#质检工作站', NULL, 3, 'WS003', '组装车间', 8, 'PROCESS8', 'QCC质检', 1, 'XBK_VIRTUAL', '线边库-虚拟', 1, 'XBKKQ_VIRTUAL', '线边库库区-虚拟', 1, 'XBKKW_VIRTUAL', '线边库库位-虚拟', 'Y', '', NULL, NULL, 0, 0, NULL, NULL, NULL, NULL);
INSERT INTO `md_workstation` VALUES (14, 'WS0014', '2#质检工作站', NULL, 3, 'WS003', '组装车间', 8, 'PROCESS8', 'QCC质检', 1, 'XBK_VIRTUAL', '线边库-虚拟', 1, 'XBKKQ_VIRTUAL', '线边库库区-虚拟', 1, 'XBKKW_VIRTUAL', '线边库库位-虚拟', 'Y', '', NULL, NULL, 0, 0, NULL, NULL, NULL, NULL);
INSERT INTO `md_workstation` VALUES (15, 'WS0015', '0#包装工作站', NULL, 3, 'WS003', '组装车间', 9, 'PROCESS9', '包装', 1, 'XBK_VIRTUAL', '线边库-虚拟', 1, 'XBKKQ_VIRTUAL', '线边库库区-虚拟', 1, 'XBKKW_VIRTUAL', '线边库库位-虚拟', 'Y', '', NULL, NULL, 0, 0, NULL, NULL, NULL, NULL);

INSERT INTO `sys_auto_code_result` (`rule_id`, `gen_date`, `gen_index`, `last_result`, `last_serial_no`) VALUES (11, '20220729122036', 15, 'WS0015', 15);

SET FOREIGN_KEY_CHECKS = 1;
