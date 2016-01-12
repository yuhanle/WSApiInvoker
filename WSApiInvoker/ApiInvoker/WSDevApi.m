//
//  WSDevApi.m
//  WS
//
//  Created by yuhanle on 15/5/8.
//  Copyright (c) 2015年 yuhanle. All rights reserved.
//

#import "WSDevApi.h"

@implementation WSDevApi

+(instancetype)sharedInstance {
    static WSDevApi * instance;
    static dispatch_once_t oneToken;
    dispatch_once(&oneToken, ^{
        instance = [[self alloc]init];
    });
    return instance;
}

-(void)loadCurrentUserDevlistWithCallback:(API_CALLBACK)callback {
    ApiRequest * request = [ApiRequest requestWithBizData:nil];
    [self postApi:@"app/xxx" andRequest:request callback:callback];
}

-(void)loadCurrentUserDevlistWithDevid:(NSArray *)devid callback:(API_CALLBACK)callback {
    ApiRequest * request = [ApiRequest requestWithBizData:@{@"xxx" : EMPTY_IF_NIL(devid)}];
    [self postApi:@"app/xxx" andRequest:request callback:callback];
}

-(void)getDevCurrentPositionWithDevid:(NSString *)devid callback:(API_CALLBACK)callback {
    ApiRequest * request = [ApiRequest requestWithBizData:@{@"xxx" : EMPTY_IF_NIL(devid)}];
    [self postApi:@"app/xxx" andRequest:request callback:callback];
}

-(void)getDevDriveSummaryWithDevid:(NSString *)devid
                               day:(NSString *)day
                          callback:(API_CALLBACK)callback {
    ApiRequest * request = [ApiRequest requestWithBizData:@{
                                                            @"xxx" : EMPTY_IF_NIL(devid),
                                                            @"xxx" : EMPTY_IF_NIL(day)
                                                            }];
    [self postApi:@"app/xxx" andRequest:request callback:callback];
}

-(void)loadDevDayDriveSummaryWithDevid:(NSString *)devid callback:(API_CALLBACK)callback {
    ApiRequest * request = [ApiRequest requestWithBizData:@{@"xxx" : EMPTY_IF_NIL(devid)}];
    [self postApi:@"app/xxx" andRequest:request callback:callback];
}

-(void)loadDevHistoryTrackWithDevid:(NSString *)devid
                         begintime:(NSString *)begintime
                           endtime:(NSString *)endtime
                          callback:(API_CALLBACK)callback {
    ApiRequest * request = [ApiRequest requestWithBizData:@{
                                                            @"xxx" : EMPTY_IF_NIL(devid),
                                                            @"xxx" : EMPTY_IF_NIL(begintime),
                                                            @"xxx" : EMPTY_IF_NIL(endtime)
                                                            }];
    [self postApi:@"app/xxx" andRequest:request callback:callback];
}

-(void)getDevCurrentPowerWithDevid:(NSString *)devid callback:(API_CALLBACK)callback {
    ApiRequest * request = [ApiRequest requestWithBizData:@{@"xxx" : EMPTY_IF_NIL(devid)}];
    [self postApi:@"app/xxx" andRequest:request callback:callback];
}

@end
