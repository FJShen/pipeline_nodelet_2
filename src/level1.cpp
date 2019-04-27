#include "ros/ros.h"
#include "pipeline_nodelet_2/helper.h"
#include "pipeline_nodelet_2/my_nodes.h"
#include <iostream>
#include <nodelet/nodelet.h>
#include "std_msgs/UInt8.h"

namespace pipeline_nodelet_2{
    void Level1::onInit(){
	ros::NodeHandle& n = getPrivateNodeHandle();
	pub = n.advertise<std_msgs::UInt8>("pipe_l1_output", 5);
	timer = n.createTimer(ros::Duration(0.25), &Level1::timerCallback, this);
	NODELET_INFO("Level1 node created\n");
    }

    void Level1::timerCallback(const ros::TimerEvent& event){
	ROS_INFO("timeout triggered\n");
	std_msgs::UInt8 msg;
	msg.data = count;
	pub.publish(msg);
	count+=1;
    }


}
