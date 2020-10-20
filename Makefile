#
# This is an example Makefile for a countwords program.  This
# program uses both the scanner module and a counter module.
# Typing 'make' or 'make count' will create the executable file.
#

# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
#
TARGET = simulPlatform

#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
# for C++ define  CC = g++
CC = g++
RM = rm
INCLUDE =-I $(INCDIR)
CFLAGS  = -std=c++11 -Wall -Werror $(INCLUDE)


SRCDIR=src
INCDIR=include

SRC=$(wildcard $(SRCDIR)/*.cpp)

OBJECT=$(SRC:.cpp = .o)

# typing 'make' will invoke the first target entry in the file
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
default: $(TARGET)

# To create the executable file count we need the object files
# countwords.o, counter.o, and scanner.o:
#
$(TARGET):  $(OBJECT)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECT)

# To create the object file countwords.o, we need the source
# files countwords.c, scanner.h, and counter.h:
#
%.o:  %.cpp
	$(CC) $(CFLAGS) -c -o $(basename $<).o



# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean:
	$(RM) $(TARGET)
#$(SRCDIR)/*.o
#*~
