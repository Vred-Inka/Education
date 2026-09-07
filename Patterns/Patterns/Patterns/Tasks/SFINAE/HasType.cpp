#include "HasType.h"
#include <type_traits>
#include <utility>
#include <iostream>
#include <vector>

template <typename T>
struct has_size_impl
{
private:
	template <typename U>
	static auto test(int) -> decltype(std::declval<U>().size(), std::true_type{});

	template <typename>
	static std::false_type test(...);

public:
	static constexpr bool has_size = decltype(test<T>(0))::value;
};

void HasType::Test()
{
	std::cout << has_size_impl<std::vector<int>>::has_size << "\n";
	std::cout << has_size_impl<int>::has_size << "\n";
}
