# Architecture

Author: Pooja Kiragi

## Android (native)
Camera -> Java (CameraX/Camera2) -> JNI (`nativeProcessFrame`) -> OpenCV processing -> return frames/bitmaps to Java for display or upload.

## Web (TypeScript)
Browser getUserMedia -> OffscreenCanvas -> Worker (simulated processing) -> UI canvas display.

