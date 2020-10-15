#include <ros/ros.h>
#include <ex_msgs/test1.h>
// std_msgs에서 Int형 헤더파일 추가
void msgCallback(const ex_msgs::test1::ConstPtr& msg)
{// 수신 메시지의 데이터 값 출력
  ROS_INFO("recieve msg = %d %d %d", msg->a, msg->b, msg->c);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "subscriber_node");
  ros::NodeHandle n;
// Subscribe 동작을 위한 정보등록[Topic 이름, 큐 사이즈, 호출함수]
  ros::Subscriber msg_sub = n.subscribe("ros_msg", 1, msgCallback);
// 통신동작 반복 : 수신대기+콜백함수 호출+반복
  ros::spin();

  return 0;
}
