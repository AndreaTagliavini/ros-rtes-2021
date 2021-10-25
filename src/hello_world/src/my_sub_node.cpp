
#include <ros/ros.h>                            // include ros header file
#include "std_msgs/String.h"


void subCallback(const std_msgs::String::ConstPtr& msg){
    ROS_INFO("I received [%s]", msg->data.c_str()); // print the message
}


int main(int argc, char* argv[]){
    ros::init(argc, argv, "my_sub_node");         // initialize ros
    ros::NodeHandle nh;                           // create a ros handle  
    
    ros::Subscriber sub = nh.subscribe("my_pub", 1000, subCallback);    // create a subscriber 
    ros::spin();                                  // keep the node alive forever
}

