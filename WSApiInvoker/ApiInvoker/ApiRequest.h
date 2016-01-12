//
//  ApiRequest.h
//  WS
//
//  Created by yuhanle on 15/5/8.
//  Copyright (c) 2015年 yuhanle. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AFNetworking.h"
#import "ApiResponse.h"

//api 异步调用回调Block
typedef void (^API_CALLBACK)(NSInteger statusCode, ApiResponse *response, BOOL requestSuccess);

@interface ApiRequest : NSObject

@property (nonatomic, copy) NSString *api;
//数据签名，防篡改
@property (nonatomic, copy) NSString *token;
@property (nonatomic, assign) BOOL hasToken; //!< 是否带token
@property (nonatomic, assign) BOOL isHttps; //!< 是否https请求
@property (nonatomic, assign) NSInteger retryCount;
@property (nonatomic, copy) API_CALLBACK callback;
//业务请求参数
@property (nonatomic, strong) NSDictionary * bizDataDict;
@property (nonatomic, strong) AFHTTPRequestOperation * operation;

+(id)requestWithBizData:(NSDictionary *)dictionary;

@end
