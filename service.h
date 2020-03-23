#pragma once
#include "repository.h"
#ifndef OPERATIONS_H
#define OPERATIONS_H

void show_menu();

void reading(Repository& repository);

void display(Repository& repository);

void filter_movies_by_gender(Repository& repository, char* gender, Movie filter_movies[100], int& m);

void delete_movies_by_date(Repository& repository, char* date);
//void deleteMovieService(Repository& repository, int& i);

//void updateMovieService(Repository& repository, int& i, char* title, char* date, char* gender);

#endif // OPERATIONS_H







