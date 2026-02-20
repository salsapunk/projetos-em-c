void clearInputBuffer();
char** initMatrix();
bool checkSpace(char** matrix, int y, int x);
void chooseSpace(char** matrix, Player* p);
char checkWinner(char** matrix);
void getWinner(char charactere, Player* jogador, Player* pc);
