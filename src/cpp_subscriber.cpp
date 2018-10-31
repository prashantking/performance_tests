#include <ros/ros.h>
#include "performance_tests/SuperAwesome.h"

void cppCallback(const performance_tests::SuperAwesome::ConstPtr& msg)
{
  ROS_INFO("[%s]", msg->funny.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "cpp_subscriber");
  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("/fun_topic", 1, cppCallback); //size of message queue

  ros::spin();

  return 0;
}
