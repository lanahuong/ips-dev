CC = g++ -std=c++11
LD = $(CC)
CFLAGS = -Wall -Wextra
LDFLAGS = $(CFLAGS) -larmadillo
BINDIR = bin/
OBJDIR = obj/
SRCDIR = src/
DOCDIR = doc/
TESTDIR = tests/
TARGET = $(BINDIR)solver
OBJS = $(OBJDIR)main.o $(OBJDIR)hermite.o
FUSED_GTEST_DIR = output
GTEST = gtest



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
	rm -rf $(FUSED_GTEST_DIR)



.PHONY : tests
tests : bin/main_tests



# A Makefile for fusing Google Test and building a sample test against it.
#
# SYNOPSIS:
#
#   make [all]  - makes everything.
#   make TARGET - makes the given target.
#   make check  - makes everything and runs the built sample test.
#   make clean  - removes all files genera	ted by make.

# Points to the root of fused Google Test, relative to where this file is.


# Paths to the fused gtest files.
FUSED_GTEST_H = $(FUSED_GTEST_DIR)/gtest/gtest.h
FUSED_GTEST_ALL_CC = $(FUSED_GTEST_DIR)/gtest/gtest-all.cc

# Where to find the sample test.


# Where to find gtest_main.cc.
GTEST_MAIN_CC = $(GTEST)/googletest/src/gtest_main.cc

# Flags passed to the preprocessor.
# We have no idea here whether pthreads is available in the system, so
# disable its use.
CPPFLAGS += -I$(FUSED_GTEST_DIR) -DGTEST_HAS_PTHREAD=0


# Flags passed to the C++ compiler.
CXXFLAGS += -g


check : all
	./sample1_unittest

$(FUSED_GTEST_H) :
	$(GTEST)/googletest/scripts/fuse_gtest_files.py $(FUSED_GTEST_DIR)

$(FUSED_GTEST_ALL_CC) :
	$(GTEST)/googletest/scripts/fuse_gtest_files.py $(FUSED_GTEST_DIR)

gtest-all.o : $(FUSED_GTEST_H) $(FUSED_GTEST_ALL_CC)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(FUSED_GTEST_DIR)/gtest/gtest-all.cc

gtest_main.o : $(FUSED_GTEST_H) $(GTEST_MAIN_CC)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(GTEST_MAIN_CC)

obj/sample1.o : $(TESTDIR)/sample1.cc $(TESTDIR)/sample1.h
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TESTDIR)/sample1.cc -o obj/sample1.o

obj/sample1_unittest.o : $(TESTDIR)/sample1_unittest.cc \
                     $(TESTDIR)/sample1.h $(FUSED_GTEST_H)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(TESTDIR)/sample1_unittest.cc -o obj/sample1_unittest.o

bin/main_tests : obj/sample1.o obj/sample1_unittest.o gtest-all.o gtest_main.o
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@
