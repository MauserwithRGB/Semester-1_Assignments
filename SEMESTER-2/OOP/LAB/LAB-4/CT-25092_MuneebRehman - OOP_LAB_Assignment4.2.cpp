// Exercise 2: DynamicArray class with dynamic memory allocation

#include <iostream>

class DynamicArray
{
	private:
		int* array;
		int arraySize;
		int currentIndex;
		
	public:
		DynamicArray(int size)
		{
			arraySize = size;
			currentIndex = 0;
			array = new int[arraySize];
			
			for (int i = 0; i < arraySize; i++)
			{
				array[i] = 0;
			}
		}
		
		~DynamicArray()
		{
			delete[] array;
		}
		
		void add(int value)
		{
			if (currentIndex < arraySize)
			{
				array[currentIndex] = value;
				currentIndex++;
				std::cout << "Value " << value << " added successfully.\n";
			}
			else
			{
				std::cout << "Error: Array is full!\n";
			}
		}
		
		int size()
		{
			return arraySize;
		}
		
		void display()
		{
			std::cout << "Array contents: ";
			for (int i = 0; i < arraySize; i++)
			{
				std::cout << array[i] << " ";
			}
			std::cout << "\n";
		}
};

int main()
{
	int inputSize;
	
	std::cout << "Enter size of array: ";
	std::cin >> inputSize;
	
	DynamicArray myArray(inputSize);
	
	std::cout << "Array size: " << myArray.size() << "\n";
	
	myArray.add(10);
	myArray.add(20);
	myArray.add(30);
	myArray.add(40);
	
	myArray.display();
	
	return 0;
}