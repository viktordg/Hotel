#include "stdafx.h"
#include<iostream>
#include<string>
#include"Date.h"
#include"Room.h"
#include"Hotel.h"
#include<fstream>
#include<ctime>

int main()
{
	//! main hotel
	Hotel hotel;

	//! Test
	/*Date date;
	Date date1(10, 10, 2020);
	Date date2(15, 10, 2020);
	Date date3(12, 12, 2020);
	Date date4(20, 12, 2020);
	Date date5(16, 12, 2020);
	Date date6(18, 12, 2020);
	Date date7(1, 10, 2020);
	Date date8(4, 11, 2020);	
	Room room1(100, 2, "", date, date);
	Room room2(101, 3, "", date, date);
	Room room3(102, 1, "", date, date);	
	hotel.add_room(room1);
	hotel.add_room(room2);
	hotel.add_room(room3);
	hotel.checkin(100, date1, date2, "moni s nqkolko macki");
	hotel.checkin(101, date7, date8, "gancho2");
	hotel.checkin(102, date3, date4, "kumcho vulcho");
	hotel.report(date2, date8);
	hotel.VIP_find(4, date7, date8);
	hotel.unavailable(100, date7, date8, "nqma toaletna");*/


	//! command
	std::string input;

	//! path on open command
	std::string path;

	//! checks if there is an open file
	bool isOpen = false;

	bool flag = true;

	//! the whole do block splits and executes commands
	do
	{
		getline(std::cin, input);
		if (input.length() > 5)
		{
			int index = 0;
			for (size_t i = 0; input[i] != ' '; i++)
			{
				index++;
			}
			std::string command = input.substr(0, index);
			index++;

			if (command == "open")
			{
				isOpen = true;

				Hotel temp;

				path = input.substr(index, input.length() - index);
				std::ifstream read(path);

				if (read.is_open())
				{
					for (std::string line = ""; std::getline(read, line); )
					{

						int numberIndex = 0;
						for (int i = 0; line[i] != ' '; i++)
						{
							numberIndex++;
						}
						std::string numberToken = line.substr(0, numberIndex);
						int number = stoi(numberToken);
						numberIndex++;
						std::cout << number << std::endl;

						int bedCountIndex = numberIndex;
						for (int i = bedCountIndex; line[i] != ' '; i++)
						{
							bedCountIndex++;
						}
						std::string bedCountToken = line.substr(numberIndex, bedCountIndex - numberIndex);
						int beds = stoi(bedCountToken);
						bedCountIndex++;
						std::cout << beds << std::endl;

						int firstDateIndex = bedCountIndex;
						for (int i = firstDateIndex; line[i] != ' '; i++)
						{
							firstDateIndex++;
						}
						std::string firstDateToken = line.substr(bedCountIndex, firstDateIndex - bedCountIndex);
						int firstDay = stoi(firstDateToken.substr(0, 2));
						int firstMonth = stoi(firstDateToken.substr(3, 5));
						int firstYear = stoi(firstDateToken.substr(6, 10));
						Date firstDate(firstDay, firstMonth, firstYear);
						firstDateIndex++;

						std::cout << firstDay << std::endl;
						std::cout << firstMonth << std::endl;
						std::cout << firstYear << std::endl;

						if (line.size() == (firstDateIndex + (firstDateIndex - bedCountIndex - 1)))
						{
							int secondDateIndex = firstDateIndex;
							for (int i = secondDateIndex; i < line.size(); i++)
							{
								secondDateIndex++;
							}
							std::string secondDateToken = line.substr(firstDateIndex, secondDateIndex - firstDateIndex);
							int secondDay = stoi(secondDateToken.substr(0, 2));
							int secondMonth = stoi(secondDateToken.substr(3, 5));
							int secondYear = stoi(secondDateToken.substr(6, 10));
							Date secondDate(secondDay, secondMonth, secondYear);

							std::cout << secondDay << std::endl;
							std::cout << secondMonth << std::endl;
							std::cout << secondYear << std::endl;

							Room room(number, beds, "", firstDate, secondDate);
							temp.add_room(room);
						}
						else
						{
							int secondDateIndex = firstDateIndex;
							for (int i = secondDateIndex; line[i] != ' '; i++)
							{
								secondDateIndex++;
							}
							std::string secondDateToken = line.substr(firstDateIndex, secondDateIndex - firstDateIndex);
							int secondDay = stoi(secondDateToken.substr(0, 2));
							int secondMonth = stoi(secondDateToken.substr(3, 5));
							int secondYear = stoi(secondDateToken.substr(6, 10));
							Date secondDate(secondDay, secondMonth, secondYear);

							std::cout << secondDay << std::endl;
							std::cout << secondMonth << std::endl;
							std::cout << secondYear << std::endl;

							std::string guests = line.substr(++secondDateIndex, line.size() - secondDateIndex);

							std::cout << guests << std::endl;

							Room room(number, beds, guests, firstDate, secondDate);
							temp.add_room(room);
						}

					}

					hotel = temp;

					read.close();
				}
				else
				{
					std::cout << "Unable to open!" << std::endl;
				}
			}
			else if (command == "saveas" && isOpen)
			{
				std::string newPath = input.substr(index, input.length() - index);
				std::ofstream saveasFile(newPath);

				std::ofstream saveas_file;
				saveas_file.open(newPath);

				if (saveasFile.is_open())
				{
					hotel.print(saveasFile);
				}
				else
				{
					std::cout << "Unable to open!" << std::endl;
				}

				saveas_file.close();
			}
			else if (command == "checkin" && isOpen)
			{
				int roomIndex = index;
				for (size_t i = index; input[i] != ' '; i++)
				{
					roomIndex++;
				}
				std::string roomToken = input.substr(index, roomIndex - index);
				int room = stoi(roomToken); 
				roomIndex++;

				int dateIndex = roomIndex;
				for (size_t i = roomIndex; input[i] != ' '; i++)
				{
					dateIndex++;
				}
				std::string firstDateToken = input.substr(roomIndex, dateIndex - roomIndex);
				dateIndex++;
				int firstYear = stoi(firstDateToken.substr(0, 4));
				int firstMonth = stoi(firstDateToken.substr(5, 7));
				int firstDay = stoi(firstDateToken.substr(8, 10));
				Date firstDate(firstDay, firstMonth, firstYear);

				int secondDateIndex = dateIndex;
				for (size_t i = dateIndex; input[i] != ' '; i++)
				{
					secondDateIndex++;
				}
				std::string secondDateToken = input.substr(dateIndex, secondDateIndex - dateIndex);
				int secondYear = stoi(secondDateToken.substr(0, 4));
				int secondMonth = stoi(secondDateToken.substr(5, 7));
				int secondDay = stoi(secondDateToken.substr(8, 10));
				Date secondDate(secondDay, secondMonth, secondYear); 

				std::string guests; 
				if (secondDateIndex == input.size())
				{
					guests = "";
				}
				else
				{
					guests = input.substr(++secondDateIndex, input.size() - secondDateIndex);
				}

				hotel.checkin(room, firstDate, secondDate, guests);
			}
			else if (command == "availability" && isOpen)
			{
				if (index == input.size())
				{
					struct tm newtime;
					time_t now = time(0);
					localtime_s(&newtime, &now);
					int year = 1900 + newtime.tm_year;
					int month = 1 + newtime.tm_mon;
					int day = newtime.tm_mday;

					Date date(day, month, year);

					hotel.availability(date);
				}
				else
				{
					std::string dateToken = input.substr(++index, input.size() - index);
					int year = stoi(dateToken.substr(0, 4));
					int month = stoi(dateToken.substr(5, 7));
					int day = stoi(dateToken.substr(8, 10));
					Date date(day, month, year); 

					hotel.availability(date);
				}

			}
			else if (command == "checkout" && isOpen)
			{
				std::string roomToken = input.substr(index, input.size() - index);
				int room = stoi(roomToken); 

				hotel.checkout(room);
			}
			else if (command == "report" && isOpen)
			{
				int dateIndex = index;
				for (size_t i = index; input[i] != ' '; i++)
				{
					dateIndex++;
				}
				std::string firstDateToken = input.substr(index, dateIndex - index);
				dateIndex++;
				int firstYear = stoi(firstDateToken.substr(0, 4));
				int firstMonth = stoi(firstDateToken.substr(5, 7));
				int firstDay = stoi(firstDateToken.substr(8, 10));
				Date firstDate(firstDay, firstMonth, firstYear); 

				std::string secondDateToken = input.substr(dateIndex, input.size() - dateIndex);
				int secondYear = stoi(secondDateToken.substr(0, 4));
				int secondMonth = stoi(secondDateToken.substr(5, 7));
				int secondDay = stoi(secondDateToken.substr(8, 10));
				Date secondDate(secondDay, secondMonth, secondYear); 

																	
				hotel.report(firstDate, secondDate);
			}
			else if (command == "find" && isOpen)
			{
				int bedIndex = index;
				for (size_t i = index; input[i] != ' '; i++)
				{
					bedIndex++;
				}
				std::string bedToken = input.substr(index, bedIndex - index);
				bedIndex++;
				int beds = stoi(bedToken); 

				int dateIndex = bedIndex;
				for (size_t i = bedIndex; input[i] != ' '; i++)
				{
					dateIndex++;
				}
				std::string firstDateToken = input.substr(bedIndex, dateIndex - bedIndex);
				dateIndex++;
				int firstYear = stoi(firstDateToken.substr(0, 4));
				int firstMonth = stoi(firstDateToken.substr(5, 7));
				int firstDay = stoi(firstDateToken.substr(8, 10));
				Date firstDate(firstDay, firstMonth, firstYear); 

				std::string secondDateToken = input.substr(dateIndex, input.size() - dateIndex);
				int secondYear = stoi(secondDateToken.substr(0, 4));
				int secondMonth = stoi(secondDateToken.substr(5, 7));
				int secondDay = stoi(secondDateToken.substr(8, 10));
				Date secondDate(secondDay, secondMonth, secondYear); 
																	
				hotel.find(beds, firstDate, secondDate);
			}
			else if (command == "find!" && isOpen)
			{
				int bedIndex = index;
				for (size_t i = index; input[i] != ' '; i++)
				{
					bedIndex++;
				}
				std::string bedToken = input.substr(index, bedIndex - index);
				bedIndex++;
				int beds = stoi(bedToken);

				int dateIndex = bedIndex;
				for (size_t i = bedIndex; input[i] != ' '; i++)
				{
					dateIndex++;
				}
				std::string firstDateToken = input.substr(bedIndex, dateIndex - bedIndex);
				dateIndex++;
				int firstYear = stoi(firstDateToken.substr(0, 4));
				int firstMonth = stoi(firstDateToken.substr(5, 7));
				int firstDay = stoi(firstDateToken.substr(8, 10));
				Date firstDate(firstDay, firstMonth, firstYear);

				std::string secondDateToken = input.substr(dateIndex, input.size() - dateIndex);
				int secondYear = stoi(secondDateToken.substr(0, 4));
				int secondMonth = stoi(secondDateToken.substr(5, 7));
				int secondDay = stoi(secondDateToken.substr(8, 10));
				Date secondDate(secondDay, secondMonth, secondYear);
																	 
				hotel.VIP_find(beds, firstDate, secondDate);
			}
			else if (command == "unavailable" && isOpen)
			{
				int roomIndex = index;
				for (size_t i = index; input[i] != ' '; i++)
				{
					roomIndex++;
				}
				std::string roomToken = input.substr(index, roomIndex - index);
				roomIndex++;
				int room = stoi(roomToken); 

				int dateIndex = roomIndex;
				for (size_t i = roomIndex; input[i] != ' '; i++)
				{
					dateIndex++;
				}
				std::string firstDateToken = input.substr(roomIndex, dateIndex - roomIndex);
				dateIndex++;
				int firstYear = stoi(firstDateToken.substr(0, 4));
				int firstMonth = stoi(firstDateToken.substr(5, 7));
				int firstDay = stoi(firstDateToken.substr(8, 10));
				Date firstDate(firstDay, firstMonth, firstYear); 

				int seondDateIndex = dateIndex;
				for (size_t i = dateIndex; input[i] != ' '; i++)
				{
					seondDateIndex++;
				}
				std::string secondDateToken = input.substr(dateIndex, seondDateIndex - dateIndex);
				seondDateIndex++;
				int secondYear = stoi(secondDateToken.substr(0, 4));
				int secondMonth = stoi(secondDateToken.substr(5, 7));
				int secondDay = stoi(secondDateToken.substr(8, 10));
				Date secondDate(secondDay, secondMonth, secondYear); 

				std::string note = input.substr(seondDateIndex, input.size() - seondDateIndex); 
																								
				hotel.unavailable(room, firstDate, secondDate, note);

			}	
		} 
		else if (input == "close" && isOpen)
		{
			isOpen = false;
		}
		else if (input == "save" && isOpen)
		{
			std::ofstream save_file;
			save_file.open(path);
			save_file.clear();

			hotel.print(save_file);

			save_file.close();
		}
		else if (input == "help")
		{
			std::cout << "The following commands are supported : " << std::endl;
			std::cout << "open <file>	opens <file>" << std::endl;
			std::cout << "close			closes currently opened file " << std::endl;
			std::cout << "save			saves the currently open file " << std::endl;
			std::cout << "saveas <file>	saves the currently open file in <file> " << std::endl;
			std::cout << "help			prints this information " << std::endl;
			std::cout << "exit			exists the program " << std::endl;
		}
		else if (input == "exit")
		{
			std::cout << "Exiting program!" << std::endl;
			return 1;
			flag = false;
		}
	}while (flag);
	return 0;
}