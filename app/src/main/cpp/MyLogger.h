//
// Created by 17719242718 on 2020/12/14.
//

#ifndef TEST_LOG4CPLUS_MYLOGGER_H
#define TEST_LOG4CPLUS_MYLOGGER_H

#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/layout.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/helpers/stringhelper.h>


#ifdef WIN32
#include <windows.h>
#pragma comment(lib, "..\\..\\log4cplus-1.2.1\\msvc10\\Win32\\bin.Debug\\log4cplusSD.lib")
unsigned CharToTchar(const char * _char, TCHAR * tchar)
{
    if (nullptr == _char || nullptr == tchar)
        return 1;
    int iLength;
    iLength = MultiByteToWideChar(0, 0, _char, strlen(_char) + 1, NULL, 0);
    MultiByteToWideChar(0, 0, _char, strlen(_char) + 1, tchar, iLength);
    return 0;
}
#else
#endif

#define MY_LOG_FILE_PATH "logconfig.property"


class MyLogger
{
private:
    MyLogger()
    {
        log4cplus::initialize();
        log4cplus::PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT(MY_LOG_FILE_PATH));
        rootLog = log4cplus::Logger::getRoot();
        char test[16] = "test";

#ifdef WIN32
        TCHAR tTest[16];
        unsigned uRet = CharToTchar(test, tTest);

        if (0 == uRet)
            logger_1 = log4cplus::Logger::getInstance(tTest);
#else
        logger_1 = log4cplus::Logger::getInstance(test);
#endif

    }
    ~MyLogger()
    {
        if (m_logger)
        {
            delete m_logger;
        }
    }


    static MyLogger* m_logger;

public:
    static MyLogger * getInstance()
    {
        if (m_logger == NULL)
        {
            m_logger = new MyLogger();
        }
        return m_logger;
    }

    log4cplus::Logger rootLog;
    log4cplus::Logger logger_1;

};

MyLogger* MyLogger::m_logger = NULL;

#endif //TEST_LOG4CPLUS_MYLOGGER_H
