#include "OutOfRangeException.h"

OutOfRangeException::OutOfRangeException(const char* Message) : Message(Message)
{ }

OutOfRangeException::OutOfRangeException(const OutOfRangeException& Exception) : Message(Exception.Message)
{ }

const char* OutOfRangeException::what() const noexcept
{
	return Message;
}