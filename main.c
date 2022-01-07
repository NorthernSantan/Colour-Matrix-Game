#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 21
#define MAX_COLS 21

#define MIN_VALUE 0
#define MAX_VALUE 5
#define OPEN 'O'
#define CLOSED 'C'


enum colourType {
    red, green, blue, yellow, pink
};


typedef struct {
    enum colourType colour; // see the possible colors
    int value;      // integer from 0 to 5
    char status;  // a grid cell is either open or closed
} cellType;

// data structure for a matrix
typedef struct {
    cellType cells[MAX_ROWS + 1][MAX_COLS + 1]; // ignore row 0 and col 0 on board!
    int r, c;    // number of rows and columns of cells
} boardType;

// use this to output the enumerated type data
char COLOURS[][10] = {"R", "G", "B", "Y", "P"};

// This function just sets up a gameboard that you can use later
void hardCodeBoard(boardType *B) {
    // set to a 10 by 7 board
    // remember ignore row 0 and col 0
    B->r = 7;
    B->c = 10;

    // set ALL cells to closed
    for (int rows = 1; rows <= B->r; rows++)
        for (int cols = 1; cols <= B->c; cols++)
            B->cells[rows][cols].status = CLOSED;

    // now set each cell
    B->cells[1][1].colour = red;
    B->cells[1][1].value = 5;
    B->cells[1][2].colour = green;
    B->cells[1][2].value = 2;
    B->cells[1][3].colour = blue;
    B->cells[1][3].value = 4;
    B->cells[1][4].colour = pink;
    B->cells[1][4].value = 3;
    B->cells[1][5].colour = green;
    B->cells[1][5].value = 4;
    B->cells[1][6].colour = yellow;
    B->cells[1][6].value = 1;
    B->cells[1][7].colour = red;
    B->cells[1][7].value = 3;
    B->cells[1][8].colour = green;
    B->cells[1][8].value = 0;
    B->cells[1][9].colour = green;
    B->cells[1][9].value = 4;
    B->cells[1][10].colour = pink;
    B->cells[1][10].value = 1;

    B->cells[2][1].colour = yellow;
    B->cells[2][1].value = 2;
    B->cells[2][2].colour = pink;
    B->cells[2][2].value = 1;
    B->cells[2][3].colour = green;
    B->cells[2][3].value = 3;
    B->cells[2][4].colour = red;
    B->cells[2][4].value = 5;
    B->cells[2][5].colour = blue;
    B->cells[2][5].value = 5;
    B->cells[2][6].colour = blue;
    B->cells[2][6].value = 0;
    B->cells[2][7].colour = yellow;
    B->cells[2][7].value = 2;
    B->cells[2][8].colour = red;
    B->cells[2][8].value = 1;
    B->cells[2][9].colour = blue;
    B->cells[2][9].value = 3;
    B->cells[2][10].colour = yellow;
    B->cells[2][10].value = 4;

    B->cells[3][1].colour = pink;
    B->cells[3][1].value = 4;
    B->cells[3][2].colour = green;
    B->cells[3][2].value = 3;
    B->cells[3][3].colour = blue;
    B->cells[3][3].value = 5;
    B->cells[3][4].colour = blue;
    B->cells[3][4].value = 1;
    B->cells[3][5].colour = green;
    B->cells[3][5].value = 1;
    B->cells[3][6].colour = red;
    B->cells[3][6].value = 0;
    B->cells[3][7].colour = pink;
    B->cells[3][7].value = 0;
    B->cells[3][8].colour = pink;
    B->cells[3][8].value = 1;
    B->cells[3][9].colour = yellow;
    B->cells[3][9].value = 2;
    B->cells[3][10].colour = blue;
    B->cells[3][10].value = 3;

    B->cells[4][1].colour = yellow;
    B->cells[4][1].value = 2;
    B->cells[4][2].colour = green;
    B->cells[4][2].value = 4;
    B->cells[4][3].colour = pink;
    B->cells[4][3].value = 0;
    B->cells[4][4].colour = green;
    B->cells[4][4].value = 1;
    B->cells[4][5].colour = red;
    B->cells[4][5].value = 1;
    B->cells[4][6].colour = blue;
    B->cells[4][6].value = 0;
    B->cells[4][7].colour = green;
    B->cells[4][7].value = 5;
    B->cells[4][8].colour = blue;
    B->cells[4][8].value = 4;
    B->cells[4][9].colour = yellow;
    B->cells[4][9].value = 2;
    B->cells[4][10].colour = green;
    B->cells[4][10].value = 3;

    B->cells[5][1].colour = blue;
    B->cells[5][1].value = 0;
    B->cells[5][2].colour = yellow;
    B->cells[5][2].value = 2;
    B->cells[5][3].colour = pink;
    B->cells[5][3].value = 0;
    B->cells[5][4].colour = blue;
    B->cells[5][4].value = 4;
    B->cells[5][5].colour = green;
    B->cells[5][5].value = 5;
    B->cells[5][6].colour = green;
    B->cells[5][6].value = 2;
    B->cells[5][7].colour = red;
    B->cells[5][7].value = 1;
    B->cells[5][8].colour = red;
    B->cells[5][8].value = 1;
    B->cells[5][9].colour = yellow;
    B->cells[5][9].value = 0;
    B->cells[5][10].colour = blue;
    B->cells[5][10].value = 4;

    B->cells[6][1].colour = blue;
    B->cells[6][1].value = 5;
    B->cells[6][2].colour = yellow;
    B->cells[6][2].value = 2;
    B->cells[6][3].colour = yellow;
    B->cells[6][3].value = 4;
    B->cells[6][4].colour = blue;
    B->cells[6][4].value = 3;
    B->cells[6][5].colour = red;
    B->cells[6][5].value = 4;
    B->cells[6][6].colour = pink;
    B->cells[6][6].value = 1;
    B->cells[6][7].colour = red;
    B->cells[6][7].value = 3;
    B->cells[6][8].colour = yellow;
    B->cells[6][8].value = 0;
    B->cells[6][9].colour = blue;
    B->cells[6][9].value = 4;
    B->cells[6][10].colour = green;
    B->cells[6][10].value = 1;

    B->cells[7][1].colour = blue;
    B->cells[7][1].value = 5;
    B->cells[7][2].colour = yellow;
    B->cells[7][2].value = 2;
    B->cells[7][3].colour = pink;
    B->cells[7][3].value = 4;
    B->cells[7][4].colour = pink;
    B->cells[7][4].value = 3;
    B->cells[7][5].colour = red;
    B->cells[7][5].value = 4;
    B->cells[7][6].colour = pink;
    B->cells[7][6].value = 1;
    B->cells[7][7].colour = green;
    B->cells[7][7].value = 3;
    B->cells[7][8].colour = green;
    B->cells[7][8].value = 0;
    B->cells[7][9].colour = red;
    B->cells[7][9].value = 4;
    B->cells[7][10].colour = yellow;
    B->cells[7][10].value = 1;

}

void outputBoard(boardType *B) {
    for (int rows = 1; rows <= B->r; rows++) {
        for (int cols = 1; cols <= B->c; cols++)
            printf("%s%i%c ",
                   COLOURS[B->cells[rows][cols].colour],
                   B->cells[rows][cols].value,
                   B->cells[rows][cols].status);
        printf("\n");
    }
}

void sumOfBoard(boardType *B, int *sum) {

    // Dont forget to do this
    *sum = 0;

    for (int rows = 1; rows <= B->r; rows++) {
        for (int cols = 1; cols <= B->c; cols++)
            *sum += B->cells[rows][cols].value;
    }

}

void sumOfColour(boardType *B, enum colourType chosenColour, int *sum) {

    *sum = 0;

    for (int rows = 1; rows <= B->r; rows++) {
        for (int cols = 1; cols <= B->c; cols++)
            if (B->cells[rows][cols].colour == chosenColour)
                *sum += B->cells[rows][cols].value;
    }
}

// function to swap elements
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void swap_c(char *a, char *b) {
    char t = *a;
    *a = *b;
    *b = t;
}

// function to find the partition position
int partition(int array[], char c_array[], int low, int high) {

    // select the rightmost element as pivot
    int pivot = array[high];

    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {

            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            swap(&array[i], &array[j]);
            swap_c(&c_array[i],&c_array[j]);
        }
    }

    // swap the pivot element with the greater element at i
    swap(&array[i + 1], &array[high]);
    swap_c(&c_array[i + 1], &c_array[high]);

    // return the partition point
    return (i + 1);
}

void quickSort(int array[], char c_array[], int low, int high) {
    if (low < high) {

        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pi = partition(array,c_array, low, high);

        // recursive call on the left of pivot
        quickSort(array, c_array, low, pi - 1);

        // recursive call on the right of pivot
        quickSort(array, c_array, pi + 1, high);
    }
}

void colourFrequency(boardType *Board, int *mostCommon) {

    // Initiate all colour structs
    int arr[MAX_VALUE] = {0,0,0,0,0};
    char c_arr[] = "rgbyp";
    // enum colourType {red, green, blue, yellow, pink};

    // Copy of print
    for (int rows = 1; rows <= Board->r; rows++) {
        for (int cols = 1; cols <= Board->c; cols++) {
            arr[Board->cells[rows][cols].colour]++;
        }
    }

    quickSort(arr, c_arr, 0, 5);


    char Preferred_Colour;

    // To handle ties
    if(arr[3] == arr[4])
        Preferred_Colour = c_arr[0];
    else
        Preferred_Colour = c_arr[4];



    switch (Preferred_Colour) {
        case 'r':
            *mostCommon = red;
            break;
        case 'g':
            *mostCommon = green;
            break;
        case 'b':
            *mostCommon = blue;
            break;
        case 'y':
            *mostCommon = yellow;
            break;
        case 'p':
            *mostCommon = pink;
            break;
        default:
            printf("Error finding most common colour\n");
            return;
    }

}


void deleteRow(boardType *B, const int row) {
    for (int rows = row; rows <= B->r - 1; rows++)
        for (int cols = 1; cols <= B->c; cols++)
            B->cells[rows][cols] = B->cells[rows + 1][cols];

    B->r--;
}

int main() {
    boardType board;
    int sum;

    hardCodeBoard(&board);
    outputBoard(&board);

    // call a function to determine the sum of the points (values) on the board
    // sum of all values
    sumOfBoard(&board, &sum);
    printf("Sum of board is %i\n", sum);

    // call a function that takes a colour and determines the sum of all the
    // cells of that colour ... don't bother getting the colour from the user
    // just hard-code the colour in the function call
    sumOfColour(&board, red, &sum);
    printf("Sum of the %s coloured cells is %i\n", COLOURS[red], sum);


    // write a function that determines the colour that occurs most frequently
    // on the board
    // if tie then lower colour is the most frequent
    int frequentColour;
    colourFrequency(&board,&frequentColour);
    printf("The most frequently occuring colour is %s\n",COLOURS[frequentColour]);


    // call a function that takes a row number and deletes that row
    // ... don't bother getting the row number just hard code it in
    // the function call ... be sure to output the board to verify the deletion
    // shift rows up
    // decrement r in struct
    deleteRow(&board, 1);
    outputBoard(&board);

}
