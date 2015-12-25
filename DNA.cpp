#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>

#include "DNA.h"
#include "RNA.h"

using namespace std;

//DNA CLASS
DNA::DNA(string DNAStrandVal)
{
	DNAStrand = DNAStrandVal; //Original DNA strand (from input file)
	otherDNAStrand = DNAStrand; //the complement of the original DNA strand; initialized to DNAStrand (equal sizes)
	pctGC = 0.0; //The proportion of the original DNA Strand that is either a 'G' or a 'C'
	vector<int> cpgLocations; //A vector storing the beginning index in the ORIGINAL DNA strand of all CpG islands
}

void DNA::otherStrand()
{
	char fromChars[5] = {"GCAT"};
	char toChars[5] = {"CGTA"};

	for(int i = 0; i < DNAStrand.size(); i++)
	{ 
		if(DNAStrand[i] == fromChars[0])
		{
			otherDNAStrand[DNAStrand.size() - 1 - i] = toChars[0];
		}
		if(DNAStrand[i] == fromChars[1])
		{
			otherDNAStrand[DNAStrand.size() - 1 - i] = toChars[1];
		}
		if(DNAStrand[i] == fromChars[2])
		{
			otherDNAStrand[DNAStrand.size() - 1 - i] = toChars[2];
		}
		if(DNAStrand[i] == fromChars[3])
		{
			otherDNAStrand[DNAStrand.size() - 1 - i] = toChars[3];
		}
	}
}

void DNA::calcPctGC()
{
	char charDict[5] = {"GCAT"};
	int numChars = 0;
	int numGC = 0;

	for(int i = 0; i < DNAStrand.size(); i++)
	{
		numChars++;
		if (DNAStrand[i] == charDict[0] || DNAStrand[i] == charDict[1])
		{
			numGC++;
		}
	}
	pctGC = 1.0 * numGC/numChars;
}

void DNA::findCPGLocations()
{
	char charDict[5] = {"GCAT"};
    bool lastCharC = false;

	for(int i = 0; i < DNAStrand.size(); i++)
	{
		if(lastCharC == true && DNAStrand[i] == charDict[0])
		{
			cpgLocations.push_back(i-1);
		} 

		if (DNAStrand[i] == charDict[1])
		{
			lastCharC = true;
		}
		else 
		{
			lastCharC = false;
		}
	}
}