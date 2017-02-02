#!/usr/bin/env python

import rospy
from performance_tests.msg import SuperAwesome


# publisher function 
def py_publisher():

    pub = rospy.Publisher( 'test_topic', SuperAwesome, queue_size=10 )

    rospy.init_node( 'py_publisher', anonymous=True )

    rate = rospy.Rate( rospy.get_param( "~publisher_rate", 10 ) )

    while not rospy.is_shutdown():

	msg = SuperAwesome()
        msg.sup_awsm = "Super Awesome Message %s" % rospy.get_time()

	rospy.loginfo( msg )

        pub.publish( msg )

        rate.sleep()


# main code 
if __name__ == '__main__':
    try:
        py_publisher()
    except rospy.ROSInterruptException:
        pass
