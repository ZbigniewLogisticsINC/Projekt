cmake_minimum_required(VERSION 2.8.3)
project(logistic_system)


set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS}")

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})
add_definitions(${Qt5Widgets_DEFINITIONS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")



 add_message_files(FILES )


 add_service_files(FILES )

 generate_messages(DEPENDENCIES std_msgs)

catkin_package()

include_directories(include include/logistic_system/gui include/logistic_system/models)
include_directories(
  ${catkin_INCLUDE_DIRS} 
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
file(GLOB FORMS ui/*.ui)
file(GLOB QOBJECT_HEADERS  include/logistic_system/gui/*.hpp include/logistic_system/models/*Model.hpp)
file(GLOB_RECURSE SRCS src/*.cpp)
file(GLOB RSRCS rsrc/*.qrc)


qt4_wrap_cpp(robot_manager_HEADERS_MOC ${QOBJECT_HEADERS} )
qt4_wrap_ui(robot_manager_FORMS_HEADERS ${FORMS} )
qt4_add_resources(RCC_SRCS ${RSRCS})

add_executable(robot_manager 
  ${robot_manager_HEADERS_MOC} ${SRCS} ${robot_manager_FORMS_HEADERS} ${RCC_SRCS} )
target_link_libraries(robot_manager ${QT_LIBRARIES} ${catkin_LIBRARIES})