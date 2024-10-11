#include <Windows.h>
#include <iostream>

#include "include/vswhere.h"

int main()
{
	printf("[ BEGIN ]\n");
	printf("%s", GetVisualStudioInstancesMetadata("-format json").c_str());
	printf("[  END  ]\n");
	return EXIT_SUCCESS;
}