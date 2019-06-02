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
    const std::string what_str = "Матрицы разных размеров";
};

class  Error2 : std::exception
{
private:
    const std::string what_str = "Количество столбцов первой матрицы отличается от количества строк второй";
public:
    const char* what() const;
};

class Error3 : std::exception
{
private:
    const std::string what_str = "В данной матрице не существует строки с таким индексом";
public:
    const char* what() const;
};

