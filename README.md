# Automated Object Placement Robot

This ROS2-based project implements an autonomous robot system capable of automatically picking up and placing objects at specified locations.

## Features

- Autonomous navigation in indoor environments
- Object detection and recognition
- Pick and place capabilities
- Path planning and obstacle avoidance
- Integration with RViz2 for visualization
- Gazebo simulation support

## Prerequisites

- Ubuntu 24.04 Noble
- ROS2 Jazzy
- Gazebo
- RViz2
- Additional ROS2 dependencies (see install_requirements.sh)

## Installation

1. Install ROS2 and dependencies

    sudo chmod -R 770 ./install_requirements.sh
    ./install_requirements.sh
    source ./install/setup.bash

2- Install BehaviorTree.CPP
    
    https://github.com/BehaviorTree/BehaviorTree.CPP
    cd ./src/3rdparty/BehaviorTree.CPP
    mkdir build; cd build
    cmake ..
    make
    sudo make install

## Main Execution

    ros2 launch robot_bringup main_robot.launch.xml

## Description RVIZ Execution

    ros2 launch description display.launch.xml

## Simulation Gazebo Execution (dont work yet)

    ros2 launch description gazebo_sim.launch.xml gz_args:="/home/ismael/Desktop/ros2-demo-robot/src/description/worlds/test_gz_world.sdf"
    
## Others executions

    # Sensors

    ## RPLidar
    ros2 launch rplidar_ros view_rplidar_a1_launch.py
    ros2 run rplidar_ros rplidar_node

    ## Camera usb execucion
    ros2 run usb_camera usb_camera_node


## Flow


## Others  

In VM if gazebo screen flickering then use

    export LIBGL_ALWAYS_SOFTWARE=1

# Project Structure

The project is organized into the following directories:

- `src/`: Main source code directory
  - `behavior/`: Behavior tree XML definitions and configurations
  - `description/`: Robot URDF description and meshes
  - `robot_bringup/`: Launch files and configuration for bringing up the robot
  - `3rdparty/`: Third-party dependencies