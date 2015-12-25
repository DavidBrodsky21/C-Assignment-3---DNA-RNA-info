/************************************************************************************
Title: DNA/RNA Sequencing (HW3)
Author: David Brodsky
Created on: August 8, 2015
Description: Program for manipulating and gathering information about DNA/RNA Sequences
************************************************************************************/


#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>

#include "DNA.h"
#include "RNA.h"

using namespace std;

//READ-WRITE FUNCTION DECLARATIONS
void readFile(string fileName, vector<string> &stringVector);
void output(vector<DNA> DNAVector, string outfileName);
void output(vector<RNA> RNAVector, string outfileName);


int main(int argc, char* argv[]){
	string fileType = argv[1];
	string fileName = argv[2];
	string outfileName = argv[3];
	vector<string> stringVector;
	vector<DNA> DNAVector;
	vector<RNA> RNAVector;	

//Read in the relevant file (as specified by user in command line)
	readFile(fileName, stringVector);

// For DNA files, create a vector of DNA objects with all of their properties filled in/calculated:
//    1)  The original DNA string (from input file)
//    2)  The "other strand"
//    3)  The proportion of the original strand that is of the 'G' or 'C' variety
//    4)  The beginning index (in the ORIGINAL strand) of all locations of CpG bridges, i.e. a 'C' immediately followed by a 'G'
	if(fileType == "DNA")
	{		
		for (int i = 0; i < stringVector.size(); i++)
		{	
			DNA aDNAStrand(stringVector[i]);
			DNAVector.push_back(aDNAStrand);
			DNAVector[i].otherStrand();
			DNAVector[i].calcPctGC();
			DNAVector[i].findCPGLocations();

			output(DNAVector, outfileName);
		}
	}
// For RNA files, create a vector of RNA objects and convert each RNA strand to an Amino Acid Sequence
	else if (fileType == "RNA")
	{
		for (int i = 0; i < stringVector.size(); i++)
		{
			RNA aRNAString = stringVector[i];
			RNAVector.push_back(aRNAString);
			RNAVector[i].convertToAminoAcids();

			output(RNAVector, outfileName);
		}
	}

	cout << endl;
	return 0;
}


//READ-WRITE FUNCTION DEFINITIONS
//Read input file
void readFile(string fileName, vector<string> &stringVector)
{
	ifstream infile;
	infile.open(fileName.c_str());

	while(infile.good()) {

		string inputString;
		infile >> inputString;
		stringVector.push_back(inputString);
	}
	infile.close();

	if (stringVector.size() == 0)
	{
		cout << "No data pulled from file!\n";
	} 
}

//Output for DNA 
void output(vector<DNA> DNAVector, string outfileName)
{
	ofstream myfile;
	myfile.open (outfileName.c_str());
	
	for (int i = 0; i < DNAVector.size(); i++)
	{
		myfile << "DNA Strand #" << i + 1 << ": \n"
			<< "Original DNA Strand: " << DNAVector[i].DNAStrand << endl
			<< "Other DNA Strand: " << DNAVector[i].otherDNAStrand << endl
			<< "Percent GC content: " << DNAVector[i].pctGC * 100.0 <<"%"<< endl
			<< "CpG islands start at the following indices: " << endl;
		if (DNAVector[i].cpgLocations.size() == 0)
		{
			myfile << "No CpG islands in DNA Strand #" << i+1 << endl;
		}
		else 
		{
			for(int j = 0; j < DNAVector[i].cpgLocations.size(); j++)
			{
				myfile << DNAVector[i].cpgLocations[j] << endl;
			}
		}
		myfile << endl << endl;

	}

	myfile.close();
}

//Output for RNA
void output(vector<RNA> RNAVector, string outfileName)
{
	ofstream myfile;
	myfile.open (outfileName.c_str());
	
	for (int i = 0; i < RNAVector.size(); i++)
	{
		myfile << "RNA Strand #" << i + 1 << ": \n"
			<< "Original RNA Strand: " << RNAVector[i].RNAString << endl
			<< "Amino Acid Sequence: ";

		for(int j = 0; j < RNAVector[i].aminoAcidVector.size() - 1; j++)
		{
			myfile  << RNAVector[i].aminoAcidVector[j] << "-";
		}
		
		myfile  << RNAVector[i].aminoAcidVector[RNAVector[i].aminoAcidVector.size() - 1];

		myfile << endl << endl;

	}

	myfile.close();
}


