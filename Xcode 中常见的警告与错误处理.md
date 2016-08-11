#### **警告提示：This application is modifying the autolayout engine from a background thread, which can lead to engine corruption and weird crashes.  This will cause an exception in a future release.**

** 错误原因：在回调函数中或者后台线程中更新了UI界面，而UI界面必须是在主界面中才能进行修改 **

** 解决办法： **
[stackoverflow解答](http://stackoverflow.com/questions/31951704/this-application-is-modifying-the-autolayout-engine-from-a-background-thread-wh)

* GCD

```
dispatch_async(dispatch_get_main_queue(), ^{

　　// Do UI stuff here
　　　
});
```

* Notifaction

```
[[NSNotificationCenter defaultCenter] addObserverForName:@"notification" object:nil queue:[NSOperationQueue mainQueue] usingBlock:^(NSNotification * _Nonnull note) {
	// Do UI stuff here
}];
```

* PerformSelector

```
[self performSelectorOnMainThread:@selector(mainThreadImpl:) withObject:nil waitUntilDone:YES];
```

===


#### ****
