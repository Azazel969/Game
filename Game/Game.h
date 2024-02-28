#pragma once
#include "Character.h"
#include "Input_registration.h"
#include "Map.h"
#include "Enemy.h"
#include "Battle.h"
#include "NPS.h"
#include "File.h"


struct Actions
{
	// �������� � ����
	void Options_actions(bool BL_Drop_Item, int Stamina, bool Alert, bool Overview, int Int_World, bool Bl_Save, bool Bl_Passage, bool return_village);

	bool Drop_item = false;// ����� ����� ���� �� ����

	bool Alert_attr = false;// ����������� � ��������� �������������

	bool No_travel = false;// ��� ����������� ��������������

	bool Travel = false;// ��������������

	bool Fire_off = false;// �������� �����

	bool Fire_on = false;// ������ �����

	bool Load_save = false;// ����������

	bool Passage = false;// �������� ������� �� ������ �����

	bool return_village = false;// ����������� � ���������

	bool Menu = false;// ����

};


class Game
{
public:

	Game();
	void Go();

	// �������� ���� ��� ������ ���������
	bool GameStatus();

	/// <summary>
	/// ������� ����
	/// </summary>
	void GameMenu();

	// �������� �����
	//Enemy CreateEnemy(int NumberEnemy);
	//Game(const ItemInHand& Item_attr);
	
private:

	// ���������� ����
	void Update();
	// ������� ���������
	void Render();
	// �������� 
	void Game_loading();
	// ����� ����������� ��������� (���� ������)
	bool PlayerRebirth();

	// ������� ����
	void Game_print_MainMenu();

	/// <summary>
	/// ����� ���� - ����� ����
	/// </summary>
	void New_game();

	/// <summary>
	/// ����� ���� - �������� ����
	/// </summary>
	/// <param name="������ ������ Character"></param>
	/// <param name="������ ������ Files"></param>
	void Loading_save(Character& player, Files& files);

	/// <summary>
	/// ����� ���� ���������� ����
	/// </summary>
	void Save_game(Character& player);

	/// <summary>
	/// ����� ���� - ���������
	/// </summary>
	void Settings();

	/// <summary>
	/// ����� ���� - ������������
	/// </summary>
	void Developers();

	// ����� ����
	void Game_mode();

	void Mode_change(Input_registration &input_registration, bool Mode);

	// ��������� ���������� battleRan
	void Bl_Battle_val(Battle& bat, int Mode);

	/// <summary>
	/// �������� ��������� ��� ��� �������� �� ����������
	/// </summary>
	void Player_initialization(Character& player, Character &tempCharacter, Map& map);

	// �������� ����
	void Nickname();

	// ������� �������
	void Game_print_Gameplay(Character& player);
	// �o��� ������
	char GetUserInput(char UserIn);
	// �������� ���������
	Character CreateCharacter(Character& player, char UserIn = '0');

private:

	bool test = false;
	
	bool bestiaryRan = false;

	// ����� ������ ���������
	char namberClass = 0;

public:

	// ������������ �������� ��������� 
	bool isGameplayStarted = false;

	// ������������ ������ ����
	bool isGameStarted = false;

	// ���������� ������ �� ���� (true - ����������� ����; false - ���������� ����)
	bool isGameRunnig = true;

	//������������ ������ ������
	bool isPlayerDie = false;

	// ��������� � ������� ����
	bool settings = false;

private:

	Character player; /// <summary>������: ������� �������� </summary>

	Character tempCharacter; /// <summary> ��������� �������� (�� ������������� ������)</summary>

	Enemy enemy; /// <summary>������: ���� </summary>

	Enemy Bestiary_enemy; /// <summary>���������� ��� ���������� �������� � ���������</summary>

	Battle bat; /// <summary>������: ��� </summary>

	NPS nps; // ��� �������

	Map map; /// <summary>������: ����� </summary>

	Input_registration input_registration;/// <summary>������: ���������� ������� </summary>

	Files files; /// <summary>������: ����������</summary>

	Actions Actions;
};




