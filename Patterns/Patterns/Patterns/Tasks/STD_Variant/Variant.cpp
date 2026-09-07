#include "Variant.h"
#include <iostream>
#include <variant>
#include <string>

void VariantTest::Test()
{
	std::variant<int, float, std::string> v;

	v = 10;
	v = "Hello";
	std::visit([](auto&& value)
		{
			std::cout << value;
		}, v);
}