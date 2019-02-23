//
//  TLBSelectTypeViewController.h
//  TLBHearingTestSDK
//
//  Created by wenxin on 2019/2/21.
//  Copyright © 2019年 wenxinguo. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol TLBEarphoneTestChargeDelegate <NSObject>

//需要收费
-(void) tlbSdkCharge:(double) price  /*建议金额*/;
//点击购买检测仪
-(void) buyButtonClick:(UIButton*) buyButton /*点击购买检测仪button*/;

@end

@interface TLBSelectTypeViewController : UITableViewController

@property(weak,nonatomic)id<TLBEarphoneTestChargeDelegate> delegate;

-(void)showSelectTypeViewControllerByNavigation:(UINavigationController*) navi
                                   leftBarTitle:(NSString*)leftBarTitle
                                  leftBarAction:(void (^)())leftBarAction
                                  rightBarTitle:(NSString*)rightBarTitle
                                 rightBarAction:(void (^)())rightBarAction;
//收费完成后掉入
-(void)tlbSdkPurchase:(double) money /*付费金额*/;

@end
