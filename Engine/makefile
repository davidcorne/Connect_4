#==============================================================================
#D A make file to make an executable project
#D Directory structure:
# +--Engine
# +--+--Engine
# +--+--+-- header files
# +--+--source
# +--+--+--application
# +--+--+--+-- application file (with int main() in)
# +--+--+--src
# +--+--+--+-- normal source files
# +--+--exe
# +--+--+-- executable file
# +--+--lib
# +--+--+-- library file
# +--+--obj
# +--+--+-- object files

#------------------------------------------------------------------------------
# Options to edit with specific project names
EXE = Connect_4
LIB = Engine
# OBJECTS must be in dependency order right depending on left, and preceded by
# obj/ eg obj/utility.o obj/file.o
OBJECTS = obj/engEngine.o obj/engAI.o
INCLUDES = -I. -I../dgcUtils

#------------------------------------------------------------------------------
# Generic options 
CFLAGS_D = -O0 -g -DDEBUG -D_DEBUG -D_WINDOWS $(INCLUDES) -Wall -Werror
CFLAGS = -O2
CC = g++

#==============================================================================
# Rules/Dependencies (all generic)
#==============================================================================

#==============================================================================
#D Build a the executable 
#D try to get debugging info out for Visual Studio -- currently doesn't work
#
#------------------------------------------------------------------------------
exe/$(EXE).exe: source/application/$(EXE).cpp lib/$(LIB).lib 
	@mkdir -p exe
	$(CC) $(CFLAGS_D) source/application/$(EXE).cpp lib/$(LIB).lib \
        -o exe/$(EXE).exe
	@echo ""

#==============================================================================
#D Build the objects into a library
#------------------------------------------------------------------------------
lib/$(LIB).lib: $(OBJECTS) 
	@mkdir -p lib
	@echo ""
	ar ruvs $(LIB).lib $(OBJECTS)
	@mv $(LIB).lib lib
	@echo ""

#==============================================================================
#D Make all the object files and move them to the obj directory
#------------------------------------------------------------------------------
obj/%.o : source/*/%.cpp $(LIB)/%.h 
	@mkdir -p obj
	$(CC) $(CFLAGS_D) -c $<
	@mv *.o obj

#==============================================================================
#D For deleting all temporary and made files
#------------------------------------------------------------------------------
clean: FRC
	@rm -f obj/* lib/* exe/* *.stackdump *~ \#*\#
	@echo "Removed all: objects, libraries, executables, and temp files."

#==============================================================================
#D Pseudo target causes all targets that depend on FRC to be remade even in 
#D case a file with the name of the target exists. Works unless there is a file
#D called FRC in the directory.
#------------------------------------------------------------------------------
FRC:
