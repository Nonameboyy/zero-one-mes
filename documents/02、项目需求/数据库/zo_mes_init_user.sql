-- ----------------------------
--  Change database
-- ----------------------------
USE `zo_mes`;

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Records of sys_user
-- ----------------------------
INSERT INTO `sys_user` VALUES (1, 4, 'admin', '管理员', '00', 'admin@163.com', '13299106672', '0', '/profile/avatar/2024/04/11/blob_20240411220241A003.jpeg', '$2a$10$7JB720yubVSZvUI0rEqK/.VqGOZTH.ulu33dHOiBE8ByOhJIrdAu2', '0', '0', '127.0.0.1', '2024-04-11 16:58:05', 'admin', '2022-04-07 00:29:31', '', '2024-04-11 16:58:02', '管理员');

-- ----------------------------
-- Records of sys_user_post
-- ----------------------------
INSERT INTO `sys_user_post` VALUES (1, 1);

-- ----------------------------
-- Records of sys_user_role
-- ----------------------------
INSERT INTO `sys_user_role` VALUES (1, 1);

SET FOREIGN_KEY_CHECKS = 1;
