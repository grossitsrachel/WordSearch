#include <iostream>
#include <math.h>
#include <time.h>
#include <string>
using namespace std;
const int size = 8;
const int numWords = 4;
void initializeGrid (char grid[size][size]);
void printGrid (char grid[size][size]);
void addWordsAcross (char grid[size][size], string word);
void addWordsDown (char grid[size][size], string word);
void addWordsDiagonal (char grid[size][size], string word);
void randomLetters (char grid[size][size]);

int main()
{
	srand ( time(NULL) ); 
	char grid[size][size], keepGrid;
	string words[numWords];
	initializeGrid (grid);
	printGrid (grid);
	cout << "Welcome to Word Search!" << endl;
	for (int x=0; x<numWords; x++)
	{
		cout << "Enter word " << x+1 << ": ";
		cin >> words[x];
	}
	do
	{
		initializeGrid (grid);
		for (int i = 0; i < numWords; i++)
		{
			int direction;
			direction = rand() % 3;
			if (direction == 0)
				addWordsAcross (grid, words[i]);
			if (direction == 1)
				addWordsDown (grid, words[i]);
			if (direction == 2)
				addWordsDiagonal (grid, words[i]);
		}
		cout << "Would you like to keep this grid? <y/n> ";
		cin >> keepGrid;
	}while(keepGrid == 'n' || keepGrid == 'N');
	randomLetters (grid);
	printGrid (grid);
	return 0;
}

void initializeGrid (char grid[size][size])
{
	for (int y=0; y<size; y++)
	{
		for (int x=0; x<size; x++)
			grid[y][x] = '.';
	}	
}

void printGrid (char grid[size][size])
{
	for (int y=0; y<size; y++)
	{
		for (int x=0; x<size; x++)
			cout << grid[y][x] << " ";
		cout << endl;
	}	
	cout << endl;
}

void addWordsAcross (char grid[size][size], string word)
{
		int x, y;
		bool isOpen;
		cout << "Adding " << word << " to grid..." << endl;
		do
		{
			isOpen = true;
			do
			{
				x = rand() % size;
			} while ((size - x) < word.length());
			y = rand() % size;
			cout << "Adding Right.  Choosing random x: " << x << " y: " << y << endl;
			for (int n = 0; n < word.length(); n++)
			{
				if (grid [y][x+n] != '.' && grid [y][x+n] != word[n])
					isOpen = false;
			}
		} while (isOpen == false);
		for (int n = 0; n < word.length();  n++)
		{
			grid [y][x+n] = word[n];
		}
		cout << word << " added!" << endl;
		printGrid (grid);
}

void addWordsDown (char grid[size][size], string word)
{
		int x, y;
		bool isOpen;
		cout << "Adding " << word << " to grid..." << endl;
		do
		{
			isOpen = true;
			do
			{
				y = rand() % size;
			} while ((size - y) < word.length());
			x = rand() % size;
			cout << "Adding Down.  Choosing random x: " << x << " y: " << y << endl;
			for (int n = 0; n < word.length(); n++)
			{
				if (grid [y+n][x] != '.' && grid [y+n][x] != word[n])
					isOpen = false;
			}
		} while (isOpen == false);
		for (int n = 0; n < word.length();  n++)
		{
			grid [y+n][x] = word[n];
		}
		cout << word << " added!" << endl;
		printGrid (grid);
}

void addWordsDiagonal (char grid[size][size], string word)
{
		int x, y;
		bool isOpen;
		cout << "Adding " << word << " to grid..." << endl;
		do
		{
			isOpen = true;
			do
			{
				x = rand() % size;
			} while ((size - x) < word.length());
			do
			{
				y = rand() % size;
			} while ((size - y) < word.length());
			cout << "Adding Diagonal.  Choosing random x: " << x << " y: " << y << endl;
			for (int n = 0; n < word.length(); n++)
			{
				if (grid [y+n][x+n] != '.' && grid [y+n][x+n] != word[n])
					isOpen = false;
			}
		} while (isOpen == false);
		for (int n = 0; n < word.length();  n++)
		{
			grid [y+n][x+n] = word[n];
		}
		cout << word << " added!" << endl;
		printGrid (grid);
}

void randomLetters (char grid[size][size])
{
	for (int y=0; y<size; y++)
	{
		for (int x=0; x<size; x++)
		{
			if (grid[y][x] == '.')
				grid[y][x] = (char)((97 + (rand() % 26)));
		}
	}
}