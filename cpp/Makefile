SRCS=$(wildcard *.cc)

OBJS=$(SRCS:.cc=.o)

OUTS=$(SRCS:.cc=.out)

%.o : %.cc
	  g++ -g3 -std=c++11 -c $< -o $@

%.out : %.o
	  g++ -g3 $< -o $@

.PHONY : all clean
all: $(OUTS)

clean :
	  $(RM) -v $(OBJS) $(OUTS)
