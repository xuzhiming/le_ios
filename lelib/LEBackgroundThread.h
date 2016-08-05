//
//  LEBackgroundThread.h
//  lelib
//
//  Created by Petr on 01.12.13.
//  Copyright (c) 2013,2014 Logentries. All rights reserved.
//

#import <Foundation/Foundation.h>


@protocol LEObjectEncodeDelegate;

/*
 This is a background thread which reads log files and sends it 
 to the server. You should not use this class directly.
 */
@interface LEBackgroundThread : NSThread

/*
 Initialization lock used to wait for background thread.
 */
@property (atomic, strong) NSCondition* initialized;

/*
 This method is invoked by le_poke() when new data are available.
 */
- (void)poke:(NSNumber*)lastLogFileNumber;


@property (nonatomic, strong) NSData* tokenPackage;

@property (nonatomic, weak)id<LEObjectEncodeDelegate> encodeDelegate;

@end


@protocol LEObjectEncodeDelegate <NSObject>

-(NSData *)encodeRawData:(NSData *)raw;

@end