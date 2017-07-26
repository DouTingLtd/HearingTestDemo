//
//  RootTableViewController.m
//  HearingTestDemo
//
//  Created by wenxin on 2017/7/24.
//  Copyright © 2017年 douting. All rights reserved.
//

#import "RootTableViewController.h"
#import <TLBHearingTestSDK/TLBHearingTestViewController.h>

#import <TLBHearingTestSDK/TLBTestHistoryViewController.h>
#import <TLBHearingTestSDK/TLBHearingTest.h>

@interface RootTableViewController ()
@property(nonatomic,strong)TLBHearingTestViewController* testVC ;
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
        
        self.testVC = [[TLBHearingTestViewController alloc] initWithT100MAC:@"16:07:07:00:DF:F5" completionHandler:^(NSError *error) {
            NSLog(@"%@",error);
            if(error == nil)
            {
                NSLog(@"设置耳机返回OK");
                [self performSelectorOnMainThread:@selector(gotoTest) withObject:nil waitUntilDone:NO];
                
            }
            else
                NSLog(@"设置耳机返回错误");
        }];
        
       
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


-(void) gotoTest
{

    [self.navigationController pushViewController:self.testVC animated:YES];
}

@end
