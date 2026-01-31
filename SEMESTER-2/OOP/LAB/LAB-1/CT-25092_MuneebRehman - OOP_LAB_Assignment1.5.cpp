// OOP lab assignment 1.5             purspose:    calculate volume and surafce area for a spehere using functions

#include <iostream>

#define PI 3.1415926535897932384626433832795 // defined pi for accurate results

float sphereVolume(float radius)
{
	float volume = (4.0/3.0) * PI * radius * radius * radius;  // the explicit decimal point is for ensuring that this performs floating point divison instead of integer division
	
	return volume;
}

float sphereArea(float radius)
{
	float area = 4 * PI * radius * radius;
	
	return area;
}

int main()
{
	float radiusIN;   // 'IN' is for 'INPUT', not inches. used different naming to avoid conflicts, not much use here but just to make it a habit
	
	std::cout << "Enter the radius of the sphere in: ";
	std::cin >> radiusIN;
	
	float resultVolume = sphereVolume(radiusIN);
	float resultArea = sphereArea(radiusIN);
	
	std::cout << "\nThe volume of the sphere is " << resultVolume << " Cubic Units.\nThe surface area of the sphere is " << resultArea << " Sqaure Units.\n";
}