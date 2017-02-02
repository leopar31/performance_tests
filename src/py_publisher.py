#!/usr/bin/env python

import rospy
from performance_tests.msg import SuperAwesome

import time

overhead_end   = time.time()
overhead_start = time.time()


# publisher function 
def py_publisher():

    global overhead_end
    global overhead_start

    pub = rospy.Publisher( 'test_topic', SuperAwesome, queue_size=10 )

    rospy.init_node( 'py_publisher', anonymous=True )

    rate = rospy.Rate( rospy.get_param( "~publisher_rate", 10 ) )

    while not rospy.is_shutdown():

	msg = SuperAwesome()
        msg.sup_awsm = "Super Awesome Message %s" % rospy.get_time()

        pub.publish( msg )

	overhead_end = time.time()

	rospy.loginfo( "Python publisher overhead %f ms", ( overhead_end - overhead_start ) * 1000.0 )

        rate.sleep()
	
	overhead_start = time.time()


# main code 
if __name__ == '__main__':
    try:
        py_publisher()
    except rospy.ROSInterruptException:
        pass


