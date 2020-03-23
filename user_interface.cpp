#include <iostream>
#include "domain.h"
#include "service.h"
#include "repository.h"


using namespace std;

void show_menu()
{
	cout << "1. Citire filme" << "\n";
	cout << "2. Afisare filme" << "\n";
	cout << "3. Afisarea tuturor filmelor dintr-un anumit gen" << "\n";
	cout << "4. Eliminarea filmelor lansate inaintea unei anumite date calendaristice" << "\n";
	cout << "5. Inchidere" << "\n";
	//cout << "6. Setergere" << "\n";
	//cout << "7. Actualizare" << "\n";
	cout << "\n";
}

int run()
{
	int op = 0;
	Repository repository;

	do
	{
		show_menu();
		int op;
		cout << "Dati optiunea: ";
		cin >> op;
		switch (op)
		{
		case 1:
		{
			reading(repository);
			cout << "\n";
			break;
		}
		case 2:
		{
			display(repository);
			cout << "\n";
			break;
		}
		case 3:
		{
			int m = 0, i;
			char gender[20];
			cout << "Dati genul: ";
			cin >> gender;
			Movie filter_movies[100];
			filter_movies_by_gender(repository, gender, filter_movies, m);
			for (i = 0; i < m; i++)
			{
				cout << filter_movies[i];
				cout << endl;
			}
			cout << "\n";
			break;
		}
		case 4:
		{
			char date[12];
			cout << "Dati data: ";
			cin >> date;
			Movie filter_movies[100];
			delete_movies_by_date(repository, date);
			cout << "\n";
			break;
		}
		case 5:
		{
			exit(1);
			break;
		}
		/*case 6:
			int size1;
			cout << "Dati id-ul de sters: ";
			cin >> size1;
			deleteMovieService(repository, size1);
			cout << "\n";
			break;
		case 7:
			int size2;
			char title[20], date[12], gender[20];
			cout << "Dati id-ul de actualizat: ";
			cin >> size2;
			cout << "Dati titlu nou: ";
			cin >> title;
			cout << "Dati data noua: ";
			cin >> date;
			cout << "Dati genul nou: ";
			cin >> gender;
			updateMovieService(repository, size2, title, date, gender);
			cout << "\n";
			break;*/
		default:
		{
			cout << "Comanda imposibila!";
			cout << "\n";
		}
		}

	} 
	while (op != 5);

}
