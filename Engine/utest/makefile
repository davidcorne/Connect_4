#==============================================================================
#D A make file to make the unit tests
EXECUTABLES = exe/utest_engEngine.exe exe/utest_engAI.exe
INCLUDES = -I.. -I../../dgcUtils
LIBS = ../lib/Engine.lib

#------------------------------------------------------------------------------
# Generic options 
CFLAGS_D = -O0 -g -DDEBUG -D_DEBUG -D_WINDOWS $(INCLUDES)
CC = g++

#==============================================================================
#D Artificial target so it makes all the executables
#------------------------------------------------------------------------------
END: $(EXECUTABLES)
	@echo "All tests made."
	@echo ""

#==============================================================================
#D Make all the executables
#------------------------------------------------------------------------------
exe/%.exe: source/%.cpp $(LIBS)
	@mkdir -p exe
	$(CC) $(CFLAGS_D) $< $(LIBS) -o $@
	@echo ""

#==============================================================================
#D Run all the tests, needs to be added to manually
#------------------------------------------------------------------------------
run: END
	./exe/utest_engEngine.exe
	./exe/utest_engAI.exe

#==============================================================================
#D For deleting all temporary and made files
#------------------------------------------------------------------------------
clean: FRC
	@rm -f obj/* exe/* *.stackdump *~ \#*\#
	@echo "Removed all: objects, libraries, executables, and temp files."

#==============================================================================
#D Pseudo target causes all targets that depend on FRC to be remade even in 
#D case a file with the name of the target exists. Works unless there is a file
#D called FRC in the directory.
#------------------------------------------------------------------------------
FRC:
