/*
 This project is based on original project made by Mark Joshi
 Author Yuxuan Xia
 New features:
 Add a payoff method defined by power option
 Add a command line singleton logger
 Add a file singleton logger
 */

#include"SimpleMC5.h"
#include<iostream>
using namespace std;
#include"Vanilla3.h"
#include "Logger.h"
#include "Logging.h"

int main()
{
	double Expiry;
	double Strike;
    double Power;
	double Spot; 
	double Vol; 
	double r; 
	unsigned long NumberOfPaths;

    
	cout << "\nEnter expiry\n";
	cin >> Expiry;

	cout << "\nStrike\n";
	cin >> Strike;
    
    cout << "\nPower\n";
    cin >> Power;

	cout << "\nEnter spot\n";
	cin >> Spot;

	cout << "\nEnter vol\n";
	cin >> Vol;

	cout << "\nr\n";
	cin >> r;

	cout << "\nNumber of paths\n";
	cin >> NumberOfPaths;

    //PayOffCall thePayOff(Strike);
    PayOffPowerCall thePowerCallPayOff(Strike,Power);
    
    VanillaOption theOption(thePowerCallPayOff, Expiry);

	double result1 = SimpleMonteCarlo3(theOption,
                                      Spot, 
                                      Vol,
                                      r,
                                      NumberOfPaths);

	cout <<"\nthe call price is " << result1 << "\n";
    
    VanillaOption secondOption(theOption);
    result1 = SimpleMonteCarlo3(secondOption,
                               Spot, 
                               Vol,
                               r,
                               NumberOfPaths);

	cout <<"\nthe call price is " << result1 << "\n";

    //PayOffPut otherPayOff(Strike);
    PayOffPowerPut thePowerPutPayOff(Strike,Power);
    VanillaOption thirdOption(thePowerPutPayOff, Expiry);
    theOption = thirdOption;

    double result2 = SimpleMonteCarlo3(theOption,
                               Spot, 
                               Vol,
                               r,
                               NumberOfPaths);

    cout <<"\nthe put price is " << result2 << "\n";
    
    //Logger is a command line logger
    cout<<"Log in comand line"<<endl;
    Logger::instance()->setOutput(true);
    Logger::instance()->setPrefix("input information--");
    Logger::instance()->setPostfix("");
    Logger::instance()->newLine(2);
    Logger::instance()->log("Input:");
    Logger::instance()->log("strike:");
    Logger::instance()->log(Strike);
    Logger::instance()->log("spot:");
    Logger::instance()->log(Spot);
    Logger::instance()->log("power:");
    Logger::instance()->log(Power);
    Logger::instance()->log("expiry:");
    Logger::instance()->log(Expiry);
    Logger::instance()->log("vol:");
    Logger::instance()->log(Vol);
    Logger::instance()->log("rate:");
    Logger::instance()->log(r);
    Logger::instance()->log("Number of paths:");
    Logger::instance()->log(double(NumberOfPaths));
    Logger::instance()->setPrefix("output information--");
    Logger::instance()->log("call price:");
    Logger::instance()->log(result1);
    Logger::instance()->log("put price:");
    Logger::instance()->log(result2);
    
    //Logging is a file logger
    cout<<"log in file"<<endl;
     Logging::instance().log("*******************************************************","New Logger");
    Logging::instance().log("Input",Logging::kLogLevelInfo);
    Logging::instance().log(std::to_string(Strike),"strike");
    Logging::instance().log(std::to_string(Spot),"spot");
    Logging::instance().log(std::to_string(Power),"power");
    Logging::instance().log(std::to_string(Expiry),"expiry");
    Logging::instance().log(std::to_string(Vol),"volatility");
    Logging::instance().log(std::to_string(r),"interest rate");
    Logging::instance().log(std::to_string(NumberOfPaths),"number of paths");
    Logging::instance().log("Output",Logging::kLogLevelInfo);
    Logging::instance().log(std::to_string(result1),"call price of power option");
    Logging::instance().log(std::to_string(result2),"put price of power option");
    
    cout<<"Done! Please check the file logging.txt"<<endl;
    
//
//    double tmp;
//    cin >> tmp;

	return 0;

}
/*
 *
 * Copyright (c) 2002
 * Mark Joshi
 *
 * Permission to use, copy, modify, distribute and sell this
 * software for any purpose is hereby
 * granted without fee, provided that the above copyright notice
 * appear in all copies and that both that copyright notice and
 * this permission notice appear in supporting documentation.
 * Mark Joshi makes no representations about the
 * suitability of this software for any purpose. It is provided
 * "as is" without express or implied warranty.
*/


