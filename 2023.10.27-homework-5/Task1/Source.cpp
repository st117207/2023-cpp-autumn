#include<iostream>
#include"Function.h"
int main(int argc, char* argv[])
{
	int* a = nullptr;
	int length = 0;
	bool exit = false;
	std::setlocale(LC_ALL, "Russian");
	while (!exit)
	{
		{
			system("cls");
			printMenu();
			PrintArray(a, length);
			std::cout << std::endl;
			std::cout << "������� �������: ";
		}
		int choice = 0;
		{
			std::cin >> choice;
		}
		{
			switch (choice)
			{
			case 0:
				exit = true;
				break;
			case 1:
				PrintArray(a, length);
				system("pause");
				break;
			case 2:
			{
				int element = 0;
				std::cout << "������� ������� ��� ���������� : ";
				std::cin >> element;
				AddElement(a, length, element);
				break;
			}
			case 3:
			{
				if (a == nullptr)
				{
					std::cout << "������ ��������� ��� ������� � ������ ��������" << std::endl;
					system("pause");
				}
				else
				{
					int index = 0;
					std::cout << "������� ������� ��� �������� : ";
					std::cin >> index;
					if (index > length - 1)
					{
						std::cout << "������ �������� ��� � �������" << std::endl;
						system("pause");
					}
					else
					{
						std::cout << "����� " << DeleteElement(a, length, index) << " �������" << std::endl;
						system("pause");
					}
				}
				break;
			}
			case 4:
			{
				if (a == nullptr)
				{
					std::cout << "������ ��������� ��� ������� � ������ ��������" << std::endl;
					system("pause");
				}
				SortArray(a, length);
				PrintArray(a, length);
				break;
			}
			case 5:
			{
				if (a == nullptr)
				{
					std::cout << "������ ��������� ��� ������� � ������ ��������" << std::endl;
					system("pause");
				}
				ReverseArray(a, length);
				PrintArray(a, length);

				break;
			}
			case 6:
			{
				if (a == nullptr)
				{
					std::cout << "������ ��������� ��� ������� � ������ ��������" << std::endl;
					system("pause");
				}
				std::cout << ChangeElements(a, length);
				system("pause");
				PrintArray(a, length);


				break;
			}
			case 7:
			{
				if (a == nullptr)
				{
					std::cout << "������ ��������� ��� ������� � ������ ��������" << std::endl;
					system("pause");
				}
				DeleteDuplicateElements(a, length);
				PrintArray(a, length);

				break;
			}
			case 8:
			{
				int n = 0;
				std::cout << "������� ���������� ��������� : ";
				std::cin >> n;

				AddRandomizeElements(a, length, n);
				PrintArray(a, length);

				break;
			}
			default:
				std::cout << "����������� �������" << std::endl;
				break;
			}
		}
	}
	return EXIT_SUCCESS;
}