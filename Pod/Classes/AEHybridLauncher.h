//
//  AEHybridLauncher.h
//  Pods
//
//  Created by Altair on 02/08/2017.
//
//

#import <Foundation/Foundation.h>
#import "AEJavaScriptHandler.h"

#define AE_JSHANDLED_SELECTOR(AliasName) __attribute__((annotate("ae_jshandled_selector")))

typedef enum {
    AEMethodTypeClass,
    AEMethodTypeInstance,
    AEMethodTypeAll
}AEMethodType;

NS_ASSUME_NONNULL_BEGIN

@interface AEHybridLauncher : NSObject

/**
 根据方法的类型和执行者，获取对应的contexts
 注：该方法获取的是本地打过标记的方法，需要在待注册的方法后面打上AE_JSHANDLED_SELECTOR()标记，小括号内标明方法的别名（不包括@""）。每个类内部的别名不可重复，没有的话留空。

 @param type 方法类型
 @param performer 方法执行者，如果为nil，则获取所有已记录的类方法
 @return contexts
 */
+ (NSSet<AEJSHandlerContext *> *)jsContextsOfType:(AEMethodType)type forPerformer:(id __nullable)performer;

/**
 自动向指定的JSHandler注册本地方法。
 注：该方法自动注册的是本地打过标记的方法，需要在待注册的方法后面打上AE_JSHANDLED_SELECTOR()标记，小括号内标明方法的别名（不包括@""）。每个类内部的别名不可重复，没有的话留空。
 
 @param type 方法类型
 @param performer 方法执行者，如果为nil，则获取所有已记录的类方法
 @param handler 指定的JSHandler
 */
+ (void)automaticallyRegisterNativeMethodsOfType:(AEMethodType)type forPerformer:(id __nullable)performer toJavaScriptHandler:(AEJavaScriptHandler *)handler;

@end

NS_ASSUME_NONNULL_END
