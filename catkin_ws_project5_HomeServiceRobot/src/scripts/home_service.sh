#!/bin/sh
xterm -e "source ~/workspace/catkin_ws_project5_HomeServiceRobot/devel/setup.bash; roscore" &
sleep 5
# Launch turtlebot_world.launch, using my custom world
xterm -e "roslaunch turtlebot_gazebo turtlebot_world.launch" &
sleep 5
# Launch the amcl package for navigation using the mapped world or the saved mapped world
xterm -e "roslaunch turtlebot_gazebo amcl_demo_copy.launch" &
sleep 5
# Launch rviz with the visualization of the robot and features
xterm -e "roslaunch turtlebot_rviz_launchers view_navigation.launch" & 
sleep 40
# Run pick_objects node
xterm -e "rosrun pick_objects pick_objects" &
sleep 5
# Run add_markers node
xterm -e "rosrun add_markers add_markers" &
sleep 10
