#ifndef PIPELINE_NODELET_2__MY_NODES_H_
#define PIPELINE_NODELET_2__MY_NODES_H_

#include "ros/ros.h"
#include "pipeline_nodelet_2/helper.h"
#include <iostream>
#include <nodelet/nodelet.h>
#include "std_msgs/UInt8.h"

namespace pipeline_nodelet_2{

    class Level1 : public nodelet::Nodelet{
    public:
	Level1(){
	    NODELET_INFO("Level1 node contructed\n");
	};
	~Level1(){
	    NODELET_INFO("Level1 node destrcuted\n");
	}; 
	virtual void onInit();

    private:
	ros::Publisher pub;
	ros::Timer timer;
	unsigned char count=0;
	void timerCallback(const ros::TimerEvent& event);
    };

    class Level2 : public nodelet::Nodelet{
    public:
	Level2(){
	    NODELET_INFO("Level2 node contructed\n");
	};
	~Level2(){
	    NODELET_INFO("Level2 node destructed\n");
	};
	virtual void onInit();
    private:
	ros::Publisher pub;
	ros::Subscriber sub;
	void drain_callback(const std_msgs::UInt8::ConstPtr& msg);
    };

    class Level3 : public nodelet::Nodelet{
    public:
	Level3(){
	    NODELET_INFO("Level3 node contructed\n");
	};
	~Level3(){
	    NODELET_INFO("Level3 node destructed\n");
	};
	virtual void onInit();
    private:
	ros::Subscriber sub;
	void drain_callback(const std_msgs::UInt8::ConstPtr& msg);
    };
    
}


#endif
