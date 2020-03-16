#include <cassert>
#include <string.h>
#include "tests.h"
#include "entity.h"

void tests() 
{


	Entity entity[5];
	char* name1 = new char[10];
	char* name2 = new char[10];
	char* name3 = new char[10];
	char* name4 = new char[10];
	char* name5 = new char[10];

	strcpy_s(name1, sizeof "Ion", "Ion");
	Entity s1(name1);

	strcpy_s(name2, sizeof "Maria", "Maria");
	Entity s2(name2);

	strcpy_s(name3, sizeof "Carmen", "Carmen");
	Entity s3(name3);

	strcpy_s(name4, sizeof "Radu", "Radu");
	Entity s4(name4);

	strcpy_s(name5, sizeof "John", "John");
	Entity s5(name5);

	entity[0] = s1;
	entity[1] = s2;
	entity[2] = s3;
	entity[3] = s4;
	entity[4] = s5;

	Entity s1;
	Entity s2('Ana');
	Entity s3 != s4;
	assert(s5.getName() == "John");
	s3.setName("Adrian");
	s4 = s1;
	assert(s4 == s1);
	//Student result[5];
	//int resultLen;

	//char* searchedName = new char[10];
	//strcpy_s(searchedName, sizeof "ar", "ar");

	/*filterStudents(students, 5, searchedName, 10, result, resultLen);

	assert(resultLen == 2);
	assert(students[1] == result[0]);
	assert(students[2] == result[1]);*/
}

void tests_with_repository()
{
	Entity entity[5];
	char* name1 = new char[10];
	char* name2 = new char[10];
	char* name3 = new char[10];
	char* name4 = new char[10];
	char* name5 = new char[10];

	strcpy_s(name1, sizeof "Ion", "Ion");
	Entity s1(name1);

	strcpy_s(name2, sizeof "Maria", "Maria");
	Entity s2(name2);

	strcpy_s(name3, sizeof "Carmen", "Carmen");
	Entity s3(name3);

	strcpy_s(name4, sizeof "Radu", "Radu");
	Entity s4(name4);

	strcpy_s(name5, sizeof "John", "John");
	Entity s5(name5);

	entity[0] = s1;
	entity[1] = s2;
	entity[2] = s3;
	entity[3] = s4;
	entity[4] = s5;

	Entity s1("Ion);
	Repository 
}