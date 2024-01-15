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
	

	// ������� ���
	void battle(Character& player, Enemy& enemy);

	// ���� ���������
	//void Menu_Character(Character& player);
	
	// ������� �������� ������� �������
	void Size_Console();

private:

	/// <summary>
	/// ������ ��� � �������� �������
	/// </summary>
	void FidhtOverview(Character& player, Enemy& enemy);

	/// <summary>
	/// ������ ��� � �������
	/// </summary>
	void FightNotOverview(Character& player, Enemy& enemy);

	/// <summary>
	/// ��������
	/// </summary>
	void Fight(Character& player, Enemy& enemy);

	/// <summary>
	/// ������ �����
	/// </summary>
	void Attack(Character& player, Enemy& enemy);

	/// <summary>
	/// ����� � ���� ���
	/// </summary>
	/// <param name="player"></param>
	void Escape(Character& player);

	//������
	void Victory();

	// ��������
	void Loss();

	// ������ �����
	double Calculation_Xp();






public:

	// ���������� ��� (���� true ������� Battle ����� ����������)
	bool battleRan;

	bool PlayerDie = false;
	bool EnemyDie = false;
	
private:

	int x_console = 0; // ������
	int y_console = 0; // �������

	Character player;
	Enemy enemy;
	Map map;
	Input_registration input_registration;

	/// <summary>
	/// ������ ��������� ����
	/// </summary>
	bool first_enemy = true;;

	/// <summary>
	/// ������������ ������� ��� (true - ��� ������������)
	/// </summary>
	bool Bl_Fight = false;

	/// <summary>
	/// ������ ��� 
	/// </summary>
	bool start_fight;

	/// <summary>
	/// true - ��� ��������
	/// </summary>
	bool detecred_player;

	/// <summary>
	/// true - �� �������� enemy
	/// </summary>
	bool detecred_enemy;

	/// <summary>
	/// ���� 
	/// </summary>
	bool enemy_aggression = false;

	
	int numberEnemy;
	/// <summary>
	/// ���� � ����
	/// </summary>
	bool mobDrop = false;

	// ���� �� ������
	int Damage_Player = 0;

	// ���� �� enemy
	int Damage_Enemy = 0;

	// ��� ���
	int Step = 0;

	/// <summary>
	/// ����������� ���� �� ����
	/// </summary>
	bool crit_enemy = false;

	/// <summary>
	/// ����������� ���� �� ������
	/// </summary>
	bool crit_player = false;

	/// <summary>
	/// ����� � ���� ���
	/// </summary>
	bool runaway = false;
};