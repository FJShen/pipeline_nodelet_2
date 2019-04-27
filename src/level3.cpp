#include "ros/ros.h"
#include "pipeline_nodelet_2/helper.h"
#include "pipeline_nodelet_2/my_nodes.h"
#include <iostream>
#include <nodelet/nodelet.h>
#include "std_msgs/UInt8.h"

namespace pipeline_nodelet_2{
    void Level3::onInit(){
	ros::NodeHandle& n = getPrivateNodeHandle();
	sub = n.subscribe("pipe_l2_output", 5, &Level3::drain_callback, this);
	NODELET_INFO("Level3 node created\n");
    }

    void Level3::drain_callback(const std_msgs::UInt8::ConstPtr& msg){
	helper::print_time_stamp("pipe_level3");
	NODELET_INFO("\n");
	std::stringstream ss;
	ss<<"received "<<(unsigned int)(msg->data)<<"\n";
	std::string myStr = ss.str();
	const char* c = myStr.c_str();
	NODELET_INFO(c);
    };


}
