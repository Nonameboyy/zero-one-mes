USE `zo_mes`;

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Records of qc_defect
-- ----------------------------
INSERT INTO `qc_defect` VALUES (1, 'DF001', '外观缺陷', 'APPEARANCE', 'MIN', '', NULL, NULL, 0, 0, '', '2022-05-19 11:37:13', '', '2022-08-18 16:34:07');
INSERT INTO `qc_defect` VALUES (2, 'DF002', '气孔和夹渣', 'APPEARANCE', 'MIN', '', NULL, NULL, 0, 0, '', '2022-05-19 11:37:38', '', '2022-08-18 16:34:22');
INSERT INTO `qc_defect` VALUES (3, 'DF003', '裂纹', 'APPEARANCE', 'MAJ', '', NULL, NULL, 0, 0, '', '2022-05-19 11:37:59', '', '2022-08-18 16:34:41');
INSERT INTO `qc_defect` VALUES (4, 'DF004', '未焊透', 'APPEARANCE', 'CR', '', NULL, NULL, 0, 0, '', '2022-05-19 11:38:49', '', '2022-08-18 16:35:01');
INSERT INTO `qc_defect` VALUES (5, 'DF005', '未熔合', 'SIZE', 'CR', '', NULL, NULL, 0, 0, '', '2022-05-19 11:38:59', '', '2022-08-18 16:35:11');
INSERT INTO `qc_defect` VALUES (6, 'DF006', '测试人员太差', 'PERFORMANCE', 'MIN', '', NULL, NULL, 0, 0, '', '2022-08-19 14:45:46', '', NULL);

INSERT INTO `sys_auto_code_result` (`rule_id`, `gen_date`, `gen_index`, `last_result`, `last_serial_no`) VALUES (19, '20220729122036', 6, 'DF006', 6);

-- ----------------------------
-- Records of qc_index
-- ----------------------------
INSERT INTO `qc_index` VALUES ( 1, 'I0001', '长度', 'WEIGHT', '卡尺', '', NULL, NULL, 0, 0, '', '2022-05-17 21:58:30', '', '2022-08-19 22:59:05');
INSERT INTO `qc_index` VALUES ( 2, 'I0002', '高度', 'SIZE', '卡尺', '', NULL, NULL, 0, 0, '', '2022-05-17 21:58:43', '', NULL);
INSERT INTO `qc_index` VALUES ( 3, 'I0003', '宽度', 'SIZE', '卡尺', '', NULL, NULL, 0, 0, '', '2022-05-17 21:58:55', '', NULL);
INSERT INTO `qc_index` VALUES ( 4, 'I0004', '外径', 'SIZE', '尺子', '', NULL, NULL, 0, 0, '', '2022-05-17 21:59:09', '', NULL);
INSERT INTO `qc_index` VALUES ( 5, 'I0005', '内径', 'SIZE', '卡尺', '', NULL, NULL, 0, 0, '', '2022-05-17 21:59:22', '', NULL);
INSERT INTO `qc_index` VALUES ( 6, 'I0006', '毛重', 'WEIGHT', '电子秤', '', NULL, NULL, 0, 0, '', '2022-05-17 21:59:48', '', NULL);
INSERT INTO `qc_index` VALUES ( 7, 'I0007', '净重', 'WEIGHT', '电子秤', '', NULL, NULL, 0, 0, '', '2022-05-17 22:00:04', '', NULL);
INSERT INTO `qc_index` VALUES ( 8, 'I0008', '是否破损', 'APPEARANCE', '目视', '', NULL, NULL, 0, 0, '', '2022-05-17 22:00:31', '', NULL);
INSERT INTO `qc_index` VALUES ( 9, 'I0009', '是否污渍', 'APPEARANCE', '目视', '', NULL, NULL, 0, 0, '', '2022-05-17 22:00:46', '', NULL);
INSERT INTO `qc_index` VALUES (10, 'I0010', '是否变形', 'APPEARANCE', '目视', '', NULL, NULL, 0, 0, '', '2022-05-17 22:01:00', '', NULL);
INSERT INTO `qc_index` VALUES (11, 'I0011', '色泽', 'APPEARANCE', '目视', '', NULL, NULL, 0, 0, '', '2022-05-17 22:01:17', '', '2022-05-18 16:47:26');
INSERT INTO `qc_index` VALUES (12, 'I0012', '文字标识', 'APPEARANCE', '目视', '', NULL, NULL, 0, 0, '', '2022-05-18 16:43:45', '', NULL);

INSERT INTO `sys_auto_code_result` (`rule_id`, `gen_date`, `gen_index`, `last_result`, `last_serial_no`) VALUES (17, '20220729122036', 12, 'I0012', 12);

-- ----------------------------
-- Records of qc_template
-- ----------------------------
INSERT INTO `qc_template` VALUES (1, 'QCT2022001', '螺丝刀刀柄检测', 'FIRST,FINAL,PATROL,FQC', 'Y', '', NULL, NULL, 0, 0, '', '2022-08-29 22:42:35', '', '2022-08-29 22:45:16');
INSERT INTO `qc_template` VALUES (2, 'QCT2022002', '钢板来料检验模板', 'IQC', 'Y', '', NULL, NULL, 0, 0, '', '2022-08-31 21:01:38', '', '2022-08-31 21:03:50');
INSERT INTO `qc_template` VALUES (3, 'QCT2022003', '螺丝刀出货检验模板', 'OQC', 'Y', '', NULL, NULL, 0, 0, '', '2022-09-01 21:25:14', '', '2022-09-01 21:26:59');
INSERT INTO `qc_template` VALUES (4, 'QCT2022004', '螺丝刀刀头检测模板', 'FIRST,FINAL,PATROL,SELF', 'Y', '', NULL, NULL, 0, 0, '', '2023-10-17 16:29:10', '', '2023-10-18 16:01:31');
INSERT INTO `qc_template` VALUES (5, 'QCT2022005', '色粉检验', 'IQC', 'Y', '', NULL, NULL, 0, 0, '', '2023-10-19 14:22:33', '', '2023-10-19 14:23:20');

INSERT INTO `sys_auto_code_result` (`rule_id`, `gen_date`, `gen_index`, `last_result`, `last_serial_no`) VALUES (18, '20220729122036', 5, 'QCT2022005', 5);

-- ----------------------------
-- Records of qc_template_index
-- ----------------------------
INSERT INTO `qc_template_index` VALUES ( 1, 1,  1, 'I0001', '长度', 'WEIGHT', '卡尺', NULL, 10.0000, 'cm', 1.0000, -1.0000, NULL, '', NULL, NULL, 0, 0, '', '2022-08-29 22:43:01', '', NULL);
INSERT INTO `qc_template_index` VALUES ( 2, 1,  4, 'I0004', '外径', 'SIZE', '尺子', NULL, 10.0000, 'mm', 0.1000, -0.1000, NULL, '', NULL, NULL, 0, 0, '', '2022-08-29 22:43:41', '', NULL);
INSERT INTO `qc_template_index` VALUES ( 3, 1,  7, 'I0007', '净重', 'WEIGHT', '电子秤', NULL, 100.0000, 'g', 5.0000, -5.0000, NULL, '', NULL, NULL, 0, 0, '', '2022-08-29 22:44:06', '', NULL);
INSERT INTO `qc_template_index` VALUES ( 4, 2,  1, 'I0001', '长度', 'WEIGHT', '卡尺', NULL, 100.0000, 'm', 0.1000, -0.1000, NULL, '', NULL, NULL, 0, 0, '', '2022-08-31 21:02:28', '', NULL);
INSERT INTO `qc_template_index` VALUES ( 5, 2,  3, 'I0003', '宽度', 'SIZE', '卡尺', NULL, 1.0000, 'm', 0.0500, -0.0500, NULL, '', NULL, NULL, 0, 0, '', '2022-08-31 21:03:20', '', NULL);
INSERT INTO `qc_template_index` VALUES ( 6, 3,  8, 'I0008', '是否破损', 'APPEARANCE', '目视', '外包装箱无破损', NULL, NULL, 0.0000, 0.0000, NULL, '', NULL, NULL, 0, 0, '', '2022-09-01 21:25:54', '', NULL);
INSERT INTO `qc_template_index` VALUES ( 7, 3,  9, 'I0009', '是否污渍', 'APPEARANCE', '目视', '外包装箱是否有污渍', NULL, NULL, 0.0000, 0.0000, NULL, '', NULL, NULL, 0, 0, '', '2022-09-01 21:26:21', '', NULL);
INSERT INTO `qc_template_index` VALUES ( 8, 3, 10, 'I0010', '是否变形', 'APPEARANCE', '目视', '外包装箱无明显变形', NULL, NULL, 0.0000, 0.0000, NULL, '', NULL, NULL, 0, 0, '', '2022-09-01 21:26:36', '', NULL);
INSERT INTO `qc_template_index` VALUES ( 9, 4,  1, 'I0001', '长度', 'WEIGHT', '卡尺', NULL, 10.0000, 'cm', 2.0000, -2.0000, NULL, '', NULL, NULL, 0, 0, '', '2023-10-17 16:29:51', '', NULL);
INSERT INTO `qc_template_index` VALUES (10, 4,  8, 'I0008', '是否破损', 'APPEARANCE', '目视', '1111', 11.0000, 'g', 0.5000, -0.5000, NULL, '', NULL, NULL, 0, 0, '', '2023-10-19 14:23:03', '', NULL);

-- ----------------------------
-- Records of qc_template_product
-- ----------------------------
INSERT INTO `qc_template_product` VALUES (1, 1, 5, 'IF20220824028', '螺丝刀刀柄', '10CM', 'PCS', 10, 2, 0.00, 0.00, 100.00, '', NULL, NULL, 0, 0, '', '2022-08-29 22:45:06', '', NULL);
INSERT INTO `qc_template_product` VALUES (2, 2, 4, 'IF20220824004', '钢筋', '100mm X  50mm', 'm', 10, 0, 0.00, 0.00, 100.00, '', NULL, NULL, 0, 0, '', '2022-08-31 21:03:46', '', NULL);
INSERT INTO `qc_template_product` VALUES (3, 3, 7, 'IF20220824039', '螺丝刀', NULL, 'PCS', 1, 0, 0.00, 0.00, 100.00, '', NULL, NULL, 0, 0, '', '2022-09-01 21:26:46', '', NULL);
INSERT INTO `qc_template_product` VALUES (4, 4, 6, 'IF20220824016', '螺丝刀刀头', '15CM', 'PCS', 1, 0, 0.00, 0.00, 100.00, '', NULL, NULL, 0, 0, '', '2023-10-17 16:30:02', '', NULL);
INSERT INTO `qc_template_product` VALUES (5, 5, 2, 'IF20220824037', '色粉【黑色】', '黑色', 'g', 1, 0, 0.00, 0.00, 100.00, '', NULL, NULL, 0, 0, '', '2023-10-19 14:23:18', '', NULL);

-- ----------------------------
-- Records of tm_tool_type
-- ----------------------------
INSERT INTO `tm_tool_type` VALUES (1, 'TT001', '刀具', 'N', NULL, NULL, '', NULL, NULL, 0, 0, '', '2022-05-11 00:24:04', '', NULL);
INSERT INTO `tm_tool_type` VALUES (2, 'TT002', '模具', 'Y', 'USAGE', 500000, '', NULL, NULL, 0, 0, '', '2022-05-11 00:28:22', '', '2022-08-16 18:56:56');
INSERT INTO `tm_tool_type` VALUES (3, 'TT003', '夹具', 'Y', 'USAGE', 30, '', NULL, NULL, 0, 0, '', '2022-05-11 00:28:46', '', '2022-08-16 19:58:17');
INSERT INTO `tm_tool_type` VALUES (4, 'TT004', '测试工具', 'Y', 'REGULAR', 13, '', NULL, NULL, 0, 0, '', '2022-08-19 15:04:41', '', NULL);

INSERT INTO `sys_auto_code_result` (`rule_id`, `gen_date`, `gen_index`, `last_result`, `last_serial_no`) VALUES (12, '20220729122036', 4, 'TT004', 4);

SET FOREIGN_KEY_CHECKS = 1;
