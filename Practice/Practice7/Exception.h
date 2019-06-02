#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <locale.h>

class Error1 : std::exception
{
private:
    const char* what() const;
public:
    const std::string what_str = "Векторы разных размеров";
};

class  Error2 : std::exception
{
private:
    const std::string what_str = "Элемента с таким индексом нет";
public:
    const char* what() const;
};
