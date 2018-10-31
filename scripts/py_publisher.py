#!/usr/bin/env python

import rospy
from performance_tests.msg import SuperAwesome

if __name__ == "__main__":
	rospy.init_node("py_publisher")

	msg_string = SuperAwesome()
	pub = rospy.Publisher('/fun_topic', SuperAwesome, queue_size=1)
	r = rospy.Rate(rospy.get_param("/py_publisher/loop_frequency")) 
	#r = rospy.Rate(100)
	while not rospy.is_shutdown():
		msg_string.funny = "Hello Fun World"
		pub.publish(msg_string)
		r.sleep()
