//
//  main.cpp
//  homework3
//
//  Created by Yuxuan Xia on 2/8/17.
//  Copyright (c) 2017 Yuxuan Xia. All rights reserved.
//

/*Use your platform to create a project that input 10 stock Level1 quotes from your keyboard, save the quotes into an file at first, display them in monitor,  and then load into an array from the file that you save. The stock quote includes stock name(12 characters), Best bid price and size, ask price and size, yesterday close price, open price, last price, and total volume. The stock quote must be handled by a structure.*/
#include "SplitString.h"
#include <fstream>
#include <iomanip>
const int N = 2;
#include <string>
#include <iostream>
using namespace std;


struct quote{
	string stock_name;
	float best_bid;
	float best_size;
	float yesterday_close_price;
	float open_price;
	float last_price;
	float total_volumn;
};

int main() {
	cout << "input N=2 quotes";

	quote data[N];
	ofstream ofile;
	ofile.open("quote_data.txt", ios::trunc);
	quote temp;


	for (int i = 0; i<N; i++){
		cout << "please input quote data:" << endl;
		cout << "stock_name: ";
		cin >> temp.stock_name;
		ofile << temp.stock_name;
		cout << "best_bid: ";
		cin >> temp.best_bid;
		ofile << " " << temp.best_bid;
		cout << "best size: ";
		cin >> temp.best_size;
		ofile << " " << temp.best_size;
		cout << "yesterday close price: ";
		cin >> temp.yesterday_close_price;
		ofile << " " << temp.yesterday_close_price;
		cout << "open price: ";
		cin >> temp.open_price;
		ofile << " " << temp.open_price;
		cout << "last price";
		cin >> temp.last_price;
		ofile << " " << temp.last_price;
		cout << "total_volumn";
		cin >> temp.total_volumn;
		ofile << " " << temp.total_volumn << "\n";
	}
	ofile.close();

	ifstream ifile;
	ifile.open("quote_data.txt");


	//input file to string
	string s;
	int i=0;
	while (getline(ifile, s))
	{
		//        cout << "Read from file: " << s << endl;
		vector<string> result;
		split(s, ' ', result);
		data[i].stock_name = result[0];
		data[i].best_bid = std::stof(result[1]);
		data[i].best_size = std::stof(result[2]);
		data[i].yesterday_close_price = std::stof(result[3]);
		data[i].open_price = std::stof(result[4]);
		data[i].last_price = std::stof(result[5]);
		data[i].total_volumn = std::stof(result[6]);
		i++;
	}
	ifile.close();

	//print data
	for (int i = 0; i<N; i++){
		cout << "quote" << i << ": ";
		cout << "stock_name: ";
		cout << data[i].stock_name;
		cout << "best bid: ";
		cout << data[i].best_bid;
		cout << "best size: ";
		cout << data[i].best_size;
		cout << "yesterday close price: ";
		cout << data[i].yesterday_close_price;
		cout << "open price: ";
		cout << data[i].open_price;
		cout << "last price: ";
		cout << data[i].last_price;
		cout << "total_volumn: ";
		cout << data[i].total_volumn;
		cout << endl;
	}




	return 0;
}
