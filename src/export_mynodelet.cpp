#include <pluginlib/class_list_macros.h>
#include <nodelet/nodelet.h>
#include "pipeline_nodelet_2/my_nodes.h"

PLUGINLIB_EXPORT_CLASS(pipeline_nodelet_2::Level1, nodelet::Nodelet);
PLUGINLIB_EXPORT_CLASS(pipeline_nodelet_2::Level2, nodelet::Nodelet);
PLUGINLIB_EXPORT_CLASS(pipeline_nodelet_2::Level3, nodelet::Nodelet);
