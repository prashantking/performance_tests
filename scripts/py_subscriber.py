#!/usr/bin/env python

import rospy
from performance_tests.msg import SuperAwesome


def cppcallback(msg):
	rospy.loginfo(msg.funny)

if __name__ == '__main__':
	rospy.init_node("py_subscriber")
	rospy.Subscriber('/fun_topic', SuperAwesome, cppcallback)
	rospy.spin()

