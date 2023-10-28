#include "Function.h"
#include<iostream>

int printMenu()
{
	std:: setlocale(LC_ALL, "Russian");
	std::cout << "0 - Выход из программы" << std::endl;
	std::cout << "1 - Вывести массив" << std::endl;
	std::cout << "2 - Добавить элемент в массив" << std::endl;
	std::cout << "3 - Удалить элемент из массива" << std::endl;
	std::cout << "4 - Отсортировать массив по возрастанию" << std::endl;
	std::cout << "5 - Развернуть массив" << std::endl;
	std::cout << "6 - Поменять местами первый максимальный и последний минимальный элемент массива" << std::endl;
	std::cout << "7 - Удалить из массива все дубликаты" << std::endl;
	std::cout << "8 - Добавить в массив n случайных элементов (n вводится с клавиатуры)" << std::endl;
	
	return 1;
}