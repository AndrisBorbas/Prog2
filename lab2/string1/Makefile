#
# Makefile pelda a string1 feladat (2. labor) megoldasanak forditasara 
# gnumake valtozat
# 	Linuxokon es ural2-n is elerheto
#
# A make paranccsorabol magadott CMD valtozo tartalma atadodik a forditonak
# Pl:
# make CMD=-DMEMTRACE
#
PROG = string1        			# a program neve (ezt allitjuk elo)
PROG_O = string1.o string1_main.o   	# program object fajljai 
PROG_H = string1.h 	      		# program header fajljai
PROG_L =              			# program libjei

MTRACE_O = memtrace.o # memtrace object fajl
MTRACE_H = memtrace.h # memtrace header fajlja

CC = gcc   # a C fordito neve
#CC = clang # clang-ot (llvm) is erdemes kiprobalni
CFLAGS = -std=c99 -pedantic -Wall # kapcsolok: C99, legyen bobeszedu es pedans
CFLAGS += -g # es legyeb debug info is
CFLAGS += $(CMD) # es amit a parancsorbol megadnak
LDFLAGS = -g # debug a linkelesnel 

# osszes object, osszes header osszes lib
OBJS = $(PROG_O) $(MTRACE_O)
HEADS = $(PROG_H) $(MTRACE_H)
LIBS = $(PROG_L) 

# alapertelmezett cel: program
.PHONY: all
all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@ $(LIBS)

# feltetelezzuk, hogy az osszes obj fugg az osszes headertol
$(OBJS): $(HEADS)

# takaritas igeny szerint
.PHONY: clean
clean:
	rm -f $(OBJS) $(PROG)

