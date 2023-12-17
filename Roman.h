#pragma once
#ifndef ROMAN_H
#define ROMAN_H

#include "Writer.h"
class Roman : public Writer
{
	std::string _FIO;
	std::string _years;
	std::string _poems;
	std::string _bio;
public:
	Roman(std::string FIO, std::string years, std::string poems, std::string bio);
	Roman(std::ifstream& fin);
	~Roman();
	void edit();
	void save(std::ofstream& fout);
	void print(std::ostream& out);


};

#endif // !ROMAN_H



