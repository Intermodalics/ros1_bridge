// Copyright 2015 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <iostream>

#include <rclcpp/rclcpp.hpp>

#include <std_interfaces/msg/string.hpp>


void chatterCallback(const std_interfaces::msg::String::ConstSharedPtr & msg)
{
  std::cout << "I heard: [" << msg->data << "]" << std::endl;
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  auto node = rclcpp::Node::make_shared("listener");

  auto sub = node->create_subscription<std_interfaces::msg::String>(
    "chatter", rmw_qos_profile_default, chatterCallback);

  rclcpp::spin(node);

  return 0;
}
