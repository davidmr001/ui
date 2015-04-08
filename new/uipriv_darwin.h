// 6 january 2015
#define MAC_OS_X_VERSION_MIN_REQUIRED MAC_OS_X_VERSION_10_7
#define MAC_OS_X_VERSION_MAX_ALLOWED MAC_OS_X_VERSION_10_7
#import <Cocoa/Cocoa.h>
#import "uipriv.h"
#import "ui_darwin.h"

#define toNSString(str) [NSString stringWithUTF8String:(str)]

// TODO move this to the right place
struct uiSizing {
};

#ifdef uiLogAllocations
#import <stdio.h>
#define uiLogObjCClassAllocations \
- (id)init \
{ \
	self = [super init]; \
	fprintf(stderr, "%p alloc %s\n", self, [[self className] UTF8String]); \
	return self; \
} \
- (void)dealloc \
{ \
	[super dealloc]; \
	fprintf(stderr, "%p free\n", self); \
}
#else
#define uiLogObjCClassAllocations
#endif

// util_darwin.m
extern void setStandardControlFont(NSControl *);

// container_darwin.m
@interface uiContainer : NSView
@property uiControl *child;
@end
