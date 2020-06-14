#pragma once
#include "Date.h"
#include<string>

/*! \class Room
\brief Class that defines a Room
*/
class Room
{
private:
	int number;
	int bedCount;
	std::string guests;
	Date startDate;
	Date endDate;
public:
	Room();
	Room(int number,int bedCount, std::string guests, const Date startDate, const Date endDate);

	int get_number() const;
	int get_bedCount() const;
	const std::string get_guests() const;
	Date get_startDate() const;
	Date get_endDate() const;

	void set_number(int number);
	void set_bedCount(int bedCount);
	void set_guest(std::string guests);
	void set_startDate(Date other);
	void set_endDate(Date other);
};

