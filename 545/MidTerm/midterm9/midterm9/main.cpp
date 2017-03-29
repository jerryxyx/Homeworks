//
//  main.cpp
//  midterm9
//
//  Created by 夏宇轩 on 2/27/17.
//  Copyright (c) 2017 夏宇轩. All rights reserved.
//

#include <iostream>
using namespace std;
float my_mean(int a[],int n);
int main(int argc, const char * argv[]) {
    // insert code here...
    int a[10];
    for(int i=0;i<10;i++){
        cout<<"a["<<i<<"]: ";
        cin>>a[i];
        cout<<endl;
    }
    cout<<"the mean of your array is: "<<my_mean(a,10)<<endl;
    
    return 0;
}
float my_mean(int* a, int n){
    float a_mean=0;
    for(int i=0;i<n; i++){
        a_mean+=*a;
        a++;
    }
    a_mean=a_mean/float(n);
    return a_mean;
}