CFLAGS=-g -O2 
LDFLAGS= -lm

Test_Table_Hashage: Test_Table_Hashage.o fonctions.o graphe.o liste_succ.o sommet.o succ.o
	gcc -o $@ $^  $(LDFLAGS)


%.o: %.c
	gcc -c $(CFLAGS) $< 
