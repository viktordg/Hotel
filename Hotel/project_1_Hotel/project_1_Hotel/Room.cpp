#include "stdafx.h"
#include "Room.h"

Room::Room()
{	
	Date token;
	this->number = 0;
	this->bedCount = 1;
	this->guests = "----";
	this->set_startDate(token);
	this->set_endDate(token);
}
Room::Room(int number, int bedCount, std::string guests, const Date startDate, const Date endDate)
{
	this->number = number;
	this->bedCount = bedCount;
	this->guests = guests;
	this->startDate = startDate;
	this->endDate = endDate;

}

int Room::get_number() const
{
	return this->number;
}
int Room::get_bedCount() const
{
	return this->bedCount;
}
const std::string Room::get_guests() const
{
	return this->guests;
}
Date Room::get_startDate() const
{
	return this->startDate;
}
Date Room::get_endDate() const
{
	return this->endDate;
}

void Room::set_number(int number)
{
	this->number = number;
}
void Room::set_bedCount(int bedCount)
{
	this->bedCount = bedCount;
}
void Room::set_guest(std::string guests)
{
	this->guests = guests;
}
void Room::set_startDate(Date other)
{
	this->startDate = other;
}
void Room::set_endDate(Date other)
{
	this->endDate = other;
}
