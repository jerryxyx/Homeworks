//
//  Logging.h
//  PowerOption3
//
//  Created by 夏宇轩 on 3/30/17.
//  Copyright (c) 2017 Yuxuan Xia. All rights reserved.
//

#ifndef __PowerOption3__Logging__
#define __PowerOption3__Logging__




#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <mutex>

// Definition of a multithread safe singleton Logging class
class Logging
{
public:
    static const std::string kLogLevelDebug;
    static const std::string kLogLevelInfo;
    static const std::string kLogLevelError;
    
    // Returns a reference to the singleton Logging object
    static Logging& instance();
    
    // Logs a single message at the given log level
    void log(const std::string& inMessage,
             const std::string& inLogLevel);
    
    // Logs a vector of messages at the given log level
    void log(const std::vector<std::string>& inMessages,
             const std::string& inLogLevel);
    
protected:
    // Static variable for the one-and-only instance
    static Logging* pInstance;
    
    // Constant for the filename
    static const char* const kLogFileName;
    
    // Data member for the output stream
    std::ofstream mOutputStream;
    
    // Embedded class to make sure the single Logging
    // instance gets deleted on program shutdown.
    friend class Cleanup;
    class Cleanup
    {
    public:
        ~Cleanup();
    };
    
    // Logs message. The thread should own a lock on sMutex
    // before calling this function.
    void logHelper(const std::string& inMessage,
                   const std::string& inLogLevel);
    
private:
    Logging();
    virtual ~Logging();
    Logging(const Logging&);
    Logging& operator=(const Logging&);
    static std::mutex sMutex;
};




#endif // LOGGING_H

