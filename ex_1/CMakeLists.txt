cmake_minimum_required(VERSION 3.0.2)
project(ex_1)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  ex_msgs
  message_generation
)
#add_message_files(
#   DIRECTORY msg
#   FILES    test1.msg
#			SrvTutorial.srv
#)

## Generate services in the 'srv' folder
# add_service_files(
#   DIRECTORY srv
#   FILES
#   Service1.srv
#   Service2.srv
# )

#generate_messages(
#   DEPENDENCIES
#   std_msgs  # Or other packages containing msgs
#)

catkin_package(
	CATKIN_DEPENDS roscpp std_msgs
#  INCLUDE_DIRS include
	LIBRARIES ex_1
	LIBRARIES ex_msgs
#  DEPENDS system_lib
)
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(ex1 src/ex1.cpp)
add_dependencies(ex1 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(ex1 ${catkin_LIBRARIES})

add_executable(publisher_node src/publisher.cpp)
add_dependencies(publisher_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(publisher_node ${catkin_LIBRARIES})

add_executable(subscriber_node src/subscriber.cpp)
add_dependencies(subscriber_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(subscriber_node ${catkin_LIBRARIES})

#service_server
add_executable(service_server src/service_server.cpp)
add_dependencies(service_server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(service_server ${catkin_LIBRARIES})

#service_client
add_executable(service_client src/service_client.cpp)
add_dependencies(service_client ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(service_client ${catkin_LIBRARIES})

