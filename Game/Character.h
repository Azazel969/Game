#pragma once
#include <string>
#include "Input_registration.h"



struct PlayerInventory
{
	int many = 0;/// <summary>������</summary>

	// ������ ������a��
	static constexpr int inventoryPage = 4; // ��������
	static constexpr int width = 10; // ������
	static constexpr int height = 10; // ������

	bool resetInventory;

	int inventory[inventoryPage][width][height];

	int quantity[inventoryPage][width][height];

	/// <summary>
	/// ����� ���� � ����� ���������
	/// </summary>
	int namberItem;

	/// <summary>
	/// ���������� ����� � ����� ���������
	/// </summary>
	int quantityItem;

	/// <summary>
	/// �������� ��������� (�����, �����, o�����, ���������)
	/// </summary>
	int page;
};

struct PlayerSet
{
	std::string name_Armor;// �����
	int int_Armor;// ����� ��������
	float Armor_Mod; // ����������� �����
	bool bl_Armor_mod = false;// ����/���

	std::string name_Weapon;// ������
	int int_Weapon;// ����� ��������
	float Weapon_Mod; // ����������� ������
	bool bl_Weapon_mod = false;// ����/���

	std::string str_name_jewelry;//���������
	int int_jewelry;// ����� ��������
	bool bl_jewelry = false;// ����/���
};

struct Skills
{
	std::string Name_skill_1 = " �������"; // �������� ������ 1
	int Int_skill_1 = 0; // ����� ������ 1
	int Int_levl_skill_1 = 1; // ������� ������
	int Int_Xp_skill_1 = 1;
	std::string Description_skill_1 = " ��������� ������� � ������ ������������"; // �������� ������ 1
	
	std::string Name_skill_2 = " ��������� �����"; 
	int Int_skill_2 = 0; 
	int Int_levl_skill_2 = 1;
	int Int_Xp_skill_2 = 1;
	std::string Description_skill_2 = " +� ��"; 

	std::string Name_skill_3 = " ����� �������";
	int Int_skill_3 = 0;
	int Int_levl_skill_3 = 1;
	int Int_Xp_skill_3 = 1;
	std::string Description_skill_3 = " �������� ���� �� ����������� ������ ��������";
};

struct Abilitys
{
	std::string Name_ability_1 = " ������ ������"; // �������� ����������� 1
	int Int_ability_1 = 0; // ����� ����������� 1
	int Int_levl_ability_1 = 1; // ������� ����������� 1
	int Int_Xp_ability_1 = 1;
	std::string Description_ability_1 = " �������� ����� �� ����� �������� ���. � ��� ���������� ����������� ���������� �� �����"; // �������� ����������� 1

	std::string Name_ability_2 = " ������ ����";
	int Int_ability_2 = 0;
	int Int_levl_ability_2 = 1;
	int Int_Xp_ability_2 = 1;
	std::string Description_ability_2 = " � �������� ������ ���������� �� �����. �� 1 ��� �������� ���� �� � ���-��"; 

	std::string Name_ability_3 = " ������ �����";
	int Int_ability_3 = 0;
	int Int_levl_ability_3 = 1;
	int Int_Xp_ability_3 = 1;
	std::string Description_ability_3 = " � ������ ��� ����� ������ ����. �� 1 ��� �������� ������ �� � ���-��";

};

struct Position
{
	int x;// position x
	int y;// position y

	/// <summary>
	/// �������������� ������� ��� ���
	/// </summary>
	bool Transfer_player = false;

	int Int_World; /// <summary>�� ����� ����� ��������� (�����)</summary>

	bool returns_village = false; /// <summary>������������ ����� � ��������� ��� ���</summary>

	std::string World; // �� ����� ����� ���������
};

struct StorageAttributesg
{
	// ����������� ��������� ���������
	void Add_standart_param();

	int St_Hp;
	int St_Mana;
	int St_Armor;
	int St_Attack;
	int St_Stamina;
	int St_Avoid;
};

/// <summary>
/// ��������� � ����������� � ��������� ����������
/// </summary>
struct SystemParam
{
	int int_name_Class;// �������� ��� ������

	bool Overview = false; // �����

	bool Auto_input = false;// ���� ����

	// ����������� ��������� c ���������������� ���������
	bool Alert = false;

	/// <summary>
	/// ����� ����������� �� ����������
	/// </summary>
	bool Load_save = false;

	/// <summary>
	/// ��������� � ����������� �� ��������� �������� ������������� ���������
	/// </summary>
	StorageAttributesg _StorageAttributes;

	/// <summary>
	/// ��������� � ����������� � ������� �����
	/// </summary>
	Position _Position;
};

/// <summary>
/// ��������� � ����������� � �����
/// </summary>
struct PlayerAttributes
{
	// �������� �����
	std::string name_Character = "DEF";// ���
	std::string name_Class;
	int P_Levl;
	int P_XP;
	int P_Hp;
	int P_Mana;
	int P_armor;
	float P_attack;
	int P_avoid; // ���������
	int P_stamina; // ������������

	// ���. �����
	int P_Expenditure_Attack; // ������ ������������ ��� �����
	int P_Expenditure_Escape; // ������ ������������ ��� ������

	
	/// <summary>
	/// ��������� � ����������� �� ��������� �����
	/// </summary>
	PlayerInventory _Inventory;

	/// <summary>
	/// ��������� � ����������� � ������� �� ����� �����
	/// </summary>
	PlayerSet _PlayerSet;

	/// <summary>
	/// ��������� � ����������� �� ������� �����
	/// </summary>
	Skills _Skills;

	/// <summary>
	/// ��������� � ����������� �� ������������ �����
	/// </summary>
	Abilitys _Abilitys;
	

	SystemParam _SystemParam;
};

struct Item//������� 
{
	// �������� ��������
	std::string NameItem;
	//���������� ����� ���� (�������� �������������)
	int NumberItem;
	//���������� ����� ���� (��������� �������������)
	std::string NameNumberItem;

	int Int_Rare;// ����� �������� (1 - �������, 2 - �� �������, 3 - ������, 4 - �����������)
	std::string Name_Rare_Item; // ����� �������� (��������� �������������) 

	// ���������� ����� ������������� ������
	int quantity;

	// ������� � ����� ��� ���
	bool InHand = false;
};

class Character
{
public:

	Character();//�����������
	~Character();

	Character(const Item& Item_attr);

	//�������� �����
	Character(const PlayerAttributes& attr);
	// ������ �����
	Character(const PlayerSet& attr_Set);

	// ���������
	//Character(const _PlayerInventory& _Inventory);

	// ����� ������������� ��� ������ ������
	void PrintCreatStatsP();

	// ����� ������ ���������
	void PrintStats();
	// ����� ������ ������
	void PrintSetStats();      //  ��������� �����
	 
	// ������� ����������� ���������� ���������
	PlayerAttributes GetAttributesP() const;
	// ������ ������
	/*
	_AttributesPlayer warriorAttributes = {};
	warriorAttributes.P_Hp = ???;
	*/

	// ������� ����������� ���������� ������
	PlayerSet GetSetAttributes() const;
	// ������ ������
	/*
	_Player_Set Set = {};
	Set.name_Set = ??? ;
	*/

	/// <summary>
	/// ���� ���������
	/// </summary>
	void Player_Windows();

	// ������������� ������������� �� ����� ������
	void Restore_attributes();

	// ������� ����������� ������ �������������
	void SimbolOutAttr();                                // �������� ������� ������

	/// <summary>
	/// ������� ��������� �
	/// </summary>
	/// <param name=" 0 - �������� ���������, �!= 0 ������� �������� (�) � ���������� ������� �� �"></param>
	int Get_player_position_X(int x = 0);
	
	
	/// <summary>
	/// ������� ��������� Y
	/// </summary>
	/// <param name=" 0 - �������� ���������, �!= 0 ������� �������� (�) � ���������� ������� �� �"></param>
	int Get_player_position_Y(int y = 0);  
	
	// ������� ���
	int Get_Int_World();
	///������� ������ � ������� ����������
	bool Get_File_save(bool save);


	// ������� ��������� ��������� ���������
	void Move(int direction);

	// �������� ��������� �� ������ �� ���������
	void CreateInventiry(int Option);
	
	// ������� ���������
	void Inventory();

	//����� ������������ ��������� �� �� ������
	void OutNameItem(int namberItem);

	// ���������� ��������� � ���������
	void InItemsInventory(int namberItem = 0, int quantity = 0, int page = 0);

	/// <summary>
	/// ����� ��������� �� ���������
	/// </summary>
	void OutItemsInventory(int namberItem);

public:
	 
	Item Item_attr;/// <summary>��������� � ����������� � ��������</summary>

	PlayerAttributes _PlayerAttributes;

	// ������� �������� ��������� (0 - �����; 1 - ���������� ���������; 2 - ���������� � �������� ��������)
	int Option;
	
private:

	Input_registration input_registration;



};