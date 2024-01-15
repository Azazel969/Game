#pragma once
#include <string>
#include "Input_registration.h"



struct PlayerInventory
{
	int many = 0;/// <summary>Деньги</summary>

	// размер инвентaря
	static constexpr int inventoryPage = 4; // страница
	static constexpr int width = 10; // ширина
	static constexpr int height = 10; // высота

	bool resetInventory;

	int inventory[inventoryPage][width][height];

	int quantity[inventoryPage][width][height];

	/// <summary>
	/// Номер вещи в слоте инвентаря
	/// </summary>
	int namberItem;

	/// <summary>
	/// Количество вещей в слоте инвентаря
	/// </summary>
	int quantityItem;

	/// <summary>
	/// Страница инвентаря (зелья, броня, oружие, бижутерия)
	/// </summary>
	int page;
};

struct PlayerSet
{
	std::string name_Armor;// броня
	int int_Armor;// номер предмета
	float Armor_Mod; // модификатор брони
	bool bl_Armor_mod = false;// есть/нет

	std::string name_Weapon;// оружие
	int int_Weapon;// номер предмета
	float Weapon_Mod; // модификатор оружия
	bool bl_Weapon_mod = false;// есть/нет

	std::string str_name_jewelry;//бижутерия
	int int_jewelry;// номер предмета
	bool bl_jewelry = false;// есть/нет
};

struct Skills
{
	std::string Name_skill_1 = " Неспуль"; // название навыка 1
	int Int_skill_1 = 0; // номер навыка 1
	int Int_levl_skill_1 = 1; // уровень навыка
	int Int_Xp_skill_1 = 1;
	std::string Description_skill_1 = " Позволяет драться с низкой выносливотью"; // описание навыка 1
	
	std::string Name_skill_2 = " Племенной бычок"; 
	int Int_skill_2 = 0; 
	int Int_levl_skill_2 = 1;
	int Int_Xp_skill_2 = 1;
	std::string Description_skill_2 = " +Х хп"; 

	std::string Name_skill_3 = " Тихая поступь";
	int Int_skill_3 = 0;
	int Int_levl_skill_3 = 1;
	int Int_Xp_skill_3 = 1;
	std::string Description_skill_3 = " Двигаясь тише вы привлекаете меньше внимания";
};

struct Abilitys
{
	std::string Name_ability_1 = " Бросок факела"; // название способности 1
	int Int_ability_1 = 0; // номер способности 1
	int Int_levl_ability_1 = 1; // уровень способности 1
	int Int_Xp_ability_1 = 1;
	std::string Description_ability_1 = " Бросаете факел во врага ослепляя его. У вас появляется возможность спрятаться от врага"; // описание способности 1

	std::string Name_ability_2 = " Боевой клич";
	int Int_ability_2 = 0;
	int Int_levl_ability_2 = 1;
	int Int_Xp_ability_2 = 1;
	std::string Description_ability_2 = " С яростным воплем бросаетесь на врага. На 1 ход повышает урон на Х кол-во"; 

	std::string Name_ability_3 = " Боевая тойка";
	int Int_ability_3 = 0;
	int Int_levl_ability_3 = 1;
	int Int_Xp_ability_3 = 1;
	std::string Description_ability_3 = " В стойке вам проще отбить удар. На 1 ход повышает защиту на Х кол-во";

};

struct Position
{
	int x;// position x
	int y;// position y

	/// <summary>
	/// осуществляется переход или нет
	/// </summary>
	bool Transfer_player = false;

	int Int_World; /// <summary>на какой карте находится (число)</summary>

	bool returns_village = false; /// <summary>возвращается игрок в поселение или нет</summary>

	std::string World; // на какой карте находится
};

struct StorageAttributesg
{
	// добавленние эталонных атрибутов
	void Add_standart_param();

	int St_Hp;
	int St_Mana;
	int St_Armor;
	int St_Attack;
	int St_Stamina;
	int St_Avoid;
};

/// <summary>
/// структура с информацией о системных параметрах
/// </summary>
struct SystemParam
{
	int int_name_Class;// числовое имя класса

	bool Overview = false; // обзор

	bool Auto_input = false;// авто ввод

	// уведомление связанное c характеристиками персонажа
	bool Alert = false;

	/// <summary>
	/// игара загружается из сохранения
	/// </summary>
	bool Load_save = false;

	/// <summary>
	/// структура с информацией об этолонном значении характеристик персонажа
	/// </summary>
	StorageAttributesg _StorageAttributes;

	/// <summary>
	/// струкрура с информацией о позиции героя
	/// </summary>
	Position _Position;
};

/// <summary>
/// структура с информацией о герое
/// </summary>
struct PlayerAttributes
{
	// основные харки
	std::string name_Character = "DEF";// ник
	std::string name_Class;
	int P_Levl;
	int P_XP;
	int P_Hp;
	int P_Mana;
	int P_armor;
	float P_attack;
	int P_avoid; // уклонение
	int P_stamina; // выносливость

	// доп. харки
	int P_Expenditure_Attack; // расход выносливости при атаке
	int P_Expenditure_Escape; // расход выносливости при побеге

	
	/// <summary>
	/// структура с информацией об инвентаре героя
	/// </summary>
	PlayerInventory _Inventory;

	/// <summary>
	/// структура с информицией о надетых на герое вещей
	/// </summary>
	PlayerSet _PlayerSet;

	/// <summary>
	/// структура с информацоей об навыках героя
	/// </summary>
	Skills _Skills;

	/// <summary>
	/// структура с информацией об способностях героя
	/// </summary>
	Abilitys _Abilitys;
	

	SystemParam _SystemParam;
};

struct Item//предмет 
{
	// название предмета
	std::string NameItem;
	//порядковый номер вещи (числовое представление)
	int NumberItem;
	//порядковый номер вещи (словесное представление)
	std::string NameNumberItem;

	int Int_Rare;// класс редкости (1 - обычная, 2 - не обычная, 3 - редкая, 4 - легендарная)
	std::string Name_Rare_Item; // класс редкости (словесное представление) 

	// количество вещей определенного номера
	int quantity;

	// предмет в руках или нет
	bool InHand = false;
};

class Character
{
public:

	Character();//конструктор
	~Character();

	Character(const Item& Item_attr);

	//персонаж статы
	Character(const PlayerAttributes& attr);
	// Одежда статы
	Character(const PlayerSet& attr_Set);

	// инвентарь
	//Character(const _PlayerInventory& _Inventory);

	// Вывод характеристик при выборе класса
	void PrintCreatStatsP();

	// Вывод статов персонажа
	void PrintStats();
	// Вывод статов одежды
	void PrintSetStats();      //  придумать статы
	 
	// функция возвращения аттрибутов персонажа
	PlayerAttributes GetAttributesP() const;
	// пример записи
	/*
	_AttributesPlayer warriorAttributes = {};
	warriorAttributes.P_Hp = ???;
	*/

	// Функция возвращения аттрибутов одежды
	PlayerSet GetSetAttributes() const;
	// пример записи
	/*
	_Player_Set Set = {};
	Set.name_Set = ??? ;
	*/

	/// <summary>
	/// окно персонажа
	/// </summary>
	void Player_Windows();

	// востоновление характеристик во время отдыха
	void Restore_attributes();

	// Функция символьного вывода хараткеристик
	void SimbolOutAttr();                                // написать функцию вывода

	/// <summary>
	/// Позиция персонажа Х
	/// </summary>
	/// <param name=" 0 - получить заначение, х!= 0 запишет значение (х) в переменную позиции по х"></param>
	int Get_player_position_X(int x = 0);
	
	
	/// <summary>
	/// Позиция персонажа Y
	/// </summary>
	/// <param name=" 0 - получить заначение, у!= 0 запишет значение (у) в переменную позиции по у"></param>
	int Get_player_position_Y(int y = 0);  
	
	// текущий мир
	int Get_Int_World();
	///лучение данных о наличии сохранения
	bool Get_File_save(bool save);


	// функция изменения координат персонажа
	void Move(int direction);

	// Создание инвентаря по одному из вариантов
	void CreateInventiry(int Option);
	
	// Функция инвентаря
	void Inventory();

	//Вывод наименования предметов по их номеру
	void OutNameItem(int namberItem);

	// Добавление предметов в инвентарь
	void InItemsInventory(int namberItem = 0, int quantity = 0, int page = 0);

	/// <summary>
	/// Вывод предметов из инвентаря
	/// </summary>
	void OutItemsInventory(int namberItem);

public:
	 
	Item Item_attr;/// <summary>структура с информацией о предмете</summary>

	PlayerAttributes _PlayerAttributes;

	// Вариант создания инвентаря (0 - ресет; 1 - объявление элементов; 2 - заполнение в тестовов варианте)
	int Option;
	
private:

	Input_registration input_registration;



};