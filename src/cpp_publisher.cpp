// ------------------------------------------------------
//
// CPP_Publisher code for performance_tests project
//   
// Blue Ocean Robotics task No.1 
// author: Leonid Paramonov    
//   
// ------------------------------------------------------

#include "ros/ros.h"
#include "performance_tests/SuperAwesome.h"

#include <sstream>


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

	int count = 0; 
	std::stringstream str_strm;
	while( ros::ok() )
	{
		// the message object
		performance_tests::SuperAwesome msg;

		// composing the message string 
		str_strm << "Super Awesome Message " << count;
		// assigning the the message content
		msg.sup_awsm = str_strm.str();
		// cleaning the stream for the next usage
		str_strm.str( std::string() );

		// a signal output
		ROS_INFO( "%s", msg.sup_awsm.c_str() );

		// publishing the main message on the test_topic
		test_publisher.publish( msg );

		// spinning callbacks once
		ros::spinOnce();

		// sleepnig untill the next loop
		loop_rate.sleep();

		++count; 
	}

	return 0;

} 
