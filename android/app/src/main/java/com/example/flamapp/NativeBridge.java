package com.example.flamapp;

public class NativeBridge {
    static {
        System.loadLibrary("native-lib");
    }

    public static native String stringFromJNI();
    public static native byte[] nativeProcessFrame(byte[] data, int width, int height);
}
