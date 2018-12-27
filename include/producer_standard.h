#define FLOAT_STORAGE "random_float_array.txt"
#define FIXED_STORAGE "random_fixed_array.txt"

#define STORAGE_SIZE 100000
#define ITEM_TYPE 3

#define ITEM_OPERATION 5

enum Error {
    EXEC_SUCCESS = 0,
    FILE_CANT_OPEN,
    MEM_NOT_ALLOC,
    INSUFFICIENT_ARGC,
    WRONG_ARR_SIZE,
    WRONG_FLOAT_MODE
};

enum TYPE {
    SPECIAL = 0,
    NORMALIZE,
    DENORMALIZE,
    DE2NOR
};