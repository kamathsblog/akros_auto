/*
==========
ROS node for control using a SixAxis Joystick. The ROS joy package is needed.
This code implements the following functionality:
  > Subscribe to ROS Deep Learning node - probability of edge being detected
  > Calculate linear/angular velocities based on the probability
  > Publish twist message
by Aditya Kamath
adityakamath.github.io
github.com/adityakamath
==========
*/

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Int8.h>

class EdgeAvoidance
{
public:
    EdgeAvoidance();
    
private:
    //void probCallback(const sensor_msgs::Joy::ConstPtr& joy); //change message type
    
    int l_scale, a_scale;
    
    ros::NodeHandle nh;

    //ros::Subscriber dl_sub;
    ros::Publisher  autovel_pub;
};

EdgeAvoidance::EdgeAvoidance():
    l_scale(7),
    a_scale(6)
{
    if(nh.hasParam("/edge_avoidance")){
        nh.param("lpad_ud",  l_scale, l_scale); 
        nh.param("lpad_lr",  a_scale, a_scale); 
        ROS_INFO("[EDG] Loaded config from parameter server");
    }
        
    autovel_pub  = nh.advertise<geometry_msgs::Twist>("/auto_node/cmd_vel", 1);
    
    //dl_sub  = nh.subscribe<sensor_msgs::Joy>("joy", 5, &EdgeAvoidance::probCallback, this); //change message type       
}

/*void EdgeAvoidance::probCallback(const sensor_msgs::Joy::ConstPtr& joy) //change message type
{
    geometry_msgs::Twist twist;
    
    // publish velocities
    if(prob_blocked<0.4){ //not blocked
        twist.linear.x  = 1.0*l_scale;
        twist.angular.z = 0.0*a_scale;
    }
    else{ //blocked
        twist.linear.x  = 0.0*l_scale;
        twist.angular.z = 1.0*a_scale;
    }
    autovel_pub.publish(twist);
}*/

int main(int argc, char** argv)
{
    ros::init(argc, argv, "edge_avoidance");
    EdgeAvoidance edge_avoidance;
    ROS_INFO("[EDG] Edge Avoidance node initialized");
    ros::spin();
}