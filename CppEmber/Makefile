#
# Makefile a CppEmber feladathoz
#

# MEMTRACE-hez:
CXXFLAGS = -g -Wall -Werror -pedantic -DMEMTRACE

# Mpatrol-hoz:
#CXXFLAGS = -g -Wall -Werror -pedantic
LIBMPATROL = -lmpatrol -lbfd

OBJS = ember.o hallgato.o emberMain.o 

# Ez a default cel
.PHONY: all
all: main_mtrac

# Nincs mem ellenorzes
main: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

# MPATROL valtozat
main_mpat: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(LIBMPATROL) -o $@

# MEMTRACE
main_mtrac: $(OBJS) memtrace.o
	$(CXX) $(CXXFLAGS) $(OBJS) memtrace.o -o $@

#-------------
ember.o: ember.cpp ember.h

hallgato.o: hallgato.cpp hallgato.h ember.h

emberMain.o: emberMain.cpp hallgato.h ember.h kutato.h gtest_lite.h

memtrace.o:	memtrace.cpp memtrace.h

clean:
	rm -f *.o *.log main main_mpat main_mtrac

check:  main_mpat
	MPATROL_OPTIONS=LEAKTABLE ./main_mpat
	
