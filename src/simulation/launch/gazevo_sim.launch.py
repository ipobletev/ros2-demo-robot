#!/usr/bin/env python3
import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess, IncludeLaunchDescription
from launch.substitutions import LaunchConfiguration, Command, FindPackageShare
from launch_ros.actions import Node

def generate_launch_description():
    # Declare arguments
    world_arg = DeclareLaunchArgument(
        'world',
        default_value=os.path.join(FindPackageShare('simulation').find('simulation'), 'worlds', 'demo.world'),
        description='Path to Gazebo world file'
    )
    urdf_arg = DeclareLaunchArgument(
        'urdf_path',
        default_value=os.path.join(FindPackageShare('description').find('description'), 'urdf', 'robot.urdf.xacro'),
        description='Path to robot URDF file'
    )
    rviz_arg = DeclareLaunchArgument(
        'rviz_config_path',
        default_value=os.path.join(FindPackageShare('description').find('description'), 'rviz', 'urdf_config.rviz'),
        description='Path to RViz config file'
    )

    # Nodes
    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[{'description': Command(['xacro ', LaunchConfiguration('urdf_path')])}],
        output='screen'
    )

    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        arguments=['-d', LaunchConfiguration('rviz_config_path')],
        output='screen'
    )

    # Launch Gazebo executables directly (gzserver and gzclient)
    gzserver = ExecuteProcess(
        cmd=['gzserver', LaunchConfiguration('world')],
        output='screen'
    )
    gzclient = ExecuteProcess(
        cmd=['gzclient'],
        output='screen'
    )

    return LaunchDescription([
        world_arg,
        urdf_arg,
        rviz_arg,
        robot_state_publisher_node,
        rviz_node,
        gzserver,
        gzclient
    ])