#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void drawline()
{
    cout << " ";
    for (int m = 0; m < 23; m++)
	cout << "-";
    cout << "\n";
}

template < size_t X, size_t Y > void clearArray(int (&arr)[X][Y])
{
    for (size_t n = 0; n != X; ++n)
	for (size_t m = 0; m != Y; ++m)
	    arr[n][m] = 0;
}

template < size_t X, size_t Y > void drawBoard(int (&arr)[X][Y])
{

    drawline();
    for (int i = 0; i != X; ++i) {
	for (int j = 0; j != Y; ++j) {
	    cout << "|" << setw(5) << arr[i][j];
	}
	cout << "|\n";
	drawline();
    }
}

void reverseSerial(int (&arr)[4])
{
    int cTmp;
    int nMid = 2;
    for (int i = 0; i < nMid; i++) {
	cTmp = arr[i];
	arr[i] = arr[4 - i - 1];
	arr[4 - i - 1] = cTmp;
    }
}

void checkSerial(int (&arr)[4])
{
    int j = 3;
    while (j != 0) {

	for (int i = 3; i > 0; --i) {
	    if ((arr[i] == 0) && (arr[i - 1] != 0)) {
		arr[i] = arr[i - 1];
		arr[i - 1] = 0;
	    }
	}
	j--;
    }

    if ((arr[3] == arr[2]) && (arr[3] != 0)) {
	arr[3] *= 2;
	arr[2] = arr[1];
	arr[1] = arr[0];
	arr[0] = 0;
    }

    if ((arr[2] == arr[1]) && (arr[2] != 0)) {
	arr[2] *= 2;
	arr[1] = arr[0];
	arr[0] = 0;
    }

    if ((arr[1] == arr[0]) && (arr[1] != 0)) {
	arr[1]*= 2;
	arr[0] = 0;
    }

}

void processArray(int direction, int (&arr)[4][4])
{
    //intitalize array 
    int serial[4];
    for (int i = 0; i < 4; i++)
	serial[i] = 0;

    switch (direction) {
    case 0:
	//north
	for (int j = 0; j < 4; j++) {
	    for (int i = 0; i < 4; i++) {
		serial[i] = arr[i][j];
		if (i == 3) {
		    reverseSerial(serial);
		    checkSerial(serial);
		    reverseSerial(serial);
		    for (int m = 0; m < 4; m++)
			arr[m][j] = serial[m];
		}
	    }
	}
	break;
    case 1:
	for (int i = 0; i < 4; i++) {
	    for (int j = 0; j < 4; j++) {
		serial[j] = arr[i][j];
		if (j == 3) {
		    checkSerial(serial);
		    for (int m = 0; m < 4; m++)
			arr[i][m] = serial[m];
		}
	    }
	}
	break;
    case 2:
	for (int j = 0; j < 4; j++) {
	    for (int i = 0; i < 4; i++) {
		serial[i] = arr[i][j];
		if (i == 3) {
		    checkSerial(serial);
		    for (int m = 0; m < 4; m++)
			arr[m][j] = serial[m];
		}
	    }
	}
	break;
    case 3:
	for (int i = 0; i < 4; i++) {
	    for (int j = 0; j < 4; j++) {
		serial[j] = arr[i][j];
		if (j == 3) {
		    reverseSerial(serial);
		    checkSerial(serial);
		    reverseSerial(serial);
		    for (int m = 0; m < 4; m++)
			arr[i][m] = serial[m];
		}
	    }
	}

	break;
    default:
	break;
    }
}

void addsTwo(int (&arr)[4][4])
{
    srand(time(NULL));

    while (1) {
	int ranX = rand() % 3;
	int ranY = rand() % 3;
	if (arr[ranX][ranY] == 0) {
	    arr[ranX][ranY] = 2;
	    break;
	}
    }
}

int main()
{
    int posArray[4][4];
    clearArray(posArray);
    int direction = 0;
    char cDirection = { 0 };

    while (1) {
	addsTwo(posArray);
	drawBoard(posArray);

	cout << "\nEnter direction to move (wasd) : ";
	cin >> cDirection;
	switch (cDirection) {
	case 'w':
	    processArray(0, posArray);
	    break;
	case 's':
	    processArray(2, posArray);
	    break;
	case 'a':
	    processArray(3, posArray);
	    break;
	case 'd':
	    processArray(1, posArray);
	    break;
	}
	drawBoard(posArray);
    }
    return 0;
}
