# Git
## Git 的工作方式
### Git对待数据的方法
Git把数据看作是对小型文件系统的一组快照，不比较差异。  

### Git的三种状态
* 已提交(committed0
    数据已保存在本地数据库中。  
* 已修改(modified)
    已修改了文件，但还没保存到数据库中。  
* 已暂存(staged)
    对一个已修改文件的当前版本做了标记，使之包含在下次提交的快照中。  

### Git的三个位置
* Git仓库(.git目录)
    用来保存项目的元数据和对象数据库的地方。  
* 工作目录(工作树)
    从Git仓库中提取出的某个版本的内容。  
* 暂存区
    一个文件，保存了下次将提交的文件列表信息。  

## 使用前的初始设置
可使用`git config`命令来修改配置。  

### Git的配置文件
从下往上覆盖设置。  
* `/etc/gitconfig`文件
    包含系统上每一位用户及仓库的通用设置。  
    使用`git config`命令时加上`--system`参数，就会从此文件读写配置。  

* `~/.gitconfig`或`~/.config/git/config`文件
    只针对当前用户。  
    使用`--global`参数让Git读写此文件。  

* 当前使用的仓库的Git的`config`文件(`.git/config`)
    针对当前仓库。  

### 一般的设置方式
* 设置姓名和邮箱地址
    ```
    $ git config --global user.name "Firstname Lastname"
    $ git config --global user.email "your_email@example.com"
    ```
    "~/.gitconfig"将会有如下内容:  
    ```
    [user]
      name = Firstname Lastname  
      email = your_email@example.com  
    ```
    可直接在此编辑设置。  

* 提高命令输出的可读性
    将 color.ui 设置为 auto  
    ```
    $ git config --global color.ui auto
    ```
    "~/.gitconfig"会增加下面一行
    ```
    [color]
      ui = auto
    ```

* 查看配置信息
    ```
    $ git config --list
    ```

## 基本操作
* git status——查看仓库状态，在仓库目录下使用。
    带上`-s`或`--short`参数可得到一种更紧凑的输出。  
    `??`：新添加的未跟踪文件。  
    `A`：新添加到暂存区的文件。  
    `M`：修改过的文件，出现在右边表示修改了没加入暂存区，出现在左边表示修改了且加入了暂存区。  
            或者红色表示没加入暂存区，绿色表示已加入。  
### 获取Git仓库
* git init——初始化仓库
    创建一个目录，在目录下使用`git init`初始化仓库。  
    如果初始化成功，目录下将会出现 .git 目录。  
    **工作树**  
    仓库的根目录(执行了git init)的目录称为“附属于该仓库的工作树”。  
    文件的编辑的操作在工作树中进行，之后记录到仓库中。(通过git add 和 git commit *<font color='green'>//具体在下面</font>*)。  

* git clone
    ```
    $ git clone git@github.com:用户名/仓库名.git
    $ git clone https://github.com/用户名/仓库名.git
    ```

### 记录更新到仓库
* git add——向暂存区添加文件
    暂存区是提交前的一个临时区域，使用`git add`命令将文件加入暂存区(跟踪文件)以使文件成为Git仓库的管理对象。

* git commit——保存仓库的历史记录
    将暂存区的文件实际保存到仓库的历史记录中。  
    通过这些记录可以在工作树中复原文件。  

    * 记述一行提交信息
        ```
        $ git commit -m "提交信息"
        ```

    * 向暂存区添加文件&记述一行提交信息
        已tracked的文件(使用过一次 `git add`)可用如下方式提交。
        ```
        $ git commit -am "提交信息"
        ```

    * 记述详细提交信息
        先直接执行命令。
        ```
        $ git commit
        ```
        之后会打开 vim ，以如下方式写入信息。  
        第一行：一行文字简述提交的更改内容。  
        第二行：空行。  
        第三行至后：记述更改的原因和详细内容。  
        *<font color='green'>//下面以#开头的注释会显示本次提交包含的文件，注释不需要删除。</font>*  

    * 终止提交
        直接执行`git commit`的情况下打开编辑器后留空提交信息后关闭编辑器将取消提交。

    * 忽略提交
        创建一个名为`.gitignore`的文件，列出要忽略的文件模式。  
        可使用`glob`模式(简化的正则表达式)匹配。  
        支持中括号表达式，新号作用为通配符，`**`表示匹配任意中间目录。  

* git log——查看提交日志
    在一页无法显示全部日志的情况下，命令行处会有一个冒号`:`。  
    按回车键`Enter`以显示更多内容。  
    内容显示完毕后命令行处将显示`(END)`。需要退出则按下`q`键。  
    此命令只能查看以当前状态为终点的历史日志。  

    * 只显示提交信息的第一行
        ```
        $ git log --pretty=short
        ```
    * 只显示指定目录、文件的日志
        `git log`命令后加目录名则只显示该目录下的日志，加文件名则只显示与该文件相关的日志。
    * 显示文件的改动
        ```
        $ git log -p        //查看提交带来的改动。
        $ git log -p 文件名 //查看提交后某文件的改动。
        ```
* git diff——查看更改前后的差别
    查看工作树、暂存区、最新提交之间的差别。
    `+`开头的是新增(了内容)的行。`-`开头的是删除(了内容)的行。

    * 查看工作树和最新提交的差别
        ```
        $ git diff HEAD
        ```
        HEAD：指向当前分支中最新一次提交的指针。

## 分支的操作
master 分支是Git默认创建的分支，一般以此分支为中心。
* git branch——显示分支列表
    将分支名列表显示，当前所在分支名以星号`*`开头。

* git checkout -b——创建和切换分支
    新建一个分支，并将当前分支切换为新创建的分支。
    ```
    $ git checkout -b 分支名
    ```
    * 创建分支
        此命令将创建一个分支，不会切换当前所在分支。
        ```
        $ git branch 分支名
        ```
    * 切换分支
        此命令将切换当前所在分支。会将工作树的文件切换为另一个分支的状态。  
        可用 `-`代替分支名，以切换到上一个分支。
        ```
        $ git checkout 分支名
        ```

* 删除分支
    ```
    $ git branch -d 分支名
    ```

* git merge——合并分支
    1.切换到master分支
    2.合并分支
        为了明确记录分支合并，使用`--no-ff`参数创建合并提交。
    ```
    $ git merge --no-ff feature-A(分支名)
    ```
    3.录入合并提交的信息
        默认信息已包含了从 feature-A(分支名)合并过来的相关内容，所以可直接保存并关闭。
* git log --graph——以图表形式查看分支
    可清晰的表现分支的创建和合并。  

## 历史版本操作
* 回溯历史版本
    提供目标时间的哈希值。  
    使仓库的HEAD、暂存区、当前工作树回溯到指定状态。  
    ```
    $ git reset --hard 哈希值
    ```
    可用`git log`查看哈希值，即commit 后跟的一大串十六进制数字。  
    或者用`git reflog`查看哈希值，显示为开头的十六进制数。  

* git reflog——查看仓库的操作日志

* 消除冲突
    合并冲突提示：
    ```
    CONFLICT (content): Merge conflict in README.md(文件名)
    Automatic merge failed; fix conflicts and then commit the result.
    ```
    发送合并冲突后，冲突文件将发生修改。  
    `=======`以上的部分是当前HEAD的内容，以下的部分是要合并的分支中的内容。  
    在编辑器中将内容改成想要的样子即可。  
    修改后执行`git add`和`git commit`提交。  
    *<font color='green'>//对于解决冲突，提交信息记为 "Fix conflict"。</font>*  

* git commit --amend——修改上一条提交信息
    解决合并时发生的冲突只是过程之一，用"Fix conflict"不妥。  
    执行`git commit --amend`后会打开 vim 在其中将信息改为"Merge branch '分支名'。  

* git rebase -i——压缩历史
    选定当前分支中HEAD(最新提交)在内的两个最新历史记录为对象，在编辑器中打开。
    ```
    $ git rebase -i HEAD~2
    ```
    在编辑器中，将第二行左侧的`pick`改为`fixup`。关闭编辑器。  
    结果为第二行的提交被合并到上一个提交。  
    <font color='green'>感觉不是必须的还是不要这么做的好，压缩之后会造成无法提交。</font>  
    <font color='green'>虽然可以使用`--force`参数强制提交但是有一定风险。</font>  
    > 例：将"Fix typo"(修复错字漏字)提交合并。  
    > 在分支 feature-C 下有两次提交：
    > ```
    > $ git commit -am "Add feature-C"
    > $ git commit -am "Fix typo"
    > ```
    > 将"Fix typo"合并
    > ```
    > $ git rebase -i HEAD~2
    > ```
    > Vim 中的修改：
    > ```
    > pick 7a34294 Add feature-C
    > pick(改为fixup) 6fba227 Fix typo
    > ```
    > 结果：  
    > 两次提交合并为"Add feature-C"且哈希值改变。  

## 推送至远程仓库
### 1.在GitHub上创建一个空仓库。
保存仓库名与本地仓库一致。  
不勾选其他选项(创建一个空仓库)。  
### 2.添加远程仓库
GitHub上创建的仓库的位置(SSH)：git@github.com:用户名/仓库名.git。  
使用下面的命令将GitHub的仓库设置为本地仓库的远程仓库。Git会自动将该远程仓库命名为`origin`
```
$ git remote add origin git@github.com:用户名/仓库名.git
```
删除指定远程仓库：`git remote rm origin(仓库标识符)`

### 3.推送至远程仓库
* 推送至master分支
    切换到master分支。
    ```
    $ git push -u origin(远程仓库名) master
    ```
    -u:在推送的同时，将origin仓库的master分支设置为本地仓库当前分支的upstream(上游)。  
    将来运行`git  pull`命令从远程仓库获取内容时，本地仓库的此分支可以直接从origin的master分支获取内容。  
    <font color='orange'>似乎不需要切换到对应的分支下，例如在master分支下也可以提交feature-D分支。</font>  
    <font color='orange'>还是一致比较好。</font>  

* 推送至master以外的分支
    ```
    $ git checkout -b feature-D
    $ git push -u origin feature-D
    ```

## 从远程仓库获取
* 获取远程仓库
    创建一个空目录。  
    运行命令。  
    ```
    $ git clone git@github.com:用户名/仓库名.git
    ```
    此命令会将远程仓库的master分支复制到本地，同时自动将origin设置成该远程仓库的标识符。  
    * 显示本地仓库和远程仓库的分支信息。
        ```
        $ git branch -a
        ```

* 获取远程的其他分支
    新建分支后接上分支来源。  
    ```
    $ git checkout -b feature-D origin/feature-D
    //以名为origin的仓库的feature-D分支为来源，在本地仓库中创建feature-D分支。
    ```

* 推送分支
    ```
    $ git push
    ```

* git pull——获取最新的远程仓库分支
    在feature-D分支下，
    将本地的feature-D分支更新到最新状态。
    ```
    $ git pull origin feature-D
    ```












