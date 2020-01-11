#ifndef JSONUTILS_H 
#define JSONUTILS_H 

#include "json.h"
#include <iostream>

using namespace nlohmann;
using namespace std;

class JSONUtils {
    public:
        template<typename T>
        static T loadParam(string jstring, string paramName, T defaultValue);
};

template<typename T>
T JSONUtils::loadParam(string jstring, string paramName, T defaultValue) {

            T res = defaultValue;
            auto params = json::parse(jstring);
            auto it = params.find(paramName);
            if(it != params.end()) {
                res = params[paramName];
            }

            return res;
        }

#endif
