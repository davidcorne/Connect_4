#==============================================================================
#D A make file to make the unit tests

#------------------------------------------------------------------------------
# Generic options 
CFLAGS_D = -O0 -g -DDEBUG -D_DEBUG -D_WINDOWS -I.. -I../..
CC = g++
#==============================================================================
#D Build the unit test exe for engEngine
#------------------------------------------------------------------------------

exe/utest_engEngine.exe: source/utest_engEngine.cpp ../lib/* ../../*.h
	$(CC) $(CFLAGS_D) source/utest_engEngine.cpp ../lib/Engine.lib \
        -o exe/utest_engEngine.exe 

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
