test: main.o graph.o test_graph.o entropie.o
	clang -std=c99 -Wall -Wextra -pedantic -g3 -fsanitize=address graph.o test_graph.o entropie.o main.o -o test

test_mot: test_mot.o mot.o
	clang -std=c99 -Wall -Wextra -pedantic -g3 -fsanitize=address mot.o test_mot.o -o test_mot

mot.o: includes/mot.h mot.c
	clang -std=c99 -Wall -Wextra -pedantic -g3 -fsanitize=address -c mot.c

test_mot.o : test_mot.c
	clang -std=c99 -Wall -Wextra -pedantic -g3 -fsanitize=address -c test_mot.c

graph.o : includes/graph.h graph.c
	clang -std=c99 -Wall -Wextra -pedantic -g3 -fsanitize=address -c graph.c

test_graph.o : includes/test_graph.h test_graph.c
	clang -std=c99 -Wall -Wextra -pedantic -g3 -fsanitize=address -c test_graph.c

entropie.o : includes/entropie.h entropie.c
	clang -std=c99 -Wall -Wextra -pedantic -g3 -fsanitize=address -c entropie.c

main.o : main.c
	clang -c -Wall -Wextra -pedantic -O0 -g3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls main.c

clean:
	@rm -d *.o
