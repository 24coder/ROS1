#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"

void poseCallback(const std_msgs::String& msg)
 
{
    ROS_INFO("I accept the message from publisher:%s", msg.data.c_str());
}



int main(int argc, char **argv)
{
    int count=0;
    // ROS节点初始化
    ros::init(argc, argv, "publisher_subscriber");
 
    // 创建节点句柄kbk
    ros::NodeHandle nh;
    // 创建一个Subscriber
    ros::Subscriber sub = nh.subscribe("pub_sub", 1000, poseCallback);
    // 创建一个Publisher，发布名为vel_pub的topic，消息类型为std_msgs::String
    ros::Publisher vel_pub = nh.advertise<std_msgs::String>("pub_sub",10);
    
    // 设置循环的频率
    ros::Rate loop_rate(1000);
    ROS_INFO("pub and sub start...");
    while (ros::ok())
    {
        // 初始化std_msgs 类型的消息
        
        std_msgs::String msg;
    	std::stringstream ss;
    	ss << "i am ready to send messages:  are you ready!!! " <<count;
    	msg.data = ss.str();
	// 发布消息
        vel_pub.publish(msg);
         
    	//ROS_INFO("%s", msg.data.c_str());

        // 按照循环频率延时
        loop_rate.sleep();
        count++;
        ros::spinOnce();
    }
   
   return 0;
}
