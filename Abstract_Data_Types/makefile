#	Source, Executable, Include, Library Defines
INCL	:=	new.h	Object.h	Set.h
SRC		:=	new.c	Object.c	Set.c	main.c
OBJ		=	$(SRC:.c=.o)
LIBS	=	-lgen
EXE		=	main



#	Compiler, Linker Defines
CC		=	gcc
CFLAGS	=	-std=gnu99 -Wall -O0
LIBPATH	=	-L.
LDFLAGS	=	-o $(EXE) $(LIBPATH) $(LIBS)
CFDEBUG	=	-ansi -pedantic -Wall -g -DDEBUG $(LDFLAGS)



#	Compile and Assemble C Source files into Object Files
%.o : %.c
	$(CC) -c $(CFLAGS) $*.c



#	Link all Object Files with external Libraries into Binaries
$(EXE) : $(OBJ)
		$(CC) $(LDFLAGS) $(OBJ)



#	Objects depend on these libraries
$(OBJ) : $(INCL)



#	Create a gdb/dbx Capable Executable with DEBUG flags turned on
debug:
		$(CC) $(CFDEBUG) $(SRC)



#	Clean up Objects, Executables, Dumps out of source directory
clean:
		$(RM) $(OBJ) $(EXE) core a.out