#pragma once

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
	virtual void edit() = 0;
	virtual void print(ostream& out) = 0;
	virtual ~Writer() = 0;
};



