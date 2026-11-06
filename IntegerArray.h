#pragma once

class IntegerArray
{
private:

	int Size = 0;
	int Capacity = 10;
	int* Data;

private:

	void Resize();

public:

	IntegerArray();
	IntegerArray(int* Data, int Size);
	IntegerArray(const IntegerArray& Array);
	~IntegerArray();

	void Add(int Number);
	int Get(int Index);
	void Delete(int Index);
	void IncreaseCapacity(int NewCapacity);
	void Clear();

	int GetSize();
	int GetCapacity();
};