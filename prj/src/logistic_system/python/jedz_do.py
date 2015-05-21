#!/usr/bin/env python
#-*- coding: latin2 -*-

import sys
import roslib
import rospy
from geometry_msgs.msg import Twist, Pose
from drive import RosAriaDriver
from math import atan, sqrt, pow


def funkcja():
	robot = sys.argv[1]
	string1 = '/PIONIER{0}/RosAria/pose'.format(robot)
	string2 = '/PIONIER{0}/RosAria/cmd_vel'.format(robot)
	string3 = '/PIONIER{0}'.format(robot)
	p=RosAriaDriver(string3)	
	x2=float(sys.argv[2])
	y2=float(sys.argv[3])

	#Ustawienie się robota w kierunku celu.
	ustawiony = False
	while ustawiony == True:
		xx=p.GetPose()
		x1=xx[0]
		y1=xx[1]
		theta=xx[2]*3.1415/180
		print theta
	
		kat=atan((y2-y1)/(x2-x1))
		print kat
	
		if kat > theta:
			time = kat-theta
			p.SetSpeed(0,1,time)
			p.SetSpeed(0,0,0)
		else:
			time = theta-kat
			p.SetSpeed(0,-1,time)
			p.SetSpeed(0,0,0)

		print p.ReadSonar()
		xx=p.GetPose()
		theta2=xx[2]*3.1415/180
		print theta2
		if theta == theta2:
			ustawiony = True

	#Jazada w kierunku celu.
	xx=p.GetPose()
	x1=xx[0]
	y1=xx[1]
	d=sqrt(pow(x2-x1,2)+pow(y2-y1,2))
	SetSpeed(1,0,d)
	SetSpeed(0,0,0)
				

if __name__ == '__main__':
	funkcja()
