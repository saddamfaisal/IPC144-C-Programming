//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           14/07/2020
#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>
#include "Utils.h"

const int MAX_NO_OF_ITEMS = 10;

namespace sdds {

	class MenuItem {


	public:
		char* m_value = nullptr;
		MenuItem(const char* value);
		~MenuItem();
		operator bool() const;



		friend class Menu;

	};



	class Menu {

		char* m_title = nullptr;

		MenuItem* m_menuItems[MAX_NO_OF_ITEMS];

		int m_ItemNum = 0;

		int m_Indt = 0;

	public:
		void setTitle(const char* ttl);
		void setIdentation(int identLev);
		void setEmpty();
		Menu(const char* title, int indt = 0);
		Menu(const Menu& menu);
		~Menu();
		Menu();
		Menu& operator=(const Menu& menu);
		Menu& operator=(const char* title);
		operator bool() const;
		bool isEmpty() const;
		void display() const;
		void add(const char* value);
		Menu& operator<<(const char* value);
		int run() const;
		operator int() const;
		//ostream& operator<<(ostream& os, const MenuItem& menuItem);

	};
	std::ostream& operator<<(std::ostream& os, const MenuItem& menuItem);
}

#endif



