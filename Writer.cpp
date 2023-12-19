#include "Writer.h"


void Writer::setType(int type) {
	this->_type = type;
}

int Writer::getType() {
	return _type;
}

void Writer::setSuccess(bool success) {
	this->_success = success;
}


bool Writer::successful() {
	return _success;
}

Writer::~Writer() {
}