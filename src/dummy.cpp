#include "ros/ros.h"

int main(int argc, char **argv)
{

    ros::init(argc, argv, "dummy");

    ros::NodeHandle n;

    ROS_INFO("This is a dummy test node.");

    return 0;
}

