//
//  MacroDefinition.h
//  MiBaby2015
//
//  Created by jiangshuwei on 16/7/12.
//  Copyright © 2016年 GodzillaYu. All rights reserved.
//

/**
 宏是在预编译时发生作用的
 */

#ifndef LKMacroDef_h
#define LKMacroDef_h

/**
 *   __FILE__ 宏在预编译时，会替换成当前的源文件名字
 
    __FUNCTION__ 替换成当前的函数的名称
 
    __LINE__ 替换成当前的行号
 
    __VA_ARGS__ 可变参数的宏，宏前面加上“ ## ”(##__VA_ARGS__)作用在于：当可变参数的个数为0 的时候，这里的“ ## ”起到把前面多余的参数去掉的作用。否则编译出错。
 
 *  重写Debug模式下，系统的NSLog(); 方法
 */
#if DEBUG
#define NSLog(FORMAT, ...) fprintf(stderr,"\nFunction:%s Line:%d Content:%s\n", __FUNCTION__, __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String])
#else
#define NSLog(FORMAT, ...) nil
#endif

#endif /* LKMacroDef_h */
