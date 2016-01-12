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
 *  @param request  <#request description#>
 *  @param callback <#callback description#>
 */
- (void)request:(NSURLRequest *)request callback:(API_CALLBACK)callback;
/**
 *  按需求要保存已发出的请求 方便做错误处理以及重发
 *
 *  @param request    <#request description#>
 *  @param apiRequest <#apiRequest description#>
 *  @param callback   <#callback description#>
 */
- (void)request:(NSURLRequest *)request apiRequest:(ApiRequest *)apiRequest callback:(API_CALLBACK)callback;

+ (id)apiInvokerWithBaseUrl:(NSString *)baseUrl;
+ (id)apiHttpsInvokerWithBaseUrl:(NSString *)baseUrl;

- (void)addRequest:(ApiRequest *)apiRequest;

- (void)removeAllRequest;
- (void)removeRequest:(ApiRequest *)apiRequest normal:(BOOL)normal;

- (void)cancellAllRequest;
- (void)cancellAllRequestExcept:(ApiRequest *)apiRequest;

@property (strong, nonatomic) NSMutableArray *apiRequestArray;
@property (nonatomic, weak) id<AFWSApiInvokerDelegate> delegate;
@end

@protocol AFWSApiInvokerDelegate<NSObject>
@optional
- (void)handleError:(NSInteger)statusCode response:(ApiResponse *)apiResponse;
- (void)handleError:(NSInteger)statusCode apiRequest:(ApiRequest *)apiRequest response:(ApiResponse *)apiResponse;

@end