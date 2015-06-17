#!/usr/bin/env python
#-*- coding: latin2 -*-
# Nazwa pliku: zapisz_pozycje_robota.py
"""
Funkcja zczytujaca bierzaca pozycje robota:
wspolrzedna x, wspolrzedna y oraz kat obrotu.
Nastepnie zapisuje te dane w pliku podanym jako
argument argv[2] wywolania programu.
Wywolanie pliku tylko z argumentami argv[1] argv[2]
gdzie argv[1] to nazwa robota
"""
import sys
import roslib
import rospy
from geometry_msgs.msg import Pose
from drive2 import RosAriaDriver2

"""zmienna definujaca numer poruszanego robota (liczba naturalna w przedziale <1,6>)"""
robot = sys.argv[1]

"""pomocniczy string uzyty przy inicjacji robota"""
nazwa_robota = '/{0}'.format(robot)

"""Stworzenie obiektu klasy RosAriaDriver."""
p=RosAriaDriver2(nazwa_robota)

"""sciezka do pliku docelowego"""
sciezka=(sys.argv[2])

"""pobranie potrzebnych wspolrzednych"""
xx=p.GetPose()	
x1=xx[0]	        #x - bierząca współrzędna x robota w metrach.
y1=xx[1]	        #y - bierząca współrzędna y robota w metrach.
theta=xx[2]*3.1415/180	#theta - bierzący kąt obrotu robota, jego orientacja w radianach.


"""inicjacja lancucha znakow do zapisu w pliku"""
wspolrzedne = '{0} {1} {2}'.format(x1,y1,theta)

"""otwarcie lub utworzenie (jesli nie ma) pliku do zapisu danych"""
plik = open(sciezka, 'w+')
"""zapis danych"""
plik.write(wspolrzedne)
"""zamkniecie pliku"""
plik.close()
