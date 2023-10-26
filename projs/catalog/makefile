CC=g++
EXE_FILE=catalog

all: $(EXE_FILE)

$(EXE_FILE): catalog.o catalog.h run_catalog.cpp
	$(CC) catalog.o run_catalog.cpp -o $(EXE_FILE)

catalog.o: catalog.h catalog.cpp
	$(CC) -c catalog.cpp

clean:
	rm -f *.o $(EXE_FILE)
