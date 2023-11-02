CC = g++  # The C++ compiler
EXE_FILE = coffee

all: $(EXE_FILE)

$(EXE_FILE): prog.o display.o shop.o menu.o order.o coffee.o
	$(CC) prog.o display.o shop.o menu.o order.o coffee.o -o $(EXE_FILE)

prog.o: display.h
	$(CC) -c prog.cpp

display.o: display.h shop.h
	$(CC) -c display.cpp

shop.o: shop.h menu.h order.h
	$(CC) -c shop.cpp

menu.o: menu.h coffee.h
	$(CC) -c menu.cpp

order.o: order.h
	$(CC) -c order.cpp

coffee.o: coffee.h
	$(CC) -c coffee.cpp

clean:
	rm -f *.o
