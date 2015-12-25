#ifndef DNA_H
#define DNA_H

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class DNA {
public:
	DNA(string DNAStrandVal);
	void otherStrand();
	void calcPctGC();
	void findCPGLocations();

	string DNAStrand;
	string otherDNAStrand;
	double pctGC;
	vector<int> cpgLocations; 
};

#endif