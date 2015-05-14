#include <cmath>
#include "DobierzRobota.hpp"

using namespace std;

int DobierzRobota::Dobierz_Robota(int ZadanieId)
{
	int ID=0;
	Magazyn *magazyn, *cel;
	double najkrotsza_trasa = 10000, trasa;

	RobotManagerData* robotmanagerdata = getRobotManagerData();
	const std::vector<Zadanie>& listazadan = robotmanagerdata->tasksVector();
	const std::vector<Robot>& listarobotow = robotmanagerdata->robotVector();

	for(std::vector<Zadanie>::const_iterator it1=listazadan.begin(); it1!=listazadan.end(); it1++)
	{
		if(it1->WezId()==ZadanieId)
		{
					
			magazyn = robotmanagerdata->findStoreId(it1->WezStartMagazynId());
			cel = robotmanagerdata->findStoreId(it1->WezCelMagazynId());
			for(std::vector<Robot>::const_iterator it2=listarobotow.begin(); it2!=listarobotow.end(); it2++)
			{
				if(it2->WezCzyWolny())
				{	
					trasa=sqrt(pow(it2->WezWspX()-magazyn->WezWspX(),2)+pow(it2->WezWspY()-magazyn->WezWspY(),2))+
					sqrt(pow(magazyn->WezWspX()-cel->WezWspX(),2)+pow(magazyn->WezWspY()-cel->WezWspY(),2));
					if(trasa < najkrotsza_trasa) ID=it2->WezRobotId();
				}	//if 
			}	//for
		}	//if
	}	//for	
	return ID;      
}
