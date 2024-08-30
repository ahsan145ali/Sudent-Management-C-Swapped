CC=gcc
BINS=runDB
BIN_PATH=src/$(BINS)
CFLAGS=-Iheaders
SRC=src/runDB.c src/students.c src/Utils.c src/DisplayMenus.c src/teachers.c src/subjects.c src/enrollments.c

all: $(BIN_PATH)

$(BIN_PATH): $(SRC)
	$(CC) $(CFLAGS) -o $(BIN_PATH) $(SRC)

clean:
	rm -f $(BIN_PATH)
