#!/usr/bin/env python

import rospy
from performance_tests.msg import SuperAwesome

import time

# returns time in seconds
overhead_end   = time.time()
overhead_start = time.time()

def callback( msg ):
    
    global overhead_end
    global overhead_start
    
    overhead_end   = time.time()
    rospy.loginfo( "Python subscriber overhead %f ms", ( overhead_end - overhead_start ) * 1000.0 )
    overhead_start = time.time()
    

def py_subscriber():

    rospy.init_node( 'py_subscriber', anonymous=True )

    rospy.Subscriber( "test_topic", SuperAwesome, callback )

    rospy.spin()


if __name__ == '__main__':
    py_subscriber()
