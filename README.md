# RoboCup2016RVRL_Demo  
A playable sample package of RoboCup 2016 Rescue Virtual Robot League Fields with gazebo_ros.  

## This pachage includes following packages.  
    * https://github.com/m-shimizu/p3at_with_sensors_for_gazebo_ros  
      (it includes https://github.com/nkoenig/pioneer3at_demo)  
    * https://github.com/m-shimizu/RoboCup2016RVRL_FieldModels  

## How to setup.  
    $ cd  
    $ git clone https://github.com/m-shimizu/RoboCup2016RVRL_Demo  
    $ cd ~/RoboCup2016RVRL_Demo/src  
    $ catkin_init_workspace  
    $ cd ..  
    $ catkin_make install  

## How to play.  
    $ cd ~/RoboCup2016RVRL_Demo/src  
    $ source install/setup.bash  
    $ source setup.gazebo_model_path  
    $ roslaunch RC2016RVRL RC2016VRL_Final_RUN2_RETRY.launch  
    $ roslaunch teleop_joy teleop_joy  

## How to stop the simulation.
    (On the terminal which you did "roslauch RC2016RVRL RC2016VRL_Final_RUN2_RETRY.launch")
    * Push CTRL-Z  
    $ killall -9 roscore gzserver gzclient  
