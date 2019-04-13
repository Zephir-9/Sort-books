
#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <algorithm>


class Books
{
public:
	char name_book[80] = "";
	char name_avtor[80] = "";
	unsigned int str = NULL;
	unsigned int year = NULL;

	void Show()
	{
		std::cout << "\nНазвание книги: " << name_book;
		std::cout << "\nИмя автора: " << name_avtor;
		std::cout << "\nКоличество страниц: " << str;
		std::cout << "\nГод издания: " << year;
		std::cout << '\n';
	}

};

void Sorting_Avtor(Books book[]);
void Sorting_Year(Books book[]);

int main()
{
	setlocale(LC_ALL, "RUS");

	Books book[7];
	Books *p_book = &book[7];

	for (int i = 0, j = 1; i < 7; i++, j++)
	{
		system("cls");
		std::cout << "Введите данные книги " << j;
		std::cout << "\nНазвание книги: ";
		std::cin >> book[i].name_book;
		std::cout << "\nИмя автора: ";
		std::cin >> book[i].name_avtor;
		std::cout << "\nКоличество страниц: ";
		std::cin >> book[i].str;
		std::cout << "\nГод издания: ";
		std::cin >> book[i].year;
	}


	system("cls");

	char chose = NULL;

	std::cout << "Выберите метод сортировки:\n" << "  1 - По имени Автора\n" << "  2 - По году издания\n" << "  3 - Выход\n";
	std::cin >> chose;

	switch (chose)
	{
	case '1':
		Sorting_Avtor(book);
		break;
	case '2':
		Sorting_Year(book);
		break;
	case '3':
		return EXIT_SUCCESS;
	default:
		std::cout << "Ошибка ввода, ничего не выбранно\n";
		system("PAUSE");
		return EXIT_FAILURE;
	}
	

	system("PAUSE");
	return 0;
}

void Sorting_Avtor(Books book[])
{
	for (int i = 0; i < 7 - 1; i++)
		for (int j = i + 1; j < 7; j++)
			if (strcmp(book[i].name_avtor, book[j].name_avtor) > 0)
			{
				Books t = book[i];
				book[i] = book[j];
				book[j] = t;

			}
	system("cls");
	for (int i = 0; i < 7; i++)
	{

		book[i].Show();
	}
}

void Sorting_Year(Books book[])
{
	Books tmp;
	for (int i = 0; i < 7; i++) {
		for (int j = 7 - 1; j > i - 1; j--) {
			if (book[j].year > book[j + 1].year) {
				tmp.year = book[j].year;
				book[j].year = book[j + 1].year;
				book[j + 1].year = tmp.year;
			}
		}
	}

	system("cls");

	for (int i = 0; i < 7; i++)
	{
		book[i].Show();
	}
}