#---------------------------------------------
# Target file to be compiled by default
#---------------------------------------------
MAIN = example
#---------------------------------------------
# CC is the compiler to be used
#---------------------------------------------
CC = gcc
#---------------------------------------------
# CFLAGS are the options passed to the compiler
#---------------------------------------------
CFLAGS = -Wall 
#---------------------------------------------
# OBJS are the object files to be linked
#---------------------------------------------
OBJ1 = kohonen
OBJS = $(MAIN).o $(OBJ1).o
#---------------------------------------------
# LIBS are the external libraries to be used
#--------------------------------------------
LIBS = -lm
#---------------------------------------------
# Dependencies
#--------------------------------------------
$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS) $(LIBS)

$(MAIN).o: $(MAIN).c constant.h
	$(CC) $(CFLAGS) -c $(MAIN).c

$(OBJ1).o: $(OBJ1).c constant.h
	$(CC) $(CFLAGS) -c $(OBJ1).c

#-------------------------------------------
# Command that can be specified inline: make clean
#-------------------------------------------
clean: 
	rm -rf *.o $(MAIN)
