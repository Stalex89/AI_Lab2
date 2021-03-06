// AI_Lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Mosaic_Board.h"
#include "Hitori_Board.h"

// Define constraints 
constexpr int fieldSize{ 12 }; // enter 5 or 8 
constexpr int number{ 1 }; // enter 1 or 2 for fieldsize = 5 


void LetterMosaic();
void Hitori();

int main()
{
	//LetterMosaic();
	Hitori();
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

		delete b;
		b = nullptr;
	}
	catch(const invalid_argument &ex) 
	{
		cout << ex.what() << "\n";
	}
	
}

void Hitori()
{


	try
	{
		// Creating board
		Hitori_Board *h = new Hitori_Board(fieldSize, number);
		h->PrintBoard();

		// Start timer 
		auto start = chrono::high_resolution_clock::now();

		if (h->BackTracking())
		{
			cout << "The solution is :\n\n";
			h->PrintBoard();
		}
		else
			cout << "no solution" << '\n';

		//if (h->ForwardChecking())
		//{
		//	cout << "The solution is :\n\n";
		//	h->PrintBoard();
		//}
		//else
		//	cout << "no solution" << '\n';
		
		// End timer
		auto finish = chrono::high_resolution_clock::now();

		// Create duration instance
		chrono::duration<double> elapsed = finish - start;

		cout << "Elapsed time : " << elapsed.count() << " s\n\n";


		delete h;
		h = nullptr;
	}
	catch (const invalid_argument &ex)
	{
		cout << ex.what() << "\n";
	}
}
