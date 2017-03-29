/*
 * Theater.h
 *
 *  Created on: Feb 5, 2017
 *      Author: yuxuan
 */
#include<iostream>
using namespace std;

#ifndef THEATER_H_
#define THEATER_H_

class Theater/* : public TheaterInterface*/{
private:
    int n_rows;
    int resid;
    int n_people;
    int n_columns;
public:
    Theater(int m):n_columns(m),n_people(0),n_rows(1){};//constructor
    void inject(int);//when people go to theater
    void information();//output result
};

void Theater::inject(int n) {
    n_people = n;
    while(n-n_columns>0){
        n=n-n_columns;
        ++n_rows;
    }
    if(n-n_columns<0){
        resid=n;
    }else{
        resid=n_columns;
    }
    /*switch(n-n_columns==0){
     case(false): resid=n;
     case(true): resid=n_columns;
     }*/
};

void Theater::information(){
    cout<<"There are "<<n_rows<<" rows"<<endl;
    cout<<"The last row have "<<resid<<" students"<<endl;
}




#endif /* THEATER_H_ */
