#include <iostream>
#include <string>
#include "Character.h"
#include "Game.h"
#include "Map.h"
#include "Battle.h"
#include <Windows.h>//������� � �������

using namespace std;


/*


// ���������� ������
	char InputOutGame;
	// ����� ������ ��������� ��� �����
	int UserIn = 0;
	//�������� ���������
	int choise = 0;


	Character player;


	// ����� ����
		//int healht = createdCharacter.GetAttributes().Hp;






	while (isRanning)
	{
		Game_print_MainMenu();


		//�������� ���������
		///////////////////////////////////////////

		choise = GetUserInput(UserIn);

		Character createdCharacter = CreateCharacter(choise);
		//createdCharacter.PrintStats();


		player = createdCharacter;
		cout << " ������� ����� ������" << endl;


		// ����
		////////////////////////////////////////////
		player.PrintStats();









		////////////////////////////////////////////
		// �����
		cout << endl;
		cout << " ��� ����������� ������ ������� � ������� Q � ��������� ���������" << endl;
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
{ // ������� � �������:
	SetConsoleCP(1251); // ����
	SetConsoleOutputCP(1251); // �����

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










