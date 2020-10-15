cmake_minimum_required(VERSION 3.0.2)
project(moving_turtle)


find_package(
	catkin REQUIRED COMPONENTS
#	geometry_msgs
	turtlesim
	roscpp
)
## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
#add_service_files(
#  FILES
#   TeleportAbsolute.srv
#)

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
# generate_messages(
#   DEPENDENCIES
#   geometry_msgs
# )

catkin_package(
#  INCLUDE_DIRS include
#	LIBRARIES moving_turtle
	CATKIN_DEPENDS  roscpp
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(turtle_pub_node src/turtlesim_pub.cpp)
add_dependencies(turtle_pub_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(turtle_pub_node ${catkin_LIBRARIES})

#service_server
add_executable(teleport_server src/moving_server.cpp)
add_dependencies(teleport_server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(teleport_server ${catkin_LIBRARIES})

#service_client
add_executable(teleport_client src/moving_client.cpp)
add_dependencies(teleport_client ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(teleport_client ${catkin_LIBRARIES})

