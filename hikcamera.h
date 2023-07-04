#ifndef HIKCAMERA_H
#define HIKCAMERA_H

#include <QString>
//#include <opencv2/opencv.hpp>
#include "HCNetSDK.h"
//#include "plaympeg4.h"

class HIKCamera
{
public:
    bool isInit = false; // 设备是否初始化，正常工作
    bool isConn = false; // 相机连接标记
    bool isRunning = false;  // 正在运行
    int cameraCnt = -1;  // 系统相机数
    int cameraIndex = -1; // 相机索引

public:
    HIKCamera();
    ~HIKCamera();

    LONG lUserID = -1; //注册设备ID
    LONG lRealPlayHandle = -1; //实时预览控制端口
    NET_DVR_USER_LOGIN_INFO struLoginInfo = {0}; //相机登录参数设定
    NET_DVR_DEVICEINFO_V40 struDeviceInfoV40 = {0}; //登录的相机信息
    NET_DVR_PREVIEWINFO struPlayInfo; //实时显示参数设定
    char *pPicBuf;

    LONG lUserID2 = -1; //注册设备ID
    LONG lRealPlayHandle2 = -1; //实时预览控制端口
    NET_DVR_USER_LOGIN_INFO struLoginInfo2 = {0}; //相机登录参数设定
    NET_DVR_DEVICEINFO_V40 struDeviceInfoV402 = {0}; //登录的相机信息
    NET_DVR_PREVIEWINFO struPlayInfo2; //实时显示参数设定
    char *pPicBuf2;

public:
    static HIKCamera* getInstance(); // 获取实例
    int initialize(); // 初始化实例
    int uninitialize(); //
    bool isInitialized(); // 是否已初始化
    int connect(); // 连接相机
    int disconnect(); // 断开相机
    bool isConnected(); // 是否已连接相机
    int startStreaming(HWND hPlayWnd); // 开始拉流
    int startStreaming2(HWND hPlayWnd); // 开始拉流
    int stopStreaming(); // 结束拉流
//    int startGrabbing(cv::Mat& srcImg); // 开始抓图
    int stopGrabbing(); // 结束抓图
    int getImage(); // 结束拉流
};

#endif // HIKCAMERA_H
