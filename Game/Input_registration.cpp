#include "Input_registration.h"
#include <iostream>
#include <Windows.h>

Input_registration::Input_registration()
{
}

char Input_registration::Click_tracking(char Input)
{
	if (Auto_input_mod)
	{
		std::cout << "\n (auto) ввод: ";
	}
	else
	{
		std::cout << "\n Ввод: ";
	}

	while (true)
	{

		if (!Auto_input_mod)
		{
			// нажатие - enter - действие

			std::cin >> Input;

			return Input;

		}
		else if (Auto_input_mod)
		{
			// нажатие - действие
			if (_kbhit())
			{
				NUM = _getwch();
				Input = (char)NUM;

				if (Test_output)
				{
					std::cout << (char)NUM << "\t" << " Код: " << NUM << std::endl;
					Sleep(300);
				}
				else
				{
					std::cout << (char)NUM << std::endl;
				}

				return Input;
			}
		}
	}
}

void Input_registration::Input_mod()
{
	bool ran = true;

	char in = NULL;

	while (ran)
	{
		system("CLS");
		std::cout << "        * Изменение способа ввода * " << std::endl;
		std::cout << std::endl;
		std::cout << " 1. Автоматический ввод" << std::endl;
		std::cout << " 2. Ввод с подтверждением" << std::endl;
		std::cout << " 3. Назад" << std::endl;

		in = Click_tracking(in);

		if (in == '1')
		{
			system("CLS");
			std::cout<<"\n" << " Ввод символа -> действие" << std::endl;
			system("pause");
			Auto_input_mod = true;
			ran = false;
		}
		else if (in == '2')
		{
			system("CLS");
			std::cout << "\n" << " Ввод символа -> нажатие enter -> действие" << std::endl;
			system("pause");
			Auto_input_mod = false;
			ran = false;
		}
		else if (in == '3')
		{
			ran = false;
		}
		else
		{
			std::cout << "\n" << " Не корректный ввод. введите 1, 2 или 3" << std::endl;
			system("pause");
		}
	}
}
