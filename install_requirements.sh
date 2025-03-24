######
# Install Ros2 Jazzy
######
## Set locale
locale  # check for UTF-8
sudo apt update && sudo apt install locales
sudo locale-gen en_US en_US.UTF-8
sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
export LANG=en_US.UTF-8

## Add the ROS 2 apt repository
sudo apt install software-properties-common
sudo add-apt-repository universe
sudo apt update && sudo apt install curl -y
sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null

## Update package lists and install ROS 2 Jazzy
sudo apt update
sudo apt upgrade -y
sudo apt install ros-jazzy-desktop -y

## Install development tools and ROS tools
sudo apt install -y \
  python3-pip \
  python3-colcon-common-extensions \
  python3-rosdep \
  python3-vcstool

## Initialize rosdep
sudo rosdep init
rosdep update

######
## Source ROS 2 environment
######
echo "source /opt/ros/jazzy/setup.bash" >> ~/.bashrc
source ~/.bashrc

######
# Install Ros2 Dependencies
######

## Others Tools
sudo apt install python3-colcon-common-extensions

## Install rviz2
sudo apt install ros-jazzy-rviz2 -y

## Install Gazebo Ros
sudo apt install ros-jazzy-gazebo-* -y
sudo apt-get install ros-jazzy-ros-gz
### Tools
sudo apt install ros-jazzy-joint-state-publisher-gui

##  QT5
sudo apt install qtbase5-dev libqt5svg5-dev libzmq3-dev libdw-dev -y

## BehaviorTree
sudo apt-get install ros-jazzy-behaviortree-cpp-v3 -y

## Navigation NAV2
sudo apt-get install ros-jazzy-navigation2 ros-jazzy-nav2-bringup -y

######
# Install Project Dependencies
######
# Camera USB
sudo apt install ros-jazzy-v4l2-camera -y
sudo apt install ros-jazzy-cv-bridge ros-jazzy-image-transport -y

