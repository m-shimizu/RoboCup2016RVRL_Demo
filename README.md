# RoboCup2016RVRL_Demo  
A playable sample package of RoboCup 2016 Rescue Virtual Robot League Fields with gazebo_ros.  

## This pachage includes following packages.  
    * https://github.com/m-shimizu/p3at_with_sensors_for_gazebo_ros  
      (it includes https://github.com/nkoenig/pioneer3at_demo)  
    * https://github.com/m-shimizu/RoboCup2016RVRL_FieldModels  
    * models from https://github.com/m-shimizu/RoboCupRescuePackage

## Robots.  
You can use the pioneer3at robot. It has a camera and a hokuyo laser range finder.  
In this demo, automatically 4 pioneer3at robots will be spawned.  
You can see topics which will be published from robots with a ros command "rostopic list".  

## Controlling robots with joy stick.  
For this demo, I prepared a ros package "teleop_joy".  
With teleop_joy, you can controll a robot by using a game coontoller.
You can use just only the left analog stick.

## How to setup.  
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

Now, you can see 4 robots on a field.  
Next you have to execute a robot controller.  

  At Terminal2:  
    $ cd ~/RoboCup2016RVRL_Demo  
    $ source install/setup.bash  
    $ roslaunch teleop_joy teleop_joy robot_name:=robot1  

## How to stop the simulation.
    (On the terminal which you did "roslauch rc2016rvrl RC2016VRL_Final_RUN2_RETRY.launch")
    * Push CTRL-Z  
    $ killall -9 roscore gzserver gzclient  
