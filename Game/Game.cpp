#include "Game.h"
#include <iostream>
#include "Enemy.h"
#include "Map.h" 
#include "Battle.h"
#include "Character.h"
#include <Windows.h>
#include "NPS.h"
#include "File.h"
#include "Input_registration.h"

Game::Game()
{
}

void Game::Go()
{
	Render();
	Update();
}

bool Game::GameStatus() 
{
	if (isPlayerDie)
	{
		isGameRunnig = PlayerRebirth();
	}

	return isGameRunnig;
}

bool Game::PlayerRebirth()
{
	char in = NULL;
	std::cout << " Вы умерли" << std::endl;
	std::cout << std::endl;
	std::cout << " Желаете начать игру заново?" << std::endl;
	std::cout << " Да(Y)    Нет(N)" << std::endl;

	in = input_registration.Click_tracking(in);

	if (in == 'Y'|| in == 'y')
	{
		map.Map_set();
		isGameRunnig = true;
		player.~Character();
		bat.~Battle();
		isGameplayStarted = false;
		isGameStarted = false;
		isPlayerDie = false;
		bat.PlayerDie = false;
	}
	else if (in == 'N' || in == 'n')
	{
		isGameRunnig = false;
	}

	return isGameRunnig;
}

void Game::Render()
{
	if (!isGameStarted)
	{
		Game_loading();
	}

	if (!isGameStarted)
	{
		Game_print_MainMenu();
	}
}

void Game::Game_loading()
{
	//files.Load_File();

	//int const cols = 110;
	//int const rows = 30; // ctroka
	////x == 110 (cols)
	////y == 30 (rows)
	//int LoadingArr[rows][cols];
}

void Game::Save_game(Character& player)
{
	bool ran = true;
	char UserInput = NULL;
	char Slot_sv = NULL;

	while (ran)
	{
		system("CLS");

		std::cout << "\t\t Сохранение " << std::endl;
		std::cout << " 1. Сохранить игру " << std::endl;
		std::cout << " 2. Удалить сохранение " << std::endl;
		std::cout << " 3. Назад" << std::endl;

		UserInput = input_registration.Click_tracking(UserInput);

		switch (UserInput)
		{
		case '1':

			while (ran)
			{
				system("CLS");

				std::cout << " Введите номер слота сохранения " << std::endl;

				if (files.File_save_name.Name_save_files.Bl_path_sv_1)
				{
					std::cout << " 1. Файл: " + files.File_save_name.Name_save_files.path_sv_1 << std::endl;
				}
				else
				{
					std::cout << " 1. Пустой слот сохранения " << std::endl;
				}

				if (files.File_save_name.Name_save_files.Bl_path_sv_2)
				{
					std::cout << " 2. Файл: " + files.File_save_name.Name_save_files.path_sv_2 << std::endl;
				}
				else
				{
					std::cout << " 2. Пустой слот сохранения " << std::endl;
				}

				if (files.File_save_name.Name_save_files.Bl_path_sv_3)
				{
					std::cout << " 3. Файл: " + files.File_save_name.Name_save_files.path_sv_3 << std::endl;
				}
				else
				{
					std::cout << " 3. Пустой слот сохранения " << std::endl;
				}

				std::cout << " 4. Назад" << std::endl;

				UserInput = input_registration.Click_tracking(UserInput);

				if (UserInput != '4')
				{
					if (UserInput == '1')
					{
						Slot_sv = UserInput;
						ran = false;
					}
					else if (UserInput == '2')
					{
						Slot_sv = UserInput;
						ran = false;

					}
					else if (UserInput == '3')
					{
						Slot_sv = UserInput;
						ran = false;
					}
				}
				else if (UserInput == '4')
				{
					ran = false;
				}
				else
				{
					ran = true;
				}

			}

			if (UserInput == '4')// досрочный выход из case
			{
				break;
			}

			/////////////////////////////////////////
			//создание имени файла

			files.File_name(Slot_sv);

			////////////////////////////////////////
			// сохранение

			files.Working_file(0, 2, Slot_sv, player, input_registration);
			files.Working_file(0, 1, Slot_sv, player, input_registration);

			///////////////////////////////////////

			//////////////////////////////////////
			break;
		case '2':
			files.Working_file(2, 2, Slot_sv, player, input_registration);
			files.Working_file(0, 1, Slot_sv, player, input_registration);
			/*
			map.Map_set();
			isGameRunnig = true;
			player.~Character();
			bat.~Battle();
			isGameplayStarted = false;
			isGameStarted = false;
			isPlayerDie = false;
			bat.PlayerDie = false;
			//*/
			break;
		case'3':
			ran = false;
			break;
		default:
			break;
		}
	}
}

void Game::Loading_save(Character& player, Files& files)
{
	bool ran = true;
	char UserInput = NULL;
	char Slot_sv = NULL;

	while (ran)
	{
		system("CLS");

		std::cout << "\t\t Загрузка " << std::endl;
		std::cout << " 1. Загрузить сохранение " << std::endl;
		std::cout << " 2. Удалить сохранение " << std::endl;
		std::cout << " 3. Назад" << std::endl;

		UserInput = input_registration.Click_tracking(UserInput);

		switch (UserInput)
		{
		case '1':

			while (ran)
			{
				system("CLS");

				std::cout << " Введите номер слота сохранения " << std::endl;

				if (files.File_save_name.Name_save_files.Bl_path_sv_1)
				{
					std::cout << " 1. Файл: " + files.File_save_name.Name_save_files.path_sv_1 << std::endl;
				}
				else
				{
					std::cout << " 1. Пустой слот сохранения " << std::endl;
				}

				if (files.File_save_name.Name_save_files.Bl_path_sv_2)
				{
					std::cout << " 2. Файл: " + files.File_save_name.Name_save_files.path_sv_2 << std::endl;
				}
				else
				{
					std::cout << " 2. Пустой слот сохранения " << std::endl;
				}

				if (files.File_save_name.Name_save_files.Bl_path_sv_3)
				{
					std::cout << " 3. Файл: " + files.File_save_name.Name_save_files.path_sv_3 << std::endl;
				}
				else
				{
					std::cout << " 3. Пустой слот сохранения " << std::endl;
				}

				std::cout << " 4. Назад" << std::endl;

				UserInput = input_registration.Click_tracking(UserInput);

				if (UserInput != '4')
				{
					if (UserInput == '1')
					{
						if (files.File_save_name.Name_save_files.Bl_path_sv_1)
						{
							Slot_sv = UserInput;
							ran = false;
						}
						else
						{
							ran = true;
						}
					}
					else if (UserInput == '2')
					{
						if (files.File_save_name.Name_save_files.Bl_path_sv_2)
						{
							Slot_sv = UserInput;
							ran = false;
						}
						else
						{
							ran = true;
						}
					}
					else if (UserInput == '3')
					{
						if (files.File_save_name.Name_save_files.Bl_path_sv_3)
						{
							Slot_sv = UserInput;
							ran = false;
						}
						else
						{
							ran = true;
						}
					}
				}
				else if (UserInput == '4')
				{
					ran = false;
				}
				else
				{
					ran = true;
				}

			}

			if (UserInput == '4')// досрочный выход из case
			{
				break;
			}

			///////////////////////////////////////
			// загрузка из файла под слотом (Slot_sv)
			isGameRunnig = true;
			isGameStarted = true;
			isGameplayStarted = true;

			files.Working_file(1, 2, Slot_sv, player, input_registration);
			player = CreateCharacter(player);
			Player_initialization(player, tempCharacter, map);
			map.Map_set();
			map.InsertPlayerIntoMap(player);
			//////////////////////////////////////
			break;
		case '2':

			files.Working_file(2, 2, Slot_sv, player, input_registration);
			files.Working_file(0, 1, Slot_sv, player, input_registration);
			/*
			map.Map_set();
			isGameRunnig = true;
			player.~Character();
			bat.~Battle();
			isGameplayStarted = false;
			isGameStarted = false;
			isPlayerDie = false;
			bat.PlayerDie = false;
			//*/
			break;
		case'3':
			ran = false;
			break;
		default:
			break;
		}
	}
}

void Game::Game_print_MainMenu()
{
	if (!isGameStarted)
	{
		files.Working_file(1, 1, 0, player, input_registration);

		if (!files.File_save)
		{
			system("CLS");
			std::cout << std::endl;
			std::cout << "*********************************" << std::endl;
			std::cout << "************** GAME *************" << std::endl;
			std::cout << "*********************************" << std::endl;
			std::cout << std::endl; std::cout << std::endl;
			std::cout << "***     1.  Начать игру       ***" << std::endl;
			std::cout << std::endl; std::cout << std::endl;
			std::cout << "****     2.  Настройки       ****" << std::endl;
			std::cout << std::endl; std::cout << std::endl;
			std::cout << "*****    3. Разработчики    *****" << std::endl;
			std::cout << std::endl; std::cout << std::endl;
			std::cout << "******     4.  Выход       ******" << std::endl;
			std::cout << std::endl;
			std::cout << "\t Версия a 0.0.3 " << std::endl;
		}
		else if (files.File_save)
		{
			system("CLS");
			std::cout << std::endl;
			std::cout << "*********************************" << std::endl;
			std::cout << "************** GAME *************" << std::endl;
			std::cout << "*********************************" << std::endl;
			std::cout << std::endl; std::cout << std::endl;
			std::cout << "**       1.  Начать игру       **" << std::endl;
			std::cout << std::endl; std::cout << std::endl;
			std::cout << "***     2. Загрузить игру     ***" << std::endl;
			std::cout << std::endl; std::cout << std::endl;
			std::cout << "****     3.  Настройки       ****" << std::endl;
			std::cout << std::endl; std::cout << std::endl;
			std::cout << "*****    4. Разработчики    *****" << std::endl;
			std::cout << std::endl; std::cout << std::endl;
			std::cout << "******     5.  Выход       ******" << std::endl;
			std::cout << std::endl;
			std::cout << "\t Версия a 0.0.2 " << std::endl;
		}
		else
		{
			std::cout << " Не корректная работа программы" << std::endl;
			system("pause");
		}
		char UserInput = NULL;
		bool settings = true;
		char input = NULL;

		input = input_registration.Click_tracking(input);

		switch (input)
		{
		case '1':
		{
			New_game();
			break;
		}
		case '2':
		{
			if (files.File_save)
			{
				Loading_save(player, files);
				break;
			}
			else
			{
				Settings();
				break;
			}
		}
		case '3':
		{
			if (files.File_save)
			{
				Settings();
				break;
			}
			else
			{
				Developers();
				break;
			}
		}
		case '4':
		{
			if (files.File_save)
			{
				Developers();
				break;
			}
			else
			{
				isGameRunnig = false;
				break;
			}
		}
		case '5':
		{
			if (files.File_save)
			{
				isGameRunnig = false;
				break;
			}
		}
		default:
			system("CLS");
			break;
			
		}
	}
}

void Game::New_game()
{
	system("CLS");
	//bat.Size_Console();
	Game_mode();
	Nickname();
	isGameStarted = true;
}

void Game::Settings()
{
	char UserInput = NULL;

	settings = true;

	while (settings)
	{
		system("CLS");
		std::cout << "1. Изменение способа ввода" << std::endl;
		std::cout << "2. >Изменение символов< не работает по причине ввода enum" << std::endl;
		std::cout << "3. Востановить карту" << std::endl;
		std::cout << "4. Выйти из настроек" << std::endl;

		UserInput = input_registration.Click_tracking(UserInput);

		switch (UserInput)
		{
		case '1':
		{
			system("CLS");

			input_registration.Input_mod();

			files.Working_file(0, 1, 0, player, input_registration);

			break;
		}
		case '2':
			system("CLS");

			map.Simbol();

			break;

		case '3':
			system("CLS");

			UserInput = NULL;

			std::cout << " Вы действительно желаете пересобрать карту?" << std::endl;
			std::cout << "      Да(Y)                Нет(N)" << std::endl;

			UserInput = input_registration.Click_tracking(UserInput);

			if (UserInput == 'Y' || UserInput == 'y')
			{
				std::cout << " Создание карты... 0%" << std::endl;
				Sleep(500);
				std::cout << " Создание карты... 20%" << std::endl;
				Sleep(300);
				std::cout << " Создание карты... 50%" << std::endl;
				Sleep(600);
				std::cout << " Создание карты... 70%" << std::endl;
				Sleep(100);
				std::cout << " Создание карты... 80%" << std::endl;
				map.Map_set();
				Sleep(400);
				std::cout << " Создание карты закончено" << std::endl;
				system("pause");
			}
			else if (UserInput == 'N' || UserInput == 'n')
			{
				settings = true;
			}
			break;

		case '4':
			system("CLS");
			UserInput = NULL;
			settings = false;
			break;

		case 'm':
			system("CLS");
			map.PrintMap(player);
			system("pause");
			settings = true;
			break;

		default:
			system("CLS");
			settings = true;
			break;
		}
	}
}

void Game::Developers()
{
	system("CLS");
	std::cout << " Люди приложившие усилия чтобы сие творение увидело свет: " << std::endl;
	std::cout << std::endl; std::cout << std::endl;
	std::cout << " Создатель вселенной:" << std::endl;
	std::cout << " - Azazel" << std::endl;
	std::cout << std::endl;
	std::cout << " Демиург: " << std::endl;
	std::cout << " - Alfatrion" << std::endl;
	std::cout << std::endl;
	std::cout << " Заклинатель букв:" << std::endl;
	std::cout << " - Mezekin" << std::endl;
	std::cout << std::endl;
	std::cout << " [болтал под руку]: " << std::endl;
	std::cout << " - Albatros995" << std::endl;
	std::cout << std::endl;
	system("pause");
}

void Game::Game_mode()
{
	bool work;

	char in = NULL;

	do
	{
		switch (in)
		{
		case NULL:
		{
			system("CLS");
			std::cout << " Выберите режим игры:" << std::endl;
			std::cout << " 1 - Легкий режим" << std::endl;
			std::cout << " 2 - Нормальный режим" << std::endl;
			std::cout << " 3 - Сложный режим" << std::endl;
			std::cout << " Т - тестовый" << std::endl;
			in = input_registration.Click_tracking(in);
			work = true;
			break;
		}
		case '1':
		{
			system("CLS");
			std::cout << " Нет функционала" << std::endl;
			system("pause");
			in = NULL;
			work = true;
			break;
		}
		case '2':
		{
			system("CLS");
			std::cout << " Стандартные настройки сложности" << std::endl;

			Bl_Battle_val(bat, 1);
			Mode_change(input_registration, false);

			in = '@';
			work = true;
			break;
		}
		case '3':
		{
			system("CLS");
			std::cout << " Нет функционала" << std::endl;
			system("pause");
			in = NULL;
			work = true;
			break;
		}
		case 't':
		{
			system("CLS");
			std::cout << " Режим игры без боя" << std::endl;

			Bl_Battle_val(bat, 2);
			Mode_change(input_registration, true);

			in = '@';
			work = true;
			break;
		}
		case '@':
		{
			std::cout << std::endl;
			std::cout << " Вы уверены в своем выборе?" << std::endl;
			std::cout << "     Да(Y)         Нет(N)" << std::endl;

			in = input_registration.Click_tracking(in);

			if (in == 'Y' || in == 'y')
			{
				work = false;
			}
			else if (in == 'N' || in == 'n')
			{
				work = true;
				in = NULL;
			}
			break;
		}
		default:
		{
			in = NULL;
			std::cout << " Не корректный ввод" << std::endl;
			system("pause");
			work = true;
			break;
		}
		}

	} while (work);
}

void Game::Mode_change(Input_registration& input_registration, bool Mode)
{
	if (!Mode)
	{
		input_registration.Test_output = false;
	}
	else if (Mode)
	{
		input_registration.Test_output = true;
	}
}

void Game::Bl_Battle_val(Battle& bat, int Mode)
{
	if (Mode == 1)
	{
		bat.battleRan = true;
	}
	else if (Mode == 2)
	{
		bat.battleRan = false;
	}
}

void Game::Player_initialization(Character& player, Character& tempCharacter, Map& map)
{
	if (!isGameplayStarted)
	{
		player = tempCharacter;
		isGameplayStarted = true;
	}
	player.CreateInventiry(1);
	player._PlayerAttributes._SystemParam._StorageAttributes.Add_standart_param();
	map.InsertPlayerIntoMap(player);
	tempCharacter.~Character();
}

void Game::Nickname()
{
	system("CLS");
	while (true)
	{
		std::cout << " Введите ник: ";

		std::cin >> player._PlayerAttributes.name_Character;

		if (player._PlayerAttributes.name_Character != "DEF")
		{
			return;
		}
		else
		{
			system("CLS");
		}
	}
}

void Game::Update()
{
	char charInput = NULL;

	if (isGameStarted)
	{
		if (isGameStarted && !isGameplayStarted && !player._PlayerAttributes._SystemParam.Load_save)
		{
			bool B_While = true;
			do
			{
				namberClass = GetUserInput(namberClass);
				if (namberClass != '4')
				{
					tempCharacter = CreateCharacter(player, namberClass);
					std::cout << " Вы уверены в в своем выборе?  y/n" << std::endl;

					charInput = input_registration.Click_tracking(charInput);

					if (charInput == 'Y' || charInput == 'y' || charInput == 'Н' || charInput == 'н')
					{
						Player_initialization(player, tempCharacter, map);
						B_While = false;
					}
					else if (charInput == 'N' || charInput == 'n' || charInput == 'Т' || charInput == 'т')
					{
						B_While = true;
					}
					else
					{
						system("CLS");
					}
				}
				else 
				{
					isGameStarted = false;
					B_While = false;
				}
			} while (B_While);
		}
		if (isGameplayStarted)
		{
			Game_print_Gameplay(player);
		}
	}
}

char Game::GetUserInput(char namberClass)
{

	bool revisionClassNumber = true;

	while (revisionClassNumber)
	{
		system("CLS");
		std::cout << std::endl;
		std::cout << " Выберие класс персонажа" << std::endl;
		std::cout << " 1. Воин" << " 2. Маг" << " 3. Охотник"<< " 4. Назад в главное меню" << std::endl;

		namberClass = input_registration.Click_tracking(namberClass);
		 
		switch (namberClass)
		{
		case '1':
			revisionClassNumber = false;
			return namberClass;
		case '2':
			revisionClassNumber = false;
			return namberClass;
		case '3':
			revisionClassNumber = false;
			return namberClass;
		case '4':
			revisionClassNumber = false;
			return namberClass;
		default:
			std::cout << " Введите номер нужного вам класса или 4 для выхода из меню выбора персонажа " << std::endl;
			system("pause");
			revisionClassNumber = true;
			break;
		}
	}
}

Character Game::CreateCharacter(Character& player, char tempCharacter)
{
	bool isRanning = true;

	// переменная пере выбора класса
	//char Input;

	while (isRanning)
	{
		if (tempCharacter == '1' || player._PlayerAttributes._SystemParam.int_name_Class == 1)
		{
			PlayerAttributes warriorAttributes = {};

			warriorAttributes.name_Character = player._PlayerAttributes.name_Character;
			if (!player._PlayerAttributes._SystemParam.Load_save)
			{
				warriorAttributes.P_Levl = 1;
			}
			else if (player._PlayerAttributes._SystemParam.Load_save)
			{
				warriorAttributes.P_Levl = player._PlayerAttributes.P_Levl;
			}

			if (!player._PlayerAttributes._SystemParam.Load_save)
			{
				warriorAttributes.P_Hp = 150;
			}
			else if (player._PlayerAttributes._SystemParam.Load_save)
			{
				warriorAttributes.P_Hp = player._PlayerAttributes.P_Hp;
			}

			if (!player._PlayerAttributes._SystemParam.Load_save)
			{
				warriorAttributes.P_Mana = 50;
			}
			else if (player._PlayerAttributes._SystemParam.Load_save)
			{
				warriorAttributes.P_Mana = player._PlayerAttributes.P_Mana;
			}

			warriorAttributes.P_armor = 70;

			warriorAttributes.P_attack = 60;

			warriorAttributes.P_avoid = 25;

			if (!player._PlayerAttributes._SystemParam.Load_save)
			{
				warriorAttributes.P_stamina = 40;
			}
			else if (player._PlayerAttributes._SystemParam.Load_save)
			{
				warriorAttributes.P_stamina = player._PlayerAttributes.P_stamina;
			}

			if (!player._PlayerAttributes._SystemParam.Load_save)
			{
				warriorAttributes._SystemParam.Overview = false;
			}
			else if (player._PlayerAttributes._SystemParam.Load_save)
			{
				warriorAttributes._SystemParam.Overview = player._PlayerAttributes._SystemParam.Overview;
			}

			warriorAttributes.P_Expenditure_Attack = 10;

			warriorAttributes.P_Expenditure_Escape = 7;

			warriorAttributes.name_Class = " Воин";

			warriorAttributes._SystemParam.int_name_Class = 1;

			if (!player._PlayerAttributes._SystemParam.Load_save)
			{
				warriorAttributes._SystemParam._Position.Int_World = 9;
			}
			else if (player._PlayerAttributes._SystemParam.Load_save)
			{
				warriorAttributes._SystemParam._Position.Int_World = player._PlayerAttributes._SystemParam._Position.Int_World;
			}

			if (!player._PlayerAttributes._SystemParam.Load_save)
			{
				warriorAttributes._SystemParam._Position.x = 25;
			}
			else if (player._PlayerAttributes._SystemParam.Load_save)
			{
				warriorAttributes._SystemParam._Position.x = player._PlayerAttributes._SystemParam._Position.x;
			}

			if (!player._PlayerAttributes._SystemParam.Load_save)
			{
				warriorAttributes._SystemParam._Position.y = 12;
			}
			else if (player._PlayerAttributes._SystemParam.Load_save)
			{
				warriorAttributes._SystemParam._Position.y = player._PlayerAttributes._SystemParam._Position.y;
			}

			Character Warrior(warriorAttributes);

			if (!player._PlayerAttributes._SystemParam.Load_save)
			{
				Warrior.PrintCreatStatsP();
			}
			else if (player._PlayerAttributes._SystemParam.Load_save)
			{
				player = Warrior;
			}

			return Warrior;
		}
		else if (tempCharacter == '2' || player._PlayerAttributes._SystemParam.int_name_Class == 2)
		{
			PlayerAttributes mageAttributes = {};

			mageAttributes.name_Character = player._PlayerAttributes.name_Character;

			if (!player._PlayerAttributes._SystemParam.Load_save)
			{
				mageAttributes.P_Levl = 1;
			}
			else if (player._PlayerAttributes._SystemParam.Load_save)
			{
				mageAttributes.P_Levl = player._PlayerAttributes.P_Levl;
			}

			if (!player._PlayerAttributes._SystemParam.Load_save)
			{
				mageAttributes.P_Hp = 100;
			}
			else if (player._PlayerAttributes._SystemParam.Load_save)
			{
				mageAttributes.P_Hp = player._PlayerAttributes.P_Hp;
			}

			if (!player._PlayerAttributes._SystemParam.Load_save)
			{
				mageAttributes.P_Mana = 250;
			}
			else if (player._PlayerAttributes._SystemParam.Load_save)
			{
				mageAttributes.P_Mana = player._PlayerAttributes.P_Hp;
			}

			mageAttributes.P_armor = 25;

			mageAttributes.P_attack = 70;

			mageAttributes.P_avoid = 15;

			if (!player._PlayerAttributes._SystemParam.Load_save)
			{
				mageAttributes.P_stamina = 15;
			}
			else if (player._PlayerAttributes._SystemParam.Load_save)
			{
				mageAttributes.P_stamina = player._PlayerAttributes.P_stamina;
			}

			if (!player._PlayerAttributes._SystemParam.Load_save)
			{
				mageAttributes._SystemParam.Overview = false;
			}
			else if (player._PlayerAttributes._SystemParam.Load_save)
			{
				mageAttributes._SystemParam.Overview = player._PlayerAttributes._SystemParam.Overview;
			}

			mageAttributes.P_Expenditure_Attack = 2;

			mageAttributes.P_Expenditure_Escape = 4;

			mageAttributes.name_Class = " Маг";

			mageAttributes._SystemParam.int_name_Class = 2;

			if (!player._PlayerAttributes._SystemParam.Load_save)
			{
				mageAttributes._SystemParam._Position.Int_World = 9;
			}
			else if (player._PlayerAttributes._SystemParam.Load_save)
			{
				mageAttributes._SystemParam._Position.Int_World = player._PlayerAttributes._SystemParam._Position.Int_World;
			}

			if (!player._PlayerAttributes._SystemParam.Load_save)
			{
				mageAttributes._SystemParam._Position.x = 25;
			}
			else if (player._PlayerAttributes._SystemParam.Load_save)
			{
				mageAttributes._SystemParam._Position.x = player._PlayerAttributes._SystemParam._Position.x;
			}

			if (!player._PlayerAttributes._SystemParam.Load_save)
			{
				mageAttributes._SystemParam._Position.y = 12;
			}
			else if (player._PlayerAttributes._SystemParam.Load_save)
			{
				mageAttributes._SystemParam._Position.y = player._PlayerAttributes._SystemParam._Position.y;
			}

			Character Mage(mageAttributes);

			if (!player._PlayerAttributes._SystemParam.Load_save)
			{
				Mage.PrintCreatStatsP();
			}
			else if (player._PlayerAttributes._SystemParam.Load_save)
			{
				player = Mage;
			}

			return Mage;
		}
		else if (tempCharacter == '3' || player._PlayerAttributes._SystemParam.int_name_Class == 3)
		{
			PlayerAttributes hunterAttributes = {};

			hunterAttributes.name_Character = player._PlayerAttributes.name_Character;

			if (!player._PlayerAttributes._SystemParam.Load_save)
			{
				hunterAttributes.P_Levl = 1;
			}
			else if (player._PlayerAttributes._SystemParam.Load_save)
			{
				hunterAttributes.P_Levl = player._PlayerAttributes.P_Levl;
			}

			if (!player._PlayerAttributes._SystemParam.Load_save)
			{
				hunterAttributes.P_Hp = 120;
			}
			else if (player._PlayerAttributes._SystemParam.Load_save)
			{
				hunterAttributes.P_Hp = player._PlayerAttributes.P_Hp;
			}

			if (!player._PlayerAttributes._SystemParam.Load_save)
			{
				hunterAttributes.P_Mana = 70;
			}
			else if (player._PlayerAttributes._SystemParam.Load_save)
			{
				hunterAttributes.P_Mana = player._PlayerAttributes.P_Mana;
			}
			hunterAttributes.P_armor = 50;

			hunterAttributes.P_attack = 50;

			hunterAttributes.P_avoid = 45;

			if (!player._PlayerAttributes._SystemParam.Load_save)
			{
				hunterAttributes.P_stamina = 50;
			}
			else if (player._PlayerAttributes._SystemParam.Load_save)
			{
				hunterAttributes.P_stamina = player._PlayerAttributes.P_stamina;
			}

			if (!player._PlayerAttributes._SystemParam.Load_save)
			{
				hunterAttributes._SystemParam.Overview = false;
			}
			else if (player._PlayerAttributes._SystemParam.Load_save)
			{
				hunterAttributes._SystemParam.Overview = player._PlayerAttributes._SystemParam.Overview;
			}

			hunterAttributes.P_Expenditure_Attack = 4;

			hunterAttributes.P_Expenditure_Escape = 6;

			hunterAttributes.name_Class = " Охотник";

			hunterAttributes._SystemParam.int_name_Class = 3;

			if (!player._PlayerAttributes._SystemParam.Load_save)
			{
				hunterAttributes._SystemParam._Position.Int_World = 9;
			}
			else if (player._PlayerAttributes._SystemParam.Load_save)
			{
				hunterAttributes._SystemParam._Position.Int_World = player._PlayerAttributes._SystemParam._Position.Int_World;
			}

			if (!player._PlayerAttributes._SystemParam.Load_save)
			{
				hunterAttributes._SystemParam._Position.x = 25;
			}
			else if (player._PlayerAttributes._SystemParam.Load_save)
			{
				hunterAttributes._SystemParam._Position.x = player._PlayerAttributes._SystemParam._Position.x;
			}

			if (!player._PlayerAttributes._SystemParam.Load_save)
			{
				hunterAttributes._SystemParam._Position.y = 12;
			}
			else if (player._PlayerAttributes._SystemParam.Load_save)
			{
				hunterAttributes._SystemParam._Position.y = player._PlayerAttributes._SystemParam._Position.y;
			}

			Character Hunter(hunterAttributes);

			if (!player._PlayerAttributes._SystemParam.Load_save)
			{
				Hunter.PrintCreatStatsP();
			}
			else if (player._PlayerAttributes._SystemParam.Load_save)
			{
				player = Hunter;
			}
			return Hunter;
		}
		else if (tempCharacter == '4')
		{
			std::cout << " Выход из меню выбора персонажа " << std::endl;
			std::cout << std::endl;
			isGameStarted = false; // в главное меню
			isRanning = false;
		}
		else
		{
			system("CLS");
			std::cout << " Введите номер нужного вам класса или 4 для выхода " << std::endl;
			system("pause");
		}
	}
}

void Actions::Options_actions(bool BL_Drop_Item, int Stamina, bool Alert, bool Overview, int Int_World, bool Bl_Save, bool Bl_Passage, bool return_village)
{
	/////////////////// 1
	if (BL_Drop_Item)
	{
		std::cout << " Подобрать предмет(F)" << std::endl;

		Drop_item = true;
		
	}
	////////////////////  2
	if (Stamina <=10 || Alert)
	{
		std::cout << " Окно персонажа (E)*" << std::endl;

		Alert_attr = true;
	}
	else
	{
		std::cout << " Окно персонажа (E)" << std::endl;
	}

	///////////////////  3
	if (Stamina <= 3)
	{
		std::cout << " Вы слишком устали для путешествий" << std::endl;

		No_travel = true;
	}
	else
	{
		std::cout << " Путешествовать (Т)" << std::endl;

		Travel = true;
	}

	//////////////////  4
	if (Overview)
	{
		std::cout << " Потушить факел (V)" << std::endl;

		Fire_off = true;
	}
	else if (!Overview && Int_World != 10)
	{
		std::cout << " Зажечь факел (V)" << std::endl;

		Fire_on = true;
	}
	//////////////////  5
	if (Bl_Save || Int_World == 10)
	{
		std::cout << " Сохраниться (S)" << std::endl;

		Load_save = true;
	}

	//////////////////  6

	if (Bl_Passage)
	{
		std::cout << " Перейти в новую облость (G)" << std::endl;

		if (return_village)
		{
			std::cout << " Вернуться в поселение (R)" << std::endl;
		}

		Passage = true;
	}

	///////////////// 7
	
	if (true)
	{
		std::cout << " Meню (Q)" << std::endl;

		Menu = true;
	}
}

void Game::Game_print_Gameplay(Character& player)
{
	if (player._PlayerAttributes._SystemParam.Auto_input != input_registration.Auto_input_mod)
	{
		player._PlayerAttributes._SystemParam.Auto_input = input_registration.Auto_input_mod;
	}
	
	bool While_ran = true;
	char In = NULL;

	if (bat.battleRan &&  map.attr_World.Int_Current_World != 10)
	{
		bat.battle(player, enemy);

		if (bat.PlayerDie)
		{
			isPlayerDie = true;
			return;
		}
	}

	do
	{
		system("CLS");
		std::cout << "\t\t" << map.attr_World.Current_World << map.attr_World.village.Village_region << std::endl;
		map.PrintMap(player);
		std::cout << "X: " << player._PlayerAttributes._SystemParam._Position.x << " Y: " << player._PlayerAttributes._SystemParam._Position.y <<std::endl;
		std::cout << std::endl;

		Actions.Options_actions( map.attr_World.Drop_attr.Bl_Drop_Item, player._PlayerAttributes.P_stamina, player._PlayerAttributes._SystemParam.Alert, player._PlayerAttributes._SystemParam.Overview, map.attr_World.Int_Current_World, map.attr_World.Load_save, map.attr_World.Passage, map.attr_World.village.Return_village);

		In = input_registration.Click_tracking(In);
		
		if (In == 'Q' || In == 'q' || In == 'Й' || In == 'й')
		{
			if (Actions.Menu)
			{
				GameMenu();
				While_ran = false;
				Actions.Menu = false;
			}
		}
		else if (In == 'V' || In == 'v' || In == 'М' || In == 'м')
		{

			if (!player._PlayerAttributes._SystemParam.Overview)
			{
				if (Actions.Fire_on)
				{
					player._PlayerAttributes._SystemParam.Overview = true;
					map.InsertPlayerIntoMap(player);
					While_ran = false;
					Actions.Fire_on = false;
				}
			}
			else if (player._PlayerAttributes._SystemParam.Overview)
			{
				if (Actions.Fire_off)
				{
					player._PlayerAttributes._SystemParam.Overview = false;
					map.InsertPlayerIntoMap(player);
					While_ran = false;
					Actions.Fire_off = false;
				}
			}
		}
		else if (In == 'T' || In == 't' || In == 'Е' || In == 'е')
		{
			if (Actions.Travel && !Actions.No_travel)
			{
				std::cout << "      Выберите направление              " << std::endl;
				std::cout << std::endl;
				std::cout << "            Север (W) " << std::endl;
				std::cout << " Запад (A)" << "             Восток (D) " << std::endl;
				std::cout << "             Юг (S) " << std::endl;

				In = input_registration.Click_tracking(In);

				if (In == 'A' || In == 'a')//1
				{
					//player.Move(1);
					map.InsertPlayerIntoMap(player, 1);
					While_ran = false;
				}
				else if (In == 'W' || In == 'w')//2
				{
					//player.Move(2);
					map.InsertPlayerIntoMap(player, 2);
					While_ran = false;
				}
				else if (In == 'D' || In == 'd')//3
				{
					//player.Move(3);
					map.InsertPlayerIntoMap(player, 3);
					While_ran = false;
				}
				else if (In == 'S' || In == 's')//4
				{
					//player.Move(4);
					map.InsertPlayerIntoMap(player, 4);
					While_ran = false;
				}
				Actions.Travel = false;
			}
		}
		else if (In == 'E' || In == 'e')
		{
			player.Player_Windows();
			While_ran = false;
			Actions.Alert_attr = false;
		}
		else if (In == 'S' || In == 's')
		{
			if (Actions.Load_save)
			{
				Save_game(player);
				While_ran = false;
				Actions.Load_save = false;
			}
		}
		else if (In == 'G' || In == 'g' || In == 'R' || In == 'r')
		{
			if (Actions.Passage)
			{
				if (In == 'R' || In == 'r')
				{
					player._PlayerAttributes._SystemParam.Overview = false;
					player._PlayerAttributes._SystemParam._Position.returns_village = true;
				}
				player._PlayerAttributes._SystemParam._Position.Transfer_player = true;
				map.InsertPlayerIntoMap(player);
				While_ran = false;
				Actions.Passage = false;
			}
		}
		else if (In == 'F' || In == 'f')
		{
			if (Actions.Drop_item)
			{
				std::cout << " Нет функционала" << std::endl;
				Actions.Drop_item = false;
			}
		}
		system("CLS");

		In = NULL;

	} while (While_ran);
}

void Game::GameMenu()
{
	bool RaningGameMenu = true;

	char input = NULL;

	while (RaningGameMenu)
	{
		system("CLS");
		std::cout << std::endl;
		std::cout << "**************************************" << std::endl;
		std::cout << "************** GAME MENU *************" << std::endl;
		std::cout << "**************************************" << std::endl;
		std::cout << std::endl; std::cout << std::endl;
		std::cout << "***       1.  Продолжить           ***" << std::endl;
		std::cout << std::endl; std::cout << std::endl;
		std::cout << "****       2.  Настройки          ****" << std::endl;
		std::cout << std::endl; std::cout << std::endl;
		std::cout << "***** 3.  Выйти в главное меню   *****" << std::endl;
		std::cout << std::endl;

		input = input_registration.Click_tracking(input);

		if (input == '1')
		{
			system("CLS");
			RaningGameMenu = false;
		}
		else if (input == '2')
		{
			bool inventory = true;
			int namberItem;
			int quantity;

			char UserInput = NULL;
			settings = true;
			while (settings)
			{
				system("CLS");
				std::cout << "1. Изменение символов" << std::endl;
				std::cout << "2. Востановить карту" << std::endl;
				std::cout << "3. > inventory <"  << std::endl;
				std::cout << "4. Бестиарий" << std::endl;
				std::cout << "5. Выйти из настроек" << std::endl;
				std::cout << "m" << std::endl;

				UserInput = input_registration.Click_tracking(UserInput);

				switch (UserInput)
				{
				case '1':
					map.Simbol();
					break;

				case '2':
					std::cout << " Вы действительно желаете пересобрать карту?" << std::endl;
					std::cout << "      Да(Y)                Нет(N)" << std::endl;

					UserInput = input_registration.Click_tracking(UserInput);

					if (UserInput == 'Y' || UserInput == 'y')
					{
						std::cout << " Создание карты... 0%" << std::endl;
						Sleep(500);
						std::cout << " Создание карты... 20%" << std::endl;
						Sleep(300);
						std::cout << " Создание карты... 50%" << std::endl;
						Sleep(600);
						std::cout << " Создание карты... 70%" << std::endl;
						Sleep(100);
						std::cout << " Создание карты... 80%" << std::endl;
						map.Map_set();
						Sleep(400);
						std::cout << " Создание карты закончено" << std::endl;
						system("pause");
					}
					else if (UserInput == 'N' || UserInput == 'n')
					{
						settings = false;
					}
					break;

				case '3':
					
					system("CLS");
					std::cout << "*** inventory ***" << std::endl;
					
					player.CreateInventiry(1);

					UserInput = ' ';	

					while (inventory)
					{
						if (UserInput == ' ')
						{

							std::cout << " Введите номер предмета и его количество" << std::endl;

							std::cout << " NamberItem: "; std::cin >> namberItem;
							std::cout << "\n Quantity: "; std::cin >> quantity;

							player.InItemsInventory(namberItem, quantity);
						}
						else if (UserInput != ' ')
						{
							UserInput = ' ';
						}

						std::cout << "\n Закончить добавление предметов в инвентарь?" << std::endl;
						std::cout << "Нет(1)   Да(2)" << std::endl;

						UserInput = input_registration.Click_tracking(UserInput);


						if (UserInput == '1')
						{
							UserInput = ' ';
						}
						else if (UserInput == '2')
						{
							inventory = false;
						}
						else
						{
							UserInput = '0';
						}
					}

					// inventory

					player.Inventory();


					// out

					inventory = true;
					UserInput = ' ';

					while (inventory)
					{

						if (UserInput == '1')
						{
							std::cout << " Введите номер предмета " << std::endl;
							std::cout << " Номер: "; std::cin >> namberItem;
							std::cout << std::endl;
							player.OutItemsInventory(namberItem);
							UserInput = ' ';
						}
						else if (UserInput == '2')
						{

							inventory = false;
						}
						else
						{
							std::cout << "\n Желаете выбрать предмет?" << std::endl;
							std::cout << "да(1)   Нет(2)" << std::endl;
							std::cin >> UserInput;
						}

					}
					break;

				case '4':
					
					system("CLS");
					std::cout << "*** Бестиарий ***" << std::endl;

					Bestiary_enemy.Enemy_Attrbutes.enamyNumber = 1;
					Bestiary_enemy.bestiaryRan = true;
					
				    Bestiary_enemy.CreateEnemy(Bestiary_enemy);
					std::cout << std::endl;

					std::cout << "*** final ***" << std::endl;
					system("pause");
					break;

				case '5':
					UserInput = ' ';
					settings = false;
					break;
					 
				case 'm':
					map.PrintMapSetting(player);
					system("pause");
					break;
				default:
					system("CLS");
					break;
				}
				settings = false;
			}
		}
		else if (input == '3')
		{
			map.Map_set();
			isGameRunnig = true;
			player.~Character();
			bat.~Battle();
			isGameplayStarted = false;
			isGameStarted = false;
			isPlayerDie = false;
			bat.PlayerDie = false;
			RaningGameMenu = false;
		}
		else
		{
		/*
		
		// враг
		enemy.GetAttributesE();
		enemy.PrintEnemyStats();

		// персонаж
		player.GetAttributesP();
		player.Get_player_position_X();
		player.Get_player_position_Y();
		player.Move(1);
		player.PrintCreatStatsP();
		player.PrintStats();
		player.WindowPlayer();
		
		// инвентарь
		player.CreateInventiry(1);
		player.Inventory(NumberItem, quantity, page);
		player.InItemsInventory(NumberItem, quantity, page);

		//*/
			system("CLS");
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////
