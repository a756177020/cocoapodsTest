//
//  Utils.h
//  IDRSSDK
//
//  Created by cuixling on 2020/4/16.
//  Copyright © 2020年 cuixling. All rights reserved.
//

#ifndef IDRSUtils_h
#define IDRSUtils_h
#ifdef DEBUG_MODE
#define TLog( s, ... ) NSLog( s, ##__VA_ARGS__ )
#else
#define TLog( s, ... )
#endif

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@interface IDRSUtils : NSObject

+ (CVPixelBufferRef)convertYUVToPixelBufferRef:(long) dataPtr
                                        dataYPtr:(long) dataYPtr
                                        dataUPtr:(long) dataUPtr
                                        dataVPtr:(long) dataVPtr
                                         strideY:(int) strideY
                                         strideU:(int) strideU
                                         strideV:(int) strideV
                                          height:(int) height
                                           width:(int) width
                                        rotation:(int) rotation
                                          stride:(int) stride
                                       timeStamp:(long long)timeStamp;

+ (uint8_t *)convertPixelBufferToRGB:(nonnull CVImageBufferRef)pixelBuffer;

+ (uint8_t *)convertYUVToRawData:(long) dataPtr
                        dataYPtr:(long) dataYPtr
                        dataUPtr:(long) dataUPtr
                        dataVPtr:(long) dataVPtr
                         strideY:(int) strideY
                         strideU:(int) strideU
                         strideV:(int) strideV
                          height:(int) height
                           width:(int) width
                        rotation:(int) rotation
                          stride:(int) stride
                       timeStamp:(long long)timeStamp;

+ (uint8_t *)convert420PixelBufferToRawData:(CVPixelBufferRef)pixelBuffer;

// 判断手的主体与目标人脸是否是同一个。返回结果为[0, 1]。 >0.3认为匹配上了。
+ (float)computeHandOwner:(CGRect) handFace
               targetFace:(CGRect) targetFace;
@end
#endif /* IDRSUtils */

