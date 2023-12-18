#pragma once
#include "Poet.h"
#include "Roman.h"
#include "Fantast.h"
#include <fstream>
class Keeper
{
	Writer** data;
	int size;
public:
	Keeper();
	~Keeper();
	int getSize();
	void add();
	void add(int _type, ifstream& fin);
	void edit();
	void del();
	void save();
	void load();
	friend ostream& operator<<(ostream& out, Keeper& obj);
};
