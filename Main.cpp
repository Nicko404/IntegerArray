#include <iostream>
#include "IntegerArray.h"
#include "OutOfRangeException.h"
#include "BadCapacityException.h"

int main()
{
	IntegerArray Array;

	for (int i = 0; i < 10; i++)
	{
		Array.Add(i);
	}

	std::cout << "Try to get number at index 2!" << std::endl;
	std::cout << "Number at index 2: " << Array.Get(2) << std::endl;

	try
	{
		std::cout << "Try to get number at index 10!" << std::endl;
		std::cout << "Number at index 10: " << Array.Get(10) << std::endl;

	}
	catch (const OutOfRangeException& Ex)
	{
		std::cout << Ex.what() << std::endl;
	}

	try
	{
		std::cout << "Try to increase capacity correctly!" << std::endl;
		Array.IncreaseCapacity(15);
		std::cout << "New Capacity: " << Array.GetCapacity() << std::endl;

		std::cout << "Try to increase capacity wrongly!" << std::endl;
		Array.IncreaseCapacity(10);
		std::cout << "New Capacity: " << Array.GetCapacity() << std::endl;
	}
	catch (const BadCapacityException& Ex)
	{
		std::cout << Ex.what() << std::endl;
	}

	std::cout << "Program has been finished!" << std::endl;

	return 0;
}
