//
//  LKDeviceManager.h
//  公告传输列表-demo
//
//  Created by jiangshuwei on 16/7/21.
//  Copyright © 2016年 jiangshuwei. All rights reserved.
//

/** 设备管理类 */
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface LKDeviceInfo : NSObject
+ (instancetype)sharedDeviceInfo;

#pragma mark - ***** 电池相关 *****
#pragma mark - 手机电量
/**
 *  通过苹果官方文档里面UIDevice public API来获取当前手机电量;
 *  在iOS7 上 它是以0.05为单位的，但是在iOS9下测试，它是以0.01为单位的，虽然也是0.01为单位，但是测试多次也会出现偏差1%左右，不精确
 *
 *  @return 手机电量
 */
+ (float)batteryLevelFromDeviceAPI;

/**
 *  通过IOKit.framework内的信息，获取当前手机电量(不精确)
 *
 *  不支持模拟器：IOKit.framework中的方法不支持模拟器运行
 *
 *  需要导入IOKit.framework包以及 IOPowerSources.h 和 IOPSKeys.h两个头文件
 *  /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk/System/Library/Frameworks/IOKit.framework
 *
 *  @return 手机电量
 */
+ (float)batteryLevelFromIOKit;


/**
 *  通过runtime 获取StatusBar上电池电量控件类私有变量的值，此方法可精准获取iOS6以上电池电量
 *
 *  如果在设置里面没有开启电量的百分比显示 获取到的是0
 *
 *  使用了私有的API，可能被拒
 *
 *  @return 通过runtime 获取StatusBar上电池电量控件类私有变量的值，此方法可精准获取iOS6以上电池电量
 */
+ (float)batteryLevelFromStatusBar;



#pragma mark - ***** 存储容量 *****
/**
 *  内存大小
 */

/**
 *  磁盘空间
 */

#pragma mark - ***** 手机屏幕 *****
/** 获取屏幕宽、高 */
#ifndef SCREEN_WIDTH
#define SCREEN_WIDTH ([UIScreen mainScreen].bounds.size.width)
#endif
#ifndef SCREEN_HEIGHT
#define SCREEN_HEIGHT ([UIScreen mainScreen].bounds.size.height)
#endif

/** 屏幕分辨率 */
#ifndef SCREEN_RESOLUTION
#define SCREEN_RESOLUTION (SCREEN_WIDTH * SCREEN_HEIGHT * ([UIScreen mainScreen].scale))
#endif

#pragma mark - ***** 手机型号 *****
/**
 *  设备型号
 *  模拟器，真机，iPhone6，iPhone6 Plus，iPhone6s...
 */

/** 模拟器 */
#if TARGET_IPHONE_SIMULATOR
#ifndef IS_SIMULATOR
#define IS_SIMULATOR
#endif
#endif

/** 真机 */
#if TARGET_OS_IPHONE
#ifndef IS_REAL_IPHONE
#define IS_REAL_IPHONE
#endif
#endif

#ifndef IS_IPAD
#define IS_IPAD     [[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad
#endif

#ifndef IS_IPHONE
#define IS_IPHONE   [[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone
#endif

#ifndef IS_IPHONE_4
#define IS_IPHONE_4 (fabs((double)[[UIScreen mainScreen] bounds].size.height - (double)480) < DBL_EPSILON )
#endif

#ifndef IS_IPHONE_5
#define IS_IPHONE_5 (fabs((double)[[UIScreen mainScreen] bounds].size.height - (double )568) < DBL_EPSILON )
#endif

#ifndef IS_IPHONE_6
#define IS_IPHONE_6 (fabs((double)[[UIScreen mainScreen] bounds].size.height - (double )667) < DBL_EPSILON )
#endif

#ifndef IS_IPHONE_6_PLUS
#define IS_IPHONE_6_PLUS (fabs((double)[[UIScreen mainScreen] bounds].size.height - (double )960) < DBL_EPSILON )
#endif



/**
 *  操作系统
 *  iOS7，iOS8，iOS9，iOS10...
 */
#define IS_IOS_VERSION   floorf([[UIDevice currentDevice].systemVersion floatValue]
#define IS_IOS_5    floorf([[UIDevice currentDevice].systemVersion floatValue]) == 5.0 ? 1 : 0
#define IS_IOS_6    floorf([[UIDevice currentDevice].systemVersion floatValue]) == 6.0 ? 1 : 0
#define IS_IOS_7    floorf([[UIDevice currentDevice].systemVersion floatValue]) == 7.0 ? 1 : 0
#define IS_IOS_8    floorf([[UIDevice currentDevice].systemVersion floatValue]) == 8.0 ? 1 : 0
#define IS_IOS_9    floorf([[UIDevice currentDevice].systemVersion floatValue]) == 9.0 ? 1 : 0

@end
