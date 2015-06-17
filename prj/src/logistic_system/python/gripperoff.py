#!/usr/bin/env python
#-*- coding: latin2 -*-

'''
Plik umożliwia zabranie paczki z miejsca.
'''

import sys
import roslib
import rospy
from drive import RosAriaDriver

'''
Obsługa argumentu wywołania skryptu.

#argument 1: numer robota (zostaje zkonkatenowany do zmiennych typu string)

'''
robot = sys.argv[1]	

'''
Stworzenie obiektu klasy RosAriaDriver.
'''
string = '/PIONIER{0}'.format(robot)
p=RosAriaDriver(string)

'''
Opuszczenie i otwarcie chwytaka robota wraz z paczką.
'''
p.GripperDown();
p.SetSpeed(0,0,2);
p.GripperOpen();
p.SetSpeed(0,0,2);

'''
Cofnięcie się robota.
'''
p.SetSpeed(-0.25,0,1)

'''
Zamknięcie i podniesienie chwytaka robota.
'''
p.GripperClose();
p.SetSpeed(0,0,2);
p.GripperUp();
p.SetSpeed(0,0,2);
