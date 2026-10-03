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
			<< "4: Price ascending\n"
			<< "5: Price descending\n"
			<< "6: discount ascending\n"
			<< "7: discount descending\n"
			<< "0: Exit\n";

		choice = _getch();///
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
		case 52:  // '4'
			price -> show_by_price_ascending();
			break;
		case 53: // '5'
			price->show_by_price_descending();
				break;
		case 54: // '6'
				price->show_by_discount_ascending();
				break;
		case 55: // '7'
			price->show_by_discount_descending();
				break;
		case 48:  // '0'
			return 0;

		default:
			std::cout << "Invalid choice" << std::endl;
		}
	}





	return 0;
}



/*

[ПК]    -- git init -- [git]
Project(P58)|
   sours	|			   source	|	git
   header	|	git add    headers	|   comit		push
   resouce	x			   resources|   -m "message" -->
   bin		x

   Відміність проєкту та репозиторію - репозиторій це частина проєтку до якої
   входить лише, що неможна взяти з загальних джерел або створити 
   компіляцією чи виконання проєкту.
   Ця відмінність задається у файлі ".gitignor"


   ...................................................

   Якщо на пк немає прокту то здійснюеться клонування 
   - запускаемо студію авторитизуємось через git
   -вибираємо clone repository
   - натискаемо  Github і знаходимо репозиторій або ссилку на який нам потрібен 
   - клонуемо та переходим до проєкту

   Якщо проєкт є але в старій версії то
   -відкриваємо проєкт
   - відкриваємо View
   - знаходимо кнопку pull
   -натискаємо 
   
   
	конфлікти виникають коли різні гілки (зміни в різних джерелах) намагаються 
	внести дані що суперечатьь один іншому. Наприклад
	було внесенно зміни в один ш той самий файл
	Злиття (Marge) - процес узгодження конфліктів прийняття підсумково версії
	у VS для цього э кнопка Merge editer якщо гылки вносять зміни в різні файли то 
	злиття здійснюються без конфліктів проте примій PUSH може бути
	відхилений якщо в репозиторії є зміни які не були завантажені на ПК

		


   */