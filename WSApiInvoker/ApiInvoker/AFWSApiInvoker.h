//
//  WS
//
//  Created by yuhanle on 15/5/8.
//  Copyright (c) 2015年 yuhanle. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ApiResponse.h"
#import "ApiRequest.h"

//api 异步调用回调Block
typedef void (^API_CALLBACK)(NSInteger statusCode, ApiResponse *response, BOOL requestSuccess);

@protocol AFWSApiInvokerDelegate;
@interface AFWSApiInvoker : NSObject

/**
 *  最初始的请求
 *
 *  @param request  url请求
 *  @param callback 接口回调
 */
- (void)request:(NSURLRequest *)request callback:(API_CALLBACK)callback;
/**
 *  按需求要保存已发出的请求 方便做错误处理以及重发
 *
 *  @param request    url请求
 *  @param apiRequest 实例请求
 *  @param callback   接口回调
 */
- (void)request:(NSURLRequest *)request apiRequest:(ApiRequest *)apiRequest callback:(API_CALLBACK)callback;

/**
 *  构建普通http请求实例
 *
 *  @param baseUrl http请求baseUrl
 *
 *  @return http请求实例
 */
+ (id)apiInvokerWithBaseUrl:(NSString *)baseUrl;

/**
 *  构建安全https请求实例
 *
 *  @param baseUrl https请求baseUrl
 *
 *  @return https请求实例
 */
+ (id)apiHttpsInvokerWithBaseUrl:(NSString *)baseUrl;

/**
 *  新增请求实例
 *
 *  @param apiRequest 请求实例
 */
- (void)addRequest:(ApiRequest *)apiRequest;

/**
 *  移除队列中的所有请求
 */
- (void)removeAllRequest;
/**
 *  移除队列中的某个特殊请求
 *
 *  @param apiRequest 请求实例
 *  @param normal     标识是否正常移除 YES 用户手动移除 NO 其他原因自动移除
 */
- (void)removeRequest:(ApiRequest *)apiRequest normal:(BOOL)normal;

/**
 *  取消队列中的所有请求
 */
- (void)cancellAllRequest;
/**
 *  取消队列中的某个特殊请求
 *
 *  @param apiRequest 请求实例
 */
- (void)cancellAllRequestExcept:(ApiRequest *)apiRequest;

@property (strong, nonatomic) NSMutableArray *apiRequestArray; //!< 请求实例数组
@property (nonatomic, weak) id<AFWSApiInvokerDelegate> delegate; //!< 错误处理协议
@end

#pragma 统一处理协议
@protocol AFWSApiInvokerDelegate<NSObject>
@optional
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

@end