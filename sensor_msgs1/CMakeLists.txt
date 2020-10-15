cmake_minimum_required(VERSION 3.0.2)
project(sensor_msgs1)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
)

add_message_files(
   FILES
   test_msg.msg
#   Message2.msg
)

# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

# generate_messages(
#   DEPENDENCIES
#   std_msgs
# )

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES sensor_msgs
  CATKIN_DEPENDS roscpp 
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(sensor_pub_node src/sensor_pub.cpp)
add_dependencies(sensor_pub_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(sensor_pub_node ${catkin_LIBRARIES})

