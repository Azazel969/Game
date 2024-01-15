#pragma once
#include <string>
#include"Character.h"
#include "Enemy.h"
#include "Map.h"
#include "Input_registration.h"

class Battle
{
public:
	Battle();
	~Battle();
	

	// функция боя
	void battle(Character& player, Enemy& enemy);

	// Меню персонажа
	//void Menu_Character(Character& player);
	
	// функция передачи размера консоли
	void Size_Console();

private:

	/// <summary>
	/// Начало боя с заженным факелом
	/// </summary>
	void FidhtOverview(Character& player, Enemy& enemy);

	/// <summary>
	/// Начало боя в темноте
	/// </summary>
	void FightNotOverview(Character& player, Enemy& enemy);

	/// <summary>
	/// Сражение
	/// </summary>
	void Fight(Character& player, Enemy& enemy);

	/// <summary>
	/// Расчет урона
	/// </summary>
	void Attack(Character& player, Enemy& enemy);

	/// <summary>
	/// Побег с поля боя
	/// </summary>
	/// <param name="player"></param>
	void Escape(Character& player);

	//победа
	void Victory();

	// проигрыш
	void Loss();

	// расчет опыта
	double Calculation_Xp();






public:

	// переменная боя (пока true функция Battle будет выполнятся)
	bool battleRan;

	bool PlayerDie = false;
	bool EnemyDie = false;
	
private:

	int x_console = 0; // строка
	int y_console = 0; // столбец

	Character player;
	Enemy enemy;
	Map map;
	Input_registration input_registration;

	/// <summary>
	/// первый увиденный враг
	/// </summary>
	bool first_enemy = true;;

	/// <summary>
	/// отслеживание статуса боя (true - бой продолжается)
	/// </summary>
	bool Bl_Fight = false;

	/// <summary>
	/// начало боя 
	/// </summary>
	bool start_fight;

	/// <summary>
	/// true - вас заметили
	/// </summary>
	bool detecred_player;

	/// <summary>
	/// true - вы заметили enemy
	/// </summary>
	bool detecred_enemy;

	/// <summary>
	/// агро 
	/// </summary>
	bool enemy_aggression = false;

	
	int numberEnemy;
	/// <summary>
	/// дроп с моба
	/// </summary>
	bool mobDrop = false;

	// урон по игроку
	int Damage_Player = 0;

	// урон по enemy
	int Damage_Enemy = 0;

	// шаг боя
	int Step = 0;

	/// <summary>
	/// критический урон по мобу
	/// </summary>
	bool crit_enemy = false;

	/// <summary>
	/// критический урон по игроку
	/// </summary>
	bool crit_player = false;

	/// <summary>
	/// Побег с поля боя
	/// </summary>
	bool runaway = false;
};