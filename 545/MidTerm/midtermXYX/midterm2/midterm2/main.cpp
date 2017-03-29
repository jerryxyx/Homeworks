//
//  main.cpp
//  midterm2
//
//  Created by 夏宇轩 on 2/27/17.
//  Copyright (c) 2017 夏宇轩. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    for(int i=0;i<=200;i=i+5){
        int j=i++;
        cout<<j<<" ";
        i--;
    }
    return 0;
}
