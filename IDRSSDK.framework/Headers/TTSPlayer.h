//
//  TTSPlayer.h
//  IDRSSDK
//
//  Created by cuixling on 2020/5/15.
//  Copyright © 2020年 cuixling. All rights reserved.
//

#ifndef TTSPlayer_h
#define TTSPlayer_h


#endif /* TTSPlayer_h */

#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>

#ifdef DEBUG_MODE
#define TLog( s, ... ) NSLog( s, ##__VA_ARGS__ )
#else
#define TLog( s, ... )
#endif

#define EVERY_READ_LENGTH 200
#define NUM_BUFFERS 3
#define QUEUE_BUFFER_SIZE 640
/**
 *@discuss TTSPlayer 各种回调接口
 */
@protocol TTSPlayerDelegate <NSObject>

@end

// TTS语音合成事件
enum TTSPlayerEvent {
    TTSPlayer_EVENT_PLAY = 0,
    TTSPlayer_EVENT_STOP = 1,
    TTSPlayer_EVENT_PAUSE = 2,
    TTSPlayer_EVENT_RESUME = 3,
    TTSPlayer_EVENT_DRAINING = 4,
    TTSPlayer_EVENT_CLEAN = 5,
    TTSPlayer_EVENT_ERROR = 6
};
typedef void(^TTSPlayerEventCallBackBlock) (enum TTSPlayerEvent event); // 播放事件结果

@interface TTSPlayer : NSObject {

    //音频参数
    AudioStreamBasicDescription audioDescription;
    // 音频播放队列
    AudioQueueRef audioQueue;
    // 音频缓存
    AudioQueueBufferRef audioQueueBuffers[QUEUE_BUFFER_SIZE];
}
@property (nonatomic, copy)TTSPlayerEventCallBackBlock onTTSPlayerEventCallback; // 播放事件回调

@property(nonatomic,assign) id<TTSPlayerDelegate> delegate;

-(void)play;
-(void)pause;
-(void)resume;
-(void)stop;
-(void)drain;
-(void)cleanup;
-(int)write:(const char*)buffer Length:(int)len;
-(int)GetAudioData:(AudioQueueBufferRef)buffer;
@end

