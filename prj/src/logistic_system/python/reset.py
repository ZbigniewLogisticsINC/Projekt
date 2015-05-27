#!/usr/bin/env python
#-*- coding: latin2 -*-

import sys
import roslib
import rospy
from drive2 import RosAriaDriver2

robot = sys.argv[1]
string1 = '/PIONIER{0}'.format(robot)
p=RosAriaDriver2(string1)
	
p.ResetPose()
