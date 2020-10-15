#include <ros/ros.h>
//#include <std_msgs/Int32.h>
#include <geometry_msgs/Twist.h>
// std_msgs에서 Int형 헤더파일 추가

int main(int argc, char **argv)
{
  ros::init(argc, argv, "publisher_velocity");
  ros::NodeHandle nh;
// Publish 동작을 위한 정보등록[ Topic 형식, Topic 이름, 큐 사이즈]
  ros::Publisher msg_pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);
  
  srand(time(0));
// 동작주기 설정: 1hz
  ros::Rate rate(1);
// 변수 데이터 생성
//  std_msgs::Int32 msg;
  
// 루프시작
	while(ros::ok()){
		geometry_msgs::Twist msg;
		msg.linear.x = double(rand())/double(RAND_MAX);
		
		msg.angular.z = 2*double(rand())/double(RAND_MAX) - 1;

		msg_pub.publish(msg);

		ROS_INFO_STREAM("Sending random velocity command:"<<" linear="<<msg.linear.x<<" angular="<<msg.angular.z);

		rate.sleep();
	}
}
