CFLAGS=-g -O2 -I./Headers
LDFLAGS= -lm

Test_Table_Hashage: Test_Table_Hashage.o fonctions.o types.o liste.o
	gcc -o $@ $^  $(LDFLAGS)

%.o: Sources/%.c
	gcc -c $<  $(CFLAGS)
