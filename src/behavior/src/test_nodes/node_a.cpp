#include <rclcpp/rclcpp.hpp>
#include <iostream>

class NodeA : public rclcpp::Node {
public:
    NodeA() : Node("node_a") {
        RCLCPP_INFO(this->get_logger(), "Hello: node_a");
    }
};

// int main(int argc, char **argv) {
//     rclcpp::init(argc, argv);
//     auto node = std::make_shared<NodeA>();
//     rclcpp::spin(node);
//     rclcpp::shutdown();
//     return 0;
// }

