#include "ros/ros.h"
#include "pipeline_nodelet_2/helper.h"
#include "pipeline_nodelet_2/my_nodes.h"
#include <iostream>
#include <nodelet/nodelet.h>
#include "std_msgs/UInt8.h"

namespace pipeline_nodelet_2{
    void Level2::onInit(){
	ros::NodeHandle& n = getPrivateNodeHandle();
	sub = n.subscribe("pipe_l1_output", 5, &Level2::drain_callback, this);
	pub = n.advertise<std_msgs::UInt8>("pipe_l2_output", 5);
	NODELET_INFO("Level2 node created\n");
    }

    void Level2::drain_callback(const std_msgs::UInt8::ConstPtr& msg){
	std_msgs::UInt8 new_msg;
	new_msg.data = (msg->data)*2;
	pub.publish(new_msg);
    }


}
