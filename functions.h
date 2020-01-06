#pragma once
#include <vector>

void BubbleSort(sf::RectangleShape* arr, short n, int height, int width, sf::RenderWindow& window, int timer);

void heapify(sf::RectangleShape* array, short len, short total_len, int i, sf::RenderWindow& window, int timer);

void HeapSort(sf::RectangleShape* array, short len, sf::RenderWindow& window, int timer);

int partition(sf::RectangleShape* array, short low, short high, sf::RenderWindow& window, int timer, int size);

void QuickSort(sf::RectangleShape* array, short low, short high, sf::RenderWindow& window, int timer, int size);

void InsertSort(sf::RectangleShape* arr, short n, int height, int width, sf::RenderWindow& window, int timer);

void swap(int* xp, int* yp);

void Generate_Bars(long amount, int window_height, int window_width, sf::RectangleShape* tab);

void Randomize(sf::RectangleShape* tab, long amount);

void Reposition(sf::RectangleShape* tab, short amount, int window_height, int window_width);

void Complete(sf::RectangleShape* tab, short amount);

void swap_Pos(sf::RectangleShape* xp, sf::RectangleShape* yp);

void Close_check(sf::RenderWindow& window);


