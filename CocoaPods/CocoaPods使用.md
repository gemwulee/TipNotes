
===

# 安装步骤

## 查看Ruby版本
```
& ruby -v

```

## 更换ruby镜像

### 1.移除现有Ruby 默认源
```
$ gem sources --remove https://rubygems.org/ 

```

### 2.使用新的taobao源
```
$ gem sources -a https://ruby.taobao.org/ 

```

### 3.验证新源是否替换成功
```
$ gem sources -l 

```



## 安装CocoaPods
```
$ sudo gem install cocoapods
$ sudo gem install -n /usr/local/bin cocoapods
$ pod setup

```

## 查看CocoaPods是否安装成功
```
$ pod --version

```

# 更新gem
```
$ sudo gem update --system 

```



===
# CocoaPods使用
## 1.建立Podfile文件
```
& vim Podfile

```
1.1 输入 i 进入编辑模式 ，输入 e.g.:

```
target 'MyApp' do

pod 'AFNetworking', '~> 2.6'

pod 'ORStackView', '~> 3.0'

end

```
* MyApp 为自己工程的名字



===

# 错误处理

### 1. pod setup 失败　

```

$ pod setup
Setting up CocoaPods master repo
[!] /usr/bin/git clone https://github.com/CocoaPods/Specs.git master

Cloning into 'master'...
error: RPC failed; curl 56 SSLRead() return error -36
fatal: The remote end hung up unexpectedly
fatal: early EOF
fatal: index-pack failed

```

没有做处理，重新执行 `pod setup` 成功

```
Setting up CocoaPods master repo

CocoaPods 1.1.0.beta.1 is available.
To update use: `sudo gem install cocoapods --pre`
[!] This is a test version we'd love you to try.

For more information, see https://blog.cocoapods.org and the CHANGELOG for this version at https://github.com/CocoaPods/CocoaPods/releases/tag/1.1.0.beta.1

Setup completed

```


===











