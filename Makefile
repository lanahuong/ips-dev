MODULES = hermite
MAIN = main
TEST_MODULES = test1


CC = g++ -std=c++11
LD = $(CC)
CFLAGS = -Wall -Wextra
LDFLAGS = $(CFLAGS) -larmadillo


BINDIR = bin/
OBJDIR = obj/
SRCDIR = src/
DOCDIR = doc/




TARGET = $(BINDIR)solver
MAIN_SRC = $(addprefix $(SRCDIR), $(MAIN:=.cpp))
MAIN_OBJ = $(addprefix $(OBJDIR), $(MAIN:=.o))
SOURCES = $(addprefix $(SRCDIR), $(MODULES:=.cpp))
OBJECTS = $(addprefix $(OBJDIR), $(MODULES:=.o))
ALL_OBJECTS = $(OBJECTS) $(MAIN_OBJ)
ALL_SOURCES = $(SOURCES) $(MAIN_SRC)

all : $(TARGET)

$(TARGET) : $(ALL_OBJECTS) $(ALL_SOURCES)
	$(LD) $(LDFLAGS) -o $@ $(ALL_OBJECTS)

$(MAIN_OBJ): obj/%.o : src/%.cpp $(MAIN_SRC)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJECTS): obj/%.o : src/%.cpp $(SOURCES)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY : doc
doc :
	doxygen $(DOCDIR)Doxyfile

FUSED_GTEST_H = $(FUSED_GTEST_DIR)/gtest/gtest.h
FUSED_GTEST_ALL_CC = $(FUSED_GTEST_DIR)/gtest/gtest-all.cc
GTEST_MAIN_CC = $(GTEST_SRC)/googletest/src/gtest_main.cc
CPPFLAGS += -I$(FUSED_GTEST_DIR) -DGTEST_HAS_PTHREAD=0
CXXFLAGS += -g

TEST_SRCDIR = tests/
TEST_TARGET = $(BINDIR)tests
TEST_SOURCES = $(addprefix $(TEST_SRCDIR), $(TEST_MODULES:=.cpp))
TEST_OBJECTS = $(addprefix $(OBJDIR), $(TEST_MODULES:=.o))
ALL_TEST_OBJECTS = TE
GTEST_ALL_OBJ =


FUSED_GTEST_DIR = output
GTEST_SRC = gtest

.PHONY : tests
tests : $(TEST_TARGET)

check : $(TEST_TARGET)
	$(TEST_TARGET)

$(FUSED_GTEST_H) :
	$(GTEST_SRC)/googletest/scripts/fuse_gtest_files.py $(FUSED_GTEST_DIR)

$(FUSED_GTEST_ALL_CC) :
	$(GTEST_SRC)/googletest/scripts/fuse_gtest_files.py $(FUSED_GTEST_DIR)

obj/gtest-all.o : $(FUSED_GTEST_H) $(FUSED_GTEST_ALL_CC)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(FUSED_GTEST_DIR)/gtest/gtest-all.cc -o obj/gtest-all.o

$(TEST_OBJECTS): $(OBJDIR)%.o : $(TEST_SRCDIR)%.cpp $(TEST_SOURCES)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(GTEST_SRC)/googletest/include

obj/gtest_main.o : $(FUSED_GTEST_H) $(GTEST_MAIN_CC)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(GTEST_MAIN_CC) -o $(OBJDIR)gtest_main.o

$(TEST_TARGET) : $(OBJECTS) $(OBJDIR)gtest-all.o $(OBJDIR)gtest_main.o $(TEST_OBJECTS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $(TEST_TARGET)


.PHONY : clean
clean :
	rm -rf $(ALL_OBJECTS) $(TEST_OBJECTS)
	rm -rf $(TARGET) $(TEST_TARGET)
	rm -rf $(FUSED_GTEST_DIR)

