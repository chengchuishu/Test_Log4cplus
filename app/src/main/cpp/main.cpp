//
// Created by 17719242718 on 2020/12/25.
//

#include <cstdio>
#include <string>

#include "MyLogger.h"


int main(int argc, char* argv[])
{
    // 设置信号回调函数，运行程序后键入ctrl + C回调signal_callback_handler函数
    printf("==========start service [check] ============\n");

    std::string hello = "Hello from C++";

    MyLogger * myLoger = NULL;
    myLoger = MyLogger::getInstance();

    LOG4CPLUS_FATAL(myLoger->rootLog, "DeleteService failed,errCode=[0]");
    LOG4CPLUS_DEBUG(myLoger->rootLog, " Service is removed");

    LOG4CPLUS_DEBUG(myLoger->logger_1, " Service ");

    printf("==========start service [enter] ============\n");
    return 0;
}