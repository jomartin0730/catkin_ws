cmake_minimum_required(VERSION 3.0.2)
project(ex_msgs)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  std_msgs
)

add_message_files(
	DIRECTORY msg
	FILES
	
	test1.msg
)


add_service_files(
	DIRECTORY srv	
	FILES 

	SrvTutorial.srv
 )

#add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )


generate_messages(
   DEPENDENCIES std_msgs
 )

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES ex_msgs
  CATKIN_DEPENDS std_msgs message_runtime
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)
