//
//  WSDevApi.h
//  WS
//
//  Created by yuhanle on 15/5/8.
//  Copyright (c) 2015年 yuhanle. All rights reserved.
//

#import "WSApi.h"

@interface WSDevApi : WSApi

+(instancetype) sharedInstance;

/**
 *  获取当前用户的设备列表
 *
 *  @param callback  接口回调
 */
-(void)loadCurrentUserDevlistWithCallback:(API_CALLBACK)callback;

/**
 *  获取某一组电动车的信息
 *
 *  @param  devid       电动车id数组
 *  @param  callback    接口回调
 */
-(void)loadCurrentUserDevlistWithDevid:(NSArray *)devid callback:(API_CALLBACK)callback;

/**
 *  获取电动车当前位置
 *
 *  @param  devid    设备号
 *  @param  callback 接口回调
 */
-(void)getDevCurrentPositionWithDevid:(NSString *)devid callback:(API_CALLBACK)callback;

/**
 *  获取电动车特定日期的行驶情况概要
 *
 *  @param  devid    设备号
 *  @param  day      某一天
 *  @param  callback 接口回调
 */
-(void)getDevDriveSummaryWithDevid:(NSString *)devid
                                day:(NSString *)day
                           callback:(API_CALLBACK)callback;
/**
 *  获取电动车按日汇总概要
 *
 *  @param  devid    设备号
 *  @param  callback 接口回调
 */
-(void)loadDevDayDriveSummaryWithDevid:(NSString *)devid callback:(API_CALLBACK)callback;

/**
 *  获取电动车历史轨迹
 *
 *  @param  devid     设备号
 *  @param  begintime 开始时间
 *  @param  endtime   结束时间
 *  @param  callback  接口回调
 */
-(void)loadDevHistoryTrackWithDevid:(NSString *)devid
                         begintime:(NSString *)begintime
                           endtime:(NSString *)endtime
                          callback:(API_CALLBACK)callback;

/**
 *  获取电动车电量
 *
 *  @param  devid       设备号
 *  @param  callback    接口回调
 */
-(void)getDevCurrentPowerWithDevid:(NSString *)devid callback:(API_CALLBACK)callback;

/**
 *  绑定电动车
 *  
 *  @param  qr       定位器二维码
 *  @param  callback 接口回调
 */
-(void)bindNewDevWithQRCode:(NSString *)qr callback:(API_CALLBACK)callback WSDeprecated("建议使用bindNewDevWithQRCode:alertor:callback:");

/**
 *  绑定电动车 new接口 区分前装 后装
 *
 *  @param  qr       定位器二维码
 *  @param  alertor  报警器类型  0 未定义   -1 无报警器     1 有报警器
 *  @param  callback 接口回调
 */
-(void)bindNewDevWithQRCode:(NSString *)qr alertor:(NSInteger)alertor callback:(API_CALLBACK)callback;

/**
 *  检查电动车绑定
 *
 *  @param  devid    设备号
 *  @param  callback 接口回调
 */
-(void)checkBindWithDevid:(NSString *)devid callback:(API_CALLBACK)callback;

/**
 *  重新绑定
 *  
 *  @param  devid     设备号
 *  @param  callback  接口回调
 */
-(void)rebindDevWithDevid:(NSString *)devid callback:(API_CALLBACK)callback;
 
/**
 *  获取和电动车有关系的用户列表
 *
 *  @param  devid    设备号
 *  @param  callback 接口回调
 */
-(void)loadRelativeUserinfoWithDevid:(NSString *)devid callback:(API_CALLBACK)callback;

/**
 *  修改电动车名称
 *
 *  @param  devid       设备号
 *  @param  name        新名称
 *  @param  callback    接口回调
 */
-(void)modifyDevNameWithDevid:(NSString *)devid
                         name:(NSString *)name
                     callback:(API_CALLBACK)callback;

/**
 *  解除用户（非机主）对电动车的查看权限
 *
 *  @param  devid       设备号
 *  @param  userid      用户id
 *  @param  callback    接口回调
 */
-(void)removeDevUserWithDevid:(NSString *)devid
                       userid:(NSString *)userid
                     callback:(API_CALLBACK)callback;

/**
 *  解除对电动车的绑定
 *
 *  @param  devid       设备号
 *  @param  vcode       验证码
 *  @param  callback    接口回调
 */
-(void)removeDevUserSelfWithDevid:(NSString *)devid
                            vcode:(NSString *)vcode
                         callback:(API_CALLBACK)callback;

/**
 *  设置电动车安防选项
 *
 *  @param  data        数据
 *  "data": {                           // 数据
         "secset": [{                   // 安防设置
         "devid" : "1",                 // 电动车编号
         "vibrate":"1",                 // 震动
         "elecfence" :"1",              // 电子围栏
         "battrm" :"1",                 // 电瓶移除
         "lowpower":"1"                 // 低电量
         "lockswitch":"1"               // 开关锁
         "regularrep": "1"              // 定时报告
     }]
 }
 *  @param  callback    接口回调
 */
-(void)setSecuritySetingWithData:(NSDictionary *)data callback:(API_CALLBACK)callback;

/**
 *  获取电动车的各类日志消息
 *
 *  @param  devid     设备号
 *  @param  begintime 开始时间
 *  @param  endtime   结束时间
 *  @param  callback  接口回调
 */
-(void)loadListDevMsgWithDevid:(NSString *)devid
                     begintime:(NSString *)begintime
                       endtime:(NSString *)endtime
                      callback:(API_CALLBACK)callback;

/**
 *  电动车授权
 *
 *  @param  devid       设备号
 *  @param  userid      用户id
 *  @param  grant       授权类型
 *  @param  privs       权限
 *  @param  callback    接口回调
 */
-(void)grantDevPrivsWithDevid:(NSString *)devid
                       userid:(NSInteger)userid
                        grant:(NSString *)grant
                        privs:(NSString *)privs
                     callback:(API_CALLBACK)callback;

/**
 *  电动车加锁解锁
 *
 *  @param  devid       设备号
 *  @param  lock        加解锁指令
 *  @param  callback    接口回调
 */
-(void)controllerLockWithDevid:(NSString *)devid
                          lock:(NSInteger)lock
                      callback:(API_CALLBACK)callback;

/**
 *  电动车加锁解锁状态
 *
 *  @param  devid       设备号
 *  @param  callback    接口回调
 */
-(void)getDevStatusWithDevid:(NSString *)devid callback:(API_CALLBACK)callback;

/**
 *  电动车安全评分
 *
 *  @param  token           口令
 *  @param  devid           设备号
 *  @param  securitysetting 当前安防等级
 *  @param  callback        接口回调
 */
-(void)evaluatingDevSafetyScoreWithDevid:(NSString *)devid
                         securitysetting:(NSInteger)securitysetting
                                callback:(API_CALLBACK)callback;

/**
 *  安防设置
 *
 *  @param  token       口令
 *  @param  devid       设备号
 *  @param  mode        模式
 *  @param  detail      具体内容    字典形式
 *  "detail" : {
                 "vibrate1": 1 ,    //轻微震动
                 "vibrate2": 0 ,    //中度震动
                 "vibrate3": 0 ,    //严重震动
                 "lowpower": 0 ,     //低电量
                 "battrm" : 0 ,    //电瓶移除
                 "battin" : 0 ,    //电瓶接入
                 "abnormalmove": 1, //非法移动
                }
 *  @param  bluetooth   蓝牙感应
 *  @param  callback    接口回调
 */
-(void)setDevSecuritySettingsWithDevid:(NSString *)devid
                                  mode:(NSInteger)mode
                                detail:(NSDictionary *)detail
                             bluetooth:(NSInteger)bluetooth
                              callback:(API_CALLBACK)callback;

/**
 *  用户点击忽略或找车
 *  
 *  @param  token       口令
 *  @param  devid       设备id
 *  @param  type        动作  igonre 忽略   find 找车
 *  @param  callback    接口回调
 */
-(void)ignoreOrFindDevWhenWarnComeWithDevid:(NSString *)devid
                                       type:(NSString *)type
                                   callback:(API_CALLBACK)callback;

/**
 *  根据二维码检查设备类型
 *
 *  @param qr       设备二维码
 *  @param callback 接口回调
 */
-(void)checkDevtypeWithQr:(NSString *)qr callback:(API_CALLBACK)callback;

/**
 *  设置报警器选项
 *
 *  @param devid    设备id
 *  @param alertor  报警器类型 0 无   1 有
 *  @param callback 接口回调
 */
-(void)setAlertSwitchWithDevid:(NSString *)devid alertor:(NSInteger)alertor callback:(API_CALLBACK)callback;

/**
 *  给报警器发送指令
 *
 *  @param devid         设备id
 *  @param command       指令类型   1 设防    2 撤防    3 开关电门  4 鸣笛
 *  @param commandParams 指令参数值  
 *  {"type" : 0} 
 *  设防：1 正常设防  2 静音设防
 *  撤防：暂不使用
 *  开关电门：1 开电门  2 关电门
 *  鸣笛：未定义
 *  @param callback      接口回调
 */
- (void)sendOperateAlertorWithDevid:(NSString *)devid command:(NSInteger)command commandParams:(NSDictionary *)commandParams callback:(API_CALLBACK)callback;

/**
 *  设置相同报警（推送到app）忽略的时间
 *
 *  @param devid      电动车编号
 *  @param ignoretime 忽略时间（分钟） 0 无
 *  @param callback   接口回调
 */
- (void)setSamePushIgnoreWithDevid:(NSString *)devid ignoretime:(NSInteger)ignoretime callback:(API_CALLBACK)callback;

/**
 *  忽略相同的报警
 *
 *  @param devid    电动车编号
 *  @param pushtype 推送类型，使用推送代码。不同的震动级别定义为不同类型，用推送代码+震动级别表示，即0110/0120/0130
 *  @param callback 接口回调
 */
- (void)ignoreSamePushWithDevid:(NSString *)devid pushtype:(NSString *)pushtype callback:(API_CALLBACK)callback;

@end
