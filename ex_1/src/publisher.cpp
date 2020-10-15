#include <ros/ros.h>
//#include <std_msgs/Int32.h>
#include <ex_msgs/test1.h>
// std_msgs에서 Int형 헤더파일 추가
int main(int argc, char **argv)
{
  ros::init(argc, argv, "publisher_node");
  ros::NodeHandle n;
// Publish 동작을 위한 정보등록[ Topic 형식, Topic 이름, 큐 사이즈]
  ros::Publisher msg_pub = n.advertise<ex_msgs::test1>("ros_msg", 1);
// 동작주기 설정: 1hz
  ros::Rate rate(1);
// 변수 데이터 생성
//  std_msgs::Int32 msg;
  ex_msgs::test1 msg;
  int count = 0;
// 루프시작
  while (ros::ok())
  {
    msg.a  = count;
    msg.b  = count;
    msg.c  = count;

    ROS_INFO("send msg = %d %d %d", msg.a, msg.b, msg.c);
    msg_pub.publish(msg);

    rate.sleep();
    count++;
  }
  return 0;
}
