// main.cpp

/*
  25.04.2023
  Часть 3 - Продвинутое программирование на C++
  Занятие 1 - Новшества С++
  Задача 3* - Операции над углами
  CPP-07
  Горюнов Илья
*/

// DEFINES

#define _USE_MATH_DEFINES

#define FIRST_ANGLE		30
#define SECOND_ANGLE	60
#define THIRD_ANGLE		90

// INCLUDES

#include <iostream>
#include <vector>
#include <math.h>
#include <functional>

/*
[Входные данные]: 30 * 3.1415926 / 180, 60 * 3.1415926 / 180, 90 * 3.1415926 / 180 // перевод из градусов в радианы
[Выходные данные]:
0.523599: sin: 0.5 cos: 0.866025
1.0472: sin: 0.866025 cos: 0.5
1.5708: sin: 1 cos: 2.67949e-08
*/

int main()
{
	// LOCALE

	setlocale(LC_ALL, "Russian");

	// CONSOLE SETTINGS

	std::cout.precision(6);

	// VARIABLES

	constexpr double firstAngle = FIRST_ANGLE * M_PI / 180;
	constexpr double secondAngle = SECOND_ANGLE * M_PI / 180;
	constexpr double thirdAngle = THIRD_ANGLE * M_PI / 180;

	std::vector<double> angles = { firstAngle , secondAngle , thirdAngle };

	std::cout << "[Входные данные]: ";

	for (double i : angles)
	{
		std::cout << i << ' ';
	}

	std::cout << std::endl;	

	std::vector<std::function<void(const double &)>> functions;

	// push functions to vector
	auto func1 = [](const double & angle)
	{
		// sin
		std::cout << " sin: " << sin(angle) << ' ';

	};

	functions.push_back(func1);

	auto func2 = [](const double& angle)
	{
		// cos
		std::cout << " cos: " << cos(angle) << ' ';

	};

	functions.push_back(func2);

	// BODY

	std::cout << "[Выходные данные]:\n";

	for (const auto& angle : angles) 
	{
		std::cout << angle << ": ";
		for (const auto & function : functions)
		{
			function(angle);
		}
		std::cout << std::endl;
	}

	// CLEAN & EXIT
	std::cout << "\n\n";
	system("pause");
	std::cout.clear();
	return 0;

} // END OF main()