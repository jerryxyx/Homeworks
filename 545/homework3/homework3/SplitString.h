//
//  SplitString.h
//  homework3
//
//  Created by yuxuan Xia on 2/10/17.
//  Copyright (c) 2017 yuxuan Xia. All rights reserved.
//

#ifndef homework3_SplitString_h
#define homework3_SplitString_h
#include <iostream>
using std::cout; using std::getline;
#include <iterator>
using std::ostream_iterator;
#include <string>
using std::string;
#include <sstream>
using std::istringstream;
#include <vector>
using std::vector;
#include <algorithm>
using std::copy;
using namespace std;

//string spliting function
vector<string> &split(const string &str, char delim, vector<string> &elems, bool skip_empty = true) {
    istringstream iss(str);
    for (string item; getline(iss, item, delim); )
        if (skip_empty && item.empty()) continue;
        else elems.push_back(item);
    return elems;
}

#endif
