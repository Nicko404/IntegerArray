#pragma once
#include <exception>

class BadCapacityException : public std::exception
{
private:

	const char* Message;

public:

	BadCapacityException(const char* Message);
	BadCapacityException(const BadCapacityException& Exception);

	virtual const char* what() const noexcept override;
};