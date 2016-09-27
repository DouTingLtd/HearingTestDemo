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
@property(nonatomic,weak)__nullable id<TLBHearingTestDelegate> delegate;
//=================================================
-(__nullable instancetype )initWithTestType:(TLBHearingTestType)type;
//=================================================
+(void) registerAppKey:(nonnull NSString*)key;//注册key,使用类之前设置
-(void) setEarPlugModel:(nonnull NSString*) model completionHandler: (nonnull void (^)( NSError * __nullable error))completionHandler;//设置插入的耳机类型,必须设置
-(void) setNosiseValue:(nonnull NSString*) dbValue;//设置当前的环境噪声大小,没有测试的话可设置为0
-(void)setLogEnable:(BOOL)isShowLog;
//=================================================
- (void)startTest:(BOOL) isleft;//单耳开始测试
- (void)pauseTest;//暂停当前测试
- (void)continueTest;//继续测试
- (BOOL)isTestLeft;////测试左耳或右耳
-(float)getTestProgress;//获取测试进度
- (void)listened;//听到了声音
-(nullable NSDictionary*)getTestResult:(BOOL)isleft;
//=================================================
-(void) playAtHz:(nonnull NSString*)hz db:(nonnull NSString*)db;//用户手动测试
//=================================================
+(NSInteger)computeEarTestResult:(nonnull NSDictionary*)dataDictory age:(NSInteger) age gender:(nonnull NSString*)gender;//依据测试结果计算听力损失db,gender，男性为@“1”，女性为@“0”
+(nullable NSString *)computeResultString:(NSInteger)result;//依据听力损失获取听力结果描述
//=================================================
@end

