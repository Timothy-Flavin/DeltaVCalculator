//Delta V calculator
#include<iostream>
#include<cmath>
#include<iomanip>
#include<string>
using namespace std;



int main()
{
	int r;
do
{
	r = 0;
	char findTWR, findISP;
	int numEngineTypes, numEngines, engineThrust, numStages, totalThrust = 0;
	float fullMass, dryMass, gravity, DeltaV, totalDeltaV = 0, deltaVLeft;
	double thrustWeightRatio, ISP;
	string rocketName;
	
	cout << fixed << showpoint << setprecision(2);
	cout << "What is the name of your rocket? ";
	getline(cin, rocketName);
	cout << "How many stages does your rocket have? ";
	cin >> numStages;
	for(int y = 1; y <= numStages; y++)
	{
		totalThrust = 0;
		do
		{
			cout << "Do you want to find the thrust to weight ratio of stage " << y << " ? (y or n) ";
			cin >> findTWR;
		}while(findTWR != 'y' && findTWR != 'n');
	
		if (findTWR == 'y')
		{
			cout << "Enter the Mass of the stage in tons: ";
			cin >> fullMass;
			cout << "How many engine types are there? (ex: 2, (one 2hammers and 3 fleas)) ";
			cin >> numEngineTypes;
			for (int x = 1; x <= numEngineTypes; x++)
			{
				int subTotalThrust;
			
				cout << "What is the thrust in kn of engine type " << x << " ? ";
				cin >> engineThrust;
				cout << "How many of engine type " << x << " are there? ";
				cin >> numEngines;
				subTotalThrust = engineThrust * numEngines;
				cout << "The Total thrust in kn of Engine type " << x << " is: " << subTotalThrust << "Kn "<< endl;
				totalThrust += subTotalThrust;
			
			}
		
			cout << "The Total Thrust of stage " << y << " is: " << totalThrust << "Kn." << endl;
			cout << "What is the gravity of the surface that you are launching from? (in m/s^2)";
			cin >> gravity;
			thrustWeightRatio = (totalThrust) / (fullMass * gravity);
			cout << "Your thrust to weight ratio is: " << thrustWeightRatio << endl;
		}
	
		else
		{
			cout << "Ok then. \n";
		}
		do
		{
			cout << "Do you need to find the combined ISP for multiple engines? (y or n)";
			cin >> findISP;
		}while(findISP != 'y' && findISP != 'n');
	
		if (findISP == 'y')
		{
			int singleISP = 0;
			double totalThrustOverISP = 0;
			totalThrust = 0;
			cout << "How many Engine types are their? ";
			cin >> numEngineTypes;
			for (int z = 1; z <= numEngineTypes; z++)
			{
				float engineTypeThrust, stageThrustOverISP;
				cout << "Enter the number of engines for type " << z << ": ";
				cin >> numEngines;
				cout << "Enter the thrust for that engine type: ";
				cin >> engineThrust;
				cout << "Enter the ISP for engine type " << z << ": ";
				cin >> singleISP;
				engineTypeThrust = (numEngines * engineThrust);
			
				totalThrust += engineTypeThrust;				
				stageThrustOverISP = (numEngines * (static_cast<double>(engineThrust)/singleISP));				
				totalThrustOverISP += stageThrustOverISP;
			}
		
			cout << "Total thrust: " << totalThrust << endl;
			cout << "Total thrust over ISP: " << totalThrustOverISP << endl;
			ISP = totalThrust / totalThrustOverISP;
			cout << "ISP: " << ISP << endl;
		
		}
	
		else
		{
			cout << "What is the ISP for your engine type? ";
			cin >> ISP;
		}
	
		cout << "What is the full weight of your stage? ";
		cin >> fullMass;
		cout << "What is the dry mass of your stage? ";
		cin >> dryMass;
		DeltaV = (log (fullMass/dryMass)) * ISP * 9.81;
		cout << "Your DeltaV for stage " << y << " is: " << DeltaV << " m/s^2.\n\n";
	
	
		totalDeltaV += DeltaV;
	}
	
	cout << "Your rocket's total Delta V is: " << setw(20) << totalDeltaV << endl << endl;
	
	if (totalDeltaV >= 3400)
	{
		deltaVLeft = totalDeltaV - 3400;
		cout << "You can make it into orbit with: " << setw(17) << deltaVLeft << " DeltaV to spare.\n\n";
		if(deltaVLeft >= 860)
		{
			deltaVLeft -= 860;
			cout << "You can fly by the mun with: " << setw(21) << deltaVLeft << " DeltaV to spare.\n";
			if(deltaVLeft >= 310)
			{
				deltaVLeft -= 310;
				cout << "You can orbit the mun with: " << setw(22) << deltaVLeft << " DeltaV to spare.\n";
				
				if(deltaVLeft >= 580)
				{
					deltaVLeft -= 580;
					cout << "You can land on the mun with: " << setw(19) << deltaVLeft << " DeltaV to spare.\n\n";
				
				}
			}
		}
		deltaVLeft = totalDeltaV - 3400;
		if(deltaVLeft >= 930)
		{
			deltaVLeft -= 930;
			cout << "You can fly by Minmus with: " << setw(22) << deltaVLeft << " DeltaV to spare.\n";
			if(deltaVLeft >= 160)
			{
				deltaVLeft -= 160;
				cout << "You can orbit Minmus with: " << setw(23) << deltaVLeft << " DeltaV to spare.\n";
				
				if(deltaVLeft >= 180)
				{
					deltaVLeft -= 180;
					cout << "You can land on Minmus with: " << setw(20)<< deltaVLeft << " DeltaV to spare.\n\n";
				
				}
			}
		}
		if(deltaVLeft >= 950)
		{
			deltaVLeft -= 950;
			cout << "You escape Kerbin with: " << setw(27) << deltaVLeft << " DeltaV to spare.\n\n";
		}
	}
	else 
	{
		cout << "You do not have the Delta V to go into orbit.\n\n Program will now end\n";
	}
	
	cout << "Press 1 to restart or 0 to quit. ";
	cin >> r;
	cin.ignore();
	
}while(r == 1);	
}