//
//  main.cpp
//  midterm6
//
//  Created by 夏宇轩 on 2/27/17.
//  Copyright (c) 2017 夏宇轩. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

int reverse_number(int a);

int main(int argc, const char * argv[]) {
    // insert code here...
    int a=0;
    cout<<"please input number to be reversed: "<<endl;
    cin>>a;
    cout<<"the reversed number: "<<endl;
    cout<<reverse_number(a)<<endl;
    
    return 0;
}
int reverse_number(int a){
    int i,j,digit;
    int reverse_a=0;
    for(i=0;int(a/(pow(10,i)))>0;i++){
        //cout<<"a"<<int(a/(pow(10,i)))<<endl;
    }
    cout<<"the input number is "<<i<<" digit number"<<endl;
    
    for(j=i;j>0;j--){
        digit=a/(pow(10,j-1));
        a=a-digit*pow(10,j-1);
        reverse_a+=digit*pow(10,i-j);
    }
    return reverse_a;
}