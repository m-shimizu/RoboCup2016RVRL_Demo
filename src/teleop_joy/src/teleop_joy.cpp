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
  std::string     _tpc_cmd_vel, _tpc_joy;
  ros::Publisher  twist_pub;
  ros::Subscriber joy_sub;
};


TeleopJoy::TeleopJoy():
  _linear(1), _angular(2), _scale_l(0.7), _scale_a(1.2)
{
  _nh.param("axis_linear", _linear, _linear);
  _nh.param("axis_angular", _angular, _angular);
  _nh.param("scale_angular", _scale_a, _scale_a);
  _nh.param("scale_linear", _scale_l, _scale_l);
  _nh.param("cmd_vel", _tpc_cmd_vel, std::string("/cmd_vel"));
  _nh.param("joy", _tpc_joy, std::string("/joy"));
  twist_pub = _nh.advertise<geometry_msgs::Twist>(_tpc_cmd_vel.c_str(), 1);
  joy_sub = _nh.subscribe<sensor_msgs::Joy>(_tpc_joy.c_str(), 10
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
