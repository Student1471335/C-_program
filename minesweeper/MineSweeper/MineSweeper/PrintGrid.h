#ifndef PRINT_GRID_H
#define PRINT_GRID_H
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
#endif // !PRINT_GRID_H

