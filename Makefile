CC=`which gcc`
LD=`which gcc`
RM=`which rm` -f
DOXYGEN=`which doxygen`
TAR=`which tar` --exclude=.svn -czvf 

INCDIR=-I include

CFLAGS=-Wall -ansi -g -pedantic-errors $(INCDIR)
LFLAGS=

OBJ= test_auto_nombre.o auto_nombre.o etape1.o

GARBAGE=*~ include/*~

ARCHNAME=`date +%d-%m-%y-%H-%M`-`whoami`.tgz
ARCHCONTENT=*.c *file include res doc *.txt

TARGET=test_auto_nombre

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
