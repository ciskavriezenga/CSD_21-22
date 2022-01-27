CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS=-ljack
SRC_PROJECT = interpolation.cpp main.cpp
SHAREDCODE_PATH = ../../../sharedCode/
MODULES = utilities
# append shared code path prefix to modules
MODULE_PATHS = $(addprefix $(SHAREDCODE_PATH),$(MODULES))
# log MODULE_PATHS
$(info $$MODULE_PATHS is [${MODULE_PATHS}])

# module .mk files
MODULE_MK = $(patsubst %,%/module.mk,$(MODULE_PATHS))
# log MODULE_MK
$(info $$MODULE_MK is [${MODULE_MK}])

# include the description for each module
SRC_MODULES =
include $(MODULE_MK)
# log SRC_MODULES
$(info $$SRC_MODULES is [${SRC_MODULES}])

# create src list for all .cpp files
SRC = $(addprefix $(SHAREDCODE_PATH),$(SRC_MODULES))
SRC+= $(SRC_PROJECT)
# log SRC
$(info $$SRC is [${SRC}])

# look for include files in
# each of the modules
CXXFLAGS += $(patsubst %,-I%,./$(MODULE_PATHS))

# determine the object files --> replace all .cpp in SRC with .o
OBJ := $(patsubst %.cpp,%.o, $(filter %.cpp,$(SRC)))
# log OBJ
$(info $$OBJ is [${OBJ}])

TARGET=example
# link the program
$(TARGET):$(OBJ)
	$(CXX) -o $@ $(OBJ) $(LDFLAGS)

# -o $*.o --> write .o file to the directory of the current target
.cpp.o:
	$(CXX) -c $< $(CXXFLAGS) -o $*.o

plot:
	python3 $(SHAREDCODE_PATH)utilities/plot.py

clean:
	rm $(TARGET)
	rm $(OBJ)
