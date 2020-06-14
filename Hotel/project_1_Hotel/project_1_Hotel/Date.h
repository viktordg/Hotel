#pragma once
/*! \class Date
\brief Class that defines Date
*/
class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(int day, int month, int year);

	Date& operator=(const Date& other);
	bool operator==(const Date& other);
	bool operator!=(const Date& other);
	bool operator<(const Date& other);
	bool operator>(const Date& other);
	bool operator<=(const Date& other);
	bool operator>=(const Date& other);

	int get_day() const;
	int get_month() const;
	int get_year() const;
	void set_day(int day);
	void set_month(int month);
	void set_year(int year);
};



