#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"
#include "std_msgs/msg/int32.hpp"

class SubNode : public rclcpp::Node
{
public:
    SubNode();
private:
    std::shared_ptr<rclcpp::Subscription<std_msgs::msg::Float64>> subscriber_;
    std::shared_ptr<rclcpp::Publisher<std_msgs::msg::Int32>> pub_shutdown_;

    void topic_callback(const std::shared_ptr<std_msgs::msg::Float64> msg);

    double counter_ = 0.0;
    int is_shutdown_ = 0;
};