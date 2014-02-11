#include "exectimer.h"

#include <vector>
#include <string>
#include <iostream>

int main(int argc, char** argv) {
	std::vector< std::string> args;

	for (int i = 1; i < argc; i++)
		args.push_back(argv[i]);
	
	std::string cmd = "\"" + *(args.begin()) + "\" ";
	for (std::vector<std::string>::iterator it = args.begin()+1; it != args.end(); ++it)
		cmd += *it + " ";

	std::cout << "We gaan het volgende commando timen: " << cmd << std::endl << std::endl;
	
	ExecTimer* et = new ExecTimer();
	et->run(cmd,true);

	std::cout << "Klaar met timen..." << std::endl;
	std::cout << "De tijd: " << et->elapsedMicroSeconds() << " microseconden." << std::endl << std::endl;
	std::cout << "De tijd: " << et->elapsedMilliSeconds() << " milliseconden." << std::endl << std::endl;
	std::cout << "De tijd: " << et->elapsedSeconds() << " seconden." << std::endl << std::endl;
	int m;
	std::cin >> m;

	return 0;
}