#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=c++
CXX=c++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin_1-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Arbol_ABB.o \
	${OBJECTDIR}/Capa.o \
	${OBJECTDIR}/Cubo.o \
	${OBJECTDIR}/Generador_Imagen.o \
	${OBJECTDIR}/Generador_Repore.o \
	${OBJECTDIR}/Lista_Filtro.o \
	${OBJECTDIR}/Lista_String.o \
	${OBJECTDIR}/Nodo_ABB.o \
	${OBJECTDIR}/Nodo_Capa.o \
	${OBJECTDIR}/Nodo_Cubo.o \
	${OBJECTDIR}/Nodo_Filtro.o \
	${OBJECTDIR}/Nodo_String.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/edd_2s2019_py1_201709426.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/edd_2s2019_py1_201709426.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/edd_2s2019_py1_201709426 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Arbol_ABB.o: Arbol_ABB.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Arbol_ABB.o Arbol_ABB.cpp

${OBJECTDIR}/Capa.o: Capa.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Capa.o Capa.cpp

${OBJECTDIR}/Cubo.o: Cubo.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Cubo.o Cubo.cpp

${OBJECTDIR}/Generador_Imagen.o: Generador_Imagen.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Generador_Imagen.o Generador_Imagen.cpp

${OBJECTDIR}/Generador_Repore.o: Generador_Repore.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Generador_Repore.o Generador_Repore.cpp

${OBJECTDIR}/Lista_Filtro.o: Lista_Filtro.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Lista_Filtro.o Lista_Filtro.cpp

${OBJECTDIR}/Lista_String.o: Lista_String.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Lista_String.o Lista_String.cpp

${OBJECTDIR}/Nodo_ABB.o: Nodo_ABB.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Nodo_ABB.o Nodo_ABB.cpp

${OBJECTDIR}/Nodo_Capa.o: Nodo_Capa.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Nodo_Capa.o Nodo_Capa.cpp

${OBJECTDIR}/Nodo_Cubo.o: Nodo_Cubo.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Nodo_Cubo.o Nodo_Cubo.cpp

${OBJECTDIR}/Nodo_Filtro.o: Nodo_Filtro.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Nodo_Filtro.o Nodo_Filtro.cpp

${OBJECTDIR}/Nodo_String.o: Nodo_String.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Nodo_String.o Nodo_String.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/edd_2s2019_py1_201709426.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
