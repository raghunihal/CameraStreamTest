# CameraStreamTest
Test Application for Reading Multiple RTSP Streams using Opencv 4.5.5
# Libararies 
Opencv 4.5.5
Intel Threaded Building Blocks (Intel TBB)

Compilation steps
g++ -std=c++14 CameraStreamer.hpp CameraStreamer.cpp MultiCamera.cpp `pkg-config opencv --cflags --libs` -I /usr/include/tbb -ltbb -lpthread
