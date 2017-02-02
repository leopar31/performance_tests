# performance_tests

Intial commit of the publishers and subscribers in c++ and Python with basic functionality as requested in the problem formulation

Both of the publishers: "cpp_publisher.cpp" and "py_publisher.py" accept a private parameter "publisher_rate" at runtime as: $rosrun performance_tests py_publisher.py _publisher_rate:=50 if not given the rate of publishing defaults to value 10 (10Hz)

Both of the publishers publish on the same topic "test_topic"

Both subscribers: "cpp_subscriber.cpp" and "py_subscriber.py" are subscribing to "test_topic"

Publishers and Subscribers report overheads measured in ms

For publishers rate.sleep() calls are excluded from the measured overhead

for publishers and subscribers alike the ROS_INFO signal calls (as unnecessary for functionality) are excluded from overheads measurements 

All tests are perfomed on a ROS Kinetic under Ubuntu 16.04 installed in a VirtualBox, which is running on a Dell laptop with Windows 8 

Typical values of CPP_Publisher (running at 50Hz publishing rate) overheads:
* without a subscriber running    ~= 0.020 ms  
* with CPP_Subscriber running     ~= 0.080 - 0.090 ms with occasional spikes of the overhead above 0.100 ms
* with Python_Subscriber running  ~= 0.080 - 0.110 ms with occasional spikes of the overhead above 0.200 ms
    
    overheads are generally much more unstable with a subscriber running  
    
Whlie running alongside CPP_Publisher typical subscribers overheads: 
* CPP_Subscriber    ~= 0.050 - 0.080 ms
* Python_Subscriber ~= 20 ms
    
    
Typical values of Python_Publisher (running at 50Hz publishing rate) overheads:
* without a subscriber running    ~= 0.050 ms  
* with CPP_Subscriber running     ~= 0.120 - 0.180 ms with occasional spikes of the overhead above 0.200 ms
* with Python_Subscriber running  ~= 0.120 - 0.180 ms with occasional spikes of the overhead above 0.300 ms
    
    overheads show similar unstable behaviour with a subscriber running  
    
Whlie running alongside Python_Publisher typical subscribers overheads: 
* CPP_Subscriber    ~= 0.080 - 0.180 ms
* Python_Subscriber ~= 20 ms

The Python subscriber has by far the largest overheads. With consistent 20ms overheads per callback it will have difficulties keeping up with 50Hz and higher publishing rates

Surprisingly the Python Publisher is not as slow as the Subscriber. It is probably because function callback is one of the main sources of drop in Python code performance, which confirms my earlier experience with numerical software development in C++/Python. The Pyhton Publisher is only marginally slower than the CPP conterpart

While looking at the subscribers overheads one can assume that they should be able to run at much higher rates than 100Hz, but when pushed to higher rates (without a subscriber - measuring by "rostopic hz /test_topic") have difficulties reaching publishing rates of above ~120 Hz even with ROS_INFO calls removed, which might be to do with the current installation I have 


With more time awailable I would have tested different timing libraries to make sure that timing precision does not influence the results, or/tried to publish the overheads values as separate ROS topics to analyse the performance figures using ROS tools 

