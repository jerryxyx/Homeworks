//
//  quotelib.h
//  
//
//  Created by 夏宇轩 on 2/15/17.
//
//

#ifndef _quotelib_h
#define _quotelib_h
#include <iostream>
#include <string>
using std::string; using std::to_string;
using std::cout; using std::endl; using std::cin;

class Quote {
public:
	Quote(string instrument, string name) : instrument(instrument), name(name) {
		//id_=total++;
	}
	virtual void printQuote() = 0;
	virtual string toString() = 0;
protected:
	string instrument;
	string name;
	//int id_;
	//static int total;
};

//The stock quote includes stock name(12 characters), bid price,  ask price,  last price, and issue exchange.
class Stock : public Quote {
public:
	Stock(string stockName = "default", float bidPrice = 0, float askPrice = 0, float lastPrice = 0, int issueExchange = 0)
		: Quote("stock", stockName), bidPrice(bidPrice), askPrice(askPrice), lastPrice(lastPrice), issueExchange(issueExchange) {}
	void reDim(string stockName = "default", float bidPrice = 0, float askPrice = 0, float lastPrice = 0, int issueExchange = 0) {
		name = stockName;
		bidPrice = bidPrice;
		askPrice = askPrice;
		lastPrice = lastPrice;
		issueExchange = issueExchange;
	}
	void printQuote() {
		cout << "stock name:" << name << " bid price:" << bidPrice << " ask price:" << askPrice << " last price:" << lastPrice << " issue exchange:" << issueExchange << endl;
	}
	string toString() {
		return instrument + " " + name + " " + to_string(bidPrice) + " " + to_string(askPrice) + " " + to_string(lastPrice) + " " + to_string(issueExchange);
	}
protected:
	float bidPrice, askPrice, lastPrice;
	int issueExchange;
};

//The option quote includes option name (26 characters), underlying name(12 characters), bid price,  ask price,  last price, contract size, and expire date.
class Option : public Quote {
public:
	Option(string optionName = "default", string underlyingName = "default", float bidPrice = 0, float askPrice = 0, float lastPrice = 0, int contractSize = 0, int expireDate = 0)
		: Quote("option", optionName), underlyingName(underlyingName), bidPrice(bidPrice), askPrice(askPrice), lastPrice(lastPrice), contractSize(contractSize), expireDate(expireDate) {}
	void reDim(string optionName = "default", string underlyingName = "default", float bidPrice = 0, float askPrice = 0, float lastPrice = 0, int contractSize = 0, int expireDate = 0) {
		name = optionName;
		underlyingName = underlyingName;
		bidPrice = bidPrice;
		askPrice = askPrice;
		lastPrice = lastPrice;
		contractSize = contractSize;
		expireDate = expireDate;
	}
	void printQuote() {
		cout << "option name:" << name << " underlying name:" << underlyingName << " bid price:" << bidPrice << " ask price:" << askPrice << " last price:" << lastPrice;
		cout << " contractSize:" << contractSize << " expire date:" << expireDate << endl;
	}
	string toString() {
		return instrument + " " + name + " " + underlyingName + " " + to_string(bidPrice) + " " + to_string(askPrice) + " " + to_string(lastPrice) + " " + to_string(contractSize) + " " + to_string(expireDate);
	}
protected:
	string underlyingName;
	float bidPrice, askPrice, lastPrice;
	int contractSize, expireDate;
};

//The future quote includes future name (12 characters), underlying name(12 characters), bid price, ask price,  last price, contract size, tick size,and contract months.
class Future : public Quote {
public:
	Future(string futureName = "default", string underlyingName = "default", float bidPrice = 0, float askPrice = 0, float lastPrice = 0, int contractSize = 0, int tickSize = 0, int contractMonths = 0)
		: Quote("future", futureName), underlyingName(underlyingName), bidPrice(bidPrice), askPrice(askPrice), lastPrice(lastPrice), contractSize(contractSize), tickSize(tickSize), contractMonths(contractMonths) {}
	void reDim(string futureName = "default", string underlyingName = "default", float bidPrice = 0, float askPrice = 0, float lastPrice = 0, int contractSize = 0, int tickSize = 0, int contractMonths = 0) {
		name = futureName;
		underlyingName = underlyingName;
		bidPrice = bidPrice;
		askPrice = askPrice;
		lastPrice = lastPrice;
		contractSize = contractSize;
		tickSize = tickSize;
		contractMonths = contractMonths;
	}
	void printQuote() {
		cout << "future name:" << name << " underlying name:" << underlyingName << " bid price:" << bidPrice << " ask price:" << askPrice << " last price:" << lastPrice;
		cout << " contractSize:" << contractSize << " tick size:" << tickSize << " contract months:" << contractMonths << endl;
	}
	string toString() {
		return instrument + " " + name + " " + underlyingName + " " + to_string(bidPrice) + " " + to_string(askPrice) + " " + to_string(lastPrice) + " " + to_string(contractSize) + " " + to_string(tickSize) + " " + to_string(contractMonths);
	}
protected:
	string underlyingName;
	float bidPrice, askPrice, lastPrice;
	int contractSize, tickSize, contractMonths;
};


class quoteFactory {
public:
	virtual Quote* createStock() = 0;
	virtual Quote* createOption() = 0;
	virtual Quote* createFuture() = 0;
	virtual Quote* createStock(string stockName, float bidPrice, float askPrice, float lastPrice, float issueExchange) = 0;
	virtual Quote* createOption(string optionName, string underlyingName, float bidPrice, float askPrice, float lastPrice, float contractSize, float expireDate) = 0;
	virtual Quote* createFuture(string futureName, string underlyingName, float bidPrice, float askPrice, float lastPrice, int contractSize, int tickSize, int contractMonths) = 0;
};

class myQuoteFactory : public quoteFactory {
public:
	Quote* createStock(string stockName = "default", float bidPrice = 0, float askPrice = 0, float lastPrice = 0, int issueExchange = 0) {
		return new Stock(stockName, bidPrice, askPrice, lastPrice, issueExchange);
	}
	Quote* createOption(string optionName = "default", string underlyingName = "default", float bidPrice = 0, float askPrice = 0, float lastPrice = 0, int contractSize = 0, int expireDate = 0) {
		return new Option(optionName, underlyingName, bidPrice, askPrice, lastPrice, contractSize, expireDate);
	}
	Quote* createFuture(string futureName = "default", string underlyingName = "default", float bidPrice = 0, float askPrice = 0, float lastPrice = 0, int contractSize = 0, int tickSize = 0, int contractMonths = 0) {
		return new Future(futureName, underlyingName, bidPrice, askPrice, lastPrice, contractSize, tickSize, contractMonths);
	}
	Quote* createStock() {
		return new Stock();
	};
	Quote* createOption() {
		return new Option();
	};
	Quote* createFuture() {
		return new Future();
	};
};


#endif

