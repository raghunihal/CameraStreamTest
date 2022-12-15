/*g++ -std=c++14 CameraStreamer.hpp CameraStreamer.cpp MultiCamera.cpp `pkg-config opencv --cflags --libs` -I /usr/include/tbb -ltbb -lpthread*/

#include "CameraStreamer.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <future>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
 
int main()
{
 
  //RTSP Camera indices
  vector < int > capture_index = {0,1,2,3};
  //IP camera URLs (RTSP)
  vector < string > capture_source = 
  {
    "rtsp://172.196.129.254:9002/172.196.129.152_WAN_65536152",
    "rtsp://172.196.129.254:9002/172.196.129.153_WAN_65536153",
    "rtsp://172.196.129.254:9002/172.196.129.162_WAN_65536162",
    "rtsp://172.196.129.254:9002/172.196.129.163_WAN_65536163"
  };
 
    //Highgui window titles
    vector<string> label;
    for (int i = 0; i < capture_source.size(); i++)
    {
        string title = "CAMERA " + to_string(i);
        label.push_back(title);
    }
 
    //Make an instance of CameraStreamer
    CameraStreamer cam(capture_source);
 
    while (waitKey(20) != 27)
    {
        //Retrieve frames from each camera capture thread
        for (int i = 0; i < capture_source.size(); i++)
		{
			Mat frame;
			//Pop frame from queue and check if the frame is valid
			if (cam.frame_queue[i]->try_pop(frame))
			{
                //Show frame on Highgui window
                imshow(label[i], frame);
            }
        }
    }
}
