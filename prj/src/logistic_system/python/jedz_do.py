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

def obroc(p):
	xx=p.GetPose()
	x1=xx[0]	#bierzaca pozycja x
	y1=xx[1]	#bierzaca pozycja y
	theta=xx[2]*3.1415/180	#bierzaca kat obrotu
	print theta

	if abs(x2-x1)<0.1:
		if y2>y1:
			print "y2>y1"			
			kat=1.57
		else: 
			print "y2<y1"
			kat=-1.57
	else:
		if abs(y2-y1)<0.1:
			if x2<x1:
				print "x2<x1"			
				kat=3.1415
			else: 
				print "x2>x1"
				kat=0
		else:	
			
			if y2<y1:
				if x2<x1:
					print "y2<y1 x2<x1"							
					kat=atan((y2-y1)/(x2-x1))
					kat=kat-3.1415
					
				else:
					print "y2<y1 x2>x1"	
					kat=atan((y2-y1)/(x2-x1))
			else:
				if x2<x1:
					print "y2>y1 x2<x1"								
					kat=atan((y2-y1)/(x2-x1))
					kat=kat+3.1415
				else:
					print "y2>y1 x2>x1"	
					kat=atan((y2-y1)/(x2-x1))
						

	ustawiony = False
	i=0
	while (ustawiony == False):
		xx=p.GetPose()
		x1=xx[0]	#bierzaca pozycja x
		y1=xx[1]	#bierzaca pozycja y
		theta=xx[2]*3.1415/180	#bierzacy kat obrotu
		if kat > theta:
			time = kat-theta
			if time > 3.1415:
				time = 6.283 - time
				p.SetSpeed(0,-1,time)
				p.SetSpeed(0,0,0)
			else:
				p.SetSpeed(0,1,time)
				p.SetSpeed(0,0,0)
		else:
			time = theta-kat
			if time > 3.1415:
				time = 6.283 - time
				p.SetSpeed(0,1,time)
				p.SetSpeed(0,0,0)
			else:
				p.SetSpeed(0,-1,time)
				p.SetSpeed(0,0,0)

		#print p.ReadSonar()
		xx=p.GetPose()
		theta2=xx[2]*3.1415/180
		print theta2
		if (abs(theta - theta2) < 0.0001):
			ustawiony = True
		p.SetSpeed(0,0,0.5)

def funkcja(p):
	#Ustawienie się robota w kierunku celu.
	obroc(p);

	#Jazada w kierunku celu.
	print p.GetPose()
	xx=p.GetPose()
	x1=xx[0]
	y1=xx[1]
	d=sqrt(pow(x2-x1,2)+pow(y2-y1,2))
	p.GoTo(d)
	
if __name__ == '__main__':
	funkcja(p)
