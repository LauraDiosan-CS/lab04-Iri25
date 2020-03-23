#include <iostream>
#include "domain.h"
#include "service.h"
#include "repository.h"

using namespace std;

void show_menu()
{
	cout << "0. Inchidere" << "\n";
	cout << "1. Citire filme" << "\n";
	cout << "2. Afisare filme" << "\n";
	cout << "3. Stergere filme" << "\n";
	cout << "4. Actualizare filme" << "\n";
	cout << "5. Afisarea tuturor filmelor dintr-un anumit gen" << "\n";
	cout << "6. Eliminarea filmelor lansate inaintea unei anumite date calendaristice" << "\n";
	cout << "\n";
}

void reading(Service& service)
{
	char title[20];
	char date[12];
	char genre[20];

	cout << "Dati titlul: ";
	cin >> title;

	cout << "Dati data lansarii: ";
	cin >> date;

	cout << "Dati genul: ";
	cin >> genre;

	Movie movie(title, date, genre);
	service.addMovieService(movie);
	cout << endl << "Filmul a fost adaugat!" << endl;

}

void display(Service& service)
{
	int i;
	for (i = 0; i < service.getSize(); i++)
	{
		cout <<service.getAll()[i];
	}
}

int run()
{
	int op = -1;
	Service service;
	Repository repository;
	do
	{
		show_menu();
		int op;
		cout << "Dati optiunea: ";
		cin >> op;
		switch (op)
		{
		case 0:
		{
			exit(1);
			break;
		}
		case 1:
		{
			reading(service);
			cout << "\n";
			break;
		}
		case 2:
		{
			display(service);
			cout << "\n";
			break;
		}
		case 3:
			int size1;
			cout << "Dati id-ul de sters: ";
			cin >> size1;
			service.deleteMovieService(repository, size1);
			cout << "\n";
			break;
		case 4:
			int size2;
			char title[20], date[12], genre[20];
			cout << "Dati id-ul de actualizat: ";
			cin >> size2;
			cout << "Dati titlu nou: ";
			cin >> title;
			cout << "Dati data noua: ";
			cin >> date;
			cout << "Dati genul nou: ";
			cin >> genre;
			service.updateMovieService(repository, size2, title, date, genre);
			cout << "\n";
			break;
		case 5:
		{
			int m = 0, i;
			char genre[20];
			cout << "Dati genul: ";
			cin >> genre;
			Movie filter_movies[100];
			service.filter_movies_by_genre(repository, genre, filter_movies, m);
			for (i = 0; i < m; i++)
			{
				cout << filter_movies[i];
				cout << endl;
			}
			cout << "\n";
			break;
		}
		case 6:
		{
			char date[12];
			cout << "Dati data: ";
			cin >> date;
			Movie filter_movies[100];
			service.delete_movies_by_date(repository, date);
			cout << "\n";
			break;
		}
		default:
		{
			cout << "Comanda imposibila!";
			cout << "\n";
		}
		}
	} 
	while (op != 0);
}
