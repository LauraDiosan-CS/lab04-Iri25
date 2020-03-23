# include "service.h"
# include "repository.h"
# include <iostream>

using namespace std;

Service::Service()
{

}

Service::Service(const Repository& repository)
{
    this->repository = repository;
}

Service::~Service()
{

}

void Service::setRepository(const Repository& repository)
{
    this->repository = repository;
}

void Service::addMovieService(Movie& movie)
{
    return repository.addMovie(movie);  
}

bool Service::findMovieService(Movie& movie)
{
    return repository.findMovie(movie);
}

void Service::deleteMovieService(Repository& repository, int& i)
{
    Movie crt_Movie = repository.getItemFromPosition(i);
    repository.deleteMovie(crt_Movie);
}

void Service::updateMovieService(Repository& repository, int& i, char* title, char* date, char* genre)
{
    Movie crt_Movie = repository.getItemFromPosition(i);
    repository.updateMovie(crt_Movie, title, date, genre);
}

int Service::getSize()
{
    return repository.getSize();
}

Movie* Service::getAll()
{
    return repository.getAll();
}


void Service::filter_movies_by_genre(Repository& repository, char* genre, Movie filter_movies[100], int& m)
{
    int i;
    for (i = 0; i < repository.getSize(); i++)
    {
        Movie crt_Movie = repository.getItemFromPosition(i);
        if (strcmp(crt_Movie.getGenre(), genre) == 0)
        {
            filter_movies[m++] = crt_Movie;
        }
    }
    if (m == 0)
        cout << "Nu exista!" << endl;

}

void Service::delete_movies_by_date(Repository& repository, char* date)
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
