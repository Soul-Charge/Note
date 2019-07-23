# Github
## 前期准备
* 设置SSH key
    运行下面命令。
    ```
    $ ssh-keygen -t rsa -C "your_email@example.com"
    ```
    "your_email@example.com"改成注册GitHub账号时使用的邮箱。

    设置目录和密码。
    ```
    (Users/your_user_directory/.ssh/id_rsa):(按回车键设置为默认目录)
    Enter passphrase (empty for no passphrase):(输入密码)
    Enter same passphrase again:(再次输入密码)
    ```

* 添加公开密匙
    1.点击头像->Settings->SSH and GPG keys->New SSH key。
    2.在Title中输入密匙名称，把id_rsa.pub文件的所有内容复制到 Key中。

    查看id_rsa.pub公匙内容:  
    1.(windows)在Git Bash 中输入下面命令。
    ```
    $ cat ~/.ssh/id_rsa.pub
    ```
    2.打开 id_rsa.pub 文件。
    默认目录：/Users/your_user_directory/.ssh/id_rsa.pub
## 创建仓库
* Add .gitignore
    初始化时自动生成 .gitignore文件，里面记录了不需要进行版本管理的文件。
    在下拉菜单中选择使用的语言或框架将生成对应的.gitignore文件。
    > 例如选择 C 后将在.gitignore里设置忽略 .o 等文件。
* Add a license
    添加许可协议，不是很懂。  

仓库的页面：https://github.com/用户名/仓库名

## GitHub的各种功能
### 键盘快捷键
按下`shift` + `/`可打开快捷键表。

### 工具栏
* LOGO
    点击GitHub的LOGO可进入控制面板。
* Explore
    从各个角度介绍GitHub上的热门软件。
    有机会了解到最尖端的技术和软件。
* Gist
    用于管理和发布一些不需要保存在仓库里的代码，如小的代码片段。

### 控制面板
* News feed
    显示以follow的用户和已watch的项目的活动信息。
* Pull Requests
    显示已进行过的`Pull Request`。

### 仓库
#### 文件的相关操作
点击文件名会显示文件的内容，还有用于该文件的菜单。
* 操作菜单
    * Edit:对文件进行编辑。
    * Raw:文件的URL，点击可直接在浏览器显示，也可用HTTPS协议获取此文件。
    * Blame:按行显示最新提交的信息。
* 文件上的操作
    点击文件内容左侧的行号，该行将高亮标记。  
    该文件URL末尾会添加:"#Ln"。<font color='green'>*// n为行号*</font>
    若改成"Lm-n"则会标记该文件的m到n行。  
* 其他操作
    在仓库按下`t`键，进入搜索模式。输入要查找的目录或文件的部分名称可进行查找。

#### 查看差别
通过修改URL的方式查看差别。

* 查看分支间的差别
    ```
    https://github.com/用户名/仓库名/compare/分支名...分支名
    ```
    >以Ruby on Rails的仓库[^1]为例。  
    >查看4-0-stable分支与3-2-stable的差别。  
    >https://github.com/rails/rails/compare/4-0-stable...3-2-stable  
[^1]:https://github.com/rails/rails/  

* 查看某分支几天内的差别
    ```
    https://github.com/用户名/仓库名/compare/分支名@{数字.时间单位.ago}...分支名
    前后分支名要一致。
    ```
    时间单位：day、week、month、year  
    若差别过大不会列出所有提交。  
    >例：查看master分支在最近7天内的差别。(还是上例的仓库)
    >https://github.com/rails/rails/compare/master@{7.day.ago}...master

* 查看某分支与指定日期之间的差别
    ```
    https://github.com/用户名/仓库名/compare/分支名@{日期}...分支名
    日期格式：年-月-日
    前后分支名要一致。
    ```
    差距过大或指定日期太久远会无法显示。  
    >例：查看master分支2013年1月1日与现在的区别。(上例仓库)
    >https://github.com/rails/rails/compare/master@{2013-01-01}...master

### Issue
* Issue 的用途
    * 发现软件的BUG并报告。
    * 有事想向作者询问、探讨。
    * 事先列出今后准备实施的任务。

* 描述方法——GFM
    GitHub的Issue和评论可以使用GFM语法进行描述。

* 添加标签
    open Issue后可给Issue添加标签(Label)。
    可以按照语言和技术分类，或者根据BUG、任务、备忘等作业类型分类。

* 添加里程碑
    可通过添加里程碑的方式来管理Issue。
    1.先点击`New milestone`创建一个里程碑。
        Issues->Milestones->New milestone
    2.然后回到Issue->Milestones的界面点击创建的里程碑，
    点击`New issue`创建里程碑里的Issue。
    3.或者在`Create new issue`下方点击蓝色链接将未加入里程碑的Issue加入里程碑。
![milestone_add_issue](_v_images/20190723222934603_903.jpg =450x)

// p92






