# Makefile Alakzatlab2-hoz
# Solaris (ural2) es Linux ala.

objs = 	alakzat.o pont.o szin.o kor.o szakasz.o teglalap.o \
	haromszog.o poligon.o rajztabla.o alakzat2_main.o memtrace.o
heads = alakzat.h pont.h szin.h kor.h szakasz.h teglalap.h \
	haromszog.h poligon.h rajztabla.h memtrace.h 


CXX = g++ #                        # a C++ fordito neve
#CXX = clang++ #                   # clang-ot (llvm) is erdemes kiprobalni
CXXFLAGS = -pedantic -Wall -Werror # C++ kapcsolok: legyen bobeszedu, 
CXXFLAGS += -g #                   # ... es legyen debug info is
CXXFLAGS += -DMEMTRACE

# alapertelmezett cel: erdeklodik, hogy melyik legyen

.PHONY: all
all: 	$(objs)
	$(CXX) $(objs) -o alakzat2

$(objs1): $(heads)

# takaritas igeny szerint
.PHONY: clean
clean:
	rm -f $(objs) alakzat2
