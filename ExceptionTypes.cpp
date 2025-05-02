#include "ExceptionTypes.h"

GameException::GameException(const std::string &msg) : message(msg) {}

const char *GameException::what() const noexcept
{
    return message.c_str();
}

FileLoadException::FileLoadException(const std::string &filename)
        : GameException("Failed to load file: " + filename) {}

InvalidEntityException::InvalidEntityException(const std::string &entityName)
        : GameException("Invalid entity: " + entityName) {}

StateException::StateException(const std::string &stateError)
        : GameException("State error: " + stateError) {}