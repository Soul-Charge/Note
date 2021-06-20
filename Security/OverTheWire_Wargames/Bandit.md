# Bandit

[网址](https://overthewire.org/wargames/bandit/)

## Level 0 -> Level 1

### 相关知识

ssh基本登录与基本的`ls` `cat` 命令  
ssh 确定端口、主机名和用户名用法例1：

```shell
ssh -p 端口 用户名@主机名
```

例2

```shell
ssh -p 端口 -l 用户名 主机名
```

### 具体操作

```shell
ssh -p 2220 bandit0@bandit.labs.overthewire.org
# 或
ssh -p 2220 -l bandit0 bandit.labs.overthewire.org

# 输入密码：`bandit0`
cat readme
# 按下 Ctrl 和 D 键断开连接
```

### 密码

```text
boJ9jbbUNNfktd78OOpsqOltutMc3MY1
```

## Level 1 -> Level 2

### 相关知识

处理以`-`开头的文件名的文件：

```shell
# ./表示后接当前目录下的文件名
command ./-filename
```

### 具体操作

```shell
ssh -p 2220 bandit1@bandit.labs.overthewire.org
cat ./-
```

### 密码

```text
CV1DtqXWVFXTvM2F0k09SHz0YwRINYA9
```

## Level 2 -> Level 3

### 相关知识

处理带空格的文件名的文件：  

> 下例中 command 表示输入的命令
> 文件名为f i le
> \<Tab\>为按下Tab按键

1. 用 \ 转义空格
    ```shell
    command f\ i\ le
    ```
2. 用双引号包围文件名
    ```shell
    command "f i le"
    ```
3. 使用Tab键自动补全
    ```shell
    command f<Tab> ↓变为
    command f\ i\ le
    ```
    ```shell
    command "f<Tab> ↓变为
    command "f i le"
    ```

### 具体操作

/*  省略登录操作 */

1

```shell
cat s<tab>
cat spaces\ in\ this\ file
```

2

```
cat "s<tab>
cat "spaces is this file"
```

### 密码

```text
UmHadQclWmgdLOKQ3YNgjWxGoRMb5luK
```

## Level 3 -> Level 4

### 相关知识

**cd命令**

```shell
# 进入文件夹
# .和..分别表示当前文件夹和上一级文件夹
cd 文件夹名
```

**隐藏文件**

以英文句点(`.`)开头的文件为隐藏文件，可使用`ls -a`列出隐藏文件

### 具体操作

```shell
ls
# 文件夹inhere
cd inhere
ls -a
# 文件.hidden
cat .hidden
```

### 密码

```text
pIwrPrtPN36QITSp3EQaw936yaFoFgAB
```

## Level 4 -> Level 5

### 相关知识

**通配符\***

```shell
# 用*通配符表示所有文件
command ./*
```

**file命令**

```shell
# 用file命令显示文件类型
file ./file1
# 输出：./file1 描述文本类型的字符串
```

### 具体操作

```shell
cd inhere
ls
# 有文件名为-file00 到-file09的十个文件
file ./*
# 发现-file07文件类型为ASCII text
cat ./-file07
##############
# 也可以直接cat./*找到正常的一段文本即为密码
```

### 密码

```text
koReBOKuIDDepwhWk7jZC0RTdopnAYKh
```

## Level 5 -> Level 6

### 相关知识

**find命令**
[文档](http://www.gnu.org/software/findutils/manual/find.html)
关于find命令按权限搜索可参考:
[Linux 文件基本属性](https://www.runoob.com/linux/linux-file-attr-permission.html)
[find 命令关于权限匹配的解释](https://blog.csdn.net/nianhuo5678/article/details/18326957)

```shell
在path路径下查找大小为233字节的文件
find path -size 233c
```

### 具体操作

```shell
find ./inhere/ -size 1033c
# ./inhere/maybehere07/.file2
cat ./inhere/maybehere07/.file2
```

### 密码

```text
DXjZPULLxYr17uwoI01bNLQbtFemEgo7
```

## Level 6 -> Level 7

### 相关知识

[find命令Owner相关选项](https://www.gnu.org/software/findutils/manual/html_mono/find.html#Owner)
[重定向](https://www.runoob.com/linux/linux-shell-io-redirections.html)

### 具体操作

```shell
# 根据页面提示设置搜索参数
# -user 文件所有者
# -group 用户组
find / -size 33c -user bandit7 -group bandit6 2>/dev/null
# 输出：/var/lib/dpkg/info/bandit7.password
cat /var/lib/dpkg/info/bandit7.password
```

### 密码

```text
HKBPTKQnIay4Fw76bEy8PVxKEDQRKTzs
```

## Level 7 -> Level 8

### 相关知识

网页提示
> The password for the next level is stored in the file data.txt next to the word millionth
> 可知密码在单词"millionth"旁边

可使用grep, vim等具有文本匹配的工具

1. grep基本匹配
    ```shell
    # pattern 为需要匹配的字符串文本
    grep pattern file
    ```
2. vim文本匹配
    ```shell
    # 用vim打开文件
    vim file
    # 按下 / 后输入匹配文本后回车，按下 n 和 N 上下切换
    </>pattern<Enter>
    ```


### 具体操作

```shell
grep millionth data.txt
# 输出 millionth       cvX2JJa4CFALtqS87jk27qwqGhBM9plV
```

### 密码
```text
cvX2JJa4CFALtqS87jk27qwqGhBM9plV
```

## Level 8 -> Level 9

### 相关知识

**sort命令**
用于对文本进行排序，此处用于使重复行相邻以使用uniq删除重复行

**[uniq命令](https://www.runoob.com/linux/linux-comm-uniq.html)**
删除重复行，或留下非重复行，(只在重复行相邻时起效，具体参考↑)

```shell
# 显示只出现一次的行
uniq -u
```

**管道**

```shell
# 将左侧命令的输出重定向至右侧命令的输入
command1 | command2
```

### 具体操作

```shell
# 将sort data.txt 的结果传递给 uniq -u
sort data.txt | uniq -u
```

### 密码
```text
UsvVyFSfZZWbi6wgC7dAFyFuR6jQQUhR
```

## Level 9 -> Level 10

### 相关知识

根据提示：
> The password for the next level is stored in the file data.txt in one of the few human-readable strings, preceded by several ‘=’ characters.
可知密码为前面有几个`=`(至少两个)引导的可读字符串

```shell
# 使grep处理二进制文件
grep -a pattern file
```

### 具体操作

1. vim
    ```shell
    vim data.txt
    # 输入/==
    # 找到正常可读的那一段
    ```
    ![example_vim](_v_images/20210619122924770_21528.png)
2. grep
    ```shell
    grep -a == data.txt
    找到多个=后跟可读的那一串
    ```
    ![example_grep](_v_images/20210619122953034_29392.png)

### 密码

```text
truKLdjsbJ5g7yyJ2X2R0o3a5HQJFuLk
```

## Level 10 -> Level 11

### 相关知识

base64命令

```shell
# 对文件内容进行base64加密
base64 file
# 解密
base 64 -d file
# 加密左侧命令输出
command | base64
```

base64会在源内容尾部添加换行符后加密，以便在解密时末尾换行
下例添加终端提示符 $ 便于说明

```shell
# 加密文本 514
$ echo 514 | base64
NTE0Cg==
$
# 此处看似文本514加密后文本为NTE0Cg==
```

```shell
# 解密文本 NTE0Cg==
$ echo NTE0Cg== | base64 -d
514
$
# 此处看似解密反证结论同上
```

但若解密文本 NTE0 可知 514 加密文本是 NTE0
```shell
$ echo NTE0 | base64 -d
514$
# ↑，因为解密文本514尾部没有换行符，所以后面紧跟提示符$
```

### 具体操作

```shell
base64 -d data.txt
# 输出直接显示密码了
The password is IFukwKGsFW8MOq3IRFqrxE1hxTNEbUPR
```

### 密码

```text
IFukwKGsFW8MOq3IRFqrxE1hxTNEbUPR
```

## Level 11 -> Level 12

### 相关知识

[参考阅读提及到的ROT-13](https://baike.baidu.com/item/ROT13/7086083?fr=aladdin)

### 具体操作

直接百度ROT13找一个在线解码把文件里的内容放上去解码即可

### 密码

```text
5Te8Y4drgCRfCx8ugdwuEX8KFC6k2EUu
```

## Level 12 -> Level 13

### 相关知识

**mv 命令**

```shell
# 重命名文件，文件名可添加路径
mv filename1 filename2
```

**xxd 命令**

```shell
xxd file    # 以十六进制方式(hexdump)查看文件
xxd -b file # 以二进制方式查看文件
xxd -r file1 file2 # 将hexdump文件还原为二进制文件到file2
```

[tar gzip bzip2，三个解压缩命令](https://www.runoob.com/w3cnote/linux-tar-gz.html)
> 1、\*.tar 用 tar –xvf 解压 
> 2、\*.gz 用 gzip -d或者gunzip 解压 
> 3、\*.tar.gz和\*.tgz 用 tar –xzf 解压 
> 4、\*.bz2 用 bzip2 -d或者用bunzip2 解压 
> 5、\*.tar.bz2用tar –xjf 解压 
> 6、\*.Z 用 uncompress 解压 
> 7、\*.tar.Z 用tar –xZf 解压 
> 8、\*.rar 用 unrar e解压 
> 9、\*.zip 用 unzip 解压

### 具体操作

```shell
# 创建一个文件夹用于存放解压的文件
mkdir /tmp/514
cd /tmp/514
# 还原data.txt的hexdump内容到新文件
xxd -r ~/data.txt ./source
# 查看文件类型，根据文件类型重命名为对应压缩包后解压
file source
# source: gzip compressed data
mv source source.gz
gzip -d source.gz
ls
# source
file source
# source: bzip2 compressed data
mv source source.bz2
bzip2 source.bz2
ls
# source
file source
# source: gzip compressed data
mv source source.gz
gzip -d source.gz
ls
# source
file source
# source: POSIX tar archive (GNU)
mv source source.tar
tar -xvf source.tar
# data5.bin
file data5.bin
# data5.bin: POSIX tar archive (GNU)
mv data5.bin data5.bin.tar
tar -xvf data5.bin.tar
# data6.bin
file data6.bin
# data6.bin: bzip2 compressed data
mv data6.bin data6.bin.bz2
bzip2 -d data6.bin.bz2
ls
# data5.bin.tar  data6.bin  source.tar
file data6.bin
# data6.bin: POSIX tar archive (GNU)
mv data6.bin data6.bin.tar
tar -xvf data6.bin.tar
# data8.bin
file data8.bin
# data8.bin: gzip compressed data
mv data8.bin data8.bin.gz
gzip -d data8.bin.gz
ls
# data5.bin.tar  data6.bin.tar  data8.bin  source.tar
file data8.bin
# data8.bin: ASCII text
cat data8.bin
```

### 密码

```text
8ZjyCRiBWFYkneahHwxCv3wb2a1ORpYL
```

## Level 13 -> Level 14

### 相关知识

**openssh**

简单讲就是在本地生成一对密钥，把公钥放在需要登录的远程主机上，私钥留在本地主机，在访问时进行配对。
此处在Bandit13用户的文件夹里留有登录Bandit14用户的私钥，所以只需把该私钥添加到本地主机即可
但过程中可能会遇到几个坑

1. 复制私钥
    私钥的内容从`-----BEGIN RSA PRIVATE KEY-----`开始，
    到`-----END RSA PRIVATE KEY-----`结束，
    在这里就是把`sshkey.private`文件的全部内容复制
2. 可能的多私钥管理
    如果本地主机没有过ssh key 则直接在`~/.ssh/`目录下创建文件`id_rsa`后粘贴内容即可
    但如果本地已有私钥则为了避免冲突需要进行管理[详见](https://gaomf.cn/2016/06/17/OpenSSH使用多个私钥（SSH%20Key）配置/)
    为防链接失效的个人例：
    创建文件`~/.ssh/config`
    文件内容：

    ```config
    Host github.com
    IdentityFile ~/.ssh/id_rsa

    Host bandit.labs.overthewire.org
    IdentityFile ~/.ssh/id_rsa_bandit13to14
    ```

3. 私钥权限
    若私钥权限太开放则会被忽略，提示内容：

    ```text
    Permissions 0644 for '/home/creeper/.ssh/id_rsa_bandit13to14' are too open.
    It is required that your private key files are NOT accessible by others.
    This private key will be ignored.
    ```

    修改密钥权限为600即可
    ```shell
    chmod 600 /home/creeper/.ssh/id_rsa_bandit13to14
    ```


### 具体操作

```shell
ls
# sshkey.private
cat sshkey.private
# ### 输出内容分界线 ###
-----BEGIN RSA PRIVATE KEY-----
MIIEpAIBAAKCAQEAxkkOE83W2cOT7IWhFc9aPaaQmQDdgzuXCv+ppZHa++buSkN+
gg0tcr7Fw8NLGa5+Uzec2rEg0WmeevB13AIoYp0MZyETq46t+jk9puNwZwIt9XgB
ZufGtZEwWbFWw/vVLNwOXBe4UWStGRWzgPpEeSv5Tb1VjLZIBdGphTIK22Amz6Zb
ThMsiMnyJafEwJ/T8PQO3myS91vUHEuoOMAzoUID4kN0MEZ3+XahyK0HJVq68KsV
ObefXG1vvA3GAJ29kxJaqvRfgYnqZryWN7w3CHjNU4c/2Jkp+n8L0SnxaNA+WYA7
jiPyTF0is8uzMlYQ4l1Lzh/8/MpvhCQF8r22dwIDAQABAoIBAQC6dWBjhyEOzjeA
J3j/RWmap9M5zfJ/wb2bfidNpwbB8rsJ4sZIDZQ7XuIh4LfygoAQSS+bBw3RXvzE
pvJt3SmU8hIDuLsCjL1VnBY5pY7Bju8g8aR/3FyjyNAqx/TLfzlLYfOu7i9Jet67
xAh0tONG/u8FB5I3LAI2Vp6OviwvdWeC4nOxCthldpuPKNLA8rmMMVRTKQ+7T2VS
nXmwYckKUcUgzoVSpiNZaS0zUDypdpy2+tRH3MQa5kqN1YKjvF8RC47woOYCktsD
o3FFpGNFec9Taa3Msy+DfQQhHKZFKIL3bJDONtmrVvtYK40/yeU4aZ/HA2DQzwhe
ol1AfiEhAoGBAOnVjosBkm7sblK+n4IEwPxs8sOmhPnTDUy5WGrpSCrXOmsVIBUf
laL3ZGLx3xCIwtCnEucB9DvN2HZkupc/h6hTKUYLqXuyLD8njTrbRhLgbC9QrKrS
M1F2fSTxVqPtZDlDMwjNR04xHA/fKh8bXXyTMqOHNJTHHNhbh3McdURjAoGBANkU
1hqfnw7+aXncJ9bjysr1ZWbqOE5Nd8AFgfwaKuGTTVX2NsUQnCMWdOp+wFak40JH
PKWkJNdBG+ex0H9JNQsTK3X5PBMAS8AfX0GrKeuwKWA6erytVTqjOfLYcdp5+z9s
8DtVCxDuVsM+i4X8UqIGOlvGbtKEVokHPFXP1q/dAoGAcHg5YX7WEehCgCYTzpO+
xysX8ScM2qS6xuZ3MqUWAxUWkh7NGZvhe0sGy9iOdANzwKw7mUUFViaCMR/t54W1
GC83sOs3D7n5Mj8x3NdO8xFit7dT9a245TvaoYQ7KgmqpSg/ScKCw4c3eiLava+J
3btnJeSIU+8ZXq9XjPRpKwUCgYA7z6LiOQKxNeXH3qHXcnHok855maUj5fJNpPbY
iDkyZ8ySF8GlcFsky8Yw6fWCqfG3zDrohJ5l9JmEsBh7SadkwsZhvecQcS9t4vby
9/8X4jS0P8ibfcKS4nBP+dT81kkkg5Z5MohXBORA7VWx+ACohcDEkprsQ+w32xeD
qT1EvQKBgQDKm8ws2ByvSUVs9GjTilCajFqLJ0eVYzRPaY6f++Gv/UVfAPV4c+S0
kAWpXbv5tbkkzbS0eaLPTKgLzavXtQoTtKwrjpolHKIHUz6Wu+n4abfAIRFubOdN
/+aLoRQ0yBDRbdXMsZN/jvY44eM+xRLdRVyMmdPtP8belRi2E2aEzA==
-----END RSA PRIVATE KEY-----
# ### 输出内容分界线 ###
# 复制以上私钥内容
vim ~/.ssh/id_rsa_bandit13to14
# <i> <粘贴> <Esc> <w> <q> <Enter>
vim ~/.ssh/config
# <i> <输入以下短线包围的内容> <Esc> <w> <q> <Enter>
-------------
Host github.com
IdentityFile ~/.ssh/id_rsa

Host bandit.labs.overthewire.org
IdentityFile ~/.ssh/id_rsa_bandit13to14
-------------
chmod 600 /home/creeper/.ssh/id_rsa_bandit13to14
# 之后即可直连Bandit14@bandit.labs.overthewire.org
```

### 密码

虽然此Level使用ssh key认证登录但仍有密码，用于Level 14 -> Level 15

```text
4wcYUJFw0k0XLShlDzztnTBHiqxU3b3e
```

## Level 14 -> Level 15

### 相关知识

**telnet**

> The password for the next level can be retrieved by submitting the password of the current level to port 30000 on localhost.
> 通过向localhost的30000端口提交当前Level的密码，可以检索到下一Level的密码。

故连接到localhost的30000端口后发送Level 14 的密码即可，localhost虽为本地主机，但仍可用telnet登录

### 问题排查

```shell
telnet localhost
# Trying 127.0.0.1...
# telnet: Unable to connect to remote host: Connection refused
```

问题应为端口号占用，连接时加上可用端口号，如在此处使用网页给出的30000
[参考文章](https://blog.csdn.net/renmengqisheng/article/details/90579205)

```shell
telnet localhost 30000
# Trying 127.0.0.1...
# Connected to localhost.
# Escape character is '^]'.
```

### 具体操作


1. 使用telnet登录127.0.0.1(localhost)

    ```shell
    telnet localhost 30000
    # Trying 127.0.0.1...
    # Connected to localhost.
    # Escape character is '^]'.
    # 粘贴Level14的密码↓
    4wcYUJFw0k0XLShlDzztnTBHiqxU3b3e
    # Correct!
    # 得到密码↓
    # BfMYroe26WYalil77FoDi9qh59eK5xNr

    # Connection closed by foreign host.
    ```

2. 网上找向端口发送字符串找到的，原理尚未明确

    ```shell
    (echo '4wcYUJFw0k0XLShlDzztnTBHiqxU3b3e'; sleep 2) | telnet localhost 30000
    # Trying 127.0.0.1...
    # Connected to localhost.
    # Escape character is '^]'.
    # Correct!
    # BfMYroe26WYalil77FoDi9qh59eK5xNr
    ```

3. 使用ssh连接到localhost后发送Level14的密码？
    目前没找到可行方法，尝试：
    ```shell
    ssh -p 30000 localhost
    # ssh_exchange_identification: Connection closed by remote host
    ssh -v -p 30000 localhost
    # 其中一条调试信息↓
    # debug1: ssh_exchange_identification: Wrong! Please enter the correct current password
    # 可知问题应为没有输入密码
    # 尝试输入密码↓
    echo 4wcYUJFw0k0XLShlDzztnTBHiqxU3b3e | ssh -v -p 30000 localhost
    # debug1: ssh_exchange_identification: Wrong! Please enter the correct current password
    # 使用类似 2. 的方法，仍然不行
    (echo '4wcYUJFw0k0XLShlDzztnTBHiqxU3b3e'; sleep 2) | ssh -v -p 30000 localhost
    # debug1: ssh_exchange_identification: Wrong! Please enter the correct current password
    ```

### 密码

```text
BfMYroe26WYalil77FoDi9qh59eK5xNr
```

## Level 15 -> Level 16

### 相关知识

### 具体操作

### 密码
