cmake_minimum_required(VERSION 3.10.2)
project("flamapp")

# NOTE: Edit OpenCV_DIR below to match your local OpenCV Android SDK path.
set(OpenCV_DIR "/path/to/OpenCV-android/sdk/native/jni")
find_package(OpenCV REQUIRED)
message(STATUS "OpenCV found: ${OpenCV_VERSION}")

add_library(native-lib SHARED native-lib.cpp)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(native-lib ${OpenCV_LIBS} android log)
