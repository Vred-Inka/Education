#pragma once

//#include "Algorithms/A_Search.cpp"

#include "Algorithms/AABB.h"

#include "DesignPatterns/Command/CommandTest.h"
#include "Tasks/Hotel/HotelRoom.h"
#include "DebugCourse/DebugCourse.h"

#include "Tasks/Hotel/HotelTest.h"
#include "Tasks/Inventory/InventoryTest.h"
#include "Tasks/Multithreading/LockTest.h"
#include "Tasks/SFINAE/HasType.cpp"
#include "Tasks/STD_Any/Any.h"
#include "Tasks/STD_Optional/Optional.h"
#include "Tasks/STD_Variant/Variant.h"
#include "Tasks/ReverseString.h"

#include "Tools/MemoryTest.cpp"


using namespace std;

int main(int argc, char* argv[])
{
    //Algorytms    
    //int i = aSearch::pathSearchAStar();
    //AABB::Test();

    // Design Patterns
    //CommandPattern::Test();
    
    // Tasks
    //InventoryTest::Test();
    //ReverseString::Test();

    //Tools
	MemoryTest::AllTests();
    DebugCourse::TestUser();

	OptionalTest::Test();
    VariantTest::Test();
    AnyTest::Test();
	HasType::Test();
   // LockTest::Test();


   //HotelTest::TestRooms();


    int n;
    std::cin >> n;
    std::vector<HotelRoom*> rooms;
    for (int i = 0; i < n; ++i) {
        std::string room_type;
        int bedrooms;
        int bathrooms;
        std::cin >> room_type >> bedrooms >> bathrooms;
        if (room_type == "standard") {
            rooms.push_back(new HotelRoom(bedrooms, bathrooms));
        }
        else {
            rooms.push_back(new HotelApartment(bedrooms, bathrooms));
        }
    }

    int total_profit = 0;
    for (auto room : rooms) {
        total_profit += room->get_price();
    }
    std::cout << total_profit << std::endl;

    for (auto room : rooms) {
        delete room;
    }
    rooms.clear();
    
   
    return 0;
}
 