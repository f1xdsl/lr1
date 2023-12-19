#pragma once
#include "Writer.h"
class Poet : public Writer
{
	std::string _FIO;
	std::string _years;
	std::string _poems;
public:
	Poet();
	Poet(std::ifstream& fin);
	~Poet();
	void edit();
	void save(std::ofstream& fout);
	void print(std::ostream& out);


};




