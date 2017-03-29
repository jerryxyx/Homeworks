include common.mk

SRC_DIRS:=.
SAMPLE_EXECUTALBE:=division_problem
SRCS:=$(wildcard $(addsuffix /*.cpp, $(SRC_DIRS)))
OBJS:=$(addsuffix .o, $(basename $(SRCS)))

OBJS:=DivisionProblem.o

.PHONY: all clean

all:$(SAMPLE_EXECUTABLE)

$(SAMPLE_EXECUTABLE):$(OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -o $^
