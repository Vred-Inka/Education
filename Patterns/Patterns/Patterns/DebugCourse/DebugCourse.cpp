#include "DebugCourse.h"
#include <format>
#include <iostream>
#include "User.h"

void DebugCourse::TestUser()
{
	User user(
		"Inna",
		Profile{
			"iv@example.com",
			Adress{.street = "Woli 16", .city = "Warszaw", .zip = 2699}
		},
		{ 10, 20, 30 }
	);

	std::cout << std::format("Name: {}\n", user.GetName());
	const char* pName = user.GetName().c_str();
	std::cout << std::format("City: {}\n", user.GetProfile().adress.city);

	constexpr int weight = 2;
	int weightedSum = user.Compute(weight);

	std::cout << std::format("Email: {}, weighted Score = {}\n", user.GetProfile().email, weightedSum);
	std::cout << std::format("Global Score: {}\n", g_Sum);
};