#!/usr/bin/env python
#-*- coding: latin2 -*-

import sys
import roslib
import rospy
from geometry_msgs.msg import Twist, Pose
from drive2 import RosAriaDriver2
from math import atan, sqrt, pow

robot = sys.argv[1]
string1 = '/PIONIER{0}/RosAria/pose'.format(robot)
string2 = '/PIONIER{0}/RosAria/cmd_vel'.format(robot)
string3 = '/PIONIER{0}'.format(robot)
p=RosAriaDriver2(string3)	
x2=float(sys.argv[2])
y2=float(sys.argv[3])

p.ResetPose()

def funkcja(p):
	#Ustawienie się robota w kierunku celu.
	ustawiony = False
	i=0
	while (ustawiony == False):
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

		#print p.ReadSonar()
		xx=p.GetPose()
		theta2=xx[2]*3.1415/180
		print theta2
		if (abs(theta - theta2) < 0.001):
			ustawiony = True
		p.SetSpeed(0,0,0.5)


	#Jazada w kierunku celu.
	print p.GetPose()
	xx=p.GetPose()
	x3=xx[0]
	y3=xx[1]
	d=sqrt(pow(x2-x1,2)+pow(y2-y1,2))
	p.GoTo(d)
'''
	dd=-9999
	while (d-dd > 0.05): #or abs(x2-x1) > 0.05 or abs(y2-y1) > 0.05:
		xx=p.GetPose()
		x1=xx[0]
		y1=xx[1]
		p.SetSpeed(1,0,0.5)
		p.SetSpeed(0,0,0.1)
		dd=sqrt(pow(x3-x1,2)+pow(y3-y1,2))
		print p.GetPose()
'''
	
	#p.SetSpeed(0,0,0)
				

if __name__ == '__main__':
	

	funkcja(p)
