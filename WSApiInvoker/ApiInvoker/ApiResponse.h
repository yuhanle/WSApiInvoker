 //
//  ApiResponse.h
//  WS
//
//  Created by yuhanle on 15/5/8.
//  Copyright (c) 2015年 yuhanle. All rights reserved.
//
//ApiResponse 对请求响应数据的处理

#import <Foundation/Foundation.h>

enum {
    /**
     *  commom
     */
    SERV_RESP_INVALID_CAR_NUM    = 19,//!< 无效的车辆编号
    SERV_RESP_ERR0R_DEV_ACTIVE   = 20,//!< 定位器激活错误
    /**
     *  绑定接口返回
     */
    SERV_RESP_BIND_INVALID_QRCODE     = 16,//!< 无效的二维码
    SERV_RESP_BIND_BINDED_CAR         = 17,//!< 已绑定的车辆
    SERV_RESP_BIND_DEV_ACTIVEING      = 18,//!< 车辆正在申请绑定，请2分钟之后重试
    SERV_RESP_BIND_ERROR_DEV_BIND     = 33,//!< 绑定电动车错误
    SERV_RESP_BIND_REQUEST_SUBMMITED  = 34,//!< 请求已提交
    SERV_RESP_BIND_CAR_MAX_BIND       = 53,//!< 每个用户最多绑定5辆电动车
    SERV_RESP_BIND_USER_MAX_BIND      = 54,//!< 每辆电动车最多被5个用户绑定
    SERV_RESP_BIND_NO_BIND            = 70,//!< 禁止操作该设备
    SERV_RESP_BIND_NEED_ALARM_INFO    = 71,//!< 需要提供感应防盗器信息
    /**
     *  检查绑定接口返回
     */
    SERV_RESP_BIND_CAR_ACTIVEING      = 7,//!< 绑定中
    SERV_RESP_BIND_ERROR_FAILED       = 8,//!< 绑定失败
    SERV_RESP_BIND_CAR_BIND_VERIFYING = 48//!< 车辆绑定审核中
};

@interface ApiResponse : NSObject
//  成功失败标志
@property (nonatomic, assign) BOOL success;
//  处理代码
@property (nonatomic, assign) NSInteger errCode;
//  处理消息
@property (nonatomic, strong) NSString *errDesc;
//  业务数据
@property (nonatomic, strong) id data;
// 附加字段
@property (nonatomic, copy) NSString *custDesc;
/** 总数目 */
@property (nonatomic, assign) NSInteger total;
/** 本次数目 */
@property (nonatomic, assign) NSInteger subtotal;

//  从dict中初始化
-(id)initWithDictionary:(NSDictionary *)dictionary;

@end
