#include <rclcpp/rclcpp.hpp>
#include <iostream>

class NodeB : public rclcpp::Node {
public:
    NodeB() : Node("node_b") {
        RCLCPP_INFO(this->get_logger(), "Hello: node_b");
    }
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NodeB>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

