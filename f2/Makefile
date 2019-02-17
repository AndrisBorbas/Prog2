## Makefile a Nem_OO feladat forditasahoz
# gnumake valtozat
# 	Linuxokon es ural2-n is elerheto
#
PROG = nem_oo_teszt   # a program neve (ezt allitjuk elo)
PROG_O = nem_oo_teszt.o nem_oo.o  # program object fajljai 
PROG_H = nem_oo.h     # program header fajljai
PROG_L =              # program libjei

MTRACE_O = memtrace.o # memtrace object fajl
MTRACE_H = memtrace.h # memtrace header fajlja

CXX = g++   # a C fordito neve
#CXX = clang++ # clang-ot (llvm) is erdemes kiprobalni
CXXFLAGS = -pedantic -Wall -Werror# kapcsolok: legyen bobeszedu es pedans
CXXFLAGS += -g # es legyeb debug info is
CXXFLAGS += -DMEMTRACE -std=c++98
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


