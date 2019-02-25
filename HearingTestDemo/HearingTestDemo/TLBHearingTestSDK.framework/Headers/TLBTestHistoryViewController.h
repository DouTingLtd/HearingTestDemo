//
//  TLBTestHistoryViewController.h
//  TLBHearingTestSDK
//
//  Created by wenxin on 2017/7/21.
//  Copyright © 2017年 wenxinguo. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TLBTestHistoryViewController : UITableViewController

//选择使用，将ViewController通过设置的navi导航器push进入，同时支持自定义左右按钮
-(void)showTestHistoryViewControllerByNavigation:(UINavigationController*) navi
                                    leftBarTitle:(NSString*)leftBarTitle
                                   leftBarAction:(void (^)())leftBarAction
                                   rightBarTitle:(NSString*)rightBarTitle
                                  rightBarAction:(void (^)())rightBarAction;

@end
