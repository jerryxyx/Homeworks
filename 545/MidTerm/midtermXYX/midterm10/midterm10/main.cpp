//
//  main.cpp
//  midterm10
//
//  Created by 夏宇轩 on 2/27/17.
//  Copyright (c) 2017 夏宇轩. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

float mid_item(vector<int> myvector);
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a;
    cout<<"your vector is initialized as: "<<endl;
    for(int i = 0;i<9;i++){
        a.push_back(i);
        cout<<a.back()<<",";
    }
    cout<<endl;
    cout<<"the middle item is: "<<endl;
    cout<<mid_item(a);
    
    return 0;
}

float mid_item(vector<int> myvector){
    vector<int>::iterator it=myvector.begin();
    int mid_index;
    
    if(myvector.size()%2!=0){
        return *(it+myvector.size()/2);
    }else{
        cout<<"Since the there are two middle items, the mean value of the middle items is: ";
        mid_index = int(myvector.size()-1)/2;
        return float(*(it+mid_index)+*(it+mid_index+1))/2.0;
    }
    return *(it+myvector.size()/2);
}