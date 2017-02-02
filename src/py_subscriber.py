#!/usr/bin/env python

import rospy
from performance_tests.msg import SuperAwesome

import  numpy as np 

sec_buffer_len = 1000
sec_buffer = np.zeros( sec_buffer_len )

global sec_before

def callback( msg ):
    
    global sec_before
    
    sec_now = rospy.get_time()
    # rospy.loginfo( "Python subscriber freq %f Hz", 1.0 / ( sec_now - sec_before ) )

    # pushing in the value
    for i in range( sec_buffer_len - 1 ) :
        sec_buffer[i] = sec_buffer[i+1]
    sec_buffer[-1] = sec_now - sec_before
    sec_before = sec_now

    rospy.loginfo( "Python subscriber freq %f Hz", 1.0 / ( np.sum( sec_buffer )/sec_buffer_len ) )
    

def py_subscriber():

    rospy.init_node( 'py_subscriber', anonymous=True )

    rospy.Subscriber( "test_topic", SuperAwesome, callback, queue_size=1 )

    global sec_before
    sec_before = rospy.get_time()

    rospy.spin()


if __name__ == '__main__':
    py_subscriber()
