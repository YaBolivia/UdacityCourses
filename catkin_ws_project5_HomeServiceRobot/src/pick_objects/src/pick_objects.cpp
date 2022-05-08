#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

move_base_msgs::MoveBaseGoal setPickupGoalPosition(move_base_msgs::MoveBaseGoal mvg) {
  // set up the frame parameters
  mvg.target_pose.header.frame_id = "map";
  mvg.target_pose.header.stamp = ros::Time::now();

  // Define a position and orientation for the robot to reach
  mvg.target_pose.pose.position.x = 5.8806;
  mvg.target_pose.pose.position.y = -19.6512;
  mvg.target_pose.pose.orientation.z = 0.9999;
  mvg.target_pose.pose.orientation.w = 0.01154;

  return mvg;
}

move_base_msgs::MoveBaseGoal setDropGoalPosition(move_base_msgs::MoveBaseGoal mvg) {
  // set up the frame parameters
  mvg.target_pose.header.frame_id = "map";
  mvg.target_pose.header.stamp = ros::Time::now();

  // Define a position and orientation for the robot to reach
  mvg.target_pose.pose.position.x = -9.5111;
  mvg.target_pose.pose.position.y = 6.2850;
  mvg.target_pose.pose.orientation.z = -0.07222;
  mvg.target_pose.pose.orientation.w = 0.9974;

  return mvg;
}


int main(int argc, char** argv){
  // Initialize the pick_objects node
  ros::init(argc, argv, "pick_objects");

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  //// set up the frame parameters
  // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending goal");
  ac.sendGoal(setPickupGoalPosition(goal));

  // Wait an infinite time for the results
  ac.waitForResult();

  //Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
    ROS_INFO("The robot has reached the virtual pickup position");
    // Send the goal position and orientation for the robot to reach
    ROS_INFO("Sending goal");
    ac.sendGoal(setDropGoalPosition(goal));

    // Wait an infinite time for the results
    ac.waitForResult();

    //Check if the robot reached its goal
    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
      ROS_INFO("The robot has reached the virtual drop position");
  }
  
  if(ac.getState() != actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("The robot failed to move for some reason");

  return 0;
}
