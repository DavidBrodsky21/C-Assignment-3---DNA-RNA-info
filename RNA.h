#ifndef RNA_H
#define RNA_H

class RNA {
public:
	RNA(string RNAStringVal);
	void convertToAminoAcids();
	string RNAString;
	vector<string> aminoAcidVector;
};

//Helper functions
string map(string a, string b, string c);
int charToInt(string someChar);

#endif