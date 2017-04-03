/*************************************************************
 * Copyright (C) 2017 your company All Rights Reserved
 *
 * Distributed under terms of the LGPL3 license.
 *************************************************************/

/**
 * @file main.cpp
 * @author wang
 * @date 2017-04-02 15:31
 * @brief
 *
 **/

#include "../glog_helper/glog_helper.h"

int main(int argc,char* argv[])
{
    //要使用 GLOG ，只需要在 main 函数开始处添加这句即可
    glog_helper::GLogHelper gh(argv[0]);

    LOG(INFO)<<"INFO";
    LOG(ERROR)<<"ERROR";

}



/*set sw=4 ts=4 sts=4 et tw=78 */
