# ROS RTES 2021

This repository contains a ros package called "hello_world".
Inside there are 4 nodes:
  - hello_world_node: just prints hello world when executed
  - my_pub_node: continuously publishes a message on topic "/my_pub"
  - my_sub_node: subscribes to topic "my_pub" and prints messages
  - my_bag_node: subscribes to an image topic and displays the image with opencv

These examples were tested on Ubuntu 18.04 LTS with ROS Melodic and on Ubuntu 20.04 LTS with ROS Noetic.

___
### Note: 
the last node is **not** compiled, you need to modify the CMakeLists.txt of the package to compile it:
simply uncomment the "add_executable", "target_link_libraries" and OpenCV_LIBRARIES lines related to "my_bag_node".
You need OpenCV installed on your system.