#define MAX_VALUE 80

typedef struct player {
	char name[MAX_VALUE];
	char charactere;
	bool win;
} Player;

void initPlayer(Player* player);
int getCharactere();
void initPC(Player* pc, int pCharactere);
