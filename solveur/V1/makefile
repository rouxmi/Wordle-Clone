##########################
##### COMPILER FLAGS #####
##########################
 
CC=/usr/bin/clang
CFLAGS=-std=c99 -Wall -Wextra -pedantic -fdiagnostics-color=always
CFLAGS+=$(CPPFLAGS) -O0 -g3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls
LDFLAGS+=-fsanitize=address
 
 
############################
##### FILES TO COMPILE #####
############################
 
# Program:

main_auto: main_auto.o whichWord.o dict.o tableau.o
 
main_auto.o: main_auto.c

whichWord.o: whichWord.h whichWord.c

tableau.o: tableau.h tableau.c

dict.o: dict.h dict.c

solv.o: solv.c

#test main_auto
test: test.o dict.o tableau.o

test.o: test.c

#UI

interface: interface.o dict.o tableau.o whichWord.o

interface.o: interface.c


# Format is:
## file_name.o: <dependency.o> <header_file.h> file_name.c
 
 
##########################
##### OTHER COMMANDS #####
##########################
 
clean: 
	rm -f *.o *_test
 
# For the test, replace `linked_list_int_test` with your program name.
	
.SILENT: clean