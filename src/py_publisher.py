#!/usr/bin/env python

import rospy
from performance_tests.msg import SuperAwesome

global sec_before

# publisher function 
def py_publisher():

    pub = rospy.Publisher( 'test_topic', SuperAwesome, queue_size=1 )

    rospy.init_node( 'py_publisher', anonymous=True )

    rate = rospy.Rate( rospy.get_param( "~publisher_rate", 10 ) )

    global sec_before
    sec_before = rospy.get_time()

    while not rospy.is_shutdown():

	msg = SuperAwesome()
        msg.sup_awsm = "Super Awesome Message %s" % rospy.get_time()

        pub.publish( msg )

	sec_now = rospy.get_time()
	rospy.loginfo( "Python publisher freq %f Hz", 1.0 / ( sec_now - sec_before ) )
	sec_before = sec_now

        rate.sleep()


# main code 
if __name__ == '__main__':
    try:
        py_publisher()
    except rospy.ROSInterruptException:
        pass


