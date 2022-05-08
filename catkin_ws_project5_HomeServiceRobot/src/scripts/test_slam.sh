#!/bin/sh
xterm -e "source ~/workspace/catkin_ws_project5_HomeServiceRobot/devel/setup.bash; roscore" &
sleep 5
# Launch turtlebot_world.launch, using my custom world
xterm -e "roslaunch turtlebot_gazebo turtlebot_world.launch" &
sleep 5
# Launch slam_gmapping for the mapping of the world
xterm -e "rosrun gmapping slam_gmapping" &
sleep 5
# Launch rviz with the visualization of the robot and features
xterm -e "roslaunch turtlebot_rviz_launchers view_navigation.launch" & 
sleep 5
# Launch the keyboard_teleop_twist for manual robot manipulation
# /cmd_vel remapped to /cmd_vel_mux/input/teleop
xterm -e "roslaunch my_robot teleop.launch" &
sleep 5
