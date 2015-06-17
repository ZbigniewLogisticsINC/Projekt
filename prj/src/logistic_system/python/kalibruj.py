#!/usr/bin/env python
#-*- coding: latin2 -*-
# Nazwa pliku: kalibruj.py
"""
Modul kalibruj.py zawiera szereg komend zdefiniowanych w pliku RosAriaDriver2
uzytych w celu skalibrowania pozycji robota w garazu przy pomocy zaimplementowanego
nawiasu Liego oraz zczytanych odleglosci od bocznych scian garazu danego robota.

Plik wymaga podanych argumentow wejsciowych, definiujacych bierzaca pozycje robota
wspolrzedne wjazdu oraz wspolrzedne jego garazu, gdzie ma przeprowadzic kalibracje.
  /.kalibruj.py [bierz_wsp_x] [bierz_wsp_y] [wsp_wjazd_g_x] [wsp_wjazd_g_y] [wsp_g_x] [wsp_g_y]
"""

import sys
import os
import roslib
import rospy
from geometry_msgs.msg import Twist, Pose
from drive2 import RosAriaDriver2
from math import atan, sqrt, pow

"""zmienna definujaca numer poruszanego robota (liczba naturalna w przedziale <1,6>)"""
robot = sys.argv[1]

"""pomocniczy string uzyty przy inicjacji robota"""
string3 = '/PIONIER{0}'.format(robot)

"""Stworzenie obiektu klasy RosAriaDriver."""
p=RosAriaDriver2(string3)

"""
Obsługa argumentów wywołania skryptu.

#argument 1: numer robota (zostaje zkonkatenowany do zmiennych typu string)
#argument 2: współrzędna x wjazdu do garazu
#argument 3: współrzędna y wjazdu do garazu
#argument 4: wspolrzedna x wnetrza garazu
#argument 5: wspolrzedna y wnetrza garazu
"""
x2=float(sys.argv[2])
y2=float(sys.argv[3])
xg=float(sys.argv[4])
yg=float(sys.argv[5])

"""
Funkcja wykonujaca proces kalibracji robota przy uzyciu nawiasu Liego.
Moze zostac zapoczatkowana tylko jesli robot znajduje sie w garazu, 
aby mozliwe byly odczyty z sonarow bocznych robota. 

#parametr:    p   obiekt klasy RosAriaDriver
#zmienna:  wspx   wczytana wsp x wnetrza garazu
#zmienna:  wspy   wczytana wsp y wnetrza garazu
"""
def kalibruj(p, wspx, wspy):

	polozenie = p.GetPose()
	odczyts = p.ReadSonar()
	s1 = odczyts[0][1]
	s2 = odczyts[7][1]
	while abs(abs(s1)-abs(s2))>0.01:
	 if abs(s1)<abs(s2):
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
	 print s1
  	 print s2


"""
Glowna funkcja programu uzywajaca innej zawartej w pliku jedz_do.py
funkcji majacej za zadanie przemieszczenie robota na okreslone wspolrzedne.
Ponadto wykorzystuje zaimplementowana funkcje kalibracji i ja wykonuje
po dotarciu do garazu  
"""
if __name__ == '__main__':

	string4 = 'rosrun logistic_system jedz_do.py {0} {1} {2}'.format(robot,x2,y2)
	string5 = 'rosrun logistic_system jedz_do.py {0} {1} {2}'.format(robot,xg,yg)
	os.system(string4)    # Udanie się robota na wsp wjazdu do garazu.
	os.system(string5)    # Udanie się robota do wnetrza garazu.
	kalibruj(p, xg, yg)   # kalibracja
	os.system(string4)    # wyjazd z garazu
