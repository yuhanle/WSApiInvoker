//
//  ApiRequest.m
//  WS
//
//  Created by yuhanle on 15/5/8.
//  Copyright (c) 2015年 yuhanle. All rights reserved.
//

#import "ApiRequest.h"
#import <UIKit/UIKit.h>

#define API_NULL_TOKEN  @""
@implementation ApiRequest{
	NSDictionary *_bizDataDict;
}

@synthesize token = _token;
@synthesize bizDataDict = _bizDataDict;

- (id)init {
	self = [super init];
	if (self) {
		self.token = @"你的token";
		if(!self.token) self.token = API_NULL_TOKEN;
	}

	return self;
}


- (id)initWithBizData:(NSDictionary *)dictionary {
	self = [self init];
	if(self){
		
		self.bizDataDict = dictionary;
		
	}
    return self;
}


+ (id)requestWithBizData:(NSDictionary *)dictionary
{
	return [[ApiRequest alloc] initWithBizData:dictionary];
}

- (NSString *)makeUUID {
	
	CFUUIDRef uuid = CFUUIDCreate(nil);

	CFStringRef	uuidString = CFUUIDCreateString(nil, uuid);

	NSString *uuidNSString = (__bridge NSString *)uuidString;
	CFRelease(uuid);

	NSString *retString = [NSString stringWithString:uuidNSString];
	CFRelease(uuidString);

	return retString;
}

@end