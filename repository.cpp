#include "repository.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Repository::Repository()
{
	this->n = 0;
}

/*
Repository::Repository(const char* file)
{
	fis = file;
	ifstream f(file);
	string line;
	char* title = new char[20];
	char* date = new char[12];
	char* gender = new char[20];
	while (!f.eof())
	{
		f >> title >> date >> gender;

		if (title!= " ")
		{
			Movie movie(title, date, gender);
			movies.push_back(movie);
		}
		
		if (date != " ")
		{
			Movie movie(title, date, gender);
			movies.push_back(movie);
		}

		if (gender != " ")
		{
			Movie movie(title, date, gender);
			movies.push_back(movie);
		}
	}

	delete[] title;
	delete[] date;
	delete[] gender;

	f.close();
}
*/

Repository::~Repository()
{
	this->n = 0;
}

/*
void Repository::loadFromFile(const char* file)
{
	movies.clear();
	ifstream f(file);
	char* title = new char[20];
	char* date = new char[12];
	char* gender = new char[20];
	while (!f.eof())
	{
		f >> title >> date >> gender;
		if (strcmp(title, " ") != 0)
		{
			Movie movie(title, date, gender);
			movies.push_back(movie);
		}

		if (strcmp(date, " ") != 0)
		{
			Movie movie(title, date, gender);
			movies.push_back(movie);
		}

		if (strcmp(gender, " ") != 0)
		{
			Movie movie(title, date, gender);
			movies.push_back(movie);
		}
	}

	delete[] title;
	delete[] date;
	delete[] gender;

	f.close();
}
*/

void Repository::addMovie(Movie& movie)
{
	this->movies[this->n++] = movie;
}

int Repository::findMovie(Movie& movie)
{
	int i = 0;
	while (i < this->n)
	{
		if (movies[i] == movie)
			return i;
	}
	return -1;
}

Movie Repository::getItemFromPosition(int i)
{
	return movies[i];
}

void Repository::deleteMovie(Movie& movie)
{
	int i = findMovie(movie);
	if (i != -1)
		movies[i] = movies[n - 1];
	n--;
}

void Repository::updateMovie(Movie& movie, char* title, char* date, char* genre)
{
	int i;
	for (i = 0; i < getSize(); i++)
	{
		if (movies[i] == movie)
		{
			movies[i].setTitle(title);
			movies[i].setDate(date);
			movies[i].setGenre(genre);
		}
	}
}

Movie* Repository::getAll()
{
	return this->movies;
}

int Repository::getSize()
{
	return this->n;
}
