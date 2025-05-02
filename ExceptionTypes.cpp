#include "ExceptionTypes.h"

const char *GameException::what() const noexcept
{
    return message.c_str();
}