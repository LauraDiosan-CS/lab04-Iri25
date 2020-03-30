#pragma once
#ifndef TESTS_DOMAIN
#define TESTS_DOMAIN
#include <ostream>

using namespace std;

class TestDomain
{
private:
	void tests_constructors();
	void test_operator();

	void test_getTitle();
	void test_getDate();
	void test_getGenre();

	void test_setTitle();
	void test_setDate();
	void test_setGenre();
public:
	TestDomain();
	~TestDomain();

	void run_TestDomain();
};

#endif // TESTS_DOMAIN


