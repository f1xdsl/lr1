#include "Poet.h"

Poet::Poet(){
	cout << "\n���������� � �����\n\n";
	try
	{
		setType(1);
		cin.ignore(256, '\n');
		cout << "������� ���: ";
		getline(cin, this->_FIO);
		if (_FIO == "")
			throw (string)"��� �� ����� ���� ������";
		setSuccess(true);

		cout << "������� ���� �����: ";
		getline(cin, this->_years);
		if (_years == "")
			throw (string)"���������� ������� ���� �����";
		setSuccess(true);

		cout << "������� ������ ������������";
		getline(cin, this->_poems);
		if (_poems == "")
		{
			throw (string)"����������� ������� ������������";
		}

	}
	catch (string err)
	{
		cout << "������: " + err << endl;
		setSuccess(false);
	}
};

Poet::Poet(std::ifstream& fin) {
	setType(1);
	getline(fin, _FIO);
	getline(fin, _years);
	getline(fin, _poems);
}

Poet::~Poet()
{
	cout << "��� ������ ���������� ������ Poet" << endl;
}

void Poet::edit() {
	try
	{
		int index;
		string sTmp;
		cout << "�������� �������� ��� ���������:" << endl
			<< "[1] ���" << endl
			<< "[2] ���� �����" << endl
			<< "[3] ������ ������������" << endl
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
			cout << _years << endl;
			cout << "����� ��������: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			if (sTmp == "")
				throw (string)"���������� ������� ���� �����";
			_years = sTmp;
			break;
		case 3:
			cout << _poems << endl;
			cout << "����� ��������: ";
			cin >> sTmp;
			if (sTmp == "")
			{
				throw (string)"����������� ������� ������������";
			}
			_poems = sTmp;
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

void Poet::save(ofstream& fout)
{
	fout << getType() << endl
		<< this->_FIO << endl
		<< this->_years << endl
		<< this->_poems << endl;
}

void Poet::print(ostream& out)
{
	out << "\n����\n\n"
		<< "��� : " << _FIO << endl
		<< "���� ����� : " << _years << endl
		<< "������ ������������ : " << _poems << endl;
}
