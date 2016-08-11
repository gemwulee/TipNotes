//
//  LKMIMEType.m
//  公告传输列表-demo
//
//  Created by jiangshuwei on 16/7/20.
//  Copyright © 2016年 jiangshuwei. All rights reserved.
//

#import "LKMIMEType.h"
#import <MobileCoreServices/MobileCoreServices.h>

@implementation LKMIMEType

//向该文件发送请求,根据请求头拿到该文件的MIMEType
+ (NSString *)typeForFileWithUrlString:(NSString *)urlString
{
    //1.确定请求路径
    NSURL *url = [NSURL fileURLWithPath:urlString];
    
    //2.创建可变的请求对象
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    
    //3.发送请求
    NSHTTPURLResponse *response = nil;
    [NSURLConnection sendSynchronousRequest:request returningResponse:&response error:nil];
    
    return response.MIMEType;
}

//调用C语言的API来获得文件的MIMEType ，只能获取本地文件哦，无法获取网络请求来的文件
+ (NSString *)typeForFileAtLocalPath:(NSString *)path
{
    if (![[[NSFileManager alloc] init] fileExistsAtPath:path]) {
        return nil;
    }
    
    CFStringRef UTI = UTTypeCreatePreferredIdentifierForTag(kUTTagClassFilenameExtension, (__bridge CFStringRef)[path pathExtension], NULL);
    CFStringRef MIMEType = UTTypeCopyPreferredTagWithClass (UTI, kUTTagClassMIMEType);
    CFRelease(UTI);
    if (!MIMEType) {
        return @"application/octet-stream";
    }
    return (__bridge NSString *)(MIMEType);
}

#pragma mark - 图片类型
+ (NSString *)typeForImageWithData:(NSData *)data
{
    uint8_t c;
    [data getBytes:&c length:1];
    switch (c) {
        case 0xFF:
            return @"image/jpeg";
        case 0x89:
            return @"image/png";
        case 0x47:
            return @"image/gif";
        case 0x49:
        case 0x4D:
            return @"image/tiff";
    }
    return nil;
}

@end
