//
//  ViewController.m
//  HearingTestDemp
//
//  Created by wenxin on 16/9/14.
//  Copyright © 2016年 wenxinguo. All rights reserved.
//

#import "ViewController.h"
#import <TLBHearingTestSDK/TLBHearingTest.h>
@interface ViewController ()<TLBHearingTestDelegate>
@property(strong)TLBHearingTest* test;
@property (weak, nonatomic) IBOutlet UISegmentedControl *erjiType;

@property (weak, nonatomic) IBOutlet UISegmentedControl *testType;
@property (weak, nonatomic) IBOutlet UILabel *status;
@property (weak, nonatomic) IBOutlet UIButton *heardButton;
@property (weak, nonatomic) IBOutlet UIButton *startLeft;
@property (weak, nonatomic) IBOutlet UIButton *startRight;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    
    
    self.test = [[TLBHearingTest alloc] initWithTestType:self.testType.selectedSegmentIndex ];
    self.test.delegate = self;
    
    __weak ViewController* vc = self;
    [self.test setT100MAC:@"16:07:07:00:DF:F5" completionHandler:^(NSError *error) {
        NSLog(@"%@",error);
        if(error == nil)
            [vc.status setText:@"设置耳机返回OK"];
        else
            [vc.status setText:@"设置耳机返回错误"];
    }];
}
-(void)dealloc
{
    [self.test pauseTest];
    self.test = nil;
}
- (IBAction)stoptest:(id)sender {
    
    [self.test pauseTest];
}
- (IBAction)heard:(id)sender {
    [self.test listened];
}
- (IBAction)reset:(id)sender {
    
    self.test = nil;
    [self.startLeft setEnabled:YES];
    [self.startRight setEnabled:YES];
}

-(IBAction)startTestLeft:(UIButton*)btn
{
    [self.test startTest:YES];
    [btn setEnabled:NO];
}

-(IBAction)startTestRight:(UIButton*)btn
{
    [self.test startTest:NO];
    [btn setEnabled:NO];
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void) hearingTest:(TLBHearingTest *)test completeWithLeftResult:(NSDictionary *)result right:(NSDictionary *)right
{
    [self.status setText:@"测试完成"];
    
    NSInteger left = [TLBHearingTest computeEarTestResult:result];
    NSInteger rig = [TLBHearingTest computeEarTestResult:right];
    
    [self.status setText:[NSString stringWithFormat:@"left:%@,right:%@",@(left),@(rig)]];
    NSLog(@"left:%@,right:%@",@(left),@(rig));
    
}

-(void) hearingTest:(TLBHearingTest *)test oneEarCompleteWithResult:(NSDictionary *)result isLeft:(BOOL)isLeft
{
    if(isLeft)
        [self.status setText:@"左耳测试完成"];
    else
        [self.status setText:@"右耳测试完成"];
    
}

-(void) hearingTest:(TLBHearingTest*)test willTestAtHz:(NSString*) hz db:(NSString*)db volume:(float)volume isLeft: (BOOL)isLeft
{
    [self.status setText:[NSString stringWithFormat: @"will测试%@,%@,vol=%f",hz,db,volume]];
}
-(void) hearingTest:(TLBHearingTest*)test willSelectedAtHz:(NSString*) hz db:(NSString*)db isLeft: (BOOL)isLeft;
{
    [self.status setText:[NSString stringWithFormat: @"测试ok%@,%@",hz,db]];
}


@end
