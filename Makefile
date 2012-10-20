CC=`which gcc`
LD=`which gcc`
RM=`which rm` -f
DOXYGEN=`which doxygen`
TAR=`which tar` --exclude=.svn -czvf 

INCDIR=-I include

CFLAGS=-Wall -g -pedantic $(INCDIR)
LFLAGS=

OBJ=  auto_nombre.o  liste_chainee.o collection.o action.o dictionnaire.o




GARBAGE=*~ include/*~

ARCHNAME=`date +%d-%m-%y-%H-%M`-`whoami`.tgz
ARCHCONTENT=*.c *file include res doc *.txt

TARGET=analyse


all : $(TARGET)


$(TARGET) : $(OBJ)
	$(LD) $(LFLAGS) $^ -o $@

.c.o : 
	$(CC) $(CFLAGS) $< -c 

clean : 
	$(RM) $(OBJ) $(GARBAGE) $(TARGET)

documentation : 
	$(DOXYGEN)

archive : 
	$(TAR) ../$(ARCHNAME) $(ARCHCONTENT) && mv ../$(ARCHNAME) .

test_file :
	gcc -std=c99 -Wall -Wextra -o test_file  liste_chainee.c test_file.c
	./test_file
	
test_classifie :
	gcc -std=c99 -Wall -Wextra -o test_classifie auto_nombre.c test_classifie.c
	./test_classifie
	 
test_coupe_ligne :
	gcc -std=c99 -Wall -Wextra -o test_coupe_ligne auto_nombre.c test_coupe_ligne.c
	./test_coupe_ligne

test_canoniser :
	gcc -std=c99 -Wall -Wextra -o test_canoniser auto_nombre.c test_canoniser.c
	./test_canoniser
	 
	 
