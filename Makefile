#Modules to consider in the build. foo.cpp will be foo.
MODULES = hermite
MAIN = main
TEST_MODULES = test1

#Compiler config for the main target
CC = g++ -std=c++11
LD = $(CC)
CFLAGS = -Wall -Wextra
LDFLAGS = $(CFLAGS) -larmadillo

#Folders config
BINDIR = bin
OBJDIR = obj
SRCDIR = src
DOCDIR = doc
TEST_SRCDIR = tests

#Names of the targets
TARGET = $(BINDIR)/solver
TEST_TARGET = $(BINDIR)/tests

all : makedirs $(TARGET)

makedirs :
	mkdir -p tmp
	mkdir -p bin
	mkdir -p obj

#Build of the target
MAIN_SRC = $(addprefix $(SRCDIR)/, $(MAIN:=.cpp))
MAIN_OBJ = $(addprefix $(OBJDIR)/, $(MAIN:=.o))
SOURCES = $(addprefix $(SRCDIR)/, $(MODULES:=.cpp))
OBJECTS = $(addprefix $(OBJDIR)/, $(MODULES:=.o))
ALL_OBJECTS = $(OBJECTS) $(MAIN_OBJ)
ALL_SOURCES = $(SOURCES) $(MAIN_SRC)

$(TARGET) : $(ALL_OBJECTS) $(ALL_SOURCES)
	$(LD) $(LDFLAGS) -o $@ $(ALL_OBJECTS)

$(MAIN_OBJ): obj/%.o : src/%.cpp $(MAIN_SRC)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJECTS): obj/%.o : src/%.cpp $(SOURCES)
	$(CC) $(CFLAGS) -c -o $@ $<


#Doxygen
.PHONY : doc
doc :
	doxygen $(DOCDIR)Doxyfile


FUSED_GTEST_H = $(FUSED_GTEST_DIR)/gtest/gtest.h
FUSED_GTEST_ALL_CC = $(FUSED_GTEST_DIR)/gtest/gtest-all.cc
GTEST_MAIN_CC = $(GTEST_SRC)/googletest/src/gtest_main.cc
CPPFLAGS += -I$(FUSED_GTEST_DIR) -DGTEST_HAS_PTHREAD=0
CXXFLAGS += -g

TEST_SOURCES = $(addprefix $(TEST_SRCDIR)/, $(TEST_MODULES:=.cpp))
TEST_OBJECTS = $(addprefix $(OBJDIR)/, $(TEST_MODULES:=.o))


FUSED_GTEST_DIR = tmp
GTEST_SRC = gtest

.PHONY : tests
tests : $(TEST_TARGET)

check : $(TEST_TARGET)
	$(TEST_TARGET)

$(FUSED_GTEST_H) :
	$(GTEST_SRC)/googletest/scripts/fuse_gtest_files.py $(FUSED_GTEST_DIR)

$(FUSED_GTEST_ALL_CC) :
	$(GTEST_SRC)/googletest/scripts/fuse_gtest_files.py $(FUSED_GTEST_DIR)

$(OBJDIR)/gtest-all.o : $(FUSED_GTEST_H) $(FUSED_GTEST_ALL_CC)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(FUSED_GTEST_DIR)/gtest/gtest-all.cc -o $(OBJDIR)/gtest-all.o

$(TEST_OBJECTS): $(OBJDIR)%.o : $(TEST_SRCDIR)%.cpp $(TEST_SOURCES)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(GTEST_SRC)/googletest/include

$(OBJDIR)/gtest_main.o : $(FUSED_GTEST_H) $(GTEST_MAIN_CC)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(GTEST_MAIN_CC) -o $(OBJDIR)/gtest_main.o

$(TEST_TARGET) : $(OBJECTS) $(OBJDIR)/gtest-all.o $(OBJDIR)/gtest_main.o $(TEST_OBJECTS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $(TEST_TARGET)


.PHONY : clean
clean :
	rm -rf $(ALL_OBJECTS) $(TEST_OBJECTS) $(OBJDIR)/gtest_main.o $(OBJDIR)/gtest-all.o
	rm -rf $(TARGET) $(TEST_TARGET)
	rm -rf $(FUSED_GTEST_DIR)

