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

1. Tab

    ```shell
    cat s<tab>
    cat spaces\ in\ this\ file
    ```

2. "Tab

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
> -size n[cwbkMG]  
>'b'    for 512-byte blocks (this is the default if no suffix is used)  
>'c'    for bytes  
>'w'    for two-byte words  
>'k'    for Kilobytes (units of 1024 bytes)  
>'M'    for Megabytes (units of 1048576 bytes)  
>'G'    for Gigabytes (units of 1073741824 bytes)  

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

网页提示：  
> The password for the next level is stored in the file **data.txt** next to the word **millionth**  
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

**使用密钥文件登录**

```shell
ssh -i sshkeyfile hostname
```


### 具体操作

1. 添加ssh私钥(多私钥添加与管理）

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

2. 添加ssh私钥  
    在`~/.ssh/`目录下创建文件`id_rsa`后粘贴bandit14的私钥内容

3. 直接使用密钥文件

    ```shell
    ssh -i sshkey.private bandit14@localhost
    ```

### 密码

虽然此Level使用ssh key认证登录但仍有密码，用于Level 14 -> Level 15  
密码位置：/etc/bandit_pass/bandit14  

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

3. 使用nc命令

    ```shell
    nc localhost 30000
    # 粘贴bandit14的密码↓
    4wcYUJFw0k0XLShlDzztnTBHiqxU3b3e
    Correct!
    BfMYroe26WYalil77FoDi9qh59eK5xNr
    ```

4. 使用ssh连接到localhost后发送Level14的密码？  
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

> The password for the next level can be retrieved by submitting the password of the current level to port 30001 on localhost **using SSL encryption**.  
> **using SSL encryption**，表示要使用经过SSL加密的连接方式  

SSL/TLS  
[浅谈SSL/TLS工作原理](https://zhuanlan.zhihu.com/p/36981565)  
SSL/TLS 的客户端程序  
[s_client文档](https://www.openssl.net.cn/docs/235.html)  

### 具体操作

```shell
openssl s_client -host localhost -port 30001
# 中间输出一大串没必要放出来了
# 粘贴Level 15 的密码
BfMYroe26WYalil77FoDi9qh59eK5xNr
# 直接显示密码了
Correct!
cluFn7wTiGryunymYOu4RcffSxQluehd

closed
# ###
```

### 密码

```text
cluFn7wTiGryunymYOu4RcffSxQluehd
```

## Level 16 -> Level 17

### 提示内容理解

> The credentials for the next level can be retrieved by submitting the password of the current level to a port on localhost in the range 31000 to 32000.  
> 下一Level的认证信息(ssh 私钥)可以通过向 localhost 的一个端口发送当前 Level 的密码得到，端口范围：31000到32000  
> First find out which of these ports have a server listening on them.  
> 首先找到有服务监听的端口  
> Then find out which of those speak SSL and which don't.  
> 然后找到分辨哪些是SSL的  
> There is only 1 server that will give the next credentials, the others will simply send back to you whatever you send to it.  
> 只有一个服务会提供下一 Level 的认证信息，其他的只会返回输入  

所以需要扫描localhost的指定范围内的端口并判断其服务类型

### 相关知识

**[nmap](https://nmap.org/man/zh/)**

直接输入nmap或使用`man nmap`即可查看用法  
使用`-pn-n`以设置端口范围(n为数字)  
> -p <port ranges>: Only scan specified ports  
> Ex: -p22; -p1-65535; -p U:53,111,137,T:21-25,80,139,8080,S:9  

使用`-sV`选项以查看服务类型  
> -sV: Probe open ports to determine service/version info  

**[SSL多私钥管理`II`(相对于上面的)](http://php-note.com/article/657.html)**

### 具体操作

```shell
nmap -p31000-32000 -sV localhost
# ### 有用信息部分↓ ###
PORT      STATE SERVICE     VERSION
31046/tcp open  echo
31518/tcp open  ssl/echo
31691/tcp open  echo
31790/tcp open  ssl/unknown
31960/tcp open  echo
# ### 有用输出信息部分↑ ###
openssl s_client -host localhost -port 31790
# 连接成功后粘贴 Level 16 的密码↓
cluFn7wTiGryunymYOu4RcffSxQluehd
# 之后显示用于连接 Level 17 的私钥（这里不贴了看下面子标题私钥）
```

（此处使用管理多私钥的方式添加私钥）  
创建新文件并粘贴私钥后，修改~/.ssh/config  
为了兼容同一ip不同用户而修改config↓（记得修改在~/.ssh/下对应的私钥文件名）  

```config
Host github.com
IdentityFile ~/.ssh/id_rsa

Host bandit.labs.overthewire.org
IdentityFile ~/.ssh/id_rsa_bandit14
User bandit14

Host bandit.labs.overthewire.org
IdentityFile ~/.ssh/id_rsa_bandit17
User bandit17
```

### 私钥

```text
-----BEGIN RSA PRIVATE KEY-----
MIIEogIBAAKCAQEAvmOkuifmMg6HL2YPIOjon6iWfbp7c3jx34YkYWqUH57SUdyJ
imZzeyGC0gtZPGujUSxiJSWI/oTqexh+cAMTSMlOJf7+BrJObArnxd9Y7YT2bRPQ
Ja6Lzb558YW3FZl87ORiO+rW4LCDCNd2lUvLE/GL2GWyuKN0K5iCd5TbtJzEkQTu
DSt2mcNn4rhAL+JFr56o4T6z8WWAW18BR6yGrMq7Q/kALHYW3OekePQAzL0VUYbW
JGTi65CxbCnzc/w4+mqQyvmzpWtMAzJTzAzQxNbkR2MBGySxDLrjg0LWN6sK7wNX
x0YVztz/zbIkPjfkU1jHS+9EbVNj+D1XFOJuaQIDAQABAoIBABagpxpM1aoLWfvD
KHcj10nqcoBc4oE11aFYQwik7xfW+24pRNuDE6SFthOar69jp5RlLwD1NhPx3iBl
J9nOM8OJ0VToum43UOS8YxF8WwhXriYGnc1sskbwpXOUDc9uX4+UESzH22P29ovd
d8WErY0gPxun8pbJLmxkAtWNhpMvfe0050vk9TL5wqbu9AlbssgTcCXkMQnPw9nC
YNN6DDP2lbcBrvgT9YCNL6C+ZKufD52yOQ9qOkwFTEQpjtF4uNtJom+asvlpmS8A
vLY9r60wYSvmZhNqBUrj7lyCtXMIu1kkd4w7F77k+DjHoAXyxcUp1DGL51sOmama
+TOWWgECgYEA8JtPxP0GRJ+IQkX262jM3dEIkza8ky5moIwUqYdsx0NxHgRRhORT
8c8hAuRBb2G82so8vUHk/fur85OEfc9TncnCY2crpoqsghifKLxrLgtT+qDpfZnx
SatLdt8GfQ85yA7hnWWJ2MxF3NaeSDm75Lsm+tBbAiyc9P2jGRNtMSkCgYEAypHd
HCctNi/FwjulhttFx/rHYKhLidZDFYeiE/v45bN4yFm8x7R/b0iE7KaszX+Exdvt
SghaTdcG0Knyw1bpJVyusavPzpaJMjdJ6tcFhVAbAjm7enCIvGCSx+X3l5SiWg0A
R57hJglezIiVjv3aGwHwvlZvtszK6zV6oXFAu0ECgYAbjo46T4hyP5tJi93V5HDi
Ttiek7xRVxUl+iU7rWkGAXFpMLFteQEsRr7PJ/lemmEY5eTDAFMLy9FL2m9oQWCg
R8VdwSk8r9FGLS+9aKcV5PI/WEKlwgXinB3OhYimtiG2Cg5JCqIZFHxD6MjEGOiu
L8ktHMPvodBwNsSBULpG0QKBgBAplTfC1HOnWiMGOU3KPwYWt0O6CdTkmJOmL8Ni
blh9elyZ9FsGxsgtRBXRsqXuz7wtsQAgLHxbdLq/ZJQ7YfzOKU4ZxEnabvXnvWkU
YOdjHdSOoKvDQNWu6ucyLRAWFuISeXw9a/9p7ftpxm0TSgyvmfLF2MIAEwyzRqaM
77pBAoGAMmjmIJdjp+Ez8duyn3ieo36yrttF5NSsJLAbxFpdlc1gvtGCWW+9Cq0b
dxviW8+TFVEBl1O4f7HVm6EpTscdDxU+bCXWkfjuRb7Dy9GOtt9JPsX8MBTakzh3
vBgsyi/sN3RqRBcGU40fOoZyfAMT8s1m/uYv52O6IgeuZ/ujbjY=
-----END RSA PRIVATE KEY-----
```

## Level 17 -> Level 18

### 提示内容理解

> The password for the next level is in passwords.new and is the only line that has been changed between passwords.old and passwords.new  
> 下一级的密码在passwords.new中，是passwords.old和passwords.new之间唯一被改变的一行。  

显然是查看两个文件的不同处

### 相关知识

**[diff命令](https://www.runoob.com/linux/linux-comm-diff.html)**

### 具体操作

```shell
diff password.old password.new
### 输出分割线
42c42 # 表示第42行
< w0Yfolrc5bwjS4qw5mq1nnQi6mF03bii # .old该行的内容
---
> kfBf3eYk5BPBRzwjqutbbfE887SVc5Yd # .new该行的内容，Level 18 的密码
### 输出分割线
```

### 密码

```text
kfBf3eYk5BPBRzwjqutbbfE887SVc5Yd
```

### 更多

关于登录后自动登出：  
来自 Level 18 -> Level 19 的页面提示  
> Unfortunately, someone has modified .bashrc to log you out when you log in with SSH.  
> 使用SSH登录badit18会自动登出  

使用命令：

```shell
ssh -p 2220 bandit18@bandit.labs.overthewire.org 'cat .bashrc'
```

查看.bashrc，实现方式应该就是加了一行exit 0  
也就是写一句退出，导致登录后自动执行退出命令  

## Level 18 -> Level 19

### 提示内容理解

> The password for the next level is stored in a file readme in the homedirectory.  
> Unfortunately, someone has modified .bashrc to log you out when you log in with SSH.  
> 概括：密码就在登录后用户目录下但是登录自动登出  

本想着使用su命令但发现报错`Authentication failure`，[关于此错误](https://blog.csdn.net/ACK_ACK/article/details/106320127)  
大概就是切换到非root用户的其他用户也要先获得root权限  
于是只能看回ssh命令尝试找到查看/home/bandit18/readme的方法  

### 相关知识

[更多关于ssh命令的内容（看SSH远程操作那一节）](https://blog.csdn.net/pipisorry/article/details/52269785)  
当然可以直接`man ssh`查看  

```shell
# 使用ssh在远程主机上执行操作
ssh usr@host 'command'
```

### 具体操作

```shell
ssh -p 2220 bandit18@bandit.labs.overthewire.org 'cat readme'
```

### 密码

```text
IueksS7Ubh8G3DCwVzrTd8rAVOwq3M5x
```

### 更多

使用ssh远程执行命令不会分配tty（终端设备），而加上`-t`参数则可分配tty  
区别表现为未分配tty执行命令后断开连接误无消息，分配tty执行命令后断开会提示Connection to xxx closed.  
此方法成功需要用户shell正常，反例见25->26,26的shell无法解析命令（个人理解）  

## Level 19 -> Level20

### 提示内容理解

> To gain access to the next level, you should use the setuid binary in the homedirectory.  
> 为获得得到下一level的密码的权限，你需要使用~/目录下的setuid 二进制文件  
> Execute it without arguments to find out how to use it.  
> 不输入参数执行它来了解如何使用  
> The password for this level can be found in the usual place (/etc/bandit_pass), after you have used the setuid binary.  
> 使用了这个setuid二进制文件后，可以在老地方(/etc/bandit_pass)找到密码  

首先根据提示了解什么是setuid  
[参考文章](https://blog.csdn.net/weixin_44575881/article/details/86552016)，概括：通过设置文件setuid权限可以使任何拥有执行该文件的用户以root权限运行此文件（普通执行变成root身份执行）  
然后查看`bandit20-do`的用法：  

```shell
./bandit20-do
# ###
Run a command as another user.
  Example: ./bandit20-do id
```

提示指出该程序可作为另一个用户执行命令  
但要注意`Example: ./bandit20-do id`，里的id不是用户的id  
而是相当于` ./bandit20-do command`的用法例  
再结合文件名可知此文件可以以bandit20的身份访问`/etc/bandit_pass/bandit20`  

然而到这里setuid并没有什么存在感，因为根本不需要管。  
这里唯一和setuid有关系的就是文件`bandit20-do`已经设置了setuid权限  

### 具体操作

```shell
./bandit20-do cat /etc/bandit_pass/bandit20
```

### 密码

```text
GbKksEFF4yrVs6il55v6gwY5aVje5f0j
```

## Level 20 -> Level 21

### 提示内容理解

> There is a setuid binary in the homedirectory that does the following:  
> ~/目录下有一个setuid二进制文件并且它会这样工作：  
> it makes a connection to localhost on the port you specify as a commandline argument.  
> 它会通过你从命令行指定的端口建立对localhost的连接  
> It then reads a line of text from the connection and compares it to the password in the previous level (bandit20).  
> 然后它会从连接中读取一行文本并且与 Level20 的密码比对  
> If the password is correct, it will transmit the password for the next level (bandit21).  
> 如果密码正确它会发送 Level21 的密码  

因为提供的程序需要给定端口连接到localhost，所以需要在localhost上开放一个服务监听端口用来提供连接  
看看提示里说可能用到的命令...可以用`nc`  
[参考视频(7:22)](https://www.youtube.com/watch?v=n7zhPMf0hxA)  
我咋就没想到这个qwq  

### 相关知识

**[nc命令](https://www.runoob.com/linux/linux-comm-nc.html)**  
**[Job Control（工作控制）](https://www.cnblogs.com/echobfy/p/3851497.html)**  
screen tmux就算了，WSL不咋好用  

### 具体操作

1. 使用Job Control一个本地终端完成
    ```shell
    nc -lvp 2333
    # listening on [any] 2333 ...
    # <Ctrl + Z>
    # [1]+  Stopped                 nc -lvp 2333
    bg %1
    # [1]+ nc -lvp 2333 &
    ./suconnect 2333
    # connect to [127.0.0.1] from localhost [127.0.0.1] 44586
    # <Ctrl + Z>
    # [2]+  Stopped                 ./suconnect 2333
    bg %2
    # ###
    [2]- ./suconnect 2333 &

    [1]+  Stopped                 nc -lvp 2333
    # ###
    fg %1
    # nc -lvp 2333
    # 粘贴 Level 20 的密码
    # GbKksEFF4yrVs6il55v6gwY5aVje5f0j
    # Read: GbKksEFF4yrVs6il55v6gwY5aVje5f0j
    # Password matches, sending next password
    # gE269g2h3mw3pwgrj0Ha9Uoqen1c9DGr
    ```
2. 直接两个本地终端远程连接
    本地终端A：

    ```shell
    nc -lvp 2333
    # listening on [any] 2333 ...
    ```

    本地终端B：

    ```shell
    ./suconnect 2333
    ```

    本地终端A：
    ```shell
    # connect to [127.0.0.1] from localhost [127.0.0.1] 40654
    # 粘贴 Level 20 的密码
    ```

    本地终端B：

    ```shell
    # Read: GbKksEFF4yrVs6il55v6gwY5aVje5f0j
    # Password matches, sending next password
    ```

    本地终端A：

    ```shell
    # gE269g2h3mw3pwgrj0Ha9Uoqen1c9DGr
    ```

### 密码

```text
gE269g2h3mw3pwgrj0Ha9Uoqen1c9DGr
```

## Level 21 -> Level 22

### 提示内容理解

> A program is running automatically at regular intervals from cron, the time-based job scheduler.  
> 一个程序正通过基于时间的任务调度程序以一定的时间间隔运行  
> Look in /etc/cron.d/ for the configuration and see what command is being executed.  
> 查看/etc/cron.d/下的配置文件看看运行的命令是什么  

了解一下corntab然后看看配置文件找密码

### 相关知识

**[crontab命令](https://www.runoob.com/linux/linux-comm-crontab.html)**  
知道这个命令用来设定配置文件中的计划任务就行了，当然还要能看懂配置文件↑  

### 具体操作

```shell
ls /etc/cron.d/
# cronjob_bandit15_root  cronjob_bandit22  cronjob_bandit24
# cronjob_bandit17_root  cronjob_bandit23  cronjob_bandit25_root
cat /etc/cron.d/cronjob_bandit22
# @reboot bandit22 /usr/bin/cronjob_bandit22.sh &> /dev/null
# * * * * * bandit22 /usr/bin/cronjob_bandit22.sh &> /dev/null
cat /usr/bin/cronjob_bandit22.sh
# ### 文件内容↓ ###
#!/bin/bash
chmod 644 /tmp/t7O6lds9S0RqQh9aMcz6ShpAoZKF7fgv
cat /etc/bandit_pass/bandit22 > /tmp/t7O6lds9S0RqQh9aMcz6ShpAoZKF7fgv
# ### 文件内容↑ ###(看第二行，把 Level 22 的密码输入到那个文件里了
cat /tmp/t7O6lds9S0RqQh9aMcz6ShpAoZKF7fgv
```

### 密码

```text
Yk7owGAcWjwMVRwrTesJEwB7WVOiILLI
```

## Level 22 -> Level 23

### 提示内容理解

> A program is running automatically at regular intervals from cron, the time-based job scheduler.  
> 一个程序正通过基于时间的任务调度程序以一定的时间间隔运行  
> Look in /etc/cron.d/ for the configuration and see what command is being executed.  
> 查看/etc/cron.d/下的配置文件看看运行的命令是什么  

和上一level一样  

> **NOTE**: Looking at shell scripts written by other people is a very useful skill.  
> 提示：观察别人写的shell脚本是一项非常有用的技能。  
> The script for this level is intentionally made easy to read.  
> 这个level的脚本特地写的非常易读  
> If you are having problems understanding what it does, try executing it to see the debug information it prints.  
> 如果你不懂它做了什么，试试运行一下看调试信息（用调试模式看吧,bash -x file.sh）  

### 相关知识

[shell编程-变量](https://www.runoob.com/linux/linux-shell-variable.html)  
能看懂下面那个shell脚本就行，主要就是使用变量  

### 具体操作

```shell
cat cronjob_bandit23
# @reboot bandit23 /usr/bin/cronjob_bandit23.sh  &> /dev/null
# * * * * * bandit23 /usr/bin/cronjob_bandit23.sh  &> /dev/null
cat /usr/bin/cronjob_bandit23.sh
```

文件内容↓，作用是将运行此文件的用户密码输入到一个临时文件中，文件名通过用户名加密生成，就是这句↓  
`echo I am user $myname | md5sum | cut -d ' ' -f 1`  

```bash
#!/bin/bash

myname=$(whoami)
mytarget=$(echo I am user $myname | md5sum | cut -d ' ' -f 1)

echo "Copying passwordfile /etc/bandit_pass/$myname to /tmp/$mytarget"

cat /etc/bandit_pass/$myname > /tmp/$mytarget
```

```shell
echo I am user bandit23 | md5sum | cut -d ' ' -f 1
# 8ca319486bfbbc3663ea0fbe81326349
cat /tmp/8ca319486bfbbc3663ea0fbe81326349
```

### 密码

```text
jc1udXuA1tiHqjIsL8yaapX5XIAI6i0n
```

## Level 23 -> Level 24

### 相关知识

**[shell编程-流程控制](https://www.runoob.com/linux/linux-shell-process-control.html)**  

`for i in *` 表示变量值为当前目录下所有非隐藏文件和目录名  
`for i in *`表示变量值为当前目录下所有隐藏文件名和目录名  
`for i in * .*`即可表示当前目录下所有文件和目录名  

**stat命令**：显示文件/文件系统的信息

[也许用得上的参考文章](https://www.cnblogs.com/klb561/p/9241228.html)  
`man stat`查看此level用到的选项  
`--format`设置输出格式  
`%U`设置格式为显示用户名  

### 具体操作

```shell
ls /etc/cron.d/
# cronjob_bandit15_root  cronjob_bandit22  cronjob_bandit24
# cronjob_bandit17_root  cronjob_bandit23  cronjob_bandit25_root
cat /etc/cron.d/cronjob_bandit24
# @reboot bandit24 /usr/bin/cronjob_bandit24.sh &> /dev/null
# * * * * * bandit24 /usr/bin/cronjob_bandit24.sh &> /dev/null
cat /usr/bin/cronjob_bandit24.sh
```

```bash
#!/bin/bash

myname=$(whoami)

cd /var/spool/$myname
echo "Executing and deleting all scripts in /var/spool/$myname:"
for i in * .*;
do
    if [ "$i" != "." -a "$i" != ".." ];
    then
        echo "Handling $i"
        owner="$(stat --format "%U" ./$i)"
        if [ "${owner}" = "bandit23" ]; then
            timeout -s 9 60 ./$i
        fi
        rm -f ./$i
    fi
done
```

通过↑此文件↑得知可以被执行的文件在/var/spool/bandit24/目录下

```
mkdir /tmp/514
chmod 777 /tmp/514
echo "cat /etc/bandit_pass/bandit24 > /tmp/514/pass" > /var/spool/bandit24/a.sh
# 给所有用户添加执行a.sh的权限
chmod a+x /var/spool/bandit24/a.sh
# ↑创建文件a.sh并写入双引号内文本↑
# 等待一分钟
cat /tmp/514/pass
```

`a.sh`不直接输出密码是因为`cronjob_bandit24`中清除了执行内容显示  
因为这个→`&> /dev/null`

### 密码

```text
UoMYTrfrBFHyQXmg6gzctqAwOmw1IohZ
```

### 问题（已解决(大概)）

为什么<span style="color:green">bandit24的计划任务</span><span style="color:red">运行的脚本</span>运行的bandit23的脚本可以读取bandit24的密码

个人理解：.sh文件本身只是一堆命令，所以bandit24执行bandit23的.sh实际上是bandit24执行一些命令


## Level 24 -> Level 25

### 提示内容理解

> A daemon is listening on port 30002 and will give you the password for bandit25 if given the password for bandit24 and a secret numeric 4-digit pincode.  
> 一个守护进程在监听30002端口，如果你向其发送bandit24的密码和一个4位数密码，它就会给你bandit25的密码。  
> There is no way to retrieve the pincode except by going through all of the 10000 combinations, called brute-forcing.  
> 除了尝试所有的10000种组合，也就是所谓的 "brute-forcing"(暴力破解？），没有任何方法可以得到这个四位数密码。  

明显就是要向localhost的30002端口发起大量尝试，不过这里注意思维不要类比到一般的账号密码登录，应该使用nc一次发送10000行而不是运行10000次nc命令

### 相关知识

**nc命令**

nc可以像telnet一样连接主机，虽然很多地方不明确但是目前只知道这里用nc才行，（不然就一个个手动试吧

```shell
# 连接方法：
nc hostname port
```
**通过nc向目标发送数据**

```shell
command | nc hostname port
```

效果相当于连接后输入一行回车等一次回应在输入这样循环往复

**还是shell编程-流程控制**  
两个例子简单说明算了，以后吧[shell.md](../../Programming/Shell%20script/shell.md)的内容补完可以引用这个

```shell
#!/bin/bash

for i in {0000..9999};
do
    echo $i;
done;
```

输出内容：

```text
0000
0001
中间省略
9998
9999
```

```shell
#!/bin/bash

for i in {3..1};
do
    echo $i;
done;
```

输出内容：

```text
3
2
1
```


### 具体操作

```shell
# 创建一个文件夹存放生成的“密码 pincode”行
mkdir /tmp/514
for i in {0000..9999}; do echo "UoMYTrfrBFHyQXmg6gzctqAwOmw1IohZ $i" > /tmp/514/pass.txt;done;
cat /tmp/514/pass.txt | nc localhost 30002
```

### 密码

```text
uNG9O58gUE7snukf3bvZ0rxhtnjzSGzG
```

## Level 25 -> Level 26

### 提示内容理解

> Logging in to bandit26 from bandit25 should be fairly easy…  
> 从bandit25登录到bandit26应该很简单...  
> The shell for user bandit26 is not /bin/bash, but something else.  
> bandit26的shell不是/bin/bash，而是其他的东西  
> Find out what it is, how it works and how to break out of it.  
> 找出它是什么，它如何工作以及如何突破它（跳出？）  

应该想到bandit26的shell不是bash带来的影响不只是表面上的登录后断开连接的，如果shell有问题就无法让终端与内核交互

### 相关知识

因为bandit26的shell不能解析命令所以无法用ssh远程执行命令（个人理解，不太懂

**在vi/vim中执行shell命令**（目前尚未明确，以下结论通过bandit26测试得出）  
底线命令模式：

1. `:command`
    使用编辑器shell处理命令并将结果发送至底线行（输入底线命令的位置）

2. `:! command`
    暂时退出编辑器使用当前用户shell执行命令，完成后在命令行显示结果并提示输入回车或命令返回编辑器

验证例：

```shell
# 通过登录bandit26后执行的more进入vi
:set shell
# 显示：shell=/usr/bin/showtext
:echo 10
# 显示：10
# 以下两命令均显示~/text.txt的内容（即登入bandit26自动执行的more的结果）
:! echo 10
:! set shell
# 多次执行 ':shell' 后往上滑动发现多个并排bandit26的字符画，再往上为登入消息，
# 可推测命令的执行过程是将'shell'命令发送至当前用户shell处理（运行了/usr/bin/showtext）
# （此文所有操作均在WSL 中进行）
```

故推测使用`:! command`执行命令是将命令交给当前用户shell处理，使用`:command`执行命令是用vi/vim的shell处理  

其他可参考文章：  
https://blog.csdn.net/bnxf00000/article/details/46618465/  
https://www.cnblogs.com/jiqing9006/p/10045464.html  

### 具体操作

缩小终端窗口然后登入bandit26，看到more的提示  
![More](_v_images/20210809190832736_5394.png)  

按`v`键进入vi编辑器并还原窗口至合适的大小  
![vi](_v_images/20210809190929541_5018.png)  

输入底线命令：  
`:set shell=/bin/bash`  
`:shell`  
成功得到bash  
![bash](_v_images/20210809191251656_26490.png)

```shell
# 直接查看bandit26的密码
cat /etc/badnit_pass/bandit26
5czgV9L3Xx8JPOyRbXh6lQbmIOWvPT6Z
```

### 密码

```txt
5czgV9L3Xx8JPOyRbXh6lQbmIOWvPT6Z
```

## Level 26 -> Level 27

### 具体操作

```shell
# 使用home目录下的bandit27-do；
./bandit27-do cat /etc/bandit_pass/bandit27
3ba3118a22e93127a4ed485be72ef5ea
```

### 密码

```txt
3ba3118a22e93127a4ed485be72ef5ea
```

## Level 27 -> Level 28

### 相关知识

**git**  
克隆仓库  
`git clone 仓库地址`  

### 具体操作

```shell
mkdir /tmp/27repo
cd /tmp/27repo
git clone ssh://bandit27-git@localhost/home/bandit27-git/repo
# 其他略
yes
# 粘贴bandit27的密码：3ba3118a22e93127a4ed485be72ef5ea
# 其他略
cd repo
cat README
# The password to the next level is: 0ef186ac70e04ea33b4c1853d2526fa2
```

### 密码

```txt
0ef186ac70e04ea33b4c1853d2526fa2
```

## Level 28 -> Level 29

### 相关知识

**git历史版本操作**  
[参考](../../Tools/GitHub/Git.md#历史版本操作)  
[git查看某次提交/更新所更改的文件及内容](https://blog.csdn.net/hbult/article/details/103079755)  

### 具体操作

```shell
mkdir /tmp/28repo
cd /tmp/28repo
# 克隆并进入仓库文件夹查看内容
git clone ssh://bandit28-git@localhost/home/bandit28-git/repo
yes
# 粘贴bandit28的密码：0ef186ac70e04ea33b4c1853d2526fa2
cd repo
# 查看README.md发现密码被修改且目录下无其他隐藏文件故从仓库历史记录操作
```

1. 直接查看更改

    ```git
    git log -p
    # 找到密码修改的行，如：↓
    # -- password: <TBD>
    # +- password: bbc96594b4e001778eee9975372716b2
    ```

2. 回溯版本查看文件

    ```git
    git log
    # ---------------- 一大堆输出 ----------------
    commit edd935d60906b33f0619605abd1689808ccdd5ee
    Author: Morla Porla <morla@overthewire.org>
    Date:   Thu May 7 20:14:49 2020 +0200

        fix info leak

    commit c086d11a00c0648d095d04c089786efef5e01264
    Author: Morla Porla <morla@overthewire.org>
    Date:   Thu May 7 20:14:49 2020 +0200

        add missing data

    commit de2ebe2d5fd1598cd547f4d56247e053be3fdc38
    Author: Ben Dover <noone@overthewire.org>
    Date:   Thu May 7 20:14:49 2020 +0200

        initial commit of README.md
    # ---------------- 一大堆输出 ----------------
    # 使仓库回到 add missing data 版本
    git reset --hard c086d11a00c0648d095d04c089786efef5e01264
    # HEAD is now at c086d11 add missing data
    cat README.md
    # 原本密码xxx(多少个x略)变为 bbc96594b4e001778eee9975372716b2
    ```

3. 直接查看某一提交的更改

    ```git
    git log
    # 其余输出略，哈希值: c086d11a00c0648d095d04c089786efef5e01264
    git show c086d11a00c0648d095d04c089786efef5e01264
    # -- password: <TBD>
    # +- password: bbc96594b4e001778eee9975372716b2
    ```

### 密码

```text
bbc96594b4e001778eee9975372716b2
```

## Level 29 -> Level 30

### 相关知识

**Git**  
[分支管理](../../Tools/GitHub/Git.md#分支的操作)  
[从远程仓库获取](../../Tools/GitHub/Git.md#从远程仓库获取)  

### 具体操作

从仓库本地分支找不到密码故考虑与仓库链接的远程仓库

```shell
git branch -a
------输出↓------
* master
  remotes/origin/HEAD -> origin/master
  remotes/origin/dev
  remotes/origin/master
  remotes/origin/sploits-dev
------输出↑------
# 使用远程仓库origin的dev分支为来源在本地仓库创建分支dev
checkout -b dev origin/dev
cat README.md
# - username: bandit30
# - password: 5b90576bedb2cc04c86a9e924ce42faf
```

### 密码

```txt
5b90576bedb2cc04c86a9e924ce42faf
```

## Level 30 -> Level 31

### 相关知识

**[Git 标签](https://www.runoob.com/git/git-tag.html)**  

**[Git 对象、底层命令](https://git-scm.com/book/zh/v2/Git-%E5%86%85%E9%83%A8%E5%8E%9F%E7%90%86-Git-%E5%AF%B9%E8%B1%A1)**  

`git show-ref`  
显示`.git/refs`下所有文件内容和其路径，文件内容为提交的哈希值  
`.git/refs/heads/`下的文件为对应分支的最近一次提交，如`.git/refs/heads/master`内容为master分支下最近一次提交的哈希值  
`.git/refs/tags/`下的文件为标签对应的提交的哈希值  

**Level 30 中提供的仓库的可能实现方式**（不包含远程仓库）  

```shell
mkdir repo
cd repo
git init
echo "just an epmty file... muahaha" > README.md
echo 47e603bb428404d265f59c42920d81e5 | git hash-object -w --stdin
# f17132340e8ee6c159e0a4a6bc6f80e1da3b1aea
git tag secret
echo f17132340e8ee6c159e0a4a6bc6f80e1da3b1aea > .git/refs/tags/secret
```

### 具体操作

```shell
mkdir /tmp/30repo
cd /tmp/30repo
ssh://bandit30-git@localhost/home/bandit30-git/repo
yes
# 粘贴bandit30的密码：5b90576bedb2cc04c86a9e924ce42faf
cd repo
git show-ref
# 3aefa229469b7ba1cc08203e5d8fa299354c496b refs/heads/master
# 3aefa229469b7ba1cc08203e5d8fa299354c496b refs/remotes/origin/HEAD
# 3aefa229469b7ba1cc08203e5d8fa299354c496b refs/remotes/origin/master
# f17132340e8ee6c159e0a4a6bc6f80e1da3b1aea refs/tags/secret
git show f17132340e8ee6c159e0a4a6bc6f80e1da3b1aea
# 47e603bb428404d265f59c42920d81e5
```

### 密码

```txt
47e603bb428404d265f59c42920d81e5
```

## Level 31 -> Level 32

### 相关知识

**[git推送到远程仓库](../../Tools/GitHub/Git.md#3推送至远程仓库)**  

**[.gitignore](https://www.jianshu.com/p/699ed86028c2):设置让git忽略的文件**  

### 具体操作

```shell
# 省略创建文件夹过程
git clone ssh://bandit31-git@localhost/home/bandit31-git/repo
yes
# 粘贴 Level 31 的密码：47e603bb428404d265f59c42920d81e5
cd repo
cat README.md
```

> This time your task is to push a file to the remote repository.  
> Details:  
>    File name: key.txt  
>    Content: 'May I come in?'  
>    Branch: master  

根据要求在当前目录创建文件，使用其中一种方式暂存文件  

1. 使用`git add key.txt -f`强行暂存文件  
2. 删除`.gitignore`中的`*.txt`后用`git add key.txt`  

提交并推送：  

```shell
git commit -m "add key.txt"
git push
yes
# 粘贴 Level 31 的密码：47e603bb428404d265f59c42920d81e5
```

> remote: Well done! Here is the password for the next level:  
> remote: 56a9bf19c63d650ce78e6ec0354ee45e  

### 密码

```txt
56a9bf19c63d650ce78e6ec0354ee45e
```