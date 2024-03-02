#pragma once
#include <string>
#include <fstream>
#include "Character.h"
#include"Input_registration.h"

struct Name_save_files
{
	/// <summary>
	/// имя файла по умолчанию
	/// </summary>
	std::string DEF_name_file = "Game_save_N.txt";

	/// <summary>
	/// имя файла принимающее вводимые имена файлов
	/// </summary>
	std::string path_sv_DEF = DEF_name_file;

	/// <summary>
	/// имя файла с игровым сохранением №1
	/// </summary>
	std::string path_sv_1 = DEF_name_file;

	/// <summary>
	/// true - слот 1 занят
	/// </summary>
	bool Bl_path_sv_1 = false;

	/// <summary>
	/// имя файла с игровым сохранением №2
	/// </summary>
	std::string path_sv_2 = DEF_name_file;

	/// <summary>
	/// true - слот 2 занят
	/// </summary>
	bool Bl_path_sv_2 = false;

	/// <summary>
	/// имя файла с игровым сохранением №3
	/// </summary>
	std::string path_sv_3 = DEF_name_file;

	/// <summary>
	/// true - слот 3 занят
	/// </summary>
	bool Bl_path_sv_3 = false;
};

struct File_save_name
{
	/// <summary>
	/// Создание и сохранение имя файла |
	/// при создании файла вернет true |
	/// при ошибке вернет false и сообщение на экран
	/// </summary>
	/// <param name="path_sv_DEF - имя файла"></param>
	/// <param name="Namber_file - слот сохранения"></param>
	bool Create_name(std::string& path_sv_DEF, char Namber_file = '0');

	/// <summary>
	/// имя файла для сохранения системных данных
	/// </summary>
	std::string path_sys = "System.txt";

	/// <summary>
	/// имена файлов сохранения
	/// </summary>
	Name_save_files Name_save_files;

};


class Files
{
public:

	Files();

	/// <summary>
	/// Создание/проверка файлов
	/// </summary>
	void Load_File();

	/// <summary>
	/// Работа с файлами
	/// </summary>
	/// <param name="action = 0-запись/ 1-чтение, 2-очистка файла"></param>
	/// <param name="File = 1 - System.txt (указывать Slot_sv = 0) , 2 - работа с файлами срхранения (указывать Slot_sv != 0)"></param>
	/// <param name="Slot_sv - слот сохранения"></param>
	void Working_file(int action, int File, char Slot_save, Character& player, Input_registration& input_registration);

	/// <summary>
	/// Создание имени файла / создание файла в нужном слоте схранения
	/// </summary>
	/// <param name="Namber_file - номер слота сохранения"></param>
	void File_name(char Namber_file);

public:
	/// <summary>
	/// отслеживание наличия файлов сохранения
	/// </summary>
	bool File_save = false;

	/// <summary>
	/// Загрузка файлов
	/// </summary>
	bool Load_file = false;

	/// <summary>
	/// Имена файлов программы
	/// </summary>
	File_save_name File_save_name;

private:

	Input_registration input_registration;

	Character player; /// <summary>Объект: Игровой персонаж </summary>

	/// <summary> Чтение из файла </summary>
	/// <param name="File - вид файла 1 - системный файл, 2 - файлы сохранения(Slot_sv =! 0) (0 - все файлы)"></param>
	void Read(Character& player, Input_registration& input_registration, int File);

	/// <summary> Запись в файл </summary>
	/// <param name="File - вид файла 1 - системный файл, 2 - файлы сохранения(Slot_sv =! 0) (0 - все файлы)"></param>
	/// <param name="Slot_sv - номер слота сохранения"></param>
	void Write(Character& player, Input_registration& input_registration, int File, char Slot_sv);

	/// <summary>
	/// очистка файлов/первое заполнение
	/// </summary>
	/// <param name="File - вид файла 1 - системный файл, 2 - файлы сохранения(Slot_sv =! 0) (0 - все файлы)"></param>
	/// <param name="Slot_sv - номер слота сохранения"></param>
	void Clean_file(int File, char Slot_sv);

	/// <summary>
	/// ошибка открытия файла
	/// </summary>
	void OpenError();

	/// <summary>
	/// чтение
	/// </summary>
	std::ifstream fin;

	/// <summary>
	/// запись
	/// </summary>
	std::ofstream fout;

	/// <summary>
	/// переменная для создания/проверки файлов
	/// </summary>
	std::string Path;
};

