#include <iostream>
#include "domain.h"
#include "service.h"
#include "repository.h"

 using namespace std;

void reading(Repository& repository)
{
    char title[20];
    char date[12];
    char gender[20];

    cout << "Dati titlul: ";
    cin >> title;

    cout << "Dati data lansarii: ";
    cin >> date;

    cout << "Dati genul: ";
    cin >> gender;
    
    Movie movie(title, date, gender);
    repository.addMovie(movie);
    cout << endl << "Filmul a fost adaugat!" << endl;

}

void display(Repository& repository)
{
    int i;
    for (i = 0; i < repository.getSize(); i++)
    {
        cout << repository.getAll()[i];
    }
}

void filter_movies_by_gender(Repository& repository, char* gender, Movie filter_movies[100], int& m)
{
    int i;
    for (i = 0; i < repository.getSize(); i++)
    {
        Movie crt_Movie = repository.getItemFromPosition(i);
        if (strcmp(crt_Movie.getGender(), gender) == 0)
        {
            filter_movies[m++] = crt_Movie;
        }
    }
    if (m == 0)
        cout << "Nu exista!" << endl;
    
}

void delete_movies_by_date(Repository& repository, char* date)
{
    int i = 0;
    while (i < repository.getSize())
    {
        Movie crt_Movie = repository.getItemFromPosition(i);
        if (strcmp(crt_Movie.getDate(), date) < 0)
        {
            repository.deleteMovie(crt_Movie);
        }
        i++;
    }
}
/*void deleteMovieService(Repository& repository, int& i)
{
    Movie crt_Movie = repository.getItemFromPosition(i);
    repository.deleteMovie(crt_Movie);
}

void updateMovieService(Repository& repository, int& i, char* title, char* date, char* gender)
{
    Movie crt_Movie = repository.getItemFromPosition(i);
    repository.updateMovie(crt_Movie, title, date, gender);
}*/