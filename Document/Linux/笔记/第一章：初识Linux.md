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

所谓虚拟机，就是通过虚拟化技术，在系统中通过软件模拟计算机硬件，并给虚拟硬件安装真实的操作系统，虚拟出一个完整的电脑。

（补充虚拟机截图）

> 注意：所谓虚拟不是随便虚拟的，也是要基于我们自己电脑的硬件配置来虚拟，不能是1050显卡虚拟出5090的显卡吧/doge/

#### 2、了解为什么要使用虚拟机

我们要学习Linux系统，就要有一个可用的Linux系统，但是重装系统会导致我们难以用Linux系统完成一些办公工作，因此需要借助虚拟机来获得可用的Linux系统环境。

------

### 04 VMware Workstation的安装

#### 1、了解 VMware Workstation软件

Q1：通过虚拟化技术，可以虚拟出计算机硬件，那么如何虚拟呢？

> 可以通过提供虚拟化的软件来获得虚拟机

#### 2、完成 VMware Workstation软件的安装

1）下载VMware WorkStation并安装

教程与步骤：[2025.5最新VMware Workstation Pro下载安装教程-CSDN博客](https://blog.csdn.net/wfchhhjj/article/details/144316131?ops_request_misc=%7B%22request%5Fid%22%3A%22dfbd587def8846fbfca22022030f228c%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=dfbd587def8846fbfca22022030f228c&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-144316131-null-null.142^v102^pc_search_result_base7&utm_term=vmware下载安装教程&spm=1018.2226.3001.4187)

> 注意：17.6.2版本完全免费了，不需要密钥了^ _ ^（这也对我们学生党、初学者比较友好了）

2）检查网络适配器是否正常

win+R 输入以下指令

```cmd
ncpa.cpl
```

检查有没有`vmnet1`   和   `vmnet8`

![image-20250608011651077](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250608011651077.png)

有的话就说明下载安装成功了，如果没有的话就是安装出了问题，卸载重启电脑重新安装试一试吧

------

### 05 在VMware WorkStation中安装CentOS7 Linux操作系统

1）下载操作系统的安装文件，

https://vault.centos.org/7.6.1810/isos/x86_64/

选中DVD-1810.iso的文件即可

![image-20250608042545076](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250608042545076.png)

2）创建虚拟机，并等待操作系统安装完成

详细步骤可见：https://www.bilibili.com/list/watchlater?bvid=BV1n84y1i7td&p=6

------

### 06 远程连接Linux系统

#### 1、掌握操作系统的图形化、命令行2种操作模式

​	所有操作系统都有这两种使用方式

- 图形化：使用操作系统提供的图形化页面，以获得图形化反馈的形式去使用操作系统
- 命令行：使用操作系统提供的各类命令，以获得字符反馈的形式去使用操作系统

#### 2、理解为什么使用命令行操作Linux系统

在Linux操作系统上，无论是企业开发还是个人开发，多数情况使用的是：**命令行**

因为Linux的图形化的优化不好，不好用、不稳定

在开发中，使用命令行效率更高，更直观，资源占用更低，程序运行更稳定。

#### 3、使用FinalShell软件连接Linux操作系统

Q：为什么要用FinalShell？

因为我们在Windows系统和Linux系统的各类交互中，跨越VMware不方便，所以要通过第三方软件FinalShell，远程连接到Linux系统之上，并通过FinalShell去操作它。

安装配置教程：https://www.bilibili.com/list/watchlater?bvid=BV1n84y1i7td&p=8

注意：Linux虚拟机如果重启，有可能发生IP改变，如果改变IP需要在FinalShell中修改连接的IP地址（在虚拟机中输入ifconfig，然后再FinalShell中修改一下）；也可以配置静态IP

------

### 07 拓展：WSL(Windows Subsystem for Linux)

> 学习目标，掌握使用WSL获得Ubuntu系统环境，WSL功能是帮助我们更好地获得Linux操作系统环境。

通过WSL，可以以非常轻量化的方式，得到Linux系统环境，所以开发者正逐步抛弃以虚拟机的形式获取Linux系统环境，逐步拥抱WSL环境

#### 什么是WSL

WSL：Windows Subsystem for Linux，适用于Windows系统之上的Linux子系统；作用很简单，可以再Windows系统中获得Linux系统环境，并且完全直连计算机硬件，无需通过虚拟机虚拟硬件。

使用教程：https://www.bilibili.com/list/watchlater?bvid=BV1n84y1i7td&p=9

与虚拟机中的操作系统不一样的是，wsl构建的操作系统是没有图形化的，只有命令行操作系统

------

### 08 拓展：虚拟机快照

> 本节任务：掌握虚拟机快照的制作和还原

#### 1、什么是虚拟机快照

在我们学习阶段，我们无可避免地可能损坏Linux操作系统。如果损坏的话，重装一个就会特别麻烦，所以我们可以通过虚拟机快照，把当前虚拟机的状态保存下来，在以后**通过快照恢复的方式恢复到虚拟机保存的状态**。

> 俗称：存档/doge/

#### 2、在VMware中制作并还原快照

> 推荐，虚拟机关机之后再去制作快照，这样的效率会高一点

1）

![image-20250609003447769](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250609003447769.png)

2）

![image-20250609003515900](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250609003515900.png)

3）

![image-20250609003530012](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250609003530012.png)

------

