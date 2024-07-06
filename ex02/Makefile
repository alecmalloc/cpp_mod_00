name    = accounts
CC      = c++
FLAGS   = -Wall -Wextra -Werror
OUT     = $(name)

# 1. Find all .cpp files in the current directory
SOURCES = $(wildcard *.cpp)
# 2. Convert the .cpp files to .o files
OBJS    = $(patsubst %.cpp,%.o,$(SOURCES))

# Compile all object files and link into the final executable
all: $(OUT)

$(OUT): $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)

# 3. Pattern rule for object files
%.o: %.cpp
	$(CC) $(FLAGS) -c $< -std=c++98

clean:
	rm -f $(OBJS) $(OUT)

fclean:
	rm -f $(name) *.o