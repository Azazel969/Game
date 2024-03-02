#pragma once
#include <string>
#include <fstream>
#include "Character.h"
#include"Input_registration.h"

struct Name_save_files
{
	/// <summary>
	/// ��� ����� �� ���������
	/// </summary>
	std::string DEF_name_file = "Game_save_N.txt";

	/// <summary>
	/// ��� ����� ����������� �������� ����� ������
	/// </summary>
	std::string path_sv_DEF = DEF_name_file;

	/// <summary>
	/// ��� ����� � ������� ����������� �1
	/// </summary>
	std::string path_sv_1 = DEF_name_file;

	/// <summary>
	/// true - ���� 1 �����
	/// </summary>
	bool Bl_path_sv_1 = false;

	/// <summary>
	/// ��� ����� � ������� ����������� �2
	/// </summary>
	std::string path_sv_2 = DEF_name_file;

	/// <summary>
	/// true - ���� 2 �����
	/// </summary>
	bool Bl_path_sv_2 = false;

	/// <summary>
	/// ��� ����� � ������� ����������� �3
	/// </summary>
	std::string path_sv_3 = DEF_name_file;

	/// <summary>
	/// true - ���� 3 �����
	/// </summary>
	bool Bl_path_sv_3 = false;
};

struct File_save_name
{
	/// <summary>
	/// �������� � ���������� ��� ����� |
	/// ��� �������� ����� ������ true |
	/// ��� ������ ������ false � ��������� �� �����
	/// </summary>
	/// <param name="path_sv_DEF - ��� �����"></param>
	/// <param name="Namber_file - ���� ����������"></param>
	bool Create_name(std::string& path_sv_DEF, char Namber_file = '0');

	/// <summary>
	/// ��� ����� ��� ���������� ��������� ������
	/// </summary>
	std::string path_sys = "System.txt";

	/// <summary>
	/// ����� ������ ����������
	/// </summary>
	Name_save_files Name_save_files;

};


class Files
{
public:

	Files();

	/// <summary>
	/// ��������/�������� ������
	/// </summary>
	void Load_File();

	/// <summary>
	/// ������ � �������
	/// </summary>
	/// <param name="action = 0-������/ 1-������, 2-������� �����"></param>
	/// <param name="File = 1 - System.txt (��������� Slot_sv = 0) , 2 - ������ � ������� ���������� (��������� Slot_sv != 0)"></param>
	/// <param name="Slot_sv - ���� ����������"></param>
	void Working_file(int action, int File, char Slot_save, Character& player, Input_registration& input_registration);

	/// <summary>
	/// �������� ����� ����� / �������� ����� � ������ ����� ���������
	/// </summary>
	/// <param name="Namber_file - ����� ����� ����������"></param>
	void File_name(char Namber_file);

public:
	/// <summary>
	/// ������������ ������� ������ ����������
	/// </summary>
	bool File_save = false;

	/// <summary>
	/// �������� ������
	/// </summary>
	bool Load_file = false;

	/// <summary>
	/// ����� ������ ���������
	/// </summary>
	File_save_name File_save_name;

private:

	Input_registration input_registration;

	Character player; /// <summary>������: ������� �������� </summary>

	/// <summary> ������ �� ����� </summary>
	/// <param name="File - ��� ����� 1 - ��������� ����, 2 - ����� ����������(Slot_sv =! 0) (0 - ��� �����)"></param>
	void Read(Character& player, Input_registration& input_registration, int File);

	/// <summary> ������ � ���� </summary>
	/// <param name="File - ��� ����� 1 - ��������� ����, 2 - ����� ����������(Slot_sv =! 0) (0 - ��� �����)"></param>
	/// <param name="Slot_sv - ����� ����� ����������"></param>
	void Write(Character& player, Input_registration& input_registration, int File, char Slot_sv);

	/// <summary>
	/// ������� ������/������ ����������
	/// </summary>
	/// <param name="File - ��� ����� 1 - ��������� ����, 2 - ����� ����������(Slot_sv =! 0) (0 - ��� �����)"></param>
	/// <param name="Slot_sv - ����� ����� ����������"></param>
	void Clean_file(int File, char Slot_sv);

	/// <summary>
	/// ������ �������� �����
	/// </summary>
	void OpenError();

	/// <summary>
	/// ������
	/// </summary>
	std::ifstream fin;

	/// <summary>
	/// ������
	/// </summary>
	std::ofstream fout;

	/// <summary>
	/// ���������� ��� ��������/�������� ������
	/// </summary>
	std::string Path;
};

