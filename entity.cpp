#include "entity.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>

using namespace std;

Entity::Entity()
{
	this->name = NULL;
}

Entity::Entity(char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, 1 + strlen(name), name);
}

Entity::Entity(const Entity& s) 
{
	cout << "Copy constructor!" << endl;
	this->name = new char[strlen(s.name) + 1];
	strcpy_s(this->name, 1 + strlen(s.name), s.name);
}

Entity::~Entity() 
{
	if (this->name) {
		delete[] this->name;
		this->name = NULL;
	}
}

char* Entity::getName() {
	return this->name;
}

void Entity::setName(char* name)
{
	if (this->name) {
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}


Entity& Entity::operator=(const Entity& s) {
	this->setName(s.name);
	return *this;
}

bool Entity:: operator==(const Entity& s) {
	return strcmp(this->name, s.name) == 0;
}

ostream& operator<<(ostream& os, const Entity& s)
{
	os << s.name;
	return os;
}
