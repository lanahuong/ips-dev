CC = g++ -std=c++11
LD = $(CC)
CFLAGS = -Wall -Wextra
LDFLAGS = $(CFLAGS) -larmadillo
BINDIR = bin/
OBJDIR = obj/
SRCDIR = src/
DOCDIR = doc/
TESTDIR = test/
TARGET = $(BINDIR)solver
OBJS = $(OBJDIR)main.o $(OBJDIR)hermite.o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

$(OBJDIR)%.o : $(SRCDIR)%.cpp $(SRCDIR)%.h
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY : doc
doc :
	doxygen $(DOCDIR)Doxyfile

.PHONY : clean
clean :
	rm -rf $(OBJS)
	rm -rf $(TARGET)
