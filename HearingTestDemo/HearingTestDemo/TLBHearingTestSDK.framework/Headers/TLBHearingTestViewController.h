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

//选择使用，将ViewController通过设置的navi导航器push进入，同时支持自定义左右按钮
-(void)showHearingTestViewControllerByNavigation:(UINavigationController*) navi
                                   leftBarTitle:(NSString*)leftBarTitle
                                  leftBarAction:(void (^)())leftBarAction
                                  rightBarTitle:(NSString*)rightBarTitle
                                 rightBarAction:(void (^)())rightBarAction;
//插入的耳机类型
-(instancetype)initT100TestByCompletionHandler:(void (^)( NSError * __nullable error))completionHandler;

-(instancetype)initEarphoneTestByCompletionHandler:(void (^)( NSError * __nullable error))completionHandler;
@end
