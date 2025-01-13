// main.cp;
// p : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

// Global Variables //
const int Rows = 9;
const int Colms = 9;
bool game_over = false;
char field[Rows][Colms];
char secret[Rows][Colms];

// functions voids //
void rules();
void random_mines();
void create_grids(char serect[Rows][Colms]);
void create_grid(char field[Rows][Colms]);
void print_grid(char field[Rows][Colms]);
void choose();
void reveal(int, int);


int main()
{
    rules();

    create_grid(field);

    do
    {
        std::cout << std::endl;
        create_grids(secret);
        random_mines();
        print_grid(field);
        choose();
    } while (game_over != true);

    return 0;
}
// first thing the player sees 
void rules() {
    std::cout << "Welcome to the minefields\n To begin clearing enter X value to pick a row and Y value to column to start clearing the field ";
}
// making the grid 
void create_grid(char field[Rows][Colms]) {
    std::cout << "Generating your grid..\n";
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Colms; j++) {
            field[i][j] = '+';
        }
    }
}
void create_grids(char sercet[Rows][Colms]) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Colms; j++) {
            sercet[i][j] = 'M';
        }
    }
}
void print_grid(char field[Rows][Colms]) {
    for (int a = 0; a < Rows; a++) {
        std::cout << a << " ";
    }
    std::cout << Rows;
    std::cout << Colms;
    std::cout << std::endl;

    for (int i = 0; i < Rows; i++)
    {
        std::cout << i + 1 << " ";

        for (int j = 0; j < Colms; j++) {
            std::cout << field[i][j] << " ";

        }
        std::cout << std::endl;
    }
}

void choose() {
    int horizontal, vertical;

    do {
        std::cout << std::endl;
        std::cin >> horizontal;
        std::cin >> vertical;
        horizontal -- ;
        vertical -- ;
        
    }

    while (horizontal < 0 || horizontal > Rows || vertical < 0 || vertical > Colms);
    std::cout << "hor" << secret[horizontal][vertical];
    if (secret[horizontal][vertical] == 'M') {
        game_over = true;

        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < Colms; j++)
                if (secret[i][j] == 'M') {
                    field[i][j] = 'M';
                }
        }
    }
    else {
        reveal(horizontal, vertical);
    }
}

void random_mines() {
    std::srand(time(NULL));

    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Colms; j++) {
            secret[i][j] = 'S';
        }
    }

    for (int a = 0; a < 10; a++) {
        int b = rand() % Rows;
        int c = rand() % Colms;

        if (secret[b][c] == 'M') {
            a--;
            continue;
        }
        secret[b][c] = 'M';
        std::cout << 'M' << std::endl;
    }
}

void reveal(int x, int y) {
    // stop out of bounds access
    if (x < 0 || x >= Rows || y < 0 || y >= Colms) {
        return;
    }

    // check if cell is already revealed
    if (field[x][y] != '+') {
        return;
    }

    // adjacent mines count
    int mine_count = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int nx = x + dx;
            int ny = y + dy;

            // checking bounds for neighboring cells
            if (nx >= 0 && nx < Rows && ny >= 0 && ny < Colms) {
                if (secret[nx][ny] == 'M') {
                    mine_count++;
                }
            }
        }
    }

    // updating the field on the number of adjacent mines
    if (mine_count > 0) {
        field[x][y] = '0' + mine_count; // convert int to char
    }
    else {
        field[x][y] = ' '; // emty marks so no mines being adjacent

        // reveal cells next the blanks ones
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx != 0 || dy != 0) {
                    //pass over current cell
                    reveal(x + dx, y + dy);
                }
            }
        }
    }
}