#include "test/sub_node.hpp"

SubNode::SubNode() : Node("sub_node")
{
    subscriber_ = this->create_subscription<std_msgs::msg::Float64>("topic", 10,
        std::bind(&SubNode::topic_callback, this, std::placeholders::_1));

    pub_shutdown_ = this->create_publisher<std_msgs::msg::Int32>("shutdown_status", 10);
}

void SubNode::topic_callback(const std::shared_ptr<std_msgs::msg::Float64> msg)
{
    double result = counter_ + msg->data;
    RCLCPP_INFO(this->get_logger(), "%f", result);
    counter_++;

    if (counter_ > 100.0) {
        is_shutdown_ = 1;
        RCLCPP_INFO(this->get_logger(), "Subscriber shutdown!");

        std_msgs::msg::Int32 shutdown_msg;
        shutdown_msg.data = is_shutdown_;
        pub_shutdown_->publish(shutdown_msg);
        
        rclcpp::shutdown();
    }
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SubNode>());
    rclcpp::shutdown();
    return 0;
}