#include "LockTest.h"

#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <vector>
#include <thread>	

std::shared_mutex mutex;
static int value = 0;

void LockTest::Reader(int id)
{
	std::shared_lock lock(mutex); // multiple readers allowed
	std::cout << "Reader:" << id << " sees value = " << value << "\n";
}

void LockTest::Writer(int id)
{
	std::unique_lock lock(mutex);
	value++;
	std::cout << "Writer" << id << " updated value to " << value << "\n";
}


void LockTest::Test()
{
    std::vector<std::thread> threads;

    for (int i = 0; i < 3; ++i)
    {
        threads.emplace_back(LockTest::Reader, i);
    }

    for (int i = 0; i < 2; ++i)
    {
        threads.emplace_back(LockTest::Writer, i);
    }

    for (auto& t : threads)
    {
        t.join();
    }
}