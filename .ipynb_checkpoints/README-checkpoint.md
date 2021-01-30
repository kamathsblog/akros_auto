# akros_auto
Autonomous nodes for the AKROS project

### Description
ROS node with different autonomous functionalities. Every script/executable within this node publishes a twist message with linear and angular velocity. The following Python scripts are provided:
* edge_avoidance.py

### Model
The collision avoidance model is stored in the scripts directory. In this case, its edge_avoidance.pth.

### Publishers
Each script within this package publishes a cmd_vel topic
* `/auto_node/cmd_vel`: Twist output like the teleop_twist_keyboard package


