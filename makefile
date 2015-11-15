CXX      = gcc
CXXFLAGS = -Wall
EXE      = project
OBJS     = main.o ascii.o admin.o getch.o

$(EXE): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@
%.o: %.c
	$(CXX) -c $^

clean:
	$(RM) $(OBJS) $(EXE) *~ 
