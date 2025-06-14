## 第三章：Linux用户和权限

`From Felix Du`

[TOC]

------

### 01 Linux的root用户

#### 1、什么是root用户（超级管理员）

无论是Windows、MacOS、Linux均采用多用户的管理模式进行权限管理。

- 在Linux系统中，拥有最大权限的账户名为：root（超级管理员）
- 而在前期，我们使用的一直是我们自己创建的普通用户

![image-20250612163154886](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250612163154886.png)

root用户拥有最大的系统操作权限，而普通用户在很多地方的权限是受限的；

- 普通用户的权限，一般在其HOME目录内是不受限的
- 一旦出了HOME目录，大多数地方，普通用户仅有只读和执行权限，无修改权限

#### 2、su和exit命令

su命令就是用于账户切换的系统命令，来源于英文单词：Switch User，语法如下：

```shell
su [-][用户名]
```

- `-` 符号是可选的，表示是否在切换用户后加载**环境变量**，建议带上
- 参数：用户名，表示要切换的用户，用户名也可以省略，省略表示切换到root
- 切换用户后，可以通过exit命令退回上一个用户，也可以使用快捷键 `ctrl+d`
- 使用普通用户，切换到其他用户需要输入密码，如切换到root用户
- 使用root用户切换到其他用户，无需密码，可以直接切换

#### 3、sudo命令

当我们得知root密码的时候，可以通过su命令切换到root得到最大权限，但我们不建议长期使用root用户，避免带来系统损坏

我们可以使用`sudo` 命令，为普通的命令授权，临时以root身份执行。语法如下：

```shell
sudo 其他命令
```

- 在其他命令之前，带上sudo，即可为这一条命令临时赋予root权限
- 但是并不是所有的用户，都有权利使用sudo，我们**需要为普通用户配置sudo认证**

#### 4、如何为普通用户配置sudo认证

- 切换到root用户，执行Visudo命令，会自动通过vi编辑器打开：`/etc/sudoers`

- 在文件的最后添加：

  ```shell
  username ALL=(ALL)  NOPASSWD:ALL
  ```

  - 其中最后的`NOPASSWD：ALL`表示使用sudo命令，无需输入密码

- 最后通过wq保存

------

### 02 用户和用户组

#### 1、用户、用户组的概念

![image-20250613155810119](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250613155810119.png)

Linux中关于权限的管控级别有两个级别，分别是：

- 针对用户的权限控制
- 针对用户组的权限控制

比如，针对某文件，可以控制**用户的权限**，也可以控制**用户组的权限**。所以，我们需要在学习Linux中进行用户、用户组管理的基础命令，为后面学习权限控制打下基础。

#### 2、用户、用户组的相关命令

##### 1）用户组管理

> 以下命令都需要以root用户执行

- 创建用户组

```shell
groupadd 用户组名
```

- 删除用户组

```shel
groupdel 用户组名
```

##### 2）用户管理

- 创建用户

  ```shell
  useradd [-g -d] 用户名
  ```

  - 选项：`-g` 指定用户的组，不指定 `-g`，会创建同名组并自动加入，指定 `-g` 需要组已存在，如已存在同名组，必须使用-g
  - 选项：`-d` 指定用户HOME路径，不指定，HOME目录默认在：/home/用户名

- 删除用户

  ```shell
  userdel [-r] 用户名
  ```

  - 选项`-r` ，删除用户HOME目录，不适用`-r`，删除用户时，HOME目录保留

- 查看用户所属组

  ```shell
  id [用户名]
  ```

  - 参数：用户名，被查看的用户，如果不提供则查看自身

- 修改用户所属组

  ```shell
  usermod -aG 用户组 用户名
  ```

  - 将指定的用户加入指定的用户组。

##### 3）getent命令

使用getent命令，可以查看当前系统中有哪些用户，语法如下：

```shell
getent passwd
```

![image-20250613161454694](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250613161454694.png)

这个结果一共有7份信息，分别是：

>  用户名：密码(x)：用户ID：组ID：描述信息(无用)：HOME目录：执行终端(默认bash)

我们也可以用以下的命令，查看系统中有哪些组：

```shell
getent group
```

![image-20250613161801116](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250613161801116.png)

包含3份信息，组名称：组认证(显示为x)：组ID

------

### 03 查看权限控制信息

#### 1、认知权限信息

![image-20250613162030238](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250613162030238.png)

![image-20250613162140962](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250613162140962.png)

举例：`d rwx r-x r-x`，表示：(这里是为了方便看才加的空格，实际中是没有的)

- 首字母d表示这是一个文件夹
- 所属用户（上上一个图中序号2）的权限是：有 `r` 有  `w` 有 `x` , `rwx`
- 所属用户组（上上个图中序号3）的权限是：有 `r` 无 `w` 有`x` ，`r-x`(表示无此权限)
- 其他用户的权限是：有 `r` 无 `w` 有`x` ，`r-x`

#### 2、rwx是什么

- r表示读权限
- w表示写权限
- x表示执行权限

针对文件、文件夹的不同，`rwx`的含义有细微差别

- r，针对文件可以查看文件内容
  - 针对文件夹，可以查看文件夹内容，如ls命令
- w，针对文件表示可以修改此文件
  - 针对文件夹，可以在文件夹内：创建、删除 、改名等操作
- x，针对文件表示可以将文件作为程序执行
  - 针对文件夹，表示可以更改工作目录到此文件夹，即cd进入

------

### 04 修改权限控制1 - chmod命令

#### 1、使用chmod修改权限信息

我们可以使用chmod命令，修改文件、文件夹的权限信息。**注意：只有文件、文件夹的所属用户或root用户可以修改。**语法如下：

```shell
chmod [-R] 权限 文件或文件夹
```

- 选项： -R，对文件夹内的全部内容应用同样的操作(如果要文件夹里面的文件一起改变，一定要-R)

示例：

- `chmod u=rwx,g=rx,o=x hello.txt`，将文件权限修改为：`rwxr-x--x`
  - 其中：u表示user所属用户权限，g表示group组权限，o表示other其他用户权限
- `chmod -R u=rwx,g=rx,o=x test`，将文件夹test以及文件夹内全部内容权限设置为：`rwxr-x--x`

> 除此之外，还有快捷写法：chmod 751 hello.txt
>
> 表示将hello.txt的权限修改为751。那么751表示的是什么东西呢？

#### 2、权限的数字序号

**记住r代表4、w代表2、x代表1就可以了**

![image-20250614113126868](C:\Users\Duuuzx\AppData\Roaming\Typora\typora-user-images\image-20250614113126868.png)

> 那我们刚刚的751表示的是 `u=rwx(7=4+2+1) g=r-x(5=4+1) o=--x(1)`

------

### 05修改权限控制2- chown命令

使用chown命令，可以修改文件、文件夹所属用户和用户组。**普通用户无法修改所属为其他用户或组，所以此命令只适用于root用户执行**(只有root用户可以用这条命令)，语法如下：

```shell
chown [-R] [用户][:][用户组] 文件或文件夹
```

- 选项：-R，同chmod，对文件夹内全部内容应用相同规则
- 选项，用户，修改所属用户
- 选项，用户组，修改所属用户组
-  ：用于分隔用户和用户组

示例：

- `chown root hello.txt`，将hello.txt所属用户修改为root
- `chown :root hello.txt`，将hello.txt所属用户组修改为root
- `chown root:itheima hello.txt`，将hello.txt所属用户修改为root，用户组修改为itheima
- `chown -R root test`,将文件夹test的所属用户修改为root并对文件夹内全部内容应用同样规则

------

