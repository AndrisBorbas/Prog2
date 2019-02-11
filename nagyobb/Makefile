#
# Demo Makefile a nagyobb program eloallitasahoz
#

PROG = nagyobb
SRCS = nagyobb_main.cpp fuggvenyeim.cpp
HDRS = fuggvenyeim.h
OBJS = $(SRCS:.cpp=.o)

CXXFLAGS = -g -Wall

$(PROG): $(OBJS) 
	$(CXX) -o $(PROG) $(OBJS)

.PHONY:
clean:
	rm -f $(OBJS) $(PROG)

# Egyszerusites: Minden .o fugg minden header-tol
$(OBJS): $(HDRS)


