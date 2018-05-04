// Duane Shaffer
// CS372
// Program to demonstrate use of the proxy design pattern

#include "proxyService.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main () {
    ProxyService test;
	std::cout << "Test has been created but did not perform the expensive operation" << endl;

	test.networkRequest();
	test.searchData();
	test.networkRequest();
	test.printRequestLog();
	// Wait for user
	cout << "Press ENTER to quit ";
	while (cin.get() != '\n');

    return 0;
}