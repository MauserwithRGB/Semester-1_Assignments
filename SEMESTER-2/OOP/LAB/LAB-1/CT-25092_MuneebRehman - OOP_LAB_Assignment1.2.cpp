// OOP Lab assignment 1.2,           pupose: a program for swapping 3 variables using pointers

#include <iostream>

void swap(int* Aptr, int* Bptr, int* Cptr)
{
	int temp = *Aptr;
	*Aptr = *Bptr;
	*Bptr = *Cptr;
	*Cptr = temp;
}

int main()
{
	int x, y, z;
	int *Xptr, *Yptr, *Zptr;
	
	std::cout << "Enter the values for 'x', 'y', and 'z', respectively: ";
	std::cin >> x >> y >> z;
	
	Xptr = &x;
	Yptr = &y;
	Zptr = &z;
	
	swap(Xptr, Yptr, Zptr);
	
	std::cout << "After swapping:\nx = " << x << "\ny = " << y << "\nz = " << z;
}