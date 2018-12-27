#include "fixed_consumer.h"

int main() {
    FILE *item_source = fopen(FIXED_STORAGE, "r");
    enum Error err;
    if (!item_source) {
        fprintf(stderr, "Failed to read random float array.\n");
        err = FILE_CANT_OPEN;
        return err;
    }

    unsigned int item [STORAGE_SIZE];

    for (size_t i = 0; i < STORAGE_SIZE; i++) {
        unsigned int temp_storage;
        fscanf(item_source, "%u\n", &temp_storage);
        item[i] = temp_storage;
    }

    fclose(item_source);

    struct timespec start_time, end_time;
    size_t time_elipse = 0;
    for (size_t i = 0; i < STORAGE_SIZE; i += 4){
        clock_gettime(CLOCK_MONOTONIC, &start_time);
        item[i + 0] *= ITEM_OPERATION;
        item[i + 1] *= ITEM_OPERATION;
        item[i + 2] *= ITEM_OPERATION;
        item[i + 3] *= ITEM_OPERATION;
        clock_gettime(CLOCK_MONOTONIC, &end_time);
        time_elipse = (size_t) (end_time.tv_nsec - start_time.tv_nsec);
        printf("%lu\n", time_elipse / 4);
    }

    return 0;

}