# Bandit

## Level 0 -> Level 1

### 相关知识

ssh登录与基本的`ls` `cat` 命令  
ssh 用法：

```shell
ssh -p 端口 用户名@主机名
```

### 具体操作

```shell
ssh -p 2220 bandit0@bandit.labs.overthewire.org
输入密码：`bandit0`
cat readme
```

### 密码

```text
boJ9jbbUNNfktd78OOpsqOltutMc3MY1
```

## Level 1 -> Level 2

### 相关知识

处理以`-`开头的文件名的文件  
两种方式:  

```shell
command -- -file
command ./-file
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

```shell
command ./f ile
command "f ile"
```

### 具体操作

/*  省略登录操作 */

```shell
/* 按tab键自动补全 */
cat s<tab>
cat "s<tab>
/* 完整命令 */
cat spaces\ in\ this\ filename
cat "spaces is this filename"
```

### 密码

```text
UmHadQclWmgdLOKQ3YNgjWxGoRMb5luK
```

## Level 3 -> Level 4

### 相关知识


### 具体操作

### 密码

## Level 4 -> Level 5

### 相关知识


### 具体操作

### 密码

## Level 5 -> Level 6

### 相关知识


### 具体操作

### 密码