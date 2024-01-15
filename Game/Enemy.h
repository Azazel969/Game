#pragma once
#include <string>
#include "Character.h"

struct Enemies
{
	/// <summary>
	/// Атрибуты enemy
	/// </summary>
	//EnemyAttribute Enemy_Attrbutes;

	/// <summary>
	/// дроп с enemy
	/// </summary>
	//EnemyDrops Enemy_Drop;
};

/// <summary>
/// дроп с enamy
/// </summary>
struct EnemyDrops
{
	int quantityItem = 1;


	int Quantity_drop_gold = 1; // золото выпавшее с врага

	int  Quantity_drop_xp_skill;// эсенция опыта скил
	
	int  Quantity_drop_xp_ability;// эсенция опыта абилка

	std::string Name_drops_potion; // дроп зелья
	int Number_drop_potion;// его номер(по функции OutNameItem(№ предмета))
	int Quantity_drop_potion = quantityItem;// количество выпавших предметов 

	std::string Name_drops_armor; // дроп брони
	int Number_drop_armor;
	int Quantity_drop_armor = quantityItem;

	std::string Name_drops_weapon; // дроп оружия
	int Number_drop_weapon;
	int Quantity_drop_weapon = quantityItem;

	//////////////////////////////////////////////////////////////////////////////////
	int Arr_drop_potion[21];// Drops_potion возможные предметы


	//////////////////////////////////////////////////////////////////////////////////
	int Arr_drop_armor[17];// Drops_armor возможные предметы
	

	////////////////////////////////////////////////////////////////////////////////////
	int Arr_drop_weapon[4] = {7, 46, 5768};// Drops_weapon возможные предметы
	

	/////////////////////////////////////////////////////////////////////////////////////

	//static constexpr int Cols = 50; // x 40
	//static constexpr int Rows = 20; // y 20
	//int tileMap[Rows][Cols] = { 1,4,46 };

};

struct EnemyAttribute
{
	
	std::string enemyName;
	int enamyLevel;
	int enamyNumber;
	int enamyHp;
	int enamyMp;
	int enamyArmor;
	int enamyAttack = 30;
	int enamyAvoid; // уклонение
	std::string enamyElement_txt;// Элемент элементаля
	int enamyElement; // числовое предстовление элемента

	enum Element 
	{
		Not, Fire, Water, Air, Earth, All
	}; 



	//////////////////////////////
	EnemyDrops Enemy_Drop;
};

class Enemy
{

public:

	Enemy();

	//враг
	Enemy(const EnemyAttribute& Enemy_Attrbutes);
	
	// создание врага
	void CreateEnemy(Enemy& enemy);

	//напечатать статы
	void PrintEnemyStats();

	// дроп с мобов
	void MobDrops(Enemy& enemy, Character& player);
	// выбор дропа
	void СhoiceDrop(Character& player);
	//функция возврвщения аттрибутов врага
	EnemyAttribute GetAttributesE() const;
	// дроп (параметры)
	EnemyDrops GetEnemyDrops() const;


public:
	
	Enemies Enemies;
	
	///////////////////////////////////////////
	EnemyAttribute Enemy_Attrbutes;

	int allEnamy = 0;
	
	//бестиарий
	bool bestiaryRan = false;

private:
	// тестовый прогон для подсчета enamy
	bool test = true;

};