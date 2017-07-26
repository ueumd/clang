-- MySQL dump 10.13  Distrib 5.5.40, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: d0718
-- ------------------------------------------------------
-- Server version	5.5.40-0ubuntu0.14.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `tcontact`
--

DROP TABLE IF EXISTS `tcontact`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tcontact` (
  `username` varchar(32) NOT NULL,
  `mobile` varchar(16) NOT NULL,
  `mobile2` varchar(16) NOT NULL,
  `telephone` varchar(32) DEFAULT NULL,
  `home` varchar(32) DEFAULT NULL,
  `homeaddr` varchar(1024) DEFAULT NULL,
  `company` varchar(128) DEFAULT NULL,
  `companyaddr` varchar(1024) DEFAULT NULL,
  `title` varchar(16) DEFAULT NULL,
  PRIMARY KEY (`mobile`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tcontact`
--

LOCK TABLES `tcontact` WRITE;
/*!40000 ALTER TABLE `tcontact` DISABLE KEYS */;
INSERT INTO `tcontact` VALUES ('sdfsdf','1111','23123','123123','12312312','123213','12323','123123','123123'),('xueguoliang','13381285235','','','','haidian qinghewenyuan 1#2210','itcast','xisanqi jiancaichengxilu','teacher'),('tut','13399891122','123123','123123213','1222','32222','fsdfsdf','wee','wfwe');
/*!40000 ALTER TABLE `tcontact` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tuser`
--

DROP TABLE IF EXISTS `tuser`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tuser` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT 'this is userid',
  `username` varchar(32) NOT NULL COMMENT 'username',
  `password` varchar(32) NOT NULL COMMENT 'password',
  `gender` int(11) NOT NULL COMMENT '1 is male 0 is female',
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=12323 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tuser`
--

LOCK TABLES `tuser` WRITE;
/*!40000 ALTER TABLE `tuser` DISABLE KEYS */;
INSERT INTO `tuser` VALUES (7,'newuser1','newpassword',0),(8,'aaaa','bbb',2),(11,'121212','12121',12323),(12321,'1212','121',121),(12322,'sdfsdf','sdfsd',0);
/*!40000 ALTER TABLE `tuser` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2014-12-14 17:15:47
