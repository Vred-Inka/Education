#pragma once

#include <cassert>
#include <iostream>
#include <ostream>
#include "Log.h"
#include "MemoryDebug.h"
#include "Parser.h"


#include "../Tasks/Inventory/Inventory.h"

namespace  MemoryTest
{
    void Test()
    {
        int a = 0;
        int* b = new int(0);
        std::cout << "size of a " << sizeof(a) << std::endl;
        std::cout << "size of b " << sizeof(b) << std::endl;

        Inventory inventory;
        std::cout << "size of inventory " << sizeof(inventory) << std::endl;
        inventory.AddItem("Goold", 2000);
        std::cout << "size of inventory " << sizeof(inventory) << std::endl;
        std::cout << "size of inventory " << sizeof(inventory.m_Items) << std::endl;        
    }

    int Function1(int a, int b)
    {
		std::cout << "Function1 called with a = " << a << ", b = " << b << std::endl;
        return a + b;
	}

    void FunctionPointerTest()
    {
		void (*functionPointer)() = &Test;
		int (*functionPointer2)(int a, int b) = Function1;

        functionPointer();
        functionPointer2(5, 10);
    }

    void AdressTest()
    {
        int x{};
		std::cout << "Value of x: " << x << std::endl;
		std::cout << "Address of x: " << &x << std::endl;

        int a = 5;
        int* ptr = &a;
        std::cout << "Address of a: " << &a << std::endl;
        std::cout << "Address stored in ptr: " << ptr << std::endl;
        std::cout << "Value pointed to by ptr: " << *ptr << std::endl;
        *ptr = 10;
        std::cout << "New value of a after modifying through ptr: " << a << std::endl;

        const char* str = "nullptr";
        if (str)
            Log(str);
	}

    void FunctionNamesTest()
    {
        Array<int> s1{};
        std::cout << std::endl;
        Array<int> s2{ 10 };
    }

    void ParserTest()
    {
        std::string validInt = "12345";
        std::string invalidInt = "12a45";
        std::string validPort = "8080";
        std::string invalidPort = "70000";
        try
        {
			int parsedInt = Parser::ParseInt(validPort);
            std::cout << "Parsed integer: " << parsedInt << std::endl;
        }
        catch (const std::runtime_error& e)
        {
            std::cout << "Error parsing integer: " << e.what() << std::endl;
        }
        try
        {
            int parsedInt = Parser::ParseInt(invalidInt);
            std::cout << "Parsed integer: " << parsedInt << std::endl;
        }
        catch (const std::runtime_error& e)
        {
            std::cout << "Error parsing integer: " << e.what() << std::endl;
        }
        try
        {
            int port = Parser::ReadPortFromConfig(validPort);
            std::cout << "Parsed port: " << port << std::endl;
        }
        catch (const std::runtime_error& e)
        {
            std::cout << "Error reading port: " << e.what() << std::endl;
        }
        try
        {
            int port = Parser::ReadPortFromConfig(invalidPort);
            std::cout << "Parsed port: " << port << std::endl;
        }
        catch (const std::runtime_error& e)
        {
            std::cout << "Error reading port: " << e.what() << std::endl;
        }
	}

    void AssertingWIthSideEffects()
    {
        //bad one
        // char* buff{};
		// assert((buff = (char*)malloc(100)) && "Memory allocation failed");

		size_t size = 100;
        char* buff{};
		buff = (char*)malloc(size);

        if (buff == nullptr)
        {
            //Handle null condition
        }
    }

	//Asserting business logic
    bool WithinRange(double percentage)
    {
        return percentage >= 0 && percentage <= 10;
	}

    double ApplyDiscount(double price, double percentage)
    {    
        // bad
        // assert(percentage>=0 &&  percentage <= 10 && "wrong percentage");

        if (!WithinRange(percentage))
        {
            _RPTF2(_CRT_WARN, "Wrong percentage for price %u - %u\n", price, percentage);
            return price;
		}

        return price - (price * percentage);
	}

    void TestDiscount()
    {
        ApplyDiscount(100, 5);
        ApplyDiscount(100, 15);
    }


    template<typename T, size_t size>
    void Process(const T(&arr)[size])
    {
        static_assert(size < 128, "Array size is too large");

    }

    void ProcessArray()
    {
        int arr[20];//[200];
        Process(arr);
    }

    template<typename T>
    void Serialize(const T& obj)
    {
		static_assert(std::is_trivially_copyable_v<T>, "Only trivial types can be serialized");
		static_assert(sizeof(T) <= 64, "Object size is too large to serialize");
	}

    struct Product
    {
        char code[10]{};
        int id{-1};
        //std::string name{};
    };

    void SerializeObject()
    {
        Product p;
		Serialize(p);

	}

    //static_assert(sizeof(void*) == 8, "Only 64-bit platform supported");


    void AllTests()
    {
        Test();
        FunctionPointerTest();
        AdressTest();
        FunctionNamesTest();
        ParserTest();
        TestDiscount();
		ProcessArray();
	}
}
