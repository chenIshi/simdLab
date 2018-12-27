#include "data_producer.h"

int produce_item(size_t item_size, enum TYPE ItemType,
                 unsigned *float_item, unsigned *fixed_item) {
    /* set output memory space */
    enum Error err = EXEC_SUCCESS;

    srand(time(NULL));
    for (unsigned long i = 0; i < item_size; i++) {
        /* get a random number to generate corresponding normalized/ denormalize float */
        unsigned int seed = RAND_RANGE_MIN + rand() % RAND_RANGE_MAX;
        unsigned de2nor_seed = DE2NOR_RANGE_MIN + rand() % DE2NOR_RANGE_MAX;
        float result;
        switch (ItemType) {
            case SPECIAL:
                break;
            case NORMALIZE:
                result = seed * NORMAL_LOWER_BIT;
                float_item[i] = *(unsigned *)&result;
                fixed_item[i] = seed;
                break;
            case DENORMALIZE:
                float_item[i] = seed;
                fixed_item[i] = seed;
                break;
            case DE2NOR:
                float_item[i] = de2nor_seed;
                fixed_item[i] = de2nor_seed;
            default:
                break;
        }
    }
    return err;
}

int main() {
    enum Error err = EXEC_SUCCESS;
    size_t item_size = STORAGE_SIZE;
    size_t item_type = ITEM_TYPE;

    unsigned *float_item;
    float_item = (unsigned *)malloc(item_size * sizeof(unsigned int));
    if (float_item == NULL) {
        err = MEM_NOT_ALLOC;
        fprintf(stderr, "Failed to malloc float test case.\n");
        return err;
    }

    unsigned *fixed_item;
    fixed_item = (unsigned *)malloc(item_size * sizeof(unsigned int));
    if (fixed_item == NULL) {
        err = MEM_NOT_ALLOC;
        free(float_item);
        fprintf(stderr, "Failed to malloc fixed test case.\n");
        return err;
    }

    err = produce_item(item_size, item_type, float_item, fixed_item);

    FILE *float_item_storage = fopen(FLOAT_STORAGE, "w");
    if (!float_item_storage) {
        fprintf(stderr,"Failed to write float output file.\n");
        err = FILE_CANT_OPEN;
        return err;
    }

    for (size_t i = 0; i < item_size; i ++) {
        fprintf(float_item_storage, "%u\n", float_item[i]);
    }

    fclose(float_item_storage);

    FILE *fixed_item_storage = fopen(FIXED_STORAGE, "w");
    if (!fixed_item_storage) {
        fprintf(stderr,"Failed to write float output file.\n");
        err = FILE_CANT_OPEN;
        return err;
    }

    for (size_t i = 0; i < item_size; i ++) {
        fprintf(fixed_item_storage, "%u\n", fixed_item[i]);
    }
    
    fclose(fixed_item_storage);

    return err;
}