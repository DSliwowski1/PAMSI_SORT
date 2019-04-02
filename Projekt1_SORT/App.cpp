#include <iostream>
#include <chrono>
#include "Array.h"
#include "MergSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "IntroSort.h"
#include "Experiment.h"
#include "UI.h"

using namespace std;

int main(int argc, char** argv)
{
	Array<int> tmpa(20);
	tmpa.Mo3Killer();
	cout << tmpa << endl;

	char tmp = 'p';

	cin.get();

	while(tmp != 'e')
		tmp = UI::Menu();

	cin.get();

	return 0;
}