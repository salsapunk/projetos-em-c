#define MAX_VALUE 80

typedef struct player {
	char name[MAX_VALUE];
	char charactere;
	bool win;
} Player;

void clearInputBuffer();
void initPlayer(Player* player);
void initPlayer2(Player* player, int pCharactere);
void cleaningNewLine(Player* p);
int getCharactere();
bool checkPC(Player* p);
void initPC(Player* pc, int pCharactere);
int getSpacePC();
