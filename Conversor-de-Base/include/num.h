#define TABLE_SIZE 16

typedef struct {
    long int content;
    int length;
} Number;

typedef struct Entry {
    int key;
    int value;
    struct Entry *next;
} Entry;

typedef struct {
    Entry *buckets[TABLE_SIZE];
} Map;

// octal 	binario
// 0 		000
// 1 		001
// 2 		010
// 3 		011
// 4 		100
// 5 		101
// 6 		110
// 7 		111

// hexadecimal 	
