//
//  WS
//
//  Created by yuhanle on 15/5/8.
//  Copyright (c) 2015年 yuhanle. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "AFWSApiInvoker.h"
#import "ApiResponse.h"
#import "ApiRequest.h"

@interface ApiInvoker : NSObject

@property (nonatomic, copy) NSString *token;    //!< token
@property (nonatomic, copy) NSString *apiBaseUrl;   //!< 接口地址
@property (nonatomic, copy) NSString *apiHttpsBaseUrl;  //!< https接口地址
@property (nonatomic, assign) NSUInteger timeoutInSeconds; //!< 请求超时秒数，默认为30s

/**
 *  快速发送post请求
 *
 *  @param api        请求接口
 *  @param apiRequest 请求实例
 *  @param callback   接口回调
 */
- (void)postApi:(NSString *)api andRequest:(ApiRequest *)apiRequest callback:(API_CALLBACK)callback;

/**
 *  创建一个新的请求
 *
 *  @param api        请求接口
 *  @param httpMethod 请求类型 如'post' 'get' 'delete' 'put' 已忽略大小写
 *  @param apiRequest 请求实例
 *  @param callback   接口回调
 */
- (void)requestApi:(NSString *)api withMethod:(NSString *)httpMethod andRequest:(ApiRequest *)apiRequest callback:(API_CALLBACK)callback;

/**
 *  错误统一处理
 *
 *  @param statusCode  状态码 若网络原因则是状态码 若请求成功则是服务端返回的code
 *  @param apiResponse 请求回应 若网络原因则是nil 若请求成功则是服务端的回应
 */
- (void)handleError:(NSInteger)statusCode response:(ApiResponse *)apiResponse;
/**
 *  错误统一处理
 *
 *  @param statusCode  状态码 若网络原因则是状态码 若请求成功则是服务端返回的code
 *  @param apiRequest  请求实例 错误处理中可以根据请求做特殊处理 如自动登录 刷新token等
 *  @param apiResponse 请求回应 若网络原因则是nil 若请求成功则是服务端的回应
 */
- (void)handleError:(NSInteger)statusCode apiRequest:(ApiRequest *)apiRequest response:(ApiResponse *)apiResponse;

/**
 *  新增一个请求
 *
 *  @param apiRequest 请求实例
 */
- (void)addRequest:(ApiRequest *)apiRequest;

/**
 *  移除所有请求
 */
- (void)removeAllRequest;
/**
 *  移除特殊请求
 *
 *  @param apiRequest 请求实例
 */
- (void)removeRequest:(ApiRequest *)apiRequest;

/**
 *  取消所有请求
 */
- (void)cancellAllRequest;
/**
 *  取消特殊请求
 *
 *  @param apiRequest 请求实例
 */
- (void)cancellAllRequestExcept:(ApiRequest *)apiRequest;

/**
 *  重新发送特殊请求
 *
 *  @param apiRequest 请求实例
 */
- (void)reRequest:(ApiRequest *)apiRequest;
/**
 *  重新发送所有请求
 */
- (void)reRequestAllRequest;

@end