#pragma once

int PrintArray(int* a, int length);
int ExpandArray(int*& a, int& length, int n);
int AddElement(int*& a, int& length, int element);
int DeleteElement(int*& a, int& length, int index);
int SortArray(int* a, int length);
int ReverseArray(int* a, int length);
int SearchIndexFirstMaxElement(int* a, int length);
int SearchIndexLastMinElement(int* a, int length);
int ChangeElements(int* a, int length);
int DeleteDuplicateElements(int*& a, int& length);
int AddRandomizeElements(int*& a, int& length, int n);
int printMenu();
