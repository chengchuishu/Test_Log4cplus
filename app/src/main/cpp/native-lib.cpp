#include <jni.h>
#include <string>

#include "MyLogger.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_yunshen_test_1log4cplus_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    MyLogger * myLoger = NULL;
    myLoger = MyLogger::getInstance();

    LOG4CPLUS_FATAL(myLoger->rootLog, "DeleteService failed,errCode=[" << 1 << "]");
    LOG4CPLUS_DEBUG(myLoger->rootLog, " Service is removed");

    LOG4CPLUS_DEBUG(myLoger->logger_1, " Service ");

    return env->NewStringUTF(hello.c_str());
}