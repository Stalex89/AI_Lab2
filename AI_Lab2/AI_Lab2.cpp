// AI_Lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Mosaic_Board.h"

// Define constraints 
constexpr int fieldSize{ 5 };



void LetterMosaic();

int main()
{
	LetterMosaic();
	system("pause");
    return 0;
}


void LetterMosaic()
{
	try
	{
		// Creating board
		Mosaic_Board *b = new Mosaic_Board(fieldSize);		
		if (b->BacktrackAlgorithm(0, 0, b))
			b->PrintBoard();
		else
			cout << "no solution" << '\n';
	}
	catch(const invalid_argument &ex) { }
	
}

