#include "Battle.h"
#include <iostream>
#include <Windows.h>
#include"Character.h"
#include "Enemy.h"
#include "Input_registration.h"


Battle::Battle()
{
}

Battle::~Battle()
{
}

void Battle::Size_Console()
{
	system("CLS");
	bool Bl_While = true;
	while (Bl_While)
	{
		char in = ' ';
		std::cout << " Для корректной работы требуется указать размер консоли" << std::endl;
		std::cout << " Выберите вид консоли из перечисленного( 1 или 2 ): " << std::endl;
		std::cout << " 1. Консоль развернута во весь экран" << std::endl;
		std::cout << " 2. Консоль открыта в маленьком окне" << std::endl;
		std::cout << " 3. Выставлялись свои параметры размера окна" << std::endl;
		std::cin >> in;
		if (in == '1')
		{
			y_console = 146;
			x_console = 42;

			Bl_While = false;
		}
		else if (in == '2')
		{
			y_console = 110;
			x_console = 30;

			Bl_While = false;
		}
		else if (in == '3')
		{
			system("CLS");
			std::cout << " Зайдите в свойства консоли" << std::endl;
			std::cout << " Затем во вкладку: Расположение" << std::endl;
			std::cout << " Из раздела Размер окна перепишите данные:" << std::endl;

			std::cout << " Ширина окна:"; std::cin >> y_console;
			std::cout << "\n Высота окна:"; std::cin >> x_console;
			Bl_While = false;
		}
		else
		{
			Bl_While = false;
		}
	}
}

void Battle::Victory() // 2е функции на отрисовку картинки при победе или проигрыше 
{

	if (x_console == 42 && y_console == 146)
	{

	}
	else if (x_console == 30 && y_console == 110)
	{

	}
	else
	{

	}
}

void Battle::Loss() 
{
	if (x_console == 42 && y_console == 146)
	{

	}
	else if (x_console == 30 && y_console == 110)
	{

	}
	else
	{

	}
}

void Battle::battle(Character& player, Enemy& enemy)
{
	system("CLS");

	char UserInput = NULL;

	if (quantityEnemies == 0)
	{
		quantityEnemies = enemy.GetAllEnemy(enemy);
	}

	PlayerDie = false;
	EnemyDie = false;
	
	while (battleRan)
	{
		// Определение условий сражения
		if (!player._PlayerAttributes._SystemParam.Overview)
		{
			srand(time(NULL));
			int odds = 1 + rand() % 10;

			if (odds == 1)
			{
				srand(time(NULL));
				numberEnemy = 1 + rand() % quantityEnemies;
				enemy.Enemy_Attrbutes.enamyNumber = numberEnemy;
				////////////////////////////
				//номера генерируемых врагов в зависимости от текущего мира





				////////////////////////////
				if (numberEnemy > quantityEnemies)
				{
					start_fight = false;
					break;
				}
				else
				{
					enemy.CreateEnemy(enemy);

					FightNotOverview(player, enemy);
				}
			}
			else
			{
				break;
			}
		}
		else
		{
			srand(time(NULL));
			numberEnemy = 1 + rand() % quantityEnemies+6;
			enemy.Enemy_Attrbutes.enamyNumber = numberEnemy;

			////////////////////////////
				//номера генерируемых врагов в зависимости от текущего мира




			////////////////////////////

			if (numberEnemy > quantityEnemies)
			{
				start_fight = false;
				break;
			}
			else
			{
				enemy.CreateEnemy(enemy);

				FightOverview(player, enemy);
			}
		}

		// бой
		if (start_fight)
		{
			while (!PlayerDie || !EnemyDie || !runaway)
			{
				system("CLS");

				if (PlayerDie || EnemyDie)
				{ 
					Bl_Fight = false;
					start_fight = false;
					if (EnemyDie)
					{
						system("CLS");
						std::cout << " Вы стоите над телом поверженного врага" << std::endl;
						std::cout << " Осмотреть место битвы на наличие вещей почившего? или побыстрее уйти в надежде что никто вас не услышал?" << std::endl;
						std::cout << " Посмотреть убитого(E)   Уйти(G)" << std::endl;
						UserInput = input_registration.Click_tracking(UserInput);

						if (UserInput == 'E' || UserInput == 'e')
						{
							enemy.MobDrops(enemy, player);
						}
						else if (UserInput == 'G' || UserInput == 'g')
						{
							std::cout << " Решив сразу уйти вы вынесли из битвы только опыт" << std::endl;
						}
						std::cout << " вывод полученного дропа" << std::endl;
						system("pause");

						EnemyDie = false;

						break;
					}
					else break;
				}

				Step++;

				runaway = false;
				int odds = 1 + rand() % 4;
				if (odds == 1)
				{
					runaway = true;
				}

				if (detected_enemy && !detected_player)
				{
					critic_enemy = true;
					critic_player = false;
				}
				else if (detected_player && !detected_enemy)
				{
					critic_player = true;
					critic_enemy = false;
				}
				else if (detected_enemy && detected_player)
				{
					critic_player = false;
					critic_enemy = false;
				}

				Fight(player, enemy);
			}
		}

		if (!Bl_Fight) battleRan = false;

	}
	battleRan = true;
}

void Battle::FightOverview(Character& player, Enemy& enemy)
{
	char UserInput = NULL;

	int odds = 1 + rand() % 10;

	if (odds > 5 && odds <= 10)
	{
		detected_player = true;
		detected_enemy = false;
		enemy_aggression = true;
	}
	else if (odds > 0 && odds < 5)
	{
		detected_enemy = true;
		detected_player = false;
		enemy_aggression = false;
	}

	if (detected_enemy)
	{
		std::cout << " В свете факела показался некий силуэт" << std::endl;
		std::cout << std::endl;
		std::cout << " Вы можете проверить что это на свой страх и риск(F) или пройти мимо(G)  " << std::endl;
		UserInput = input_registration.Click_tracking(UserInput);
		if (UserInput == 'F' || UserInput == 'f')
		{
			std::cout << " Подойдя вы видите не различимое существо" << std::endl;
			std::cout << " Вы можете вступить с ним в бой ради наживы(F) или отступить незамеченным(G)" << std::endl;
			UserInput = input_registration.Click_tracking(UserInput);

			if (UserInput == 'F' || UserInput == 'f')
			{
				std::cout << " Существом оказался: " << std::endl;
				enemy.PrintEnemyStats();
				std::cout << std::endl;
				detected_player = false;
				detected_enemy = true;
				start_fight = true;

				std::cout << " Хотите начать сражение(F) или попробуете уйти(G)?" << std::endl;
				UserInput = input_registration.Click_tracking(UserInput);
				if (UserInput == 'F' || UserInput == 'f')
				{
					std::cout << " Вы начинаете сражение нанося удар из-за спины" << std::endl;
					enemy_aggression = true;
				}
				else if (UserInput == 'G' || UserInput == 'g')
				{
					odds = 1 + rand() % 15;

					if (odds > 10 && odds <= 15)
					{
						std::cout << " Вы попытались, но "<< enemy.Enemy_Attrbutes.enemyName <<" нападает на вас" << std::endl;
						enemy_aggression = true;
						detected_player = true;
					}
					else if (odds > 0 && odds <= 10)
					{
						std::cout << " Решив не рисковать вы отправились дальше " << std::endl;
						detected_enemy = false;
						detected_player = false;
						enemy_aggression = false;
						start_fight = false;
					}
				}
			}
			else if (UserInput == 'G' || UserInput == 'g')
			{
				
				if (first_enemy)
				{
					// добавить (Beep)
					std::cout << "(Beep) Ты трухло (Beep)" << std::endl;
					Sleep(2000);
					first_enemy = false;
				}
				
				std::cout << " Уходя вы облегченно выдыхаете...." << std::endl;
				srand(time(NULL));
				int odds = 1 + rand() % 10;

				if (odds > 5 && odds <= 10)
				{
					std::cout << " Но к сожалению вы ушли не достаточно далеко" << std::endl;
					std::cout << enemy.Enemy_Attrbutes.enemyName << " вас заметил, но вы этого не знаете..." << std::endl;
					detected_player = true;
					detected_enemy = false;
					enemy_aggression = true;
					start_fight = true;
				}
				else if (odds > 1 && odds <= 5)
				{
					std::cout << " Ведь вам удалось уйти не привлекая внимания" << std::endl;
					detected_enemy = false;
					detected_player = false;
					enemy_aggression = false;
					start_fight = false;
				}
			}
		}
		else if (UserInput == 'G' || UserInput == 'g')
		{
			std::cout << " Решив не рисковать вы отправились дальше " << std::endl;
			detected_enemy = false;
			detected_player = false;
			enemy_aggression = false;
			start_fight = false;
		}
		else
		{
			std::cout << " Совершив глупость, вы привлекли его внимание" << std::endl;
			detected_player = true;
			detected_enemy = true;
			enemy_aggression = true;
			start_fight = true;
		}
	}



	
	system("pause");

}

void Battle::FightNotOverview(Character& player, Enemy& enemy)
{
	int odds = 1 + rand() % 10;

	if (odds > 5 && odds <= 10)
	{
		detected_player = true;
		detected_enemy = false;
		enemy_aggression = true;
		start_fight = true;
	}
	else if (odds > 0 && odds < 5)
	{
		detected_enemy = true;
		detected_player = false;
		enemy_aggression = false;
		start_fight = true;
	}
	
	std::cout << std::endl;

	// +возможность убежать
}

void Battle::Fight(Character& player, Enemy& enemy)
{
	char UserInput = NULL;

	std::cout <<"\t\t" << " Ход: " << Step << std::endl;

	std::cout << " Имя: " << player._PlayerAttributes.name_Character << "\t\t\t" << enemy.Enemy_Attrbutes.enemyName;

	if (enemy.Enemy_Attrbutes.enamyElement >= 1 && enemy.Enemy_Attrbutes.enamyElement <= 4)
	{
		std::cout << " Стихия: " << enemy.Enemy_Attrbutes.enamyElement_txt << std::endl;
	}
	else if (enemy.Enemy_Attrbutes.enamyElement == 0)
	{
		std::cout << " Стихии " << enemy.Enemy_Attrbutes.enamyElement_txt << std::endl;
	}
	else if (enemy.Enemy_Attrbutes.enamyElement == 5)
	{
		std::cout << enemy.Enemy_Attrbutes.enamyElement_txt << std::endl;
	}

	std::cout << std::endl;
	std::cout << "* Характеристики *" << "\t\t" << "* Характеристики *" << std::endl;
	std::cout << std::endl;
	if (Step >= 2)
	{
		std::cout << " Здоровье: " << player._PlayerAttributes.P_Hp << " ( -" << Damage_Player << " )" << "\t\t" << " Здоровье: " << enemy.Enemy_Attrbutes.enamyHp << " ( -" << Damage_Enemy << " )" << std::endl;
	}
	else
	{
		std::cout << " Здоровье: " << player._PlayerAttributes.P_Hp << "\t\t\t" << " Здоровье: " << enemy.Enemy_Attrbutes.enamyHp << std::endl;
	}
	std::cout << " Мана: " << player._PlayerAttributes.P_Mana << "\t\t\t" << " Мана: " << enemy.Enemy_Attrbutes.enamyMp << std::endl;
	std::cout << " Атака: " << player._PlayerAttributes.P_attack << "\t\t\t" << " Атака: " << enemy.Enemy_Attrbutes.enamyAttack << std::endl;
	std::cout << " Уклонение: " << player._PlayerAttributes.P_avoid << "\t\t\t" << " Уклонение: " << enemy.Enemy_Attrbutes.enamyAvoid << std::endl;
	std::cout << " Выносливость: " << player._PlayerAttributes.P_stamina << "\t\t" << " потом добавим " << std::endl;
	std::cout << std::endl;

	if (PlayerDie || EnemyDie)
	{
		if (PlayerDie)
		{
			std::cout << " Вы проиграли" << std::endl;
		}
		else if (EnemyDie)
		{
			std::cout << " Вы победили " << std::endl;
		}
	}
	else
	{
		if (runaway)
		{
			std::cout << " Атака (A)      Меню персонажа (I)      Сбежать (R)      Меню(Q)" << std::endl;
		}
		else
		{
			std::cout << " Атака (A)      Меню персонажа (I)      Меню(Q)" << std::endl;
		}
		UserInput = input_registration.Click_tracking(UserInput);

		if (UserInput == 'I' || UserInput == 'i')
		{
			//Menu_Character(player);
			std::cout << " Нет функционала" << std::endl;
			system("pause");
		}
		else if (UserInput == 'A' || UserInput == 'a')
		{
			Attack(player, enemy);
		}
		else if (UserInput == 'R' || UserInput == 'r')
		{
			Escape(player);
		}
		else if (UserInput == 'Q' || UserInput == 'q')
		{

		}

		if (player._PlayerAttributes.P_Hp <= 0)
		{
			player._PlayerAttributes.P_Hp = 0;
			PlayerDie = true;
			Step = 0;
			Loss();
		}
		else if (enemy.Enemy_Attrbutes.enamyHp <= 0)
		{
			enemy.Enemy_Attrbutes.enamyHp = 0;
			EnemyDie = true;
			Step = 0;
			Victory();
		}
	}

	
	
}

void Battle::Attack(Character& player, Enemy& enemy)
{

	player._PlayerAttributes.P_stamina = player._PlayerAttributes.P_stamina - player._PlayerAttributes.P_Expenditure_Attack;

	if (player._PlayerAttributes.P_stamina <= 0)
	{
		if (player._PlayerAttributes.P_stamina <= 0 && player._PlayerAttributes.P_stamina > -10)
		{
			player._PlayerAttributes._PlayerSet.Weapon_Mod -= 0.1;
		}
		else if (player._PlayerAttributes.P_stamina <= -10 && player._PlayerAttributes.P_stamina < -15)
		{
			player._PlayerAttributes._PlayerSet.Weapon_Mod -= 0.2;
			player._PlayerAttributes._PlayerSet.Armor_Mod -= 0.1;
		}
		else if (player._PlayerAttributes.P_stamina <= -15 && player._PlayerAttributes.P_stamina < -20)
		{
			player._PlayerAttributes.P_attack -= 10;
			player._PlayerAttributes._PlayerSet.Weapon_Mod -= 0.2;
			player._PlayerAttributes._PlayerSet.Armor_Mod -= 0.2;
		}
		else if (player._PlayerAttributes.P_stamina <= -20 && player._PlayerAttributes.P_stamina < -25)
		{
			player._PlayerAttributes.P_attack -= 10;
			player._PlayerAttributes.P_armor -= 10;
			player._PlayerAttributes._PlayerSet.Weapon_Mod -= 0.2;
			player._PlayerAttributes._PlayerSet.Armor_Mod -= 0.2;
		}
		else if (player._PlayerAttributes.P_stamina <= -25 && player._PlayerAttributes.P_stamina < -30)
		{
			player._PlayerAttributes.P_attack -= 15;
			player._PlayerAttributes.P_armor -= 15;
			player._PlayerAttributes._PlayerSet.Weapon_Mod -= 0.3;
			player._PlayerAttributes._PlayerSet.Armor_Mod -= 0.3;
		}
		else
		{
			player._PlayerAttributes.P_stamina = -30;
			player._PlayerAttributes.P_Hp = player._PlayerAttributes.P_Hp - Step;
		}
	}

	if (critic_enemy) // удар со спины (+ к урону: ???)
	{
		if (player._PlayerAttributes._PlayerSet.bl_Weapon_mod)
		{
			Damage_Enemy = (player._PlayerAttributes.P_attack - (enemy.Enemy_Attrbutes.enamyArmor / 3)) * player._PlayerAttributes._PlayerSet.Weapon_Mod;
		}
		else
		{
			Damage_Enemy = (player._PlayerAttributes.P_attack - (enemy.Enemy_Attrbutes.enamyArmor / 3));
		}
		Damage_Enemy *= 2;
		enemy.Enemy_Attrbutes.enamyHp = enemy.Enemy_Attrbutes.enamyHp - Damage_Enemy;
		detected_player = true;
	}
	else if (critic_player)
	{
		if (player._PlayerAttributes._PlayerSet.bl_Weapon_mod)
		{
			Damage_Player = enemy.Enemy_Attrbutes.enamyAttack - ((player._PlayerAttributes.P_armor / 3) * player._PlayerAttributes._PlayerSet.Armor_Mod);
		}
		else
		{
			Damage_Player = enemy.Enemy_Attrbutes.enamyAttack - (player._PlayerAttributes.P_armor / 3);
		}
		Damage_Player *= 2;
		player._PlayerAttributes.P_Hp = player._PlayerAttributes.P_Hp - Damage_Player;
		detected_enemy = true;
	}
	else // стандартная боевка
	{
		if (player._PlayerAttributes._PlayerSet.bl_Weapon_mod)
		{
			Damage_Enemy = (player._PlayerAttributes.P_attack - (enemy.Enemy_Attrbutes.enamyArmor / 3)) * player._PlayerAttributes._PlayerSet.Weapon_Mod;
		}
		else
		{
			Damage_Enemy = (player._PlayerAttributes.P_attack - (enemy.Enemy_Attrbutes.enamyArmor / 3));
		}
		enemy.Enemy_Attrbutes.enamyHp = enemy.Enemy_Attrbutes.enamyHp - Damage_Enemy;
		if (player._PlayerAttributes._PlayerSet.bl_Armor_mod)
		{
			Damage_Player = enemy.Enemy_Attrbutes.enamyAttack - ((player._PlayerAttributes.P_armor / 3) * player._PlayerAttributes._PlayerSet.Armor_Mod);
		}
		else
		{
			Damage_Player = enemy.Enemy_Attrbutes.enamyAttack - (player._PlayerAttributes.P_armor / 3);
		}
		player._PlayerAttributes.P_Hp = player._PlayerAttributes.P_Hp - Damage_Player;
	}
}

void Battle::Escape(Character& player)
{
	// не работает
	if (player._PlayerAttributes.name_Class == "Воин")
	{
		player._PlayerAttributes.P_stamina = player._PlayerAttributes.P_stamina - player._PlayerAttributes.P_Expenditure_Escape;
		// + шанс получить по жопе когда убегаешь
	}
	else if (player._PlayerAttributes.name_Class == "Маг")
	{
		player._PlayerAttributes.P_stamina = player._PlayerAttributes.P_stamina - player._PlayerAttributes.P_Expenditure_Escape;

	}
	else if (player._PlayerAttributes.name_Class == "Охотник")
	{
		player._PlayerAttributes.P_stamina = player._PlayerAttributes.P_stamina - player._PlayerAttributes.P_Expenditure_Escape;

	}
}



