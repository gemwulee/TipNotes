//
//  NSString+Category.m
//  MiBaby2015
//
//  Created by jiangshuwei on 16/8/18.
//  Copyright © 2016年 GodzillaYu. All rights reserved.
//

#import "NSString+Category.h"

@implementation NSString (Category)

//判断字符串为空或全部为空格  yes 全部为空格  no 不是
- (BOOL)isNilOrEmpty {
    
    if (!self) {
        return true;
    } else {
        //A character set containing only the whitespace characters space (U+0020) and tab (U+0009) and the newline and nextline characters (U+000A–U+000D, U+0085).
        NSCharacterSet *set = [NSCharacterSet whitespaceAndNewlineCharacterSet];
        
        //Returns a new string made by removing from both ends of the receiver characters contained in a given character set.
        NSString *trimedString = [self stringByTrimmingCharactersInSet:set];
        
        if ([trimedString length] == 0) {
            return true;
        } else {
            return false;
        }
    }
}

@end
