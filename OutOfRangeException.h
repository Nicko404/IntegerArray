#pragma once

#include <exception>

class OutOfRangeException : public std::exception
{
private:

	const char* Message;

public:

	OutOfRangeException(const char* Message);
	OutOfRangeException(const OutOfRangeException& Exception);

	virtual const char* what() const noexcept override;
};