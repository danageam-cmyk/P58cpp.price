#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include "product.h"
#include "price.h"


int main()
{
	setlocale(LC_ALL, "UA");
	Price* price = new Price();

	while (true) {
		int choice;
		std::cout << "Choice an action:\n"
			<< "1: Init price\n"
			<< "2: Load price\n"
			<< "3: Show price\n"
			<< "0: Exit\n";

		choice = _getch();
		switch (choice) {
		case 49:  // '1'
			if (price -> init()) {
				std::cout << "Price init success" << std::endl;
			}
			else {
				std::cout << "Price init error" << std::endl;
			}
			break;
		case 50:  // '2'
			if (price-> load()) {
				std::cout << "Price load success" << std::endl;
			}
			else {
				std::cout << "Price load error" << std::endl;
			}
			break;
		case 51:  // '3'
			price -> show();
			break;
		case 48:  // '0'
			return 0;

		default:
			std::cout << "Invalid choice" << std::endl;
		}
	}





	std::string str = "Hello i am Daniel";
	return 0;
}



/*

[ПК]    -- git init -- [git]
Project(P58)|
   sours	|
   header	|
   resouce	x
   bin		x

   Відміність проєкту та репозиторію - репозиторій це частина проєтку до якої
   входить лише, що неможна взяти з загальних джерел або створити 
   компіляцією чи виконання проєкту.
   Ця відмінність задається у файлі ".gitignor"




*/