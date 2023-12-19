#include "Roman.h"
#include "Poet.h"

Roman::Roman() {
	cout << "\n���������� � ���������\n\n";
	try
	{
		setType(3);
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

		cout << "������� ������ ������������: ";
		getline(cin, this->_poems);
		if (_poems == "")
		{
			throw (string)"����������� ������� ������������";
		}

		cout << "������� ���������: ";
		getline(cin, this->_bio);
		if (_bio == "")
		{
			throw (string)"����������� ������� ���������";
		}

	}
	catch (string err)
	{
		cout << "������: " + err << endl;
		setSuccess(false);
	}
};

Roman::Roman(std::ifstream& fin) {
	setType(3);
	getline(fin, _FIO);
	getline(fin, _years);
	getline(fin, _poems);
	getline(fin, _bio);
}

Roman::~Roman()
{
	cout << "��� ������ ���������� ������ Roman" << endl;
}

void Roman::edit() {
	try
	{
		int index;
		string sTmp;
		cout << "�������� �������� ��� ���������:" << endl
			<< "[1] ���" << endl
			<< "[2] ���� �����" << endl
			<< "[3] ������ ������������" << endl
			<< "[4] ���������" << endl
			<< "��� �����: ";
		cin >> index;
		if (index < 1 || index > 4)
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
		case 4:
			cout << _bio << endl;
			cout << "����� ��������: ";
			cin >> sTmp;
			if (sTmp == "")
			{
				throw (string)"����������� ������� ���������";
			}
			_bio = sTmp;
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

void Roman::save(ofstream& fout)
{
	fout << getType() << endl
		<< this->_FIO << endl
		<< this->_years << endl
		<< this->_poems << endl
		<< this->_bio << endl;
}

void Roman::print(ostream& out)
{
	out << "\n��������\n\n"
		<< "��� : " << _FIO << endl
		<< "���� ����� : " << _years << endl
		<< "������ ������������ : " << _poems << endl
		<< "��������� : " << _bio << endl;
}
