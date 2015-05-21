#!/usr/bin/env python
#-*- coding: latin2 -*-

import sys
import roslib
import rospy
from geometry_msgs.msg import Twist, Pose
from drive import RosAriaDriver
from math import atan, sqrt, pow

robot = sys.argv[1]
string1 = '/PIONIER{0}/RosAria/pose'.format(robot)
string2 = '/PIONIER{0}/RosAria/cmd_vel'.format(robot)
string3 = '/PIONIER{0}'.format(robot)	

xwej=float(sys.argv[2]) # wsp punktu wjazdu do garazu
ywej=float(sys.argv[3]) # ......
xg=float(sys.argv[4])   # wsp garazu
yg=float(sys.argv[5])   # ......
p=RosAriaDriver(string3)

def jedz(p, wspx, wspy):
	
	p=RosAriaDriver(string3)
	#Ustawienie się robota w kierunku wsp celu
	ustawiony = False
	while ustawiony == True:
		xx=p.GetPose()
		x1=xx[0]
		y1=xx[1]
		theta=xx[2]*3.1415/180	
		kat=atan((wspx-y1)/(wspy-x1))
	
		if kat > theta:
			time = kat-theta
			p.SetSpeed(0,1,time)
			p.SetSpeed(0,0,0)
		else:
			time = theta-kat
			p.SetSpeed(0,-1,time)
			p.SetSpeed(0,0,0)
		
		xx=p.GetPose()
		theta2=xx[2]*3.1415/180

		if theta == theta2:
			ustawiony = True

	#Jazda w kierunku celu.
	xx=p.GetPose()
	x1=xx[0]
	y1=xx[1]
	d=sqrt(pow(wspx-x1,2)+pow(wspy-y1,2))
	SetSpeed(1,0,d)
	SetSpeed(0,0,0)

def kalibruj(p, wspx, wspy): # uzywa funkcji liego i oczytow z sonaru zeby skalibrowac robota

	polozenie = p.GetPose()
	odczyts = p.ReadSonar()
	s1 = odczyts[0][1]
	s2 = odczyts[7][1]
	while s1!=s2:
	 if s1>s2:
		p.SetSpeed(0.1,0,1)
		p.SetSpeed(0,0,0.3)
		p.SetSpeed(0,0.1,1)
		p.SetSpeed(0,0,0.3)  
		p.SetSpeed(-0.1,0,1)
		p.SetSpeed(0,0,0.3)
		p.SetSpeed(0,-0.1,1)
		p.SetSpeed(0,0,0.3)
	 else:
		p.SetSpeed(0.1,0,1)
		p.SetSpeed(0,0,0.3)
		p.SetSpeed(0,-0.1,1)
		p.SetSpeed(0,0,0.3)  
		p.SetSpeed(-0.1,0,1)
		p.SetSpeed(0,0,0.3)
		p.SetSpeed(0,0.1,1)
		p.SetSpeed(0,0,0.3)
	 odczyts = p.ReadSonar()
	 s1 = odczyts[0][1]
	 s2 = odczyts[7][1]



if __name__ == '__main__':
	jedz(p, xwej, ywej)   # Udanie się robota na wsp wjazdu do garazu.
	jedz(p, xg, yg)       # Udanie się robota do wnetrza garazu.
	kalibruj(p, xg, yg)   # kalibracja
	jedz(p, xwej, ywej)   # wyjazd z garazu
