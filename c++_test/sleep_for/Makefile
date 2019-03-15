OBJS = sleep_for.o
CPP = g++ 
FLAGS = -std=c++14 -g
LRD = -lpthread

test: $(OBJS)
	$(CPP) $(FLAGS) -o test $(OBJS) $(lRD)

#.PHONY:clean
clean:
	rm test
