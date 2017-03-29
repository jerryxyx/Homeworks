//
//  main.cpp
//  homework4
//
//  Created by Yuxuan Xia on 2/14/17.
//  Copyright (c) 2017 Yuxuan Xia. All rights reserved.
//

/*Use your platform to create a project that input 10 stock Level1 quotes from your keyboard, save the quotes into an file at first, display them in monitor,  and then load into an array from the file that you save. The stock quote includes stock name(12 characters), Best bid price and size, ask price and size, yesterday close price, open price, last price, and total volume. The stock quote must be handled by a structure.*/
#include "SplitString.h"
#include "quotelib.h"
#include <fstream>
#include <iomanip>
const int N = 2;
#include <string>
#include <iostream>
#include "stdlib.h"
using namespace std;


//struct quote {
//	string stock_name;
//	float best_bid;
//	float best_size;
//	float yesterday_close_price;
//	float open_price;
//	float last_price;
//	float total_volumn;
//};

int main() {
	cout << "input N=2 quotes";

//	quote data[N];
	ofstream ofile;
	ofile.open("quote_data.txt", ios::trunc);
//	quote temp;
    
//    Quote* tempt = new Quote;
    string instrumentType, name, underlyingName;
    float bidPrice, askPrice, lastPrice, issueExchange;
    int contractSize, expireDate, tickSize, contractMonths;
    Stock* stockTemp=0;
    Option* optionTemp=0;
    Future* futureTemp=0;


	for (int i = 0; i<N; i++) {
		cout << "please input quote data:" << endl;
        cout<<"instrument: ";
        cin>>instrumentType;
        if(instrumentType=="stock"){
            cout << "stock name: ";
            cin >> name;
            cout << "bid price: ";
            cin >>bidPrice;
            cout << "ask price: ";
            cin >>askPrice;
            cout << "last price: ";
            cin >> lastPrice;
            cout << "issue exchange: ";
            cin >> issueExchange;
            stockTemp=new Stock(name,bidPrice,askPrice,lastPrice,issueExchange);
            ofile << stockTemp->toString()<< "\n";
            
        }else if(instrumentType=="option"){
            cout <<"option name: ";
            cin >>name;
            cout <<"underlying name: ";
            cin >> underlyingName;
            cout << "bid price: ";
            cin >>bidPrice;
            cout << "ask price: ";
            cin >>askPrice;
            cout << "last price: ";
            cin >> lastPrice;
            cout << "contract size: ";
            cin >> contractSize;
            cout << "expire date: ";
            cin >> expireDate;
            optionTemp=new Option(name,underlyingName,bidPrice,askPrice,lastPrice,contractSize,expireDate);
            ofile << optionTemp->toString()<<"\n";
        }else if(instrumentType=="future"){
            cout <<"future name: ";
            cin >>name;
            cout <<"underlying name: ";
            cin >> underlyingName;
            cout << "bid price: ";
            cin >>bidPrice;
            cout << "ask price: ";
            cin >>askPrice;
            cout << "last price: ";
            cin >> lastPrice;
            cout << "contract size: ";
            cin >> contractSize;
            cout << "tick size: ";
            cin >> tickSize;
            cout << "contractMonths: ";
            cin >> contractMonths;
            futureTemp=new Future(name,underlyingName,bidPrice,askPrice,lastPrice,contractSize,tickSize,contractMonths);
            ofile << futureTemp->toString()<<"\n";
        }else{
            cout<<"input wrong! you can only choose among stock/option/future"<<endl;
            --i;
        }
	}
	ofile.close();



	system("pause");


	return 0;
}