//
//  readQuoteFile.cpp
//  
//
//  Created by 夏宇轩 on 2/15/17.
//
//
#include "stdlib.h"
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include "quotelib.h"
#include "SplitString.h"
#include <vector>
using std::vector;

using std::cin; using std::cout; using std::endl;
using std::string; using std::ifstream;
const int N = 2;

int main() {
	ifstream ifile;
	string s;//input file to string
	Quote* quotes[N];
	//    //temptation
	//    string instrumentType, name, underlyingName;
	//    float bidPrice, askPrice, lastPrice, issueExchange;
	//    int contractSize, expireDate, tickSize, contractMonths;

	ifile.open("quote_data.txt");
	cout << "Read from file: " << endl;
	for (int i = 0; getline(ifile, s); i++)
	{
		//        cout << s << endl;
		vector<string> result;
		split(s, ' ', result);
		if (result[0] == "stock") {
			quotes[i] = new Stock(result[1], stof(result[2]), stof(result[3]), stof(result[4]), stoi(result[5]));
		}
		else if (result[0] == "option") {
			quotes[i] = new Option(result[1], result[2], stof(result[3]), stof(result[4]), stof(result[5]), stoi(result[6]), stoi(result[7]));
		}
		else if (result[0] == "future") {
			quotes[i] = new Future(result[1], result[2], stof(result[3]), stof(result[4]), stof(result[5]), stoi(result[6]), stoi(result[7]), stoi(result[8]));
		}
		else {
			cout << "Unidentifiable instrument type!";
		}
	}
	ifile.close();
	cout << "print quotes using Class Method:" << endl;
	for (int i = 0; i<N; i++) {
		quotes[i]->printQuote();
	}
	system("pause");
	return 0;
}