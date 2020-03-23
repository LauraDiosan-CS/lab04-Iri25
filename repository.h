#pragma once
#ifndef REPOSITORY_H
#define REPOSITORY_H
#include "domain.h"

class Repository
{
private:
    Movie movies[100]; 
    int n;
    const char* fis;
public:
    Repository();
   // Repository(const char* file);
    ~Repository();

    //void loadFromFile(const char* file);
    void addMovie(Movie& movie); 
    int findMovie(Movie& movie);
    Movie getItemFromPosition(int i);
    void deleteMovie(Movie& movie);
    void updateMovie(Movie& movie, char* title, char* date, char* genre);
    Movie* getAll();
    int getSize();

};

# endif //REPOSITORY_H