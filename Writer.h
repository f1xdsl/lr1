#pragma once

#ifndef WRITER_H
#define WRITER_H
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Writer {
	int _type;	
	bool _success;
public:
	void setType(int type);
	void setSuccess(bool success);
	int getType();
	bool successful();
	virtual void save(ofstream& fout) = 0;
	virtual void load(ifstream& fin) = 0;
	virtual void edit() = 0;
	virtual ~Writer() = 0;
};




#endif // !WRITER_H
