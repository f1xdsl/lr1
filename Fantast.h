#pragma once
#ifndef FANTAST_H
#define FANTAST_H

#include "Writer.h"
class Fantast : public Writer
{
	std::string _FIO;
	std::string _poems;
	bool _films;
public:
	Fantast(std::string FIO, std::string poems, bool films);
	Fantast(std::ifstream& fin);
	~Fantast();
	void edit();
	void save(std::ofstream& fout);
	void print(std::ostream& out);


};

#endif // !FANTAST_H


