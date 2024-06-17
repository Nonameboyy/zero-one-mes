USE `zo_mes`;
SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

INSERT INTO `dv_machinery_type` VALUES ( 2, 'M_TYPE_001', '注塑机', 1, '0,1', 'Y', '这个是一种类型的裁剪机', NULL, NULL, 0, 0, '', '2022-05-08 19:50:41', '', '2022-08-22 09:47:02');
INSERT INTO `dv_machinery_type` VALUES ( 3, 'M_TYPE_002', '组装机', 1, '0,1', 'Y', '', NULL, NULL, 0, 0, '', '2022-05-08 19:50:57', '', NULL);
INSERT INTO `dv_machinery_type` VALUES ( 4, 'M_TYPE_003', '大型注塑机', 2, '0,1,2', 'Y', '', NULL, NULL, 0, 0, '', '2022-05-08 19:51:10', '', '2022-05-14 13:39:51');
INSERT INTO `dv_machinery_type` VALUES ( 5, 'M_TYPE_004', '大型组装机', 3, '0,1,3', 'Y', '', NULL, NULL, 0, 0, '', '2022-05-08 19:51:25', '', '2022-07-17 12:19:14');
INSERT INTO `dv_machinery_type` VALUES ( 6, 'M_TYPE_005', '包装机', 1, '0,1', 'Y', '', NULL, NULL, 0, 0, '', '2022-05-14 13:40:03', '', NULL);
INSERT INTO `dv_machinery_type` VALUES ( 7, 'M_TYPE_006', '清洗类', 1, '0,1', 'Y', '', NULL, NULL, 0, 0, '', '2022-05-14 13:43:59', '', '2022-05-14 13:44:11');
INSERT INTO `dv_machinery_type` VALUES ( 8, 'M_TYPE_007', '喷砂机', 7, '0,1,7', 'Y', '', NULL, NULL, 0, 0, '', '2022-05-14 13:44:23', '', NULL);
INSERT INTO `dv_machinery_type` VALUES ( 9, 'M_TYPE_008', '清洗机', 7, '0,1,7', 'Y', '', NULL, NULL, 0, 0, '', '2022-05-14 13:44:33', '', NULL);
INSERT INTO `dv_machinery_type` VALUES (10, 'M_TYPE_009', '检测类', 1, '0,1', 'Y', '', NULL, NULL, 0, 0, '', '2022-05-14 13:49:13', '', NULL);
INSERT INTO `dv_machinery_type` VALUES (11, 'M_TYPE_010', 'CCD检测台', 10, '0,1,10', 'Y', '', NULL, NULL, 0, 0, '', '2022-05-14 13:49:25', '', NULL);
INSERT INTO `dv_machinery_type` VALUES (12, 'M_TYPE_011', '臂架焊机', 1, '0,1', 'Y', '', NULL, NULL, 0, 0, '', '2022-08-17 15:32:56', '', NULL);
INSERT INTO `dv_machinery_type` VALUES (13, 'M_TYPE_012', '华远焊机', 1, '0,1', 'Y', '', NULL, NULL, 0, 0, '', '2022-08-17 15:33:16', '', NULL);
INSERT INTO `dv_machinery_type` VALUES (14, 'M_TYPE_013', '麦格米特焊机', 1, '0,1', 'Y', '', NULL, NULL, 0, 0, '', '2022-08-17 15:33:24', '', NULL);
INSERT INTO `dv_machinery_type` VALUES (15, 'M_TYPE_014', '测试类', 1, '0,1', 'Y', '', NULL, NULL, 0, 0, '', '2022-08-19 14:35:27', '', '2022-08-19 14:35:45');
INSERT INTO `dv_machinery_type` VALUES (16, 'M_TYPE_015', '纺织机', 1, '0,1', 'Y', '', NULL, NULL, 0, 0, '', '2022-08-21 19:03:44', '', NULL);

INSERT INTO `sys_auto_code_result` (`rule_id`, `gen_date`, `gen_index`, `last_result`, `last_serial_no`) VALUES (8, '20220729122036', 15, 'M_TYPE_015', 15);

SET FOREIGN_KEY_CHECKS = 1;
