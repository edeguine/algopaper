//
// Created by Etienne on 12/2/18.
//

#include "Hello.h"
#include <android/log.h>

Hello::Hello() {
    value = rand();
}

void Hello::print() {
    __android_log_print(ANDROID_LOG_DEBUG, "C++ LOG",  "Value %d\n", value);
}