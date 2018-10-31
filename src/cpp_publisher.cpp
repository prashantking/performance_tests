#include <ros/ros.h>
#include <dynamic_reconfigure/server.h>
#include <performance_tests/looprateConfig.h>
#include <std_msgs/String.h>
#include <sstream>
#include "performance_tests/SuperAwesome.h"

int rateParam;

void rate_callback(performance_tests::looprateConfig &config, uint32_t level)
{
    rateParam = config.rate;
    ROS_INFO("Reconfigure Request:%d %d",rateParam ,config.rate);   
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "cpp_publisher");
  ros::NodeHandle n;

  dynamic_reconfigure::Server<performance_tests::looprateConfig> server;
  dynamic_reconfigure::Server<performance_tests::looprateConfig>::CallbackType fun;
  fun = boost::bind(&rate_callback, _1, _2); 
  server.setCallback(fun);

  ros::Publisher cpp_pub = n.advertise<performance_tests::SuperAwesome>("/fun_topic", 1); 

  double rate;
  bool enableBit;

  if (!((ros::param::get("/cpp_publisher/loop_frequency",rate)) && (ros::param::get("/cpp_publisher/dynamic_param",enableBit))))
  {
        ROS_ERROR("'loop_frequency' param not found");
  }

    ros::Rate loop_rate(rate);

  while (ros::ok())
  {

    if(enableBit)
   	 loop_rate = ros::Rate(rateParam);
    else
   	 loop_rate = ros::Rate(rate);

    performance_tests::SuperAwesome msg;

    std::stringstream ss;
    ss << "Hello Fun World";
    msg.funny = ss.str();

    cpp_pub.publish(msg);

    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}
