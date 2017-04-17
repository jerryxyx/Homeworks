/*
 This project is based on original project made by Mark Joshi
 Author Yuxuan Xia
 New features:
 Add a payoff method defined by power option
 Add a command line singleton logger
 Add a file singleton logger
 */

#include "PayOff3.h"
#include "minmax.h"
#include "math.h"

PayOffCall::PayOffCall(double Strike_) : Strike(Strike_)
{
}

double PayOffCall::operator () (double Spot) const
{
    return max(Spot-Strike,0.0);
}

PayOff* PayOffCall::clone() const
{
    return new PayOffCall(*this);
}


double PayOffPut::operator () (double Spot) const
{
    return max(Strike-Spot,0.0);
}

PayOffPut::PayOffPut(double Strike_) : Strike(Strike_)
{
}

PayOff* PayOffPut::clone() const
{
    return new PayOffPut(*this);
}

//constructor
PayOffPowerCall::PayOffPowerCall(double strike_, double power_):strike(strike_),power(power_){};
//clone constructor
PayOff* PayOffPowerCall::clone() const{
    return new PayOffPowerCall(*this);
}
//operator()
double PayOffPowerCall::operator()(double spot) const{
    return max(pow(spot,power)-strike,0.0);
}
//constructor
PayOffPowerPut::PayOffPowerPut(double strike_, double power_): strike(strike_),power(power_){};
//const clone function
PayOff* PayOffPowerPut::clone()const{
    return new PayOffPowerPut(*this);
}
//const operator()
double PayOffPowerPut::operator()(double spot) const{
    return max(strike-pow(spot,power),0.0);
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

