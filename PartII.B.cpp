#include "init.h"
#include "basicFunctions.h"
#include "PartII.B.h"
#include <vector>
using namespace std;

void QuestionB1(int, const vector<Node>&);
void QuestionB2(int, const vector<Node>&);

int PartIIB(const vector<Node> &nodeVector) {
	// Take user input
	string action;
	cout << "What do you want to do? [min/max/exit/help]: "; 
	cin >> action; 
	// perform action
	if (action.compare("help") == 0) {
		cout << "min	Find region with minimum count of births." << endl 
			<< "max	Find region with maximum count of births." << endl << endl;
	} else if (action.compare("min") == 0) {
		QuestionB1(0, nodeVector);
	} else if (action.compare("max") == 0) {
		QuestionB2(0, nodeVector);
	} else if (action.compare("exit") == 0) {
		return 0;
	} else {
		cout << "Error: Option '" << action << "' not found." << endl << endl;
		return 1;
	}
	return 2;
}

void QuestionB1(int i, const vector<Node> &nodeVector) {
	if (nodeVector[i].left == -1) {
		cout << "Region with least total births: " << nodeVector[i].region.name << " with " << nodeVector[i].region.totalBirths << " total births." << endl << endl;
	} else {
		QuestionB1(nodeVector[i].left, nodeVector);
	}
}

void QuestionB2(int i, const vector<Node> &nodeVector) {
	if (nodeVector[i].right == -1) {
		cout << "Region with most total births: " << nodeVector[i].region.name << " with " << nodeVector[i].region.totalBirths << " total births." << endl << endl;
	} else {
		QuestionB2(nodeVector[i].right, nodeVector);
	}
}
