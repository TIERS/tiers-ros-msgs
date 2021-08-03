cmake_minimum_required(VERSION 3.0.2)
project(tiers_ros_msgs)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  mavros_msgs
  nav_msgs
  roscpp
  sensor_msgs
  std_msgs
  message_generation
)

################################################
## Declare ROS messages, services and actions ##
################################################

## Generate messages
# add_message_files(
#   DIRECTORY msg/offboard_control
#   FILES
#   flight_mode.msg
# )

# Generate services
add_service_files(
  DIRECTORY srv/offboard_control
  FILES
  flight_mode.srv
  offboard_state.srv
)

## Generate actions in the 'action' folder
add_action_files(
  DIRECTORY action/mrs_uwb_sim
  FILES
  FlyTask.action
)

## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  geometry_msgs
  mavros_msgs
  nav_msgs
  sensor_msgs
  std_msgs
)

###################################
## catkin specific configuration ##
###################################
catkin_package(
  LIBRARIES tiers_ros_msgs
  CATKIN_DEPENDS geometry_msgs mavros_msgs nav_msgs roscpp sensor_msgs std_msgs
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  ${catkin_INCLUDE_DIRS}
)

## C++ dummy test node
add_library(
  ${PROJECT_NAME}
  src/dummy.cpp
)

## Add cmake target dependencies
add_dependencies(
  ${PROJECT_NAME} 
  ${${PROJECT_NAME}_EXPORTED_TARGETS} 
  ${catkin_EXPORTED_TARGETS}
)

## Declare C++ executables
add_executable(
  ${PROJECT_NAME}_node 
  src/dummy.cpp
)

## Add cmake target dependencies of the executable
add_dependencies(
  ${PROJECT_NAME}_node 
  ${${PROJECT_NAME}_EXPORTED_TARGETS} 
  ${catkin_EXPORTED_TARGETS}
)

## Specify libraries to link a library or executable target against
target_link_libraries(
  ${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
)

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executables and/or libraries for installation
install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}_node
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
