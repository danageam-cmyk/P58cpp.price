#include "price.h"
#include <iostream>

bool Price::init() {
	std::ofstream file(PRICE_FILENAME);
	if (!file.is_open()) {
		std::cout << "File open error";
		return false;
	}
	Product product = { "Black Pencil", 14.95f, 20, 0 };
	product.save_to_file(file);

	product = { "Blue Pen", 19.95f, 25, 5 };
	product.save_to_file(file);

	product = { "Green Whiteboard Marker", 17.50f, 10, 10 };
	product.save_to_file(file);

	product = { "Red Pen", 37.50f, 5, 10 };
	product.save_to_file(file);

	product = { "Blak Marker", 7.70f, 10, 60 };
	product.save_to_file(file);

	file.close();
	return true;
}

bool Price::load() {
	std::ifstream file(PRICE_FILENAME);
	if (!file.is_open()) {
		std::cout << "File open error";
		return false;
	}
	ListNode* last = NULL;
	// видаляємо наявні товари перед зчитуванням файлу
	if (first) {   // якщо вони є
		do {
			last = first->next;
			delete first;
			first = last;
		} while (first);  // while (first != NULL)
	}
	Product product;
	while (product.load_from_file(file)) {
		if (last == NULL) {
			first = last = new ListNode;
			last->product = product;
			last->next = NULL;
		}
		else {
			last->next = new ListNode;
			last->next->product = product;
			last->next->next = NULL;
			last = last->next;
		}
	}
	file.close();
	return true;
}

void Price::show() const {
	if (first == NULL) {
		std::cout << "Price is empty" << std::endl;
		return;
	}
	ListNode* node = first;
	while (node) {
		std::cout << node->product.to_string() << std::endl;
		node = node->next;
	}
}

void Price::show_by_price_ascending() {
	

	if (first == NULL) {
		std::cout << "Price is empty" << std::endl;
		return;
	}
	if (first->next == NULL) {
		std::cout << first->product.to_string() << std::endl;
		return;
	}
	bool is_ordered;
	do {
		is_ordered = true;
	
	ListNode* node = first;
	if (node->product.price > node->next->product.price) {
		first->next = first->next->next;


		ListNode* tmp = first ->next;
		first->next = first->next->next;
		first->next->next = first;
		node = first = tmp;
		is_ordered = false;
	}
	while (1) {
		//ListNode* tmp = node->next;
		//if (node->next-> product.price > node->next-> next-> product.price) {
		//	//Порядок не правильний - міняемо
		//	node->next = node->next->next; // p1.next
		//	node->next->next = node->next->next->next; // p2.next = p3.next,
			ListNode* tmp = node->next;
			ListNode* n2 = node->next;
			ListNode* n3 = n2->next;
			ListNode* n4 = n3->next;
			node->next = n3;
			n3->next = n2;
			n2->next = n4;
			node->next = tmp->next;
			tmp->next = tmp->next->next;

		
		node->next = node->next->next;
		
		}
	} while (!is_ordered);
	show();
}
///////////////////////////////////////////////

void Price::show_by_price_descending() {
	if (first == NULL) {
		std::cout << "Price is empty" << std::endl;
		return;
	}

	bool swapped;

	do {
		swapped = false;
		ListNode* node = first;

		while (node->next != NULL) {
			if (node->product.price < node->next->product.price) {
				Product temp = node->product;
				node->product = node->next->product;
				node->next->product = temp;
				swapped = true;
			}

			node = node->next;
		}
	} while (swapped);

	show();
}


void Price::show_by_discount_ascending() {
	if (first == NULL) {
		std::cout << "Price is empty" << std::endl;
		return;
	}

	bool swapped;

	do {
		swapped = false;
		ListNode* node = first;

		while (node->next != NULL) {
			if (node->product.discount_percent >
				node->next->product.discount_percent) {

				Product temp = node->product;
				node->product = node->next->product;
				node->next->product = temp;
				swapped = true;
			}

			node = node->next;
		}
	} while (swapped);

	show();
}


void Price::show_by_discount_descending() {
	if (first == NULL) {
		std::cout << "Price is empty" << std::endl;
		return;
	}

	bool swapped;

	do {
		swapped = false;
		ListNode* node = first;

		while (node->next != NULL) {
			if (node->product.discount_percent <
				node->next->product.discount_percent) {

				Product temp = node->product;
				node->product = node->next->product;
				node->next->product = temp;
				swapped = true;
			}

			node = node->next;
		}
	} while (swapped);

	show();
}
