// OOP Lab assignment,            purpose:  temperature conversion from fahrenheit to celsius

#include <iostream>

float TempConvert(float F)
{
	float C;
	C = (F - 32) / 1.8;
	
	return C;
}

int main()
{
	float fahrnht, celsius;
	std::cout << "Enter the temperature in Fahrenheit: ";
	std::cin >> fahrnht;
	
	celsius = TempConvert(fahrnht);
	
	std::cout << "\n" << fahrnht << " Fahrenheit = " << celsius << " Celsius.\n";
}

