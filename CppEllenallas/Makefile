# Pelda Makefile a Cpp Ellenallas megoldasanak forditasara 
# Solaris (ural2) es Linux ala.

objs = resistor.o resistor_test.o   # forditando obj. fajlok
heads = resistor.h		            # headerek, amitol minden fugg
prog = resistor			            # a program neve

CXX = g++                           # a C++ fordito neve
#CXX = clang++                      # clang-ot (llvm) is erdemes kiprobalni
CXXFLAGS = -pedantic -Wall          # C++ kapcsolok: legyen bobeszedu, 
CXXFLAGS += -g                      # ... es forduljon debug info is

# alapertelmezett cel: tesztprogram linkelese
all: $(prog)

$(prog): $(objs)
	$(CXX) $(objs) -o $@

$(objs): $(heads)

# takaritas igeny szerint
clean:
	rm -f $(objs) resistor *~
