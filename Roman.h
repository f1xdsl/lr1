#pragma once
#ifndef ROMAN_H
#define ROMAN_H

#include "Writer.h"
class Roman : public Writer
{
	string _FIO;
	string _years;
	string _poems;
	string _bio;
public:
	Roman();
	Roman(std::ifstream& fin);
	~Roman();
	void edit();
	void save(std::ofstream& fout);
	void print(std::ostream& out);


};

#endif // !ROMAN_H



