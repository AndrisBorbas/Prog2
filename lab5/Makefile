#
# Makefile pelda a string1 feladat (3. labor) megoldasanak forditasara 
# gnumake valtozat
# 	Linuxokon es ural2-n is elerheto
#
PROG = string5_test   # a program neve (ezt allitjuk elo)
PROG_O = string5.o rendez.o string5_test.o  # program object fajljai 
PROG_H = string5.h    # program header fajljai
PROG_L =              # program libjei

MTRACE_O = memtrace.o # memtrace object fajl
MTRACE_H = memtrace.h # memtrace es memcheck header fajlja

CXX = g++   # a C fordito neve
#CXX = clang++ # clang-ot (llvm) is erdemes kiprobalni
CXXFLAGS = -pedantic -Wall -Werror # kapcsolok: legyen bobeszedu es pedans
CXXFLAGS += -g -DMEMTRACE # es legyeb debug info is
LDFLAGS = -g # debug a linkelesnel 

# osszes object, osszes header osszes lib
OBJS = $(PROG_O) $(MTRACE_O)
HEADS = $(PROG_H) $(MTRACE_H)
LIBS = $(PROG_L) 

# alapertelmezett cel: program
.PHONY: all
all: $(PROG)

$(PROG): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@ $(LIBS)

# feltetelezzuk, hogy az osszes obj fugg az osszes headertol
$(OBJS): $(HEADS)

# takaritas igeny szerint
.PHONY: clean
clean:
	rm -f $(OBJS) $(PROG)

