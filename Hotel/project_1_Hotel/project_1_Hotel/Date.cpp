#include "stdafx.h"
#include "Date.h"


Date::Date()
{
	this->day = 1;
	this->month = 1;
	this->year = 1;
}
Date::Date(int day, int month, int year)
{
	this->set_year(year);
	this->set_month(month);
	this->set_day(day);
}
Date& Date::operator=(const Date& other)
{
	if (this != &other)
	{
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
	}
	return *this;
}
bool Date::operator==(const Date& other)
{
	if (this != &other)
	{
		if (this->day == other.day
			&& this->month == other.month
			&& this->year == other.year)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return true;
	}
}
bool Date::operator!=(const Date& other)
{
	return !(*this == other);
}
bool Date::operator<(const Date& other)
{
	if (this != &other)
	{
		if (this->year < other.year)
		{
			return true;
		}
		else
		{
			if (this->month < other.month)
			{
				return true;
			}
			else
			{
				if (this->day < other.day)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}
	else
	{
		return false;
	}

}
bool Date::operator>(const Date& other)
{
	if (this != &other)
	{
		if (this->year > other.year)
		{
			return true;
		}
		else
		{
			if (this->month > other.month)
			{
				return true;
			}
			else
			{
				if (this->day > other.day)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}
	else
	{
		return false;
	}
}
bool Date::operator<=(const Date& other)
{
	if (this != &other)
	{
		if (this->year < other.year)
		{
			return true;
		}
		else if (this->year == other.year)
		{
			if (this->month == other.month)
			{
				if (this->day <= other.day)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else if (this->month < other.month)
			{
				if (this->day <= other.day)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return true;
	}
}
bool Date::operator>=(const Date& other)
{
	if (this != &other)
	{
		if (this->year > other.year)
		{
			return true;
		}
		else if (this->year == other.year)
		{
			if (this->month == other.month)
			{
				if (this->day >= other.day)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else if (this->month > other.month)
			{
				if (this->day >= other.day)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return true;
	}
}


int Date::get_day() const
{
	return this->day;
}
int Date::get_month() const
{
	return this->month;
}
int Date::get_year() const
{
	return this->year;
}

void Date::set_day(int day)
{
	if (this->month == 2)
	{
		if (this->year % 4 == 0)
		{
			if (day >= 1 && day <= 29)
			{
				this->day = day;
			}
		}
		else
		{
			if (day >= 1 && day <= 28)
			{
				this->day = day;
			}
		}
	}
	else if (this->month == 1 || this->month == 3 
		|| this->month == 5 || this->month == 7 
		|| this->month == 8 || this->month == 10 
		|| this->month == 12)
	{
		if (day >= 1 && day <= 31)
		{
			this->day = day;
		}
	}
	else
	{
		if (day >= 1 && day <= 30)
		{
			this->day = day;
		}
	}
}
void Date::set_month(int month)
{
	if (month >= 1 && month <= 12)
	{
		this->month = month;
	}
}
void Date::set_year(int year)
{
	this->year = year;
}
