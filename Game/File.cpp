#include "File.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Character.h"
#include "Input_registration.h"

Files::Files()
{
	Working_file(1, 1, 0, player, input_registration);
}

void Files::Load_File()
{
	if (!Load_file)
	{
		for (int file = 0; file < 4; file++)
		{
			switch (file)
			{
			case 1:
			{
				Path = File_save_name.path_sys;

				fout.open(Path, std::ofstream::app);

				if (!fout.is_open())
				{
					std::cout << "Ошибка открытия файла (System.txt)" << std::endl;
					system("pause");
				}
				else
				{
					fout.close();
					Clean_file(1, 0);
				}

				break;
			}
			case 2:
			{
				Path = File_save_name.Name_save_files.path_sv_1;

				fout.open(Path, std::ofstream::app);

				if (!fout.is_open())
				{
					std::cout << "Ошибка открытия файла (Game_save.txt)" << std::endl;
					system("pause");
				}
				else
				{
					fout.close();
					Clean_file(2, 1);
				}

				break;
			}
			case 3:
			{
				Load_file = true;
				Working_file(0, 1, 0, player, input_registration);
				break;
			}
			default:
				break;
			}
		}
	}
}

void Files::Working_file(int action, int File, char Slot_save, Character& player, Input_registration& input_registration)
{
	// проверка получения номера слота сохранения
	if (Slot_save == '0' && File == '2')
	{
		char _slot_sv_ = '0';
		std::cout << " Программа не смогла получить номер слота сохранения" << std::endl;
		std::cout << " введите номер(int) вручную (не ошибитесь, это может сказаться на стабильности пррограммы):" << std::endl;
		std::cout << " при не корректном вводе, выполнение продолжится со слотом номер 1" << std::endl;
		std::cin >> _slot_sv_;

		if (_slot_sv_ != '1')
		{
			if (_slot_sv_ != '2')
			{
				if (_slot_sv_ != '3')
				{
					Slot_save = '1';
				}
				else
				{
					Slot_save = _slot_sv_;
				}
			}
			else
			{
				Slot_save = _slot_sv_;
			}
		}
		else
		{
			Slot_save = _slot_sv_;
		}

	}

	switch (action)
	{
	case 0:
	{
		Write(player,input_registration, File, Slot_save);
		break;
	}
	case 1:
	{
		Read(player, input_registration, File);
		break;
	}
	case 2:
	{
		Clean_file(File, Slot_save);
		break;
	}
	default:
		std::cout << " Не корректный ввод" << std::endl;
		system("pause");
		break;
	}
}

void Files::Read(Character& player, Input_registration& input_registration, int File)
{
	std::string str;

	switch (File)
	{
	case 1:

		Path = File_save_name.path_sys;
 
		fin.open(Path, std::ofstream::app);

		if (!fin.is_open())
		{
			std::cout << "Ошибка окрытия файла (" << Path << ")" << std::endl;
			system("pause");
		}
		else
		{
			bool if_SV_ran = false;
			bool if_SV_path_1 = false;
			bool if_SV_path_2 = false;
			bool if_SV_path_3 = false;

			bool if_AU_ran = false;
			bool if_LD_ran = false;

			int i = 0;
			int Int_Bl_AU = 0;
			int Int_Bl_LD = 0;

			while (!fin.eof())
			{
				str = "";

				std::getline(fin, str);

				if (str == "SV" || if_SV_ran)
				{
					if (str == "SV")
					{
						if_SV_ran = true;
					}
					else if (if_SV_ran)
					{
						if (str == "Path_sv_1")
						{
							if_SV_path_1 = true;
							
						}
						else if (if_SV_path_1)
						{
							if (str != "NULL")
							{
								if (str != File_save_name.Name_save_files.DEF_name_file)
								{
									File_save_name.Name_save_files.path_sv_1 = str;
									if_SV_path_1 = false;
									File_save = true;
									File_save_name.Name_save_files.Bl_path_sv_1 = true;
								}
								else
								{
									if_SV_path_1 = false;
									File_save_name.Name_save_files.Bl_path_sv_1 = false;
								}
							}
							else
							{
								File_save_name.Name_save_files.path_sv_1 = File_save_name.Name_save_files.DEF_name_file;
								File_save_name.Name_save_files.Bl_path_sv_1 = false;
								if_SV_path_1 = false;
							}
						}
						else if (str == "Path_sv_2")
						{
							if_SV_path_2 = true;
						}
						else if (if_SV_path_2)
						{
							if (str != "NULL")
							{
								if (str != File_save_name.Name_save_files.DEF_name_file)
								{
									File_save_name.Name_save_files.path_sv_2 = str;
									File_save_name.Name_save_files.Bl_path_sv_2 = true;
									if_SV_path_2 = false;
									File_save = true;
								}
								else
								{
									if_SV_path_2 = false;
									File_save_name.Name_save_files.Bl_path_sv_2 = false;
								}
							}
							else
							{
								File_save_name.Name_save_files.path_sv_3 = File_save_name.Name_save_files.DEF_name_file;
								File_save_name.Name_save_files.Bl_path_sv_2 = false;
								if_SV_path_2 = false;
							}
						}
						else if (str == "Path_sv_3")
						{
							if_SV_path_3 = true;
						}
						else if (if_SV_path_3)
						{
							if (str != "NULL")
							{
								if (str != File_save_name.Name_save_files.DEF_name_file)
								{
									File_save_name.Name_save_files.path_sv_3 = str;
									File_save_name.Name_save_files.Bl_path_sv_3 = true;
									if_SV_path_3 = false;
									File_save = true;
								}
								else
								{
									if_SV_path_3 = false;
									File_save_name.Name_save_files.Bl_path_sv_3 = false;
								}
							}
							else
							{
								File_save_name.Name_save_files.path_sv_3 = File_save_name.Name_save_files.DEF_name_file;
								File_save_name.Name_save_files.Bl_path_sv_3 = false;
								if_SV_path_3 = false;
							}
							if_SV_ran = false;
						}
						else
						{
							std::cout << "Ошибка получения данных из файла (System.txt)" << std::endl;
							if_SV_ran = false;
							system("pause");
						}
						
					}
				}
				else if (str == "AU" || if_AU_ran)
				{
					if (str == "AU")
					{
						i = 1;
						if_AU_ran = true;
					}
					else if (if_AU_ran)
					{
						Int_Bl_AU = stoi(str);

						if (Int_Bl_AU == 1)
						{
							input_registration.Auto_input_mod = true;
						}
						else if (Int_Bl_AU == 0)
						{
							input_registration.Auto_input_mod = false;
						}
						else
						{
							input_registration.Auto_input_mod = false;
							std::cout << "Ошибка получения данных из файла (System.txt)" << std::endl;
							std::cout << "\n Не читаемый результат, продолжение программы с результатом false" << std::endl;
							system("pause");
						}
						i = 0;
						if_AU_ran = false;
					}
				}
				else if (str == "LD" || if_LD_ran)
				{
					if (str == "LD")
					{
						i = 1;
						if_LD_ran = true;
					}
					else if (if_LD_ran)
					{
						Int_Bl_LD = stoi(str);

						if (Int_Bl_LD == 1)
						{
							Load_file = true;
						}
						else if (Int_Bl_LD == 0)
						{
							Load_file = false;
						}
						else
						{
							Load_file = false;
							std::cout << "Ошибка получения данных из файла (System.txt)" << std::endl;
							std::cout << "\n Не читаемый результат, продолжение программы с результатом false" << std::endl;
							system("pause");
						}
						i = 0;
						if_LD_ran = false;
					}
				}
				else if (str == "")
				{
					Load_File();
				}
			}
		}

		fin.close();
		break;
	case 2:

		Path = File_save_name.Name_save_files.path_sv_1;

		fin.open(Path, std::ofstream::app);

		if (!fin.is_open())
		{
			std::cout << "Ошибка окрытия файла (" << Path << ")" << std::endl;
			system("pause");
		}
		else
		{
			bool if_ATTR_tan = false;
			bool if_SYS_ran = false;
			bool if_POS_ran = false;

			int i = 0;

			while (!fin.eof())
			{
				str = "";

				std::getline(fin, str);

				if (str == "NULL")
				{
					continue;
				}
				else if (str == "ATTR" || if_ATTR_tan)
				{
					if (str == "ATTR")
					{
						i = 1;
						if_ATTR_tan = true;
					}
					else if (if_ATTR_tan)
					{
						if (i == 1)
						{
							player._PlayerAttributes.name_Character = str;
							i++;
						}
						else if (i == 2)
						{
							player._PlayerAttributes.P_Levl = stoi(str);
							i++;
						}
						else if (i == 3)
						{
							player._PlayerAttributes.P_XP = stoi(str);
							i++;
						}
						else if (i == 4)
						{
							player._PlayerAttributes.P_Hp = stoi(str);
							i++;
						}
						else if (i == 5)
						{
							player._PlayerAttributes.P_Mana = stoi(str);
							i++;
						}
						else if (i == 6)
						{
							player._PlayerAttributes.P_stamina = stoi(str);
							i = 0;

							if_ATTR_tan = false;
						}
					}
				}
				else if (str == "SYS" || if_SYS_ran)
				{
					if (str == "SYS")
					{
						i = 1;
						if_SYS_ran = true;
					}
					else if (if_SYS_ran)
					{
						if (i == 1)
						{
							player._PlayerAttributes._SystemParam.int_name_Class = stoi(str);
							i++;
						} 
						else if (i == 2)
						{/////////////////////////////  Можно убирать
							player._PlayerAttributes._SystemParam.Load_save = stoi(str);
							i++;
						}/////////////////////////////
						else if (i == 3)
						{
							player._PlayerAttributes._SystemParam.Overview = stoi(str);
							i = 0;

							if_SYS_ran = false;
						}
					}
				}
				else if (str == "POS" || if_POS_ran)
				{
					if (str == "POS")
					{
						i = 1;
						if_POS_ran = true;
					}
					else if (if_POS_ran)
					{
						if (i == 1)
						{
							player._PlayerAttributes._SystemParam._Position.Int_World = stoi(str);
							i++;
						}
						else if (i == 2)
						{
							player._PlayerAttributes._SystemParam._Position.x = stoi(str);
							i++;
						}
						else if (i == 3)
						{
							player._PlayerAttributes._SystemParam._Position.y = stoi(str);
							i = 0;

							if_POS_ran = false;
						}
					}
				}
			}
		}

		fin.close();

		break;

	default:
		break;
	}
}

void Files::Write(Character& player, Input_registration& input_registration, int File, char Slot_sv)
{
	Path = "";

	switch (File)
	{
	case 1:
		Path = File_save_name.path_sys;
		break;
	case 2:
		
		switch (Slot_sv)
		{
		case '1':
			Path = File_save_name.Name_save_files.path_sv_1;
			break;

		case '2':
			Path = File_save_name.Name_save_files.path_sv_2;
			break;

		case '3':
			Path = File_save_name.Name_save_files.path_sv_3;
			break;
		}
		break;
	default:
		break;
	}

	switch (File)
	{
	case 1:
	{
		fout.open(Path);

		if (!fout.is_open())
		{
			std::cout << "Ошибка окрытия файла (System.txt)" << std::endl;
			system("pause");
		}
		else
		{
			fout << "SV";

			if (File_save_name.Name_save_files.path_sv_1 == "")
			{
				fout << "\n" << "Path_sv_1";
				fout << "\n" << "NULL";
			}
			else
			{
				fout << "\n" << "Path_sv_1";
				fout << "\n" << File_save_name.Name_save_files.path_sv_1;
			}

			if (File_save_name.Name_save_files.path_sv_2 == "")
			{
				fout << "\n" << "Path_sv_2";
				fout << "\n" << "NULL";
			}
			else
			{
				fout << "\n" << "Path_sv_2";
				fout << "\n" << File_save_name.Name_save_files.path_sv_2;
			}

			if (File_save_name.Name_save_files.path_sv_3 == "")
			{
				fout << "\n" << "Path_sv_3";
				fout << "\n" << "NULL";
			}
			else
			{
				fout << "\n" << "Path_sv_3";
				fout << "\n" << File_save_name.Name_save_files.path_sv_3;
			}

			fout << "\n"<<"AU";

			fout << "\n" << input_registration.Auto_input_mod;

			fout << "\n" << "LD";

			fout << "\n" << Load_file;
		}

		fout.close();

		break;
	}
	case 2:
	{
		fout.open(File_save_name.Name_save_files.path_sv_1);

		if (!fout.is_open())
		{
			std::cout << "Ошибка окрытия файла (Game_save.txt)" << std::endl;
			system("pause");
		}
		else
		{
			fout << "ATTR";

			fout << "\n" << player._PlayerAttributes.name_Character;

			fout << "\n" << player._PlayerAttributes.P_Levl;

			fout << "\n" << player._PlayerAttributes.P_XP;

			fout << "\n" << player._PlayerAttributes.P_Hp;

			fout << "\n" << player._PlayerAttributes.P_Mana;

			fout << "\n" << player._PlayerAttributes.P_stamina;

			fout << "\n" << "SYS";

			fout << "\n" << player._PlayerAttributes._SystemParam.int_name_Class;

			player._PlayerAttributes._SystemParam.Load_save = true;
			File_save = true;

			fout << "\n" << player._PlayerAttributes._SystemParam.Load_save;

			fout << "\n" << player._PlayerAttributes._SystemParam.Overview;

			fout << "\n" << "POS";

			fout << "\n" << player._PlayerAttributes._SystemParam._Position.Int_World;

			fout << "\n" << player._PlayerAttributes._SystemParam._Position.x;

			fout << "\n" << player._PlayerAttributes._SystemParam._Position.y;

		}
	
		fout.close();

		break;
	}
	default:
		break;
	}
}

void Files::Clean_file(int File, char Slot_sv)
{
	switch (File)
	{
	case 1:
	{
		Path = File_save_name.path_sys;

		fout.open(Path);

		if (!fout.is_open())
		{
			std::cout << "Ошибка окрытия файла (System.txt)" << std::endl;
			system("pause");
		}
		else
		{
			fout << "SV";

			if (File_save_name.Name_save_files.DEF_name_file == "")
			{
				fout << "\n" << "Path_sv_1";
				fout << "\n" << "NULL";
			}
			else
			{
				fout << "\n" << "Path_sv_1";
				fout << "\n" << File_save_name.Name_save_files.DEF_name_file;
			}

			if (File_save_name.Name_save_files.DEF_name_file == "")
			{
				fout << "\n" << "Path_sv_2";
				fout << "\n" << "NULL";
			}
			else
			{
				fout << "\n" << "Path_sv_2";
				fout << "\n" << File_save_name.Name_save_files.DEF_name_file;
			}

			if (File_save_name.Name_save_files.DEF_name_file == "")
			{
				fout << "\n" << "Path_sv_3";
				fout << "\n" << "NULL";
			}
			else
			{
				fout << "\n" << "Path_sv_3";
				fout << "\n" << File_save_name.Name_save_files.DEF_name_file;
			}

			fout << "\n" << "AU";

			fout << "\n" << 0;

			fout << "\n" << "LD";

			fout << "\n" << 0;
			fout.close();
		}

		break;
	}
	case 2:
	{
		switch (Slot_sv)
		{
		case '1':
			Path = File_save_name.Name_save_files.path_sv_1;
			//File_save_name.Name_save_files.path_sv_1 = File_save_name.Name_save_files.DEF_name_file;
			//File_save_name.Name_save_files.Bl_path_sv_1 = false;
			break;
		case '2':
			Path = File_save_name.Name_save_files.path_sv_2;
			//File_save_name.Name_save_files.path_sv_2 = File_save_name.Name_save_files.DEF_name_file;
			//File_save_name.Name_save_files.Bl_path_sv_2 = false;
			break;
		case '3':
			Path = File_save_name.Name_save_files.path_sv_3;
			//File_save_name.Name_save_files.path_sv_3 = File_save_name.Name_save_files.DEF_name_file;
			//File_save_name.Name_save_files.Bl_path_sv_2 = false;
			break;
		}

		fout.open(Path);

		if (!fout.is_open())
		{
			std::cout << "Ошибка окрытия файла + " << Path << std::endl;
			system("pause");
		}
		else
		{
			fout << "ATTR";

			fout << "\n" << "NULL";

			fout << "\n" << "NULL";

			fout << "\n" << "NULL";

			fout << "\n" << "NULL";

			fout << "\n" << "NULL";

			fout << "\n" << "NULL";

			fout << "\n" << "SYS";

			fout << "\n" << "NULL";

			fout << "\n" << "NULL";

			fout << "\n" << "NULL";

			fout << "\n" << "POS";

			fout << "\n" << "NULL";

			fout << "\n" << "NULL";

			fout << "\n" << "NULL";
			fout.close();
		}

		break;
	}
	default:
		break;
	}
}

void Files::File_name(char Namber_file)
{
	bool ran = false;

	while (!ran)
	{
		system("CLS");

		std::cout << " Ведите имя файла с указанием расширения (.txt):";

		std::cin >> File_save_name.Name_save_files.path_sv_DEF;

		ran = File_save_name.Create_name(File_save_name.Name_save_files.path_sv_DEF, Namber_file);
	}

	Clean_file(2, Namber_file);


}

bool File_save_name::Create_name(std::string& path_sv_DEF, char Namber_file)
{
	if (Namber_file == '1')
	{
		if (!Name_save_files.Bl_path_sv_1)
		{
			Name_save_files.path_sv_1 = path_sv_DEF;
			Name_save_files.Bl_path_sv_1 = true;
			return true;
		}
		else
		{
			std::cout << " Слот занят, выберите другой" << std::endl;
			return false;
		}
	}
	else if (Namber_file == '2')
	{
		if (!Name_save_files.Bl_path_sv_2)
		{
			Name_save_files.path_sv_2 = path_sv_DEF;
			Name_save_files.Bl_path_sv_2 = true;
			return true;
		}
		else
		{
			std::cout << " Слот занят, выберите другой" << std::endl;
			return false;
		}
	}
	else if (Namber_file == '3')
	{
		if (!Name_save_files.Bl_path_sv_3)
		{
			Name_save_files.path_sv_3 = path_sv_DEF;
			Name_save_files.Bl_path_sv_3 = true;
			return true;
		}
		else
		{
			std::cout << " Слот занят, выберите другой" << std::endl;
			return false;
		}
	}
	else
	{
		std::cout << " Не существует слота с таким номером" << std::endl;
		return false;
	}
}
