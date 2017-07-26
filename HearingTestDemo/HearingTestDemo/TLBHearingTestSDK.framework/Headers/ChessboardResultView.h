//
//  ChessboardView.h
//  tinglibao
//
//  Created by vivian on 14-10-23.
//  Copyright (c) 2014年 xixihaha home. All rights reserved.
//

#import <UIKit/UIKit.h>
@class  ChessboardResultView;

@protocol ChessboardResultViewDataSouce <NSObject>

//xgwen
@required
-(CGPoint)chessboardResultView:(ChessboardResultView*)chess pointAtHz:(NSString*)hz  index:(int)index  isLeft:(BOOL) isleft insection:(int)section;
-(int)countOfSection:(ChessboardResultView*)chess;
-(NSArray*)hzsOfChessboardView:(ChessboardResultView*)view;

@end

@interface ChessboardResultView : UIView

@property(nonatomic,weak)id<ChessboardResultViewDataSouce>datasouce;

@end



