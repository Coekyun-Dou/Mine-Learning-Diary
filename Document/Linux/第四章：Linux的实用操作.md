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