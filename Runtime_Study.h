//
//  Runtime_Study.h
//  MiBaby2015
//
//  Created by jiangshuwei on 16/8/1.
//  Copyright © 2016年 GodzillaYu. All rights reserved.
//

#ifndef Runtime_Study_h
#define Runtime_Study_h
/**
 *  IMP(Interface Message Processor) 接口信息处理器
 *  Implementation:实现、执行
 */

typedef struct objc_method *Method;

#pragma mark - Method
#pragma mark - method_
//获取方法名
SEL method_getName(Method m);
//获取方法的类型编码
const char *method_getTypeEncoding(Method m);
//
unsigned int method_getNumberOfArguments(Method m);
//copy方法返回类型
char *method_copyReturnType(Method m);
//copy方法的内容类型
char *method_copyArgumentType(Method m, unsigned int index);
//获取方法返回类型
void method_getReturnType(Method m, char *dst, size_t dst_len);
//获取方法的内容类型
void method_getArgumentType(Method m, unsigned int index, char *dst, size_t dst_len);
//获取方法的描述
struct objc_method_description *method_getDescription(Method m);


#pragma mark - 获取【IMP】
//
IMP class_getMethodImplementation(Class cls, SEL name);
IMP class_getMethodImplementation_stret(Class cls, SEL name);
//获取方法的执行
IMP method_getImplementation(Method m);
//设置方法的执行
IMP method_setImplementation(Method m, IMP imp);
//交换方法的执行
void method_exchangeImplementations(Method m1, Method m2);

#pragma mark - 获取/添加/替换 方法
//获取实例方法
Method class_getInstanceMethod(Class cls, SEL name);
//获取类方法
Method class_getClassMethod(Class cls, SEL name);
//获取方法列表
Method *class_copyMethodList(Class cls, unsigned int *outCount);
//添加方法
BOOL class_addMethod(Class cls, SEL name, IMP imp, const char *types);
//替换方法
IMP class_replaceMethod(Class cls, SEL name, IMP imp, const char *types);





#pragma mark - 协议 protocol
struct objc_method_description protocol_getMethodDescription(Protocol *p, SEL aSel, BOOL isRequiredMethod, BOOL isInstanceMethod);
struct objc_method_description *protocol_copyMethodDescriptionList(Protocol *p, BOOL isRequiredMethod, BOOL isInstanceMethod, unsigned int *outCount);
void protocol_addMethodDescription(Protocol *proto, SEL name, const char *types, BOOL isRequiredMethod, BOOL isInstanceMethod)

#pragma mark - SEL

#endif /* Runtime_Study_h */
