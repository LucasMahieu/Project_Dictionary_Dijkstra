CFLAGS=-g -I./Headers
LDFLAGS= -lm

Test_Table_Hashage: Test_Table_Hashage.o fonctions.o liste.o graphe.o
	gcc -o $@ $^  $(LDFLAGS)

%.o: Sources/%.c
	gcc -c $<  $(CFLAGS)

