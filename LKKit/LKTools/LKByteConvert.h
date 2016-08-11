//
//  LKByteConversion.h
//  公告传输列表-demo
//
//  Created by jiangshuwei on 16/7/20.
//  Copyright © 2016年 jiangshuwei. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LKByteOperation : NSObject

/**
 *  字节转换
 *  
 *  将传入的字节数'B'换算为对应的'GB'/'MB'/'KB'/'B'字节数
 *
 *  @param length 字节长度'B'
 *
 *  @return 'B'/'KB'/'MB'/'GB' String
 */
+ (NSString *)bytesConvertGBMBKB:(int64_t)size;


/**
 *  获取文件大小
 *
 *  @param path 文件路径
 *
 *  @return 文件大小(int64_t)
 */
+ (int64_t)fileSizeAtPath:(NSString *)path;


@end
