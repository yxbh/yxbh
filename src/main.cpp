#include <iostream>
#include <string>
#include "Process.h"
#include <vector>
using namespace std;
#include "ProcessManager.h"
#include "testClass.h"
#include "InputProcessor.h"
#include "arraytp.h"



int main()
{
	cout << "Hello ... " << endl;
	InputProcessor ip;
	cout << "Enter something: ";
	ip.getInput();
	ip.processInputC();
	cout << "You've entered the following words, seperated by spaces;" << endl;
	vector<string> ppp = ip.getWordList();
	for (int n = 0; n < (int)ppp.size(); n++)
	{
		cout << "  " << ppp[n] << endl;
	}
	

	// command event loop
	bool running = true;  // in actual implementation, this should be global so other objects can switch this
	while (running)
	{
		running = false;
	}

	cout << "Press Enter to exit" << endl;
	cin.get();
	return 0;
}