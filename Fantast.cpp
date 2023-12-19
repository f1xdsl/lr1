#include "Fantast.h"

Fantast::Fantast() {
	cout << "\nИнформация о поэте\n\n";
	try
	{
		setType(2);
		cin.ignore(256, '\n');
		cout << "Введите ФИО: ";
		getline(cin, this->_FIO);
		if (_FIO == "")
			throw (string)"ФИО не может быть пустым";
		setSuccess(true);

		
		cout << "Введите лучшие произведения ";
		getline(cin, this->_poems);
		if (_poems == "")
		{
			throw (string)"Некорректно введены произведения";
		}
		setSuccess(true);


		cout << "Введите сняты ли фильмы по книгам (1 - да, 0 - нет) : ";
		cin >> _films;
		setSuccess(true);

	}
	catch (string err)
	{
		cout << "Ошибка: " + err << endl;
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
	cout << "Был вызван деструктор класса Fantast" << endl;
}

void Fantast::edit() {
	try
	{
		int index;
		int iTmp;
		string sTmp;
		cout << "Выберите параметр для изменения:" << endl
			<< "[1] ФИО" << endl
			<< "[2] Лучшие произведения" << endl
			<< "[3] Сняты ли фильмы по книгам" << endl
			<< "Ваш выбор: ";
		cin >> index;
		if (index < 1 || index > 3)
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

			cout << _poems << endl;
			cout << "Новое значение: ";
			cin >> sTmp;
			if (sTmp == "")
			{
				throw (string)"Некорректно введены произведения";
			}
			_poems = sTmp;
			break;

		case 3:
			cout << _films << endl;
			cout << "Новое значение: ";
			cin.ignore(256, '\n');
			cin >> iTmp;
			if (iTmp < 0 || iTmp > 1)
				throw (string)"Некорретно введен параметр";
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
	out << "\nФантаст\n\n"
		<< "ФИО : " << _FIO << endl
		<< "Лучшие произведения : " << _poems << endl
		<< "Сняты ли фильмы по произведениям : " << _films << endl;
}
