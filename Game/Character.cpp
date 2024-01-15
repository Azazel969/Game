#include "Character.h"
#include <iostream>
//#include "Game.h"
#include <Windows.h>





Character::Character()
{

}

Character::~Character()
{
}

Character::Character(const Item& Item_attr)
	:
	Item_attr(Item_attr)
{
}

Character::Character(const PlayerAttributes& _PlayerAttributes)
	:
	_PlayerAttributes(_PlayerAttributes)
{
}

void Character::PrintCreatStatsP()
{
	std::cout << " Вы выбрали: " << std::endl;
	std::cout << std::endl;
	std::cout << _PlayerAttributes.name_Class << "а " << std::endl;
	std::cout << std::endl;
	std::cout << "* Характеристики *" << std::endl;
	std::cout << std::endl;
	std::cout << " Здоровье: " << _PlayerAttributes.P_Hp << std::endl;
	std::cout << " Мана: " << _PlayerAttributes.P_Mana << std::endl;
	std::cout << " Броня: " << _PlayerAttributes.P_armor << std::endl;
	std::cout << " Атака: " << _PlayerAttributes.P_attack << std::endl;
	std::cout << " Атака: " << _PlayerAttributes.P_attack << std::endl;
	std::cout << " Уклонение: " << _PlayerAttributes.P_avoid << std::endl;
	std::cout << " Выносливость: " << _PlayerAttributes.P_stamina << std::endl;
	std::cout << std::endl;
	std::cout << "* Дополнительные характеристики *" << std::endl;
	std::cout << std::endl;
	std::cout << " Расход выносливости при атаке: " << _PlayerAttributes.P_Expenditure_Attack << std::endl;
	std::cout << " Расход выносливости при побеге: " << _PlayerAttributes.P_Expenditure_Escape << std::endl;
	std::cout << std::endl;

}

void Character::PrintStats()
{
	std::cout << std::endl;
	std::cout << " Имя: " << _PlayerAttributes.name_Character << std::endl;
	std::cout << " Уровень: " << _PlayerAttributes.P_Levl << std::endl;
	std::cout << " Класс: " << _PlayerAttributes.name_Class << std::endl;
	std::cout << std::endl;
	std::cout << "* Характеристики *" << std::endl;
	std::cout << std::endl;
	std::cout << " Здоровье: " << _PlayerAttributes.P_Hp << std::endl;
	std::cout << " Мана: " << _PlayerAttributes.P_Mana << std::endl;
	std::cout << " Броня: " << _PlayerAttributes.P_armor << std::endl;
	std::cout << " Атака: " << _PlayerAttributes.P_attack << std::endl;
	std::cout << " Уклонение: " << _PlayerAttributes.P_avoid << std::endl;
	std::cout << " Выносливость: " << _PlayerAttributes.P_stamina << std::endl;
	std::cout << std::endl;
	std::cout << "* Дополнительные характеристики *" << std::endl;
	std::cout << std::endl;
	std::cout << " Расход выносливости при атаке: " << _PlayerAttributes.P_Expenditure_Attack << std::endl;
	std::cout << " Расход выносливости при побеге: " << _PlayerAttributes.P_Expenditure_Escape << std::endl;
	std::cout << std::endl;
}

void Character::PrintSetStats()
{
//	std::cout << std::endl;
//	std::cout << set_attr.name_Set << std::endl;
//	std::cout << std::endl;
//	std::cout << "* Характеристики *" << std::endl;
//	std::cout << std::endl;
//	std::cout << " Здоровье: " << set_attr.name_Set << std::endl;
//	std::cout << " Мана: " << set_attr.name_Set << std::endl;
//	std::cout << " Броня: " << set_attr.name_Set << std::endl;
//	std::cout << " Атака: " << set_attr.name_Set << std::endl;
//	std::cout << " Уклонение: " << set_attr.name_Set << std::endl;
//	std::cout << " Выносливость: " << set_attr.name_Set << std::endl;
//	std::cout << std::endl;
}

PlayerAttributes Character::GetAttributesP() const
{
	return _PlayerAttributes;
}

PlayerSet Character::GetSetAttributes() const
{
	return _PlayerAttributes._PlayerSet;
}

void Character::Restore_attributes()
{





}

void Character::Player_Windows()
{
	input_registration.Auto_input_mod = _PlayerAttributes._SystemParam.Auto_input;
	char In = NULL;
	bool Bl_while = true;

	do
	{
		system("CLS");
		std::cout << "\n Окно персонажа \n" << std::endl;
		std::cout << "\t" << _PlayerAttributes.name_Character << std::endl;
		std::cout << "\n *** Характеристики ***" << std::endl;

		std::cout << std::endl;
		std::cout << " Уровень: " << _PlayerAttributes.P_Levl << std::endl;
		std::cout << " Класс: " << _PlayerAttributes.name_Class << std::endl;
		std::cout << std::endl;

		std::cout << std::endl;
		std::cout << " Здоровье: " << _PlayerAttributes.P_Hp << std::endl;
		std::cout << " Мана: " << _PlayerAttributes.P_Mana << std::endl;
		std::cout << " Броня: " << _PlayerAttributes.P_armor << std::endl;
		std::cout << " Атака: " << _PlayerAttributes.P_attack << std::endl;
		std::cout << " Уклонение: " << _PlayerAttributes.P_avoid << std::endl;
		std::cout << " Выносливость: " << _PlayerAttributes.P_stamina << std::endl;
		std::cout << std::endl;
		std::cout << "** Дополнительные характеристики **" << std::endl;
		std::cout << std::endl;
		std::cout << " Расход выносливости при атаке: " << _PlayerAttributes.P_Expenditure_Attack << std::endl;
		std::cout << " Расход выносливости при побеге: " << _PlayerAttributes.P_Expenditure_Escape << std::endl;
		std::cout << std::endl;

		if (_PlayerAttributes.P_stamina <= 5)
		{
			std::cout << " Отдохнуть(S)" << std::endl;
		}
		std::cout << " Инвентарь(I)" << std::endl;
		std::cout << " Назад(B)" << std::endl;

		In = input_registration.Click_tracking(In);

		if (In == 'S' || In == 's')
		{
			//////////
			std::cout << " Нет функционала" << std::endl;
			system("pause");
			//////////
		}
		else if (In == 'I' || In == 'i')
		{
			bool work = true;
			do
			{
				system("CLS");

				Inventory();

				std::cout << " Использовать предмет (E)" << std::endl;
				std::cout << " Назад(B)" << std::endl;

				In = input_registration.Click_tracking(In);

				if (In == 'E' || In == 'e')
				{
					//////////
					std::cout << " Нет функционала" << std::endl;
					system("pause");
					//////////
				}
				else if (In == 'B' || In == 'b')
				{
					work = false;
				}

			} while (work);
			
		}
		else if (In == 'B' || In == 'b')
		{
			Bl_while = false;
		}

	} while (Bl_while);
}

void Character::SimbolOutAttr()
{







}

int Character::Get_player_position_X(int x)
{
	if (x == 0)
	{
		return _PlayerAttributes._SystemParam._Position.x;
	}
	else
	{
		_PlayerAttributes._SystemParam._Position.x = x;
	}
}

int Character::Get_player_position_Y(int y)
{
	if (y == 0)
	{
		return _PlayerAttributes._SystemParam._Position.y;
	}
	else
	{
		_PlayerAttributes._SystemParam._Position.y = y;
	}
}

int Character::Get_Int_World()
{
	return _PlayerAttributes._SystemParam._Position.Int_World;
}

bool Character::Get_File_save(bool save)
{
	_PlayerAttributes._SystemParam.Load_save = save;

	return _PlayerAttributes._SystemParam.Load_save;
}

void Character::CreateInventiry(int Option)  
{

	if (Option == 0)// ресет
	{
		for (int page = 0; page < _PlayerAttributes._Inventory.inventoryPage; page++)
		{
			for (int b = 0; b < _PlayerAttributes._Inventory.width; b++)
			{
				for (int c = 0; c < _PlayerAttributes._Inventory.height; c++)
				{
					if (_PlayerAttributes._Inventory.quantity[page][b][c] = !0 && _PlayerAttributes._Inventory.inventory[page][b][c] != 0)
					{
						_PlayerAttributes._Inventory.quantity[page][b][c] = 0;
						_PlayerAttributes._Inventory.inventory[page][b][c] = 0;
					}
				}
			}
		}
	}
	else if (Option == 1) // объявление элементов
	{
		for (int a = 0; a < _PlayerAttributes._Inventory.inventoryPage; a++)
		{
			for (int b = 0; b < _PlayerAttributes._Inventory.width; b++)
			{
				for (int c = 0; c < _PlayerAttributes._Inventory.height; c++)
				{
					if (_PlayerAttributes._Inventory.quantity[a][b][c] < 0 && _PlayerAttributes._Inventory.inventory[a][b][c] < 0)
					{
						_PlayerAttributes._Inventory.quantity[a][b][c] = 0;
						_PlayerAttributes._Inventory.inventory[a][b][c] = 0;
					}
				}
			}
		}
	}
	else if (Option == 2) // заполнение в тестовов варианте
	{
		bool While = true;
		bool If = true;
		int i = 5;

		while (While)
		{
			bool Inventory = false;
			////////////////////////////////////////////////////////////
			Sleep(200);
			srand(time(0) + i);
			_PlayerAttributes._Inventory.namberItem = 1 + (rand() % 400);
			Sleep(200);
			srand(time(0) + i + 4);
			_PlayerAttributes._Inventory.quantityItem = 1 + (rand() % 100);
			
			if (If)
			{
				_PlayerAttributes._Inventory.page = 0;
				If = false;
			}
			else if (!If)
			{
				_PlayerAttributes._Inventory.page = 1;
				If = true;
			}
			
			////////////////////////////////////////////////////////////
			for (int a = 0; a < _PlayerAttributes._Inventory.inventoryPage; a++)
			{
				if (a == _PlayerAttributes._Inventory.page)
				{
					for (int b = 0; b < _PlayerAttributes._Inventory.width; b++)
					{
						for (int c = 0; c < _PlayerAttributes._Inventory.height; c++)
						{
							if (_PlayerAttributes._Inventory.inventory[a][b][c] == _PlayerAttributes._Inventory.namberItem)
							{
								_PlayerAttributes._Inventory.quantityItem = _PlayerAttributes._Inventory.quantityItem + _PlayerAttributes._Inventory.quantity[a][b][c];

								_PlayerAttributes._Inventory.quantity[a][b][c] = _PlayerAttributes._Inventory.quantityItem;

								Inventory = true;

								break;
							}
							else if (_PlayerAttributes._Inventory.inventory[a][b][c] == 0 )
							{
								_PlayerAttributes._Inventory.inventory[a][b][c] = _PlayerAttributes._Inventory.namberItem;

								_PlayerAttributes._Inventory.quantity[a][b][c] = _PlayerAttributes._Inventory.quantityItem;

								Inventory = true;

								break;
							}
						}
						if (Inventory)
						{
							break;
						}
					}
					if (Inventory)
					{
						break;
					}
				}

				if (Inventory)
				{
					break;
				}
			}

			/////////////////////////////////////////////


			i++;

			if (i == 49)
			{
				While = false;
			}

			////////////////////////////////////////////////
		}
	}
}   

void Character::OutNameItem(int namberItem)
{
	// зелья(001-099), броня(101-199), оружие(201-299), бижутерия(301-399)

	switch (namberItem)
	{
	case 1:
	{
		Item_attr.NameItem = " Зелье маны (маленькое) "; // зелья
		Item_attr.NumberItem = 1;
		Item_attr.NameNumberItem = " (№1)"; 
		Item_attr.Int_Rare = 1;
		Item_attr.Name_Rare_Item = " слабое";
	}
	break;
	case 2:
	{
		Item_attr.NameItem = " Зелье здоровья (маленькое) ";
		Item_attr.NumberItem = 2;
		Item_attr.NameNumberItem = " (№2)";
		Item_attr.Int_Rare = 1;
		Item_attr.Name_Rare_Item = " слабое";
	}
	break;
	case 3:
	{
		Item_attr.NameItem = " Зелье выносливости (маленькое) ";
		Item_attr.NumberItem = 3;
		Item_attr.NameNumberItem = " (№3)";
		Item_attr.Int_Rare = 1;
		Item_attr.Name_Rare_Item = " слабое";
	}
	break;
	case 4:
	{
		Item_attr.NameItem = " Зелье урона (маленькое) ";
		Item_attr.NumberItem = 4;
		Item_attr.NameNumberItem = " (№4)";
		Item_attr.Int_Rare = 1;
		Item_attr.Name_Rare_Item = " слабое";
	}
	break;
	case 5:
	{
		Item_attr.NameItem = " Зелье невидемости (маленькое) ";
		Item_attr.NumberItem = 5;
		Item_attr.NameNumberItem = " (№5)";
		Item_attr.Int_Rare = 1;
		Item_attr.Name_Rare_Item = " слабое";
	}
	break;
	case 6:
	{
		Item_attr.NameItem = " Зелье ловкости (маленькое) "; 
		Item_attr.NumberItem = 6;
		Item_attr.NameNumberItem = " (№6)";
		Item_attr.Int_Rare = 1;
		Item_attr.Name_Rare_Item = " слабое";
	}
	break;
	case 7:
	{
		Item_attr.NameItem = " Зелье маны (среднее) "; 
		Item_attr.NumberItem = 7;
		Item_attr.NameNumberItem = " (№7)";
		Item_attr.Int_Rare = 2;
		Item_attr.Name_Rare_Item = " обычное";
	}
	break;
	case 8:
	{
		Item_attr.NameItem = " Зелье здоровья (среднее) ";
		Item_attr.NumberItem = 8;
		Item_attr.NameNumberItem = " (№8)";
		Item_attr.Int_Rare = 2;
		Item_attr.Name_Rare_Item = " обычное";
	}
	break;
	case 9:
	{
		Item_attr.NameItem = " Зелье выносливости (среднее) ";
		Item_attr.NumberItem = 9;
		Item_attr.NameNumberItem = " (№9)";
		Item_attr.Int_Rare = 2;
		Item_attr.Name_Rare_Item = " обычное";
	}
	break;
	case 10:
	{
		Item_attr.NameItem = " Зелье урона (среднее) ";
		Item_attr.NumberItem = 10;
		Item_attr.NameNumberItem = " (№10)";
		Item_attr.Int_Rare = 2;
		Item_attr.Name_Rare_Item = " обычное";
	}
	break;
	case 11:
	{
		Item_attr.NameItem = " Зелье невидемости (среднее) ";
		Item_attr.NumberItem = 11;
		Item_attr.NameNumberItem = " (№11)";
		Item_attr.Int_Rare = 2;
		Item_attr.Name_Rare_Item = " обычное";
	}
	break;
	case 12:
	{
		Item_attr.NameItem = " Зелье ловкости (среднее) ";
		Item_attr.NumberItem = 12;
		Item_attr.NameNumberItem = " (№12)";
		Item_attr.Int_Rare = 2;
		Item_attr.Name_Rare_Item = " обычное";
	}
	break;
	case 13:
	{
		Item_attr.NameItem = " Зелье маны (большое) ";
		Item_attr.NumberItem = 13;
		Item_attr.NameNumberItem = " (№13)";
		Item_attr.Int_Rare = 3;
		Item_attr.Name_Rare_Item = " сильное";
	}
	break;
	case 14:
	{
		Item_attr.NameItem = " Зелье здоровья (большое) ";
		Item_attr.NumberItem = 14;
		Item_attr.NameNumberItem = " (№14)";
		Item_attr.Int_Rare = 3;
		Item_attr.Name_Rare_Item = " сильное";
	}
	break;
	case 15:
	{
		Item_attr.NameItem = " Зелье выносливости (большое) ";
		Item_attr.NumberItem = 15;
		Item_attr.NameNumberItem = " (№15)";
		Item_attr.Int_Rare = 3;
		Item_attr.Name_Rare_Item = " сильное";
	}
	break;
	case 16:
	{
		Item_attr.NameItem = " Зелье урона (большое) ";
		Item_attr.NumberItem = 16;
		Item_attr.NameNumberItem = " (№16)";
		Item_attr.Int_Rare = 3;
		Item_attr.Name_Rare_Item = " сильное";
	}
	break;
	case 17:
	{
		Item_attr.NameItem = " Зелье невидемости (большое) ";
		Item_attr.NumberItem = 17;
		Item_attr.NameNumberItem = " (№17)";
		Item_attr.Int_Rare = 3;
		Item_attr.Name_Rare_Item = " сильное";
	}
	break;
	case 18:
	{
		Item_attr.NameItem = " Зелье ловкости (большое) ";   //////////////////////////////////////
		Item_attr.NumberItem = 18;
		Item_attr.NameNumberItem = " (№18)";
		Item_attr.Int_Rare = 3;
		Item_attr.Name_Rare_Item = " сильное";
	}
	break;
	case 101:
	{
		Item_attr.NameItem = " Броня кальчужная ";// броня 
		Item_attr.NumberItem = 101;
		Item_attr.NameNumberItem = " (№101)"; 
		Item_attr.Int_Rare = 2;
		Item_attr.Name_Rare_Item = " не обычная";
	}
	break;
	case 102:
	{
		Item_attr.NameItem = " Броня чешуйчатая ";
		Item_attr.NumberItem = 102;
		Item_attr.NameNumberItem = " (№102)";
		Item_attr.Int_Rare = 3;
		Item_attr.Name_Rare_Item = " редкая";
	}
	break;
	case 103:
	{
		Item_attr.NameItem = " Броня латная ";
		Item_attr.NumberItem = 103;
		Item_attr.NameNumberItem = " (№103)"; 
		Item_attr.Int_Rare = 4;
		Item_attr.Name_Rare_Item = " легендарная";
	}
	break;
	case 104:
	{
		Item_attr.NameItem = " Роба послушника ";
		Item_attr.NumberItem = 104;
		Item_attr.NameNumberItem = " (№104)";
		Item_attr.Int_Rare = 1;
		Item_attr.Name_Rare_Item = " обычная";
	}
	break;
	case 105:
	{
		Item_attr.NameItem = " Роба ученика ";
		Item_attr.NumberItem = 105;
		Item_attr.NameNumberItem = " (№105)"; 
		Item_attr.Int_Rare = 1;
		Item_attr.Name_Rare_Item = " обычная";
	}
	break;
	case 106:
	{
		Item_attr.NameItem = " Мантия мага ";
		Item_attr.NumberItem = 106;
		Item_attr.NameNumberItem = " (№106)"; 
		Item_attr.Int_Rare = 3;
		Item_attr.Name_Rare_Item = " не обычная";
	}
	break;
	case 107:
	{
		Item_attr.NameItem = " Мантия мастера-мага ";
		Item_attr.NumberItem = 107;
		Item_attr.NameNumberItem = " (№107)"; 
		Item_attr.Int_Rare = 3;
		Item_attr.Name_Rare_Item = " редкая";
	}
	break;
	case 108:
	{
		Item_attr.NameItem = " Мантия мага-магистра ";
		Item_attr.NumberItem = 108;
		Item_attr.NameNumberItem = " (№108)";
		Item_attr.Int_Rare = 4;
		Item_attr.Name_Rare_Item = " легендарная";
	}
		break;
	case 109:
	{
		Item_attr.NameItem = " Мантия архимага ";
		Item_attr.NumberItem = 109;
		Item_attr.NameNumberItem = " (№109)"; 
		Item_attr.Int_Rare = 4;
		Item_attr.Name_Rare_Item = " легендарная";
	}
	break;
	case 110:
	{
		Item_attr.NameItem = " Одежда охотника ";
		Item_attr.NumberItem = 110;
		Item_attr.NameNumberItem = " (№110)"; 
		Item_attr.Int_Rare = 1;
		Item_attr.Name_Rare_Item = " обычная";
	}
	break;
	case 111:
	{
		Item_attr.NameItem = " Одежда егеря ";
		Item_attr.NumberItem = 111;
		Item_attr.NameNumberItem = " (№111)";
		Item_attr.Int_Rare = 2;
		Item_attr.Name_Rare_Item = " не обычная";
	}
	break;
	case 112:
	{
		Item_attr.NameItem = " Одежда следопыта ";
		Item_attr.NumberItem = 112;
		Item_attr.NameNumberItem = " (№112)";
		Item_attr.Int_Rare = 3;
		Item_attr.Name_Rare_Item = " редкая";
	}
	break;
	case 113:
	{
		Item_attr.NameItem = " Кожанная броня ";
		Item_attr.NumberItem = 113;
		Item_attr.NameNumberItem = " (№113)";
		Item_attr.Int_Rare = 1;
		Item_attr.Name_Rare_Item = " обычная";
	}
	break;
	case 114:
	{
		Item_attr.NameItem = " Накидка повелителя зверей ";////////////////////////////
		Item_attr.NumberItem = 114;
		Item_attr.NameNumberItem = " (№114)"; 
		Item_attr.Int_Rare = 4;
		Item_attr.Name_Rare_Item = " легендарная";
	}
	break;
	case 201:
	{
		Item_attr.NameItem = " Нож ";
		Item_attr.NumberItem = 201;
		Item_attr.NameNumberItem = " (№201)"; 
		Item_attr.Int_Rare = 1;
		Item_attr.Name_Rare_Item = " обычный";
	}
	break;
	case 202:
	{
		Item_attr.NameItem = " Кинжал ";
		Item_attr.NumberItem = 202;
		Item_attr.NameNumberItem = " (№202)";
		Item_attr.Int_Rare = 2;
		Item_attr.Name_Rare_Item = " не обычный";
	}
	break;
	case 203:
	{
		Item_attr.NameItem = " Короткий меч ";
		Item_attr.NumberItem = 203;
		Item_attr.NameNumberItem = " (№203)"; 
		Item_attr.Int_Rare = 3;
		Item_attr.Name_Rare_Item = " редкий";
	}
	break;
	case 204:
	{
		Item_attr.NameItem = " Длинный меч ";
		Item_attr.NumberItem = 204;
		Item_attr.NameNumberItem = " (№204)"; 
		Item_attr.Int_Rare = 4;
		Item_attr.Name_Rare_Item = " легендарный";
	}
	break;
	case 205:
	{
		Item_attr.NameItem = " Палочка ученика ";
		Item_attr.NumberItem = 205;
		Item_attr.NameNumberItem = " (№205)";
		Item_attr.Int_Rare = 1;
		Item_attr.Name_Rare_Item = " обычная";
	}
	break;
	case 206:
	{
		Item_attr.NameItem = " Камень силы(кристализированныя мана) ";
		Item_attr.NumberItem = 206;
		Item_attr.NameNumberItem = " (№206)";
		Item_attr.Int_Rare = 2;
		Item_attr.Name_Rare_Item = " не обычный";
	}
	break;
	case 207:
	{
		Item_attr.NameItem = " Магический посох ";
		Item_attr.NumberItem = 207;
		Item_attr.NameNumberItem = " (№207)";
		Item_attr.Int_Rare = 3;
		Item_attr.Name_Rare_Item = " редкий";
	}
	break;
	case 208:
	{
		Item_attr.NameItem = " Гримуар(архимага/мастера) ";
		Item_attr.NumberItem = 208;
		Item_attr.NameNumberItem = " (№208)";
		Item_attr.Int_Rare = 4;
		Item_attr.Name_Rare_Item = " легендарный";
	}
	break;
	case 209:
	{
		Item_attr.NameItem = " Рогатка ";
		Item_attr.NumberItem = 209;
		Item_attr.NameNumberItem = " (№209)"; 
		Item_attr.Int_Rare = 1;
		Item_attr.Name_Rare_Item = " обычная";
	}
	break;
	case 210:
	{
		Item_attr.NameItem = " Праща ";
		Item_attr.NumberItem = 210;
		Item_attr.NameNumberItem = " (№210)";
		Item_attr.Int_Rare = 2;
		Item_attr.Name_Rare_Item = " не обычная";
	}
	break;
	case 211:
	{
		Item_attr.NameItem = " Лук ";
		Item_attr.NumberItem = 211;
		Item_attr.NameNumberItem = " (№211)";
		Item_attr.Int_Rare = 3;
		Item_attr.Name_Rare_Item = " редкий";
	}
	break;
	case 212:
	{
		Item_attr.NameItem = " Арбалет ";
		Item_attr.NumberItem = 212;
		Item_attr.NameNumberItem = " (№212)";
		Item_attr.Int_Rare = 4;
		Item_attr.Name_Rare_Item = " легендарный";
	}
	break;
	case 213:
	{
		Item_attr.NameItem = " Кастеты ";//////////////////////////////////////////////////
		Item_attr.NumberItem = 213;
		Item_attr.NameNumberItem = " (№213)"; 
		Item_attr.Int_Rare = 1;
		Item_attr.Name_Rare_Item = " обычная";
	}
	break;
	case 301:
	{
		Item_attr.NameItem = " Амулет ночного видения "; // Бижутерия 
		Item_attr.NumberItem = 301;
		Item_attr.NameNumberItem = " (№301)"; 
		Item_attr.Int_Rare = 3;
		Item_attr.Name_Rare_Item = " Редкий";
	}
	break;
	case 302:
	{
		Item_attr.NameItem = " Камень способностей "; // изменяет доступные способности
		Item_attr.NumberItem = 302;
		Item_attr.NameNumberItem = " (№302)";
		Item_attr.Int_Rare = 4;
		Item_attr.Name_Rare_Item = " легендарный";
	}
	break;
	case 303:
	{
		Item_attr.NameItem = " Камень навыков "; // изменяет доступные навыки
		Item_attr.NumberItem = 303;
		Item_attr.NameNumberItem = " (№303)";
		Item_attr.Int_Rare = 4;
		Item_attr.Name_Rare_Item = " легендарный";
	}
	break;
	case 304:
	{
		Item_attr.NameItem = " Самогон";
		Item_attr.NumberItem = 304;
		Item_attr.NameNumberItem = " (№304)";
		Item_attr.Int_Rare = 2;
		Item_attr.Name_Rare_Item = " не обычный";
	}
	break;
	case 305:
	{
		Item_attr.NameItem = " Факел";
		Item_attr.NumberItem = 305;
		Item_attr.NameNumberItem = " (№305)";
		Item_attr.Int_Rare = 1;
		Item_attr.Name_Rare_Item = " обычный";
	}
	break;

	default:
	
		break;
	}
}	

void Character::InItemsInventory(int namberItem, int quantity, int page)
{
	/*if (page == 10)
	{
		namberItem = _PlayerAttributes._InventoryS.namberItem;

		quantity = _PlayerAttributes._InventoryS.quantity;
	}*/

	bool Inventory = false;
	

	if (namberItem < 100)
	{
		page = 0; // зелья
	}
	else if (namberItem > 100 && namberItem < 200)
	{
		page = 1; // броня
	}
	else if (namberItem > 200 && namberItem < 300)
	{
		page = 2; // оружие
	}
	else if (namberItem > 300 && namberItem < 400)
	{
		page = 3; // бижутеря
	}

	for (int a = 0; a < _PlayerAttributes._Inventory.inventoryPage; a++)
	{
		if (a == page)
		{
			for (int b = 0; b < _PlayerAttributes._Inventory.width; b++)
			{
				for (int c = 0; c < _PlayerAttributes._Inventory.height; c++)
				{
					if (_PlayerAttributes._Inventory.inventory[a][b][c] == namberItem)
					{
						quantity = quantity + _PlayerAttributes._Inventory.quantity[a][b][c];

						_PlayerAttributes._Inventory.quantity[a][b][c] = quantity;

						Inventory = true;

						break;
					}
					else if (_PlayerAttributes._Inventory.inventory[a][b][c] == 0)
					{
						_PlayerAttributes._Inventory.inventory[a][b][c] = namberItem;

						_PlayerAttributes._Inventory.quantity[a][b][c] = quantity;

						Inventory = true;

						break;
					}
				}
				if (Inventory)
				{
					break;
				}
			}
			if (Inventory)
			{
				break;
			}
		}
		if (Inventory)
		{
			break;
		}
	}
}

void Character::OutItemsInventory(int namberItem)
{
	char in = ' ';
	int Out = 0;
	bool Raning = true;
	
	if (namberItem < 7)
	{
		_PlayerAttributes._Inventory.page = 0;
	}
	else if (namberItem > 6)
	{
		_PlayerAttributes._Inventory.page = 1;
	}
	
	while (Raning)
	{
		for (int a = 0; a < _PlayerAttributes._Inventory.inventoryPage; a++)
		{
			if (a == _PlayerAttributes._Inventory.page)
			{
				for (int b = 0; b < _PlayerAttributes._Inventory.width; b++)
				{
					for (int c = 0; c < _PlayerAttributes._Inventory.height; c++)
					{
						if (_PlayerAttributes._Inventory.inventory[a][b][c] == namberItem)
						{
							OutNameItem(_PlayerAttributes._Inventory.inventory[a][b][c]);
							std::cout << " Выбранный предмет: "; std::cout << Item_attr.NameItem << std::endl;
							std::cout << " Количество в инвентаре: " << _PlayerAttributes._Inventory.quantity[a][b][c] << std::endl;
							std::cout << "\n Взять в руки(F) или выбросить(Z)" << std::endl;
							std::cin >> in;
							if (in == 'F' || in == 'f')
							{
								std::cout << " Введите количество которое вы хотите взять: "; std::cin >> _PlayerAttributes._Inventory.quantityItem;

								while (Raning)
								{
									if (_PlayerAttributes._Inventory.quantity[a][b][c] - _PlayerAttributes._Inventory.quantityItem < 0)
									{
										std::cout << " У вас нет такого количества предметов " << std::endl;
										std::cout << " Введите количество корректно, в инвентаре сейчас есть только: "<< _PlayerAttributes._Inventory.quantity[a][b][c]<< " шт." << std::endl;
										std::cin >> _PlayerAttributes._Inventory.quantityItem;
									}
									else
									{
										_PlayerAttributes._Inventory.quantity[a][b][c] = _PlayerAttributes._Inventory.quantity[a][b][c] - _PlayerAttributes._Inventory.quantityItem;

										if (_PlayerAttributes._Inventory.quantity[a][b][c] == 0)
										{
											std::cout << " Вы забрали все " << std::endl;
											_PlayerAttributes._Inventory.inventory[a][b][c] = 0;
										}
										else
										{
											std::cout << " Предметов осталось: " << _PlayerAttributes._Inventory.quantity[a][b][c] << " шт." << std::endl;
										}
										
										Item_attr.NumberItem = namberItem;
										Item_attr.quantity = _PlayerAttributes._Inventory.quantityItem;
										Item_attr.InHand = true;

										Raning = false;
									}
								}
							}
							else if (in == 'Z' || in == 'z')
							{
								_PlayerAttributes._Inventory.inventory[a][b][c] = 0;
								_PlayerAttributes._Inventory.quantity[a][b][c] = 0;
							}

							break;
						}
						else if (_PlayerAttributes._Inventory.inventory[a][b][c] == 0)
						{
							std::cout << " Данный предмет закончился" << std::endl;
							Raning = false;
						}

						if (!Raning)
						{
							break;
						}
					}
					if (!Raning)
					{
						break;
					}
				}
				if (!Raning)
				{
					break;
				}
			}
			if (!Raning)
			{
				break;
			}
		}
	}
}

void Character::Inventory()
{
	std::cout << std::endl;
	std::cout << "\t\t\t\t* Инвентарь *" << std::endl;
	std::cout << std::endl;

	// отображение инвентаря
	for (int a = 0; a < _PlayerAttributes._Inventory.inventoryPage; a++)
	{
		if (a == 0)
		{
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "\t\t\t\t Раздел: ";
			std::cout << "\t Зелья " << std::endl;
			std::cout << std::endl;
		}
		else if (a == 1)
		{
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "\t\t\t\t Раздел: ";
			std::cout << "\t Броня " << std::endl;
			std::cout << std::endl;
		}
		else if (a == 2)
		{
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "\t\t\t\t Раздел: ";
			std::cout << "\t Оружие " << std::endl;
			std::cout << std::endl;
		}
		else if (a == 3)
		{
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "\t\t\t\t Раздел: ";
			std::cout << "\t Бижутерия " << std::endl;
			std::cout << std::endl;
		}
		else
		{
			std::cout << "a = " << a << std::endl;
		}

		for (int b = 0; b < _PlayerAttributes._Inventory.width; b++)
		{
			for (int c = 0; c < _PlayerAttributes._Inventory.height; c++)
			{
				if (_PlayerAttributes._Inventory.inventory[a][b][c] > 0)
				{
					OutNameItem(_PlayerAttributes._Inventory.inventory[a][b][c]);
					std::cout << " # ";
					std::cout << " Предмет - ";
					std::cout << Item_attr.NameItem<<"|";
					std::cout << "  Клас редкости: " << Item_attr.Name_Rare_Item<<" |";
					std::cout << "  Количество - ";
					if (_PlayerAttributes._Inventory.quantity[a][b][c] < 100)
					{
						std::cout << "0";
					}
					if (_PlayerAttributes._Inventory.quantity[a][b][c] < 10)
					{
						std::cout << "0";
					}
					std::cout << _PlayerAttributes._Inventory.quantity[a][b][c] << " шт.";
					std::cout << "  # ";

					std::cout << std::endl;
					std::cout << std::endl;
				}
				else
				{
					break;
				}
			}
		}
	}
}

void StorageAttributesg::Add_standart_param()
{

}

