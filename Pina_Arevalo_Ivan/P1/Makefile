CXX = g++
CPPFLAGS = -DP1 -I../Test-auto -I.
CXXFLAGS = -Wall -Wextra -pedantic -Werror -pedantic-errors \
	-std=c++11 -g -fmax-errors=5

VPATH = ../Tests-auto:.

EXE = test-P1-consola test-P1-auto
OBJS = fecha.o cadena.o

AUTO_OBJS = test-caso0-fecha-auto.o test-caso0-cadena-auto.o
AUTO_OBJS += test-auto.o

ALL_OBJS = $(OBJS) $(AUTO_OBJS) test-P1-consola.o

all: $(EXE)

$(EXE): $(OBJS)
test-P1-consola: test-P1-consola.o
	$(CXX) $^ -o $@

test-P1-auto: $(AUTO_OBJS) $(OBJS)
	$(CXX) $^ -o $@

fecha.o: fecha.hpp
cadena.o: cadena.hpp

test-P0-consola.o: fecha.hpp cadena.hpp

$(AUTO_OBJS): test-auto.hpp fecha.hpp cadena.hpp # fct.hpp

checks:
	$(MAKE) -f Make_check.mk checks $@

clean:
	$(RM) $(ALL_OBJS) $(EXE) *~ *#
