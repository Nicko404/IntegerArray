#include "IntegerArray.h"

#include "OutOfRangeException.h"
#include "BadCapacityException.h"

IntegerArray::IntegerArray() : Data(new int[Capacity])
{ }

IntegerArray::IntegerArray(int* Data, int Size) : Data(new int[Size]), Size(Size), Capacity(sizeof(*Data) / sizeof(int) * Size + 10)
{
	for (int i = 0; i < Size; i++)
	{
		this->Data[i] = Data[i];
	}
}

IntegerArray::IntegerArray(const IntegerArray& Array) : Size(Array.Size), Capacity(Array.Capacity), Data(new int[Array.Size])
{
	for (int i = 0; i < Size; i++)
	{
		Data[i] = Array.Data[i];
	}
}

IntegerArray::~IntegerArray()
{
	delete[] Data;
}

void IntegerArray::Add(int Number)
{
	if (Size == Capacity)
	{
		Resize();
	}
	Data[Size] = Number;
	++Size;
}

int IntegerArray::Get(int Index)
{
	if (Index >= Size || Index < 0) throw OutOfRangeException("Your Index is out of boud array's size!");

	return Data[Index];
}

void IntegerArray::Delete(int Index)
{
	if (Index >= Size || Index < 0) throw OutOfRangeException("Your Index is out of bound array's size!");

	for (int i = Index; i < Size; i++)
	{
		if (i + 1 <= Size)
		{
			Data[i] = Data[i + 1];
		}
	}
	--Size;
}

void IntegerArray::IncreaseCapacity(int NewCapacity)
{

	if (NewCapacity <= Capacity || Capacity <= 0) throw BadCapacityException("Your capacity is less or equal array's capacity");

	int* NewData = new int[NewCapacity];

	for (int i = 0; i < Size; i++)
	{
		NewData[i] = Data[i];
	}

	delete[] Data;

	Data = NewData;
	Capacity = NewCapacity;
}

void IntegerArray::Clear()
{
	delete[] Data;
	
	Size = 0;
	Capacity = 10;
	Data = new int[Capacity];
}

int IntegerArray::GetSize()
{
	return Size;
}

int IntegerArray::GetCapacity()
{
	return Capacity;
}

void IntegerArray::Resize()
{
	int* NewData = new int[Capacity + 10];

	for (int i = 0; i < Size; i++)
	{
		NewData[i] = Data[i];
	}
	
	delete[] Data;

	Data = NewData;
	Capacity = Capacity + 10;
}