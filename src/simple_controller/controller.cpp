#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	
//Initializes ROS, and sets up a node
ros::init(argc, argv, "controller");
ros::NodeHandle nh;

//Ceates the publisher, and tells it to publish

//to the husky_velocity_controller/cmd_vel topic, with a queue size of 100
ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("/cmd_vel", 100);

//Sets up the random number generator
srand(time(0));

//Sets the loop to publish at a rate of 10Hz
ros::Rate rate(10);
int count = 0;
bool forward = true;

  while(ros::ok()) {
    //Declares the message to be sent
    geometry_msgs::Twist msg;
    //Random x value between -2 and 2
	
  msg.linear.x= 1.0;
  
  
    //Random y value between -3 and 3
    msg.angular.z= 3.0;
	
    //Publish the message
    pub.publish(msg);
	
    //Delays until it is time to send another message
    rate.sleep();
    }
}