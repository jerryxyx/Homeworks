/*
 This project is based on original project made by Mark Joshi
 Author Yuxuan Xia
 New features:
 Add a payoff method defined by power option
 Add a command line singleton logger
 Add a file singleton logger
 */

#ifndef PAYOFF3_H
#define PAYOFF3_H

class PayOff
{
public:

    PayOff(){};

    virtual double operator()(double Spot) const=0;
    virtual ~PayOff(){}
    virtual PayOff* clone() const=0;

private:
    
};

class PayOffCall : public PayOff
{
public:

    PayOffCall(double Strike_);

    virtual double operator()(double Spot) const;
    virtual ~PayOffCall(){}
    virtual PayOff* clone() const;

private:

    double Strike;

};


class PayOffPut : public PayOff
{
public:

    PayOffPut(double Strike_);

    virtual double operator()(double Spot) const;
    virtual ~PayOffPut(){}
    virtual PayOff* clone() const;

private:

    double Strike;

};

class PayOffPowerCall : public PayOff{
public:
    PayOffPowerCall(double strike_,double power_);
    virtual double operator()(double spot_) const;
    virtual ~PayOffPowerCall(){};
    virtual PayOff* clone() const;
private:
    double strike, power;
};

class PayOffPowerPut : public PayOff{
public:
    PayOffPowerPut(double strike_,double power_);
    virtual PayOff* clone()const;
    virtual double operator()(double spot)const;
    virtual ~PayOffPowerPut(){};
private:
    double strike,power;
};

#endif

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

