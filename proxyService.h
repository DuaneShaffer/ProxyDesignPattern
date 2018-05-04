// Duane Shaffer
// CS372
// Program to demonstrate use of the proxy design pattern
// The proxy design pattern allows a placeholder to be used for an 
// object. This program will demonstrate the applicability of this 
// design pattern for a pretend service that has slow initialization.
// It will also implement request logging, simulating what would happen
// if we wanted to add functionality to the pretend service but cannot
// due to it being a third party library.

#include <string>
// std::string
#include <vector>
// std::vector
#include <memory>
// std::unique_ptr

class PretendService {
public:

    // Simulate initialization of a resource intensive
    // pretend service
    PretendService();
    
    // Use auto-generated copy/move ctor, dctor, copy/move op=
    // PretendService(const PretendService & other) = default;
    // PretendService(PretendService && other) = default;
    // ~PretendService () = default;
    // PretendService & operator=(const PretendService & other) = default;
    // PretendService & operator=(PretendService && other) = default;

    // simulating a network request for data
    std::string networkRequest();

    //simulating a search through a database
    bool searchData();

private: 
    void expensiveOperation();
};


class ProxyService {
public:
    std::string networkRequest();
    bool searchData();
    void printRequestLog();

private: 
    bool isServiceInitialized = false;
    std::unique_ptr<PretendService> proxiedService;
    std::vector<std::string> requestLog;
    void ensureInitialization ();
};
