//
//  FPConfig.h
//  FPPicker
//
//  Created by Liyan David Chang on 6/20/12.
//  Copyright (c) 2012 Filepicker.io (Cloudtop Inc), All rights reserved.
//

//To turn off logging for prod versions
#ifdef DEBUG
#   define NSForceLog(...) NSLog(__VA_ARGS__);
#   define NSLog(...) NSLog(__VA_ARGS__);
#else 
#   define NSForceLog(FORMAT, ...) fprintf(stderr,"[Ink Mobile Framework] %s\n", [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#   define NSLog(...)
#endif


/// Stick this in code you want to assert if run on the main UI thread.
#define DONT_BLOCK_UI() \
NSAssert(![NSThread isMainThread], @"Don't block the UI thread please!")

/// Stick this in code you want to assert if run on a background thread.
#define BLOCK_UI() \
NSAssert([NSThread isMainThread], @"You aren't running in the UI thread!")

#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

#ifdef DEBUG
#define fpBASE_URL                  @"https://dialog.filepicker.io"
#else
//Make sure release builds are always on prod.
#define fpBASE_URL                  @"https://dialog.filepicker.io"
#endif  


#define fpDEVICE_NAME               [[UIDevice currentDevice] name]
#define fpDEVICE_OS                 [[UIDevice currentDevice] systemName]
#define fpDEVICE_VERSION            [[UIDevice currentDevice] systemVersion]

#define fpDEVICE_TYPE               UI_USER_INTERFACE_IDIOM()
#define fpDEVICE_TYPE_IPAD          UIUserInterfaceIdiomPad
#define fpDEVICE_TYPE_IPHONE        UIUserInterfaceIdiomPhone

#define fpCOOKIES                   [[NSHTTPCookieStorage sharedHTTPCookieStorage] cookiesForURL:[NSURL URLWithString:fpBASE_URL]]
#define fpBASE_NSURL                [NSURL URLWithString:fpBASE_URL]

#define fpAPIKEY                    [[NSPropertyListSerialization propertyListFromData:[NSData dataWithContentsOfFile:[[NSBundle mainBundle] pathForResource:@"Info" ofType:@"plist"]] mutabilityOption:0 format:NULL errorDescription:NULL] objectForKey:@"Filepicker API Key"]

#define fpWindowSize                CGSizeMake(320, 480)


#define fpCellIdentifier            @"Filepicker_Cell"


#define fpLocalThumbSize            75
#define fpRemoteThumbSize           100


#define fpMaxChunkSize              262144 //.25mb
#define fpNumRetries                10

