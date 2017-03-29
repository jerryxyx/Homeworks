//
//  main.cpp
//  midterm7
//
//  Created by 夏宇轩 on 2/27/17.
//  Copyright (c) 2017 夏宇轩. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>

using namespace std;
set<string> find_repeat(string str);
int main(int argc, const char * argv[]) {
    // insert code here...
    string str_sequence;
    set<string> repeat_set;
    cout<<"please input a sequence, I'll figure out all repeated sequences:"<<endl;
    cin>>str_sequence;
    //str_sequence="abccbaabcdecba";
    repeat_set=find_repeat(str_sequence);
    for(set<string>::iterator it= repeat_set.begin();it!=repeat_set.end();it++){
        cout<<*it<<",";
    }
    return 0;
}
set<string> find_repeat(string str){
    int i,j;
    string sub_sequence;
    set<string> str_set;
    set<string> repeat_set;
    for(j=2;j<str.length();j++){
        for(i=0; i+j-1<str.length(); ++i){
            sub_sequence=str.substr(i,j);
            if(str_set.count(sub_sequence)){
                repeat_set.insert(sub_sequence);
            }else{
                str_set.insert(sub_sequence);
            }
        }
    }
    return repeat_set;
}