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
		std::cout << " ��� ���������� ������ ��������� ������� ������ �������" << std::endl;
		std::cout << " �������� ��� ������� �� ��������������( 1 ��� 2 ): " << std::endl;
		std::cout << " 1. ������� ���������� �� ���� �����" << std::endl;
		std::cout << " 2. ������� ������� � ��������� ����" << std::endl;
		std::cout << " 3. ������������ ���� ��������� ������� ����" << std::endl;
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
			std::cout << " ������� � �������� �������" << std::endl;
			std::cout << " ����� �� �������: ������������" << std::endl;
			std::cout << " �� ������� ������ ���� ���������� ������:" << std::endl;

			std::cout << " ������ ����:"; std::cin >> y_console;
			std::cout << "\n ������ ����:"; std::cin >> x_console;
			Bl_While = false;
		}
		else
		{
			Bl_While = false;
		}
	}
}

void Battle::Victory() // 2� ������� �� ��������� �������� ��� ������ ��� ��������� 
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
		// ����������� ������� ��������
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
				//������ ������������ ������ � ����������� �� �������� ����





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
				//������ ������������ ������ � ����������� �� �������� ����




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

		// ���
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
						std::cout << " �� ������ ��� ����� ������������ �����" << std::endl;
						std::cout << " ��������� ����� ����� �� ������� ����� ���������? ��� ��������� ���� � ������� ��� ����� ��� �� �������?" << std::endl;
						std::cout << " ���������� �������(E)   ����(G)" << std::endl;
						UserInput = input_registration.Click_tracking(UserInput);

						if (UserInput == 'E' || UserInput == 'e')
						{
							enemy.MobDrops(enemy, player);
						}
						else if (UserInput == 'G' || UserInput == 'g')
						{
							std::cout << " ����� ����� ���� �� ������� �� ����� ������ ����" << std::endl;
						}
						std::cout << " ����� ����������� �����" << std::endl;
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
		std::cout << " � ����� ������ ��������� ����� ������" << std::endl;
		std::cout << std::endl;
		std::cout << " �� ������ ��������� ��� ��� �� ���� ����� � ����(F) ��� ������ ����(G)  " << std::endl;
		UserInput = input_registration.Click_tracking(UserInput);
		if (UserInput == 'F' || UserInput == 'f')
		{
			std::cout << " ������� �� ������ �� ���������� ��������" << std::endl;
			std::cout << " �� ������ �������� � ��� � ��� ���� ������(F) ��� ��������� ������������(G)" << std::endl;
			UserInput = input_registration.Click_tracking(UserInput);

			if (UserInput == 'F' || UserInput == 'f')
			{
				std::cout << " ��������� ��������: " << std::endl;
				enemy.PrintEnemyStats();
				std::cout << std::endl;
				detected_player = false;
				detected_enemy = true;
				start_fight = true;

				std::cout << " ������ ������ ��������(F) ��� ���������� ����(G)?" << std::endl;
				UserInput = input_registration.Click_tracking(UserInput);
				if (UserInput == 'F' || UserInput == 'f')
				{
					std::cout << " �� ��������� �������� ������ ���� ��-�� �����" << std::endl;
					enemy_aggression = true;
				}
				else if (UserInput == 'G' || UserInput == 'g')
				{
					odds = 1 + rand() % 15;

					if (odds > 10 && odds <= 15)
					{
						std::cout << " �� ����������, �� "<< enemy.Enemy_Attrbutes.enemyName <<" �������� �� ���" << std::endl;
						enemy_aggression = true;
						detected_player = true;
					}
					else if (odds > 0 && odds <= 10)
					{
						std::cout << " ����� �� ��������� �� ����������� ������ " << std::endl;
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
					// �������� (Beep)
					std::cout << "(Beep) �� ������ (Beep)" << std::endl;
					Sleep(2000);
					first_enemy = false;
				}
				
				std::cout << " ����� �� ���������� ���������...." << std::endl;
				srand(time(NULL));
				int odds = 1 + rand() % 10;

				if (odds > 5 && odds <= 10)
				{
					std::cout << " �� � ��������� �� ���� �� ���������� ������" << std::endl;
					std::cout << enemy.Enemy_Attrbutes.enemyName << " ��� �������, �� �� ����� �� ������..." << std::endl;
					detected_player = true;
					detected_enemy = false;
					enemy_aggression = true;
					start_fight = true;
				}
				else if (odds > 1 && odds <= 5)
				{
					std::cout << " ���� ��� ������� ���� �� ��������� ��������" << std::endl;
					detected_enemy = false;
					detected_player = false;
					enemy_aggression = false;
					start_fight = false;
				}
			}
		}
		else if (UserInput == 'G' || UserInput == 'g')
		{
			std::cout << " ����� �� ��������� �� ����������� ������ " << std::endl;
			detected_enemy = false;
			detected_player = false;
			enemy_aggression = false;
			start_fight = false;
		}
		else
		{
			std::cout << " �������� ��������, �� ��������� ��� ��������" << std::endl;
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

	// +����������� �������
}

void Battle::Fight(Character& player, Enemy& enemy)
{
	char UserInput = NULL;

	std::cout <<"\t\t" << " ���: " << Step << std::endl;

	std::cout << " ���: " << player._PlayerAttributes.name_Character << "\t\t\t" << enemy.Enemy_Attrbutes.enemyName;

	if (enemy.Enemy_Attrbutes.enamyElement >= 1 && enemy.Enemy_Attrbutes.enamyElement <= 4)
	{
		std::cout << " ������: " << enemy.Enemy_Attrbutes.enamyElement_txt << std::endl;
	}
	else if (enemy.Enemy_Attrbutes.enamyElement == 0)
	{
		std::cout << " ������ " << enemy.Enemy_Attrbutes.enamyElement_txt << std::endl;
	}
	else if (enemy.Enemy_Attrbutes.enamyElement == 5)
	{
		std::cout << enemy.Enemy_Attrbutes.enamyElement_txt << std::endl;
	}

	std::cout << std::endl;
	std::cout << "* �������������� *" << "\t\t" << "* �������������� *" << std::endl;
	std::cout << std::endl;
	if (Step >= 2)
	{
		std::cout << " ��������: " << player._PlayerAttributes.P_Hp << " ( -" << Damage_Player << " )" << "\t\t" << " ��������: " << enemy.Enemy_Attrbutes.enamyHp << " ( -" << Damage_Enemy << " )" << std::endl;
	}
	else
	{
		std::cout << " ��������: " << player._PlayerAttributes.P_Hp << "\t\t\t" << " ��������: " << enemy.Enemy_Attrbutes.enamyHp << std::endl;
	}
	std::cout << " ����: " << player._PlayerAttributes.P_Mana << "\t\t\t" << " ����: " << enemy.Enemy_Attrbutes.enamyMp << std::endl;
	std::cout << " �����: " << player._PlayerAttributes.P_attack << "\t\t\t" << " �����: " << enemy.Enemy_Attrbutes.enamyAttack << std::endl;
	std::cout << " ���������: " << player._PlayerAttributes.P_avoid << "\t\t\t" << " ���������: " << enemy.Enemy_Attrbutes.enamyAvoid << std::endl;
	std::cout << " ������������: " << player._PlayerAttributes.P_stamina << "\t\t" << " ����� ������� " << std::endl;
	std::cout << std::endl;

	if (PlayerDie || EnemyDie)
	{
		if (PlayerDie)
		{
			std::cout << " �� ���������" << std::endl;
		}
		else if (EnemyDie)
		{
			std::cout << " �� �������� " << std::endl;
		}
	}
	else
	{
		if (runaway)
		{
			std::cout << " ����� (A)      ���� ��������� (I)      ������� (R)      ����(Q)" << std::endl;
		}
		else
		{
			std::cout << " ����� (A)      ���� ��������� (I)      ����(Q)" << std::endl;
		}
		UserInput = input_registration.Click_tracking(UserInput);

		if (UserInput == 'I' || UserInput == 'i')
		{
			//Menu_Character(player);
			std::cout << " ��� �����������" << std::endl;
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

	if (critic_enemy) // ���� �� ����� (+ � �����: ???)
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
	else // ����������� ������
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
	// �� ��������
	if (player._PlayerAttributes.name_Class == "����")
	{
		player._PlayerAttributes.P_stamina = player._PlayerAttributes.P_stamina - player._PlayerAttributes.P_Expenditure_Escape;
		// + ���� �������� �� ���� ����� ��������
	}
	else if (player._PlayerAttributes.name_Class == "���")
	{
		player._PlayerAttributes.P_stamina = player._PlayerAttributes.P_stamina - player._PlayerAttributes.P_Expenditure_Escape;

	}
	else if (player._PlayerAttributes.name_Class == "�������")
	{
		player._PlayerAttributes.P_stamina = player._PlayerAttributes.P_stamina - player._PlayerAttributes.P_Expenditure_Escape;

	}
}



