//
// Created by Etienne on 12/2/18.
//

#ifndef ALGOPAPER_NATIVE_LIB_H
#define ALGOPAPER_NATIVE_LIB_H

#include <jni.h>


JNIEXPORT void
JNICALL
Java_com_algofashion_etienne_algopaper_TilesActivity_tilesCpp (
        JNIEnv *env,
        jobject /* this */,
        jintArray pixels,
        jint w,
        jint h);


JNIEXPORT void
JNICALL
Java_com_algofashion_etienne_algopaper_SnakeColorsActivity_SnakeColors (
        JNIEnv *env,
        jobject /* this */,
        jintArray pixels,
        jint w,
        jint h,
        jstring jparam);

JNIEXPORT void
JNICALL
Java_com_algofashion_etienne_algopaper_PastelGradientsActivity_PastelGradients (
        JNIEnv *env,
        jobject /* this */,
        jintArray pixels,
        jint w,
        jint h,
        jstring jparam);

JNIEXPORT void
JNICALL
Java_com_algofashion_etienne_algopaper_SpiralColorsActivity_SpiralColors (
        JNIEnv *env,
        jobject /* this */,
        jintArray pixels,
        jint w,
        jint h,
        jstring jparam);


JNIEXPORT void
        JNICALL
Java_com_algofashion_etienne_algopaper_SpiralColorsFadeActivity_SpiralColorsFade (
        JNIEnv *env,
        jobject /* this */,
        jintArray pixels,
        jint w,
        jint h,
        jstring jparam);



JNIEXPORT void
        JNICALL
Java_com_algofashion_etienne_algopaper_SpiralColorsFadeMultiActivity_SpiralColorsFadeMulti (
        JNIEnv *env,
        jobject /* this */,
        jintArray pixels,
        jint w,
        jint h,
        jstring jparam);
#endif //ALGOPAPER_NATIVE_LIB_H
