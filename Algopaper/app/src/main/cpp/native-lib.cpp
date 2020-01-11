#include <jni.h>
#include <string>
#include <stdlib.h>

#include "../../../../../cpp/src/SnakeColors.h"
#include "../../../../../cpp/src/PastelGradients.h"
#include "../../../../../cpp/src/SpiralColors.h"
#include "../../../../../cpp/src/SpiralColorsFade.h"
#include "../../../../../cpp/src/SpiralColorsFadeMulti.h"

int Color(int a, int r, int g, int b) {
    return (a << 24) | (r << 16) | (g << 8) | b;
}

int a(int color) {
    return (color & 0xFF000000) >> 24;
}

int r(int color) {
    return (color & 0x00FF0000) >> 16;
}

int g(int color) {
    return (color & 0x0000FF00) >> 8;
}

int b(int color) {
    return (color & 0x000000FF);
}

void import_pixels(jint* jpixels, int *fpixels, int w, int h) {
    int col;
    int channels = 4;

    for(int i = 0; i < w; i++) {
        for(int j = 0; j < h; j++) {
            col = jpixels[j * w + i];
            fpixels[j * w * channels + i * channels] = a(col);
            fpixels[j * w * channels + i * channels + 1] = r(col);
            fpixels[j * w * channels + i * channels + 2] = g(col);
            fpixels[j * w * channels + i * channels + 3] = b(col);
        }
    }
}

void export_pixels(int *fpixels, jint* cpixels, int w, int h) {
    int ca, cr, cg, cb;
    int channels = 4;

    for(int i = 0; i < w; i++) {
        for(int j = 0; j < h; j++) {

            ca = fpixels[j * w * channels + i * channels];
            cr = fpixels[j * w * channels + i * channels + 1];
            cg = fpixels[j * w * channels + i * channels + 2];
            cb = fpixels[j * w * channels + i * channels + 3];

            cpixels[j * w + i] = Color(ca, cr, cg, cb);
        }
    }
}


extern "C"
JNIEXPORT void
JNICALL
Java_com_algofashion_etienne_algopaper_TilesActivity_tilesCpp (
        JNIEnv *env,
jobject /* this */,
jintArray pixels,
jint w,
jint h) {

    int colorMixer = rand();
    int a, r, g, b;

    printf("Allocation\n");
    jint cpixels[w * h];

    for(int i = 0; i < w; i++) {
        for(int j = 0; j < h; j++) {

            a = 255;
            r = (i + colorMixer ) % 255;
            g = (j + colorMixer ) % 255;
            b = ( i * j + colorMixer ) % 255;

            printf("Calling colors\n");
            cpixels[i + w * j] = Color(a, r, g, b);
        }
    }

    (*env).SetIntArrayRegion(pixels, 0, w * h, cpixels);

}

extern "C"
JNIEXPORT void
JNICALL
Java_com_algofashion_etienne_algopaper_SnakeColorsActivity_SnakeColors (
        JNIEnv *env,
        jobject /* this */,
        jintArray pixels,
        jint w,
        jint h,
        jstring jparam) {
    int channels = 4;
    int *fpixels;
    jint *jpixels = env->GetIntArrayElements(pixels, NULL);
    fpixels = new int[w * h * channels];
    jint cpixels[w * h];

    const char *jcparam = env->GetStringUTFChars(jparam, NULL);
    std::string jsparam = string(jcparam);

    import_pixels(jpixels, fpixels, w, h);
    SnakeColors::androidSnakeColors(fpixels, w, h, jsparam);
    export_pixels(fpixels, cpixels, w, h);

    env->SetIntArrayRegion(pixels, 0, w * h, cpixels);
}

extern "C"
JNIEXPORT void
JNICALL
Java_com_algofashion_etienne_algopaper_PastelGradientsActivity_PastelGradients (
        JNIEnv *env,
        jobject /* this */,
        jintArray pixels,
        jint w,
        jint h,
        jstring jparam) {
    int channels = 4;
    int *fpixels;
    jint *jpixels = env->GetIntArrayElements(pixels, NULL);
    fpixels = new int[w * h * channels];
    jint cpixels[w * h];

    const char *jcparam = env->GetStringUTFChars(jparam, NULL);
    std::string jsparam = string(jcparam);

    import_pixels(jpixels, fpixels, w, h);
    PastelGradients::androidPastelGradients(fpixels, w, h, jsparam);
    export_pixels(fpixels, cpixels, w, h);

    env->SetIntArrayRegion(pixels, 0, w * h, cpixels);
}

extern "C"
JNIEXPORT void
JNICALL
Java_com_algofashion_etienne_algopaper_SpiralColorsActivity_SpiralColors (
        JNIEnv *env,
        jobject /* this */,
        jintArray pixels,
        jint w,
        jint h,
        jstring jparam) {
    int channels = 4;
    int *fpixels;
    jint *jpixels = env->GetIntArrayElements(pixels, NULL);
    fpixels = new int[w * h * channels];
    jint cpixels[w * h];

    const char *jcparam = env->GetStringUTFChars(jparam, NULL);
    std::string jsparam = string(jcparam);

    import_pixels(jpixels, fpixels, w, h);
    SpiralColors::androidSpiralColors(fpixels, w, h, jsparam);
    export_pixels(fpixels, cpixels, w, h);

    env->SetIntArrayRegion(pixels, 0, w * h, cpixels);
}

extern "C"
JNIEXPORT void
JNICALL
Java_com_algofashion_etienne_algopaper_SpiralColorsFadeActivity_SpiralColorsFade (
        JNIEnv *env,
        jobject /* this */,
        jintArray pixels,
        jint w,
        jint h,
        jstring jparam) {
    int channels = 4;
    int *fpixels;
    jint *jpixels = env->GetIntArrayElements(pixels, NULL);
    fpixels = new int[w * h * channels];
    jint cpixels[w * h];

    const char *jcparam = env->GetStringUTFChars(jparam, NULL);
    std::string jsparam = string(jcparam);

    import_pixels(jpixels, fpixels, w, h);
    SpiralColorsFade::androidSpiralColorsFade(fpixels, w, h, jsparam);
    export_pixels(fpixels, cpixels, w, h);

    env->SetIntArrayRegion(pixels, 0, w * h, cpixels);
}


extern "C"
JNIEXPORT void
JNICALL
Java_com_algofashion_etienne_algopaper_SpiralColorsFadeMultiActivity_SpiralColorsFadeMulti (
        JNIEnv *env,
        jobject /* this */,
        jintArray pixels,
        jint w,
        jint h,
        jstring jparam) {
    int channels = 4;
    int *fpixels;
    jint *jpixels = env->GetIntArrayElements(pixels, NULL);
    fpixels = new int[w * h * channels];
    jint cpixels[w * h];

    const char *jcparam = env->GetStringUTFChars(jparam, NULL);
    std::string jsparam = string(jcparam);

    import_pixels(jpixels, fpixels, w, h);
    SpiralColorsFadeMulti::androidSpiralColorsFadeMulti(fpixels, w, h, jsparam);
    export_pixels(fpixels, cpixels, w, h);

    env->SetIntArrayRegion(pixels, 0, w * h, cpixels);
}