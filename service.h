#pragma once
#ifndef SERVICE_H
#define SERVICE_H
#include "domain.h"
#include "repository.h"

class Service
{
private:
	Repository repository;
public:
	Service();
	Service(const Repository& repository);
	~Service();

	void setRepository(const Repository& repository);
	void addMovieService(Movie& movie);
	bool findMovieService(Movie& movie);
	void deleteMovieService(Repository& repository, int& i);
	void updateMovieService(Repository& repository, int& i, char* title, char* date, char* genre);
	Movie* getAll();
	int getSize();

	void filter_movies_by_genre(Repository& repository, char* genre, Movie filter_movies[100], int& m);
	void delete_movies_by_date(Repository& repository, char* date);
	
};

#endif //SERVICE_H








