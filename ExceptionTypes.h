#pragma once

#include <exception>
#include <string>

class GameException : public std::exception
{
protected:
    std::string message;

public:
    explicit GameException(const std::string &);
    virtual ~GameException()=default;

    virtual const char *what() const noexcept override;
};

class FileLoadException : public GameException
{
public:
    explicit FileLoadException(const std::string &);
};

class InvalidEntityException : public GameException
{
public:
    explicit InvalidEntityException(const std::string &);
};

class StateException : public GameException
{
public:
    explicit StateException(const std::string &);
};