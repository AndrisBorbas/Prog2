# Pelda Makefile a 3. labor megoldasanak forditasara es tesztelesere
# Solaris (ural2) es Linux ala.

GTEST = ./gtest
                                # gtest katalogus helye
ARCH = `uname`-`uname -m`       # architekturahoz tartozo kat. neve
objs = komplex_teszt.o komplex.o # forditando obj. fajlok
CXX = g++                       # a C++ fordito neve
#CXX = clang++                  # clang-ot (llvm) is erdemes kiprobalni
CXXFLAGS = -pedantic -Wall      # C++ kapcsolok: legyen bobeszedu, 
CXXFLAGS += -Wno-long-long -Wno-variadic-macros
                                # ... de gtest headerekre ne gerjedjen

# alapertelmezett cel: tesztek futtatasa
.PHONY:
do_test: test
	./test

# tesztprogram linkelese
test: $(objs)
	$(CXX) -L$(GTEST)/$(ARCH) -lgtest_main -lgtest $(objs) -o $@

# tesztprogram forditasahoz kell a gtest include katalogus
komplex_teszt.o: komplex_teszt.cpp
	$(CXX) ${LDFLAGS} -I${GTEST}/include $(CPPFLAGS) $(CXXFLAGS) -c komplex_teszt.cpp 

# ujraforditas, ha valtozik az osztaly felepitese
komplex.o komplex_teszt.o: komplex.h

fapados: fapados_komplex_teszt.o komplex.o komplex.h
	$(CXX) fapados_komplex_teszt.o komplex.o -o $@

# takaritas igeny szerint
.PHONY:
clean:
	rm -f *.o test fapados *~

# tar igeny szerint
.PHONY:
tar:
	tar -czvf komplex.tgz *.h *.cpp 

