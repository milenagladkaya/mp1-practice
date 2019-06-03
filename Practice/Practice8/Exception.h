#pragma once
#include <iostream>
#include <string>
#include <cstring>

class Error1 : std::exception
{
private:
    const std::string what_str = "Матрицы разных размеров";
public:
    const char* what() const;
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
    const std::string what_str = "В данной матрице не существует строки с такими индексами";
public:
    const char* what() const;
};

