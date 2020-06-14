#include "stdafx.h"
#include "Hotel.h"
#include<iostream>
#include<fstream>

//! Default constructor
Hotel::Hotel() {}
//! Adds a room to the hotel
void Hotel::add_room(const Room& room)
{
	this->rooms.push_back(room);
}
//! Checks in a guest to the hotel if there is an appropriate room
void Hotel::checkin(int room, const Date &startingDate, const Date &endDate,const std::string &guests)
{
	for (size_t i = 0; i < this->rooms.size(); i++)
	{
		if (this->rooms[i].get_number() == room)
		{
			if (this->isFree(i, startingDate, endDate)) 
			{
				this->rooms[i].set_startDate(startingDate);
				this->rooms[i].set_endDate(endDate);
				//! note is placed in with the guests for convenience
				this->rooms[i].set_guest(guests);
			}
		}
	}
}
//! Gives free rooms on a given date
void Hotel::availability(Date &date)
{
	for (size_t i = 0; i < this->rooms.size(); i++)
	{			
		Date roomStartingDate = this->rooms[i].get_startDate();
		Date roomEndDate = this->rooms[i].get_endDate();

		if (date < roomStartingDate || date > roomEndDate)
		{
			std::cout << this->rooms[i].get_number() << std::endl;
			std::cout << this->rooms[i].get_bedCount() << std::endl;
			std::cout << std::endl;
		}
	}
}
//! Frees up a foom
void Hotel::checkout(int room)
{
	Date baseDate;
	for (size_t i = 0; i < this->rooms.size(); i++)
	{
		if (this->rooms[i].get_number() == room)
		{
			this->rooms[i].set_startDate(baseDate);
			this->rooms[i].set_endDate(baseDate);
			this->rooms[i].set_guest("");
		}
	}
}
//! Returns days of use for each room between two dates
void Hotel::report(Date &startingDate, Date &endDate)
{
	for (size_t i = 0; i < this->rooms.size(); i++)
	{
		Date roomStartingDate = this->rooms[i].get_startDate();
		Date roomEndDate = this->rooms[i].get_endDate();

		if (roomStartingDate <= startingDate && endDate <= roomEndDate)
		{
			std::cout << this->daysBetweenTwoDates(startingDate, endDate) << std::endl;
		}
		else if (roomStartingDate >= startingDate && endDate >= roomStartingDate && endDate <= roomEndDate)
		{
			std::cout << this->daysBetweenTwoDates(roomStartingDate, endDate) << std::endl;
		}
		else if (roomStartingDate >= startingDate && endDate >= roomEndDate)
		{
			std::cout << this->daysBetweenTwoDates(roomStartingDate, roomEndDate) << std::endl;
		}
		else if (roomStartingDate <= startingDate && startingDate <=  roomEndDate && endDate > roomEndDate)
		{
			std::cout << this->daysBetweenTwoDates(startingDate, roomEndDate) << std::endl;
		}
		else
		{
			std::cout << "Date not in range" << std::endl;
		}
	}
}
//! Returns a compatible room
void Hotel::find(int beds, const Date &startingDate, const Date &endDate)
{
	//! sorts rooms so that it can be easier to find rooms
	this->sortRoomsByBedCount(this->rooms);

	for (size_t i = 0; i < this->rooms.size(); i++)
	{
		if (this->rooms[i].get_bedCount() <= beds)
		{
			if (this->isFree(i, startingDate, endDate))
			{
				this->rooms[i].set_startDate(startingDate);
				this->rooms[i].set_endDate(endDate);
				this->rooms[i].set_guest("");
				break;
			}
		}
	}
}
//! Removes guests from rooms in case the hotel is full so that the VIP guests can be checked in
void Hotel::VIP_find(int beds, const Date &startingDate, const Date &endDate)
{
	//! sorts rooms so that it can be easier to find rooms
	this->sortRoomsByBedCount(this->rooms);

	for (size_t i = 0; i < this->rooms.size(); i++)
	{
		if (this->rooms[i].get_bedCount() >= beds)
		{
			this->rooms[i].set_startDate(startingDate);
			this->rooms[i].set_endDate(endDate);
			this->rooms[i].set_guest("VIP");
			break;
		}
		else if (this->rooms[i].get_bedCount() < beds && i == this->rooms.size() - 1)
		{
			for (size_t i = 0; i < this->rooms.size(); i++)
			{
				int sumBeds = this->rooms[i].get_bedCount() + this->rooms[i + 1].get_bedCount();
				if (sumBeds >= beds)
				{
					this->rooms[i].set_startDate(startingDate);
					this->rooms[i].set_endDate(endDate);
					this->rooms[i].set_guest("VIP");
					this->rooms[i + 1].set_startDate(startingDate);
					this->rooms[i + 1].set_endDate(endDate);
					this->rooms[i + 1].set_guest("VIP");
					break;
				}
			}
		}
	}	
}
//! Makes a room unavailable 
void Hotel::unavailable(int room, const Date &startingDate, const Date &endDate, const std::string &note)
{
	for (size_t i = 0; i < this->rooms.size(); i++)
	{
		if (this->rooms[i].get_number() == room)
		{
			this->rooms[i].set_startDate(startingDate);
			this->rooms[i].set_endDate(endDate);
			this->rooms[i].set_guest(note);
		}
	}
}
//! prins information for each room of the hotel
void Hotel::print(std::ofstream &file)
{
	for (int i = 0; i < this->rooms.size(); i++)
	{
		file << this->rooms[i].get_number() << " " << this->rooms[i].get_bedCount()
			<< " " << this->rooms[i].get_startDate().get_day()
			<< "." << this->rooms[i].get_startDate().get_month()
			<< "." << this->rooms[i].get_startDate().get_year()
			<< " " << this->rooms[i].get_endDate().get_day()
			<< "." << this->rooms[i].get_endDate().get_month()
			<< "." << this->rooms[i].get_endDate().get_year()
			<< " " << this->rooms[i].get_guests() << std::endl;
	}
}