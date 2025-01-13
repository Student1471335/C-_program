#ifndef RANDOM_MINES_H
#define RANDOM_MINES_H

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
#endif RANDOM_MINES_H