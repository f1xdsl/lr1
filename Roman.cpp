#include "Roman.h"
#include "Poet.h"

Roman::Roman() {
	cout << "\nИнформация о Романисте\n\n";
	try
	{
		setType(3);
		cin.ignore(256, '\n');
		cout << "Введите ФИО: ";
		getline(cin, this->_FIO);
		if (_FIO == "")
			throw (string)"ФИО не может быть пустым";
		setSuccess(true);

		cout << "Введите годы жизни: ";
		getline(cin, this->_years);
		if (_years == "")
			throw (string)"Некорретно введены годы жизни";
		setSuccess(true);

		cout << "Введите лучшие произведения: ";
		getline(cin, this->_poems);
		if (_poems == "")
		{
			throw (string)"Некорректно введены произведения";
		}

		cout << "Введите биографию: ";
		getline(cin, this->_bio);
		if (_bio == "")
		{
			throw (string)"Некорректно введена биография";
		}

	}
	catch (string err)
	{
		cout << "Ошибка: " + err << endl;
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
	cout << "Был вызван деструктор класса Roman" << endl;
}

void Roman::edit() {
	try
	{
		int index;
		string sTmp;
		cout << "Выберите параметр для изменения:" << endl
			<< "[1] ФИО" << endl
			<< "[2] Годы жизни" << endl
			<< "[3] Лучшие произведения" << endl
			<< "[4] Биография" << endl
			<< "Ваш выбор: ";
		cin >> index;
		if (index < 1 || index > 4)
		{
			throw (string)"Параметра с данным индексом не существует";
		}
		cout << "Исходное значение: ";
		switch (index)
		{
		case 1:
			cout << this->_FIO << endl;
			cout << "Новое значение: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			if (sTmp == "")
				throw (string)"ФИО не может быть пустым";
			_FIO = sTmp;
			break;
		case 2:
			cout << _years << endl;
			cout << "Новое значение: ";
			cin.ignore(256, '\n');
			getline(cin, sTmp);
			if (sTmp == "")
				throw (string)"Некорретно введены годы жизни";
			_years = sTmp;
			break;
		case 3:
			cout << _poems << endl;
			cout << "Новое значение: ";
			cin >> sTmp;
			if (sTmp == "")
			{
				throw (string)"Некорректно введены произведения";
			}
			_poems = sTmp;
			break;
		case 4:
			cout << _bio << endl;
			cout << "Новое значение: ";
			cin >> sTmp;
			if (sTmp == "")
			{
				throw (string)"Некорректно введена биография";
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
	out << "\nРоманист\n\n"
		<< "ФИО : " << _FIO << endl
		<< "Годы жизни : " << _years << endl
		<< "Лучшие произведения : " << _poems << endl
		<< "Биография : " << _bio << endl;
}
