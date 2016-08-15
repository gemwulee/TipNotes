# Git


## Git SSH Key 配置

一、设置Git的user name 和 email:

```
$ git config --global user.name "gemwulee"
$ git config --global user.email "gemwulee@163.com"

```

二、设置Git的user name和email：

1.查看是否已经有了ssh密钥： 

```
cd ~/.ssh

```
如果没有密钥则不会有此文件夹，有则备份删除

2.生成密钥：

```
$ ssh-keygen -t rsa  -C "gemwulee@163.com"

```
回车，提示输入生成的rsa文件存储路径，可直接回车默认路径（如果自选路径，要输入rea文件名一级）

```
Generating public/private rsa key pair.
Enter file in which to save the key (/Users/apple/.ssh/id_rsa):
		
```

回车，提示输入密码，确认密码（两次回车则默认密码为空）

```
Enter passphrase (empty for no passphrase): 
Enter same passphrase again: 


```

出现如下信息，则说明密钥生成成功

```
The key fingerprint is:
SHA256:NU1Zk/Y+LIayAAlkrqQBv0xgN0YQE4vazPkxEnpYkrs gemwulee@163.com
The key's randomart image is:
+---[RSA 2048]----+
|o**B        .oo. |
|++B..      o. o. |
|=o=.. .   o .. . |
|+&.+ o   . .    .|
|*.X o . S   . .. |
| o o o . . . o o.|
|E   .   . o . . .|
|         .       |
|                 |
+----[SHA256]-----+


```
3.添加密钥到ssh：

```
ssh-add 文件名

```

需要之前输入密码。

4.在github上添加ssh密钥，这要添加的是“id_rsa.pub”里面的公钥。

5.验证关联github是否成功：

```
he authenticity of host 'github.com (192.30.253.112)' can't be established.
RSA key fingerprint is SHA256:nThbg6kXUpJWGl7E1IGOCspRomTxdCARLviKw6E5SY8.
Are you sure you want to continue connecting (yes/no)? yes
Warning: Permanently added 'github.com,192.30.253.112' (RSA) to the list of known hosts.
PTY allocation request failed on channel 0
Hi gemwulee! You've successfully authenticated, but GitHub does not provide shell access.
Connection to github.com closed.


```

三、开始使用github

1.获取源码

```
$ git clone https://github.com/gemwulee/TipNotes.git


```















