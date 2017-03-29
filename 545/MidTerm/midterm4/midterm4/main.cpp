//
//  main.cpp
//  midterm4
//
//  Created by 夏宇轩 on 2/27/17.
//  Copyright (c) 2017 夏宇轩. All rights reserved.
//

#include <iostream>
int fabonacci_with_recursion(int a1, int a2, int n);
int fabonacci_without_recursion(int a1, int a2, int n);
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int a1, a2, n_index;
    cout << "Input 2 numbers to generat a fabonacci sequence"<<endl;
    cin>>a1>>a2;
    cout << "Which item do you want(input the index of item)"<<endl;
    cin >> n_index;
    cout << "the result of the recursive function"<<endl;
    cout << "fabonacci["<<n_index<<"]="<<fabonacci_with_recursion(a1, a2, n_index)<<endl;
    cout << "the result of the non-recursive function"<<endl;
    cout << "fabonacci["<<n_index<<"]="<<fabonacci_without_recursion(a1, a2, n_index)<<endl;
    return 0;
}

int fabonacci_with_recursion(int a1, int a2, int n){
    if(n<1){
        cout<<"n<1! wrong input!"<<endl;
        return 0;
    }else if(n==1){
        return a1;
    }else if(n==2){
        return a2;
    }else if(n==3){
        return a1+a2;
    }else{
        int a3 = fabonacci_with_recursion(a1, a2, 3);
        a1=a2;
        a2=a3;
        return fabonacci_with_recursion(a1,a2,n-1);
    }
}

int fabonacci_without_recursion(int a1, int a2, int n){
    int a3=0;
    if(n<1){
        cout<<"n<1! wrong input!"<<endl;
        return 0;
    }else if(n==1){
        return a1;
    }else if(n==2){
        return a2;
    }else{
        for(int i=3;i<=n;i++){
            a3 = a1+a2;
            a1=a2;
            a2=a3;
        }
        return a3;
    }
}