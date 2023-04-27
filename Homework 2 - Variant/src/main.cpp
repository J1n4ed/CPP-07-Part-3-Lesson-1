// main.cpp

/*
  25.04.2023
  Часть 3 - Продвинутое программирование на C++
  Занятие 1 - Новшества С++
  Задача 2 - std::variant
  CPP-07
  Горюнов Илья
*/

// INCLUDES

#include <iostream>
#include <variant>
#include <vector>
#include <string>

std::variant<int, std::string, std::vector<int>> get_variant();

int main()
{
	// LOCALE

	setlocale(LC_ALL, "Russian");

	// VARIABLES

	std::variant<int, std::string, std::vector<int>> variable;

	// BODY

	std::cout << "Цикл вызовов функции get_variant()\n";

	while (true)
	{
		variable = get_variant();

		if (std::holds_alternative<std::string>(variable))
		{
			auto tmp = std::get<std::string>(variable);
			std::cout << "\nString: " << tmp;
		}
		else if (std::holds_alternative<int>(variable))
		{
			auto tmp = std::get<int>(variable);
			std::cout << "\nOrig int: " << tmp;
			tmp = tmp * 2;
			std::cout << ", changed int: " << tmp;			
		}
		else if (std::holds_alternative<std::vector<int>>(variable))
		{
			std::cout << "\nVector of ints: ";
			auto tmp = std::get<std::vector<int>>(variable);

			for (const int & i : tmp)
			{
				std::cout << i << ' ';
			}
		}
		else
		{
			std::cerr << "\nОшибка, возвращаемые условия get_variant() не соответствуют ожидаемым.";
		}

		std::getchar();
	}

	// CLEAN & EXIT
	std::cout << "\n\n";
	system("pause");
	std::cout.clear();
	return 0;

} // END OF main()

std::variant<int, std::string, std::vector<int>> get_variant() 
{
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
} // END OF get_variant()