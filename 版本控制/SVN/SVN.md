# 常见错误

####  svn“Previous operation has not finished; run 'cleanup' if it was interrupted“报错的解决方法

> [参考教程：http://blog.csdn.net/superch0054/article/details/38668017](http://blog.csdn.net/superch0054/article/details/38668017)


**【原因分析】**可能是频繁做了一些改名，文件打开的时候更新或者提交操作，导致svn罢工了。这个也该算是svn的bug吧。

**【方案一】**把整个svn checkout的主目录都删掉，重新checkout来解决的。但是随着项目的深入开展，要更新的文件越来越多。

**【方案二】**SVN的operation是存放在 `work queue` 里的。而 `work queue` 是在内嵌数据库 `wc.db` 的 `work_queue` 表中的。看看work_queue表中放了些什么，再做处理。

** 首先尝试在终端中进入该`.svn`层级的目录， 执行`svn cleanup`命令，如果失败，则进行以下操作 **

1. 内嵌数据库一般是用sqlite进行轻量级管理的。网上可以下到sqlite-shell-win32-x86: sqlite3.exe

2. 为了方便命令行执行，将sqlite3.exe放到svn 项目的主目录下，和.svn目录同级下。

3. 执行  `sqlite3 .svn/wc.db "select * from work_queue"` 看到有4条记录。就是刚才我执行的一些操作。

    ```
    226539|(sync-file-flags 93目录名 文件名)

    226540|(file-remove 21 .svn/tmp/svn-7B43C232)

    226541|(sync-file-flags 目录名 文件名)

    226542|(file-remove 21 .svn/tmp/svn-7B48224E)

    ```

4. 执行  `sqlite3 .svn/wc.db "delete from work_queue"` 把队列清空。

5. 执行 `sqlite3 .svn/wc.db "select * from work_queue"` 确认一下是否已经清空队列，发现已经没有记录显示，说明已经清空了。

6. 最后再试一下，看是否可以 执行 `svn cleanup` 来 clean up了。果然成功了。


**【方案三】**使用命令行工具svn.exe 执行cleanup svn项目目录。因为默认安装的时候，这个命令行工具是不被安装的，所以需要启动安装程序，选择”修改“，选上”命令行工具“才行。估计这个命令的实际效果和上面一种方法是类似的。不过应该比图形界面的右键菜单的更强大些吧。有兴趣可以试试。  

