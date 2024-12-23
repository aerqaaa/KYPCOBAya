#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int** CreateMatrix(int n) { //функция создающая матрицу
	int** Matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		Matrix[i] = new int[n];
		for (int j = 0; j < n; j++)
			Matrix[i][j] = 0;
	}
	return Matrix;
}

int** InputMatrix(int** Matrix, int n) { //функция ввода матриц
	cout << "\nВведите матрицу:\n";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> Matrix[i][j];
	return Matrix;
}

void Print(int** arr, int n) { //простое печатание матрицы
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(3) << arr[i][j];
		}
		cout << endl;
	}
}

void ChoosingMenu() { //вывод подменю в консоль
	cout << "\nВыберите матрицу для работы:\n";
	cout << "1 - Матрица A\n";
	cout << "2 - Матрица B\n";
	cout << "3 - Матрица C\n";
	cout << "4 - Вернуться к предыдущему меню\n";
}

void InputKeyboard(int** arrA, int** arrB, int** arrC, int MatrixChoice, int n) { //функция ввода матрицы с клавиатуры
	while (true) {
		ChoosingMenu();
		cin >> MatrixChoice;
		if (MatrixChoice >= 1 && MatrixChoice <= 4)break; //проверка на правильность выбора действия
		else {
			cout << "Неправильно введенный номер, выберите другой\n";
			continue;
		}
	}
	switch (MatrixChoice) {
	case 1: //ввод матрицы А с клавиатуры
	{
		InputMatrix(arrA, n);
		InputKeyboard(arrA, arrB, arrC, MatrixChoice, n);
	}
	break;
	case 2: //ввод матрицы В с клавиатуры
	{
		InputMatrix(arrB, n);
		InputKeyboard(arrA, arrB, arrC, MatrixChoice, n);
	}
	break;
	case 3: //ввод матрицы С с клавиатуры
	{
		InputMatrix(arrC, n);
		InputKeyboard(arrA, arrB, arrC, MatrixChoice, n);
	}
	break;
	case 4: //выход из функции
		break;
	}
}

void InputFile(int** arrA, int** arrB, int** arrC, int MatrixChoice, int n) { //файловый ввод матрицы
	while (true) {
		ChoosingMenu();
		cin >> MatrixChoice;
		if (MatrixChoice >= 1 && MatrixChoice <= 4)break; //проверка на правильность выбора действия
		else {
			cout << "Неправильно введенный номер, выберите другой\n";
			continue;
		}
	}
	switch (MatrixChoice) {
	case 1: //файловый ввод матрицы А
	{
		ifstream in("matrixA.txt");
		if (in.is_open()) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					in >> arrA[i][j];
			cout << "\nНомера были успешно введены из файла\n";
			in.close();
		}
		else
			cout << "\nОшибка при открытии файла\n";
		InputFile(arrA, arrB, arrC, MatrixChoice, n);
	}
	break;
	case 2: //файловый ввод матрицы В
	{
		ifstream in("matrixB.txt");
		if (in.is_open()) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					in >> arrB[i][j];
			cout << "\nНомера были успешно введены из файла\n";
			in.close();
		}
		else
			cout << "\nОшибка при открытии файла\n";
		InputFile(arrA, arrB, arrC, MatrixChoice, n);
	}
	break;
	case 3: //файловый ввод матрицы С
	{
		ifstream in("matrixC.txt");
		if (in.is_open()) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					in >> arrC[i][j];
			cout << "\nНомера были успешно введены из файла\n";
			in.close();
		}
		else
			cout << "\nОшибка при открытии файла\n";
		InputFile(arrA, arrB, arrC, MatrixChoice, n);
	}
	break;
	case 4: //выход из функции
		break;
	}
}

void InputMenu(int** arrA, int** arrB, int** arrC, int MatrixChoice, int n) { //функции меню ввода матриц
	int InputChoice;
	while (true) {
		cout << "\nКакой метод вы хотели бы использовать для ввода значений:\n";
		cout << "1 - Ввод с клавиатуры\n";
		cout << "2 - Ввод данных из файла\n";
		cout << "3 - Вернуться к предыдущему меню\n";
		cin >> InputChoice;
		if (InputChoice >= 1 && InputChoice <= 3)break; //проверка на правильность выбора действия
		else {
			cout << "Неправильно введенный номер, выберите другой\n";
			continue;
		}
	}
	switch (InputChoice) {
	case 1: //выбор ввода с клавиатуры
	{
		InputKeyboard(arrA, arrB, arrC, MatrixChoice, n);
		InputMenu(arrA, arrB, arrC, MatrixChoice, n);
	}
	break;
	case 2: //выбор ввода с файла
	{
		InputFile(arrA, arrB, arrC, MatrixChoice, n);
		InputMenu(arrA, arrB, arrC, MatrixChoice, n);
	}
	break;
	case 3: //выход обратно на главное меню
		break;
	}
}

int** EditMatrix(int** arr, int n) { //функия позволяющая выбрать и отредактировать специфичный элемент матрицы
	int row, column, newnum;
	char proceed;
	while (true) {
		cout << endl << "Выберите элемент, который вы хотели бы отредактировать:\n";
		while (true) {
			cout << "Ряд: ";
			cin >> row;
			if (row < n && row >= 0)break; //проверка подходит ли заданная строка к размерности матрицы
			else {
				cout << endl << "Значение должно быть меньше, чем " << n << " и больше или равно 0" << endl;
			}
		}
		while (true) {
			cout << "Колонка: ";
			cin >> column;
			if (column < n && column >= 0)break; //проверка подходит ли заданный столбец к размерности матрицы
			else {
				cout << "Значение должно быть меньше, чем " << n << " и больше или равно 0" << endl;
			}
		}
		cout << "Новое значение: "; //ввод нового числа
		cin >> newnum;

		arr[row][column] = newnum;

		cout << endl << "Обновленная матрица:\n"; //вывод отредактированной матрицы
		Print(arr, n);

		cout << endl << "Хотите продолжить редактирование? (введите y - (да) или n - (нет)):\n"; //выбор продолжать ли редактировать матрицу или нет
		cin >> proceed;
		if (proceed == 'n')break;
		else continue;
	}
	return arr;
}

void EditingMenu(int** arrA, int** arrB, int** arrC, int MatrixChoice, int n) { //меню выбора матрицы для редактирования 
	while (true) {
		ChoosingMenu();
		cin >> MatrixChoice;
		if (MatrixChoice >= 1 && MatrixChoice <= 4)break; //проверка на правильность выбора действия
		else {
			cout << "Неправильно введенный номер, выберите другой\n";
			continue;
		}
	}
	switch (MatrixChoice) {
	case 1: //редактирование матрицы А
	{
		EditMatrix(arrA, n);
		EditingMenu(arrA, arrB, arrC, MatrixChoice, n);
	}
	break;
	case 2: //редактирование матрицы В
	{
		EditMatrix(arrB, n);
		EditingMenu(arrA, arrB, arrC, MatrixChoice, n);
	}
	break;
	case 3: //редактирование матрицы С
	{
		EditMatrix(arrC, n);
		EditingMenu(arrA, arrB, arrC, MatrixChoice, n);
	}
	break;
	case 4: //выход в главное меню
		break;
	}
}

void OutputKeyboard(int** arrA, int** arrB, int** arrC, int MatrixChoice, int n) { //функция вывода матриц с клавиатуры
	while (true) {
		ChoosingMenu();
		cin >> MatrixChoice;
		if (MatrixChoice >= 1 && MatrixChoice <= 4)break; //проверка на правильность выбора действия
		else {
			cout << "Неправильно введенный номер, выберите другой\n";
			continue;
		}
	}
	switch (MatrixChoice) {
	case 1: //вывод матрицы А
	{
		Print(arrA, n);
		OutputKeyboard(arrA, arrB, arrC, MatrixChoice, n);
	}
	break;
	case 2: //вывод матрицы В
	{
		Print(arrB, n);
		OutputKeyboard(arrA, arrB, arrC, MatrixChoice, n);
	}
	break;
	case 3: //вывод матрицы С
	{
		Print(arrC, n);
		OutputKeyboard(arrA, arrB, arrC, MatrixChoice, n);
	}
	break;
	case 4: //выход из функции
		break;
	}
}

void OutputFile(int** arrA, int** arrB, int** arrC, int MatrixChoice, int n) { //функция и выбор матрицы для вывода чисел из файла
	while (true) {
		ChoosingMenu();
		cin >> MatrixChoice;
		if (MatrixChoice >= 1 && MatrixChoice <= 4)break; //проверка на правильность выбора действия
		else {
			cout << "Неправильно введенный номер, выберите другой\n";
			continue;
		}
	}
	switch (MatrixChoice) {
	case 1: //вывод матрицы А из файла
	{
		ifstream fin;
		fin.open("matrixA.txt");

		if (!fin.is_open()) //проверка открылся ли файл правильно
			cout << "\nФайл не открылся\n";
		else { //вывод матриц из текстового файла построчно
			cout << "\nМатрица, которая находится в файле:\n";
			string str;
			while (!fin.eof()) {
				str = "";
				getline(fin, str);
				cout << str << endl;
			}
		}
		OutputFile(arrA, arrB, arrC, MatrixChoice, n);
	}
	break;
	case 2: //вывод матрицы В из файла
	{
		ifstream fin;
		fin.open("matrixB.txt");

		if (!fin.is_open()) //проверка открылся ли файл правильно
			cout << "\nФайл не открылся\n";
		else { //вывод матриц из текстового файла построчно
			cout << "\nМатрица, которая находится в файле:\n";
			string str;
			while (!fin.eof()) {
				str = "";
				getline(fin, str);
				cout << str << endl;
			}
		}
		OutputFile(arrA, arrB, arrC, MatrixChoice, n);
	}
	break;
	case 3: //вывод матрицы С из файла
	{
		ifstream fin;
		fin.open("matrixC.txt");

		if (!fin.is_open()) //проверка открылся ли файл правильно
			cout << "\nФайл не открылся\n";
		else { //вывод матриц из текстового файла построчно
			cout << "\nМатрица, которая находится в файле:\n";
			string str;
			while (!fin.eof()) {
				str = "";
				getline(fin, str);
				cout << str << endl;
			}
		}
		OutputFile(arrA, arrB, arrC, MatrixChoice, n);
	}
	break;
	case 4: //выход из функции
		break;
	}
}

void OutputMenu(int** arrA, int** arrB, int** arrC, int MatrixChoice, int n) { //меню выбора метода вывода матрицы
	int OutputChoice;
	while (true) {
		cout << "Какой метод вы хотели бы использовать для вывода значений:\n";
		cout << "1 - Вывод с клавиатуры\n";
		cout << "2 - Вывод из файла\n";
		cout << "3 - Вернуться к предыдущему меню\n";
		cin >> OutputChoice;
		if (OutputChoice >= 1 && OutputChoice <= 3)break; //проверка на правильность выбора действия
		else {
			cout << "Неправильно введенный номер, выберите другой\n";
			continue;
		}
	}
	switch (OutputChoice) {
	case 1: //выбор вывода с клавиатуры
	{
		OutputKeyboard(arrA, arrB, arrC, MatrixChoice, n);
		OutputMenu(arrA, arrB, arrC, MatrixChoice, n);
	}
	break;
	case 2: //выбор вывода из файла 
	{
		OutputFile(arrA, arrB, arrC, MatrixChoice, n);
		OutputMenu(arrA, arrB, arrC, MatrixChoice, n);
	}
	break;
	case 3: //выход обратно в главное меню
		break;
	}
}

int** RowCompare(int** arrA, int** arrB, int** arrC, int size) { 
	cout << "\nЗначения строк:\n";
	bool bigger = false;
	for (int i = 0; i < size; i++) {
		bigger = false;
		for (int j = 0; j < size; j++) {
			if (arrC[i][j] > arrA[i][j] * arrB[i][j])
				bigger = true;
			else {
				bigger = false;
				break;
			}
		}
		if (bigger == true)
			cout << i << " ";
	}
	if (bigger == false)
		cout << "В матрице C нет строк, элементы которых превышали бы сумму произведения элементов матриц A и B";
	cout << endl;
	return arrC;
}

void MainMenu(int** arrA, int** arrB, int** arrC, int n) { //главное меню
	int ActionNum, MatrixChoice = 0;
	while (true) {
		cout << "\nЧто бы вы хотели сделать:\n";
		cout << "1 - Ввести матрицу\n";
		cout << "2 - Редактировать матрицу\n";
		cout << "3 - Вывести матрицу\n";
		cout << "4 - Определить является ли матрица С результатом перемножения матриц А и В\n";
		cout << "5 - Выйти из программы\n";
		cin >> ActionNum;
		if (ActionNum >= 1 && ActionNum <= 5)break; //проверка на правильность выбора действия
		else {
			cout << "Неправильно введенный номер, выберите другой\n";
			continue;
		}
	}
	switch (ActionNum) {
	case 1: //выбор функции ввода матрицы
	{
		InputMenu(arrA, arrB, arrC, MatrixChoice, n);
		MainMenu(arrA, arrB, arrC, n);
	}
	break;
	case 2: //выбор редактирования матрицы
	{
		EditingMenu(arrA, arrB, arrC, MatrixChoice, n);
		MainMenu(arrA, arrB, arrC, n);
	}
	break;
	case 3: //выбор вывода матрицы
	{
		OutputMenu(arrA, arrB, arrC, MatrixChoice, n);
		MainMenu(arrA, arrB, arrC, n);
	}
	break;
	case 4: //выбор нахождения значений рядов 
	{
		RowCompare(arrA, arrB, arrC, n);
		MainMenu(arrA, arrB, arrC, n);
	}
	break;
	case 5: //выход из программы и очищение памяти
	{
		delete arrA;
		delete arrB;
		delete arrC;
	}
	return;
	}
}

int main() {
	int size; //ввод переменной размерности

	cout << "ДОБРО ПОЖАЛОВАТЬ В МАТРИЧНЫЙ КАЛЬКУЛЯТОР\n";
	cout << "Введите размеры матриц:\n";
	cin >> size; //ввод размерности матриц

	while (size < 1) { //проверка на правильность ввода размерности
		cout << "Недопустимый размер, размер должен быть не менее 1\n";
		cin >> size;
	}

	int** arrA = CreateMatrix(size); //создание матриц
	int** arrB = CreateMatrix(size);
	int** arrC = CreateMatrix(size);

	MainMenu(arrA, arrB, arrC, size); //главная функция 
	return 0;
}
