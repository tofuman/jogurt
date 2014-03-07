# Makefile for joguhrt
# created with makefile-creator


####################
#Settings:


CXX = gcc
FLAGS += -Wall -Wextra -pedantic -std=c11  
LIBS += -lncurses 
INCLUDES += 
TARGET = joguhrt
OBJECTS = joguhrt.o


####################
#Rules:


$(TARGET) : $(OBJECTS)
	$(CXX) $(FLAGS) -o $(TARGET) $(OBJECTS) $(LIBS)

%.o:
	$(CXX) $(FLAGS) $(INCLUDES) -c -o $@ $<

clean:
	rm *.o

all: $(TARGET)


####################
#Dependencies:


joguhrt.o: joguhrt.c makefile

