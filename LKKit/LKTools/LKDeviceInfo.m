//
//  LKDeviceManager.m
//  公告传输列表-demo
//
//  Created by jiangshuwei on 16/7/21.
//  Copyright © 2016年 jiangshuwei. All rights reserved.
//

#import "LKDeviceInfo.h"
#include <objc/runtime.h>

#import "IOPSKeys.h"
#import "IOPowerSources.h"

@implementation LKDeviceInfo
+ (instancetype)sharedDeviceInfo {
    static LKDeviceInfo *deviceInfo = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        deviceInfo = [[self alloc] init];
    });
    return deviceInfo;
}

#pragma mark -
+ (float)batteryLevelFromDeviceAPI {
    UIDevice *device = [UIDevice currentDevice];
    return device.batteryLevel;
}


+ (float)batteryLevelFromIOKit {
    if (TARGET_IPHONE_SIMULATOR) {
        return -1.0f;
    }
    else {
        //Returns a blob of Power Source information in an opaque CFTypeRef.
        CFTypeRef blob = IOPSCopyPowerSourcesInfo();
        
        //Returns a CFArray of Power Source handles, each of type CFTypeRef.
        CFArrayRef sources = IOPSCopyPowerSourcesList(blob);
        
        CFDictionaryRef pSource = NULL;
        const void *psValue;
        
        //Returns the number of values currently in an array.
        int numOfSources = (int)CFArrayGetCount(sources);
        
        //Error in CFArrayGetCount
        if (numOfSources == 0) {
            NSLog(@"Error in CFArrayGetCount");
            return -1.0f;
        }
        
        //Calculating the remaining energy
        double percent = 0.0;
        for (int i = 0; i < numOfSources; i++)
        {
            //Returns a CFDictionary with readable information about the specific power source.
            pSource = IOPSGetPowerSourceDescription(blob, CFArrayGetValueAtIndex(sources, i));
            if (!pSource)
            {
                NSLog(@"Error in IOPSGetPowerSourceDescription");
                return -1.0f;
            }
            psValue = (CFStringRef)CFDictionaryGetValue(pSource, CFSTR(kIOPSNameKey));
            
            int curCapacity = 0;
            int maxCapacity = 0;
            psValue = CFDictionaryGetValue(pSource, CFSTR(kIOPSCurrentCapacityKey));
            CFNumberGetValue((CFNumberRef)psValue, kCFNumberSInt32Type, &curCapacity);
            
            psValue = CFDictionaryGetValue(pSource, CFSTR(kIOPSMaxCapacityKey));
            CFNumberGetValue((CFNumberRef)psValue, kCFNumberSInt32Type, &maxCapacity);
            
            percent = ((double)curCapacity/(double)maxCapacity * 100.0f);
        }
        return percent;
    }
}


#if __has_feature(objc_arc)
// ARC
+ (float)batteryLevelFromStatusBar {
    UIApplication *app = [UIApplication sharedApplication];
    if (app.applicationState == UIApplicationStateActive || app.applicationState==UIApplicationStateInactive) {
        Ivar ivar=  class_getInstanceVariable([app class],"_statusBar");
        id status  = object_getIvar(app, ivar);
        for (id aview in [status subviews]) {
            int batteryLevel = 0;
            for (id bview in [aview subviews]) {
                if ([NSStringFromClass([bview class]) caseInsensitiveCompare:@"UIStatusBarBatteryItemView"] == NSOrderedSame&&[[[UIDevice currentDevice] systemVersion] floatValue] >=6.0) {
                    
                    Ivar ivar=  class_getInstanceVariable([bview class],"_capacity");
                    if(ivar) {
                        batteryLevel = ((int (*)(id, Ivar))object_getIvar)(bview, ivar);
                        //这种方式也可以
                        /*ptrdiff_t offset = ivar_getOffset(ivar);
                         unsigned char *stuffBytes = (unsigned char *)(__bridge void *)bview;
                         batteryLevel = * ((int *)(stuffBytes + offset));*/
                        if (batteryLevel > 0 && batteryLevel <= 100)                            return batteryLevel;
                        else
                            return 0.0f;
                    }
                }
            }
        }
    }
    return 0.0f;
}
#else
// MRC
+ (float)batteryLevelFromStatusBar {
    UIApplication *app = [UIApplication sharedApplication];
    if (app.applicationState == UIApplicationStateActive || app == UIApplicationStateInactive) {
        void *result = nil;
        object_getInstanceVariable([UIApplication sharedApplication], "_statusBar", &result);
        id status  = result;
        for (id aview in [status subviews]) {
            for (id bview in [aview subviews]) {
                int batteryLevel = 0;
                if ([NSStringFromClass([bview class]) caseInsensitiveCompare:@"UIStatusBarBatteryItemView"] == NSOrderedSame&&[[[UIDevice currentDevice] systemVersion] floatValue] >= 6.0) {
                    object_getInstanceVariable(bview, "_capacity", &result);
                    batteryLevel = (int)result;
                    NSLog(@"电池电量:%d",batteryLevel);
                    if (batteryLevel > 0 && batteryLevel <= 100) {
                        return batteryLevel;
                        
                    } else {
                        return 0;
                    }
                }
            }
        }
        return 0;
    }
}
#endif

#pragma mark -


@end
