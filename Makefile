CONFIG_FILE=config_log
CC=gcc
INCLUDE_PATH=./include
SRC_PATH=src
DATA_FACTORY=data_producer
EXEC=$(DATA_FACTORY) $(STANDARD_SAMPLE_EXEC)
STANDARD_SAMPLE_EXEC=float_consumer fixed_consumer
STD_EXEC_SRC=$(foreach STD_SAMPLE, $(STANDARD_SAMPLE_EXEC), $(SRC_PATH)/$(STD_SAMPLE).c)

ALL : $(EXEC)
# check if not configured yet
ifeq (,$(wildcard $(CONFIG_FILE)))
	@echo "Failed to Makefile: No configured yet."
else
	@echo "Makefile success."
endif

# float_consumer : src/float_consumer.c
#	$(CC) $< -o $@ -I $(INCLUDE_PATH)

# fixed_consumer : src/fixed_consumer.c
#	$(CC) $< -o $@ -I $(INCLUDE_PATH)

.SUFFIXES:

$(STANDARD_SAMPLE_EXEC) : $(STD_EXEC_SRC)
	$(CC) $< -o $@ -I $(INCLUDE_PATH)

$(DATA_FACTORY) : $(SRC_PATH)/$(DATA_FACTORY).c
	$(CC) $< -o $@ -I $(INCLUDE_PATH)


# to-do : add "clean" target