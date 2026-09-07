#include "HotelTest.h"

#include "HotelRoom.h"
#include <iostream>
#include <vector>
#include <string>


void HotelTest::TestRooms()
{
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
};
