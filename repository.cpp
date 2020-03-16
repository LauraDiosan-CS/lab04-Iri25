#include "repository.h"

Repository::Repository()
{
	this->n = 0;
}
Repository::~Repository()
{
	this->n = 0;
}
void Repository::addElem(Entity s)
{
	this->e[this->n++] = s;
}
 
Entity* Repository::getAll()
{
	return this->e;
}

int Repository::getSize()
{
	return this->n;
}