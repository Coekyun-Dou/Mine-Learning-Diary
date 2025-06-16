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