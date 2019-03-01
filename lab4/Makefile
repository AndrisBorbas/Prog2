# Pelda Makefile a Cpp Ellenallas (3. laborfeledati) megoldasanak forditasara 
# Solaris (ural2) es Linux ala.

objs1 = resistor.o resistor_test.o # forditando obj. fajlok
heads1 = resistor.h #              # headerek, amitol minden fugg
prog1 = resistor_test #            # a program neve

objs2 = resistor.o resistor_test2.o 
heads2 = resistor.h elkeszult.h
prog2 = resistor_test2

objs3 = resistor.o potmeter.o console.o potmeter_teszt.o
heads3 = resistor.h elkeszult.h potmeter.h console.h 
prog3 = potmeter_teszt

targets = $(prog1) $(prog2) $(prog3)

CXX = g++ #                        # a C++ fordito neve
#CXX = clang++ #                   # clang-ot (llvm) is erdemes kiprobalni
CXXFLAGS = -pedantic -Wall #       # C++ kapcsolok: legyen bobeszedu, 
CXXFLAGS += -g #                   # ... es legyen debug info is
CXXFLAGS += -fno-elide-constructors# ne optimalizálja másoló konstruktorok hívását
CXXFLAGS += $(CMD)		   # CMD a parancssorból (pl: CMD=-DDEBUG)

# alapertelmezett cel: erdeklodik, hogy melyik legyen

.PHONY: all
all: 
	@echo "Melyiket allitsuk elo?"
	@for i in $(targets) ; do echo " > make $$i" ; done

$(prog1): $(objs1)
	$(CXX) $(objs1) -o $@

$(objs1): $(heads1)

$(prog2): $(objs2)
	$(CXX) $(objs2) -o $@

$(objs2): $(heads2)

$(prog3): $(objs3)
	$(CXX) $(objs3) -o $@

$(objs3): $(heads3)

# takaritas igeny szerint
.PHONY: clean
clean:
	rm -f $(objs1) $(prog1) $(objs2) $(prog2) $(objs3) $(prog3)
