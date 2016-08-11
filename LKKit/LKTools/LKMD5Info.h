//
//  LKMD5Info.h
//  公告传输列表-demo
//
//  Created by jiangshuwei on 16/7/25.
//  Copyright © 2016年 jiangshuwei. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LKMD5Info : NSObject

/**
 *  获取文件的 MD5 值
 *
 *  @param path 文件路径
 *
 *  @return md5字符串
 */
- (NSString *)getFileMD5WithPath:(NSString*)path;

@end
