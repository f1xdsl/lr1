#include "Fantast.h"

Fantast::Fantast() {
	cout << "\n���������� � �����\n\n";
	try
	{
		setType(2);
		cin.ignore(256, '\n');
		cout << "������� ���: ";
		getline(cin, this->_FIO);
		if (_FIO == "")
			throw (string)"��� �� ����� ���� ������";
		setSuccess(true);

		
		cout << "������� ������ ������������ ";
		getline(cin, this->_poems);
		if (_poems == "")
		{
			throw (string)"����������� ������� ������������";
		}
		setSuccess(true);


		cout << "������� ����� �� ������ �� ������ (1 - ��, 0 - ���) : ";
		cin >> _films;
		setSuccess(true);

	}
	catch (string err)
	{
		cout << "������: " + err << endl;
		setSuccess(false);
	}
};

Fantast::Fantast(std::ifstream& fin) {
	setType(2);
	getline(fin, _FIO);
	getline(fin, _poems);
	fin >> _films;
}

Fantast::~Fantast()
{
	cout << "��� ������ ���������� ������ Fantast" << endl;
}

void Fantast::edit() {
	try
	{
		int index;
		int iTmp;
		string sTmp;
		cout << "�������� �������� ��� ���������:" << endl
			<< "[1] ���" << endl
			<< "[2] ������ ������������" << endl
			<< "[3] ����� �� ������ �� ������" << endl
			<< "��� �����: ";
		cin >> index;
		if (index < 1 || index > 3)
		{
			throw (string)"��������� � ������ �������� �� ����������";
		}
		cout << "�������� ��������: ";
		switch (index)
		{
		case 1:
			cout << this->_FIO << endl;
			cout << "����� ��������: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			if (sTmp == "")
				throw (string)"��� �� ����� ���� ������";
			_FIO = sTmp;
			break;
		case 2:

			cout << _poems << endl;
			cout << "����� ��������: ";
			cin >> sTmp;
			if (sTmp == "")
			{
				throw (string)"����������� ������� ������������";
			}
			_poems = sTmp;
			break;

		case 3:
			cout << _films << endl;
			cout << "����� ��������: ";
			cin.ignore(256, '\n');
			cin >> iTmp;
			if (iTmp < 0 || iTmp > 1)
				throw (string)"���������� ������ ��������";
			_films = iTmp;
			break;
		default:
			break;
		}
		setSuccess(true);
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		setSuccess(false);
	}
}

void Fantast::save(ofstream& fout)
{
	fout << getType() << endl
		<< this->_FIO << endl
		<< this->_poems << endl
		<< this->_films << endl;
}

void Fantast::print(ostream& out)
{
	out << "\n�������\n\n"
		<< "��� : " << _FIO << endl
		<< "������ ������������ : " << _poems << endl
		<< "����� �� ������ �� ������������� : " << _films << endl;
}
