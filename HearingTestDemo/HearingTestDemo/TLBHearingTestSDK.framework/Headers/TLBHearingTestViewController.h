//
//  TLBHearingTestViewController.h
//  TLBHearingTestSDK
//
//  Created by wenxin on 2017/7/21.
//  Copyright © 2017年 wenxinguo. All rights reserved.
//

#import <UIKit/UIKit.h>
//右耳优先，自动测试
@interface TLBHearingTestViewController : UIViewController

//插入的耳机类型
-(instancetype)initWithT100MAC:(NSString*) mac completionHandler:(void (^)( NSError * __nullable error))completionHandler;

@end
