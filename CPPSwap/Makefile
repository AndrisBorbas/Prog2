#
# Makefile a CPPswap eloallitasahoz
#

PROG = swap_test
SRCS = swap_test.cpp swap.cpp memtrace.cpp 
HDRS = swap.h memtrace.h gtest_lite.h
OBJS = $(SRCS:.cpp=.o)

CXXFLAGS = -g -Wall -Werror -DMEMTRACE

$(PROG): $(OBJS) 
	$(CXX) -o $(PROG) $(OBJS)

.PHONY:
clean:
	rm -f $(OBJS) $(PROG)

# Egyszerusites: Minden .o fugg minden header-tol, es meg a Makefile-tol is 
$(OBJS): $(HDRS) Makefile


