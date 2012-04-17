
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

#include <json/json.h>
#include <json/reader.h>

int main(int argc, char** argv) {
	if(argc < 2) {
		cout << "Not enough arguments provided.\n";
		return(0);
	}

	FILE* fp = fopen(argv[1], "r");
	if(!fp) {
		cout << "Unable to read file " << argv[1] << ".\n";
		return(0);
	}

	fseek(fp, 0, SEEK_END);
	unsigned long end = ftell(fp);

	char* document = (char*)malloc(end + 1);
	fseek(fp, 0, SEEK_SET);
	fread(document, end, 1, fp);
	document[end + 1] = '\0';

	Json::Value root;   // will contains the root value after parsing.
	Json::Reader reader;
	bool parsingSuccessful = reader.parse(document, root);
	if ( !parsingSuccessful ) {
		// report to the user the failure and their locations in the document.
		std::cout  << "Failed to parse file\n" << reader.getFormatedErrorMessages();
		return(0);
	}	

	cout << "Successfully parsed file.\n";
	return(0);
}
