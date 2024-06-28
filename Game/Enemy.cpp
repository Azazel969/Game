#include "Enemy.h"
#include <iostream>
#include <Windows.h>
#include "Battle.h"

Enemy::Enemy()
{
}

Enemy::Enemy(const EnemyAttribute& Enemy_Attrbutes)
	:
	Enemy_Attrbutes(Enemy_Attrbutes)
{
}

void Enemy::CreateEnemy(Enemy& enemy)
{
	
	int NumberEnemy = 0;
	
	if (test)
	{
		NumberEnemy = 1;
	}
	else
	{
		NumberEnemy = enemy.Enemy_Attrbutes.enamyNumber;
		test = false;
	}
	
	int element = 0;
	int i = 1;

	do
	{
		switch (NumberEnemy)
		{
		case 1:
		{
			if (!enemy.test)
			{
				if (enemy.bestiaryRan)
				{
					if (element == 0) element = 1;
				}
				else
				{
					srand(time(NULL));
					element = 1 + rand() % 4;
				}

				EnemyAttribute elementalAttributes = {};
				elementalAttributes.enamyLevel = 3;
				elementalAttributes.enamyHp = 300;
				elementalAttributes.enamyMp = 361;
				elementalAttributes.enamyArmor = 30;
				elementalAttributes.enamyAvoid = 50;
				elementalAttributes.enamyNumber = NumberEnemy;

				switch (element)
				{
				case 1:
					elementalAttributes.enamyElement = enemy.Enemy_Attrbutes.Fire;
					elementalAttributes.enamyElement_txt = " Огонь";
					break;

				case 2:
					elementalAttributes.enamyElement = enemy.Enemy_Attrbutes.Water;
					elementalAttributes.enamyElement_txt = " Вода";
					break;

				case 3:
					elementalAttributes.enamyElement = enemy.Enemy_Attrbutes.Air;
					elementalAttributes.enamyElement_txt = " Воздух";
					break;

				case 4:
					elementalAttributes.enamyElement = enemy.Enemy_Attrbutes.Earth;
					elementalAttributes.enamyElement_txt = " Земля";
					break;
				}

				if (enemy.bestiaryRan) element++;

				elementalAttributes.enemyName = " Элементаль";

				elementalAttributes.Enemy_Drop.Quantity_drop_gold = 1;
				elementalAttributes.Enemy_Drop.Quantity_drop_xp = 1;
				elementalAttributes.Enemy_Drop.Quantity_drop_xp_skill = 1;
				elementalAttributes.Enemy_Drop.Quantity_drop_xp_ability = 1;

				Enemy Elemental(elementalAttributes);

				if (enemy.bestiaryRan) Elemental.PrintEnemyStats();

				if (!enemy.bestiaryRan) enemy = Elemental;
				else std::cout << std::endl;
			}
			else enemy.allEnemy += 4;
		}
			break;
		case 2:
		{
			if (!enemy.test)
			{
				EnemyAttribute arachnidAttributes = {};
				arachnidAttributes.enamyLevel = 1;
				arachnidAttributes.enamyHp = 90;
				arachnidAttributes.enamyMp = 0;
				arachnidAttributes.enamyArmor = 70;
				arachnidAttributes.enamyAvoid = 35;
				arachnidAttributes.enemyName = " Арахнид";
				arachnidAttributes.enamyElement = enemy.Enemy_Attrbutes.Not;
				arachnidAttributes.enamyElement_txt = "не имеет";
				arachnidAttributes.enamyNumber = NumberEnemy;

				arachnidAttributes.Enemy_Drop.Quantity_drop_gold = 1;
				arachnidAttributes.Enemy_Drop.Quantity_drop_xp = 1;
				arachnidAttributes.Enemy_Drop.Quantity_drop_xp_skill = 1;
				arachnidAttributes.Enemy_Drop.Quantity_drop_xp_ability = 1;

				Enemy Arachnid(arachnidAttributes);

				if (enemy.bestiaryRan) Arachnid.PrintEnemyStats();

				if (!enemy.bestiaryRan) enemy = Arachnid;
				else std::cout << std::endl;
			}
			else enemy.allEnemy++;
		}
			break;
		case 3:
		{
			if (!enemy.test)
			{
				EnemyAttribute goblin_warriorAttributes = {};
				goblin_warriorAttributes.enamyLevel = 1;
				goblin_warriorAttributes.enamyHp = 140;
				goblin_warriorAttributes.enamyMp = 10;
				goblin_warriorAttributes.enamyArmor = 90;
				goblin_warriorAttributes.enamyAvoid = 25;
				goblin_warriorAttributes.enemyName = " Гоблин-воин";
				goblin_warriorAttributes.enamyElement = enemy.Enemy_Attrbutes.Not;
				goblin_warriorAttributes.enamyElement_txt = "не имеет";
				goblin_warriorAttributes.enamyNumber = NumberEnemy;

				goblin_warriorAttributes.Enemy_Drop.Quantity_drop_gold = 1;
				goblin_warriorAttributes.Enemy_Drop.Quantity_drop_xp = 1;
				goblin_warriorAttributes.Enemy_Drop.Quantity_drop_xp_skill = 1;
				goblin_warriorAttributes.Enemy_Drop.Quantity_drop_xp_ability = 1;

				Enemy Goblin_Warrior(goblin_warriorAttributes);

				if (enemy.bestiaryRan) Goblin_Warrior.PrintEnemyStats();

				if (!enemy.bestiaryRan) enemy = Goblin_Warrior;
				else std::cout << std::endl;
			}
			else enemy.allEnemy++;
		}
			break;
		case 4:
		{
			if (!enemy.test)
			{
				EnemyAttribute goblin_shamanAttributes = {};
				goblin_shamanAttributes.enamyLevel = 2;
				goblin_shamanAttributes.enamyHp = 140;
				goblin_shamanAttributes.enamyMp = 220;
				goblin_shamanAttributes.enamyArmor = 20;
				goblin_shamanAttributes.enamyAvoid = 20;
				goblin_shamanAttributes.enemyName = " Гоблин-шаман";
				goblin_shamanAttributes.enamyElement = enemy.Enemy_Attrbutes.All;
				goblin_shamanAttributes.enamyElement_txt = " Имеет благословление Духа Гайи";
				goblin_shamanAttributes.enamyNumber = NumberEnemy;

				goblin_shamanAttributes.Enemy_Drop.Quantity_drop_gold = 1;
				goblin_shamanAttributes.Enemy_Drop.Quantity_drop_xp = 1;
				goblin_shamanAttributes.Enemy_Drop.Quantity_drop_xp_skill = 1;
				goblin_shamanAttributes.Enemy_Drop.Quantity_drop_xp_ability = 1;

				Enemy Goblin_Shaman(goblin_shamanAttributes);

				if (enemy.bestiaryRan) Goblin_Shaman.PrintEnemyStats();

				if (!enemy.bestiaryRan) enemy = Goblin_Shaman;
				else std::cout << std::endl;
			}
			else enemy.allEnemy++;
		}
			break;
		case 5:
		{
			if (!enemy.test)
			{
				EnemyAttribute bansheeAttributes = {};
				bansheeAttributes.enamyLevel = 2;
				bansheeAttributes.enamyHp = 210;
				bansheeAttributes.enamyMp = 140;
				bansheeAttributes.enamyArmor = 20;
				bansheeAttributes.enamyAvoid = 40;
				bansheeAttributes.enemyName = " Банши";
				bansheeAttributes.enamyElement = enemy.Enemy_Attrbutes.Air;
				bansheeAttributes.enamyElement_txt = " Воздух";
				bansheeAttributes.enamyNumber = NumberEnemy;

				bansheeAttributes.Enemy_Drop.Quantity_drop_gold = 1;
				bansheeAttributes.Enemy_Drop.Quantity_drop_xp = 1;
				bansheeAttributes.Enemy_Drop.Quantity_drop_xp_skill = 1;
				bansheeAttributes.Enemy_Drop.Quantity_drop_xp_ability = 1;

				Enemy Banshee(bansheeAttributes);

				if (enemy.bestiaryRan) Banshee.PrintEnemyStats();

				if (!enemy.bestiaryRan) enemy = Banshee;
				else std::cout << std::endl;
			}
			else enemy.allEnemy++;
		}
			break;
		case 6:
		{
			if (!enemy.test)
			{
				EnemyAttribute draugrAttributes = {};
				draugrAttributes.enamyLevel = 2;
				draugrAttributes.enamyHp = 240;
				draugrAttributes.enamyMp = 40;
				draugrAttributes.enamyArmor = 80;
				draugrAttributes.enamyAvoid = 20;
				draugrAttributes.enemyName = " Драугр";
				draugrAttributes.enamyElement = enemy.Enemy_Attrbutes.Not;
				draugrAttributes.enamyElement_txt = "не имеет";
				draugrAttributes.enamyNumber = NumberEnemy;

				draugrAttributes.Enemy_Drop.Quantity_drop_gold = 1;
				draugrAttributes.Enemy_Drop.Quantity_drop_xp = 1;
				draugrAttributes.Enemy_Drop.Quantity_drop_xp_skill = 1;
				draugrAttributes.Enemy_Drop.Quantity_drop_xp_ability = 1;

				Enemy Draugr(draugrAttributes);

				if (enemy.bestiaryRan) Draugr.PrintEnemyStats();

				if (!enemy.bestiaryRan) enemy = Draugr;
				else std::cout << std::endl;
			}
			else enemy.allEnemy++;
		}
			break;
		case 7:
		{
			if (!enemy.test)
			{
				EnemyAttribute slimeAttributes = {};
				slimeAttributes.enamyLevel = 1;
				slimeAttributes.enamyHp = 80;
				slimeAttributes.enamyMp = 400;
				slimeAttributes.enamyArmor = 10;
				slimeAttributes.enamyAvoid = 10;
				slimeAttributes.enemyName = " Слизь";
				slimeAttributes.enamyElement = enemy.Enemy_Attrbutes.Water;
				slimeAttributes.enamyElement_txt = " Вода";
				slimeAttributes.enamyNumber = NumberEnemy;

				slimeAttributes.Enemy_Drop.Quantity_drop_gold = 1;
				slimeAttributes.Enemy_Drop.Quantity_drop_xp = 1;
				slimeAttributes.Enemy_Drop.Quantity_drop_xp_skill = 1;
				slimeAttributes.Enemy_Drop.Quantity_drop_xp_ability = 1;
				
				Enemy Slime(slimeAttributes);

				if (enemy.bestiaryRan) Slime.PrintEnemyStats();

				if (!enemy.bestiaryRan) enemy = Slime;
				else std::cout << std::endl;
			}
			else enemy.allEnemy++;
		}
			break;
		case 8:
		{
			if (!enemy.test)
			{
				EnemyAttribute satanistAttributes = {};
				satanistAttributes.enamyLevel = 3;
				satanistAttributes.enamyHp = 200;
				satanistAttributes.enamyMp = 300;
				satanistAttributes.enamyArmor = 30;
				satanistAttributes.enamyAvoid = 30;
				satanistAttributes.enemyName = " Сатанист";
				satanistAttributes.enamyElement = enemy.Enemy_Attrbutes.Fire;
				satanistAttributes.enamyElement_txt = " Огонь";
				satanistAttributes.enamyNumber = NumberEnemy;

				satanistAttributes.Enemy_Drop.Quantity_drop_gold = 1;
				satanistAttributes.Enemy_Drop.Quantity_drop_xp = 1;
				satanistAttributes.Enemy_Drop.Quantity_drop_xp_skill = 1;
				satanistAttributes.Enemy_Drop.Quantity_drop_xp_ability = 1;

				Enemy Satanist(satanistAttributes);

				if (enemy.bestiaryRan) Satanist.PrintEnemyStats();

				if (!enemy.bestiaryRan) enemy = Satanist;
				else std::cout << std::endl;
			}
			else enemy.allEnemy++;

		}
			break;
		case 9:
		{
			if (!enemy.test)
			{
				EnemyAttribute cave_bearAttributes = {};
				cave_bearAttributes.enamyLevel = 2;
				cave_bearAttributes.enamyHp = 200;
				cave_bearAttributes.enamyMp = 300;
				cave_bearAttributes.enamyArmor = 30;
				cave_bearAttributes.enamyAvoid = 30;
				cave_bearAttributes.enemyName = " Пещерный медведь";
				cave_bearAttributes.enamyElement = enemy.Enemy_Attrbutes.Earth;
				cave_bearAttributes.enamyElement_txt = " Земля";
				cave_bearAttributes.enamyNumber = NumberEnemy;

				cave_bearAttributes.Enemy_Drop.Quantity_drop_gold = 1;
				cave_bearAttributes.Enemy_Drop.Quantity_drop_xp = 1;
				cave_bearAttributes.Enemy_Drop.Quantity_drop_xp_skill = 1;
				cave_bearAttributes.Enemy_Drop.Quantity_drop_xp_ability = 1;

				Enemy Cave_bear(cave_bearAttributes);

				if (enemy.bestiaryRan) Cave_bear.PrintEnemyStats();

				if (enemy.bestiaryRan) enemy = Cave_bear;
				else std::cout << std::endl;
			}
			else enemy.allEnemy++;
		}
			break;
		case 10:
		{
			if (!enemy.test)
			{
				EnemyAttribute spirit_GaiaAttributes = {}; // бос
				spirit_GaiaAttributes.enamyLevel = 4;
				spirit_GaiaAttributes.enamyHp = 500;
				spirit_GaiaAttributes.enamyMp = 700;
				spirit_GaiaAttributes.enamyArmor = 90;
				spirit_GaiaAttributes.enamyAvoid = 60;
				spirit_GaiaAttributes.enemyName = " Дух Гайи";
				spirit_GaiaAttributes.enamyElement = enemy.Enemy_Attrbutes.All;
				spirit_GaiaAttributes.enamyElement_txt = " Повелевает стихиями 4х элементов";
				spirit_GaiaAttributes.enamyNumber = NumberEnemy;

				spirit_GaiaAttributes.Enemy_Drop.Quantity_drop_gold = 1;
				spirit_GaiaAttributes.Enemy_Drop.Quantity_drop_xp = 1;
				spirit_GaiaAttributes.Enemy_Drop.Quantity_drop_xp_skill = 1;
				spirit_GaiaAttributes.Enemy_Drop.Quantity_drop_xp_ability = 1;

				Enemy Spirit_Gaia(spirit_GaiaAttributes);

				if (enemy.bestiaryRan) Spirit_Gaia.PrintEnemyStats();

				if (!enemy.bestiaryRan) enemy = Spirit_Gaia;
				else std::cout << std::endl;
			}
			else enemy.allEnemy++;
		}
			break;
		case 11:
		{
			if (!enemy.test)
			{
				EnemyAttribute lichAttributes = {}; // бос
				lichAttributes.enamyLevel = 4;
				lichAttributes.enamyHp = 400;
				lichAttributes.enamyMp = 850;
				lichAttributes.enamyArmor = 40;
				lichAttributes.enamyAvoid = 40;
				lichAttributes.enemyName = " Лич";
				lichAttributes.enamyElement = enemy.Enemy_Attrbutes.All;
				lichAttributes.enamyElement_txt = " Овладел всей известной магией";
				lichAttributes.enamyNumber = NumberEnemy;

				lichAttributes.Enemy_Drop.Quantity_drop_gold = 1;
				lichAttributes.Enemy_Drop.Quantity_drop_xp = 1;
				lichAttributes.Enemy_Drop.Quantity_drop_xp_skill = 1;
				lichAttributes.Enemy_Drop.Quantity_drop_xp_ability = 1;

				Enemy Lich(lichAttributes);

				if (enemy.bestiaryRan) Lich.PrintEnemyStats();

				if (!enemy.bestiaryRan) enemy = Lich;
				else std::cout << std::endl;
			}
			else enemy.allEnemy++;
				
		}
			break;
		case 12:
		{
			if (!enemy.test)
			{
				EnemyAttribute chthonic_golemAttributes = {}; // бос
				chthonic_golemAttributes.enamyLevel = 4;
				chthonic_golemAttributes.enamyHp = 400;
				chthonic_golemAttributes.enamyMp = 850;
				chthonic_golemAttributes.enamyArmor = 40;
				chthonic_golemAttributes.enamyAvoid = 40;
				chthonic_golemAttributes.enemyName = " Хтонический голем";
				chthonic_golemAttributes.enamyElement = enemy.Enemy_Attrbutes.Fire;
				chthonic_golemAttributes.enamyElement_txt = " Огонь";
				chthonic_golemAttributes.enamyNumber = NumberEnemy;

				chthonic_golemAttributes.Enemy_Drop.Quantity_drop_gold = 1;
				chthonic_golemAttributes.Enemy_Drop.Quantity_drop_xp = 1;
				chthonic_golemAttributes.Enemy_Drop.Quantity_drop_xp_skill = 1;
				chthonic_golemAttributes.Enemy_Drop.Quantity_drop_xp_ability = 1;

				Enemy Chthonic_golem(chthonic_golemAttributes);

				if (enemy.bestiaryRan) Chthonic_golem.PrintEnemyStats();

				if (!enemy.bestiaryRan) enemy = Chthonic_golem;
				else std::cout << std::endl;
			}
			else enemy.allEnemy++;
		}
			break;
		case 13:
		{
			if (!enemy.test)
			{
				EnemyAttribute goblin_kingAttributes = {}; // бос
				goblin_kingAttributes.enamyLevel = 4;
				goblin_kingAttributes.enamyHp = 400;
				goblin_kingAttributes.enamyMp = 850;
				goblin_kingAttributes.enamyArmor = 40;
				goblin_kingAttributes.enamyAvoid = 40;
				goblin_kingAttributes.enemyName = " Король гоблинов";
				goblin_kingAttributes.enamyElement = enemy.Enemy_Attrbutes.All;
				goblin_kingAttributes.enamyElement_txt = " Имеет благословление Духа Гайи";
				goblin_kingAttributes.enamyNumber = NumberEnemy;

				goblin_kingAttributes.Enemy_Drop.Quantity_drop_gold = 1;
				goblin_kingAttributes.Enemy_Drop.Quantity_drop_xp = 1;
				goblin_kingAttributes.Enemy_Drop.Quantity_drop_xp_skill = 1;
				goblin_kingAttributes.Enemy_Drop.Quantity_drop_xp_ability = 1;

				Enemy Goblin_king(goblin_kingAttributes);

				if (enemy.bestiaryRan) Goblin_king.PrintEnemyStats();

				if (!enemy.bestiaryRan) enemy = Goblin_king;
				else std::cout << std::endl;
			}
			else enemy.allEnemy++;
		}
			break;
		default:
		{
			if (!enemy.test)
			{
				EnemyAttribute defAttributes = {}; // final бос 
				defAttributes.enamyLevel = 1;
				defAttributes.enamyHp = 1;
				defAttributes.enamyMp = 1;
				defAttributes.enamyArmor = 1;
				defAttributes.enamyAvoid = 1;
				defAttributes.enemyName = " Default";
				defAttributes.enamyElement = enemy.Enemy_Attrbutes.Not;
				defAttributes.enamyElement_txt = " ???";
				defAttributes.enamyNumber = NumberEnemy;
				Enemy Default(defAttributes);

				enemy = Default;
			}
			else
			{
				NumberEnemy = 0;
				enemy.test = false;
			}
		}
			break;
		}

		if (enemy.bestiaryRan)
		{
			if (i == 2)// вывод на экран по два монстра
			{
				system("pause");
				i = 0;
			}
			i++;

			if (NumberEnemy == 1)//вывод элементалей
			{
				if (element == 5)
				{
					NumberEnemy++;
				}
			}
			else if (NumberEnemy > 1 && NumberEnemy < 14)//вывод всех остальных монстров
			{
				NumberEnemy++;
			}
			else if (NumberEnemy == 14)
			{
				enemy.bestiaryRan = false;
				element = 0;
			}
		}
		if (enemy.test) NumberEnemy++;

	} while (enemy.bestiaryRan || enemy.test);

	
	// старый способ адресации

	/*
	do
	{
		if (numberEnemy == 1)
		{
			if (enemy.bestiaryRan)
			{
				if (element == 0)
				{
					element = 1;
				}
			}
			else
			{
				srand(time(NULL));
				element = 1 + rand() % 4;
			}

			EnemyAttribute elementalAttributes = {};
			elementalAttributes.enamyLevel = 3;
			elementalAttributes.enamyHp = 300;
			elementalAttributes.enamyMp = 361;
			elementalAttributes.enamyArmor = 30;
			elementalAttributes.enamyAvoid = 50;
			elementalAttributes.enamyNumber = numberEnemy;

			if (element == 1)
			{
				elementalAttributes.enamyElement = enemy.Enemy_Attrbutes.Fire;
				elementalAttributes.enamyElement_txt = " Огонь";
			}
			else if (element == 2)
			{
				elementalAttributes.enamyElement = enemy.Enemy_Attrbutes.Water;
				elementalAttributes.enamyElement_txt = " Вода";
			}
			else if (element == 3)
			{
				elementalAttributes.enamyElement = enemy.Enemy_Attrbutes.Air;
				elementalAttributes.enamyElement_txt = " Воздух";
			}
			else if (element == 4)
			{
				elementalAttributes.enamyElement = enemy.Enemy_Attrbutes.Earth;
				elementalAttributes.enamyElement_txt = " Земля";
			}

			if (enemy.bestiaryRan)
			{
				element++;
			}

			elementalAttributes.enemyName = " Элементаль";
			Enemy Elemental(elementalAttributes);


			if (enemy.bestiaryRan)
			{
				Elemental.PrintEnemyStats();
			}

			if (!enemy.bestiaryRan)
			{
				enemy = Elemental;
			}
			else
			{
				std::cout << std::endl;
			}

		}
		else if (numberEnemy == 2)
		{
			EnemyAttribute arachnidAttributes = {};
			arachnidAttributes.enamyLevel = 1;
			arachnidAttributes.enamyHp = 90;
			arachnidAttributes.enamyMp = 0;
			arachnidAttributes.enamyArmor = 70;
			arachnidAttributes.enamyAvoid = 35;
			arachnidAttributes.enemyName = " Арахнид";
			arachnidAttributes.enamyElement = enemy.Enemy_Attrbutes.Not;
			arachnidAttributes.enamyElement_txt = "не имеет";
			arachnidAttributes.enamyNumber = numberEnemy;
			Enemy Arachnid(arachnidAttributes);

			if (enemy.bestiaryRan)
			{
				Arachnid.PrintEnemyStats();
			}

			if (!enemy.bestiaryRan)
			{
				enemy = Arachnid;
			}
			else
			{
				std::cout << std::endl;
			}
		}
		else if (numberEnemy == 3)
		{
			EnemyAttribute goblin_warriorAttributes = {};
			goblin_warriorAttributes.enamyLevel = 1;
			goblin_warriorAttributes.enamyHp = 140;
			goblin_warriorAttributes.enamyMp = 10;
			goblin_warriorAttributes.enamyArmor = 90;
			goblin_warriorAttributes.enamyAvoid = 25;
			goblin_warriorAttributes.enemyName = " Гоблин-воин";
			goblin_warriorAttributes.enamyElement = enemy.Enemy_Attrbutes.Not;
			goblin_warriorAttributes.enamyElement_txt = "не имеет";
			goblin_warriorAttributes.enamyNumber = numberEnemy;
			Enemy Goblin_Warrior(goblin_warriorAttributes);

			if (enemy.bestiaryRan)
			{
				Goblin_Warrior.PrintEnemyStats();
			}

			if (!enemy.bestiaryRan)
			{
				enemy = Goblin_Warrior;
			}
			else
			{
				std::cout << std::endl;
			}
		}
		else if (numberEnemy == 4)
		{
			EnemyAttribute goblin_shamanAttributes = {};
			goblin_shamanAttributes.enamyLevel = 2;
			goblin_shamanAttributes.enamyHp = 140;
			goblin_shamanAttributes.enamyMp = 220;
			goblin_shamanAttributes.enamyArmor = 20;
			goblin_shamanAttributes.enamyAvoid = 20;
			goblin_shamanAttributes.enemyName = " Гоблин-шаман";
			goblin_shamanAttributes.enamyElement = enemy.Enemy_Attrbutes.All;
			goblin_shamanAttributes.enamyElement_txt = " Имеет благославление Духа Гаии";
			goblin_shamanAttributes.enamyNumber = numberEnemy;
			Enemy Goblin_Shaman(goblin_shamanAttributes);

			if (enemy.bestiaryRan)
			{
				Goblin_Shaman.PrintEnemyStats();
			}

			if (!enemy.bestiaryRan)
			{
				enemy = Goblin_Shaman;
			}
			else
			{
				std::cout << std::endl;
			}
		}
		else if (numberEnemy == 5)
		{
			EnemyAttribute bansheeAttributes = {};
			bansheeAttributes.enamyLevel = 2;
			bansheeAttributes.enamyHp = 210;
			bansheeAttributes.enamyMp = 140;
			bansheeAttributes.enamyArmor = 20;
			bansheeAttributes.enamyAvoid = 40;
			bansheeAttributes.enemyName = " Баньши";
			bansheeAttributes.enamyElement = enemy.Enemy_Attrbutes.Air;
			bansheeAttributes.enamyElement_txt = " Воздух";
			bansheeAttributes.enamyNumber = numberEnemy;
			Enemy Banshee(bansheeAttributes);

			if (enemy.bestiaryRan)
			{
				Banshee.PrintEnemyStats();
			}

			if (!enemy.bestiaryRan)
			{
				enemy = Banshee;
			}
			else
			{
				std::cout << std::endl;
			}
		}
		else if (numberEnemy == 6)
		{
			EnemyAttribute draugrAttributes = {};
			draugrAttributes.enamyLevel = 2;
			draugrAttributes.enamyHp = 240;
			draugrAttributes.enamyMp = 40;
			draugrAttributes.enamyArmor = 80;
			draugrAttributes.enamyAvoid = 20;
			draugrAttributes.enemyName = " Драугр";
			draugrAttributes.enamyElement = enemy.Enemy_Attrbutes.Not;
			draugrAttributes.enamyElement_txt = "не имеет";
			draugrAttributes.enamyNumber = numberEnemy;
			Enemy Draugr(draugrAttributes);

			if (enemy.bestiaryRan)
			{
				Draugr.PrintEnemyStats();
			}

			if (!enemy.bestiaryRan)
			{
				enemy = Draugr;
			}
			else
			{
				std::cout << std::endl;
			}
		}
		else if (numberEnemy == 7)
		{
			EnemyAttribute slimeAttributes = {};
			slimeAttributes.enamyLevel = 1;
			slimeAttributes.enamyHp = 80;
			slimeAttributes.enamyMp = 400;
			slimeAttributes.enamyArmor = 10;
			slimeAttributes.enamyAvoid = 10;
			slimeAttributes.enemyName = " Слизь";
			slimeAttributes.enamyElement = enemy.Enemy_Attrbutes.Water;
			slimeAttributes.enamyElement_txt = " Вода";
			slimeAttributes.enamyNumber = numberEnemy;
			Enemy Slime(slimeAttributes);

			if (enemy.bestiaryRan)
			{
				Slime.PrintEnemyStats();
			}

			if (!enemy.bestiaryRan)
			{
				enemy = Slime;
			}
			else
			{
				std::cout << std::endl;
			}
		}
		else if (numberEnemy == 8)
		{
			EnemyAttribute satanistAttributes = {};
			satanistAttributes.enamyLevel = 3;
			satanistAttributes.enamyHp = 200;
			satanistAttributes.enamyMp = 300;
			satanistAttributes.enamyArmor = 30;
			satanistAttributes.enamyAvoid = 30;
			satanistAttributes.enemyName = " Сатанист";
			satanistAttributes.enamyElement = enemy.Enemy_Attrbutes.Fire;
			satanistAttributes.enamyElement_txt = " Огонь";
			satanistAttributes.enamyNumber = numberEnemy;
			Enemy Satanist(satanistAttributes);

			if (enemy.bestiaryRan)
			{
				Satanist.PrintEnemyStats();
			}

			if (!enemy.bestiaryRan)
			{
				enemy = Satanist;
			}
			else
			{
				std::cout << std::endl;
			}
		}
		else if (numberEnemy == 9)
		{
		EnemyAttribute cave_bearAttributes = {};
		cave_bearAttributes.enamyLevel = 2;
		cave_bearAttributes.enamyHp = 200;
		cave_bearAttributes.enamyMp = 300;
		cave_bearAttributes.enamyArmor = 30;
		cave_bearAttributes.enamyAvoid = 30;
		cave_bearAttributes.enemyName = " Пещерный медведь";
		cave_bearAttributes.enamyElement = enemy.Enemy_Attrbutes.Earth;
		cave_bearAttributes.enamyElement_txt = " Земля";
		cave_bearAttributes.enamyNumber = numberEnemy;
		Enemy Cave_bear(cave_bearAttributes);

			if (enemy.bestiaryRan)
			{
				Cave_bear.PrintEnemyStats();
			}

			if (enemy.bestiaryRan)
			{
				enemy = Cave_bear;
			}
			else
			{
				std::cout << std::endl;
			}
		}
		else if (numberEnemy == 10)
		{
			EnemyAttribute spirit_GaiaAttributes = {}; // бос
			spirit_GaiaAttributes.enamyLevel = 4;
			spirit_GaiaAttributes.enamyHp = 500;
			spirit_GaiaAttributes.enamyMp = 700;
			spirit_GaiaAttributes.enamyArmor = 90;
			spirit_GaiaAttributes.enamyAvoid = 60;
			spirit_GaiaAttributes.enemyName = " Дух Гайи";
			spirit_GaiaAttributes.enamyElement = enemy.Enemy_Attrbutes.All;
			spirit_GaiaAttributes.enamyElement_txt = " Повелевает стихиями 4х элементов";
			spirit_GaiaAttributes.enamyNumber = numberEnemy;
			Enemy Spirit_Gaia(spirit_GaiaAttributes);

			if (enemy.bestiaryRan)
			{
				Spirit_Gaia.PrintEnemyStats();
			}

			if (!enemy.bestiaryRan)
			{
				enemy = Spirit_Gaia;
			}
			else
			{
				std::cout << std::endl;
			}
		}
		else if (numberEnemy == 11)
		{
			EnemyAttribute lichAttributes = {}; // бос
			lichAttributes.enamyLevel = 4;
			lichAttributes.enamyHp = 400;
			lichAttributes.enamyMp = 850;
			lichAttributes.enamyArmor = 40;
			lichAttributes.enamyAvoid = 40;
			lichAttributes.enemyName = " Лич";
			lichAttributes.enamyElement = enemy.Enemy_Attrbutes.All;
			lichAttributes.enamyElement_txt = " Овладел всей известной магией";
			lichAttributes.enamyNumber = numberEnemy;
			Enemy Lich(lichAttributes);

			if (enemy.bestiaryRan)
			{
				Lich.PrintEnemyStats();
			}

			if (!enemy.bestiaryRan)
			{

				enemy = Lich;
			}
			else
			{
				std::cout << std::endl;
			}
		}
		else if (numberEnemy == 12)///////////////////////////////////////////////////////////
		{
			EnemyAttribute chthonic_golemAttributes = {}; // бос
			chthonic_golemAttributes.enamyLevel = 4;
			chthonic_golemAttributes.enamyHp = 400;
			chthonic_golemAttributes.enamyMp = 850;
			chthonic_golemAttributes.enamyArmor = 40;
			chthonic_golemAttributes.enamyAvoid = 40;
			chthonic_golemAttributes.enemyName = " Хтонический голем";
			chthonic_golemAttributes.enamyElement = enemy.Enemy_Attrbutes.Fire;
			chthonic_golemAttributes.enamyElement_txt = " Огонь";
			chthonic_golemAttributes.enamyNumber = numberEnemy;
			Enemy Chthonic_golem(chthonic_golemAttributes);

			if (enemy.bestiaryRan)
			{
				Chthonic_golem.PrintEnemyStats();
			}

			if (!enemy.bestiaryRan)
			{
				enemy = Chthonic_golem;
			}
			else
			{
				std::cout << std::endl;
			}
		}
		else if (numberEnemy == 13)///////////////////////////////////////////////
		{
			EnemyAttribute goblin_kingAttributes = {}; // бос
			goblin_kingAttributes.enamyLevel = 4;
			goblin_kingAttributes.enamyHp = 400;
			goblin_kingAttributes.enamyMp = 850;
			goblin_kingAttributes.enamyArmor = 40;
			goblin_kingAttributes.enamyAvoid = 40;
			goblin_kingAttributes.enemyName = " Король гоблинов";
			goblin_kingAttributes.enamyElement = enemy.Enemy_Attrbutes.All;
			goblin_kingAttributes.enamyElement_txt = " Имеет благословение Духа Гаии";
			goblin_kingAttributes.enamyNumber = numberEnemy;
			Enemy Goblin_king(goblin_kingAttributes);

			if (enemy.bestiaryRan)
			{
				Goblin_king.PrintEnemyStats();
			}

			if (!enemy.bestiaryRan)
			{
				enemy = Goblin_king;
			}
			else
			{
				std::cout << std::endl;
			}
		}
		else if (numberEnemy == 99)//////////////////////////////////////////////
		{
			EnemyAttribute defAttributes = {}; // final бос 
			defAttributes.enamyLevel = 1;
			defAttributes.enamyHp = 1;
			defAttributes.enamyMp = 1;
			defAttributes.enamyArmor = 1;
			defAttributes.enamyAvoid = 1;
			defAttributes.enemyName = " Default";
			defAttributes.enamyElement = enemy.Enemy_Attrbutes.Not;
			defAttributes.enamyElement_txt = " ???";
			defAttributes.enamyNumber = numberEnemy;
			Enemy Default(defAttributes);

			enemy = Default;
		}

		if (enemy.bestiaryRan)
		{
			if (i == 2)// вывод на экран по два монстра
			{
				system("pause");
				i = 0;
			}
			i++;

			if (numberEnemy == 1)//вывод элементалей
			{
				if (element == 5)
				{
					numberEnemy++;
				}
			}
			else if (numberEnemy > 1 && numberEnemy < 14)//вывод всех остальных монстров
			{
				numberEnemy++;
			}
			else if (numberEnemy == 14)
			{
				enemy.bestiaryRan = false;
				element = 0;
			}
		}
	} while (enemy.bestiaryRan);

	//*/
}
 
void Enemy::PrintEnemyStats()
{
	std::cout << std::endl;
	std::cout << Enemy_Attrbutes.enemyName << std::endl;
	if (Enemy_Attrbutes.enamyElement >= 1 && Enemy_Attrbutes.enamyElement <= 4)
	{
		std::cout << std::endl;
		std::cout <<" Стихия: " << Enemy_Attrbutes.enamyElement_txt << std::endl;
	}
	else if (Enemy_Attrbutes.enamyElement == 0)
	{
		std::cout << std::endl;
		std::cout << " Стихии " << Enemy_Attrbutes.enamyElement_txt << std::endl;
	}
	else if (Enemy_Attrbutes.enamyElement == 5)
	{
		std::cout << std::endl;
		std::cout << Enemy_Attrbutes.enamyElement_txt << std::endl;
	}
	else if (Enemy_Attrbutes.enamyElement == 6)
	{
		std::cout << std::endl;
		std::cout << Enemy_Attrbutes.enamyElement_txt << std::endl;
		std::cout << " тестовый объект" << std::endl;
	}
	std::cout << std::endl;
	std::cout << "* Характеристики *" << std::endl;
	std::cout << std::endl;
	std::cout << " Уровень: " << Enemy_Attrbutes.enamyLevel << std::endl;
	std::cout << " Здоровье: " << Enemy_Attrbutes.enamyHp << std::endl;
	std::cout << " Мана: " << Enemy_Attrbutes.enamyMp << std::endl;
	std::cout << " Броня: " << Enemy_Attrbutes.enamyArmor << std::endl;
	std::cout << " Атака: " << Enemy_Attrbutes.enamyAttack << std::endl;
	std::cout << " Уклонение: " << Enemy_Attrbutes.enamyAvoid << std::endl;
	std::cout << std::endl;
}


void Enemy::СhoiceDrop(Character& player)
{
	char in = ' ';
	
	int choiseDrop = 0;// возможный дроп


	// деньга +
	// 
	// + навыкам
	// if
	// + абилке
	// 
	//дроп
	//дроп

	player._PlayerAttributes._Inventory.many = player._PlayerAttributes._Inventory.many + 10;

	//player._PlayerAttributes._Inventory.many = 







	





//////////////

	/* srand(time(NULL));
	choiseDrop = 1 + rand() % 8;
	std::cout << "тестовая запись: " << choiseDrop << std::endl;
	std::cout << " В останках существа вы ";
	if (choiseDrop >= 1 && choiseDrop <= 3)
	{
		int choiseDrop_C = 0;
		srand(time(NULL));
		choiseDrop_C = 1 + rand() % 3;
		if (choiseDrop_C == 1)
		{
			std::cout<<"нашли ";

			Enemy_Attrbutes.Enemy_Drop.Name_Drops_1 = Enemy_Attrbutes.Enemy_Drop.Name_Possible_C1_Drops_1;
			Enemy_Attrbutes.Enemy_Drop.NumberDrop_1 = Enemy_Attrbutes.Enemy_Drop.Number_Possible_C1_Drop_1;

			std::cout << Enemy_Attrbutes.Enemy_Drop.Name_Drops_1 << std::endl;

		}
		else if (choiseDrop_C == 2)
		{
			std::cout<<"нашли ";

			Enemy_Attrbutes.Enemy_Drop.Name_Drops_1 = Enemy_Attrbutes.Enemy_Drop.Name_Possible_C2_Drops_1;
			Enemy_Attrbutes.Enemy_Drop.NumberDrop_1 = Enemy_Attrbutes.Enemy_Drop.Number_Possible_C2_Drop_1;

			std::cout << Enemy_Attrbutes.Enemy_Drop.Name_Drops_1 << std::endl;
		}
		else if (choiseDrop_C == 3)
		{
			std::cout<<"нашли ";

			Enemy_Attrbutes.Enemy_Drop.Name_Drops_1 = Enemy_Attrbutes.Enemy_Drop.Name_Possible_C3_Drops_1;
			Enemy_Attrbutes.Enemy_Drop.NumberDrop_1 = Enemy_Attrbutes.Enemy_Drop.Number_Possible_C3_Drop_1;

			std::cout << Enemy_Attrbutes.Enemy_Drop.Name_Drops_1 << std::endl;
		}

	}
	else if (choiseDrop >= 4 && choiseDrop <= 5)
	{
		int choiseDrop_S = 0;
		srand(time(NULL));
		choiseDrop_S = 1 + rand() % 4;
		if (choiseDrop_S == 1 || choiseDrop_S == 3)
		{
			std::cout<<"нашли ";

			Enemy_Attrbutes.Enemy_Drop.Name_Drops_1 = Enemy_Attrbutes.Enemy_Drop.Name_Possible_S1_Drops_1;
			Enemy_Attrbutes.Enemy_Drop.NumberDrop_1 = Enemy_Attrbutes.Enemy_Drop.Number_Possible_S1_Drop_1;

			std::cout << Enemy_Attrbutes.Enemy_Drop.Name_Drops_1 << std::endl;

		}
		else if (choiseDrop_S == 2 || choiseDrop_S == 4)
		{
			std::cout<<"нашли ";

			Enemy_Attrbutes.Enemy_Drop.Name_Drops_1 = Enemy_Attrbutes.Enemy_Drop.Name_Possible_S2_Drops_1;
			Enemy_Attrbutes.Enemy_Drop.NumberDrop_1 = Enemy_Attrbutes.Enemy_Drop.Number_Possible_S2_Drop_1;

			std::cout << Enemy_Attrbutes.Enemy_Drop.Name_Drops_1 << std::endl;
		}
	}
	else if (choiseDrop == 6)
	{
		std::cout<<"нашли ";

		Enemy_Attrbutes.Enemy_Drop.Name_Drops_1 = Enemy_Attrbutes.Enemy_Drop.Name_Possible_G1_Drops_1;
		Enemy_Attrbutes.Enemy_Drop.NumberDrop_1 = Enemy_Attrbutes.Enemy_Drop.Number_Possible_G1_Drop_1;

		std::cout << Enemy_Attrbutes.Enemy_Drop.Name_Drops_1 << std::endl;
	}
	else
	{
		std::cout << "ничего не нашли" << std::endl;
	}

	if (choiseDrop < 7)
	{
		std::cout << " Добавить в инвентарь?" << std::endl;
		std::cout << " Да(Y)   Нет(N)" << std::endl;
		std::cin >> in;
		if (in == 'Y' || in == 'y')
		{
			player.InItemsInventory(Enemy_Attrbutes.Enemy_Drop.NumberDrop_1, Enemy_Attrbutes.Enemy_Drop.Quantity_drop_1);

		}
	}

	choiseDrop = 0;
	//*/
}
//////////////


void Enemy::MobDrops(Enemy& enemy, Character& player)
{
	int numberEnemy = Enemy_Attrbutes.enamyNumber;


	switch (numberEnemy)
	{
	case 1:
		
		 /*элементаль*/

		//player.OutNameItem(1); // зелье маны
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_C1_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_C1_Drop_1 = player.Item_attr.NumberItem;
		//player.OutNameItem(2); // зелье здоровья
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_C2_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_C2_Drop_1 = player.Item_attr.NumberItem;
		//player.OutNameItem(3); // зелье выносливости
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_C3_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_C3_Drop_1 = player.Item_attr.NumberItem;
		//
		//player.OutNameItem(4); // зелье урона
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_S1_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_S1_Drop_1 = player.Item_attr.NumberItem;
		//player.OutNameItem(5);// зелье невидимости
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_S2_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_S2_Drop_1 = player.Item_attr.NumberItem;
		//
		//player.OutNameItem(6);// зелье урона
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_G1_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_G1_Drop_1 = player.Item_attr.NumberItem;

		break;




	default:
		break;
	}





	/* пример

	if (numberEnemy == 1)
	{
		 //элементаль
		player.OutNameItem(1); // зелье маны
		Enemy_Attrbutes.Enemy_Drop.Quantity_drop_gold = 10;
		Enemy_Attrbutes.Enemy_Drop.Name_Possible_C1_Drops_1 = player.Item_attr.NameItem;
		Enemy_Attrbutes.Enemy_Drop.Number_Possible_C1_Drop_1 = player.Item_attr.NumberItem;
		player.OutNameItem(2); // зелье здоровья
		Enemy_Attrbutes.Enemy_Drop.Name_Possible_C2_Drops_1 = player.Item_attr.NameItem;
		Enemy_Attrbutes.Enemy_Drop.Number_Possible_C2_Drop_1 = player.Item_attr.NumberItem;
		player.OutNameItem(3); // зелье выносливости
		Enemy_Attrbutes.Enemy_Drop.Name_Possible_C3_Drops_1 = player.Item_attr.NameItem;
		Enemy_Attrbutes.Enemy_Drop.Number_Possible_C3_Drop_1 = player.Item_attr.NumberItem;
		
		player.OutNameItem(4); // зелье урона
		Enemy_Attrbutes.Enemy_Drop.Name_Possible_S1_Drops_1 = player.Item_attr.NameItem;
		Enemy_Attrbutes.Enemy_Drop.Number_Possible_S1_Drop_1 = player.Item_attr.NumberItem;
		player.OutNameItem(5);// зелье невидимости
		Enemy_Attrbutes.Enemy_Drop.Name_Possible_S2_Drops_1 = player.Item_attr.NameItem;
		Enemy_Attrbutes.Enemy_Drop.Number_Possible_S2_Drop_1 = player.Item_attr.NumberItem;
		
		player.OutNameItem(6);// зелье урона
		Enemy_Attrbutes.Enemy_Drop.Name_Possible_G1_Drops_1 = player.Item_attr.NameItem;
		Enemy_Attrbutes.Enemy_Drop.Number_Possible_G1_Drop_1 = player.Item_attr.NumberItem;
	}
	else if (numberEnemy == 2)
	{
		// арахнид

		//player.OutNameItem(1); // зелье маны
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_C1_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_C1_Drop_1 = player.Item_attr.NumberItem;
		//player.OutNameItem(2); // зелье здоровья
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_C2_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_C2_Drop_1 = player.Item_attr.NumberItem;
		//player.OutNameItem(3); // зелье выносливости
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_C3_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_C3_Drop_1 = player.Item_attr.NumberItem;

		//player.OutNameItem(4); // зелье урона
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_S1_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_S1_Drop_1 = player.Item_attr.NumberItem;
		//player.OutNameItem(5);// зелье невидимости
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_S2_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_S2_Drop_1 = player.Item_attr.NumberItem;

		//player.OutNameItem(6);// зелье урона
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_G1_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_G1_Drop_1 = player.Item_attr.NumberItem;
	}
	else if (numberEnemy == 3)
	{
		//  гоблин воин  (зелья мал и ср)

		//player.OutNameItem(1); // зелье маны
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_C1_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_C1_Drop_1 = player.Item_attr.NumberItem;
		//player.OutNameItem(2); // зелье здоровья
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_C2_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_C2_Drop_1 = player.Item_attr.NumberItem;
		//player.OutNameItem(3); // зелье выносливости
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_C3_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_C3_Drop_1 = player.Item_attr.NumberItem;

		//player.OutNameItem(4); // зелье урона
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_S1_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_S1_Drop_1 = player.Item_attr.NumberItem;
		//player.OutNameItem(5);// зелье невидимости
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_S2_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_S2_Drop_1 = player.Item_attr.NumberItem;

		//player.OutNameItem(6);// зелье урона
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_G1_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_G1_Drop_1 = player.Item_attr.NumberItem;
	}
	else if (numberEnemy == 4)
	{
		// гоблин шаман  весе зелья

	//	player.OutNameItem(1); // зелье маны
	//	Enemy_Attrbutes.Enemy_Drop.Name_Possible_C1_Drops_1 = player.Item_attr.NameItem;
	//	Enemy_Attrbutes.Enemy_Drop.Number_Possible_C1_Drop_1 = player.Item_attr.NumberItem;
	//	player.OutNameItem(2); // зелье здоровья
	//	Enemy_Attrbutes.Enemy_Drop.Name_Possible_C2_Drops_1 = player.Item_attr.NameItem;
	//	Enemy_Attrbutes.Enemy_Drop.Number_Possible_C2_Drop_1 = player.Item_attr.NumberItem;
	//	player.OutNameItem(3); // зелье выносливости
	//	Enemy_Attrbutes.Enemy_Drop.Name_Possible_C3_Drops_1 = player.Item_attr.NameItem;
	//	Enemy_Attrbutes.Enemy_Drop.Number_Possible_C3_Drop_1 = player.Item_attr.NumberItem;

	//	player.OutNameItem(4); // зелье урона
	//	Enemy_Attrbutes.Enemy_Drop.Name_Possible_S1_Drops_1 = player.Item_attr.NameItem;
	//	Enemy_Attrbutes.Enemy_Drop.Number_Possible_S1_Drop_1 = player.Item_attr.NumberItem;
	//	player.OutNameItem(5);// зелье невидимости
	//	Enemy_Attrbutes.Enemy_Drop.Name_Possible_S2_Drops_1 = player.Item_attr.NameItem;
	//	Enemy_Attrbutes.Enemy_Drop.Number_Possible_S2_Drop_1 = player.Item_attr.NumberItem;

	//	player.OutNameItem(6);// зелье урона
	//	Enemy_Attrbutes.Enemy_Drop.Name_Possible_G1_Drops_1 = player.Item_attr.NameItem;
	//	Enemy_Attrbutes.Enemy_Drop.Number_Possible_G1_Drop_1 = player.Item_attr.NumberItem;
	}
	else if (numberEnemy == 5)
	{
		// баньши

		//player.OutNameItem(1); // зелье маны
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_C1_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_C1_Drop_1 = player.Item_attr.NumberItem;
		//player.OutNameItem(2); // зелье здоровья
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_C2_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_C2_Drop_1 = player.Item_attr.NumberItem;
		//player.OutNameItem(3); // зелье выносливости
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_C3_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_C3_Drop_1 = player.Item_attr.NumberItem;

		//player.OutNameItem(4); // зелье урона
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_S1_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_S1_Drop_1 = player.Item_attr.NumberItem;
		//player.OutNameItem(5);// зелье невидимости
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_S2_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_S2_Drop_1 = player.Item_attr.NumberItem;

		//player.OutNameItem(6);// зелье урона
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_G1_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_G1_Drop_1 = player.Item_attr.NumberItem;
	}
	else if (numberEnemy == 6)
	{
	// драугр

		//player.OutNameItem(1); // зелье маны
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_C1_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_C1_Drop_1 = player.Item_attr.NumberItem;
		//player.OutNameItem(2); // зелье здоровья
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_C2_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_C2_Drop_1 = player.Item_attr.NumberItem;
		//player.OutNameItem(3); // зелье выносливости
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_C3_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_C3_Drop_1 = player.Item_attr.NumberItem;

		//player.OutNameItem(4); // зелье урона
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_S1_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_S1_Drop_1 = player.Item_attr.NumberItem;
		//player.OutNameItem(5);// зелье невидимости
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_S2_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_S2_Drop_1 = player.Item_attr.NumberItem;

		//player.OutNameItem(6);// зелье урона
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_G1_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_G1_Drop_1 = player.Item_attr.NumberItem;
	}
	else if (numberEnemy == 7)
	{
		// слизь

		//player.OutNameItem(1); // зелье маны
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_C1_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_C1_Drop_1 = player.Item_attr.NumberItem;
		//player.OutNameItem(2); // зелье здоровья
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_C2_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_C2_Drop_1 = player.Item_attr.NumberItem;
		//player.OutNameItem(3); // зелье выносливости
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_C3_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_C3_Drop_1 = player.Item_attr.NumberItem;

		//player.OutNameItem(4); // зелье урона
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_S1_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_S1_Drop_1 = player.Item_attr.NumberItem;
		//player.OutNameItem(5);// зелье невидимости
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_S2_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_S2_Drop_1 = player.Item_attr.NumberItem;

		//player.OutNameItem(6);// зелье урона
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_G1_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_G1_Drop_1 = player.Item_attr.NumberItem;
	}
	
	else if (numberEnemy == 8)
	{
		// сатанист
		
		//player.OutNameItem(1); // зелье маны
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_C1_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_C1_Drop_1 = player.Item_attr.NumberItem;
		//player.OutNameItem(2); // зелье здоровья
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_C2_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_C2_Drop_1 = player.Item_attr.NumberItem;
		//player.OutNameItem(3); // зелье выносливости
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_C3_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_C3_Drop_1 = player.Item_attr.NumberItem;

		//player.OutNameItem(4); // зелье урона
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_S1_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_S1_Drop_1 = player.Item_attr.NumberItem;
		//player.OutNameItem(5);// зелье невидимости
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_S2_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_S2_Drop_1 = player.Item_attr.NumberItem;

		//player.OutNameItem(6);// зелье урона
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_G1_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_G1_Drop_1 = player.Item_attr.NumberItem;
	}
	else if (numberEnemy == 9)
	{
		// дух гайи

		//player.OutNameItem(1); // зелье маны
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_C1_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_C1_Drop_1 = player.Item_attr.NumberItem;
		//player.OutNameItem(2); // зелье здоровья
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_C2_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_C2_Drop_1 = player.Item_attr.NumberItem;
		//player.OutNameItem(3); // зелье выносливости
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_C3_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_C3_Drop_1 = player.Item_attr.NumberItem;

		//player.OutNameItem(4); // зелье урона
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_S1_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_S1_Drop_1 = player.Item_attr.NumberItem;
		//player.OutNameItem(5);// зелье невидимости
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_S2_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_S2_Drop_1 = player.Item_attr.NumberItem;

		//player.OutNameItem(6);// зелье урона
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_G1_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_G1_Drop_1 = player.Item_attr.NumberItem;
	}
	else if (numberEnemy == 10)
	{
		// лич

		//player.OutNameItem(1); // зелье маны
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_C1_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_C1_Drop_1 = player.Item_attr.NumberItem;
		//player.OutNameItem(2); // зелье здоровья
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_C2_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_C2_Drop_1 = player.Item_attr.NumberItem;
		//player.OutNameItem(3); // зелье выносливости
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_C3_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_C3_Drop_1 = player.Item_attr.NumberItem;

		//player.OutNameItem(4); // зелье урона
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_S1_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_S1_Drop_1 = player.Item_attr.NumberItem;
		//player.OutNameItem(5);// зелье невидимости
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_S2_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_S2_Drop_1 = player.Item_attr.NumberItem;

		//player.OutNameItem(6);// зелье урона
		//Enemy_Attrbutes.Enemy_Drop.Name_Possible_G1_Drops_1 = player.Item_attr.NameItem;
		//Enemy_Attrbutes.Enemy_Drop.Number_Possible_G1_Drop_1 = player.Item_attr.NumberItem;
	}
	     
	*/

	СhoiceDrop(player);
}


EnemyAttribute Enemy::GetAttributesE() const
{
	return Enemy_Attrbutes;
}

EnemyDrops Enemy::GetEnemyDrops() const
{
	return Enemy_Attrbutes.Enemy_Drop;
}

int Enemy::GetAllEnemy(Enemy& enemy)
{
	CreateEnemy(enemy);

	return allEnemy;
}












