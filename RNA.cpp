#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>

#include "DNA.h"
#include "RNA.h"

using namespace std;

RNA::RNA(string RNAStringVal)
{
	RNAString = RNAStringVal;
	vector<string> aminoAcidVector;
}

void RNA::convertToAminoAcids()
{
	//Check that RNA String has appropriate number of characters
	if(RNAString.size() % 3 != 0)
	{
		cout << "Non valid RNA string found. Number of characters not divisible by 3. Please check source file.\n";
		exit(1);
	}

	vector<string> RNACodonVector;
	bool writeFlag = false;
	for(int i = 0; i < RNAString.size() - 2; i += 3)
	{
		string codon0 = RNAString.substr(i,1);
		string codon1 = RNAString.substr(i+1,1);
		string codon2 = RNAString.substr(i+2,1);

		string newAminoAcid = map(codon0, codon1, codon2);

		if(newAminoAcid == "M")
		{
			writeFlag = true;
		} else if(newAminoAcid == "1")
		{
			writeFlag = false;
		}
		if(writeFlag == true)
		{
			aminoAcidVector.push_back(newAminoAcid);	
		}		
	}
	if(aminoAcidVector.size() == 0)
	{
		cout << "Non valid RNA string found. No start codon. Please check source file.\n";
		exit(1);
	}
	if(writeFlag == true)
	{
		cout << "Non valid RNA string found. No end codon after start codon. Please check source file.\n";
		exit(1);
	}
}



// DEFINE HELPER FUNCTIONS

string map(string a, string b, string c)
{
	//STOP CODON = "1"
	//Start CODON = "M" 
	string RNAMap[4][4][4] = 
	{
		{ {"F","F","L","L"}, {"S","S","S","S"}, {"Y","Y","1","1"}, {"C","C","1","W"} },
		{ {"L","L","L","L"}, {"P","P","P","P"}, {"H","H","Q","Q"}, {"R","R","R","R"} },
		{ {"I","I","I","M"}, {"T","T","T","T"}, {"N","N","K","K"}, {"S","S","R","R"} },
		{ {"V","V","V","V"}, {"A","A","A","A"}, {"D","D","E","E"}, {"G","G","G","G"} }
	};

	int aAsInt = charToInt(a);
	int bAsInt = charToInt(b);
	int cAsInt = charToInt(c);
	
	return RNAMap[aAsInt][bAsInt][cAsInt]; 
}

//Function maps a character to an integer from 0-3; used to map RNA to Amino Acids
int charToInt(string someChar)
{
	char charArray[5] = {"UCAG"};

	if(someChar[0] == charArray[0])
	{
		return 0;
	}
	else if (someChar[0] == charArray[1])
	{
		return 1; 
	}
	else if (someChar[0] == charArray[2])
	{
		return 2; 
	}
	else if (someChar[0] == charArray[3])
	{
		return 3; 
	}
	else 
	{
		cout << "Found non-valid character in RNA string, i.e. not in set {A, C, G, U}.  Please check source file.\n";
		exit(1);
	}
}
