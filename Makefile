CC = g++ -std=c++11
CFLAGS = -Wall -Wextra
LDFLAGS =
BINDIR = bin/
OBJDIR = obj/
SRCDIR = src/
DOCDIR = doc/
TESTDIR = test/
TARGET = $(BINDIR)solver
OBJS = $(OBJDIR)main.o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^

$(OBJDIR)%.o : $(SRCDIR)%.cpp $(SRCDIR)%.h
	$(CC) -c -o $@ $<

.PHONY : doc
doc :
	doxygen $(DOCDIR)Doxyfile

.PHONY : clean
clean :
	rm -rf $(OBJS)
	rm -rf $(TARGET)
