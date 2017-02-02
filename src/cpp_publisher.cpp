// ------------------------------------------------------
//
// CPP_Publisher code for performance_tests project
//   
// Blue Ocean Robotics task No.1 
// author: Leonid Paramonov    
//   
// ------------------------------------------------------

#include <ctime>
#include <sstream>

#include "ros/ros.h"
#include "performance_tests/SuperAwesome.h"


int main(  int argc, char **argv  )
{

	// node init
	ros::init( argc, argv, "cpp_publisher" );

	// a node handle to start the publisher
	ros::NodeHandle nh;
	// the publisher  
	ros::Publisher test_publisher = nh.advertise<performance_tests::SuperAwesome>( "test_topic", 10  ); 

	// publisher_rate private parameter to be defined at run time 
	// defaults to 10 Hz
	int publisher_rate;
	nh.param( "/cpp_publisher/publisher_rate", publisher_rate, 10 );

	// setting the loop rate 
	ros::Rate loop_rate( publisher_rate );

	std::stringstream str_strm;
	clock_t overhead_start = std::clock(); 
	clock_t overhead_end   = std::clock(); 
	while( ros::ok() )
	{
		// the message object
		performance_tests::SuperAwesome msg;

		// composing the message string 
		str_strm << "Super Awesome Message ";
		// assigning the the message content
		msg.sup_awsm = str_strm.str();
		// cleaning the stream for the next usage
		str_strm.str( std::string() );

		// publishing the main message on the test_topic
		test_publisher.publish( msg );

		// // a signal output
		// ROS_INFO( "%s", msg.sup_awsm.c_str() );

		// spinning callbacks once
		ros::spinOnce();
		
		// measuring overhead excluding the signal output and rate.sleep()
		overhead_end = std::clock();

		// chrono requires C++11 support
		ROS_INFO( "CPP publisher overhead: %f ms", 1000.0 * (double)( overhead_end - overhead_start ) / CLOCKS_PER_SEC );

		// sleepnig untill the next loop
		loop_rate.sleep();

		overhead_start = std::clock();
	}

	return 0;

} 
