#include "domain.h"
#include <cstddef>
#include <string.h>
#include <istream>
#include <ostream>
#include <iostream>

using namespace std;

Movie::Movie()
{
	//cout << "Implicit constructor!" << endl;

	this->title = NULL;
	this->date = NULL;
	this->gender = NULL;
}

Movie::Movie(char* title, char* date, char* gender)
{
	//cout << "General constructor!" << endl;

	this->title = new char[strlen(title) + 1];
	strcpy_s(this->title, 1 + strlen(title), title);

	this->date = new char[strlen(date) + 1];
	strcpy_s(this->date, 1 + strlen(date), date);

	this->gender = new char[strlen(gender) + 1];
	strcpy_s(this->gender, 1 + strlen(gender), gender);
}

Movie::Movie(const Movie& movie)
{
	//cout << "Copy constructor!" << endl;

	setTitle(movie.title);
	setDate(movie.date);
	setGender(movie.gender);
}

Movie::~Movie()
{
	//cout << "Destructor!" << endl;

	if (this->title)
		delete[] this->title;
	this->title = NULL;

	if (this->date)
		delete[] this->date;
	this->date = NULL;

	if (this->gender)
		delete[] this->gender;
	this->gender = NULL;

}

char* Movie::getTitle()
{
	return this->title;
}

char* Movie::getDate()
{
	return this->date;
}

char* Movie::getGender()
{
	return this->gender;
}


void Movie::setTitle(char* title)
{
	if (this->title) 
	{
		delete[] this->title;
	}
	this->title = new char[strlen(title) + 1];
	strcpy_s(this->title, strlen(title) + 1, title);
}


void Movie::setDate(char* date)
{
	if (this->date)
	{
		delete[] this->date;
	}
	this->date = new char[strlen(date) + 1];
	strcpy_s(this->date, strlen(date) + 1, date);
}


void Movie::setGender(char* gender)
{
	if (this->gender) 
	{
		delete[] this->gender;
	}
	this->gender = new char[strlen(gender) + 1];
	strcpy_s(this->gender, strlen(gender) + 1, gender);
}


Movie& Movie::operator=(const Movie& movie)
{
	this->setTitle(movie.title);
	this->setDate(movie.date);
	this->setGender(movie.gender);

	return *this;
}

bool Movie:: operator==(const Movie& movie)
{
	return (strcmp(this->title, movie.title) == 0) && (strcmp(this->date, movie.date) == 0) && (strcmp(this->gender, movie.gender) == 0);
}

istream& operator>>(istream& is, const Movie& movie)
{
	cout << "Dati titlul: ";
	is >> movie.title;
	cout << "Dati data lansarii: ";
	is >> movie.date;
	cout << "Dati genul: ";
	is >> movie.gender;
	return is;
}
ostream& operator<<(ostream& os, const Movie& movie)
{
	os <<"Film: "<< movie.title << ", "<< movie.date << ", " << movie.gender << endl;
	return os;
}
