#include "BadCapacityException.h"

BadCapacityException::BadCapacityException(const char* Message) : Message(Message)
{ }

BadCapacityException::BadCapacityException(const BadCapacityException& Exception) : Message(Exception.Message)
{ }

const char* BadCapacityException::what() const noexcept
{
	return Message;
}