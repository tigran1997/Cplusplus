// Snake.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<vector>
#include<string>
#include<conio.h>

using namespace std;

int x = 1;
int y = 1;

char c; // for getch

vector<string> lab; // map

void print() {
//	system("cls");
	for (int i = 0; i < lab.size(); i++) {
		cout << lab[i] << endl;
	}
}

int main()
{
	lab.push_back("#######################################");
	lab.push_back("#A                                    #");
	lab.push_back("#                                     #");
	lab.push_back("#                                     #");
	lab.push_back("#                                     #");
	lab.push_back("#                                     #");
	lab.push_back("#                                     #");
	lab.push_back("#                                     #");
	lab.push_back("#                                     #");
	lab.push_back("#                                     #");
	lab.push_back("#######################################");
	while (c != 'e')
	{
		print();
		c = _getch();
		switch (c) {
		case 'w': //up
		{

			if (lab[x - 1][y] == ' ') {
				lab[x - 1][y] = lab[x][y];
				lab[x][y] = ' ';
				--x;
			}
			break;
		}
		case 's': //down
		{
			if (lab[x + 1][y] == ' ') {
				lab[x + 1][y] = lab[x][y];
				lab[x][y] = ' ';
				++x;
			}
			break;
		}
		case 'a': //left
		{
			if (lab[x][y - 1] == ' ') {
				lab[x][y - 1] = lab[x][y];
				lab[x][y] = ' ';
				--y;
			}
			break;
		}
		case 'd': //right
		{
			if (lab[x][y + 1] == ' ') {
				lab[x][y + 1] = lab[x][y];
				lab[x][y] = ' ';
				++y;
			}
			break;
		}
		}
	}
	_getch();
	return 0;
}
