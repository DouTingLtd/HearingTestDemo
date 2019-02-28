//
//  TLBTestResultViewController.h
//  TLBHearingTestSDK
//
//  Created by wenxin on 2017/7/21.
//  Copyright © 2017年 wenxinguo. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TLBTestResultViewController : UIViewController
@property(nonatomic,strong)NSDictionary* left;
@property(nonatomic,strong)NSDictionary* right;

//选择使用，将ViewController通过设置的navi导航器push进入，同时支持自定义左右按钮
-(void)showTestResultViewControllerByNavigation:(UINavigationController*) navi
                                   leftBarTitle:(NSString*)leftBarTitle
                                  leftBarAction:(void (^)())leftBarAction
                                  rightBarTitle:(NSString*)rightBarTitle
                                 rightBarAction:(void (^)())rightBarAction;
@end
