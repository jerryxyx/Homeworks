//
//  main.cpp
//  midterm
//
//  Created by 夏宇轩 on 2/27/17.
//  Copyright (c) 2017 夏宇轩. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    // open and input the contents
    int n_lines=0;
    string lineContent;
    ofstream ofile;
    ofile.open("input.txt",ios::trunc);
    if(ofile.is_open()){
        cout<<"How many lines do you need to input？"<<endl;
        cin>>n_lines;
        for(int i = 0; i < n_lines;i++){
            cout<<"please in put the "<<i+1<<" line:"<<endl;
            cin>>lineContent;
            ofile<<lineContent<<"\n";
        }
    }else{
        cout<<"Open file failure"<<endl;
    }
    ofile.close();
    
    
    
    
    // open file and print the last K lines
    ifstream ifile;
    int count=0;
    int k_lines;
    
    ifile.open("input.txt");
    if(ifile.is_open()){
        cout<<"how many last lines do you want to read?"<<endl;
        cin>>k_lines;
        if(k_lines>n_lines){
            k_lines=n_lines;
            cout<<"k_lines>n_lines"<<endl;
        }
        while(getline(ifile,lineContent)){
            if( ++count > (n_lines-k_lines) ){
                cout<<lineContent<<endl;
            }
        }
    }
    
    ifile.close();
    
    return 0;
}
