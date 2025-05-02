#pragma once

#include <exception>
#include <string>

class GameException : public std::exception
{
protected:
    std::string message;

public:
    explicit GameException(const std::string &msg) : message(msg) {}

    virtual const char *what() const noexcept override;
};

class FileLoadException : public GameException
{
public:
    explicit FileLoadException(const std::string &filename)
        : GameException("Failed to load file: " + filename) {}
};

class InvalidEntityException : public GameException
{
public:
    explicit InvalidEntityException(const std::string &entityName)
        : GameException("Invalid entity: " + entityName) {}
};

class StateException : public GameException
{
public:
    explicit StateException(const std::string &stateError)
        : GameException("State error: " + stateError) {}
};