//
//  TLBHearingTest.h
//  tinglibao
//
//  Created by wenxin on 16/8/15.
//  Copyright © 2016年 xixihaha home. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum
{
    AutoTest,//自动测试
    ManualTest,//手动测试
    StandardTest//标准测试
    
}TLBHearingTestType;
#define EXEONMAINTHREAD(x) dispatch_async(dispatch_get_main_queue(), ^{\
x;\
})
@class TLBHearingTest;
//=================================================
@protocol TLBHearingTestDelegate <NSObject>

@required

@optional
//测试完成
-(void) hearingTest:(nonnull TLBHearingTest*)test completeWithLeftResult:(nonnull NSDictionary*) result right:(nonnull NSDictionary*)right;
//单耳完成
-(void) hearingTest:(nonnull TLBHearingTest*)test oneEarCompleteWithResult:(nonnull NSDictionary*) result isLeft: (BOOL)isLeft;
//将要测试某hz的某db
-(void) hearingTest:(nonnull TLBHearingTest*)test willTestAtHz:(nonnull NSString*) hz db:(nonnull NSString*)db volume:(float)volume isLeft: (BOOL)isLeft;
//将要选中某hz的某db为阀值点
-(void) hearingTest:(nonnull TLBHearingTest*)test willSelectedAtHz:(nonnull NSString*) hz db:(nonnull NSString*)db isLeft: (BOOL)isLeft;
@end

@interface TLBHearingTest : NSObject
@property(nonatomic,weak)id  <TLBHearingTestDelegate> delegate;
@property(nonatomic,strong)NSString* earPlugModel;//当前使用的耳机类型0-3
//=================================================
-(instancetype )initWithTestType:(TLBHearingTestType)type;

//=================================================
+(void) registerAppKey:(NSString*)key;//注册key,使用类之前设置
//设置用户信息
+(void) setAppUserID:(NSString*)userID username:(NSString*)username isWomen:(BOOL)isWomen birthday:(NSDate*)birthday phone:(NSString*)phone completionHandler:(void (^)(NSError* error))completionHandler;//注册用户信息,使用类之前设置
//+(void) setAppUserID:(NSString*)userID isWomen:(BOOL)isWomen birthday:(NSDate*)birthday phone:(NSString*)phone
//   completionHandler:(void (^)(NSError* error))completionHandler;
+(void)getListenTestWithCompletion:(void (^)(NSError *error,NSArray* tests))completion;
-(void) setEarPlugModel:(NSString*) model completionHandler:(void (^)( NSError * __nullable error))completionHandler;//设置插入的耳机类型,必须设置
-(void)setT100MAC:(NSString*) mac completionHandler:(void (^)( NSError * __nullable error))completionHandler;//设置插入的耳机类型,必须设置

+(void)getListenTestPriceWithCompletion:(void (^)(NSError *error,NSDictionary* headset,NSArray* prices))completion;
+(void)listenTestPurchaseWithCompletion:(void (^)(NSError * __nullable error))completion;
+(void)listenTestConsumptionWithCompletion:(void (^)(NSError * __nullable error))completion;
+(void)listenTestWithLeft:(NSDictionary*)left right:(NSDictionary*)right  earPlugModel:(NSString*)earPlugModel   completion:(void (^)(NSString* listenTestID,NSError *error))completion;

-(void) setNosiseValue:(NSString*) dbValue;//设置当前的环境噪声大小
-(void)setLogEnable:(BOOL)isShowLog;

-(void)setTestHzs:(NSArray*)hzs;
//=================================================
- (void)startTest:(BOOL) isleft;//单耳开始测试
- (void)pauseTest;//暂停当前测试
- (void)continueTest;//继续测试
- (BOOL)isTestLeft;////测试左耳或右耳
-(float)getTestProgress;//获取测试进度
- (void)listened;//听到了声音
-(NSDictionary*)getTestResult:(BOOL)isleft;
//=================================================
-(void) playAtHz:(NSString*)hz db:(NSString*)db;//用户手动测试
//=================================================
+(NSInteger)computeEarTestResult:(NSDictionary*)dataDictory;//依据测试结果计算听力损失db
+(NSString *)computeResultString:(NSInteger)result;//依据听力损失获取听力结果描述
//=================================================


+(NSString*)getT100Mac;//获取检测仪的mac地址
+ (BOOL)hasHeadset;
+(NSString *)platform;
@end

