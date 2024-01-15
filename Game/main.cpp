#include <iostream>
#include <string>
#include "Character.h"
#include "Game.h"
#include "Map.h"
#include "Battle.h"
#include <Windows.h>//русский в консоле

using namespace std;


/*


// переменная выхода
	char InputOutGame;
	// номер класса персонажа при вводе
	int UserIn = 0;
	//создание персонажа
	int choise = 0;


	Character player;


	// вывод аттр
		//int healht = createdCharacter.GetAttributes().Hp;






	while (isRanning)
	{
		Game_print_MainMenu();


		//создание персонажа
		///////////////////////////////////////////

		choise = GetUserInput(UserIn);

		Character createdCharacter = CreateCharacter(choise);
		//createdCharacter.PrintStats();


		player = createdCharacter;
		cout << " Игровой класс создан" << endl;


		// игра
		////////////////////////////////////////////
		player.PrintStats();









		////////////////////////////////////////////
		// Выход
		cout << endl;
		cout << " Для нормального выхода введите в консоль Q и программа закроется" << endl;
		cout << endl;
		cin >> InputOutGame;
		if (InputOutGame == 'Q' || InputOutGame == 'q')
		{
			isRanning = false;
		}
		else
		{
			isRanning = true;
		}
	}




*/








int main()
{ // русский в консоле:
	SetConsoleCP(1251); // ввод
	SetConsoleOutputCP(1251); // вывод

	////////////////////////

	

	Game game;

	bool isRanning = true;
	
	while (isRanning)
	{
		game.Go();
		isRanning = game.GameStatus();

	}

	
	
	
	



	//system("pause");



	return 0;
}










