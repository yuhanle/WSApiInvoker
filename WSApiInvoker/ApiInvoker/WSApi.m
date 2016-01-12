//
//  WSApi.m
//  WS
//
//  Created by yuhanle on 15/5/8.
//  Copyright (c) 2015年 yuhanle. All rights reserved.
//

#import "WSApi.h"

@implementation WSApi
- (id)init {
	//重写init方法 设置不同的请求
    self = [super init];
    if (self) {
        //ENT API Base
        self.apiBaseUrl = @"mainHost";
        self.apiHttpsBaseUrl = @"mainHttpsHost";
        self.timeoutInSeconds = 30;//30秒超时

        self.token = @"你的token";
        if(!self.token) self.token = @"";
    }
    
    return self;
}

- (void)postApi:(NSString *)api andRequest:(ApiRequest *)apiRequest callback:(API_CALLBACK)callback{
    [self postApi:api andRequest:apiRequest token:YES https:NO callback:callback];
}

- (void)postApi:(NSString *)api andRequest:(ApiRequest *)apiRequest token:(BOOL)hasToken callback:(API_CALLBACK)callback {
    [self postApi:api andRequest:apiRequest token:hasToken https:NO callback:callback];
}

- (void)postApi:(NSString *)api andRequest:(ApiRequest *)apiRequest token:(BOOL)hasToken https:(BOOL)isHttps callback:(API_CALLBACK)callback {
    apiRequest.api = api;
    apiRequest.isHttps = isHttps;
    apiRequest.hasToken = hasToken;
    apiRequest.callback = callback;
    
#warning 这里可由全局控制是否允许网络请求，比如异地登陆，为了防止出错，设置后，后续请求都不会发送出去，而回添加到一个数组
    BOOL allowNetRequest = YES;
    if (!allowNetRequest) {
        [self addRequest:apiRequest];
    }else {
        [self requestApi:api withMethod:@"POST" andRequest:apiRequest callback:callback];
    }
}

- (void)handleError:(NSInteger)statusCode response:(ApiResponse *)apiResponse {
    NSString * statuts = nil;
    if (statusCode == 0) {
       statuts = @"未能连接到服务器";
    }else if (statusCode == 200) {
        // 请求成功
    } else if (statusCode == 404) {
       statuts = @"请求错误";
    } else if (statusCode >= 500) {
        statuts = @"服务器异常";
    }else if (statusCode == -1001) {
        statuts = @"网络连接超时，请重试";
    }else if (statusCode == -1004) {
        statuts = @"未能连接到服务器";
    }
}

-(void)handleError:(NSInteger)statusCode apiRequest:(ApiRequest *)apiRequest response:(ApiResponse *)apiResponse {
    NSString * statuts = nil;
    if (statusCode == 0) {
        statuts = @"未能连接到服务器";
    }else if (statusCode == 200) {
        // 请求成功
    } else if (statusCode == 404) {
        statuts = @"请求错误";
    } else if (statusCode >= 500) {
        statuts = @"服务器异常";
    }else if (statusCode == -1001) {
        statuts = @"网络连接超时，请重试";
    }else if (statusCode == -1004) {
        statuts = @"未能连接到服务器";
    }else if (statusCode == -1005) {
        statuts = @"网络连接已中断";
    }
    
    // 以下是服务器返回的特殊错误 需要另作处理
    if (apiResponse.errCode == 6 || apiResponse.errCode == 64) {
        [self cancellAllRequest];
    }
}

-(void)reRequestAllRequestFromFather {
    [self reRequestAllRequest];
}

-(void)removeAllRequestFromFather {
    [self removeAllRequest];
}

@end
