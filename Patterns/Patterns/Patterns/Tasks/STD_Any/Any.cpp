#include "Any.h"
#include <any>
#include <iostream>
#include <string>

void AnyTest::Test()
{
	std::any a = 10;
	a = std::string("hello");
	a = 2.555;

	try
	{
		std::cout << std::any_cast<std::string>(a) << std::endl;
	}
	catch (const std::bad_any_cast&)
	{
		std::cout << "Wrong type!" << std::endl;
	}
}