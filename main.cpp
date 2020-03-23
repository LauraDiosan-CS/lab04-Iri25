#include <iostream>
#include "domain.h"
#include "repository.h"
#include "service.h"
#include "user_interface.h"
#include "tests_domain.h"
#include "tests_repository.h"
#include "tests_service.h"


using namespace std;

int main()
{
	run();
	tests_with_domain();
	tests_with_repository();
	tests_with_service();
	

	return 0;
}
