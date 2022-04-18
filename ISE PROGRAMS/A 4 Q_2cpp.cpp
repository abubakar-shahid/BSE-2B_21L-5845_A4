#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>
using namespace std;
bool l_to_r(char* str, int size, char** grid, int row, int col, int i1, int i2) {
	if (size > col) {
		return 0;
	}
	for (int i = i2, x = 0; i < (i1 + size); i++, x++) {
		if (str[x] != grid[i1][i]) {
			return 0;
		}
	}
	return 1;
}
void Search(char* str, int size, char** grid, int row, int col) {
	bool flag = 0;
	int st1, st2, end1, end2;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (grid[i][j] == str[0]) {
				if (l_to_r(str, size, grid, row, col, i, j)) {
					flag = 1;
					cout << i << j << endl;
					st1 = i, end1 = j, st2 = (st1 + size) - 1, end2 = (end1 + size) - 1;
					break;
				}
			}
		}
		if (flag) {
			break;
		}
	}
	if (flag) {
		cout << "Word found at (" << st1 << "," << st2 << ") , (" << end1 << "," << end2 << ")." << endl;
	}
	else {
		cout << "Word NOT found" << endl;
	}
}
int main() {
	ifstream fin;
	char str[50];
	int row = 0, col = 0;
	fin.open("Grid.txt", ios::in);
	while (fin.getline(str, 50)) {
		col = 0;
		for (int i = 0; str[i] != '\0'; i++) {
			col++;
		}
		row++;
	}
	fin.close();
	char** grid = new char* [row];
	for (int i = 0; i < row; i++) {
		grid[i] = new char[col];
	}
	fin.open("Grid.txt", ios::in);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			fin >> grid[i][j];
		}
	}
	cout << "                    Welcome to FAST Word-Search Puzzle!!!\n\n";
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	int size;
	char exit;
	for (int i = 1; i > 0; i++) {
		if (i != 1) {
			cout << "Press any key to search another word else press ESC to exit ";
			exit = _getch();
			if (exit == 27) {
				break;
			}
		}
		cout << "\n\nEnter the word that you want to search: ";
		cin.getline(str, 50);
		cout << str << endl;
		size = strlen(str);
		cout << size << endl;
		Search(str, size, grid, row, col);
	}
	return 0;
}