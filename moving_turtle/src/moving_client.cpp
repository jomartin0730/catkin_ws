#include <ros/ros.h>
#include <turtlesim/TeleportAbsolute.h>
#include <cstdlib>

int main(int argc, char **argv)
{
	ros::init(argc,argv, "teleport_client");
	
	if(argc != 3)
	{
		ROS_INFO("cmd : rosrun movingturtle service_client arg0 arg1");
		ROS_INFO("arg0 : double number, arg1 : double number");
		return 1;
	}
	
	ros::NodeHandle nh;
	
	ros::ServiceClient moving_turtle_client = nh.serviceClient<turtlesim::TeleportAbsolute>("turtle1/teleport_absolute_srv");
	
	turtlesim::TeleportAbsolute srv;
	
	
	srv.request.x = atof(argv[1]);
	srv.request.y = atof(argv[2]);
	
	if(moving_turtle_client.call(srv))
	{
		ROS_INFO("send srv, srv.Request.x and y: %.1lf, %.1lf", srv.request.x, srv.request.y);
//		ROS_INFO("receive srv, srv.Response.result: %.1lf, %.1lf", srv.response.x, srv.response.y);
	}
	else
	{
		ROS_ERROR("Failed to go call service moving_turtle_srv");
		return 1;
	}
	return 0;
}
