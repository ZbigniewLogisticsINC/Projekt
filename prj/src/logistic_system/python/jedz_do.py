#!/usr/bin/env python
#-*- coding: latin2 -*-

'''
Plik umożliwia przemieszczenie robota z aktualnej pozycji do punktu celu podanego w argumentach wywołania.
'''

import sys
import roslib
import rospy
from geometry_msgs.msg import Twist, Pose
from drive import RosAriaDriver
from math import atan, sqrt, pow

'''
Obsługa argumentów wywołania skryptu.

#argument 1: nazwa robota (zostaje zkonkatenowany do zmiennych typu string)
#argument 2: współrzędna x punktu celu
#argument 3: współrzędna y punkty celu
#argument 4: definiuje czy robot ma ustawić się przed paczkę lub nie (0 jeśli jedzie do miejsca, 1 jeśli jedzie po paczkę)

'''
robot = sys.argv[1]	
string = '/{0}'.format(robot)	
x2=float(sys.argv[2])
y2=float(sys.argv[3])

'''
Stworzenie obiektu klasy RosAriaDriver.
'''
p=RosAriaDriver(string)

'''
Definicja funkcja obracającej robota.

#parametr: p obiekt klasy RosAriaDriver

Funkcja pozwala nakierować, ustawić robota na cel. 

'''
def obroc(p):
	xx=p.GetPose()	#Pobranie bierzącej pozycji robota oraz jego orientacji.
	x1=xx[0]	#x - bierząca współrzędna x robota w metrach.
	y1=xx[1]	#y - bierząca współrzędna y robota w metrach.
	theta=xx[2]*3.1415/180	#theta - bierzący kąt obrotu robota, jego orientacja w radianach.
	#print theta
	
	'''
	Poniższa część kodu funkcji obroc dotyczny obsługi przypadków jakie mogą wystąpić, aby dobrze obliczyć orientację, 
	kąt, na który robot powinien zostać ustawiony względem jego aktualnej pozycji. Po wykonaniu funkcji obroc 
	kąt theta robota powinna przyjąć wartość obliczonego niżej kąta.
	#zmienne:	kat - obliczana orientacja potrzebna do nakierowania robota na cel (orientacja końcowa).
	'''
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
						
	'''
	Następnym etapem funkcji obroc jest ustawienie robota na obliczoną orientację.
	Ruch robota zadawany jest za pomocą metody dostępnej w klasie RosAriaDriver SetSpeed()
	#Zmienne:	kat - obliczona orientacja potrzebna do nakierowania robota na cel (orientacja końcowa).
			time - odwzorowuje kąt o jaki robot powinien się obrócić  względem orientacji końcowej i aktualnej orientacji.
			theta - orientacja robota pobierana z każdą iteracją pętli while na jej początku w radianach.
			theta2 - orientacja robota pobierana z każdą iteracją pętli while po wykonaniu obrotu w radianach.
			ustawiony - gdy zostaje ustawiona na true oznacza, że różnica między kątami theta oraz theta2 jest bliska 0, 
			czyli robot osiągnął już właściwą orientację.
			
	'''
	ustawiony = False
	i=0
	while (ustawiony == False):
		xx=p.GetPose()	#Pobranie bierzącej pozycji robota oraz jego orientacji.
		x1=xx[0]	#x - bierząca współrzędna x robota w metrach.
		y1=xx[1]	#y - bierząca współrzędna y robota w metrach.
		theta=xx[2]*3.1415/180	#theta - bierzący kąt obrotu robota, jego orientacja w radianach.
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

		xx=p.GetPose()
		theta2=xx[2]*3.1415/180
		print theta2
		if (abs(theta - theta2) < 0.0001):
			ustawiony = True
		p.SetSpeed(0,0,0.5)
'''
Definicja funkcji wykonującej przemieszczenie robota do punktu celu.
#parametr:	p obiekt klasy RosAriaDriver

#Zmienne:	d - długość dystansu z punktu startowego do punktu celu robota liczona za pomocą wzoru na długość odcinka.
'''
def funkcja(p):
	#Ustawienie się robota w kierunku celu.
	obroc(p);

	#Jazada w kierunku celu.
	print p.GetPose()
	xx=p.GetPose()
	x1=xx[0]
	y1=xx[1]
	paczka = float(sys.argv[4])
	if paczka == 1:
		d=sqrt(pow(x2-x1,2)+pow(y2-y1,2)) - 0.4
	else:
		d=sqrt(pow(x2-x1,2)+pow(y2-y1,2))
	p.GoTo(d)	#Jazda robota na wprost przez odległość d, wykorzystuje się metodę klasy RosAriaDrier GetPose().
	
if __name__ == '__main__':
	funkcja(p)	#Wywołanie funkcja

