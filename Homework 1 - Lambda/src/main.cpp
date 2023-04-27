// main.cpp

/*
  25.04.2023
  Часть 3 - Продвинутое программирование на C++
  Занятие 1 - Новшества С++
  Задача 1 - Лямбда-функция
  CPP-07
  Горюнов Илья
*/

/*
Входные данные:  4 7 9 14 12
Выходные данные: 4 21 27 14 12
*/

#include <iostream>
#include <vector>

int main()
{
	// LOCALE
	
	setlocale(LC_ALL, "Russian");

	// VARIABLES

	std::vector<int> dataArr = { 4, 7, 9, 14, 12 };

	// BODY
	std::cout << "Входные данные: ";

	for (const int & i : dataArr)
	{
		std::cout << i << ' ';
	}

	std::cout << std::endl;

	std::cout << "Выходные данные: ";
	
	for (int i : dataArr)
	{
		auto mult = [&i]()
		{
			if (i % 2 != 0)
			{
				i = i * 3;
			}
		};

		mult();		 

		std::cout << i << ' ';		
	}

	// CLEAN & EXIT
	std::cout << "\n\n";
	system("pause");
	std::cout.clear();
	return 0;

} // END OF main()