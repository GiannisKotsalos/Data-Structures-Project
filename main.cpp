#include "init.h"
#include "basicFunctions.h"
#include "sortingFunctions.h"
#include "searchFunctions.h"
#include <time.h>
using namespace std;

ifstream DataFile("Data(Edited).txt");
Row dataArray[NUMOFENTRIES];
Region regionArray[NUMOFREGIONS];
vector<Node> nodeVector(NUMOFREGIONS);

void Question2();
void Question3();

int main() {
	clock_t clockStart, clockEnd;
	readFile(DataFile, dataArray);
	DataFile.close();
	
	// make region array
	makeRegionArray(regionArray, dataArray);
    calcTotalBirths(regionArray);
    calcTotalDeaths(regionArray);
  	
	// make nodeVector
	nodeVector = makeNodeVector(regionArray);
	makeTree(nodeVector);
	
	// print tree
	/*
	for (int i = 0; i < NUMOFREGIONS; i++) {
		cout << i << ": " << nodeVector[i].region.name << ": " << endl;
		cout << "\tParent: " << nodeVector[i].parent << endl;
		cout << "\tLeft: " << nodeVector[i].left << endl;
		cout << "\tRight: " << nodeVector[i].right << endl;
	}
	*/
	
	// Question 2: Search Tree
	Question2();
	//Question 3: Modify Node
	Question2();	

	return 0;
}

void Question2() {
	string searchString;
	cout << "Type Region name to search: ";
	getline(cin >> ws, searchString); // Input searchString for region
	int found = searchTree(nodeVector, searchString, 0); // found = index of region, -1: not Found
	if (found != -1) {		// if found
		int searchPeriod;
		cout << "Type Period [2005-2022]: ";	// ask for period
		cin >> searchPeriod;
		int births;
		births = nodeVector[found].region.period(searchPeriod).births; // get births of found region and period
		cout << "Births in " << searchString << " on " << searchPeriod << " are: " << births << endl; // print output
	} else {
		cout << "Region Not Found!" << endl;
	}
}

void Question3() {
	string searchString;
	cout << "Type Region name to search: ";
	getline(cin >> ws, searchString); // Input searchString for region
	int found = searchTree(nodeVector, searchString, 0); // found = index of region, -1: not Found
	if (found != -1) {		// if found
		int searchPeriod;
		cout << "Type Period [2005-2022]: ";	// ask for period
		while (searchPeriod < 2005 && searchPeriod > 2022)
			cin >> searchPeriod;
		int births;
		births = nodeVector[found].region.period(searchPeriod).births; // get births of found region and period
		cout << "Births in " << searchString << " on " << searchPeriod << " are: " << births << endl; // print output
	} else {
		cout << "Region Not Found!" << endl;
	}

}
