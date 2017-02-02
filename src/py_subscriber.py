#!/usr/bin/env python

import rospy
from performance_tests.msg import SuperAwesome


def callback( msg ):
    rospy.loginfo( rospy.get_caller_id() + "I heard %s", msg.sup_awsm )
    

def py_subscriber():

    rospy.init_node( 'py_subscriber', anonymous=True )

    rospy.Subscriber( "test_topic", SuperAwesome, callback )

    rospy.spin()


if __name__ == '__main__':
    py_subscriber()
