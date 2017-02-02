






























































































































// ------------------------------------------------------
//
// CPP_Subscriber code for performance_tests project
//   
// Blue Ocean Robotics task No.1 
// author: Leonid Paramonov    
//   
// ------------------------------------------------------

#include "ros/ros.h"
#include "performance_tests/SuperAwesome.h"


void topic_callback( const performance_tests::SuperAwesome::ConstPtr& msg )
{
  	ROS_INFO( "the awesome message is: %s", msg->sup_awsm.c_str() );
}

int main( int argc, char **argv )
{

	ros::init( argc, argv, "cpp_subscriber" );

	ros::NodeHandle nh;

	ros::Subscriber sub = nh.subscribe( "test_topic", 10, topic_callback );

	ros::spin();

	return 0;

}





















