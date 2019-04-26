# Pelda Makefile a generikus tomb feladat megoldasanak forditasara 
# Solaris (ural2) es Linux ala.

# forditando obj. fajlok
objs = generikus2_teszt.o

# headerek, melyektol az egyszeruseg kedveert minden fugg
heads = fancy_iterators.hpp sablonok.hpp gtest_lite.h

prog = generikus2_teszt             # a program neve

CXX = g++                           # a C++ fordito neve
CXXFLAGS = -pedantic -Wall -std=c++11 # C++ kapcsolok: legyen bobeszedu, 
CXXFLAGS += -g                      # ... es forduljon debug info is

# alapertelmezett cel: tesztprogram linkelese
all: $(prog)

$(prog): $(objs) $(objs2)
	$(CXX) $(objs) $(objs2) -o $@

$(objs): $(heads)

# takaritas igeny szerint
clean:
	rm -f $(objs) $(prog)
