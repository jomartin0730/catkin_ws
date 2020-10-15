#include <ros/ros.h>
#include <turtlesim/TeleportAbsolute.h>

bool calculation(turtlesim::TeleportAbsolute::Request & req, turtlesim::TeleportAbsolute::Response & res)
{
	for(int i=0; i<11; i++)
	{
		req.x++;
//		res.x = req.x;
		for(int j=0; j<11; j++)
		{
			req.y++;
//			res.x = req.x;
		}
	}
	
	ROS_INFO("request: x=%.1lf, y=%.1lf", req.x, req.y);
//	ROS_INFO("sending back response: x=%.1lf, y=%.1lf", res.x, res.y);
	
	return true;
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "teleport_server");
	ros::NodeHandle nh;
	
	ros::ServiceServer moving_turtle_server = nh.advertiseService("turtle1/teleport_absolute_srv", calculation);
	ros::Rate rate(2);
//	while(ros::ok()){
//	turtlesim::TeleportAbsolute srv;
//	moving_turtle_server.req(srv);
	ROS_INFO("ready srv server!");
	
	ros::spin();
//	rate.sleep();
//	}
	return 0;
}
