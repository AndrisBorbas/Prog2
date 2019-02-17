#
# Makefile pelda a string1 feladat (2. labor) megoldasanak forditasara 
# gnumake valtozat
# 	Linuxokon es ural2-n is elerheto
#
# A make paranccsorabol magadott CMD valtozo tartalma atadodik a forditonak
# Pl:
# make CMD=-DMEMTRACE
#
PROG = string2_cpp   # a program neve (ezt allitjuk elo)
PROG_O = string2.o string2_main.o  # program object fajljai 
PROG_H = string2.h    # program header fajljai
PROG_L =              # program libjei

MTRACE_O = memtrace.o # memtrace object fajl
MTRACE_H = memtrace.h # memtrace header fajlja

CXX = g++   # a C fordito neve
#CXX = clang++ # clang-ot (llvm) is erdemes kiprobalni
CXXFLAGS = -pedantic -Wall # kapcsolok: legyen bobeszedu es pedans
CXXFLAGS += -g # es legyeb debug info is
CXXFLAGS += $(CMD) # es amit a parancsorbol megadnak
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

