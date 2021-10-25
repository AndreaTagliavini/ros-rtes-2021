#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>


#define TOPIC_NAME "/device_0/sensor_0/Fisheye_1/image/data"

void imageCallback(const sensor_msgs::ImageConstPtr& msg){
    try{
        cv::imshow("view", cv_bridge::toCvShare(msg, msg->encoding.c_str())->image);
        cv::waitKey(30);
    }
    catch (cv_bridge::Exception& e){
        ROS_ERROR("Could not convert from '%s' to 'mono8'.", msg->encoding.c_str());
    }
}


int main(int argc, char* argv[]){
    ros::init(argc, argv, "my_bag_node");         // initialize ros
    ros::NodeHandle nh;                           // create a ros handle  
    cv::namedWindow("view");

    image_transport::ImageTransport it(nh);
    image_transport::Subscriber sub = it.subscribe(TOPIC_NAME, 1, imageCallback);
    ros::spin();                                  // keep the node alive forever

    cv::destroyWindow("view");
}

