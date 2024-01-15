#pragma once
#include <string>
#include <conio.h>

class Input_registration
{
public:
	Input_registration();

	/// <summary>
	/// функция перехвата нажатия клавиши
	/// </summary>
	/// <param name="Input (то что вернет функция)"></param>
	/// <returns></returns>
	char Click_tracking(char Input);

	/// <summary>
	/// изменение способа ввода
	/// </summary>
	void Input_mod();
	/// <summary>
	/// Режим авто ввода (нажатие клавиши -> действие)
	/// </summary>
	bool Auto_input_mod = false;

	/// <summary>
	/// Тестовый вывод нажатой клавиши
	/// </summary>
	bool Test_output = false;

private:
	/// <summary>
	/// Хранение числового (int) кода нажатой клвиши
	/// </summary>
	int NUM;

};

