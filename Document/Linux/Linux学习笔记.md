# Linux学习笔记

> 为什么要学Linux？
>
> 我们可以简单把操作系统分为两类、一类是个人桌面操作系统（Windows、MacOs）、一类是服务器操作系统（Linux）；在服务器操作系统这一块，Linux是当之无愧的King（基本都是用的Linux）而且我们无论是前端还是后端，所有的程序都是要运行在服务器的Linux系统上的，所以Linux对于程序员来说非常的重要。

`学习须知：一个字：敲！学完就敲，因为Linux这门课程是实践性很强的`

[TOC]

## 第一章 初识Linux

### 01 操作系统概述

#### 1、了解操作系统的作用

​	操作系统，就是软件的一类，用于连接用户与硬件；是用户和硬件之间的桥梁，用来管理和调度计算机硬件的工作。操作系统可以做很多事情：

- 调度CPU进行工作
- 调度内存进行工作
- 调度硬盘进行数据存储
- 调度网卡进行网络通讯
- 调度音响发出声音
- 调度打印机打印内容......

**`操作系统就是计算机的灵魂`**

#### 2、了解常见的操作系统

PC端：Windows、Linux、MacOs等....

移动端：Android、iOS、Harmony OS等...

------

### 02 Linux初识

#### 1、了解Linux系统的诞生

[【Linux入门】Linux发展史-腾讯云开发者社区-腾讯云](https://cloud.tencent.com/developer/article/2337226)

![林纳斯·本纳第克特·托瓦兹_百度百科](https://github.com/Coekyun-Dou/My-Learning-Diary/blob/main/Document/Linux/image/1.jpg?raw=true)

> 贴一张创始人的照片为我们的学习保驾护航 ^ _ ^
>
> 顺便说一句：Linux的创始人Linus Benedict Torvalds在编写Linux的时候还顺手发明了Git（膜拜膜拜！！！）

#### 2、了解什么是Linux内核

Linux主要由两部分组成：

- Linux系统内核
- 系统级应用程序

##### 内核提供了最核心的功能：

比如调度CPU、调度内存、调度文件系统、网络通讯、I/O等

> Linux的内核是免费开源的，任何人都可以下载内核源码并查看和修改
>
> 下载地址：https://www.kernel.org
>
> ![image-20250607211741551](https://github.com/Coekyun-Dou/My-Learning-Diary/blob/main/Document/Linux/image/2.png?raw=true)

*感兴趣的话可以下载瞧一瞧*

##### 系统级应用程序可供用户快速上手操作系统：

如文件管理器、任务管理器等等......

#### 3、了解常见的Linux发行版

​	我们每个人都能拿到开源的Linux内核，那么我们自己编写系统级应用程序，就相当于封装了完整的Linux系统，这就是封装了一个Linux发行版。

那么这样子市面上就会有很多Linux发行版：

![image-20250607212030683](https://github.com/Coekyun-Dou/My-Learning-Diary/blob/main/Document/Linux/image/3.png?raw=true)

> 在本系列的学习中，我们主要使用CentOS（国外用得多）以及Ubuntu（国内用的多）来学习Linux

关于不同的发现版：

- 基础的命令100%是相同的
- 只有小部分操作是不同的
- 不管用什么发行版来学习，学到的东西都是通用的

------

### 03 虚拟机介绍

#### 1、了解什么是虚拟机

#### 2、了解为什么要使用虚拟机