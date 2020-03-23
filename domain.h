#pragma once
#ifndef DOMAIN_H
#define DOMAIN_H
#include <ostream>

using namespace std;

class Movie
{
private:
    char* title;
    char* date;
    char* gender;
public:
    Movie();
    Movie(char* title, char* date, char* gender);
    Movie(const Movie& movie);
    ~Movie();

    char* getTitle();
    char* getDate();
    char* getGender();
    void setTitle(char* title);
    void setDate(char* date);
    void setGender(char* gender);

    Movie& operator = (const Movie& movie);
    bool operator == (const Movie& movie);
    friend istream& operator>>(istream& is, const Movie& movie);
    friend ostream& operator<<(ostream& os, const Movie& movie);

};

#endif // DOMAIN_H = MOVIE_H


