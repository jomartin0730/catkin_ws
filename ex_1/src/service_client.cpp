#include <ros/ros.h>
#include "ex_msgs/SrvTutorial.h"

#include <cstdlib>
 
int main(int argc, char **argv)
{
	ros::init(argc,argv, "service_client");
	
	if(argc != 3)
	{
		ROS_INFO("cmd : rosrun ex_1 service_client arg0 arg1");
		ROS_INFO("arg0 : double number, arg1 : double number");
		return 1;
	}
	
	ros::NodeHandle nh;
	
	ros::ServiceClient ex_1_client = nh.serviceClient<ex_msgs::SrvTutorial>("ex_msgs_srv");
	ex_msgs::SrvTutorial srv;
	
	srv.request.a = atoll(argv[1]);
	srv.request.b = atoll(argv[2]);
	
	if(ex_1_client.call(srv))
	{
		ROS_INFO("send srv, srv.Request.a and b: %ld, %ld", (long)srv.request.a, (long)srv.request.b);
		ROS_INFO("receive srv, srv.Response.result: %ld", (long)srv.response.result);
	}
	else
	{
		ROS_ERROR("Failed to go call service ex_msgs_srv");
		return 1;
	}
	return 0;
}
