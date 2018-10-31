# performance_tests
Performance test is for testing the 4 combinations of publisher and subscriber (c++ and python)

## PROGRAMS
1. cpp_publisher - contains a c++ publisher and two parameters(loop rate and dynmamic parameter enable bit).
                   loop rate can be set either directly with param or using dymanic parameter. to use dynamic parameter
                   ```
                   <param name="dynamic_param" type="bool" value="true"/>
                   ```
                   should be true in all launch file where cpp_publisher is used and rqt_reconfigure can be used by using below command
                   ```
                   rosrun rqt_reconfigure rqt_reconfigure
                   ```
2. cpp_subscriber - It is a simple subscriber scubsctibing to a topic ("/fun_topic")
3. py_publisher 
4. py_subscriber

## LAUNCH FILES
1. test_combination1.launch - C++ publisher to Python subscriber
2. test_combination2.launch - C++ publisher to C++ subscriber  
3. test_combination3.launch - Python publisher to Python subscriber
4. test_combination4.launch - Python publisher to C++ subscriber
