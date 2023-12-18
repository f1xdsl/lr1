#include "Keeper.h"


Keeper::Keeper()
{
	this->data = nullptr;
	this->size = 0;
}


Keeper::~Keeper()
{
	delete[] data;
}


int Keeper::getSize()
{
	return size;
}


void Keeper::add()
{
	int type; // Тип наследника
	
	try
	{
		cout << "Выберите тип: " << endl
			<< "[1] Поэт" << endl
			<< "[2] Фантаст" << endl
			<< "[3] Романист" << endl
			<< "Ваш выбор: ";
		cin >> type;
		
		if (type > 3 || type < 1)
		{
			throw (string)"Выбран не правильный класс наследника";
		}

		Writer** tmp = new Writer * [size + 1];

		for (int i = 0; i < size; i++)
		{
			tmp[i] = data[i];
		}
		switch (type)
		{
		case 1:
			tmp[size] = new Poet;
			break;
		case 2:
			tmp[size] = new Fantast;
			break;
		case 3:
			tmp[size] = new Roman;
			break;
		default:
			break;
		}

		if (!tmp[size]->successful())
		{
			cout << "Элемент не был добавлен из-за ошибки" << endl;
			system("pause");
			return;
		}

		size++;

		if (data)
			delete[] data;
		data = tmp;

		cout << "Элемент успешно добавлен" << endl;
		system("pause");
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		system("pause");
	}
}


void Keeper::add(int _type, ifstream& fin)
{
	Writer** tmp = new Writer* [size + 1];
	
	for (int i = 0; i < size; i++)
	{
		tmp[i] = data[i];
	}
	
	switch (_type)
	{
	case 1:
		tmp[size] = new Poet(fin);
		break;
	case 2:
		tmp[size] = new Fantast(fin);
		break;
	case 3:
		tmp[size] = new Roman(fin);
		break;
	default:
		break;
	}
	
	size++;

	if (data)
		delete[] data;
	data = tmp;
}


void Keeper::edit()
{
	int index;
	
	if (!size)
	{
		cout << "[INFO] Контейнер пуст! Загрузите файлы из файла или добавьте новые элементы." << endl;
		system("pause");
		return;
	}

	try
	{
		for (int i = 0; i < size; i++)
		{
			cout << "[" << i << "] ";
			switch (data[i]->getType())
			{
			case 1:
				cout << "Поэт" << endl;
				break;
			case 2:
				cout << "Фантаст" << endl;
				break;
			case 3:
				cout << "Романист" << endl;
				break;
			default:
				break;
			}
		}
		
		cout << "Выберите элемент для именения: ";
		cin >> index;
		
		if (index < 0 || index > size - 1)
			throw (string)"Выбранного элемента не существует";
		
		data[index]->edit();
		
		if (!data[index]->successful())
		{
			cout << "Элемент не изменен из-за ошибки" << endl;
		}
		else
		{
			cout << "Элемент изменен успешно" << endl;
		}
		system("pause");
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		system("pause");
	}
}


void Keeper::del()
{
	int index;

	if (!size)
	{
		cout << "[INFO] Контейнер пуст! Загрузите файлы из файла или добавьте новые элементы." << endl;
		system("pause");
		return;
	}

	try
	{
		for (int i = 0; i < size; i++)
		{
			cout << "[" << i << "] ";
			switch (data[i]->getType())
			{
			case 1:
				cout << "Поэт" << endl;
				break;
			case 2:
				cout << "Фантаст" << endl;
				break;
			case 3:
				cout << "Романист" << endl;
				break;
			default:
				break;
			}
		}

		cout << "Выберите элемент для удаления: ";
		cin >> index;

		if (index < 0 || index > size - 1)
			throw (string)"Выбранного элемента не существует";

		if (size == 1)
		{
			delete[] data;
			data = nullptr;
			cout << "Элемент удален успешно" << endl;
			size--;
			system("pause");
			return;
		}

		Writer** tmp = new Writer* [size - 1];
		int j = 0;

		for (int i = 0; i < size; i++)
		{
			if (index == i)
				continue;
			tmp[j] = data[i];
		}

		delete[] data;
		data = tmp;
		size--;
		cout << "Элемент удален успешно" << endl;
		system("pause");
	}
	catch (string err)
	{
		cout << "ERROR: " + err << endl;
		system("pause");
	}
}


void Keeper::save()
{
	ofstream fout("output.txt");
	for (int i = 0; i < size; i++)
	{
		data[i]->save(fout);
	}
	fout.close();
	cout << "Элементы успешно сохранены в файл" << endl;
	system("pause");
}


void Keeper::load()
{
	ifstream fin("output.txt");
	if (fin.fail())
	{
		cout << "Файл пустой!" << endl;
		system("pause");
		return;
	}
	int type = 0;
	while (fin)
	{
		fin >> type;
		if (fin.peek() == -1)
		{
			break;
		}
		add(type, fin);
	}
	fin.close();
	cout << "Элементы успешно загружены из файла" << endl;
	system("pause");
}


ostream& operator<<(ostream& out, Keeper& obj)
{
	if (!obj.size)
	{
		cout << "[INFO] Контейнер пуст! Загрузите файлы из файла или добавьте новые элементы." << endl;
		system("pause");
		return out;
	}
	for (int i = 0; i < obj.size; i++)
	{
		obj.data[i]->print(out);
	}
	system("pause");
	return out;
}