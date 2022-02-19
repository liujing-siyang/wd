INC_DIR :=  ./include/
SRC_DIR := ./src ./src/threadpool ./src/netlib
#EXE_DIR := ./bin
CC := g++
CPPFLAGS :=  -g 
LIBS := -lpthread
INC_FILE := $(addprefix -I, $(INC_DIR))
CPP_FILE :=  $(wildcard ./src/threadpool/*.cc) $(wildcard ./src/netlib/*.cc) $(wildcard ./src/*.cc)

OBJS := $(patsubst %.cc, %.o, $(CPP_FILE))

# objs:=$(addsuffix /*.o, $(SRC_DIR))

TARGET := server.exe

$(TARGET):$(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^ $(INC_FILE) $(LIBS)

%.o:%.cc
	$(CC) $(CPPFLAGS) -o $@ -c $< $(INC_FILE) $(LIBS)
object:
	@echo $(OBJS)
clean:
	rm -rf $(TARGET) $(OBJS)
