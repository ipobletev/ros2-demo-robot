#include <rclcpp/rclcpp.hpp>
#include <behaviortree_cpp_v3/bt_factory.h>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

class BehaviorNode : public rclcpp::Node {
public:
    BehaviorNode() : Node("behavior_node") {
        RCLCPP_INFO(this->get_logger(), "Behavior Node (BehaviorNode) initialized.");
        timer_ = this->create_wall_timer(1s, std::bind(&BehaviorNode::timer_callback, this));
    }

private:
    void timer_callback() {
        RCLCPP_INFO(this->get_logger(), "Behavior Node alive!");
    }
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<BehaviorNode>();

    BT::BehaviorTreeFactory factory;

    // Register local actions
    factory.registerSimpleAction("node_a", [](BT::TreeNode& tree_node) -> BT::NodeStatus {
        RCLCPP_INFO(rclcpp::get_logger("node_a"), "Executing node_a");
        return BT::NodeStatus::SUCCESS;
    });

    factory.registerSimpleAction("node_b", [](BT::TreeNode& tree_node) -> BT::NodeStatus {
        RCLCPP_INFO(rclcpp::get_logger("node_b"), "Executing node_b");
        return BT::NodeStatus::SUCCESS;
    });

    // Register subtrees
    factory.registerBehaviorTreeFromFile("src/behavior/behavior_trees/bt_node_a.xml");
    factory.registerBehaviorTreeFromFile("src/behavior/behavior_trees/bt_node_b.xml");
    factory.registerBehaviorTreeFromFile("src/behavior/bt_main.xml");
    
    // Create the main tree using its ID, as the subtrees have been registered
    auto tree = factory.createTree("bt_main");

    while (rclcpp::ok() && tree.rootNode()->status() != BT::NodeStatus::SUCCESS)
    {
        tree.tickRoot();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}