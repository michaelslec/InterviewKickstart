typedef struct AlgorithmTest {
    int array_size;
    int array_item_max;
    int rounds;
    void (*algorithm)(int*, int);
} AlgorithmTest;

AlgorithmTest createTest(int, int, int, void (*algorithm)(int*, int));

void printIntArray(int*, int);
void randomizeArray(int*, int, int);
double timeSortAlgorithm(AlgorithmTest, int);
double rampingNSortTest(AlgorithmTest, int);
