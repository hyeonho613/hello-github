#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"
#include "std_msgs/msg/int32.hpp"
#include <chrono>

class PubNode : public rclcpp::Node
{
public:
    PubNode();

private:
    std::shared_ptr<rclcpp::Publisher<std_msgs::msg::Float64>> publisher_;
    std::shared_ptr<rclcpp::Subscription<std_msgs::msg::Int32>> sub_shutdown_;
    std::shared_ptr<rclcpp::TimerBase> timer_;

    void timer_callback();
    void shutdown_callback(const std::shared_ptr<std_msgs::msg::Int32> msg);
};