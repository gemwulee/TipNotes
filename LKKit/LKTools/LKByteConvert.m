//
//  LKByteConversion.m
//  公告传输列表-demo
//
//  Created by jiangshuwei on 16/7/20.
//  Copyright © 2016年 jiangshuwei. All rights reserved.
//

#import "LKByteConvert.h"
#import <UIKit/UIKit.h>

#include "sys/stat.h"  //获取文件大小.h

@implementation LKByteOperation

#pragma mark - 字节转换
//const int KB = 1024;//定义KB的计算常量
const int KB = 1000;//定义KB的计算常量
const int MB = KB * KB;//定义MB的计算常量
const int GB = KB * KB * KB;//定义GB的计算常量
+ (NSString *)bytesConvertGBMBKB:(int64_t)size {
    NSString *unit = @"B";
    CGFloat unitLegth = size;
    
    if (size / GB >= 1){//如果当前Byte的值大于等于1GB
        unit = @"GB";
        unitLegth = 1.0f*size / GB;
    } else if (size / MB >= 1){//如果当前Byte的值大于等于1MB
        if(size / MB >= 1000){
            unit = @"GB";
            unitLegth = 1.0f*size / GB;
        }else{
            unit = @"MB";
            unitLegth = 1.0f*size / MB;
        }
    } else if (size / KB >= 1){//如果当前Byte的值大于等于1KB
        if(size / KB >= 1000){
            unit = @"MB";
            unitLegth = 1.0f*size / MB;
        }else{
            unit = @"KB";
            unitLegth = 1.0f*size / KB;
        }
    } else{
        if(size >= 1000){
            unit = @"KB";
            unitLegth = 1.0f*size / KB;
        }
    }
    return [NSString stringWithFormat:@"%.2f%@",unitLegth,unit];
}

#pragma mark - 文件大小
// C语言实现
+ (int64_t)fileSizeAtPath:(NSString*)filePath{
    struct stat st;
    if(lstat([filePath cStringUsingEncoding:NSUTF8StringEncoding], &st) == 0){
        return st.st_size;
    }
    return 0;
}
/*/
// Object-C实现
+ (int64_t)fileSizeAtPath:(NSString *)path {
    NSFileManager *fileManager = [NSFileManager defaultManager];
    if ([fileManager fileExistsAtPath:path]) {
        return [[fileManager attributesOfItemAtPath:path error:nil] fileSize];
    }
    return 0;
}
//*/

@end
