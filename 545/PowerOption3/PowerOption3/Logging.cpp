//
//  Logging.cpp
//  PowerOption3
//
//  Created by 夏宇轩 on 3/30/17.
//  Copyright (c) 2017 Yuxuan Xia. All rights reserved.
//
#include <stdexcept>
#include "Logging.h"

using namespace std;

const string Logging::kLogLevelDebug = "DEBUG";
const string Logging::kLogLevelInfo = "INFO";
const string Logging::kLogLevelError = "ERROR";

const char* const Logging::kLogFileName = "logging.txt";

Logging* Logging::pInstance = nullptr;

mutex Logging::sMutex;

Logging& Logging::instance()
{
    static Cleanup cleanup;
    
    lock_guard<mutex> guard(sMutex);
    if (pInstance == nullptr)
        pInstance = new Logging();
    return *pInstance;
}

Logging::Cleanup::~Cleanup()
{
    lock_guard<mutex> guard(Logging::sMutex);
    delete Logging::pInstance;
    Logging::pInstance = nullptr;
}

Logging::~Logging()
{
    mOutputStream.close();
}

Logging::Logging()
{
    mOutputStream.open(kLogFileName, ios_base::app);
    if (!mOutputStream.good()) {
        throw runtime_error("Unable to initialize the Logging!");
    }
}

void Logging::log(const string& inMessage, const string& inLogLevel)
{
    lock_guard<mutex> guard(sMutex);
    logHelper(inMessage, inLogLevel);
}

void Logging::log(const vector<string>& inMessages, const string& inLogLevel)
{
    lock_guard<mutex> guard(sMutex);
    for (size_t i = 0; i < inMessages.size(); i++) {
        logHelper(inMessages[i], inLogLevel);
    }
}

void Logging::logHelper(const std::string& inMessage, const std::string& inLogLevel)
{
    mOutputStream << inLogLevel << ": " << inMessage << endl;
}
