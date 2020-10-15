#include "ros/ros.h"
#include "ex_msgs/SrvTutorial.h"

#define PLUS 1
#define MINUS 2
#define MULTIPLICATION 3
#define DIVISION 4

int g_operator = PLUS;

bool calculation(ex_msgs::SrvTutorial::Request & req, ex_msgs::SrvTutorial::Response & res)
{
	switch(g_operator)
	{
		case PLUS:
			res.result = req.a + req.b;
			break;
		case MINUS:
			res.result = req.a - req.b;
			break;
		case MULTIPLICATION:
			res.result = req.a * req.b;
			break;
		case DIVISION:
			if(req.b = 0)
			{
				res.result = 0;
				break;
			}
			else
			{
				res.result = req.a / req.b;
				break;
			}
		default:
			res.result = req.a + req.b;
			break;
	}
			
	ROS_INFO("request: x=%ld, y=%ld", (long)req.a, (long)req.b);
	ROS_INFO("sending back response: %ld", (long)res.result);
	
	return true;
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "service_server");
	ros::NodeHandle nh;
	nh.setParam("calculation_method", PLUS);
	
	ros::ServiceServer ex_1_server = nh.advertiseService("ex_msgs_srv", calculation);
	
	ROS_INFO("ready srv server!");
	ros::Rate r(10);
	while(1)
	{
		nh.getParam("calculation_method", g_operator);
		ros::spinOnce();
		r.sleep();
	}
	return 0;
}
