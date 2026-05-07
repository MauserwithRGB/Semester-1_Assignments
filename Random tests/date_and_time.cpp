#include <iostream>
#include <ctime>

int main()
{
	std::time_t timeRn = std::time(0);
	std::cout << timeRn;				// time since UNIX epoch in seconds
	std::cout << "\n" << ctime(&timeRn);
	
	struct tm *time = std::gmtime(&timeRn);
	std::cout << "\nDay of month: " << time->tm_mday;
}