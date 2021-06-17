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
或
ssh -p 2220 -l bandit0 bandit.labs.overthewire.org

输入密码：`bandit0`
cat readme
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