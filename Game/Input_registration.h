#pragma once
#include <string>
#include <conio.h>

class Input_registration
{
public:
	Input_registration();

	/// <summary>
	/// ������� ��������� ������� �������
	/// </summary>
	/// <param name="Input (�� ��� ������ �������)"></param>
	/// <returns></returns>
	char Click_tracking(char Input);

	/// <summary>
	/// ��������� ������� �����
	/// </summary>
	void Input_mod();
	/// <summary>
	/// ����� ���� ����� (������� ������� -> ��������)
	/// </summary>
	bool Auto_input_mod = false;

	/// <summary>
	/// �������� ����� ������� �������
	/// </summary>
	bool Test_output = false;

private:
	/// <summary>
	/// �������� ��������� (int) ���� ������� ������
	/// </summary>
	int NUM;

};

