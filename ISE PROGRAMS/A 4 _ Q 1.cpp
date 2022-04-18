#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
void Fill(char** grid, int max) {
	int ran = 0;
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			ran = (rand() % 26) + 1;
			ran += 64;
			if (grid[i][j] == '*') {
				grid[i][j] = ran;
			}
		}
	}

}
void swap(char *str,int size) {
	char temp;
	for (int i = 0, j = size - 1; i < size/2; i++, j--) {
		temp = str[j];
		str[j] = str[i];
		str[i] = temp;
	}
}
bool check_v(int row, int col, char **grid, int size) {
	for (int i = col + 1; i < (col + size); i++) {
		if (grid[row][i] != '*') {
			return 0;
		}
	}
	return 1;
}
bool check_h(int row, int col, char** grid, int size) {
	for (int i = row + 1; i < (row + size); i++) {
		if (grid[i][col] != '*') {
			return 0;
		}
	}
	return 1;
}
bool check_sr(int row, int col, char** grid, int size) {
	for (int i = row + 1, j = col + 1; i < 15; i++, j++) {
		if (grid[i][j] != '*') {
			return 0;
		}
	}
	return 1;
}
bool check_sl(int row, int col, char** grid, int size) {
	for (int i = row + 1, j = col + 1; i < (row + size); i++, j--) {
		if (grid[i][j] != '*') {
			return 0;
		}
	}
	return 1;
}
bool l_to_r(char *str,int size,char **grid,int max) {
	bool flag=0;
	int row = 0, col = 0;
	for (int x = 0; x < max; x++) {
		while (true){
			row = (rand() % max);
			col = (rand() % max);
			if ((max - col) > size) {
				break;
			}
		}
		if (grid[row][col] == '*') {
			if (check_v(row, col, grid, size)) {
				flag = 1;
				break;
			}
			else {
				flag = 0;
			}
		}
	}
	if (flag) {
		for (int i = col, j = 0; j < size; i++, j++) {
			grid[row][i] = str[j];
		}
		return 1;
	}
	else {
		return 0;
	}
}
bool r_to_l(char* str, int size, char** grid, int max) {
	swap(str, size);
	if (l_to_r(str, size, grid, max)) {
		return 1;
	}
}
bool t_to_b(char* str, int size, char** grid, int max) {
	bool flag = 0;
	int row = 0, col = 0;
	for (int x = 0; x < max; x++) {
		while (true) {
			row = (rand() % max);
			col = (rand() % max);
			if ((max - row) > size) {
				break;
			}
		}
		if (grid[row][col] == '*') {
			if (check_h(row, col, grid, size)) {
				flag = 1;
				break;
			}
			else {
				flag = 0;
			}
		}
	}
	if (!flag) {
		return 0;
	}
	else {
		for (int i = row, j = 0; j < size; i++, j++) {
			grid[i][col] = str[j];
		}
		return 1;
	}
}
bool b_to_t(char* str, int size, char** grid, int max) {
	swap(str, size);
	if (t_to_b(str, size, grid, max)) {
		return 1;
	}
}
bool lt_to_rb(char* str, int size, char** grid, int max) {
	bool flag = 0;
	int row = 0, col = 0;
	for (int i = 0; i < max; i++) {
		while (true) {
			row = (rand() % max);
			col = (rand() % max);
			if (((max - row) > size) && ((max - col) > size)) {
				break;
			}
		}
		if (grid[row][col] == '*') {
			if (check_sr(row, col, grid, size)) {
				flag = 1;
				break;
			}
			else {
				flag = 0;
			}
		}
	}
	if (!flag) {
		return 0;
	}
	else {
		for (int i = row, j = col, k = 0; k < size; k++,i++,j++) {
			grid[i][j] = str[k];
		}
		return 1;
	}
}
bool rt_to_lb(char* str, int size, char** grid, int max) {
	bool flag = 0;
	int row = 0, col = 0;
	for (int i = 0; i < max; i++) {
		while (true) {
			row = (rand() % max);
			col = (rand() % max);
			if (((max - row) > size) && ((max - col) > size)) {
				break;
			}
		}
		if (grid[row][col] == '*') {
			if (check_sr(row, col, grid, size)) {
				flag = 1;
				break;
			}
			else {
				flag = 0;
			}
		}
	}
	if (!flag) {
		return 0;
	}
	else {
		for (int i = row, j = col, k = 0; k < size; k++, i++, j--) {
			grid[i][j] = str[k];
		}
		return 1;
	}
}
bool rb_to_lt(char* str, int size, char** grid, int max) {
	swap(str, size);
	if (lt_to_rb(str, size, grid, max)) {
		return 1;
	}
}
bool lb_to_rt(char* str, int size, char** grid, int max) {
	swap(str, size);
	if (rt_to_lb(str, size, grid, max)) {
		return 1;
	}
}
int main() {
	srand(time(0));
	ifstream fin;
	char str1[50];
	char str[50];
	int size, ran;
	int max = 0, words = 0;
	fin.open("input.txt");
	while (fin.getline(str1, 50)) {
		words++;
	}
	fin.close();
	fin.open("input.txt", ios::in);
	for (int i = 0; i < words; i++) {
		size = 0;
		fin.getline(str, 50);
		for (int i = 0; str[i] != '\0'; i++) {
			size++;
		}
		if (size > max) {
			max = size;
		}
	}
	fin.close();
	max += 5;
	char **grid;
	grid = new char* [max];
	for (int i = 0; i < max; i++) {
		grid[i] = new char[max];
	}
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			grid[i][j] = '*';
		}
	}
	fin.open("input.txt", ios::in);
	for (int i = 0; i < words; i++) {
		size = 0;
		fin.getline(str, 50);
		for (int i = 0; str[i] != '\0'; i++) {
			size++;
		}
		/*for (int i = 0; i < size; i++) {
			cout << str[i];
		}
		cout << endl;
		cout << size << endl;*/
		while (true) {
		    ran = (rand() % 8);
			if (ran == 0) {
				if (l_to_r(str,size,grid,max)) {
					break;
				}
			}
			else if (ran == 1) {
				if (r_to_l(str, size, grid, max)) {
					break;
				}
			}
			else if (ran == 2) {
				if (t_to_b(str, size, grid, max)) {
					break;
				}
			}
			else if (ran == 3) {
				if (b_to_t(str, size, grid, max)) {
					break;
				}
			}
			else if (ran == 4) {
				if (lt_to_rb(str, size, grid, max)) {
					break;
				}
			}
			else if (ran == 5) {
				if (rt_to_lb(str, size, grid, max)) {
					break;
				}
			}
			else if (ran == 6) {
				if (rb_to_lt(str, size, grid, max)) {
				    break;
			    }
			}
			else if (ran == 7) {
			    if (lb_to_rt(str, size, grid, max)) {
				    break;
			    }
			}
		}
	}
	/*for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/
	Fill(grid, max);
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}