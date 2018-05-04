// Duane Shaffer
// CS372
// Program to demonstrate use of the proxy design pattern
// The proxy design pattern allows a placeholder to be used for an 
// object. This program will demonstrate the applicability of this 
// design pattern for a pretend service that has slow initialization.
// It will also implement request logging, simulating what would happen
// if we wanted to add functionality to the pretend service but cannot
// due to it being a third party library.

#include "proxyService.h"
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;
#include <vector> 
using std::vector;
#include <memory>
using std::make_unique;
#include <utility>
using std::move;


PretendService::PretendService() {
    std::cout << "Initializing Pretend Service" << endl;
    expensiveOperation();
};

std::string PretendService::networkRequest () {
        expensiveOperation();
        return "Pretend Data from Network Request";
    };

bool PretendService::searchData() {
        expensiveOperation();
        // pretend that the data desired was found
        return true;
    }
void PretendService::expensiveOperation () {
    std::cout << "Performing expensive operation!" << endl;
}


std::string ProxyService::networkRequest () {
    ensureInitialization();
    requestLog.push_back("Network Request ");
    return proxiedService->networkRequest();
}

bool ProxyService::searchData() {
    ensureInitialization();
    requestLog.push_back("Search Data ");
    return proxiedService->searchData();
}

void ProxyService::printRequestLog() {
    for (auto i: requestLog) {
        cout << i;
    }
    cout << endl;
}

void ProxyService::ensureInitialization() {
    if (!isServiceInitialized) {
        proxiedService = make_unique<PretendService>();
		isServiceInitialized = true;
    }
}
