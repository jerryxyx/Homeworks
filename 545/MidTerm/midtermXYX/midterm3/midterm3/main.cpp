//
//  main.cpp
//  midterm3
//
//  Created by 夏宇轩 on 2/27/17.
//  Copyright (c) 2017 夏宇轩. All rights reserved.
//

#include <iostream>
using namespace std;


void myfun(float* A,float* B,int n);

int main(int argc, const char * argv[]) {
    // insert code here...
    float a[5]={1,2,3,4,5};
    float b[5];
    for(int i=0;i<5;i++){
        cout<<"a["<<i<<"]="<<a[i]<<endl;
        b[i]=0;
    }
    myfun(a,b,5);
    cout<<"after inplementation, we can see B[i] is the mean of all A[j] where j != i"<<endl;
    for(int i=0;i<5;i++){
        cout<<"b["<<i<<"]="<<b[i]<<endl;
    }
    return 0;
}

void myfun(float* A,float* B,int n){
    int i,j;
    for(j=0;j<n;j++){
        for(i=0;i<n;i++){
            if(i!=j){
                *(B+j)=*(B+j)+*(A+i);
            }
        }
        *(B+j)=float(*(B+j))/float(n);
    }
    return;
}