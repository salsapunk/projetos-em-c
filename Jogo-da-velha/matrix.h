void clearInputBuffer();
char** initMatrix();
bool checkSpace(char** matrix, int y, int x);
void printMessage(Player* p, char message[]);
void chooseSpace(char** matrix, Player* p);
char checkWinner(char** matrix);
bool getWinner(char charactere, Player* p);
