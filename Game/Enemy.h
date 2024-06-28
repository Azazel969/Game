#pragma once
#include <string>
#include "Character.h"

struct Enemies
{
	/// <summary>
	/// �������� enemy
	/// </summary>
	//EnemyAttribute Enemy_Attrbutes;

	/// <summary>
	/// ���� � enemy
	/// </summary>
	//EnemyDrops Enemy_Drop;
};

/// <summary>
/// ���� � enamy
/// </summary>
struct EnemyDrops
{
	int quantityItem = 1;


	int Quantity_drop_gold = 1; // ������ �������� � �����

	int  Quantity_drop_xp;// �������� ����� ������

	int  Quantity_drop_xp_skill;// �������� ����� �����
	
	int  Quantity_drop_xp_ability;// �������� ����� ������

	std::string Name_drops_potion; // ���� �����
	int Number_drop_potion;// ��� �����(�� ������� OutNameItem(� ��������))
	int Quantity_drop_potion = quantityItem;// ���������� �������� ��������� 

	std::string Name_drops_armor; // ���� �����
	int Number_drop_armor;// ��� �����(�� ������� OutNameItem(� ��������))
	int Quantity_drop_armor = quantityItem;// ���������� �������� ��������� 

	std::string Name_drops_weapon; // ���� ������
	int Number_drop_weapon;// ��� �����(�� ������� OutNameItem(� ��������))
	int Quantity_drop_weapon = quantityItem;// ���������� �������� ��������� 

	//////////////////////////////////////////////////////////////////////////////////
	int Arr_drop_potion[21];// Drops_potion ��������� ��������


	//////////////////////////////////////////////////////////////////////////////////
	int Arr_drop_armor[17];// Drops_armor ��������� ��������
	

	////////////////////////////////////////////////////////////////////////////////////
	int Arr_drop_weapon[4] = {7, 46, 5768};// Drops_weapon ��������� ��������
	

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
	int enamyAvoid; // ���������
	std::string enamyElement_txt;// ������� ����������
	int enamyElement; // �������� ������������� ��������

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

	//����
	Enemy(const EnemyAttribute& Enemy_Attrbutes);
	
	// �������� �����
	void CreateEnemy(Enemy& enemy);

	//���������� �����
	void PrintEnemyStats();

	// ���� � �����
	void MobDrops(Enemy& enemy, Character& player);
	// ����� �����
	void �hoiceDrop(Character& player);
	//������� ����������� ��������� �����
	EnemyAttribute GetAttributesE() const;
	// ���� (���������)
	EnemyDrops GetEnemyDrops() const;


public:
	
	Enemies Enemies;
	
	///////////////////////////////////////////
	EnemyAttribute Enemy_Attrbutes;

	/// <summary>
	/// ���������� ���������� ������ 
	/// </summary>
	/// <returns></returns>
	int GetAllEnemy(Enemy& enemy);
	
	//���������
	bool bestiaryRan = false;

private:
	/// <summary>
	/// �������� ������ ��� �������� enamy
	/// </summary>
	bool test = true;

	/// <summary>
	/// ����� ���������� ������
	/// </summary>
	int allEnemy = 0;


};