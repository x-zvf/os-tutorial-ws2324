CC=     gcc
LD=     ld
CFLAGS= -g -W -Wall -Werror -std=c99 -fopenmp
LDFLAGS= -fopenmp
TARGET= concurrent
SRC=    concurrent.c

all: $(TARGET) $(addprefix $(TARGET),-O1 -O2)

$(TARGET): $(SRC)
	$(CC) $(LDFLAGS) -o $@ $(SRC)

$(TARGET)-O1: $(SRC)
	$(CC) -O1 $(LDFLAGS) -o $@ $(SRC)
$(TARGET)-O2: $(SRC)
	$(CC) -O2 $(LDFLAGS) -o $@ $(SRC)

clean:
	rm -rf $(TARGET) $(TARGET)-O1 $(TARGET)-O2

.PHONY: all clean
