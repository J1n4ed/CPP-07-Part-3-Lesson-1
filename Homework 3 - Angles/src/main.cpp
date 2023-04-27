// main.cpp

/*
  25.04.2023
  ����� 3 - ����������� ���������������� �� C++
  ������� 1 - ��������� �++
  ������ 3* - �������� ��� ������
  CPP-07
  ������� ����
*/

// DEFINES

#define _USE_MATH_DEFINES
#define ROUND_PRECISION 10000.0

#define DEGREE_30		30
#define DEGREE_60		60
#define DEGREE_90		90

// INCLUDES

#include <iostream>
#include <vector>
#include <math.h>
#include <functional>
// #include <iomanip>

/*
[������� ������]: 30 * 3.1415926 / 180, 60 * 3.1415926 / 180, 90 * 3.1415926 / 180 // ������� �� �������� � �������
[�������� ������]:
0.523599: sin: 0.5 cos: 0.866025
1.0472: sin: 0.866025 cos: 0.5
1.5708: sin: 1 cos: 2.67949e-08
*/

int main()
{
	// LOCALE

	setlocale(LC_ALL, "Russian");

	// CONSOLE SETTINGS

	std::cout.precision(8);
	std::cout << std::fixed;

	// ROUNDING METHOD

	auto round_num = [](const double& value)
	{
		return std::round(value * ROUND_PRECISION) / ROUND_PRECISION;
	};

	// VARIABLES

	constexpr double firstAngle		= DEGREE_30 * M_PI / 180;
	constexpr double secondAngle	= DEGREE_60 * M_PI / 180;
	constexpr double thirdAngle		= DEGREE_90 * M_PI / 180;

	std::vector<double> angles = { firstAngle , secondAngle , thirdAngle };

	std::cout << "[������� ������]: ";

	for (const double & i : angles)
	{
		std::cout << round_num(i) << ' ';
	}

	std::cout << std::endl;	

	std::vector<std::function<void(const double &)>> functions;

	// push functions to vector
	auto get_sin = [](const double & angle)
	{
		// sin
		std::cout << "\tsin: " << std::round(sin(angle) * ROUND_PRECISION) / ROUND_PRECISION << '\t';

	};

	functions.push_back(get_sin);

	auto get_cos = [](const double& angle)
	{
		// cos
		std::cout << "\tcos: " << std::round(cos(angle) * ROUND_PRECISION) / ROUND_PRECISION << '\t';

	};

	functions.push_back(get_cos);

	// BODY

	std::cout << "[�������� ������]:\n";

	for (const auto & angle : angles) 
	{
		std::cout << "rad: " << round_num(angle) << '\t';
		for (const auto & function : functions)
		{
			function(angle);
		}
		std::cout << std::endl;
	}

	// ������� ������� � ���������
	auto get_tan = [](const double& angle)
	{
		// tan
		std::cout << std::scientific << "\ttan: " << std::round(tan(angle) * ROUND_PRECISION) / ROUND_PRECISION << '\t' << std::fixed;

	};

	functions.push_back(get_tan);

	auto get_cot = [](const double& angle)
	{
		// cot
		std::cout << std::scientific << "\tcot: " << std::round(( cos(angle) / sin(angle) ) * ROUND_PRECISION) / ROUND_PRECISION << '\t' << std::fixed;

	};

	functions.push_back(get_cot);

	std::cout << "[��������� ����� (\w tan & cot]:\n";
	for (const auto& angle : angles)
	{
		std::cout << "rad: " << angle << '\t';
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