# IMPORTANT : THIS REPOSITORY WAS MOVED TO THE NEW ORGANIZATION "[RoboCup Rescue Simulation Virtual Robot League](https://github.com/RoboCupRescueVirtualRobotLeague)."  
# PLEASE VISIT THE ORGANIZATION TO KEEP YOU UPTODATE.  
---  
# RoboCup2016RVRL_Demo  
A playable sample package of RoboCup 2016 Rescue Virtual Robot League Fields with gazebo_ros.  

## This package includes following packages.  
    * https://github.com/m-shimizu/p3at_with_sensors_for_gazebo_ros  
      (it includes https://github.com/nkoenig/pioneer3at_demo)  
    * https://github.com/m-shimizu/RoboCup2016RVRL_FieldModels  
    * models from https://github.com/m-shimizu/RoboCupRescuePackage  

## Robots.  
You can use the pioneer3at robot. It has a camera and a hokuyo laser range finder.  
In this demo, automatically 4 pioneer3at robots will be spawned.  
You can see topics which will be published from robots with a ros command "rostopic list".  

## Requirement of Gazebo and ROS  
This package requires Gazebo5 and ROS-Indigo.  
You should prepare them with following commands.  
If you are already using ROS with Gazebo2 embedded in ROS-Indigo, you must uninstall Gazebo2 before installing Gazebo5.  

    * Gazebo5  
    $ sudo sh -c 'echo "deb http://packages.osrfoundation.org/gazebo/ubuntu `lsb_release -cs` main" > /etc/apt/sources.list.d/gazebo-latest.list'  
    $ wget http://packages.osrfoundation.org/gazebo.key -O - | sudo apt-key add -   
    $ sudo apt-get update   
    $ sudo apt-get install libgazebo5 libgazebo5-dev   

    * ROS-Indigo  
    $ sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'  
    $ sudo apt-key adv --keyserver hkp://pool.sks-keyservers.net --recv-key 0xB01FA116  
    $ sudo apt-get update  
    $ sudo apt-get install ros-indigo-desktop ros-indigo-ros-controllers ros-indigo-image-view2 ros-indigo-rqt ros-indigo-rqt-common-plugins ros-indigo-hector-mapping ros-indigo-hector-geotiff ros-indigo-joy ros-indigo-teleop-twist-keyboard python-rosinstall ros-indigo-gazebo5-ros-pkgs ros-indigo-gazebo5-ros-control  

## How to setup this package.  
    $ cd  
    $ git clone https://github.com/m-shimizu/RoboCup2016RVRL_Demo  
    $ cd ~/RoboCup2016RVRL_Demo/src  
    $ catkin_init_workspace  
    $ cd ..  
    $ catkin_make install  

## How to play.  
You need two terminals.  

  At Terminal1:  

    $ cd ~/RoboCup2016RVRL_Demo  
    $ source install/setup.bash  
    $ source setup.gazebo_model_path  
    $ roslaunch rc2016rvrl RC2016VRL_Final_RUN2_RETRY.launch  

  You can choose other worlds from followings:

    * RC2016VRL_Preliminary1.launch  
    * RC2016VRL_Preliminary2.launch  
    * RC2016VRL_Preliminary3.launch  
    * RC2016VRL_Final_RUN1.launch  
    * RC2016VRL_Final_RUN2.launch  
    * RC2016VRL_Final_RUN2_RETRY.launch  

Now, you can see 4 robots on a field.  
Next you have to execute a robot controller.  

  At Terminal2:  

    $ cd ~/RoboCup2016RVRL_Demo  
    $ source install/setup.bash  
    $ roslaunch rc2016rvrl control_a_robot.launch robot_name:=robot1 joystick:=0  

You can choose robot2, robot3 or robot4 with robot_name:=robot2, robot_name:=robot3 or robot_name:=robot4 .

## Controlling robots with joy stick.  
For this demo, I prepared a ros package "teleop_joy".  
Calling control_a_robot.launch With "joystick:=1", you can controll a robot by using a game coontoller.  
You can use just only the left analog stick to move your robot.  

## How to stop the simulation.  
    (On the terminal which you did "roslauch rc2016rvrl RC2016VRL_Final_RUN2_RETRY.launch")  
    * Push CTRL-Z  
    $ killall -9 roscore gzserver gzclient  
