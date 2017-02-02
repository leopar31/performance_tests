// ------------------------------------------------------
//
// CPP_Subscriber code for performance_tests project
//   
// Blue Ocean Robotics task No.1 
// author: Leonid Paramonov    
//   
// ------------------------------------------------------

#include <ctime> 

#include "ros/ros.h"
#include "performance_tests/SuperAwesome.h"

// should have used <std::chrono> 
clock_t overhead_start = std::clock(); 
clock_t overhead_end   = std::clock(); 

void topic_callback( const performance_tests::SuperAwesome::ConstPtr& msg )
{
	overhead_end   = std::clock(); 
  	ROS_INFO( "CPP subscriber overhead: %f ms", 1000.0 * (double)( overhead_end - overhead_start ) / CLOCKS_PER_SEC );
	overhead_start = std::clock(); 
}

int main( int argc, char **argv )
{

	ros::init( argc, argv, "cpp_subscriber" );

	ros::NodeHandle nh;

	ros::Subscriber sub = nh.subscribe( "test_topic", 10, topic_callback );

	ros::spin();

	return 0;

}





















