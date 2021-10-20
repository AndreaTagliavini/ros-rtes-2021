
#include <ros/ros.h>                            // include ros header file

int main(int argc, char* argv[]){
    ros::init(argc, argv, "hello_world_node");    // initialize ros
    ros::NodeHandle nh;                           // create a ros handle

    ROS_INFO("Hello, World!");                    // print hello world using ros functions
  

    ros::spin();                                  // keep the node alive forever
}

