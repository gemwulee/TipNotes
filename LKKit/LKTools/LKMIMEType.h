//
//  LKMIMEType.h
//  公告传输列表-demo
//
//  Created by jiangshuwei on 16/7/20.
//  Copyright © 2016年 jiangshuwei. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LKMIMEType : NSObject

/**
 *  向该文件发送请求,根据请求头拿到该文件的MIMEType
 *
 *  @param urlString 文件的请求路径
 *
 *  @return 文件的MIME类型
 */
+ (NSString *)typeForFileWithUrlString:(NSString *)urlString;


/**
 *  调用C语言的API来获得文件的MIMEType
 *  只能获取本地文件，无法获取网络请求来的文件
 *
 *  @param path 文件本地路径
 *
 *  @return 文件的MIME类型
 */
+ (NSString *)typeForFileAtLocalPath:(NSString *)path;


/**
 *  根据图片的data数据获取该图片的MIMEType
 *
 *  @param data 图片的data数据
 *
 *  @return 图片的MIME类型
 */
+ (NSString *)typeForImageWithData:(NSData *)data;

@end
