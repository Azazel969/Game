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
	// варианты в меню
	void Options_actions(bool BL_Drop_Item, int Stamina, bool Alert, bool Overview, int Int_World, bool Bl_Save, bool Bl_Passage, bool return_village);

	bool Drop_item = false;// можно взять вещь из мира

	bool Alert_attr = false;// уведомление о изменении характеристик

	bool No_travel = false;// нет возможности путешествовать

	bool Travel = false;// путешествовать

	bool Fire_off = false;// потушить факел

	bool Fire_on = false;// зажечь факел

	bool Load_save = false;// сохранение

	bool Passage = false;// возможен переход на другую карту

	bool return_village = false;// возвращение в поселение

	bool Menu = false;// меню

};


class Game
{
public:

	Game();
	void Go();

	// закрытие игры при смерти персонажа
	bool GameStatus();

	/// <summary>
	/// Игровое меню
	/// </summary>
	void GameMenu();

	// создание врага
	//Enemy CreateEnemy(int NumberEnemy);
	//Game(const ItemInHand& Item_attr);
	
private:

	// обновление мира
	void Update();
	// функция отрисовки
	void Render();
	// загрузка 
	void Game_loading();
	// метод воскрешения персонажа (игра заново)
	bool PlayerRebirth();

	// главное меню
	void Game_print_MainMenu();

	/// <summary>
	/// Пункт меню - новая игра
	/// </summary>
	void New_game();

	/// <summary>
	/// Пункт меню - загрузка игры
	/// </summary>
	/// <param name="объект класса Character"></param>
	/// <param name="объект класса Files"></param>
	void Loading_save(Character& player, Files& files);

	/// <summary>
	/// Пункт меню сохранение игры
	/// </summary>
	void Save_game(Character& player);

	/// <summary>
	/// Пункт меню - настройки
	/// </summary>
	void Settings();

	/// <summary>
	/// Пункт меню - разработчики
	/// </summary>
	void Developers();

	// режим игры
	void Game_mode();

	void Mode_change(Input_registration &input_registration, bool Mode);

	// изменение переменной battleRan
	void Bl_Battle_val(Battle& bat, int Mode);

	/// <summary>
	/// создание персонажа или его загрузка из сохранения
	/// </summary>
	void Player_initialization(Character& player, Character &tempCharacter, Map& map);

	// создание ника
	void Nickname();

	// игровой процесс
	void Game_print_Gameplay(Character& player);
	// нoмер класса
	char GetUserInput(char UserIn);
	// создание персонажа
	Character CreateCharacter(Character& player, char UserIn = '0');

private:

	bool test = false;
	
	bool bestiaryRan = false;

	// выбор номера персонажа
	char namberClass = 0;

public:

	// отслеживание создания персонажа 
	bool isGameplayStarted = false;

	// отслеживание начала игры
	bool isGameStarted = false;

	// переменная выхода из игры (true - продолжение игры; false - завершение игры)
	bool isGameRunnig = true;

	//отслеживание смерти игрока
	bool isPlayerDie = false;

	// настройки в игровом меню
	bool settings = false;

private:

	Character player; /// <summary>Объект: Игровой персонаж </summary>

	Character tempCharacter; /// <summary> Временный персонаж (до подтверждения выбора)</summary>

	Enemy enemy; /// <summary>Объект: Враг </summary>

	Enemy Bestiary_enemy; /// <summary>Переменная для сохранения монстров в бестиарии</summary>

	Battle bat; /// <summary>Объект: Бой </summary>

	NPS nps; // НПС деревни

	Map map; /// <summary>Объект: Карта </summary>

	Input_registration input_registration;/// <summary>Объект: Оброботчик нажатия </summary>

	Files files; /// <summary>Объект: Сохранение</summary>

	Actions Actions;
};




