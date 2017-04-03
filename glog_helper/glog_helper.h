/*************************************************************
 * Copyright (C) 2017 your company All Rights Reserved
 *
 * Distributed under terms of the LGPL3 license.
 *************************************************************/

/**
 * @file glog_helper.h
 * @author wang
 * @date 2017-04-02 15:10
 * @brief
 *
 **/

#ifndef GLOG_HELPER_H
#define GLOG_HELPER_H

#include <stdlib.h>
#include <glog/logging.h>
#include <glog/raw_logging.h>

//配置输出日志的目录：
#define LOGDIR "log"
#define MKDIR "mkdir -p "LOGDIR

namespace glog_helper {
    //将信息输出到单独的文件和 LOG(ERROR)
    //void SignalHandle(const char* data, int size);

    class GLogHelper {
        public:
            //GLOG配置：
            GLogHelper(const char* program);

            //GLOG内存清理：
            ~GLogHelper();
    };

    //将信息输出到单独的文件和 LOG(ERROR)
    void SignalHandle(const char* data, int size) {
        std::string str = std::string(data,size);
        //std::ofstream fs("glog_dump.log",std::ios::app);
        //fs<<str;
        //fs.close();

        LOG(ERROR)<<str;
    }


    //GLOG配置：
    GLogHelper::GLogHelper(const char* program)
    {
        system(MKDIR);
        google::InitGoogleLogging(program);

        //设置级别高于 google::INFO 的日志同时输出到屏幕
        google::SetStderrLogging(google::INFO);

        //设置输出到屏幕的日志显示相应颜色
        FLAGS_colorlogtostderr=true;

        //设置 google::ERROR 级别的日志存储路径和文件名前缀
        //google::SetLogDestination(google::ERROR,"log/error_");

        //设置 google::INFO 级别的日志存储路径和文件名前缀
        google::SetLogDestination(google::INFO,LOGDIR"/INFO_");

        //设置 google::WARNING 级别的日志存储路径和文件名前缀
        google::SetLogDestination(google::WARNING,LOGDIR"/WARNING_");

        //设置 google::ERROR 级别的日志存储路径和文件名前缀
        google::SetLogDestination(google::ERROR,LOGDIR"/ERROR_");

        //缓冲日志输出，默认为30秒，此处改为立即输出
        FLAGS_logbufsecs = 0;

        //最大日志大小为 100MB
        FLAGS_max_log_size =100;

        //当磁盘被写满时，停止日志输出
        FLAGS_stop_logging_if_full_disk = true;

        //设置文件名扩展，如平台？或其它需要区分的信息
        google::SetLogFilenameExtension("91_");

        //捕捉 core dumped
        google::InstallFailureSignalHandler();

        //默认捕捉 SIGSEGV 信号信息输出会输出到 stderr，可以通过下面的方法自定义输出>方式：
        google::InstallFailureWriter(&SignalHandle);
    }


    //GLOG内存清理：
    GLogHelper::~GLogHelper()
    {
        google::ShutdownGoogleLogging();
    }

}
#endif /* !GLOG_HELPER_H */

/*set sw=4 ts=4 sts=4 et tw=78 */




