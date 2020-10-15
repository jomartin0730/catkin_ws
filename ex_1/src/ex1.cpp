  #include <ros/ros.h>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "ex1");

	ros::NodeHandle n;

	ros::Rate rate(1);

	while(ros::ok())
	{
		ROS_INFO("hello");

		rate.sleep();
	}
	return 0;
}
