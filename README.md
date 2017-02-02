# performance_tests

Intial commit of the publishers and subscribers in c++ and Python with basic functionality as requested in the problem formulation

Both of the publishers: "cpp_publisher.cpp" and "py_publisher.py" accept a private parameter "publisher_rate" at runtime as: $rosrun performance_tests py_publisher.py _publisher_rate:=50 if not given the rate of publishing defaults to value 10 (10Hz)

Both of the publishers publish on the same topic "test_topic"

Both subscribers: "cpp_subscriber.cpp" and "py_subscriber.py" are subscribing to "test_topic"
