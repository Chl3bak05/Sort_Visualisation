#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <vector>
#include "functions.h"
#include <time.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void swap_shape(sf::RectangleShape * xp, sf::RectangleShape * yp)
{
	sf::RectangleShape temp = * xp;
	*xp = *yp;
	*yp = temp;
}

void swap_Pos(sf::RectangleShape* xp, sf::RectangleShape* yp) {
	sf::Vector2f temp = xp->getPosition();
	xp->setPosition(yp->getPosition());
	yp->setPosition(temp);
}

void BubbleSort(sf::RectangleShape* arr, short n, int height, int width, sf::RenderWindow& window, int timer) {

	int i, j;

	for (i = 0; i < n - 1; i++)
		// Last i elements are already in place  
		for (j = 0; j < n - i - 1; j++) {
			Close_check(window);

			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			sf::Color temp = arr[j].getFillColor();
			arr[j].setFillColor(sf::Color::White);
			if (arr[j].getSize().y > arr[j + 1].getSize().y) {
				
				Sleep(timer/n);				

				swap_shape(&arr[j], &arr[j + 1]);
				swap_Pos(&arr[j], &arr[j + 1]);
				window.clear();
				for (int k = 0; k < n; k++)
				{
					window.draw(arr[k]);
				}
				window.display();				
				arr[j+1].setFillColor(temp);
			}
			else
			{
				window.clear();
				for (int k = 0; k < n; k++)
				{
					window.draw(arr[k]);
				}
				window.display();
				arr[j].setFillColor(temp);
			}
		}
}

void heapify(sf::RectangleShape* array, short len, short total_len, int i, sf::RenderWindow& window, int timer)
{	
	Close_check(window);

	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < len && array[left].getSize().y > array[largest].getSize().y)
		largest = left;

	if (right < len && array[right].getSize().y > array[largest].getSize().y)
		largest = right;

	sf::Color temp1 = array[i].getFillColor();
	sf::Color temp2 = array[largest].getFillColor();

	array[i].setFillColor(sf::Color::White);
	array[largest].setFillColor(sf::Color::White);

	window.clear();
	for (int k = 0; k < total_len; k++)
	{
		window.draw(array[k]);
	}
	window.display();
	array[i].setFillColor(temp1);
	array[largest].setFillColor(temp2);
	Sleep(timer/total_len);
	if (largest != i)
	{
		swap_shape(&array[i], &array[largest]);
		swap_Pos(&array[i], &array[largest]);
		heapify(array, len, total_len, largest, window, timer);
	}

}

void HeapSort(sf::RectangleShape* array, short len, sf::RenderWindow& window, int timer)
{
	for (int i = len / 2 - 1; i >= 0; i--) {
		heapify(array, len, len , i, window, timer);
	}
		

	for (int i = len - 1; i >= 0; i--)
	{
		window.clear();
		for (int k = 0; k < len; k++)
		{
			window.draw(array[k]);
		}
		window.display();
		swap_shape(&array[0], &array[i]);
		swap_Pos(&array[0], &array[i]);
		heapify(array, i,len, 0, window, timer);
	}
}

int partition(sf::RectangleShape* array, short low, short high, sf::RenderWindow& window, int timer, int size)
{
	int pivot = array[high].getSize().y; // pivot  
	int i = (low - 1); // Index of smaller element  

	for (int j = low; j <= high - 1; j++)
	{
		Close_check(window);

		sf::Color temp1 = array[i].getFillColor();
		sf::Color temp2 = array[j].getFillColor();

		array[i].setFillColor(sf::Color::White);
		array[j].setFillColor(sf::Color::White);

		window.clear();
		for (int k = 0; k < size; k++)
		{
			window.draw(array[k]);
		}
		window.display();

		Sleep(timer / size);

		array[i].setFillColor(temp1);
		array[j].setFillColor(temp2);

		// If current element is smaller than the pivot  
		if (array[j].getSize().y < pivot)
		{
			i++; // increment index of smaller element  
			swap_shape(&array[i], &array[j]);
			swap_Pos(&array[i], &array[j]);

		}
	}
	sf::Color temp1 = array[i+1].getFillColor();
	sf::Color temp2 = array[high].getFillColor();

	array[i+1].setFillColor(sf::Color::White);
	array[high].setFillColor(sf::Color::White);

	window.clear();
	for (int k = 0; k < size; k++)
	{
		window.draw(array[k]);
	}
	window.display();

	Sleep(timer / size);

	array[i+1].setFillColor(temp1);
	array[high].setFillColor(temp2);

	swap_shape(&array[i + 1], &array[high]);
	swap_Pos(&array[i + 1], &array[high]);

	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void QuickSort(sf::RectangleShape* array, short low, short high, sf::RenderWindow& window, int timer, int size)
{	
	Close_check(window);

	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(array, low, high, window, timer, size);

		// Separately sort elements before  
		// partition and after partition  
		QuickSort(array, low, pi - 1, window, timer,size);
		QuickSort(array, pi + 1, high, window, timer,size);
	}
}

void InsertSort(sf::RectangleShape* array, short size, int height, int width, sf::RenderWindow& window, int timer)
{
	int j;
	sf::RectangleShape key;
	sf::RectangleShape temp;
	sf::Color temp_color;
	for (int i = 1; i < size; i++) {
		key = array[i];//take value
		j = i;
		while (j > 0 && array[j - 1].getSize().y > key.getSize().y) {
			Close_check(window);
			temp_color = array[j].getFillColor();
			array[j].setFillColor(sf::Color::White);
			window.clear();
			for (int k = 0; k < size; k++)
			{
				window.draw(array[k]);
			}
			window.display();	
			array[j].setFillColor(temp_color);
			temp = array[j];
			array[j] = array[j - 1];
			array[j].setPosition(temp.getPosition());
			Sleep(timer / size);
			j--;
		}
		temp = array[j];
		array[j] = key; // insert in right place
		array[j].setPosition(temp.getPosition());
	}
}

void Generate_Bars(long amount, int window_height, int window_width, sf::RectangleShape * tab) {
	for (long i = 0; i < amount; i++)
	{
		tab[i].setSize(sf::Vector2f(window_width / amount, (window_height / amount) * i+1));
		tab[i].setOrigin(0, (window_height / amount) * i);
		tab[i].setPosition((window_width / amount) * i, window_height - 1);

		if (i > 510) {
			tab[i].setFillColor(sf::Color::Color(255, i - 510, 0, 255));
		}
		else if (i > 255) {
			tab[i].setFillColor(sf::Color::Color(255, 0, 255-(i-255), 255));
		}
		else tab[i].setFillColor(sf::Color::Color(i, 0, 255, 255));
	}
}

void Randomize(sf::RectangleShape* tab, long amount) {
	srand(time(NULL));
	for (long i = 0; i < amount*amount; i++)
	{
		swap_shape(&tab[rand() % amount], &tab[rand() % amount]);
	}
}

void Reposition(sf::RectangleShape* tab, short amount, int window_height, int window_width) {
	for (short i = 0; i < amount; i++)
	{
		tab[i].setPosition((window_width / amount) * i, window_height - 1);
	}
}

void Complete(sf::RectangleShape* tab, short amount) {
	for (long i = 0; i < amount; i++)
	{
		tab[i].setFillColor(sf::Color::Green);
	}
}

void Close_check(sf::RenderWindow& window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}



