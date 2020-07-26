CXX=g++ -I.
COMMON_FILES=IOPipeline.cpp
CPP_FILE=02_08_01_JollyJumper.cpp
EXE=$(shell basename ${CPP_FILE} .cpp ).exe
RM=rm -rf
all:
	${CXX} ${CPP_FILE} ${COMMON_FILES} -o ${EXE}
.PHONY:clean
clean:
	${RM} ${EXE}

