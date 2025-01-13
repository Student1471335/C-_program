#ifndef REVEAL_H
#define REVEAL_H
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
#endif REVEAL_H
