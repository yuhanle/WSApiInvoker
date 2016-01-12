//
//  WSApi.h
//  WS
//
//  Created by yuhanle on 15/5/8.
//  Copyright (c) 2015年 yuhanle. All rights reserved.
//
#import <UIKit/UIKit.h>
#import "ApiInvoker.h"
#import "ApiRequest.h"
#import "WSMacros.h"

@interface WSApi : ApiInvoker

/**
 *  默认post请求 带token 非https请求
 *
 *  @param api        接口地址
 *  @param apiRequest 请求实例
 *  @param callback   接口回调
 */
- (void)postApi:(NSString *)api andRequest:(ApiRequest *)apiRequest callback:(API_CALLBACK)callback;
/**
 *  是否带token请求接口
 *
 *  @param api        接口地址
 *  @param apiRequest 请求实例
 *  @param hasToken   是否带token
 *  @param callback   接口回调
 */
- (void)postApi:(NSString *)api andRequest:(ApiRequest *)apiRequest token:(BOOL)hasToken callback:(API_CALLBACK)callback;
/**
 *  是否带token的https请求
 *
 *  @param api        接口地址
 *  @param apiRequest 请求实例
 *  @param hasToken   是否带token
 *  @param hasHttps   是否是https
 *  @param callback   接口回调
 */
- (void)postApi:(NSString *)api andRequest:(ApiRequest *)apiRequest token:(BOOL)hasToken https:(BOOL)isHttps callback:(API_CALLBACK)callback;

@end
