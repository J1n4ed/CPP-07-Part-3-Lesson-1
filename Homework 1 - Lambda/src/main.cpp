// main.cpp

/*
  25.04.2023
  ����� 3 - ����������� ���������������� �� C++
  ������� 1 - ��������� �++
  ������ 1 - ������-�������
  CPP-07
  ������� ����
*/

/*
������� ������:  4 7 9 14 12
�������� ������: 4 21 27 14 12
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
	std::cout << "������� ������: ";

	for (const int & i : dataArr)
	{
		std::cout << i << ' ';
	}

	std::cout << std::endl;

	std::cout << "�������� ������: ";
	
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