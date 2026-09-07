#include "MemoryDebug.h"
#include <cassert>
#include <stack>
#include <cassert>
#include <thread>


void Copy(const char* pStr)
{
	assert(pStr != nullptr);
	assert(strlen(pStr) != 0);
}

template<typename T>
const T& Array<T>::operator[](size_t index) const
{
    assert(index < m_Length);
    return m_pBuffer[index];
}

int pop(std::stack<int>& commands)
{
	assert(!commands.empty() && "pre: stack should be  not empty");

	const auto old_size = commands.size();
	const int top = commands.top();
	commands.pop();


	assert(commands.size() == old_size - 1 && "post: size decreased by one");
	return top;
}

class Worker
{

	std::thread thr_;
	bool work_done_ = false;

	void do_work()
	{
		// Simulate some work being done
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	void start_and_join()
	{
		assert(!thr_.joinable() && "pre: thread must not already be running");
		work_done_ = false;
		thr_ = std::thread([this]
			{
				do_work();
				work_done_ = true;
			});
		thr_.join();

		assert(!thr_.joinable() && "post: thread still running");
		assert(work_done_ && "post: work in progress");
	}
};

class Card
{
public:

	void Validate() const
	{
		assert(m_Balance >= 0 && "pre: balance should be non-negative");
		assert(m_Currency.size() == 3 && "invariant: CUrrency must be 3 letters");
	}

	void Deposit(long long amount)
	{
		assert(amount >= 0 && "pre: deposit negative");
		m_Balance += amount;
		Validate();
	}

	bool Withdraw(long long amount)
	{
		assert(amount >= 0 && "pre: withdraw negative");
		if (amount > m_Balance)
		{
			return false;
		}
		m_Balance -= amount;
		Validate();
		return true;
	}

private:
	long long m_Balance{ 0 };
	std::string m_Currency{ "USD" };
};




