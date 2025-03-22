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

- Ubuntu 22.04
- ROS2 Jazzy
- Gazebo
- RViz2
- Additional ROS2 dependencies (see install_requirements.sh)

## Installation

    sudo chmod -R 770 ./install_requirements.sh
    ./install_requirements.sh
    source ./install/setup.bash

## Ejecution

    

## Others ejecutions

    # Sensors

    ## RPLidar
    ros2 launch rplidar_ros view_rplidar_a1_launch.py

    ## Camera usb ejecucion
    
    ros2 run usb_camera usb_camera_node
