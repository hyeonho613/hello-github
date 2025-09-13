cmake_minimum_required(VERSION 3.8)
project(test)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(pub_node src/pub_node.cpp)
add_executable(sub_node src/sub_node.cpp)

target_include_directories(pub_node
  PUBLIC include
)

target_include_directories(sub_node
  PUBLIC include
)

ament_target_dependencies(pub_node
  rclcpp
  std_msgs
)

ament_target_dependencies(sub_node
  rclcpp
  std_msgs
)

install(TARGETS pub_node
  DESTINATION lib/${PROJECT_NAME}
)

install(TARGETS sub_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
