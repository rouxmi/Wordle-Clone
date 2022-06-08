mot.o: includes/mot.h mot.c
	clang -std=c99 -Wall -Wextra -pedantic -g3 -fsanitize=address -c mot.c

graph.o : includes/graph.h graph.c
	clang -std=c99 -Wall -Wextra -pedantic -g3 -fsanitize=address -c graph.c

entropie.o : includes/entropie.h entropie.c
	clang -std=c99 -Wall -Wextra -pedantic -g3 -fsanitize=address -c entropie.c

interface: interface.o entropie.o graph.o mot.o
	clang -std=c99 -Wall -Wextra -pedantic -g3 -fsanitize=address entropie.o interface.o mot.o graph.o -o interface
	
interface.o:	
	clang -std=c99 -c -Wall -Wextra -pedantic -g3 -fsanitize=address -c interface.c

main_auto: entropie.o main_auto.o mot.o graph.o
	clang -std=c99 -c -Wall -Wextra -pedantic -g3 -fsanitize=address entropie.o main_auto.o mot.o graph.o -o main_auto

main_auto.o:
	clang -std=c99 -c -Wall -Wextra -pedantic -g3 -fsanitize=address -c main_auto.c

clean:
	@rm -d *.o
