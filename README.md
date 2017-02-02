# performance_tests

Package contains publishers and subscribers in C++ and Python with basic functionality as requested in the problem formulation

Both of the publishers: "cpp_publisher.cpp" and "py_publisher.py" accept a private parameter "publisher_rate" at runtime as: $rosrun performance_tests py_publisher.py _publisher_rate:=50 if not given the rate of publishing defaults to value 10 (10Hz)

Both of the publishers publish on the same topic "test_topic"

Both subscribers: "cpp_subscriber.cpp" and "py_subscriber.py" are subscribing to "test_topic"

A straightforward timing of the overheads (via ros::Time::now().toSec();/rospy.get_time() ) did not produce sufficiently stable results to draw consistent conclusions. Therefore a simple numerical buffer was added to both versions of the code (CPP:a custom buffer array, Python: a numpy array based buffer) for averaging out the noise. The length of the buffer was chosen to be 1000 consequent time intervals measured in the Subscriber callback function. The resulting vaues averaged over the last 1000 subscriber callback function calls were compared to publishing rates measured by "rostopic hz /test_topic". It takes few seconds for the running average to converge to comparatively stable values depending on the publisher_rate 


Results for the CPP_Publisher / CPP_Subscriber combination: 

|   publisher_rate   |   averaged subscriber rate   |   rostopic hz   |
|   ---   |   ---   |   ---   |
|   100   |   100   |   100   |
|   200   |   200   |   200   |
|   300   |   297   |   300   |
|   400   |   390   |   398   |
|   500   |   483   |   493   |


Results for the CPP_Publisher / Python_Subscriber combination: 

|   publisher_rate   |   averaged subscriber rate   |   rostopic hz   |
|   ---   |   ---   |   ---   |
|   100   |   100   |   100   |
|   200   |   199   |   199   |
|   300   |   294   |   299   |
|   400   |   354   |   398   |
|   500   |   365   |   495   |


Results for the Python_Publisher / CPP_Subscriber combination: 

|   publisher_rate   |   averaged subscriber rate   |   rostopic hz   |
|   ---   |   ---   |   ---   |
|   100   |   100   |   100   |
|   200   |   199   |   199   |
|   300   |   293   |   295   |
|   400   |   350   |   370   |
|   500   |   370   |   388   |


Results for the Python_Publisher / Python_Subscriber combination: 

|   publisher_rate   |   averaged subscriber rate   |   rostopic hz   |
|   ---   |   ---   |   ---   |
|   100   |   100   |   100   |
|   200   |   195   |   199   |
|   300   |   274   |   285   |
|   400   |   293   |   337   |
|   500   |   300   |   366   |


The averaged subscriber rates for publisher_rate = 300 and above were quite noisy (may be except the CPP/CPP pair).  

The trend of better performance of CPP nodes is clearly seen, while for the frequencies of 100Hz the difference in performance is insignificant (probably due to low computational load per node)

The example was not as trivial as it might have been looking from the first glance. It took way above 2 hours allocated for it



