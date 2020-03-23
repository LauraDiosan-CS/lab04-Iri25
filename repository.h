#pragma once
#include "domain.h"

class Repository
{
private:
    Movie movies[100]; 
    int n;
public:
    Repository();
    ~Repository();

    void addMovie(Movie& movie); 
    int findMovie(Movie& movie);
    Movie getItemFromPosition(int i);
    void deleteMovie(Movie& movie);
    void updateMovie(Movie movie, char*, char*, char*);
    Movie* getAll();
    int getSize();

};

