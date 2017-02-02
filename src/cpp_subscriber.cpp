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

// data is very inconsistent ... need to average 
const int sec_buffer_len = 1000;
double sec_buffer[ sec_buffer_len ];

void ini_sec_buffer() 
{
	for( int i=0; i<sec_buffer_len; i++ ) sec_buffer[i] = 0.0; 
}

void push_sec_buffer( double val ) 
{
	for( int i=0; i<sec_buffer_len-1; i++ ) sec_buffer[i] = sec_buffer[i+1];

	sec_buffer[sec_buffer_len - 1] = val; 
}

double sum_sec_buffer() 
{
	double sum = 0.0; 
	for( int i=0; i<sec_buffer_len; i++ ) sum += sec_buffer[i];

	return sum; 
}


double sec_before;   

void callback( const performance_tests::SuperAwesome::ConstPtr& msg )
{
	double sec_now = ros::Time::now().toSec(); 
  	// ROS_INFO( "CPP subscriber freq: %f Hz", 1.0 / ( sec_now - sec_before ) ); // data is very inconsistent

	push_sec_buffer( sec_now - sec_before );
	sec_before = sec_now;

  	ROS_INFO( "CPP subscriber freq: %f Hz", 1.0 / ( sum_sec_buffer() / sec_buffer_len ) );
 
}

int main( int argc, char **argv )
{

	ini_sec_buffer();
 
	ros::init( argc, argv, "cpp_subscriber" );

	ros::NodeHandle nh;

	ros::Subscriber sub = nh.subscribe( "test_topic", 1, callback );

	sec_before = ros::Time::now().toSec();
	
	ros::spin();

	return 0;

}





















