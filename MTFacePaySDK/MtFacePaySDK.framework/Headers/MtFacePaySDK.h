//
//  MtWalletSDK.h
//  MtWalletSDK
//
//  Created by BiuKia on 2020/2/14.
//  Copyright © 2020 mt. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for MtWalletSDK.
FOUNDATION_EXPORT double MtWalletSDKVersionNumber;

//! Project version string for MtWalletSDK.
FOUNDATION_EXPORT const unsigned char MtWalletSDKVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <MtWalletSDK/PublicHeader.h>


@interface MtFacePayManager : NSObject

/**
 设置接口请求环境
 
 @param environment ‘1’：【QA】 ；‘2’：【内测】  ‘3’：【生产】  默认：生产
 */
+(void)setSdkRunEnvironment:(NSInteger)environment;


+(MtFacePayManager *)sharedManager;

/**
 初始化刷脸配置（在调起刷脸支付API之前调用）
 
 @param licenseID 调起刷脸的授权ID
 @param licensePath 调起刷脸的授权文件所在路径
 */
-(void)initialFacePay:(NSString *)licenseID licensePath:(NSString *)licensePath;

/**
 设置定制化相关信息（在调起刷脸支付API之前调用）
 
 @param customJson 可根据APP的主题色，定制SDK控件的颜色
 */
-(void)setCustom:(NSDictionary *)customJson;


/**
 调起刷脸支付
 
 @param orderInfo 支付参数
 @param parentMerchantNo 父商编
 @param securityCode 安全码
 @param controller 所在页面的controller
 @param success 成功
 @param failure 失败
 */
-(void)startFacePayWith:(NSDictionary *)orderInfo
       parentMerchantNo:(NSString *)parentMerchantNo
           securityCode:(NSString *)securityCode
             controller:(UIViewController *)controller
                success:(void(^)(NSDictionary * responseObject))success
                failure:(void (^)(NSError *error))failure;


/**
 调起活体检测
 
 @param controller 所在页面的controller
 @param success 成功
 @param failure 失败
 */
-(void)startLiveFaceWith:(UIViewController *)controller
                 success:(void(^)(NSArray * responseObject))success
                 failure:(void (^)(NSString *errorCode, NSString *errorMsg))failure;


/**
 调起人脸采集检测
 
 @param controller 所在页面的controller
 @param success 成功
 @param failure 失败
 */
-(void)startDetectFaceWith:(UIViewController *)controller
                   success:(void(^)(NSArray * responseObject))success
                   failure:(void (^)(NSString *errorCode, NSString *errorMsg))failure;


+(void)setLogPrintEnable:(BOOL)enable;


/**
 SDK版本号
 */
-(NSString *)sdkVersion;


@end
