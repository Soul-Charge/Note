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

#### 了解对仓库贡献时的规则
在仓库的根目录下添加CONTRIBUTING.md，
在其中描述希望贡献者遵循的规则。
>如Issue的描述方法、Pull Request时的规则要求、许可证的相关信息。  

贡献者将在创建Issue等时候看到一条规范链接。要做贡献应该仔细阅读。  
链接文本：Please review the guidelines for contributing to this repository.  

#### Issue
* Issue 的用途
    * 发现软件的BUG并报告。
    * 有事想向作者询问、探讨。
    * 事先列出今后准备实施的任务。

* 描述方法——GFM
    GitHub的Issue和评论可以使用GFM语法进行描述。
    * Tasklist
        >例：以如下方式编辑
        >```
        ># holiday daily task
        >- [ ]  Learning English at least 80 minutes.
        >- [ ]  Learning Psychology at least 40 minutes.
        >- [ ]  Running at least 30 minutes.
        >```
        >将显示为
        >![tasklist](_v_images/20190724202207152_7615.jpg)

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
![milestone_add_issue](_v_images/20190723222934603_903.jpg)

* 通过提交信息操作Issue
    * 将提交与Issue关联
        在提交信息的描述中加入Issue的编号(#n)，可将提交和Issue关联。  
        在Issue中可以看到相关的提交，可以点击跳转到对应提交。  
        在提交信息中点击编号可跳转到对应Issue。  
    * Close Issue
        在提交中以下列任意一种格式描述提交信息，对应的Issue就会被Close。  
        fix #n、fixes #n、fixed #n、close #n、closes #n、closed #n、resolve #n、resolves #n、resolved #n

* 将特定的Issue转换为Pull Request
    Issue与Pull Request的编号相互通用。

#### Pull Request
* 获取diff格式与patch格式的文件
    以diff格式和patch格式文件的形式处理Pull Request。  
    在Pull Request的URL后添加`.diff`或`.patch`。  
    >例：假设Pull Request的URL为 https://github.com/用户名/仓库名/pull/28
    >diff格式的文件：https://github.com/用户名/仓库名/pull/28.diff
    >patch格式的文件：https://github.com/用户名/仓库名/pull/28.patch

* Conversation
    * 引用评论
        选择(按住左键右滑)想引用的评论然后按`r`键，选择部分会自动写入评论文本框。  

* Commits
    提交右侧的哈希值可以连接到该提交的代码。  
    * 在评论中应用表情
        可使用的表情：<http://www.emoji-cheat-sheet.com/>  
        在评论中输入`:`会启动表情自动补全。

* Files Changed
    在URL的末尾添加`?w=1`可以显示不显示空格的差别。  
    点击蓝底白色加号可以对某一行进行评论。  

#### Wiki
Wiki的Git仓库URL：git@github.com:用户名/仓库名.wiki.git  
可通过clone获取wiki仓库，然后本地修改在push。  
一般wiki记载软件相关的FAQ、文档、代码示例及解说。  
* 在wiki中显示侧边栏
    创建一个名为`_sidebar`的页面。  
    在其中编辑边栏内容。
    >例：
    >```
    >## Getting Started
    >* [Getting Started with Kingfisher](https://github.com/onevcat/Kingfisher/wiki/Getting-Started-with-Kingfisher)
    >* [Install Kingfisher](https://github.com/onevcat/Kingfisher/wiki/Installation-Guide)
    >* [Cheat Sheet](https://github.com/onevcat/Kingfisher/wiki/Cheat-Sheet)
    >* [API Reference](http://onevcat.github.io/Kingfisher/)
    >```
    >效果：
    >![sidebar](_v_images/20190725115606912_23888.jpg)

#### Pulse
Insights->Pulse  
可以体现一个仓库软件开发的活跃度。  
* active pull requests
    特定期间内活动过的Pull Request数。  
    可以了解到该软件最近正在开发哪些功能。

* active issue
    特定期间内活动过的Issue数。  
    通过观察Issue的整体动向，可知道这个软件是否有人在积极维护与支持。

* commits
    Overview下方，与提交相关的信息。  
    左侧文字信息包含下面几类。  (冒号后面是显示方式)
    * 编写过代码的人数: n author
    * 提交的次数 n commits
    * default branch 中修改过的文件数: n files
    * dafault branch 中添加的行数: n additions
    * default branch 中删除的行数: deletions
    通过这些信息，可以大致把握该仓库中活跃开发者的人数。  
    通过图表还可以了解到有哪些开发者在积极的提交。  

* Releases published
    repository->releases
    可以了解到该软件的版本升级频率。

* Unresolved Conversations
    Pulse 页面下可能在最下面。  
    未Closed的Issue和Pull Request。  

#### Graphs
* Contributors
    Insights->Contributors  
    可以看到每个用户在相应日期中发送提交、添加代码、删除代码的大致数量。  
    可以了解到仓库的代码主要由哪些人编写。  
    还可以分析出该软件大幅修改阶段和稳定维护时期的相应时期。  

* Commit Activity
    显示了一年内每周提交的大致数量。  
    还可以查看相应周对应每天的提交数量。  
    可判断仓库是否有人在积极更新。  

* Code Frequency
    显示了仓库中代码行数的增加量和删除量。  
    <font green='orange'>左边的单位是k，怎么感觉是字节数。</font>

* Punchcard
    找不到。。。  

#### NetWork
以图表形式显示包括克隆仓库在内的所有分支的提交。  
将鼠标指针停在提交或合并的点上，可以查看相应的参考内容。

#### Settings
* Options
    * Features
        可以更改Wiki和Issue的相关设置。  
        取消勾选的复选框可移除功能。
    * GitHub Pages
        可利用仓库中的资料创建web页。
        * master分支下的docs文件夹
            1.在master分支下创建一个docs文件夹。  
            2.在该文件夹内放入页面。  
            3.在Source的下拉选项中选择`master branch /docs folder`  。  
            4.之后页面刷新，在Source上有蓝底显示的文本和页面链接。  
            页面链接形式：https://用户名.github.io/仓库名/
        * gh-pages分支
            1.创建`gh-pages`分支。  
            2.将页面内容放入。  
            3.在Source的下拉选项中选择`gh-pages branch`。  
            4.页面刷新，在Source上有蓝底显示的文本额页面链接。  
        * master分支
            直接将页面内容放在master分支下。下拉选项中选择`master branch`。  

    * Danger Zone
        删除仓库等危险操作。

* Webhooks
    当仓库有新的操作，会触发调用web接口，通知对应的服务器。

* Collaborators
    设置仓库的访问权限。  
    如果仓库属于个人账户，可以添加用户名，赋予用户读写仓库的权限。  
    如果仓库属于组织账户，需要先创建Team，然后赋予该Team读写仓库的权限。  

* Deploy Keys
    可以给仓库单独添加一个SSH公匙，允许以只读方式访问仓库。  
    一对密匙对应一个仓库。  

### Notifications
页面右上角的铃铛，当创建Issue、收到评论、创建Pull Request等情况发生时会在此收到通知。  

### 其他功能
* GitHub Jobs
    面向全世界招聘程序员的职位公告板。  
    450美元发布30天招聘公告。  

* GitHub Enterprise
    以虚拟机的形式提供GitHub。  
    主要面向20人以上的组织。  
    为无法将源码放到公司之外的企业设计。  
    <https://enterprise.github.com/pricing>

* GitHub API
    <https://developer.github.com/>

## Pull Request
### 概要
* Pull Request 是什么
    自己修改源代码后，请求对方仓库采纳修改时采取的行为。  

* Pull Request的流程
    1.本地修改代码。
    2.发送Pull Request请求合并修改。
        接受方的仓库会创建一个附带源码的Issue。
    3.对方仓库管理员接受Pull Request。

### 发送Pull Request前
1.在要修改的仓库页面下点击`Fork`将仓库克隆到自己的账户下。  
2.使用`clone`将自己账户下的新仓库复制到本地。  
3.在仓库创建一个特性分支在其中作业。  
4.修改完成后提交到自己账户下的Fork过来的仓库。(创造远程分支)  
```
git push origin 特性分支名
```

### 发送PullRequest
在Fork过来的仓库切换到新建的特性分支。  
点击`Compare`查看更改是否正确。点击`Create Pull Request`发起。  
在评论栏中描述Pull Request的理由。  

### 让Pull Request更有效的方法
* 在开发过程中发送Pull Request进行讨论
    在想发起讨论时发送Pull Request，不必等代码最终完成。  
    在Pull Request中加入TaskList描述代办与完成。  
    注意不要在Pull Request中添加无关的修改。  

* 明确标出“正在开发中”
    还未开发完成的Pull Request在标题前加上`[WIP]`[^WIP]
    [^WIP]: Work In Process

* 不Fork直接从分支发送Pull Request
    对仓库有编辑权限的成员可以直接创造分支，从分支发送Pull Request。  

### 仓库的维护
使Fork或clone来的仓库保持最新状态。  
通过将原仓库设置为远程仓库，从该仓库获取(fetch)数据与本地仓库进行合并，让本地仓库的源码保持最新状态。  
<font color='orange'>那Fork来的仓库怎么保持最新，把本地仓库push上去？</font>

#### 1.将仓库Fork到自己账户下并clone到本地

#### 2.将原仓库设置为本地仓库的远程仓库
将远程仓库设置`upstream`的名称。  
```
$ git remote add upstream git://github.com/用户名/仓库名.git
```
<font color='orange'>git:? 不是https:吗</font>
<font color='orange'>用这个使我电脑蓝屏，应该是书中错误。</font>

#### 3.从远程仓库获取数据与本地仓库分支进行合并
获取最新分支。  
```
$ git fetch upstream
```
与本地分支合并。  
```
$ git merge upstream/master
```
<font color='green'>*//`git fetch`只会获取但不会自动合并。也可以直接使用`git pull`*</font>

## 接收Pull Request
### 接收准备
* 代码审查
    在某个Pull Request的详细页面点击`Files changed`可查看文件的更改，可对某一行进行评论。  

* 查看图片的差别
    有多种方式查看图片的差别，现在好像用不了了。  
    <https://github.com/cameronmcefee/Image-Diff-View-Modes>

* 在本地反应Pull Request的内容
    1.将接收方的本地仓库更新至最新状态
    clone接收方仓库，已clone就用`git pull`等命令更新。  
    2.获取发送方的远程仓库
    ```
    $ git remote add PR发送者 git@github.com:PR发送者/仓库名.git
    $ git fetch PR发送者
    ```
    3.创建用于检查的分支
    4.合并
    切换到用于检查的分支。  
    ```
    $ git merge PR发送者/分支名
    ```
    5.删除检查用分支

### 接收方法
* 在GitHub上接收
    仓库页面点击`Pull Request`进入列表，点击一个Pull Request 进入详细页面点击`Merge pull request`  

* 通过Git接收
    1.合并到主分支
    切换到主分支然后合并获取的分支。  
    2.push修改内容
    先查看本地与GitHub端仓库的差别。  
    ```
    $ git diff origin/gh-pages(分支名)
    ```
    之后直接`git push`即可，Pull Request会自动关闭。  

## 与GitHub相互协作的工具及服务
### Hub命令
#### Hub的安装
* Windows
    在powerShell中执行下方命令安装scoop。  
    ```
    iex (new-object net.webclient).downloadstring('https://get.scoop.sh')
    ```
    如不能安装则执行下面的命令更改执行策略。  
    ```
    Set-ExecutionPolicy RemoteSigned -scope CurrentUser
    ```
    scoop 安装成功后安装hub。  
    ```
    scoop install hub
    ```
    使用下面的命令确认hub已安装。  
    ```
    $ hub --version
    ```

#### 初始设置
* `~/.config/hub`
    使用hub命令初次访问GitHub的API时会询问用户名和密码。  
    输入完后会进行OAuth认证，Token会自动保存在`~/.config/hub`中。  
    Token可在Settings/Developer Settings/Personal access tokens 页面查看。  
* 设置别名
    将相应git设置为hub的别名。  
    在Shell的配置文件(.bash_profile)添加下面一句。  
    ```
    eval "$(hub alias -s)"
    ```
    <font color='orange'>Windows不知道在哪设置。</font>  

* 实现Shell上功能的补全
    GItHub上发布了面向bash和zsh的脚本。  
    bash:<https://github.com/defunkt/hub/blob/master/etc/hub.bash_completion.sh>  
    zsh:<https://github.com/defunkt/hub/blob/master/etc/hub.zsh_completion>  
    将正在使用的shell与相应脚本组合可让hub命令更易用，在某些安装方法会自动安装。  
    <font color='orange'>不知道怎么组合，也不知道怎么样的更易用，还不知道有没有自动安装。</font>  

#### 命令
* hub help
    ```
    $ hub help
    ```
    查看hub命令的相关帮助。  

* hub fork
    在clone过来的本地仓库中使用此命令，相当于在GitHub上Fork了此仓库。  
    执行完毕后，Fork出的仓库会被设置为当前本地仓库的远程仓库（以用户名为标识符）。  

* hub pull-request
    可通过命令行创建Pull Request。  
    ```
    $ hub pull-request -b 接收方用户名:接收分支名 -h 发送方用户名:发送分支名
    ```
    执行命令后会启动编辑器，第一行写标题，空一行第三行正文。  
    >例：
    >```
    >$ hub pull-request -b github-book:master -h hirocaster:index5-draft
    >```
    >从hirocaster的index5-draft分支向github-book的master分支发送Pull Request。  

    如果要发送Pull Request的分支是已存在的Issue的作业内容，可直接将Issue作为Pull Request发送。  
    ```
    $ hub pull-request -i Issue编号数字 -b 接收方用户名:接收分支名 -h 发送方用户名:发送分支名
    ```
    >例：
    >index5-draft的作业内容是已创建的Issue#123的作业内容。  
    >```
    >$ hub pull-request -i 123 -b github-book:master -h hirocaster:index5-draft
    >```

* hub create
    适用于本地已创建仓库但GitHub上没创建仓库的情况。  
    使用此命令会在GitHub上创建一个同名仓库。  

* hub browse
    可在浏览器中打开当前操作的仓库在GitHub上的页面。  
    可用别的等效命令。
    ```
    $ open https://github.com/用户名/仓库名
    ```

* hub compare
    可在GitHub上查看当前分支与master分支的差别。  
    查看的是GitHub端仓库的差别。  

* hub clone
    可以只指定仓库名或用户名/仓库名。  
    >例：
    >```
    >$ hub clone Hello-World
    >$ hub clone octocat/Hello-World
    >```

* hub push
    此命令支持同时向多个远程仓库进行push操作。  
    仓库名之间用逗号隔开。  
    ```
    $ hub push origin, staging, qa
    ```

### Travis CI
托管面向开源开发组织的CI[^CI]。  
[^CI]:Continuous Integration, 持续集成  

让CI软件监视仓库，可以在开发者执行提交后自动进行测试或构建。  
支持Web相关语言。  
<http://travis-ci.org/>  
<http://about.travis-ci.org/docs>  

* 与GitHub集成
在仓库添加`.travis.yml`。  
    * 编写配置文件
        参考[官方网站的相关文档](http://about.travis-ci.org/docs/user/getting-started/)进行设置。  
        编写完成后，将配置文件放到仓库路径下在push给GItHub端。  

    * 检查配置文件
        使用[Travis WebLint](http://lint.travis-ci.org/)进行检查。  
        检测是只需指定仓库。  
        <font color='orange'>不知道怎么指定仓库，好像现在用不了(2019.7.31)。</font>  

    * 在Travis CI的网站上设置
        访问[官方网站](http://travis-ci.org/)点击`Sing with GitHub`  
        点击`repositories`可查看仓库列表，将右侧的开关设置为ON即可应用Travis CI。  
        仓库在Travis CI的位置：<https://travis-ci.org/用户名/仓库名>  

    * 将Travis CI的结果添加至README.md
        用MarkDown语法如下描述。  
        ```
        [![Build Status](https://secure.travis-ci.org/用户名/仓库名.png)](http://travis-ci.org/用户名/仓库名)
        ```

### Jenkins
代表性的持续集成服务器，可以自动测试。  
将Jenkins与GitHub集成，并将Pull Request设置为触发器，可自动测试并将结果发送至GitHub的Pull Request页面。  
<font color='orange'>感觉暂时用不上，先挂起好了。</font>  

### Coveralls
借助Travis CI或Jenkins等持续集成服务器，报告自动测试的测试覆盖率。  
[官方网站的相关文档](https://coveralls.io/docs)  
使用前提条件：源代码保存在GitHub上，已经集成了Travis CI 或 Jenkins等服务。  

* 注册
    进入[主页](https://coveralls.io/)点击注册使用GitHub注册账户。  

* 添加对象仓库
    点击`ADD REPO`将仓库名左边的开关设置为ON。  

* 编写配置文件
    在coveralls里查看仓库有配置文件解说。  
    配置文件名：`.coveralls.yml`，将此文件放入仓库路径。  
    repo_token 可在仓库的配置文件解说界面找到。  

### Gemnasium
可以查询GitHub仓库中软件正在使用的RubyGems或npm是否是最新版本。  

### Code Climate
代码分析报告服务，可以查出质量有问题的代码，同时可给软件评级。  
收费服务，有14天试用。  

### Coderwall
可以根据GItHub的仓库信息为开发者免费生成个人信息。  

## 使用GitHub的开发流程
### GitHub Flow——以部署为中心的开发模式
部署：在正式环境中配置源代码并试运行。  

### GitHub Flow 的流程
1.令master分支时常保持可部署的状态。  
2.进行新的作业时要从master分支创建新分支，新分支名称要具有描述性。  
3.在`2.`新建的本地仓库分支中进行提交。  
4.在GitHub端仓库创建同名分支，定期push。  
5.需要帮助或反馈时创建Pull Request，以Pull Request进行交流。  
6.让其他开发者进行审查，确认完作业后与master分支合并。  
7.与master分支合并后立刻部署。  

* 关于创建新分支和提交
    应明确在分支中应该做的，不能在分支中做无关的修改。  
    应减小提交的规模，使每一次提交清晰。  

* 让其他开发者审查
    通过自动测试后让其他开发者进行审查。  
    认为可以合并会发`:+1:`或`:shipit:`等表情或`LGTM`(Looks good to me)。  

### 实践GitHub Flow的前提条件
* 部署作业完全自动化
    * 使用部署工具
    
        |    名称    |                    URL                     |             备注             |
        | ---------- | ------------------------------------------ | --------------------------- |
        | Capistrano | <https://github.com/capistrano/capistrano> | Ruby开发的代表性部署工具      |
        | Mina       | <https://github.com/nadarei/mina>          | Ruby开发的部署工具            |
        | Fabric     | <http://fabfile.org/>                      | Python开发的部署工具          |
        | Cinnamon   | <https://github.com/kentaro/cinnamon>      | Perl开发的部署工具            |
        | Webistrano | <https://github.com/kentaro/webistrano>    | 可通过Web执行Capistrano的工具 |
        | Strano     | <https://github.com/joelmoss/strano>       | 同上，中间件不同              |

    * 导入开发时的注意事项
        实施部署时通过工具上锁，通知团队。防止一个部署还没完成就开始下一个。  

* 重视测试
    * 测试自动化
        <font color='orange'>指的是本地测试？</font>
    * 编写测试代码，通过全部测试
        成品代码的Pull Request要包含测试代码且全部通过。  
        本地代码通过所有测试后，push到远程仓库通过CI工具自动测试。  
        先写测试代码再写实现。  
    * 维护测试代码

### GitHub Flow 的建议
* 减小Pull Request的体积

* 准备可供试运行的环境
    如果分支中包含对系统有重大影响的关键性修改，最好先将其部署到预演环境部署。  

* 不让Pull Request中有太多反馈
    交流不足就通过其他手段交流，技术或能力问题就先制定好规则。  

* 不要积攒Pull Request


### Git Flow——以发布为中心的开发模式
#### 流程
1.从开发版分支(develop)创建工作分支(feature branches)，进行功能的实现或修正。  
2.工作分支的修改结束后，与开发版分支合并。
3.重复`1`和`2`直至可以发布。
4.创建用于发布的分支(release branches)，处理发布的各项工作。
5.发布完成后与master分支合并，打上版本标签(Tag)进行发布。
6.如果发布的版本出现BUG，以打了标签的版本为基础进行修正(hotfix)。
![20190801083938182_9239](_v_images/20190810135318718_8356.png)

#### 前期准备
* 安装git-flow
    ```
    $ git flow
    ```
    可运行即可。  

* 仓库的初始设置
    1.GitHub上新建仓库并clone到本地。  
    2.`git flow init -d`默认方式初始化，会自动创建develop分支。  
    3.将develop分支push上去`git push -u origin develop`  
    <font style='background:yellow'>caution:对分支进行任何操作前必须先执行`pull`获取最新代码。  </font>  

#### 详细内容
##### master分支与develop分支
贯彻开发流程的两分支，不会被删除。  

* master 分支
    保存着软件可以正常运行的状态，不能直接对其进行修改。  
    其他分支进展到可以发布的程度后，将与master分支进行合并。(只在发布成品时合并，且附带包含版本号的Git标签)  

* develop 分支
    不能直接进行修改。  
    以develop分支为起点新建feature分支并在其中进行修改。  

##### 在feature分支中进行的工作
###### 1.从develop分支创建feature分支
先确保develop分支为最新状态。  
创建feature分支。  
```
$ git flow feature start add-user(分支名)
```
![built feature](_v_images/20190801094649905_15472.jpg)

###### 2.在feature分支中实现目标功能
![working in feature branchs](_v_images/20190801094325108_24941.jpg)

###### 3.通过GItHub向develop分支发送Pull Request
先确保develop和feature分支都为最新状态，然后push本地feature分支。  
在GitHub页面从feature分支发送Pull Request。  
确保合并对象正确。  
![merge](_v_images/20190801130159201_12675.jpg)

>设置默认分支
>可在仓库的`Settings/Default Branch`将默认分支设置为develop

###### 4.接受审查后，将Pull Request合并至develop分支
* 流程
    1.由其他开发者进行审查，在Pull Request中反馈。
    2.修正代码反映反馈内容(在本地feature/add-user分支中)。
    3.将feature/add-user分支push到远程仓库(会自动添加到之前的Pull Request)。
    4.重复前三步，没有问题后将分支合并到develop分支。

* 反馈要点
    * 没测试或测试不通过
    * 违反编码规则
    * 代码品质过低（方法不明确，方法冗长等）
    * 还有重构的余地
    * 有重复部分

![After PR](_v_images/20190801131928810_16994.jpg)

###### 5.更新本地develop分支
Pull Request 在GitHub端与develop合并后，要更新本地的develop分支。  

##### 在release分支中进行的工作
发布所需的工作完成后开始分配版本号进行发布，今后此版本只做BUG修复。  
###### 1.创建分支
在最新的develop分支下开始release分支。  
```
$ git checkout develop
$ git pull
$ git flow release start '1.0.0'(版本)
```
创建后的情况：  
![start release](_v_images/20190801132745819_30769.jpg)

###### 2.分支内的工作
只处理与发布前准备相关的提交。  
>版本编号变更等元数据的添加
相关BUG的修正也添加到此分支。  

###### 3.进行发布与合并
**发布**
修正完成后结束分支。  
```
$ git flow release finish '1.0.0'
```
release发布结束后的状态。  
![After release finish](_v_images/20190801133631819_13167.jpg)

**合并**
之后release分支与master分支合并，没有需要特别声明的事项直接保存默认状态关闭编辑器。  
合并后的master分支会加入一个与版本号相同编号的标签，输入这一版本的相关提交信息。  
```
Release 1.0.0
#
# Write a tag massage
# Lines starting with '#' will be ignored.
#
```
<font color='orange'>这里没有试过，不是很清楚。</font>  
master分支添加标签后的状态：  
![master after tag](_v_images/20190801134731549_27112.jpg)

**将release合并至develop分支。**  
```
$ git flow release finish '1.0.0'
```
合并后的状态：  
![merge release with develop](_v_images/20190801152747474_21333.jpg)

**查看版本标签**
前面的操作创建了与发布版本号相同的Git标签，通过这个标签可回溯到此版本。  
```
$ git tag
```

###### 4.更新到远程仓库
将develop分支和master分支push到远程仓库，再push标签信息。  
```
$ git push --tags
```

##### 在hotfix分支中进行的工作
只有在当前发布的版本中出现BUG或漏洞，且严重程度要求开发方必须立即处理，无法等到下一个版本发布时才被创建的分支。  
hotfix分支以发布版本的标签或master分支为起点。  
###### 1.创建分支和进行修改
确保本地仓库的标签号最新。  
```
$ git fetch origin
```
以最新标签号为起点创建新版本分支。  
```
$ git flow hotfix start '1.0.1'(新版本) '1.0.0'(旧版本)
```
新分支为`hotfix/1.0.1`，在此分支进行修改。  
修改完成后push到远程仓库在向master分支发送Pull Request。  

###### 2.创建标签和进行发布
master分支已合并了hotfix分支的Pull Request后，在GitHub端创建新标签。  
位置：`repository/release`  
点击`Draft a new release`，在`Tag version`中输入hotfix分支新建的标签名(这里是1.0.1)。  
点击`Publish release`完成创建标签。  

###### 3.从hotfix分支合并至develop分支
在GItHub端从hotfix分支向develop分支发送Pull Request，进过审查后合并。  
如果合并后develop分支出现异常应在合并后在develop分支中修改。  
hotfix分支只对master分支进行最少的修改。  
目前状态(部分)：  
![hotfix status after merge](_v_images/20190801211426606_8318.jpg)

### 版本号分配规则
* 格式：x.y.z
* x：重大功能变更或新版本不向下兼容时，加1，y与z归0
* y：添加新功能或删除已有功能时加1，z归0
* z：只在进行内部修改后加1
>例
>* 1.0.0：最初发布版本
>* 1.0.1：修正了轻微BUG
>* 1.0.2：修复漏洞
>* 1.1.0：添加新功能
>* 2.0.0：更新整体UI并添加新功能


## Gist
### Gist的特点
可与他人分享实例代码（小的代码片段）。  
Gist的历史记录保存在Git仓库内。  
<font color='orange'>好像被墙了，开了VPN才能连上。</font>  