#ifndef CHOOSE_H
#define CHOOSE_H

void choose() {
    int horizontal, vertical;

    do {
        std::cout << std::endl;
        std::cin >> horizontal;
        std::cin >> vertical;
        horizontal--;
        vertical--;

    }

    while (horizontal < 0 || horizontal > Rows || vertical < 0 || vertical > Colms)
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
#endif choose.h // !choose.h

