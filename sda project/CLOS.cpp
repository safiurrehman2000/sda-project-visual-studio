#include <iostream>
#include <fstream>
#include "CLO.cpp"
#include <string>
#include <string.h>
using namespace std;

class CLOS 
{
public:
	CLO * clo;

	CLOS() 
	{
		std::string myline;
		fstream fin("CLO.txt");
		for (int i = 0; i < fin.eof(); i++)
		{
			std::getline(fin, myline);
		}
	}
};