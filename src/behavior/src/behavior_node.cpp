#include <behaviortree_cpp_v3/bt_factory.h>
#include <rclcpp/rclcpp.hpp>
#include <chrono>

using namespace std::chrono_literals;

// Supongamos que ya tienes implementadas las clases NodeA y NodeB.
// Debes definirlas adaptadas para que sean compatibles con BehaviorTreeCPP.

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<BehaviorNode>();

    // Crear la fábrica del Behavior Tree.
    BT::BehaviorTreeFactory factory;

    // Registrar las acciones, asegurándote que las clases coincidan con la definición en el XML.
    factory.registerSimpleAction("NodoA", []() -> BT::NodeStatus {
        RCLCPP_INFO(rclcpp::get_logger("NodoA"), "Ejecutando NodoA");
        return BT::NodeStatus::SUCCESS;
    });

    factory.registerSimpleAction("NodoB", []() -> BT::NodeStatus {
        RCLCPP_INFO(rclcpp::get_logger("NodoB"), "Ejecutando NodoB");
        return BT::NodeStatus::SUCCESS;
    });

    // Cargar el behavior tree desde el archivo XML "bt_main.xml"
    auto tree = factory.createTreeFromFile("src/behavior/bt_main.xml");

    // Ciclo de tick para ejecutar el árbol
    while (rclcpp::ok() && tree.rootNode()->status() != BT::NodeStatus::SUCCESS)
    {
        tree.tickRoot();
        std::this_thread::sleep_for(100ms);
    }

    rclcpp::shutdown();
    return 0;
}