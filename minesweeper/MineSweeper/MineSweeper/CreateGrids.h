#ifndef CREATE_GRIDS_H
#define CREATE_GRIDS_H
void create_grids(char sercet[Rows][Colms]) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Colms; j++) {
            sercet[i][j] = 'M';
        }
    }
}
#endif // !CREATE_GRIDS_H
