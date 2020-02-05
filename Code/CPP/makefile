CC = g++

INCLUDES = -I/opt/ibm/ILOG/CPLEX_Studio1271/cplex/include -I/opt/ibm/ILOG/CPLEX_Studio1271/concert/include -I./include

LFLAGS = -L/opt/ibm/ILOG/CPLEX_Studio1271/cplex/lib/x86-64_linux/static_pic -L/opt/ibm/ILOG/CPLEX_Studio1271/concert/lib/x86-64_linux/static_pic

LIBS = -lilocplex -lconcert -lcplex -lm -lpthread

SRCS = ./src/*.cpp

OBJS = $(SRCS:.c=.o)

MAIN = diet

all: $(MAIN)

$(MAIN): $(OBJS)
	 $(CC) -DIL_STD $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)
