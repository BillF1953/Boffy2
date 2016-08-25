# Makefile for Final Project
# Tyler Forrester
# Aug 6, 2016
CXX = g++ -g 
OBJSSUM = Creature.o
SRCSSUM = Creature.cpp
OBJSAVG = Dice.o
SRCSAVG = Dice.cpp
OBJSL1 = InputValid.o
SRCSL1 = InputValid.cpp
OBJSL2 = main.o
SRCSL2 = main.cpp
HEADERS = Creature.hpp
HEADERA = Dice.hpp
HEADERI = InputValid.hpp
OBJS4 = Boffy.o
HEADER4 = Boffy.hpp
SRCS4 = Boffy.cpp
OBJS5 = DreamWalker.o
HEADER5 = DreamWalker.hpp
SRCS5 = DreamWalker.cpp
OBJS6 = FightSpace.o
HEADER6 = FightSpace.hpp
SRCS6 = FightSpace.cpp
OBJS7 = ItemSpace.o
HEADER7 = ItemSpace.hpp
SRCS7 = ItemSpace.cpp
OBJS8 = StartSpace.o
HEADER8 = StartSpace.hpp
SRCS8 = StartSpace.cpp
OBJS9 = Space.o
HEADER9 = Space.hpp
SRCS9 = Space.cpp
OBJS10 = queue.o
HEADER10 = Queue.hpp
SRCS10 = queue.cpp
HEADER11 = Node.hpp

PROG = Final
#PROGT = Test

all: $(PROG) 

$(PROG): $(OBJSL2) $(OBJSSUM) $(OBJSAVG) $(OBJSL1) $(OBJS4) $(OBJS5) $(OBJS6) $(OBJS7) $(OBJS8) $(OBJS9) $(OBJS10)
	$(CXX) $(OBJSAVG) $(OBJSL2) $(OBJSSUM) $(OBJSL1) $(OBJS4) $(OBJS5) $(OBJS6) $(OBJS7) $(OBJS8) $(OBJS9) $(OBJS10) -o $(PROG)
$(OBJSL2): $(SRCSL2) $(HEADERS) $(HEADERA) $(HEADERI)
	$(CXX) -c $(SRCSL2)
$(OBJSAVG): $(SCRSAVG) $(HEADERA) 
	$(CXX) -c $(SRCSAVG)
$(OBJSL1): $(SRCSL1) $(HEADERI)
	$(CXX) -c $(SRCSL1)
$(OBJSSUM): $(SRCSSUM) $(HEADERS)
	$(CXX) -c $(SRCSSUM)
$(OBJS4): $(SRCS4) $(HEADER4)
	$(CXX) -c $(SRCS4)
$(OBJS5): $(SRCS5) $(HEADER5)
	$(CXX) -c $(SRCS5)
$(OBJS6): $(SRCS6) $(HEADER6)
	$(CXX) -c $(SRCS6)
$(OBJS7): $(SRCS7) $(HEADER7)
	$(CXX) -c $(SRCS7)
$(OBJS8): $(SRCS8) $(HEADER8)
	$(CXX) -c $(SRCS8)
$(OBJS9): $(SRCS9) $(HEADER9)
	$(CXX) -c $(SRCS9)
$(OBJS10): $(SRCS10) $(HEADER10) $(HEADER11)
	$(CXX) -c $(SRCS10)
clean:
	rm -rf $(PROG) *.o  *~
