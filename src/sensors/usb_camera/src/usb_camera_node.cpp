#include <rclcpp/rclcpp.hpp>
#include <cv_bridge/cv_bridge.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <opencv2/opencv.hpp>

class USBCameraNode : public rclcpp::Node {
public:
    USBCameraNode() : Node("usb_camera_node") {
        publisher_ = this->create_publisher<sensor_msgs::msg::Image>("camera/image", 10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(1000), 
            std::bind(&USBCameraNode::capture_image, this));
        cap_.open(0); // Camera 
    }

private:
    void capture_image() {
        cv::Mat frame;
        cap_ >> frame; // Capture an image from the camera
        if (!frame.empty()) {
            auto msg = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", frame).toImageMsg();
            publisher_->publish(*msg);
        }
    }

    cv::VideoCapture cap_;
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<USBCameraNode>());
    rclcpp::shutdown();
    return 0;
}