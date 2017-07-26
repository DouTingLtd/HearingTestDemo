//
//  ChessboardView.h
//  tinglibao
//
//  Created by vivian on 14-10-23.
//  Copyright (c) 2014年 xixihaha home. All rights reserved.
//

#import <UIKit/UIKit.h>
@class ChessboardView;
@protocol ChessboardViewDelegate<NSObject>
@required
-(void)chessboardViewTouchedAtHz:(NSString*)hz db:(NSString*)db;
@end

@protocol ChessboardViewDataSource<NSObject>
@required
-(NSArray*)hzsOfChessboardView:(ChessboardView*)view;
@end

@interface ChessboardView : UIView
@property (weak, nonatomic) id<ChessboardViewDelegate>delegate;
@property (weak, nonatomic) id<ChessboardViewDataSource>datasource;
@property (assign, nonatomic) BOOL isTestLeft;


-(void) drawTestEnd;
-(void) drawTestAtHz:(NSString*)hz db:(NSString*)db;
-(void) drawSelectAtHz:(NSString*)hz db:(NSString*)db;

@end



