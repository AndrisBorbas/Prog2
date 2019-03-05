#
# Makefile a CppVektor0 feladathoz
#

# MEMTRACE-hez:
CXXFLAGS = -g -Wall -DMEMTRACE

# Mpatrol-hoz:
#CXXFLAGS = -g -Wall
LIBMPATROL = -lmpatrol -lbfd

OBJS = vektor.o vektorMain.o

# Ez a default cel
.PHONY: all
all: vektorMain_mtrac

# Nincs mem ellenorzes
vektorMain: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

# MPATROL valtozat
vektorMain_mpat: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(LIBMPATROL) -o $@

# MEMTRACE
vektorMain_mtrac: $(OBJS) memtrace.o
	$(CXX) $(CXXFLAGS) $(OBJS) memtrace.o -o $@

#-------------
vektor.o: vektor.h vektor.cpp

clean:
	rm -f *.o *.log vektorMain vektorMain_mpat vektorMain_mtrac

check:  main_mpat
	MPATROL_OPTIONS=LEAKTABLE ./vektorMain_mpat
	
