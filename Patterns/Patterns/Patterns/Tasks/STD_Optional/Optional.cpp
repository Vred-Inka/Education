#include "Optional.h"

#include <iostream>
#include <optional>	

std::optional<int> divide(int a, int b)
{
	if (b == 0)
	{
		return std::nullopt;
	}
	return a / b;
}

void OptionalTest::Test()
{
	auto result = divide(10, 2);

	if (result)
	{
		std::cout << *result << std::endl;
	}
}