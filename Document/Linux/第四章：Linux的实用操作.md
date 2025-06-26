## 第四章：Linux的实用操作

**`From Felix Du`**

[TOC]

------

### 01 各类小技巧快捷键

#### 1、`ctrl+C`强制停止

- Linux某些程序的运行，如果想要强制停止它，可以使用快捷键`ctrl+c`
- 命令输入错误，也可以通过快捷键`ctrl+c` , 退出当前输入，重新输入

![image-20250615222548223](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250615222548223.png)

#### 2、`ctrl+D`退出、登出

- 可以通过快捷键：`ctrl+D` ，退出账号的登录
- 或者退出某些特定程序的专属页面

![image-20250615222750006](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250615222750006.png)

> 注意：不能用于退出vi/vim
>
> python是Linux自带的，不用专门去安装

#### 3、历史命令搜索

- 可以通过`history`命令，查看历史输入过的命令

![image-20250615222925896](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250615222925896.png)

> 序号越大的就是离得越近，同样可以用grep命令来筛选

- 可以通过：`!命令前缀`，自动执行上一次匹配前缀的命令

![image-20250615223155535](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250615223155535.png)

- 可以通过快捷键`ctrl+r` ，输入内容去匹配历史命令

![image-20250615223319449](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250615223319449.png)

如果搜索到的内容是你需要的，那么：

- 回车键可以 直接执行
- 键盘左右键，可以得到此命令（不执行）

#### 4、光标移动

- `ctrl+a`，跳到命令开头
- `ctrl+e`，跳到命令结尾
- `ctrl+键盘左键`，向左跳一个单词
- `ctrl+键盘右键`，向右跳一个单词

#### 5、清屏

- 可以通过快捷键`ctrl+l`，可以清空终端内容
- 或通过命令clear得到同样效果

------

### 02 软件安装

> 学会使用yum为CentOS系统安装软件，以及用apt为Ubuntu安装软件（拓展）

操作系统安装软件有许多种方式，一般分为：

- 下载安装包自行安装

  - 如win系统使用exe文件、msi文件等
  - mac系统使用dmg文件、pkg文件等

- 系统的应用商店内安装

  - 如win系统有Microsoft Store商店
  - mac系统有 AppStore商店

  Linux同样支持这两种方式，yum就是Linux命令行内的“应用商店”

#### 1、yum命令

yum：RPM包软件管理器，用于自动化安装配置Linux软件，并可以自动解决依赖问题。语法如下:

```shell
yun [-y] [install | remove | search] 软件名称
```

- 选项：-y，自动确认，无需手动确认安装或卸载过程
- install：安装
- remove：卸载
- search：搜索

> 注意：yum命令需要root权限，可以su切换到root，或使用sudo提权。且yum命令需要联网

- 例如：`yum [-y] install wget`，通过yum命令安装wget程序

这里如果报错了的话：显示无法找到wget可以参考下面这个博客，把mirror改成aliyun的即可：

[使用yum search wget 出现Loaded plugins: fastestmirror, langpacks的报错-CSDN博客](https://blog.csdn.net/llgl56789/article/details/141432897?ops_request_misc=&request_id=&biz_id=102&utm_term=yum search wget失败&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-0-141432897.142^v102^pc_search_result_base7&spm=1018.2226.3001.4187)

#### 2、apt命令-扩展

前面学习的各类Linux命令都是通用的。但是软件安装，CentOS系统和Ubuntu是使用不同的包管理器的。CentOS使用yum管理器，Ubuntu使用apt管理器，语法如下：

```shell
apt [-y] [install | remove | search] 软件名称
```

用法与yum一致，同样需要root权限

- apt install wget，安装wget
- apt remove wget ，移除wget
- apt search wget，搜索wget

------

### 03 systemctl控制软件启动关闭

Linux系统很多软件（内置或第三方）均支持使用systemctl命令控制：启动、停止、开机自启 ；能够被systemctl管理的软件，一般也称之为：服务，语法如下：

```shell
systemctl start | stop | status | enable| disable 服务名
```

- stop：关闭
- start：启动
- status：查看状态
- enable：开启开机自启
- disable：关闭开机自启

系统内置的服务比较多，比如：

- NetworkManager：主网络服务
- network：副网络服务
- firewalled：防火墙服务
- sshd，ssh服务（FinalShell远程登录Linux用的就是这个服务）

除了内置的服务以外，部分第三方软件安装后也可以通过systemctl进行控制

<img src="C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250616101036713.png" alt="image-20250616101036713" style="zoom:80%;" />

【注意】有部分软件安装后没有自动集成到systemctl中，这就需要我们手动添加。

------

### 04 软链接

#### 1、ln命令创建软链接

在系统中创建软链接，可以 将文件、文件夹连接到其它位置。类似于Windows系统中的《快捷方式》，语法如下：

```shell
ln -s 参数1 参数2
```

- -s 选项，创建软链接
- 参数1：被链接的文件或文件夹
- 参数2：要链接去的目的地

实例：

- `ln -s /etc/yum.conf~/yum.conf`
- `ln -s /etc/yum~/yum`

------

### 05 日期和时区

#### 1、date命令查看时间

通过date命令可以在命令行中查看系统的时间，语法如下：

```shell
date [-d] [+格式化字符]
```

- -d 按照给定字符显示日期，一般用于日期计算

![image-20250616103021332](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250616103021332.png)

- 格式化字符：通过特定的字符串标记，来控制显示的日期格式
  - %Y：年
  - %y：年份后两位数字（范围 00~99）
  - %m：月份
  - %d：日
  - %H：小时
  - %M：分钟
  - %S：秒
  - %s：自1970-01-01 00:00:00 UTC到现在的秒数（也就是时间戳）

#### 2、修改Linux系统的时区

我们可以发现，现在用date命令查看的日期时间是不准确的，这是因为：**系统默认时区是非中国的东八区**

我们可以使用root权限，执行如下命令，修改时区为东八区时区

```shel
rm -f /etc/localtime
sudo ln -s /usr/share/zoneinfo/Asia/Shanghai /etc/localtime
```

将系统自带的localtime文件删除，并将`/usr/share/zoneinfo/Asia/Shanghai /etc/localtime`  链接到localtime就可以了

#### 3、使用ntp进行时间同步和校准

>  我们可以通过ntp程序自动校准系统时间

安装ntp：yum install ntp

启动并设置开机自启：

- systemctl start ntpd
- systemctl enable ntpd

当ntpd启动后会定期帮助我们联网校准系统时间

- 也可以手动校准（需要root权限）：ntpdate -u ntp.aliyun.com

通过阿里云提供的服务完整配合ntpdate实现手动校准

------

### 06 IP地址和主机名

#### 1、什么是ip地址

每一台联网的电脑都会有一个地址，用于和其他计算机进行通讯

ip地址主要有两个版本（V4和V6）

IPV4的地址格式是`a.b.c.d` 其中abcd表示0~255的数字

可以通过命令：`ifconfig` ，查看本机的ip地址，如无法使用ifconfig命令，可以安装：`yum -y install net-tools`

![image-20250617003001980](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250617003001980.png)

#### 2、特殊的IP地址

除了标准的IP地址外，还有几个特殊的IP地址需要我们了解：

- 127.0.0.1，这个地址用于指代本机
- 0.0.0.0 特殊IP地址
  - 可用于指代本机
  - 可以在端口绑定用来确定绑定关系
  - 在一些IP地址限制中，表示所有IP的意思，如放行规则设置为0.0.0.0，表示允许任意IP访问

#### 3、主机名

每台电脑除了对外联络地址（IP地址）以外，也可以有一个名字，称之为主机名。无论是Windows或Linux，都可以给系统设置主机名

- Linux系统的主机名可用命令`hostname` 查看
- 可以用`hostnamectl set-hostname 主机名`，修改主机名（需root）
- 重新登陆后就可以发现主机名已经被更改了

#### 4、域名解析

IP地址难以记忆，所以我们一直通过域名去访问服务器，很少指定IP地址，例如www.baidu.com，其中baidu.com就是他的域名，而不是他的IP地址

> 域名解析其实就是字符到IP地址的映射
>
> 具体的只是可以查阅计算机网络课程相关知识；

------

### 07 配置Linux固定IP地址

#### 1）为什么需要固定IP

当前我们虚拟机的Linux操作系统，其IP地址是通过DHCP服务获取的。

DHCP：动态获取IP地址，即每次重启设备后都会获取一次，可能导致IP地址频繁变更，导致我们远程连接Linux和映射关系需要不断去变更以适配新的IP

#### 2）步骤：

https://www.bilibili.com/video/BV1n84y1i7td?spm_id_from=333.788.videopod.episodes&p=35

------

### 08 网络请求和下载

#### 1、用ping命令检查服务器是否可联通

可以通过ping命令，检查指定的网络服务器是否是可联通的状态，语法如下：

```shell
ping [-c num] ip或主机名
```

- 选项：-c，检查的次数，不使用-c选项，将无限次数持续检查
- 参数：ip或主机名，被检查的服务器的IP地址或主机名地址

#### 2、使用wget命令下载文件

wget是一个非交互式的文件下载器，可以在命令行内下载网络文件，语法如下：

```shell
wger [-b] url
```

- 选项：-b，可选，后台下载，会将日志写入当前工作目录的wget-log文件
- 参数：url，下载链接

#### 3、使用curl命令发起网络请求

curl可以发送http网络请求，可用于：下载文件、获取信息等，语法如下：

```shell
curl [-O] url
```

- 选项：-O，用于下载文件，当url是下载链接时，可以使用此选项保存文件
- 参数：url，要发起请求的网络地址

------

### 09 端口

#### 1、端口的概念

​	端口，是设备与外界通讯交流的出入口。端口可以分为：物理端口和虚拟端口两类。

- 物理端口：又可称之为接口，是可见的端口，如USB接口，RJ45网口，HDMI端口等
- 虚拟端口：是指计算机内部的端口，是不可见的，是用来操作系统和外部进行交互使用的

![image-20250618215210529](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250618215210529.png)

![image-20250618215331713](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250618215331713.png)

计算机程序之间的通讯，通过IP只能锁定计算机，但是无法锁定具体的程序

通过端口可以锁定计算机上具体的程序，确保程序之间进行沟通

IP地址相当于小区地址，在小区内可以有许多住户（程序），而门牌号（端口）就是各个住户（程序）的联系地址

##### 2、Linux的端口划分

![image-20250618215607074](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250618215607074.png)

##### 3、查看端口占用

我们可以通过Linux中的`nmap`命令去查看端口的占用情况

- 使用 `nmap` 命令，安装`nmap：yum -y install nmap`

语法如下：

```shell
nmap 被查看的IP地址
```

#### 2、netstat命令的基本使用

也可以通过 `netstat` 命令，查看指定端口的占用情况，语法如下：

```shell
netstat -anp|grep 端口号
```

 需要通过安装netstat:`yum -y install net-tools`

比如：`netstat -anp|grep 6000` 这样就可以查看当前系统6000端口被程序的占用情况

------

### 10 进程管理

#### 1、进程的概念

程序运行在操作系统中，是被操作系统所管理的。为管理运行的程序，每一个程序在运行的时候，便被操作系统注册为系统中的一个：进程；并会为每一个进程都分配一个独有的：进程ID（进程号）

![image-20250619010052253](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250619010052253.png)

#### 2、查看与关闭进程

##### 1）查看进程

可以通过ps命令查看Linux系统中的进程信息，语法如下：

```shell
ps [-e -f]
```

- 选项：-e，显示出全部的进程
- 选项：-f，以完全格式化的形式展示信息（展示全部信息）

一般来说，**固定用法就是**：ps -ef 列出全部进程的全部信息

![image-20250619010343260](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250619010343260.png)

##### 2）查看指定进程

- 在FinalShell中，执行命令 `tail` ，可以看到，此命令一直阻塞在那里
- 在FinalShell中，复制一个标签页，执行：`ps -ef` 找出tail这个程序的进程信息
- 问题：是否会发现，列出的信息太多，无法准确的找到或很麻烦怎么办？

我们可以使用管道符配合 `grep`  来进行过滤，如：

```shell
grep -ef|grep tail
```

即可准确找到tail命令的信息

- 过滤不仅仅过滤名称，进程号，用户ID等等，都可以被grep过滤
- 如：ps -ef|grep 30001，过滤带有30001关键字的进程信息(一般指代过滤30001进程号)

##### 3）关闭进程

在Windows系统中，可以通过任务管理器选择进程后，点击结束进程从而关闭它。同样，在Linux中，可以通过kill命令关闭进程。语法如下：

```shell
kill [-9] 进程ID
```

选项：-9 表示强制关闭进程，不适用此选项会向进程发送信号要求其关闭，但是否关闭看进程自身的处理机制。

![image-20250619011520182](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250619011520182.png)

------

### 11 主机状态监控

#### 1、查看系统资源占用

- 可以通过top命令查看CPU、内存使用情况，类似Windows的任务管理器

>  默认**每5秒刷新一次**，语法：**直接输入`top` 即可，按`q` 或 `ctrl + c`退出 

![image-20250623205918463](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250623205918463.png)

- 第一行：`top - 14:39:58 up 6min, 2users ,load average:0.06,0.17,0.13`

> top：命令名称，14:39:58 当前系统时间，up 6min 启动了6分钟，2users 两个用户登录 load：1、5、15分钟负载

- 第二行`Task:175 total ,1 running, 174 sleeping, 0stopped, 0 zombie`

> Task：175个进程，1running：1个进程子在运行，174 sleeping：174个进程睡眠，0个停止进程，0个僵尸进程

- 第三行：`%Cpu(s): 0.3us, 1.4 sy, 0.0ni, 98.3 id, 0.0wa, 0.0hi, 0.0si, 0.0st`

> %Cpu(s)：CPU使用率，us：用户CPU使用率，sy：系统CPU使用率，ni：高优先级进程占用CPU时间百分比；id：空闲CPU率，wa：IO等待CPU占有率，hi：CPU硬件中断率，si：CPU软件中断率，st 强制等待占用CPU率

- 第四、五行：

![image-20250623210803810](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250623210803810.png)

> Kib Mem：物理内存，total：总量，free：空闲，used：使用，buff/cache：buff何cache占用
>
> KibSwap：虚拟内存（交换空间），total：总量，free 空闲，used 使用，buff/cache：buff何cache占用

##### 1）top命令内容详解

![image-20250623211500304](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250623211500304.png)

- PID：进程id
- USER：进程所属用户
- PR：进程优先级，越小越高
- NI：负值表示高优先级，正表示低优先级
- VIRT：进程使用虚拟内存，单位KB
- RES：进程使用物理内存，单位KB
- SHR：进程使用共享内存，单位KB
- S：进程状态（S休眠，R运行，Z僵死状态，N负数优先级，I空闲状态）
- %CPU：进程占用CPU率
- %MEM：进程占用内存率
- TIME+：进程使用CPU时间总计，单位10毫秒
- COMMAND：进程的命令或名称或程序文件路径

##### 2）top命令选项

![image-20250623211918476](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250623211918476.png)

##### 3）top的交互式选项

![image-20250623212232272](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250623212232272.png)

#### 2、磁盘信息监控

- 使用df命令，可以查看硬盘的使用情况
  - 语法：`df [-h]`
  - 选项：-h，以更加人性化的单位显示

- 可以使用iostat查看CPU、磁盘的相关信息
  - 语法：`iostat [-x][num1][num2]`
  - 选项：-x，显示更多信息
  - num1：数字，刷新间隔，num2：数字，刷新几次

【Tips】该设备美妙的传输次数。“一次传输”意思是“一次I/O请求”。多个逻辑请求可能会被合并为“一次I/O请求”。“一次传输”请求的大小是未知的

![image-20250623213125406](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250623213125406.png)

#### 3、网络状态监控

![image-20250623213442414](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250623213442414.png)

------

### 12 环境变量

在讲解which命令的时候，我们知道使用的一系列命令其本质上就是一个个的可执行程序。比如，cd命令的本体就是:/usr/bin/cd这个程序文件。

那么我们可能会有译文，就是无论当前工作目录在哪里，都能执行：/usr/bin/cd这个程序呢？

> 这就是环境变量的作用

#### 1、什么是环境变量

环境变量是操作系统在运行的时候，记录的一些关键性信息，用以辅助系统运行。在Linux系统中执行`env` 命令即可查看当前系统中记录的环境变量，环境变量是一种KeyValue型结构，即名称和值，

![image-20250625204146661](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250625204146661.png)

**PATH**

在前面提出的问题中，我们说无论当前的工作目录是什么，都能执行/usr/bin/cd这个程序，这个就是借助环境变量中：PATH这个项目的值来做到的。

可以通过修改这个项目的值，加入自定义的命令搜索路径，如：

`export PATH=$PATH:自定义路径`

![image-20250625204347392](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250625204347392.png)

#### 2、$符号

![image-20250625204457006](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250625204457006.png)

#### 3、自行设置环境变量

Linux环境变量可以用户自行设置，其中分为：

- 临时设置，语法：export 变量名 = 变量值
- 永久生效
  - 针对当前用户生效，配置在当前用户的：~/bashrc文件中
  - 针对所有用户生效，配置在系统的:/etc/profile文件中
  - 并通过语法：source配置文件，进行立刻生效，或重新登录FinalShell生效

![image-20250625204832120](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250625204832120.png)

------

### 13 Linux文件的上传和下载

#### 1、上传、下载

我们可以通过FinalShell工具，方便地和虚拟机进行数据交换。

在FinalShell软件的下方窗口，提供了Linux的文件系统视图，可以方便的：

- 浏览文件系统，找到合适的文件，右键单击下载，即可传输到本地电脑
- 浏览文件系统，找到合适的目录，将本地电脑的文件拓展进入，即可方便的上传数据到Linux中

![image-20250625205757133](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250625205757133.png)

#### 2、rz、sz命令

当然，除了通过FinalShell的下方窗体进行文件的传输以外，也可以通过rz、sz命令进行文件传输。rz、sz命令需要安装，可以通过：`yum -y install lrzsz` 即可安装。

- rz命令，进行上传，语法：直接输入rz即可

- sz命令进行下载，语法：sz 要下载的文件

  >  文件会自动下载到桌面的fsdownload文件夹中

【注意】拖拽的速度会 比rz快得多。

------

### 14 压缩和解压

####  1、压缩格式

市面上有很多压缩格式，比如：

- zip格式：Linux、Windows、Macos常用
- 7zip：Windows系统常用
- rar：Windows常用
- tar：Linux、Macos常用
- gzip：Linux、Macos常用

在Windows系统中常用的软件，如winrar、bandizip等软件，都支持各类常见的压缩格式，这里不做过多讨论；我们本节课所要缩写的就是：如何在Linux系统中操作：tar、gzip、zip这三种压缩格式，完成文件的压缩、解压操作。

#### 2、tar命令

Linux和Mac系统常用有两种压缩格式，后缀名分别是：

- tar，称之为tarball，归档文件，即简单的将文件组装到一个.tar文件内，并没有太多文件体积的减少，仅仅是简单的封装。
- gz，也常见为.tar .gz,gzip格式压缩文件，即使用gzip压缩算法将文件压缩到一个文件内，可以极大的减少压缩后的体积。

**针对这两种格式，使用tar命令均可以进行压缩和解压缩的操作**，语法如下：

```shell
tar [-c -v -x -f -z -C]参数1 参数2 ... 参数N
```

- -c，创建压缩文件，用于压缩模式
- -v，显示压缩，解压过程，用于查看进度
- -x，解压模式
- -f，要创建的文件，或要解压的文件，-f选项必须在所有选项中位置处于最后一个
- -z，gzip模式，不适用-z就是普通的tarball格式
- -C，选择解压的目的地，用于解压模式

##### 1）tar命令的几个常用组合

- tar -cvf test.rar 1.txt 2.txt 3.txt

> 将1.txt 2.txt 3.txt压缩到test.rar文件内

- tar -zcvf test.tar.gz 1.txt 2.txt 3.txt

> 将1.txt 2.txt 3.txt压缩到test.tar.gz文件内，使用gzip模式

【注意】

- -z选项如果使用的话，一般处于选项位第一个
- -f选项，**必须**在选项位最后一个

#####  2）tar解压

常见的tar解压组合有

- tar -xvf test.rar

> 解压test.rar 将文件解压至当前目录

- tar -xvf test.rar -C/home/iteima

> 解压test.rar，将文件解压至指定目录（/home/itheima）

- tar -zxvf test.rar -C/home/itheima

> 以Gzip模式解压test.tar.gz，将文件解压至指定目录（/home/itheima）

【注意】

- -f选项，必须在选项组合体的最后以为
- -z选项，建议在开头位置
- -C选项单独使用，和解压所需的其他参数分开

#### 3、zip命令

##### 1）zip压缩文件

可以使用zip命令，压缩文件为zip压缩包，语法如下：

```shell
zip [-r] 参数1 参数2 ... 参数N
```

- -r，被压缩的包含文件夹的时，需要使用-r选项，和rm、cp等命令的 -r效果一致

示例：

- zip test.zip a.txt b.txt c,txt

> 将a.txt b.txt c.txt压缩到test.zip文件内

- zip -r test.zip test itheima a.txt

> 将test、itheima两个文件夹和a.txt文件，压缩到test.zip文件内

##### 2）unzip命令解压文件

使用unzip命令，可以方便的解压zip压缩包，语法如下：

```shell
unzip [-d] 参数
```

- -d，指定要解压去的位置，同tar的-C选项
- 参数，被解压的zip压缩包文件

示例：

- unzip test.zip ，将test.zip解压到当前目录
- unzip test.zip -d/home/itheima，将test.zip解压到指定文件夹内（/home/itheima）
