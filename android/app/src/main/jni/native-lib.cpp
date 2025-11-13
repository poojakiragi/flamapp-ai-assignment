#include <jni.h>
#include <string>
#include <opencv2/opencv.hpp>

using namespace cv;

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_flamapp_NativeBridge_stringFromJNI(JNIEnv* env, jobject /* this */) {
    std::string hello = "Native layer loaded";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jbyteArray JNICALL
Java_com_example_flamapp_NativeBridge_nativeProcessFrame(JNIEnv* env, jobject,
                                                        jbyteArray data, jint width, jint height) {
    jsize len = env->GetArrayLength(data);
    jbyte* body = env->GetByteArrayElements(data, 0);

    Mat yuv(height + height/2, width, CV_8UC1, (unsigned char*)body);
    Mat bgr;
    cvtColor(yuv, bgr, COLOR_YUV2BGR_NV21);

    Mat gray, edges;
    cvtColor(bgr, gray, COLOR_BGR2GRAY);
    Canny(gray, edges, 50, 150);

    Mat rgba;
    cvtColor(edges, rgba, COLOR_GRAY2RGBA);

    int outLen = rgba.total() * rgba.elemSize();
    jbyteArray out = env->NewByteArray(outLen);
    env->SetByteArrayRegion(out, 0, outLen, (jbyte*)rgba.data);

    env->ReleaseByteArrayElements(data, body, 0);
    return out;
}
