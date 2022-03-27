//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           14/07/2020
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "Menu.h"
#include "Utils.h"
#include <iomanip>

using namespace std;

namespace sdds {


	MenuItem::MenuItem(const char* value)
	{
		if (value != nullptr && value[0] != '\0')
		{

			m_value = new char[strlen(value) + 1];
			strcpy(m_value, value);
		}
		else
		{
			m_value = nullptr;
		}
	}

	MenuItem::~MenuItem()
	{
		delete[] m_value;
		m_value = nullptr;
	}

	MenuItem::operator bool() const
	{
		return m_value != nullptr;
	}

	void Menu::setEmpty()
	{


		m_title = nullptr;
		m_Indt = 0;
		m_ItemNum = 0;
		for (int i = 0; i < MAX_NO_OF_ITEMS; i++)
		{
			m_menuItems[i] = nullptr;
		}
	}

	  
	void Menu::setTitle(const char* ttl) {

		if (ttl != nullptr && ttl[0] != '\0') {

			int size = strlen(ttl) + 1;

			m_title = new char[size];

			strcpy(m_title, ttl);

		}

		else {

			m_title = nullptr;

		}

	}


                



	
	void Menu::setIdentation(int identLev) {

		if (identLev > 0) {

			m_Indt = identLev;

		}

		else {

			m_Indt = 0;

		}

	}


	Menu::Menu(const char* ttl, int identLev)
	{
		setEmpty();
		setTitle( ttl);
		 setIdentation(identLev);
		/*if (title != nullptr && title[0] != '\0')
		{
			delete[] m_title;
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
			m_Indt = indt;
		}*/
	}

	Menu::Menu(const Menu& menu)
	{
		setEmpty();
		*this = menu;
	}

	Menu::~Menu()
	{
		delete[] m_title;
		m_title = nullptr;
		for (int i = 0; i < m_ItemNum; ++i) {
			delete m_menuItems[i];
			m_menuItems[i] = nullptr;
		}
	}
	Menu& Menu::operator=(const Menu& menu)
	{
		if (this != &menu)
		{
			if (menu)
			{
				delete[] m_title;
				m_title = new char[strlen(menu.m_title) + 1];
				strcpy(m_title, menu.m_title);
				m_Indt = menu.m_Indt;
				m_ItemNum = menu.m_ItemNum;
				for (int i = 0; i < m_ItemNum; i++)
				{
					delete m_menuItems[i];
					m_menuItems[i] = new MenuItem(menu.m_menuItems[i]->m_value);
				}
			}
			else
			{
				setEmpty();
			}
		}
		return *this;
	}

	Menu& Menu::operator=(const char* title)
	{
		delete[] m_title;
		m_title = new char[strlen(title) + 1];
		strcpy(m_title, title);
		return *this;
	}

	Menu::operator bool() const
	{
		return m_title != nullptr;
	}

	bool Menu::isEmpty() const
	{
		return !*this;
	}

	void Menu::display() const
	{
		if (isEmpty())
		{
			cout << "Invalid Menu!" << endl;
		}
		else
		{
			int indentSize = m_Indt * 4;
			cout << setw(indentSize) << "" << m_title << endl;
			if (m_ItemNum == 0)
			{
				cout << "No Items to display!" << endl;
			}
			else
			{
				for (int i = 0; i < m_ItemNum; i++)
				{
					cout << setw(indentSize) << "" << i + 1 << "- " << *m_menuItems[i];
				}
				cout << setw(indentSize) << "" << "> ";
			}
		}

	}

	void Menu::add(const char* value)
	{
		if (value == nullptr || value[0] == '\0')
		{
			setEmpty();
		}
		if (!isEmpty())
		{
			if (m_ItemNum < MAX_NO_OF_ITEMS) {
				delete m_menuItems[m_ItemNum];
				m_menuItems[m_ItemNum] = new MenuItem(value);
				m_ItemNum++;
			}
		}
	}

	Menu& Menu::operator<<(const char* value)
	{
		add(value);
		return *this;
	}

	int Menu::run() const
	{
		int choose;
		bool done = false;
		display();
		if (m_ItemNum != 0)
		{
			do
			{
				cin >> choose;
				if (!cin.good())
				{
					cin.clear();
					cin.ignore(2000, '\n');
					cout << "Invalid Integer, try again: ";
				}
				else if (choose < 1 || choose > m_ItemNum)
				{
					cout << "Invalid selection, try again: ";
				}
				else
				{
					done = true;
					cin.ignore();
				}
			} while (!done);
		}
		else
		{
			choose = 0;
		}
		return choose;
	}

	Menu::operator int() const
	{
		return run();
	}




	ostream& operator<<(ostream& os, const MenuItem& menuItem)
	{
		// TODO: insert return statement here
		os << menuItem.m_value << endl;
		return os;
	}

}