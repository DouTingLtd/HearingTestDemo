//
//  RootTableViewController.m
//  HearingTestDemo
//
//  Created by wenxin on 2017/7/24.
//  Copyright © 2017年 douting. All rights reserved.
//

#import "RootTableViewController.h"
#import "BuyViewController.h"


#import <TLBHearingTestSDK/TLBHearingTestViewController.h>
#import <TLBHearingTestSDK/TLBTestHistoryViewController.h>
#import <TLBHearingTestSDK/TLBHearingTest.h>
#import <TLBHearingTestSDK/TLBSelectTypeViewController.h>



@interface RootTableViewController ()
@property(nonatomic,strong)TLBHearingTestViewController* testVC ;
@property(nonatomic,strong)TLBSelectTypeViewController* selectTypevc;
@end

@implementation RootTableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
    
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    if(indexPath.row == 0)
    {

        self.selectTypevc = [[TLBSelectTypeViewController alloc] init];
        self.selectTypevc.delegate = self;
        [self.selectTypevc showSelectTypeViewControllerByNavigation:self.navigationController
                                                       leftBarTitle:nil
                                                      leftBarAction:nil
                                                      rightBarTitle:nil
                                                     rightBarAction:nil];
       
    }
    else if(indexPath.row ==1)
    {
  
    }
    
    else if(indexPath.row == 2)
    {
//        [TLBHearingTest getListenTestWithCompletion:^(NSError *error,NSArray* tests) {
//            
//            if(error == nil)
//                NSLog(@"%@", [tests description]);
//            
//        }];
        
        TLBTestHistoryViewController* vc = [[TLBTestHistoryViewController alloc] init];
        [self.navigationController pushViewController:vc animated:YES];
        
    }

}

-(void) tlbSdkCharge:(double) price  /*建议金额*/
{
    NSLog(@"选择了普通耳机，收费%f",price);
    
    //。。。。支付流程后回调
    
    UIStoryboard *storyBoard=[UIStoryboard storyboardWithName:@"Main" bundle:nil];
    //
    BuyViewController *vc=[storyBoard instantiateViewControllerWithIdentifier:@"BuyViewController"];
    
    
    vc.buyCompleteBlock = ^{
        [self dismissViewControllerAnimated:YES completion:^{
            
        }];
        [self.selectTypevc tlbSdkPurchase:price];
    };
    [self presentViewController:vc animated:YES completion:^{
        
    }];
    

}
//点击购买检测仪
-(void) buyButtonClick:(UIButton*) buyButton /*点击购买检测仪button*/
{
    NSLog(@"点击了购买链接");
    
    //例如
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:@"https://item.taobao.com/item.htm?spm=a1z10.1-c.w5003-17642606087.1.300f5fbeSk316G&id=563601486085&scene=taobao_shop"]];
}
-(void) gotoTest
{

    if([[self.navigationController topViewController] isMemberOfClass:[self.testVC class]])
    {
        return;
    }
    [self.navigationController pushViewController:self.testVC animated:YES];
}

@end
