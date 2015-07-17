# Makefile: MersenneTwister
#
# Jason R. Blevins <jrblevin@sdf.lonestar.org>
# Durham, March  7, 2007

CXX = g++
LD = g++
AR = ar

CXXFLAGS = -O3 -Wall
LDFLAGS = 
LIBS = 
ARFLAGS = rcs

###############################################################################
# BUILD RULES

.SUFFIXES: .o .cc

.cc.o:
	$(CXX) $(CXXFLAGS) -c $*.cc

all: passgen

passgen: mt.o genAlpha.o
	$(LD) $(LDFLAGS) -o passgen genAlpha.o mt.o $(LIBS)

clean:
	rm -f *.o *~ passgen

###############################################################################
