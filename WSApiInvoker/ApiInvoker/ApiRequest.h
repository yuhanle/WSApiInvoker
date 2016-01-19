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

@property (nonatomic, copy) NSString *api; //!< 请求揭露
//数据签名，防篡改
@property (nonatomic, copy) NSString *token; // !< 请求token
@property (nonatomic, assign) BOOL hasToken; //!< 是否带token
@property (nonatomic, assign) BOOL isHttps; //!< 是否https请求
@property (nonatomic, assign) NSInteger retryCount; //!< 重传次数
@property (nonatomic, copy) API_CALLBACK callback; //!< 接口回调
//业务请求参数
@property (nonatomic, strong) NSDictionary * bizDataDict; //!< 业务数据
@property (nonatomic, strong) AFHTTPRequestOperation * operation; //!< 请求队列

/**
 *  快速创建实例方法
 *
 *  @param dictionary 业务数据
 *
 *  @return 请求实例
 */
+(id)requestWithBizData:(NSDictionary *)dictionary;

@end
