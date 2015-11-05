
CXX_FLAGS = -O0 -Wall -g --std=c++0x

PROGS=main

all: $(PROGS)

clean: ; rm -f *.o data* *.unc-* $(PROGS)
uncrustify: ; uncrustify -c uncrust.cfg --replace *.hh *.cc

%.o: %.cc; $(CXX) -c $< $(CXX_FLAGS)

OBJECTS = matrix.o main.o

default:

main: $(OBJECTS); $(CXX) -o $@ $(OBJECTS) $(CXX_FLAGS)
