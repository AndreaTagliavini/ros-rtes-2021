#include <ros/ros.h>                            // include ros header file
#include "std_msgs/String.h"    
#include <sstream>

#define RATE 1000000000

int main(int argc, char* argv[]){
    ros::init(argc, argv, "my_pub_node");         // initialize ros
    ros::NodeHandle nh;                           // create a ros handle  
    ros::Publisher my_publisher = \
        nh.advertise<std_msgs::String>("my_pub", RATE);   // create a publisher
    std_msgs::String msg;                         // create a message that contains simple text (String)
    
    int count = 0;

    while(ros::ok()){
        std::stringstream ss;
        count++;
        ss << "Message " << count;                // save the string
        msg.data = ss.str();                      // copy the text in the message payload

        my_publisher.publish(msg);                // publish the message on the publisher topic
        msg.data = "";                            // remove the text from the message payload
    }
    
    ros::spin();                                  // keep the node alive forever
}
