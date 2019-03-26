#
#
# Makefile a CppBolt eloallitasahoz
# 	kihazsnalja, hogy gmake
#

PROG = boltMain
SRCS = boltMain.cpp datum.cpp kassza.cpp memtrace.cpp
HDRS = aru.h datum.h gtest_lite.h kassza.h memtrace.h tej.h
OBJS = $(SRCS:.cpp=.o)

CXXFLAGS = -ggdb -pedantic -Wall -Werror -DMEMTRACE

$(PROG): $(OBJS) 
	$(CXX) -o $(PROG) $(OBJS)

.PHONY:
clean:
	rm -f $(OBJS) $(PROG)

# Egyszerusites: Minden .o fugg minden header-tol, es meg a Makefile-tol is 
$(OBJS): $(HDRS) Makefile


