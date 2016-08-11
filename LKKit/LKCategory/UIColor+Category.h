//
//  UIColor+Category.h
//  公告传输列表-demo
//
//  Created by jiangshuwei on 16/7/21.
//  Copyright © 2016年 jiangshuwei. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (Category)

/**
 *  使用十六进制字符串设置颜色
 *
 *  @param hexString 颜色的十六进制字符码，支持@“#123456”、 @“0X123456”、 @“123456”三种格式
 *  @param alpha     透明度
 *
 *  @return 颜色值
 */
+ (UIColor *)colorWithHexString:(NSString *)hexString alpha:(CGFloat)alpha;
+ (UIColor *)colorWithHexString:(NSString *)hexString;


@end

#pragma mark - ***** RGBA宏 *****
#define UIColorFromRGBA(r, g, b, a) [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:a]
#define UIColorFromRGB(r, g, b) UIColorFromRGBA(r, g, b, 1.0f)
#define UIColorFromHexA(hex, a) [UIColor colorWithHexString:hex alpha:a]
#define UIColorFromHex(hex) UIColorFromHexA(hex, 1.0f)

