#pragma once
#include "Writer.h"
class Fantast : public Writer
{
	string _FIO;
	string _poems;
	int _films;
public:
	Fantast();
	Fantast(ifstream& fin);
	~Fantast();
	void edit();
	void save(ofstream& fout);
	void print(ostream& out);


};



