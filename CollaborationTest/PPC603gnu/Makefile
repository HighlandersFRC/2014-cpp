# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = PPC603gnu
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := C:/WindRiver/workspace
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/2014-cpp/CollaborationTest



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = ppc
CPU = PPC603
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 

IDE_DEFINES = 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif


#Project Targets
PROJECT_TARGETS = CollaborationTest/$(MODE_DIR)/CollaborationTest.out \
	 CollaborationTest_partialImage/$(MODE_DIR)/CollaborationTest_partialImage.o


#Rules

# CollaborationTest
ifeq ($(DEBUG_MODE),1)
CollaborationTest/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
CollaborationTest/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
CollaborationTest/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
CollaborationTest/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
CollaborationTest/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
CollaborationTest/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
CollaborationTest/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
CollaborationTest/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
CollaborationTest/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
CollaborationTest/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
CollaborationTest/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
CollaborationTest/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
CollaborationTest/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
CollaborationTest/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
CollaborationTest/$(MODE_DIR)/% : IDE_DEFINES = 
CollaborationTest/$(MODE_DIR)/% : PROJECT_TYPE = DKM
CollaborationTest/$(MODE_DIR)/% : DEFINES = 
CollaborationTest/$(MODE_DIR)/% : EXPAND_DBG = 0
CollaborationTest/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
CollaborationTest/$(MODE_DIR)/% : CPU = PPC603
CollaborationTest/$(MODE_DIR)/% : TOOL_FAMILY = gnu
CollaborationTest/$(MODE_DIR)/% : TOOL = gnu
CollaborationTest/$(MODE_DIR)/% : TOOL_PATH = 
CollaborationTest/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
CollaborationTest/$(MODE_DIR)/% : LIBPATH = 
CollaborationTest/$(MODE_DIR)/% : LIBS = 
CollaborationTest/$(MODE_DIR)/% : OBJ_DIR := CollaborationTest/$(MODE_DIR)

OBJECTS_CollaborationTest = CollaborationTest_partialImage/$(MODE_DIR)/CollaborationTest_partialImage.o

CollaborationTest/$(MODE_DIR)/CollaborationTest.out : $(OBJECTS_CollaborationTest)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmppc $(OBJECTS_CollaborationTest) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_CollaborationTest) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

CollaborationTest/$(MODE_DIR)/CollaborationTest_compile_file : $(FILE) ;

_clean :: CollaborationTest/$(MODE_DIR)/CollaborationTest_clean

CollaborationTest/$(MODE_DIR)/CollaborationTest_clean : 
	$(TRACE_FLAG)if [ -d "CollaborationTest" ]; then cd "CollaborationTest"; rm -rf $(MODE_DIR); fi


# CollaborationTest_partialImage
ifeq ($(DEBUG_MODE),1)
CollaborationTest_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
CollaborationTest_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
CollaborationTest_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
CollaborationTest_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
CollaborationTest_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
CollaborationTest_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
CollaborationTest_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
CollaborationTest_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
CollaborationTest_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
CollaborationTest_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
CollaborationTest_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
CollaborationTest_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
CollaborationTest_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
CollaborationTest_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
CollaborationTest_partialImage/$(MODE_DIR)/% : IDE_DEFINES = 
CollaborationTest_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
CollaborationTest_partialImage/$(MODE_DIR)/% : DEFINES = 
CollaborationTest_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
CollaborationTest_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
CollaborationTest_partialImage/$(MODE_DIR)/% : CPU = PPC603
CollaborationTest_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = gnu
CollaborationTest_partialImage/$(MODE_DIR)/% : TOOL = gnu
CollaborationTest_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
CollaborationTest_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
CollaborationTest_partialImage/$(MODE_DIR)/% : LIBPATH = 
CollaborationTest_partialImage/$(MODE_DIR)/% : LIBS = 
CollaborationTest_partialImage/$(MODE_DIR)/% : OBJ_DIR := CollaborationTest_partialImage/$(MODE_DIR)

CollaborationTest_partialImage/$(MODE_DIR)/Objects/CollaborationTest/Commands/AlexCommand.o : $(PRJ_ROOT_DIR)/Commands/AlexCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CollaborationTest_partialImage/$(MODE_DIR)/Objects/CollaborationTest/Commands/AutonomousCommand.o : $(PRJ_ROOT_DIR)/Commands/AutonomousCommand.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CollaborationTest_partialImage/$(MODE_DIR)/Objects/CollaborationTest/OI.o : $(PRJ_ROOT_DIR)/OI.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CollaborationTest_partialImage/$(MODE_DIR)/Objects/CollaborationTest/Robot.o : $(PRJ_ROOT_DIR)/Robot.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CollaborationTest_partialImage/$(MODE_DIR)/Objects/CollaborationTest/RobotMap.o : $(PRJ_ROOT_DIR)/RobotMap.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


CollaborationTest_partialImage/$(MODE_DIR)/Objects/CollaborationTest/Subsystems/AlexSubsystem.o : $(PRJ_ROOT_DIR)/Subsystems/AlexSubsystem.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_CollaborationTest_partialImage = CollaborationTest_partialImage/$(MODE_DIR)/Objects/CollaborationTest/Commands/AlexCommand.o \
	 CollaborationTest_partialImage/$(MODE_DIR)/Objects/CollaborationTest/Commands/AutonomousCommand.o \
	 CollaborationTest_partialImage/$(MODE_DIR)/Objects/CollaborationTest/OI.o \
	 CollaborationTest_partialImage/$(MODE_DIR)/Objects/CollaborationTest/Robot.o \
	 CollaborationTest_partialImage/$(MODE_DIR)/Objects/CollaborationTest/RobotMap.o \
	 CollaborationTest_partialImage/$(MODE_DIR)/Objects/CollaborationTest/Subsystems/AlexSubsystem.o

CollaborationTest_partialImage/$(MODE_DIR)/CollaborationTest_partialImage.o : $(OBJECTS_CollaborationTest_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X  -o "$@" $(OBJECTS_CollaborationTest_partialImage) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS)  && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

CollaborationTest_partialImage/$(MODE_DIR)/CollaborationTest_partialImage_compile_file : $(FILE) ;

_clean :: CollaborationTest_partialImage/$(MODE_DIR)/CollaborationTest_partialImage_clean

CollaborationTest_partialImage/$(MODE_DIR)/CollaborationTest_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "CollaborationTest_partialImage" ]; then cd "CollaborationTest_partialImage"; rm -rf $(MODE_DIR); fi

force : 

DEP_FILES := CollaborationTest_partialImage/$(MODE_DIR)/Objects/CollaborationTest/Commands/AlexCommand.d CollaborationTest_partialImage/$(MODE_DIR)/Objects/CollaborationTest/Commands/AutonomousCommand.d CollaborationTest_partialImage/$(MODE_DIR)/Objects/CollaborationTest/OI.d \
	 CollaborationTest_partialImage/$(MODE_DIR)/Objects/CollaborationTest/Robot.d CollaborationTest_partialImage/$(MODE_DIR)/Objects/CollaborationTest/RobotMap.d CollaborationTest_partialImage/$(MODE_DIR)/Objects/CollaborationTest/Subsystems/AlexSubsystem.d
-include $(DEP_FILES)



-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

main_all : external_build $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
