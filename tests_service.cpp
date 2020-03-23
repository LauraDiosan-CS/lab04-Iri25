#include <cassert>
#include <string.h>
#include "domain.h"
#include "repository.h"
#include "service.h"
#include "tests_service.h"



void tests_with_service()
{
	int m, i;
	Movie filter_movies[100];
	Movie movies[5];
	Repository repository;
	Service service;

	char* title1 = new char[20];
	char* title2 = new char[20];
	char* title3 = new char[20];
	char* title4 = new char[20];
	char* title5 = new char[20];

	char* date1 = new char[20];
	char* date2 = new char[20];
	char* date3 = new char[20];
	char* date4 = new char[20];
	char* date5 = new char[20];

	char* genre1 = new char[20];
	char* genre2 = new char[20];
	char* genre3 = new char[20];
	char* genre4 = new char[20];
	char* genre5 = new char[20];

	//implicit constructor
	strcpy_s(title1, sizeof "Bright", "Bright");
	strcpy_s(date1, sizeof "11.11.2019", "11.11.2019");
	strcpy_s(genre1, sizeof "thriller", "thriller");
	Movie movie1;

	//general constructor
	strcpy_s(title2, sizeof "Mute", "Mute");
	strcpy_s(date2, sizeof "11.11.2011", "11.11.2011");
	strcpy_s(genre1, sizeof "drame", "drame");
	Movie movie2(title2, date2, genre2);

	strcpy_s(title3, sizeof "Mank", "Mank");
	strcpy_s(date3, sizeof "09.11.2016", "09.11.2016");
	strcpy_s(genre3, sizeof "biographical", "biographical");
	Movie movie3(title3, date3, genre3);

	strcpy_s(title4, sizeof "Tig", "Tig");
	strcpy_s(date4, sizeof "02.03.2020", "02.03.2020");
	strcpy_s(genre4, sizeof "documentary", "documentary");
	Movie movie4(title4, date4, genre4);

	strcpy_s(title5, sizeof "Rebecca", "Rebecca");
	strcpy_s(date5, sizeof "01.02.2020", "01.02.2020");
	strcpy_s(genre5, sizeof "thriller", "thriller");
	Movie movie5(title5, date5, genre5);

	movies[0] = movie1;
	movies[1] = movie2;
	movies[2] = movie3;
	movies[3] = movie4;
	movies[4] = movie5;


	//addMovie
	service.addMovieService(movie1);
	service.addMovieService(movie2);
	service.addMovieService(movie3);
	service.addMovieService(movie4);
	service.addMovieService(movie5);

	assert(movies[0] == movie1);
	assert(movies[1] == movie2);
	assert(movies[2] == movie3);
	assert(movies[3] == movie4);
	assert(movies[4] == movie5);

	//deleteMovie
	i = 4;
	service.deleteMovieService(repository, i);

	//updateMovie
	i = 3;
	service.updateMovieService(repository, i, movie3.getTitle(), movie1.getDate(), movie5.getGenre());
	assert(movie2.getTitle() == "Mank");
	assert(movie2.getDate() == "11.11.2019");
	assert(movie2.getGenre() == "thriller");


	//getAll
	assert(service.getAll()[0] == movie1);
	assert(service.getAll()[1] == movie2);
	assert(service.getAll()[2] == movie3);
	assert(service.getAll()[3] == movie5);

	//filter_movies_by_gender
	service.filter_movies_by_genre(repository, movie5.getGenre(), filter_movies, m);

	//delete_movies_by_date
	service.delete_movies_by_date(repository, movie5.getDate());
}
