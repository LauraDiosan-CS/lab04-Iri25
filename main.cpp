#include <iostream>
#include "domain.h"
#include "repository.h"
#include "service.h"
#include "user_interface.h"
#include "tests.h"


using namespace std;

int main()
{
	run();
	tests();
	tests_with_repository();
	tests_with_service();
	return 0;
}
