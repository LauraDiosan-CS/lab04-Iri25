#pragma once
#ifndef TESTS_REPOSITORY
#define TESTS_REPOSITORY
#include "repository.h"

class TestRepository
{
private:
	Repository repository;

	void tests_constructors();
	void test_addMovie();
	void test_updateMovie();
	void test_deleteMovie();
	void test_getAll();
public:
	TestRepository();
	~TestRepository();

	void run_TestRepository();
};

#endif //TESTS_REPOSITORY

