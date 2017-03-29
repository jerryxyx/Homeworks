//
//  main.cpp
//  midterm5
//
//  Created by 夏宇轩 on 2/27/17.
//  Copyright (c) 2017 夏宇轩. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    for(int i=1;i<=100;i++){
        if(i%3==0){
            cout<<"Fizz";
        }
        if(i%4==0){
            cout<<"Buzz";
        }
        if(i%4!=0&&i%3!=0){
            cout<<i;
        }
    }
    return 0;
}
