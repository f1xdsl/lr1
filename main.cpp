#include <iostream>
#include "Keeper.h"
#include <Windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Keeper Writers;
	int menu;
	do
	{
		system("cls");
		cout << "----------------------------------" << endl
			<< " ���� " << endl
			<< "----------------------------------" << endl
			<< "���-�� ��������� � ���������� : [" << Writers.getSize()
			<< "]" << endl
			<< "[1] �������� �������" << endl
			<< "[2] ������� �������" << endl
			<< "[3] ��������� ������ � ����" << endl
			<< "[4] ��������� ������ �� �����" << endl
			<< "[5] �������� ������ ��������" << endl
			<< "[6] ������� ������ �� ����������" << endl
			<< "[0] �����" << endl;
		cin >> menu;
		system("cls");
		switch (menu)
		{
		case 1:
			Writers.add();
			break;
		case 2:
			Writers.del();
			break;
		case 3:
			Writers.save();
			break;
		case 4:
			Writers.load();
			break;
		case 5:
			Writers.edit();
			break;
		case 6:
			cout << Writers;
			break;
		case 0:
			return 0;
		default:
			break;
		}
		/*����*/
	} while (true);
}