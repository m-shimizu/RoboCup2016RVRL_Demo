#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>


class TeleopJoy
{
public:
  TeleopJoy();
  ~TeleopJoy() {} ;
private:
  void JoyCB(const sensor_msgs::Joy::ConstPtr& joy);
  ros::NodeHandle _nh;
  int             _linear, _angular;
  double          _scale_l, _scale_a;
  std::string     _cmd_vel_tpc;
  ros::Publisher  twist_pub;
  ros::Subscriber joy_sub;
};


TeleopJoy::TeleopJoy():
  _linear(1),
  _angular(2)
{
  _nh.param("axis_linear", _linear, _linear);
  _nh.param("axis_angular", _angular, _angular);
  _nh.param("scale_angular", _scale_a, _scale_a);
  _nh.param("scale_linear", _scale_l, _scale_l);
  _nh.param("cmd_vel", _cmd_vel_tpc, std::string("/cmd_vel"));
  twist_pub = _nh.advertise<geometry_msgs::Twist>(_cmd_vel_tpc.c_str(), 1);
  joy_sub = _nh.subscribe<sensor_msgs::Joy>("joy", 10
                                         , &TeleopJoy::JoyCB, this);
}

void TeleopJoy::JoyCB(const sensor_msgs::Joy::ConstPtr& joy)
{
  geometry_msgs::Twist twist;
  twist.angular.z = _scale_a*joy->axes[_angular];
  twist.linear.x = _scale_l*joy->axes[_linear];
  twist_pub.publish(twist);
}


int main(int argc, char** argv)
{
  ros::init(argc, argv, "teleop_joy");
  TeleopJoy teleop_joy;
  ros::spin();
}
