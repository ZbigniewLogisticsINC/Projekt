#!/bin/bash 

source /opt/ros/indigo/setup.bash
cd ../src
catkin_init_workspace
cd ..
catkin_make 

ls devel


# tę linijkę trzeba dodać samodzielnie
#source devel/setup.bash
