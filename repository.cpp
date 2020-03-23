#include "repository.h"
#include<iostream>
using namespace std;

Repository::Repository()
{
	this->n = 0;
}

Repository::~Repository()
{
	this->n = 0;
}


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

void Repository::updateMovie(Movie movie, char* title, char* date, char* gender)
{
	int i = findMovie(movie);
	movies[i].setTitle(title);
	movies[i].setDate(date);
	movies[i].setGender(gender);
}

Movie* Repository::getAll()
{
	return this->movies;
}

int Repository::getSize()
{
	return this->n;
}
