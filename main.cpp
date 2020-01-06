#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <math.h>
#include "functions.h"
#include <vector>


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
start:
	system("cls");
	std::cout << "Sorting Method:\n" << "1.BubbleSort\n" << "2.HeapSort\n"<<"3.QuickSort\n" << "4.InsertionSort\n";
	char choice;
	std::cin >> choice;
	std::string title;
	switch (choice)
	{
	case '1':
		title = "BubbleSort";

		break;
	case '2':
		title = "HeapSort";

		break;
	case '3':
		title = "QuickSort";

		break;
	case '4':
		title = "InsertSort";

		break;
	default:
		std::cout << "Wrong Value";
		Sleep(10);
		std::cout << "\nExit? Y/N";
		std::cin >> choice;
		if (choice == 'Y' || choice == 'y') break;
		goto start;
		break;
	}
	short precision;
precisioning:
	std::cout << "Enter Amount of Elements <1;765>:";
	std::cin >> precision;
	if (precision < 1 || precision > 765)
	{
		std::cout << "Wrong Value";
		Sleep(500);
		system("cls");
		goto precisioning;
	}
	int amount = precision;

	system("cls");
	std::cout << "Enter Speed (Bigger = Slower):";
	unsigned time;
	std::cin >> time;

	int height = 765, width = ((height*2)/precision)*precision;
	
	sf::RectangleShape* bar = new sf::RectangleShape[precision];
	Generate_Bars(precision, height, width, bar);
	Randomize(bar, precision);
	Reposition(bar, precision, height, width);


	sf::RenderWindow window(sf::VideoMode(width, height), title);

	while (window.isOpen())
	{
		Close_check(window);
		if (title=="BubbleSort")
		{
			BubbleSort(bar, precision, height, width, window, time);
			title = "null";
			Complete(bar, precision);
		}
		if (title == "HeapSort")
		{
			HeapSort(bar, precision, window, time);
			title = "null";
			Complete(bar, precision);
		}
		if (title == "InsertSort")
		{
			InsertSort(bar, precision, height, width, window, time);
			title = "null";
			Complete(bar, precision);
		}
		if (title == "QuickSort")
		{
			QuickSort(bar, 0, precision-1, window, time, precision);
			title = "null";
			Complete(bar, precision);
		}

		window.clear();
		for (int k = 0; k < precision; k++)
		{
			window.draw(bar[k]);
		}
		window.display();
	}

	return 0;
}