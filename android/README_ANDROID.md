# Android Module - Build Notes

Package name: com.example.flamapp
App name: Flamapp AI Demo

Prereqs:
- Android Studio (Arctic Fox or later)
- Installed NDK (r21+)
- OpenCV Android SDK (download and extract)

CMake:
- Edit `android/app/src/main/jni/CMakeLists.txt` to set OpenCV_DIR to your local OpenCV Android SDK path.
