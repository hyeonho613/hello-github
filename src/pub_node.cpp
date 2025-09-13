#include "test/pub_node.hpp"

PubNode::PubNode() : Node("pub_node")
{
    publisher_ = this->create_publisher<std_msgs::msg::Float64>("topic", 10);
    sub_shutdown_ = this->create_subscription<std_msgs::msg::Int32>("shutdown_status", 10,
        std::bind(&PubNode::shutdown_callback, this, std::placeholders::_1));

    timer_ = this->create_wall_timer(std::chrono::milliseconds(10), 
        std::bind(&PubNode::timer_callback, this));
}

void PubNode::timer_callback()
{
    std_msgs::msg::Float64 msg;
    msg.data = 0.0;
    publisher_->publish(msg);
}

void PubNode::shutdown_callback(const std::shared_ptr<std_msgs::msg::Int32> msg)
{
    if (msg->data == 1) {
        RCLCPP_INFO(this->get_logger(), "Publisher shutdown!");
        rclcpp::shutdown();
    }
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PubNode>());
    rclcpp::shutdown();
    return 0;
}