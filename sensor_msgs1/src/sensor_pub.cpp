#include <ros/ros.h>
#include <sensor_msgs/Range.h>

int main(int argc, char **argv) {
    ros::init(argc, argv, "sensor_Range_node");
    ros::NodeHandle nh;
    ros::Publisher sensor_pub = nh.advertise<sensor_msgs::Range>("/Range", 1000);
//    heart_first_stop_time = ros::Time::now();

    ros::Rate rate(2);     
    sensor_msgs::Range msg;

    while(ros::ok()) {
    	sensor_msgs::Range msg;
        msg.header.frame_id = "/map";
        msg.min_range = 0.1;
        msg.max_range = 10.0;
        msg.range = 5.0;
        ROS_INFO("Send range data to rviz");            

        ROS_INFO_STREAM("Sending range data command:"<<" minimum="<<msg.min_range<<" maximum="<<msg.max_range);
        sensor_pub.publish(msg); 
        rate.sleep();
    }

    return 0;
}

