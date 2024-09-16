#include "Map.h"
#include <cstdlib>
#include "Character.h"
#include "Game.h"

 Map::Map()
 {
	 Map_set();
 }

 void Map::Map_set()
 {
	 /*if (!player._PlayerAttributes._SystemParam.Load_save)
	 {
		 attr_World.Int_Current_World = 10;
		 attr_World.village.Village_region = 1;
	 }
	 else if (player._PlayerAttributes._SystemParam.Load_save)
	 {
		 attr_World.Int_Current_World = player.Get_Int_World();
	 }*/

	 attr_World.tileMap[0][0] = 999;
	 attr_World.Build_map_west_1();
	 attr_World.Build_map_west_north_2();
	 attr_World.Build_map_north_1();
	 attr_World.Build_map_north_east_2();
	 attr_World.Build_map_east_1();
	 attr_World.Build_map_east_south_2();
	 attr_World.Build_map_south_1();
	 attr_World.Build_map_south_west_2();
	 attr_World.Build_map_centre_0();
 }

 void World::Choice_World(Character& player)
 {
	 player._PlayerAttributes._SystemParam._Position.Int_World = Int_Current_World;

	 int Pos_X = player.Get_player_position_X();
	 int Pos_Y = player.Get_player_position_Y();

	

	if (Int_Current_World == 1) 
	{
		for (int y = 0; y < Rows; y++)
		{
			for (int x = 0; x < Cols; x++)
			{

				if (tileMap_west_1[y][x] == attr_simbol.Player_int)
				{
					if (tileMap_west_1[y][x] == attr_simbol.Player_int && tileMap_west_1[Pos_Y][Pos_X] == attr_simbol.Player_int)
					{
						tileMap[y][x] = tileMap_west_1[y][x];
					}
					else
					{
						tileMap_west_1[y][x] = attr_simbol.Dark_area_int;

						tileMap[y][x] = tileMap_west_1[y][x];
					}
				}
				else
				{
					tileMap[y][x] = tileMap_west_1[y][x];
				}
			}
		}
		player._PlayerAttributes._SystemParam._Position.World = "Западная область";
		Current_World = "Западная область";
	}
	else if (Int_Current_World == 2) 
	{

		for (int y = 0; y < Rows; y++)
		{
			for (int x = 0; x < Cols; x++)
			{
				if (tileMap_west_north_2[y][x] == attr_simbol.Player_int)
				{
					if (tileMap_west_north_2[y][x] == attr_simbol.Player_int && tileMap_west_north_2[Pos_Y][Pos_X] == attr_simbol.Player_int)
					{
						tileMap[y][x] = tileMap_west_north_2[y][x];
					}
					else
					{
						tileMap_west_north_2[y][x] = attr_simbol.Dark_area_int;

						tileMap[y][x] = tileMap_west_north_2[y][x];
					}
				}
				else
				{
					tileMap[y][x] = tileMap_west_north_2[y][x];
				}
			}
		}
		player._PlayerAttributes._SystemParam._Position.World = "Северо-западная область";
		Current_World = "Северо-западная область";
	}
	else if (Int_Current_World == 3) 
	{
		for (int y = 0; y < Rows; y++)
		{
			for (int x = 0; x < Cols; x++)
			{
				if (tileMap_north_1[y][x] == attr_simbol.Player_int)
				{
					if (tileMap_north_1[y][x] == attr_simbol.Player_int && tileMap_north_1[Pos_Y][Pos_X] == attr_simbol.Player_int)
					{
						tileMap[y][x] = tileMap_north_1[y][x];
					}
					else
					{
						tileMap_north_1[y][x] = attr_simbol.Dark_area_int;

						tileMap[y][x] = tileMap_north_1[y][x];
					}
				}
				else
				{
					tileMap[y][x] = tileMap_north_1[y][x];
				}
			}
		}
		player._PlayerAttributes._SystemParam._Position.World = "Северная область";
		Current_World = "Северная область";
	}
	else if (Int_Current_World == 4)
	{
		for (int y = 0; y < Rows; y++)
		{
			for (int x = 0; x < Cols; x++)
			{
				if (tileMap_north_east_2[y][x] == attr_simbol.Player_int)
				{
					if (tileMap_north_east_2[y][x] == attr_simbol.Player_int && tileMap_north_east_2[Pos_Y][Pos_X] == attr_simbol.Player_int)
					{
						tileMap[y][x] = tileMap_north_east_2[y][x];
					}
					else
					{
						tileMap_north_east_2[y][x] = attr_simbol.Dark_area_int;

						tileMap[y][x] = tileMap_north_east_2[y][x];
					}
				}
				else
				{
					tileMap[y][x] = tileMap_north_east_2[y][x];
				}
			}
		}
		player._PlayerAttributes._SystemParam._Position.World = "Северо-восточная область";
		Current_World = "Северо-восточная область";
	}
	else if (Int_Current_World == 5)
	{
		for (int y = 0; y < Rows; y++)
		{
			for (int x = 0; x < Cols; x++)
			{
				if (tileMap_east_1[y][x] == attr_simbol.Player_int)
				{
					if (tileMap_east_1[y][x] == attr_simbol.Player_int && tileMap_east_1[Pos_Y][Pos_X] == attr_simbol.Player_int)
					{
						tileMap[y][x] = tileMap_east_1[y][x];
					}
					else
					{
						tileMap_east_1[y][x] = attr_simbol.Dark_area_int;

						tileMap[y][x] = tileMap_east_1[y][x];
					}
				}
				else
				{
					tileMap[y][x] = tileMap_east_1[y][x];
				}
			}
		}
		player._PlayerAttributes._SystemParam._Position.World = "Восточная область";
		Current_World = "Восточная область";
	}
	else if (Int_Current_World == 6)
	{
		for (int y = 0; y < Rows; y++)
		{
			for (int x = 0; x < Cols; x++)
			{
				if (tileMap_east_south_2[y][x] == attr_simbol.Player_int)
				{
					if (tileMap_east_south_2[y][x] == attr_simbol.Player_int && tileMap_east_south_2[Pos_Y][Pos_X] == attr_simbol.Player_int)
					{
						tileMap[y][x] = tileMap_east_south_2[y][x];
					}
					else
					{
						tileMap_east_south_2[y][x] = attr_simbol.Dark_area_int;

						tileMap[y][x] = tileMap_east_south_2[y][x];
					}
				}
				else
				{
					tileMap[y][x] = tileMap_east_south_2[y][x];
				}
			}
		}
		player._PlayerAttributes._SystemParam._Position.World = "Юго-восточная область";
		Current_World = "Юго-восточная область";
	}
	else if (Int_Current_World == 7)
	{
		for (int y = 0; y < Rows; y++)
		{
			for (int x = 0; x < Cols; x++)
			{
				if (tileMap_south_1[y][x] == attr_simbol.Player_int)
				{
					if (tileMap_south_1[y][x] == attr_simbol.Player_int && tileMap_south_1[Pos_Y][Pos_X] == attr_simbol.Player_int)
					{
						tileMap[y][x] = tileMap_south_1[y][x];
					}
					else
					{
						tileMap_south_1[y][x] = attr_simbol.Dark_area_int;

						tileMap[y][x] = tileMap_south_1[y][x];
					}
				}
				else
				{
					tileMap[y][x] = tileMap_south_1[y][x];
				}
			}
		}
		player._PlayerAttributes._SystemParam._Position.World = "Южная область";
		Current_World = "Южная область";
	}
	else if (Int_Current_World == 8)
	{
		for (int y = 0; y < Rows; y++)
		{
			for (int x = 0; x < Cols; x++)
			{
				if (tileMap_south_west_2[y][x] == attr_simbol.Player_int)
				{
					if (tileMap_south_west_2[y][x] == attr_simbol.Player_int && tileMap_south_west_2[Pos_Y][Pos_X] == attr_simbol.Player_int)
					{
						tileMap[y][x] = tileMap_south_west_2[y][x];
					}
					else
					{
						tileMap_south_west_2[y][x] = attr_simbol.Dark_area_int;

						tileMap[y][x] = tileMap_south_west_2[y][x];
					}
				}
				else
				{
					tileMap[y][x] = tileMap_south_west_2[y][x];
				}
			}
		}
		player._PlayerAttributes._SystemParam._Position.World = "Юго-западная область";
		Current_World = "Юго-западная область";
	}
	else if (Int_Current_World == 9)
	{
		for (int y = 0; y < Rows; y++)
		{
			for (int x = 0; x < Cols; x++)
			{
				if (tileMap_centre_0[y][x] == attr_simbol.Player_int)
				{
					if (tileMap_centre_0[y][x] == attr_simbol.Player_int && tileMap_centre_0[Pos_Y][Pos_X] == attr_simbol.Player_int)
					{
						tileMap[y][x] = tileMap_centre_0[y][x];
					}
					else
					{
						tileMap_centre_0[y][x] = attr_simbol.Dark_area_int;

						tileMap[y][x] = tileMap_centre_0[y][x];
					}
				}
				else
				{
					tileMap[y][x] = tileMap_centre_0[y][x];
				}
			}
		}
		player._PlayerAttributes._SystemParam._Position.World = "Центральная область";
		Current_World = "Центральная область";
	}
	else if (Int_Current_World == 10)
	{
		if (village.Village_region == 1)
		{
			for (int y = 0; y < Rows; y++)
			{
				for (int x = 0; x < Cols; x++)
				{
					if (village.tileMap_village_gate_area[y][x] == attr_simbol.Player_int)
					{
						if (village.tileMap_village_gate_area[y][x] == attr_simbol.Player_int && village.tileMap_village_gate_area[Pos_Y][Pos_X] == attr_simbol.Player_int)
						{
							tileMap[y][x] = village.tileMap_village_gate_area[y][x];
						}
						else if (village.tileMap_village_gate_area[y][x] == attr_simbol.Player_int && village.tileMap_village_gate_area[Pos_Y][Pos_X] != attr_simbol.Player_int)
						{
							village.tileMap_village_gate_area[y][x] = attr_simbol.Light_area_int;

							tileMap[y][x] = village.tileMap_village_gate_area[y][x];
						}
					}
					else
					{
						tileMap[y][x] = village.tileMap_village_gate_area[y][x];
					}
				}
			}
		}
		else if (village.Village_region == 2)
		{
			for (int y = 0; y < Rows; y++)
			{
				for (int x = 0; x < Cols; x++)
				{
					if (village.tileMap_village_central_region[y][x] == attr_simbol.Player_int)
					{
						if (village.tileMap_village_central_region[y][x] == attr_simbol.Player_int && village.tileMap_village_central_region[Pos_Y][Pos_X] == attr_simbol.Player_int)
						{
							tileMap[y][x] = village.tileMap_village_central_region[y][x];
						}
						else if (village.tileMap_village_gate_area[y][x] == attr_simbol.Player_int && village.tileMap_village_gate_area[Pos_Y][Pos_X] != attr_simbol.Player_int)
						{
							village.tileMap_village_central_region[y][x] = attr_simbol.Light_area_int;

							tileMap[y][x] = village.tileMap_village_central_region[y][x];
						}
					}
					else
					{
						tileMap[y][x] = village.tileMap_village_central_region[y][x];
					}
				}
			}
		}
		player._PlayerAttributes._SystemParam._Position.World = " Поселение";
		Current_World = " Поселение";
	}
 }

 void World::Saving_World()
 {
	 if (Int_Current_World == 1)
	 {
		 for (int y = 0; y < Rows; y++)
		 {
			 for (int x = 0; x < Cols; x++)
			 {
				 tileMap_west_1[y][x] = tileMap[y][x];
			 }
		 }
	 }
	 else if (Int_Current_World == 2)
	 {

		 for (int y = 0; y < Rows; y++)
		 {
			 for (int x = 0; x < Cols; x++)
			 {
				tileMap_west_north_2[y][x] = tileMap[y][x];
			 }
		 }
	 }
	 else if (Int_Current_World == 3)
	 {
		 for (int y = 0; y < Rows; y++)
		 {
			 for (int x = 0; x < Cols; x++)
			 {
				 tileMap_north_1[y][x] = tileMap[y][x];
			 }
		 }
	 }
	 else if (Int_Current_World == 4)
	 {
		 for (int y = 0; y <Rows; y++)
		 {
			 for (int x = 0; x < Cols; x++)
			 {
				tileMap_north_east_2[y][x] = tileMap[y][x];
			 }
		 }
	 }
	 else if (Int_Current_World == 5)
	 {
		 for (int y = 0; y < Rows; y++)
		 {
			 for (int x = 0; x < Cols; x++)
			 {
				 tileMap_east_1[y][x] = tileMap[y][x];
			 }
		 }
	 }
	 else if (Int_Current_World == 6)
	 {
		 for (int y = 0; y < Rows; y++)
		 {
			 for (int x = 0; x < Cols; x++)
			 {
				 tileMap_east_south_2[y][x] = tileMap[y][x];
			 }
		 }
	 }
	 else if (Int_Current_World == 7)
	 {
		 for (int y = 0; y < Rows; y++)
		 {
			 for (int x = 0; x < Cols; x++)
			 {
				 tileMap_south_1[y][x] = tileMap[y][x];
			 }
		 }
	 }
	 else if (Int_Current_World == 8)
	 {
		 for (int y = 0; y < Rows; y++)
		 {
			 for (int x = 0; x < Cols; x++)
			 {
				 tileMap_south_west_2[y][x] = tileMap[y][x];
			 }
		 }
	 }
	 else if (Int_Current_World == 9)
	 {
		 for (int y = 0; y < Rows; y++)
		 {
			 for (int x = 0; x < Cols; x++)
			 {
				 tileMap_centre_0[y][x] = tileMap[y][x];
			 }
		 }
	 }
	 else if (Int_Current_World == 10)
	 {

		 if (village.Village_region == 1)
		 {
			 for (int y = 0; y < Rows; y++)
			 {
				 for (int x = 0; x < Cols; x++)
				 {
					 village.tileMap_village_gate_area[y][x] = tileMap[y][x];
				 }
			 }
		 }
		 else if (village.Village_region == 2)
		 {
			 for (int y = 0; y < Rows; y++)
			 {
				 for (int x = 0; x < Cols; x++)
				 {
					 village.tileMap_village_central_region[y][x] = tileMap[y][x];
				 }
			 }

		 }
	 }
 }

void Map::PrintMap(Character& player)
{
	// "#", 0 - Simbol_wall
	// "*", 1 - SimbolDarkAreaD
	// "P", 3 - SimbolPlayerD
	// " ", 4 - SimbollightAreaD = true
	// "E", 5 - Simbol_enemy
	// "*", 6 - SimbollightAreaD = false
	// "S", 7 - Simbol_save
	// "G", 8 - Simboi_gate

	//attr_World.attr_simbol.Dark_area;
	//attr_World.attr_simbol.Dark_area_int;

	for (int y = 0; y < attr_World.Rows; y++)
	{
		for (int x = 0; x < attr_World.Cols; x++)
		{
			if (attr_World.tileMap[y][x] == attr_World.attr_simbol.Wall_int)
			{
				std::cout << (char)attr_World.attr_simbol.Wall;
			}
			else if (attr_World.tileMap[y][x] == attr_World.attr_simbol.Dark_area_int)
			{
				std::cout << (char)attr_World.attr_simbol.Dark_area;
			}
			else if (attr_World.tileMap[y][x] == attr_World.attr_simbol.Player_int)
			{
				std::cout << (char)attr_World.attr_simbol.Player;
			}
			else if (attr_World.tileMap[y][x] == attr_World.attr_simbol.Enemy)
			{
				std::cout << (char)attr_World.attr_simbol.Enemy;
			}
			else if (attr_World.tileMap[y][x] == attr_World.attr_simbol.Save_int)
			{
				std::cout << (char)attr_World.attr_simbol.Save;
			}
			else if (attr_World.tileMap[y][x] == attr_World.attr_simbol.Gate_int)
			{
				std::cout << (char)attr_World.attr_simbol.Gate;
			}
			else if (player._PlayerAttributes._SystemParam.Overview)
			{
				if (attr_World.tileMap[y][x] == attr_World.attr_simbol.Light_area_int)
				{
					std::cout << (char)attr_World.attr_simbol.Light_area;
				}
			}
			else if (!player._PlayerAttributes._SystemParam.Overview)
			{
				if (attr_World.Int_Current_World != 10)
				{
					if (attr_World.tileMap[y][x] == attr_World.attr_simbol.Light_area_int)
					{
						attr_World.tileMap[y][x] = attr_World.attr_simbol.Dark_area_int;
						std::cout << (char)attr_World.attr_simbol.Dark_area;
					}
				}
				else
				{
					std::cout << (char)attr_World.attr_simbol.Light_area;
				}
			}
		}
		std::cout << std::endl;
	}
}

void Map::PrintMapSetting(Character& player)
{
	// "#", 0 - Simbol_wall
	// "*", 1 - SimbolDarkAreaD
	// "P", 3 - SimbolPlayerD
	// " ", 4 - SimbollightAreaD = true
	// "E", 5 - Simbol_enemy
	// "*", 6 - SimbollightAreaD = false
	// "S", 7 - Simbol_save
	// "G", 8 - Simboi_gate

	for (int y = 0; y < attr_World.Rows; y++)
	{
		for (int x = 0; x < attr_World.Cols; x++)
		{
			if (attr_World.tileMap[y][x] == attr_World.attr_simbol.Wall_int)
			{
				std::cout << attr_World.attr_simbol.Wall_int;
			}
			else if (attr_World.tileMap[y][x] == attr_World.attr_simbol.Dark_area_int)
			{
				std::cout << attr_World.attr_simbol.Dark_area_int;
			}
			else if (attr_World.tileMap[y][x] == attr_World.attr_simbol.Player_int)
			{
				std::cout << attr_World.attr_simbol.Player_int;
			}
			else if (attr_World.tileMap[y][x] == attr_World.attr_simbol.Enemy_int)
			{
				std::cout << attr_World.attr_simbol.Enemy_int;
			}
			else if (attr_World.tileMap[y][x] == attr_World.attr_simbol.Save_int)
			{
				std::cout << attr_World.attr_simbol.Save_int;
			}
			else if (attr_World.tileMap[y][x] == attr_World.attr_simbol.Gate_int)
			{
				std::cout << attr_World.attr_simbol.Gate_int;
			}
			else if (player._PlayerAttributes._SystemParam.Overview)
			{
				if (attr_World.tileMap[y][x] == attr_World.attr_simbol.Light_area_int)
				{
					std::cout << attr_World.attr_simbol.Light_area_int;
				}
			}
			else if (!player._PlayerAttributes._SystemParam.Overview)
			{
				if (attr_World.tileMap[y][x] == attr_World.attr_simbol.Light_area_int)
				{
					attr_World.tileMap[y][x] = attr_World.attr_simbol.Dark_area_int;
					std::cout << attr_World.attr_simbol.Dark_area_int;
				}
			}
		}
		std::cout << std::endl;
	}
}

void Map::Tracking_Move(int direction)
{
	CordinateNextStepX = Current_Position_X;
	CordinateNextStepY = Current_Position_Y;

	switch (direction)
	{
	case 1://запад
	{
		if (attr_World.tileMap[Current_Position_Y][Current_Position_X - 1] != attr_World.attr_simbol.Wall_int)
		{
			if (attr_World.tileMap[Current_Position_Y][Current_Position_X - 1] != attr_World.attr_simbol.Gate_int)
			{
				CordinateNextStepX -= 1;
			}
		}
		break;
	}
	case 2://север
	{
		if (attr_World.tileMap[Current_Position_Y - 1][Current_Position_X] != attr_World.attr_simbol.Wall_int)
		{
			if (attr_World.tileMap[Current_Position_Y - 1][Current_Position_X] != attr_World.attr_simbol.Gate_int)
			{
				CordinateNextStepY -= 1;
			}
		}
		break;
	}
	case 3://восток
	{
		if (attr_World.tileMap[Current_Position_Y][Current_Position_X + 1] != attr_World.attr_simbol.Wall_int)
		{
			if (attr_World.tileMap[Current_Position_Y][Current_Position_X + 1] != attr_World.attr_simbol.Gate_int)
			{
				CordinateNextStepX += 1;
			}
		}
		break;
	}
	case 4://юг
	{
		if (attr_World.tileMap[Current_Position_Y + 1][Current_Position_X] != attr_World.attr_simbol.Wall_int)
		{
			if (attr_World.tileMap[Current_Position_Y + 1][Current_Position_X] != attr_World.attr_simbol.Gate_int)
			{
				CordinateNextStepY += 1;
			}
		}
		break;
	}
	default:

		break;
	}
}

bool Map::Checking_save(int Cordinate_X, int Cordinate_Y)
{
	if (attr_World.Int_Current_World != 10)
	{
		if (Cordinate_Y == 6 && Cordinate_X == 7)
			return true;
		else if (Cordinate_Y == 4 && Cordinate_X == 21)
			return true;
		else if (Cordinate_Y == 10 && Cordinate_X == 33)
			return true;
		else if (Cordinate_Y == 3 && Cordinate_X == 40)
			return true;
		else if (Cordinate_Y == 19 && Cordinate_X == 5)
			return true;
		else if (Cordinate_Y == 13 && Cordinate_X == 17)
			return true;
		else if (Cordinate_Y == 18 && Cordinate_X == 28)
			return true;
		else if (Cordinate_Y == 20 && Cordinate_X == 41)
			return true;
		else
			return false;
	}
	else
	{
		return false;
	}
}

void Map::InsertPlayerIntoMap(Character& player, int direction)
{
	// первая запись мира
	if (attr_World.tileMap[0][0] == 999)
	{
		attr_World.Int_Current_World = 10;

		attr_World.village.Village_region = 1;

		attr_World.Choice_World(player);

		attr_World.Save_game_world = true;
	}

	if (Last_Position_X == 0 )
	{
		Last_Position_X = player.Get_player_position_X();
	}

	if (Last_Position_Y == 0)
	{
		Last_Position_Y = player.Get_player_position_Y();
	}

	if (!attr_World.Passage || !player._PlayerAttributes._SystemParam._Position.Transfer_player)
	{
		// обычный ход

		if (attr_World.Int_Current_World == 10)
		{
			if (Last_Position_Y != 0 && Last_Position_X != 0)
			{
				attr_World.tileMap[Last_Position_Y][Last_Position_X] = attr_World.attr_simbol.Light_area_int;
			}
		}
		else
		{
			attr_World.tileMap[Last_Position_Y][Last_Position_X] = attr_World.attr_simbol.Dark_area_int;
		}

		Current_Position_X = player.Get_player_position_X();
		Current_Position_Y = player.Get_player_position_Y();

		Tracking_Move(direction);

		attr_World.Load_save = Checking_save(CordinateNextStepX, CordinateNextStepY);

		if (attr_World.Load_save)
		{
			attr_World.tileMap[CordinateNextStepY][CordinateNextStepX] = attr_World.attr_simbol.Save_int;
		}
		else
		{
			attr_World.tileMap[CordinateNextStepY][CordinateNextStepX] = attr_World.attr_simbol.Player_int;  // координаты следующего шага персонажа
		}

		//сохранение позиции персонажа
		player.Get_player_position_X(CordinateNextStepX);
		player.Get_player_position_Y(CordinateNextStepY);

		Last_Position_X = CordinateNextStepX;
		Last_Position_Y = CordinateNextStepY;

		Erasing_last_step(CordinateNextStepX, CordinateNextStepY);

		if (player._PlayerAttributes._SystemParam.Overview)
		{
			MapOverview(CordinateNextStepX, CordinateNextStepY);
		}

		attr_World.Next_world(player);
	}
	else if (attr_World.Passage && player._PlayerAttributes._SystemParam._Position.Transfer_player)
	{
		attr_World.Moving_next_world(player);

		if (attr_World.Int_Last_World != attr_World.Int_Current_World)
		{
			attr_World.Int_Current_World = attr_World.Int_Last_World;
			attr_World.Choice_World(player);
			attr_World.Save_game_world = true;
		}
		else if (attr_World.Int_Last_World == 10 && attr_World.Int_Current_World == 10)
		{
			attr_World.Choice_World(player);
			attr_World.Save_game_world = true;
		}

		InsertPlayerIntoMap(player);

		player._PlayerAttributes._SystemParam._Position.Transfer_player = false;

	}
	
	if (attr_World.Save_game_world)
	{
		attr_World.Saving_World();
		attr_World.Save_game_world = false;
	}
	
}

void Map::Erasing_last_step(int Cordinate_X, int Cordinate_Y)
{
	int SaveCordinateStepY = Cordinate_X;
	int SaveCordinateStepX = Cordinate_Y;

	Cordinate_X--;
	if (attr_World.tileMap[Cordinate_X][Cordinate_Y] != attr_World.attr_simbol.Wall_int && attr_World.tileMap[Cordinate_X][Cordinate_Y] != attr_World.attr_simbol.Save_int)// 2   
	{
		if (attr_World.tileMap[Cordinate_X][Cordinate_Y] == attr_World.attr_simbol.Player_int)
		{
			if (attr_World.Int_Current_World != 10)
			{
				attr_World.tileMap[Cordinate_X][Cordinate_Y] = attr_World.attr_simbol.Dark_area_int;
			}
			else
			{
				attr_World.tileMap[Cordinate_X][Cordinate_Y] = attr_World.attr_simbol.Light_area_int;
			}
		}
	}
	Cordinate_X = SaveCordinateStepY;

	Cordinate_X++;
	if (attr_World.tileMap[Cordinate_X][Cordinate_Y] != attr_World.attr_simbol.Wall_int && attr_World.tileMap[Cordinate_X][Cordinate_Y] != attr_World.attr_simbol.Save_int)// 7   
	{
		if (attr_World.tileMap[Cordinate_X][Cordinate_Y] == attr_World.attr_simbol.Player_int)
		{
			if (attr_World.Int_Current_World != 10)
			{
				attr_World.tileMap[Cordinate_X][Cordinate_Y] = attr_World.attr_simbol.Dark_area_int;
			}
			else
			{
				attr_World.tileMap[Cordinate_X][Cordinate_Y] = attr_World.attr_simbol.Light_area_int;
			}
		}
	}
	Cordinate_X = SaveCordinateStepY;
	 
	Cordinate_Y--;
	if (attr_World.tileMap[Cordinate_X][Cordinate_Y] != attr_World.attr_simbol.Wall_int && attr_World.tileMap[Cordinate_X][Cordinate_Y] != attr_World.attr_simbol.Save_int) // 4  
	{
		if (attr_World.tileMap[Cordinate_X][Cordinate_Y] == attr_World.attr_simbol.Player_int)
		{
			if (attr_World.Int_Current_World != 10)
			{
				attr_World.tileMap[Cordinate_X][Cordinate_Y] = attr_World.attr_simbol.Dark_area_int;
			}
			else
			{
				attr_World.tileMap[Cordinate_X][Cordinate_Y] = attr_World.attr_simbol.Light_area_int;
			}
		}
	}
	Cordinate_Y = SaveCordinateStepX;

	Cordinate_Y++;
	if (attr_World.tileMap[Cordinate_X][Cordinate_Y] != attr_World.attr_simbol.Wall_int && attr_World.tileMap[Cordinate_X][Cordinate_Y] != attr_World.attr_simbol.Save_int) // 5  
	{
		if (attr_World.tileMap[Cordinate_X][Cordinate_Y] == attr_World.attr_simbol.Player_int)
		{
			if (attr_World.Int_Current_World != 10)
			{
				attr_World.tileMap[Cordinate_X][Cordinate_Y] = attr_World.attr_simbol.Dark_area_int;
			}
			else
			{
				attr_World.tileMap[Cordinate_X][Cordinate_Y] = attr_World.attr_simbol.Light_area_int;
			}
		}
	}
	Cordinate_Y = SaveCordinateStepX;
}

void Map::MapOverview(int PlayerX, int PlayerY)
{
	int SavePlayerX = PlayerX;// сохранение координат персонажа X
	int SavePlayerY = PlayerY;// сохранение координат персонажа Y

	int CordinateOpenAreaX = SavePlayerX;// координаты открытой обл относительно персонажа X
	int CordinateOpenAreaY = SavePlayerY;// координаты открытой обл относительно персонажа Y
	
	CordinateOpenAreaY--; CordinateOpenAreaX--;
	if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Wall_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Gate_int)// 1 
	{
		if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Light_area_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Save_int)
		{
			attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] = attr_World.attr_simbol.Light_area_int;
		}

		CordinateOpenAreaY--;
		if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] == attr_World.attr_simbol.Light_area_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Save_int)//2.2
		{
			attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] = attr_World.attr_simbol.Dark_area_int;
		}
		  
		CordinateOpenAreaX--;
		if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] == attr_World.attr_simbol.Light_area_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Save_int)//1.2
		{
			attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] = attr_World.attr_simbol.Dark_area_int;
		}

		CordinateOpenAreaY++;
		if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] == attr_World.attr_simbol.Light_area_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Save_int)//16.2
		{
			attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] = attr_World.attr_simbol.Dark_area_int;
		}
	}
	CordinateOpenAreaY = SavePlayerY; CordinateOpenAreaX = SavePlayerX;

	CordinateOpenAreaY--;
	if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Wall_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Gate_int)// 2   
	{
		if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Light_area_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Save_int)
		{
			attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] = attr_World.attr_simbol.Light_area_int;
		}

		CordinateOpenAreaY--;
		if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] == attr_World.attr_simbol.Light_area_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Save_int)//3.2
		{
			attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] = attr_World.attr_simbol.Dark_area_int;
		}
	}

	CordinateOpenAreaY = SavePlayerY;

	CordinateOpenAreaY--; CordinateOpenAreaX++;
	if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Wall_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Gate_int)// 3
	{
		if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Light_area_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Save_int)
		{
			attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] = attr_World.attr_simbol.Light_area_int;
		}

		CordinateOpenAreaY--;
		if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] == attr_World.attr_simbol.Light_area_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Save_int)//4.2
		{
			attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] = attr_World.attr_simbol.Dark_area_int;
		}

		CordinateOpenAreaX++;
		if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] == attr_World.attr_simbol.Light_area_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Save_int)//5.2
		{
			attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] = attr_World.attr_simbol.Dark_area_int;
		}

		CordinateOpenAreaY++;
		if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] == attr_World.attr_simbol.Light_area_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Save_int)//6.2
		{
			attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] = attr_World.attr_simbol.Dark_area_int;
		}
	}
	CordinateOpenAreaY = SavePlayerY; CordinateOpenAreaX = SavePlayerX;

	CordinateOpenAreaX--;
	if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Wall_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Gate_int)// 4 
	{
		if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Light_area_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Save_int)
		{
			attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] = attr_World.attr_simbol.Light_area_int;
		}

		CordinateOpenAreaX--;
		if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] == attr_World.attr_simbol.Light_area_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Save_int)//15.2
		{
			attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] = attr_World.attr_simbol.Dark_area_int;
		}
	}
	CordinateOpenAreaX = SavePlayerX;

	CordinateOpenAreaX++;
	if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Wall_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Gate_int)// 5 
	{
		if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Light_area_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Save_int)
		{
			attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] = attr_World.attr_simbol.Light_area_int;
		}

		CordinateOpenAreaX++;
		if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] == attr_World.attr_simbol.Light_area_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Save_int)//7.2
		{
			attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] = attr_World.attr_simbol.Dark_area_int;
		}
	}
	CordinateOpenAreaX = SavePlayerX;

	CordinateOpenAreaY++; CordinateOpenAreaX--;
	if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Wall_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Gate_int)// 6
	{
		if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Light_area_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Save_int)
		{
			attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] = attr_World.attr_simbol.Light_area_int;
		}

		CordinateOpenAreaY++;
		if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] == attr_World.attr_simbol.Light_area_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Save_int)//12.2
		{
			attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] = attr_World.attr_simbol.Dark_area_int;
		}

		CordinateOpenAreaX--;
		if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] == attr_World.attr_simbol.Light_area_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Save_int)//13.2
		{
			attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] = attr_World.attr_simbol.Dark_area_int;
		}

		CordinateOpenAreaY--;
		if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] == attr_World.attr_simbol.Light_area_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Save_int)//14.2
		{
			attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] = attr_World.attr_simbol.Dark_area_int;
		}
	}
	CordinateOpenAreaY = SavePlayerY; CordinateOpenAreaX = SavePlayerX;

	CordinateOpenAreaY++;
	if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Wall_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Gate_int)// 7
	{
		if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Light_area_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Save_int)
		{
			attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] = attr_World.attr_simbol.Light_area_int;
		}

		CordinateOpenAreaY++;
		if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] == attr_World.attr_simbol.Light_area_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Save_int)//11.2
		{
			attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] = attr_World.attr_simbol.Dark_area_int;
		}
	}
	CordinateOpenAreaY = SavePlayerY;

	CordinateOpenAreaY++; CordinateOpenAreaX++;
	if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Wall_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Gate_int)//8
	{
		if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Light_area_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Save_int)
		{
			attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] = attr_World.attr_simbol.Light_area_int;
		}

		CordinateOpenAreaY++;
		if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] == attr_World.attr_simbol.Light_area_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Save_int)//10.2
		{
			attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] = attr_World.attr_simbol.Dark_area_int;
		}

		CordinateOpenAreaX++;
		if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] == attr_World.attr_simbol.Light_area_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Save_int)//9.2
		{
			attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] = attr_World.attr_simbol.Dark_area_int;
		}

		CordinateOpenAreaY--;
		if (attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] == attr_World.attr_simbol.Light_area_int && attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] != attr_World.attr_simbol.Save_int)//8.2
		{
			attr_World.tileMap[CordinateOpenAreaY][CordinateOpenAreaX] = attr_World.attr_simbol.Dark_area_int;
		}
	}
	CordinateOpenAreaY = SavePlayerY; CordinateOpenAreaX = SavePlayerX;
}

char Map::Symbol()
{
	bool settings = true;
	while (settings)
	{
		char UserInput = ' ';
		system("CLS");
		std::cout << " 1. Символ стены"<< std::endl;
		std::cout << " 2. Символ темной области"<< std::endl;
		std::cout << " 3. Символ светлой области" << std::endl;
		std::cout << " 4. Символ персонажа" << std::endl;
		std::cout << " 5. Символ врага" << std::endl;
		std::cout << " 6. Выход из настроек символов" << std::endl;
		std::cin >> UserInput;
		switch (UserInput)
		{
			/*
		case '1':
			system("CLS");
			std::cout << " Символ стены: " << attr_World.attr_simbol.Simbol_wall << std::endl;
			std::cout << "      Изменить?" << std::endl;
			std::cout << " Да(Y)        Нет(N)" << std::endl;
			std::cin >> UserInput;
			if (UserInput == 'Y' || UserInput == 'y' || UserInput == 'Н' || UserInput == 'н')
			{
				std::cout << " Старый символ: " << attr_World.attr_simbol.Simbol_wall << std::endl;
				std::cout << " Новый символ: ";
				std::cin >> attr_World.attr_simbol.Wall_int;
			}
			else if (UserInput == 'N' || UserInput == 'n' || UserInput == 'Т' || UserInput == 'т')
			{
				UserInput = ' ';
			}

			break;

		case '2':
			system("CLS");
			std::cout << " Символ темной облости: " << attr_World.attr_simbol.Simbol_dark_area << std::endl;
			std::cout << "      Изменить?" << std::endl;
			std::cout << " Да(Y)        Нет(N)" << std::endl;
			std::cin >> UserInput;
			if (UserInput == 'Y' || UserInput == 'y' || UserInput == 'Н' || UserInput == 'н')
			{
				std::cout << " Старый символ: " << attr_World.attr_simbol.Simbol_dark_area << std::endl;
				std::cout << " Новый символ: ";
				std::cin >> attr_World.attr_simbol.Simbol_dark_area;;
			}
			else if (UserInput == 'N' || UserInput == 'n' || UserInput == 'Т' || UserInput == 'т')
			{
				UserInput = ' ';
			}

			break;

		case '3':
			system("CLS");
			std::cout << " Символ светлой облости: " << attr_World.attr_simbol.Simbol_light_area << std::endl;
			std::cout << "      Изменить?" << std::endl;
			std::cout << " Да(Y)        Нет(N)" << std::endl;
			std::cin >> UserInput;
			if (UserInput == 'Y' || UserInput == 'y' || UserInput == 'Н' || UserInput == 'н')
			{
				std::cout << " Старый символ: " << attr_World.attr_simbol.Simbol_light_area << std::endl;
				std::cout << " Новый символ: ";
				std::cin >> attr_World.attr_simbol.Simbol_light_area;
			}
			else if (UserInput == 'N' || UserInput == 'n' || UserInput == 'Т' || UserInput == 'т')
			{
				UserInput = ' ';
			}

			break;

		case '4':
			system("CLS");
			std::cout << " Символ персонажа: " << attr_World.attr_simbol.Simbol_player << std::endl;
			std::cout << "      Изменить?" << std::endl;
			std::cout << " Да(Y)        Нет(N)" << std::endl;
			std::cin >> UserInput;
			if (UserInput == 'Y' || UserInput == 'y' || UserInput == 'Н' || UserInput == 'н')
			{
				std::cout << " Старый символ: " << attr_World.attr_simbol.Simbol_player << std::endl;
				std::cout << " Новый символ: ";
				std::cin >> attr_World.attr_simbol.Simbol_player;
			}
			else if (UserInput == 'N' || UserInput == 'n' || UserInput == 'Т' || UserInput == 'т')
			{
				UserInput = ' ';
			}

			break;

		case '5':
			system("CLS");
			std::cout << " Символ врага: " << attr_World.attr_simbol.Simbol_enemy << std::endl;
			std::cout << "      Изменить?" << std::endl;
			std::cout << " Да(Y)        Нет(N)" << std::endl;
			std::cin >> UserInput;
			if (UserInput == 'Y' || UserInput == 'y' || UserInput == 'Н' || UserInput == 'н')
			{
				std::cout << " Старый символ: " << attr_World.attr_simbol.Simbol_enemy << std::endl;
				std::cout << " Новый символ: ";
				std::cin >> attr_World.attr_simbol.Simbol_enemy;
			}
			else if (UserInput == 'N' || UserInput == 'n' || UserInput == 'Т' || UserInput == 'т')
			{
				UserInput = ' ';
			}

			break;

			//*/

		case '6':
			system("CLS");
			std::cout << " Выйти из настроек символов?" << std::endl;
			std::cout << "     Да(Y)        Нет(N)" << std::endl;
			std::cin >> UserInput;
			if (UserInput == 'Y' || UserInput == 'y' || UserInput == 'Н' || UserInput == 'н')
			{
				settings = false;
				return settings;
			}
			else if (UserInput == 'N' || UserInput == 'n' || UserInput == 'Т' || UserInput == 'т')
			{
				UserInput = ' ';
				settings = true;
			}
			break;

		default:

			break;
		}
	}
}

void World::Next_world(Character& player)
{
	int x = player.Get_player_position_X(0);
	int y = player.Get_player_position_Y(0);

	if (Int_Current_World == 10)
	{
		if (village.Village_region == 1)// регион ворот
		{
			if (x == 1 && y == 1)// башня левый ход (выход из деревни)
			{
				Passage = true;
			}
			else if (x == 7 && y == 1) // башня правый ход (выход из деревни)
			{
				Passage = true;
			}
			else if (x == 25 && y == 8 || x == 26 && y == 8 || x == 27 && y == 8) // храм три прохода (вход)
			{
				Passage = true;
			}
			else if (x == 25 && y == 6 || x == 26 && y == 6 || x == 27 && y == 6) // храм три прохода (выход)
			{
				Passage = true;
			}
			else if (x == 43 && y == 6)// кузнеца (вход)
			{
				Passage = true;
			}
			else if (x == 43 && y == 4)// кузнеца (выход)
			{
				Passage = true;
			}
			else if (x == 49 && y == 10 || x == 49 && y == 13 || x == 49 && y == 17) // 2й регеон три прохода (1 -> 2)
			{
				Passage = true;
			}
			else if (x == 27 && y == 17)// вельва (вход)
			{
				Passage = true;
			}
			else if (x == 27 && y == 19)// вельва (выход)
			{
				Passage = true;
			}
			else if (x == 7 && y == 18)// охотник (вход)
			{
				Passage = true;
			}
			else if (x == 5 && y == 18)// охотник (выход)
			{
				Passage = true;
			}
			else
			{
				Passage = false;
			}
		}
		else if (village.Village_region == 2)//центральный регион
		{
			if (x == 44 && y == 1 || x == 1 && y == 10 || x == 17 && y == 23) // 1й регион три прохода (2 -> 1)
			{
				Passage = true;
			}
			else
			{
				Passage = false;
			}
		}
	}
	else
	{
		if (x == 26 && y == 1)
		{
			Passage = true;

			if (Int_Current_World == 1)
			{
				Int_Last_World = 2;
			}
			else if (Int_Current_World == 2)
			{
				// not
				Passage = false;
			}
			else if (Int_Current_World == 3)
			{
				// not
				Passage = false;
			}
			else if (Int_Current_World == 4)
			{
				// not
				Passage = false;
			}
			else if (Int_Current_World == 5)
			{
				Int_Last_World = 4;
			}
			else if (Int_Current_World == 6)
			{
				Int_Last_World = 5;
			}
			else if (Int_Current_World == 7)
			{
				Int_Last_World = 9;
			}
			else if (Int_Current_World == 8)
			{
				Int_Last_World = 1;
			}
			else if (Int_Current_World == 9)
			{
				Int_Last_World = 3;
			}
		}
		else if (x == 1 && y == 13)
		{
			Passage = true;

			if (Int_Current_World == 1)
			{
				// not
				Passage = false;
			}
			else if (Int_Current_World == 2)
			{
				// not
				Passage = false;
			}
			else if (Int_Current_World == 3)
			{
				Int_Last_World = 2;
			}
			else if (Int_Current_World == 4)
			{
				Int_Last_World = 3;
			}
			else if (Int_Current_World == 5)
			{
				Int_Last_World = 9;
				village.Return_village = true;
			}
			else if (Int_Current_World == 6)
			{
				Int_Last_World = 7;
			}
			else if (Int_Current_World == 7)
			{
				Int_Last_World = 8;
			}
			else if (Int_Current_World == 8)
			{
				// not
				Passage = false;
			}
			else if (Int_Current_World == 9)
			{
				Int_Last_World = 1;
			}
		}
		else if (x == 49 && y == 13)
		{
			Passage = true;

			if (Int_Current_World == 1)
			{
				Int_Last_World = 9;
			}
			else if (Int_Current_World == 2)
			{
				Int_Last_World = 3;
			}
			else if (Int_Current_World == 3)
			{
				Int_Last_World = 4;
			}
			else if (Int_Current_World == 4)
			{
				// not
				Passage = false;
			}
			else if (Int_Current_World == 5)
			{
				// not
				Passage = false;
			}
			else if (Int_Current_World == 6)
			{
				//not
				Passage = false;
			}
			else if (Int_Current_World == 7)
			{
				Int_Last_World = 6;
			}
			else if (Int_Current_World == 8)
			{
				Int_Last_World = 7;
			}
			else if (Int_Current_World == 9)
			{
				Int_Last_World = 5;
				village.Return_village = true;
			}
		}
		else if (x == 26 && y == 23)
		{
			Passage = true;

			if (Int_Current_World == 1)
			{
				Int_Last_World = 8;
			}
			else if (Int_Current_World == 2)
			{
				Int_Last_World = 1;
			}
			else if (Int_Current_World == 3)
			{
				Int_Last_World = 9;
			}
			else if (Int_Current_World == 4)
			{
				Int_Last_World = 5;
			}
			else if (Int_Current_World == 5)
			{
				Int_Last_World = 6;
			}
			else if (Int_Current_World == 6)
			{
				// not
				Passage = false;
			}
			else if (Int_Current_World == 7)
			{
				// not
				Passage = false;
			}
			else if (Int_Current_World == 8)
			{
				// not
				Passage = false;
			}
			else if (Int_Current_World == 9)
			{
				Int_Last_World = 7;
			}
		}
		else
		{
			Passage = false;
		}
	}
}

void World::Moving_next_world(Character& player)
{
	int x = player.Get_player_position_X(0);
	int y = player.Get_player_position_Y(0);

	if (player._PlayerAttributes._SystemParam._Position.returns_village)
	{
		player._PlayerAttributes._SystemParam._Position.returns_village = false;
		village.Return_village = false;
		village.Village_region = 1;
		Int_Last_World = 10;

		if (Int_Current_World == 9)// вход в деревню
		{
			x = 1;
			y = 1;
		}
		else if (Int_Current_World == 5)// вход в деревню
		{
			x = 7;
			y = 1;
		}
	}
	else if (Int_Current_World == 10)// переходы в деревне
	{
		if (village.Village_region == 1)// область ворот
		{
			if (x == 1 && y == 1)// выход из деревни
			{
				Int_Last_World = 9;
				village.Village_region = 0;
				x = 49;
				y = 13;
			}
			else if (x == 7 && y == 1)// выход из деревни
			{
				Int_Last_World = 5;
				village.Village_region = 0;
				x = 1;
				y = 13;
			}
			else if (x == 25 && y == 8 || x == 26 && y == 8 || x == 27 && y == 8) // храм три прохода (вход)
			{
				Int_Last_World = 10;
				village.Village_region = 1;

				if (x == 25) // первый проход
				{
					x = 25;
					y = 6;
				}
				else if (x == 26) // второй проход
				{
					x = 26;
					y = 6;
				}
				else if (x == 27) // третий проход
				{
					x = 27;
					y = 6;
				}
			}
			else if (x == 25 && y == 6 || x == 26 && y == 6 || x == 27 && y == 6) // храм три прохода (выход)
			{
				Int_Last_World = 10;
				village.Village_region = 1;

				if (x == 25) // первый проход
				{
					x = 25;
					y = 8;
				}
				else if (x == 26) // второй проход
				{
					x = 26;
					y = 8;
				}
				else if (x == 27) // третий проход
				{
					x = 27;
					y = 8;
				}
			}
			else if (x == 43 && y == 6)// кузнеца (вход)
			{
				Int_Last_World = 10;
				village.Village_region = 1;
				x = 43;
				y = 4;
			}
			else if (x == 43 && y == 4)// кузнеца (выход)
			{
				Int_Last_World = 10;
				village.Village_region = 1;
				x = 43;
				y = 6;
			}
			else if (x == 49 && y == 10 || x == 49 && y == 13 || x == 49 && y == 17) // 2й регион три прохода (1 -> 2)
			{
				Int_Last_World = 10;
				village.Village_region = 2;

				if (y == 10) // первый проход
				{
					x = 44;
					y = 1;
				}
				else if (y == 13) // второй проход
				{
					x = 1;
					y = 10;
				}
				else if (y == 17) // третий проход
				{
					x = 17;
					y = 23;
				}
			}
			else if (x == 27 && y == 17)// вельва (вход)
			{
				Int_Last_World = 10;
				village.Village_region = 1;
				x = 27;
				y = 19;
			}
			else if (x == 27 && y == 19)// вельва (выход)
			{
				Int_Last_World = 10;
				village.Village_region = 1;
				x = 27;
				y = 17;
			}
			else if (x == 7 && y == 18)// охотник (вход)
			{
				Int_Last_World = 10;
				village.Village_region = 1;
				x = 5;
				y = 18;
			}
			else if (x == 5 && y == 18)// охотник (выход)
			{
				Int_Last_World = 10;
				village.Village_region = 1;
				x = 7;
				y = 18;
			}
		}
		else if (village.Village_region == 2)// центральный район
		{
			if (x == 44 && y == 1 || x == 1 && y == 10 || x == 17 && y == 23) // 1й регион три прохода (2 -> 1)
			{
				Int_Last_World = 10;
				village.Village_region = 1;
				if (y == 1) // первый проход
				{
					x = 49;
					y = 10;
				}
				else if (y == 10) // второй проход
				{
					x = 49;
					y = 13;
				}
				else if (y == 23) // третий проход
				{
					x = 49;
					y = 17;
				}
			}
		}
	}
	else
	{
	//мир определен в функции void World::Next_world

		if (x == 26 && y == 1)
		{
			x = 26;
			y = 23;
		}
		else if (x == 1 && y == 13)
		{
			x = 49;
			y = 13;
		}
		else if (x == 49 && y == 13)
		{
			x = 1;
			y = 13;
		}
		else if (x == 26 && y == 23)
		{
			x = 26;
			y = 1;
		}
	}
	player.Get_player_position_X(x);
	player.Get_player_position_Y(y);
	Passage = false;
}

void World::Build_map_west_1()
{
	int rows = 0;
	int cols = 0;
	rows = Rows;
	cols = Cols;
	rows--;
	cols--;

	for (int y = 0; y < Rows; y++)
	{
		for (int x = 0; x < Cols; x++)
		{
			if (x == 26 && y == 0 || x == 50 && y == 13 || x == 26 && y == 24)
			{
				tileMap_west_1[y][x] = attr_simbol.Gate_int;
			}
			else
			{
				tileMap_west_1[y][x] = attr_simbol.Wall_int;
			}

			for (int y_in = 1; y_in < rows; y_in++)
			{
				for (int x_in = 1; x_in < cols; x_in++)
				{

					if (y_in == 6 && x_in == 7)
					{
						tileMap_west_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 4 && x_in == 21)
					{
						tileMap_west_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 10 && x_in == 33)
					{
						tileMap_west_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 3 && x_in == 40)
					{
						tileMap_west_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 19 && x_in == 5)
					{
						tileMap_west_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 13 && x_in == 17)
					{
						tileMap_west_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 18 && x_in == 28)
					{
						tileMap_west_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 20 && x_in == 41)
					{
						tileMap_west_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else
					{
						tileMap_west_1[y_in][x_in] = attr_simbol.Dark_area_int;
					}
				}
			}
		}
	}
}

void World::Build_map_west_north_2()
{
	int rows = 0;
	int cols = 0;
	rows = Rows;
	cols = Cols;
	rows--;
	cols--;

	for (int y = 0; y < Rows; y++)
	{
		for (int x = 0; x < Cols; x++)
		{
			if ( x == 50 && y == 13 || x == 26 && y == 24)
			{
				tileMap_west_north_2[y][x] = attr_simbol.Gate_int;
			}
			else
			{
				tileMap_west_north_2[y][x] = attr_simbol.Wall_int;
			}

			for (int y_in = 1; y_in < rows; y_in++)
			{
				for (int x_in = 1; x_in < cols; x_in++)
				{

					if (y_in == 6 && x_in == 7)
					{
						tileMap_west_north_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 4 && x_in == 21)
					{
						tileMap_west_north_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 10 && x_in == 33)
					{
						tileMap_west_north_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 3 && x_in == 40)
					{
						tileMap_west_north_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 19 && x_in == 5)
					{
						tileMap_west_north_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 13 && x_in == 17)
					{
						tileMap_west_north_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 18 && x_in == 28)
					{
						tileMap_west_north_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 20 && x_in == 41)
					{
						tileMap_west_north_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else
					{
						tileMap_west_north_2[y_in][x_in] = attr_simbol.Dark_area_int;
					}
				}
			}
		}
	}
}

void World::Build_map_north_1()
{
	int rows = 0;
	int cols = 0;
	rows = Rows;
	cols = Cols;
	rows--;
	cols--;

	for (int y = 0; y < Rows; y++)
	{
		for (int x = 0; x < Cols; x++)
		{
			if (x == 0 && y == 13 || x == 50 && y == 13 || x == 26 && y == 24)
			{
				tileMap_north_1[y][x] = attr_simbol.Gate_int;
			}
			else
			{
				tileMap_north_1[y][x] = attr_simbol.Wall_int;
			}

			for (int y_in = 1; y_in < rows; y_in++)
			{
				for (int x_in = 1; x_in < cols; x_in++)
				{

					if (y_in == 6 && x_in == 7)
					{
						tileMap_north_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 4 && x_in == 21)
					{
						tileMap_north_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 10 && x_in == 33)
					{
						tileMap_north_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 3 && x_in == 40)
					{
						tileMap_north_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 19 && x_in == 5)
					{
						tileMap_north_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 13 && x_in == 17)
					{
						tileMap_north_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 18 && x_in == 28)
					{
						tileMap_north_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 20 && x_in == 41)
					{
						tileMap_north_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else
					{
						tileMap_north_1[y_in][x_in] = attr_simbol.Dark_area_int;
					}
				}
			}
		}
	}
}

void World::Build_map_north_east_2()
{
	int rows = 0;
	int cols = 0;
	rows = Rows;
	cols = Cols;
	rows--;
	cols--;

	for (int y = 0; y < Rows; y++)
	{
		for (int x = 0; x < Cols; x++)
		{
			if (x == 0 && y == 13 || x == 26 && y == 24)
			{
				tileMap_north_east_2[y][x] = attr_simbol.Gate_int;
			}
			else
			{
				tileMap_north_east_2[y][x] = attr_simbol.Wall_int;
			}

			for (int y_in = 1; y_in < rows; y_in++)
			{
				for (int x_in = 1; x_in < cols; x_in++)
				{

					if (y_in == 6 && x_in == 7)
					{
						tileMap_north_east_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 4 && x_in == 21)
					{
						tileMap_north_east_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 10 && x_in == 33)
					{
						tileMap_north_east_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 3 && x_in == 40)
					{
						tileMap_north_east_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 19 && x_in == 5)
					{
						tileMap_north_east_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 13 && x_in == 17)
					{
						tileMap_north_east_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 18 && x_in == 28)
					{
						tileMap_north_east_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 20 && x_in == 41)
					{
						tileMap_north_east_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else
					{
						tileMap_north_east_2[y_in][x_in] = attr_simbol.Dark_area_int;
					}
				}
			}
		}
	}
}

void World::Build_map_east_1()
{
	int rows = 0;
	int cols = 0;
	rows = Rows;
	cols = Cols;
	rows--;
	cols--;

	for (int y = 0; y < Rows; y++)
	{
		for (int x = 0; x < Cols; x++)
		{
			if (x == 26 && y == 0 || x == 0 && y == 13 || x == 26 && y == 24)
			{
				tileMap_east_1[y][x] = attr_simbol.Gate_int;
			}
			else
			{
				tileMap_east_1[y][x] = attr_simbol.Wall_int;
			}

			for (int y_in = 1; y_in < rows; y_in++)
			{
				for (int x_in = 1; x_in < cols; x_in++)
				{

					if (y_in == 6 && x_in == 7)
					{
						tileMap_east_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 4 && x_in == 21)
					{
						tileMap_east_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 10 && x_in == 33)
					{
						tileMap_east_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 3 && x_in == 40)
					{
						tileMap_east_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 19 && x_in == 5)
					{
						tileMap_east_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 13 && x_in == 17)
					{
						tileMap_east_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 18 && x_in == 28)
					{
						tileMap_east_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 20 && x_in == 41)
					{
						tileMap_east_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else
					{
						tileMap_east_1[y_in][x_in] = attr_simbol.Dark_area_int;
					}
				}
			}
		}
	}
}

void World::Build_map_east_south_2()
{
	int rows = 0;
	int cols = 0;
	rows = Rows;
	cols = Cols;
	rows--;
	cols--;

	for (int y = 0; y < Rows; y++)
	{
		for (int x = 0; x < Cols; x++)
		{
			if (x == 26 && y == 0 || x == 0 && y == 13)
			{
				tileMap_east_south_2[y][x] = attr_simbol.Gate_int;
			}
			else
			{
				tileMap_east_south_2[y][x] = attr_simbol.Wall_int;
			}

			for (int y_in = 1; y_in < rows; y_in++)
			{
				for (int x_in = 1; x_in < cols; x_in++)
				{

					if (y_in == 6 && x_in == 7)
					{
						tileMap_east_south_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 4 && x_in == 21)
					{
						tileMap_east_south_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 10 && x_in == 33)
					{
						tileMap_east_south_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 3 && x_in == 40)
					{
						tileMap_east_south_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 19 && x_in == 5)
					{
						tileMap_east_south_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 13 && x_in == 17)
					{
						tileMap_east_south_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 18 && x_in == 28)
					{
						tileMap_east_south_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 20 && x_in == 41)
					{
						tileMap_east_south_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else
					{
						tileMap_east_south_2[y_in][x_in] = attr_simbol.Dark_area_int;
					}
				}
			}
		}
	}
}

void World::Build_map_south_1()
{
	int rows = 0;
	int cols = 0;
	rows = Rows;
	cols = Cols;
	rows--;
	cols--;

	for (int y = 0; y < Rows; y++)
	{
		for (int x = 0; x < Cols; x++)
		{
			if (x == 26 && y == 0 || x == 0 && y == 13 || x == 50 && y == 13)
			{
				tileMap_south_1[y][x] = attr_simbol.Gate_int;
			}
			else
			{
				tileMap_south_1[y][x] = attr_simbol.Wall_int;
			}

			for (int y_in = 1; y_in < rows; y_in++)
			{
				for (int x_in = 1; x_in < cols; x_in++)
				{

					if (y_in == 6 && x_in == 7)
					{
						tileMap_south_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 4 && x_in == 21)
					{
						tileMap_south_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 10 && x_in == 33)
					{
						tileMap_south_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 3 && x_in == 40)
					{
						tileMap_south_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 19 && x_in == 5)
					{
						tileMap_south_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 13 && x_in == 17)
					{
						tileMap_south_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 18 && x_in == 28)
					{
						tileMap_south_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 20 && x_in == 41)
					{
						tileMap_south_1[y_in][x_in] = attr_simbol.Save_int;
					}
					else
					{
						tileMap_south_1[y_in][x_in] = attr_simbol.Dark_area_int;
					}
				}
			}
		}
	}
}

void World::Build_map_south_west_2()
{
	int rows = 0;
	int cols = 0;
	rows = Rows;
	cols = Cols;
	rows--;
	cols--;

	for (int y = 0; y < Rows; y++)
	{
		for (int x = 0; x < Cols; x++)
		{
			if (x == 0 && y == 13 || x == 50 && y == 13)
			{
				tileMap_south_west_2[y][x] = attr_simbol.Gate_int;
			}
			else
			{
				tileMap_south_west_2[y][x] = attr_simbol.Wall_int;
			}

			for (int y_in = 1; y_in < rows; y_in++)
			{
				for (int x_in = 1; x_in < cols; x_in++)
				{

					if (y_in == 6 && x_in == 7)
					{
						tileMap_south_west_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 4 && x_in == 21)
					{
						tileMap_south_west_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 10 && x_in == 33)
					{
						tileMap_south_west_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 3 && x_in == 40)
					{
						tileMap_south_west_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 19 && x_in == 5)
					{
						tileMap_south_west_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 13 && x_in == 17)
					{
						tileMap_south_west_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 18 && x_in == 28)
					{
						tileMap_south_west_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 20 && x_in == 41)
					{
						tileMap_south_west_2[y_in][x_in] = attr_simbol.Save_int;
					}
					else
					{
						tileMap_south_west_2[y_in][x_in] = attr_simbol.Dark_area_int;
					}
				}
			}
		}
	}
}

void World::Build_map_centre_0()
{
	int rows = 0;
	int cols = 0;
	rows = Rows;
	cols = Cols;
	rows--;
	cols--;

	for (int y = 0; y < Rows; y++)
	{
		for (int x = 0; x < Cols; x++)
		{
			if (x == 26 && y == 0 || x == 0 && y == 13 || x == 50 && y == 13 || x == 26 && y == 24)
			{
				tileMap_centre_0[y][x] = attr_simbol.Gate_int;
			}
			else
			{
				tileMap_centre_0[y][x] = attr_simbol.Wall_int;
			}

			for (int y_in = 1; y_in < rows; y_in++)
			{
				for (int x_in = 1; x_in < cols; x_in++)
				{

					if (y_in == 6 && x_in == 7)
					{
						tileMap_centre_0[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 4 && x_in == 21)
					{
						tileMap_centre_0[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 10 && x_in == 33)
					{
						tileMap_centre_0[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 3 && x_in == 40)
					{
						tileMap_centre_0[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 19 && x_in == 5)
					{
						tileMap_centre_0[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 13 && x_in == 17)
					{
						tileMap_centre_0[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 18 && x_in == 28)
					{
						tileMap_centre_0[y_in][x_in] = attr_simbol.Save_int;
					}
					else if (y_in == 20 && x_in == 41)
					{
						tileMap_centre_0[y_in][x_in] = attr_simbol.Save_int;
					}
					else
					{
						tileMap_centre_0[y_in][x_in] = attr_simbol.Dark_area_int;
					}
				}
			}
		}
	}
}

