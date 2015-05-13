CFLAGS=-g -I./Headers
LDFLAGS= -lm

Test_Liste_Successeur: Test_Liste_Successeur.o fonctions.o liste.o graphe.o
	gcc -o $@ $^  $(LDFLAGS)

%.o: Sources/%.c
	gcc -c $<  $(CFLAGS)

