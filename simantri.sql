/*
Navicat MySQL Data Transfer

Source Server         : local
Source Server Version : 100125
Source Host           : localhost:3306
Source Database       : simantri

Target Server Type    : MYSQL
Target Server Version : 100125
File Encoding         : 65001

Date: 2018-06-24 22:08:19
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for admin
-- ----------------------------
DROP TABLE IF EXISTS `admin`;
CREATE TABLE `admin` (
  `user` varchar(45) DEFAULT NULL,
  `pass` varchar(45) DEFAULT NULL,
  `nama` varchar(255) DEFAULT NULL,
  `jk` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of admin
-- ----------------------------
INSERT INTO `admin` VALUES ('admin', 'admin', null, null);
INSERT INTO `admin` VALUES ('a', 'b', null, null);
INSERT INTO `admin` VALUES ('1', '4', '2', '3');

-- ----------------------------
-- Table structure for pasien
-- ----------------------------
DROP TABLE IF EXISTS `pasien`;
CREATE TABLE `pasien` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) DEFAULT NULL,
  `jk` varchar(255) DEFAULT NULL,
  `status` varchar(255) DEFAULT NULL,
  `umur` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of pasien
-- ----------------------------
