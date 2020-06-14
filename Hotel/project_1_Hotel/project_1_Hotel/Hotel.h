#pragma once
#include "Room.h"
#include<iostream>
#include<vector>

/*! \class Hotel
\brief Class that defines a Hotel
*/
class Hotel
{
private:
	std::vector<Room> rooms;

	//! sorts the rooms in a hotel by their bed count
	void sortRoomsByBedCount(std::vector<Room> rooms)
	{
		size_t i, j;
		for (i = 0; i < this->rooms.size() - 1; i++)
		{
			for (j = 0; j < this->rooms.size() - i - 1; j++)
			{
				if (rooms[j].get_bedCount() > rooms[j + 1].get_bedCount())
				{
					Room temp = rooms[j];
					rooms[j] = rooms[j + 1];
					rooms[j + 1] = temp;
				}
			}			
		}

		this->rooms = rooms;
	}
	//! isFree check if input dates are compatible with the given room`s dates
	bool isFree(int index, const Date &startingDate, const Date &endDate)
	{
		Date roomStartingDate = this->rooms[index].get_startDate();
		Date roomEndDate = this->rooms[index].get_endDate();

		if (roomStartingDate <= startingDate && roomEndDate >= endDate)
		{
			return false;
		}
		else if (roomStartingDate <= startingDate && roomEndDate >= startingDate && roomEndDate < endDate)
		{
			return false;
		}
		else if (roomStartingDate > startingDate && roomStartingDate <= endDate && roomEndDate >= endDate)
		{
			return false;
		}
		return true;

	}
	//! counts leap years used in daysBetweenTwoDates method
	int countLeapYears(const Date &d)
	{
		int years = d.get_year();

		if (d.get_month() <= 2)
		{
			years--;
		}

		return years / 4 - years / 100 + years / 400;
	}
	//! counts days between two dates 
	int daysBetweenTwoDates(const Date &firstDate,const Date &secondDate)
	{
		const int monthDays[12] = { 31, 28, 31, 30, 31, 30,
									31, 31, 30, 31, 30, 31 };

		long int n1 = firstDate.get_year() * 365 + firstDate.get_day();
		for (int i = 0; i < firstDate.get_month() - 1; i++)
		{
			n1 += monthDays[i];
		}
		n1 += countLeapYears(firstDate);

		long int n2 = secondDate.get_year() * 365 + secondDate.get_day();
		for (int i = 0; i < secondDate.get_month() - 1; i++)
		{
			n2 += monthDays[i];
		}
		n2 += countLeapYears(secondDate);

		return (n2 - n1);
	}
public:
	Hotel();
	
	void add_room(const Room &room);
	void checkin(int room, const Date &startingDate, const Date &endDate,const std::string &guests);
	void availability(Date &date);
	void checkout(int rooms);
	void report(Date &startingDate, Date &endDate);
	void find(int beds, const Date &startingDate, const Date &endDate);
	void VIP_find(int beds, const Date &startingDate, const Date &endDate);
	void unavailable(int room, const Date &startingDate, const Date &endDate, const std::string &note);
	void print(std::ofstream &file);

};

