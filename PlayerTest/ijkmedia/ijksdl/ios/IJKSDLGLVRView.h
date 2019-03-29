//
//  IJKSDLGLVRView.h
//  PlayerTest
//
//  Created by 玉洋 on 2019/3/27.
//  Copyright © 2019 玉洋. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IJKSDLGLViewProtocol.h"
#include "ijksdl/ijksdl_vout.h"

NS_ASSUME_NONNULL_BEGIN

@interface IJKSDLGLVRView : UIView <IJKSDLGLViewProtocol>

- (id) initWithFrame:(CGRect)frame;
- (void) display: (SDL_VoutOverlay *) overlay;

- (UIImage*) snapshot;
- (void)setShouldLockWhileBeingMovedToWindow:(BOOL)shouldLockWhiteBeingMovedToWindow __attribute__((deprecated("unused")));

@end

NS_ASSUME_NONNULL_END
