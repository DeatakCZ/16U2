#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=a
DEBUGGABLE_SUFFIX=
FINAL_IMAGE=${DISTDIR}/IC_Library.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=a
DEBUGGABLE_SUFFIX=
FINAL_IMAGE=${DISTDIR}/IC_Library.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=IC_4021.cpp Led.cpp IC_4022.cpp IC_4056.cpp IC_2024.cpp Switch.cpp IC_4051.cpp IC_4094.cpp

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/IC_4021.o ${OBJECTDIR}/Led.o ${OBJECTDIR}/IC_4022.o ${OBJECTDIR}/IC_4056.o ${OBJECTDIR}/IC_2024.o ${OBJECTDIR}/Switch.o ${OBJECTDIR}/IC_4051.o ${OBJECTDIR}/IC_4094.o
POSSIBLE_DEPFILES=${OBJECTDIR}/IC_4021.o.d ${OBJECTDIR}/Led.o.d ${OBJECTDIR}/IC_4022.o.d ${OBJECTDIR}/IC_4056.o.d ${OBJECTDIR}/IC_2024.o.d ${OBJECTDIR}/Switch.o.d ${OBJECTDIR}/IC_4051.o.d ${OBJECTDIR}/IC_4094.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/IC_4021.o ${OBJECTDIR}/Led.o ${OBJECTDIR}/IC_4022.o ${OBJECTDIR}/IC_4056.o ${OBJECTDIR}/IC_2024.o ${OBJECTDIR}/Switch.o ${OBJECTDIR}/IC_4051.o ${OBJECTDIR}/IC_4094.o

# Source Files
SOURCEFILES=IC_4021.cpp Led.cpp IC_4022.cpp IC_4056.cpp IC_2024.cpp Switch.cpp IC_4051.cpp IC_4094.cpp

# Pack Options 
PACK_COMPILER_OPTIONS=-I "${DFP_DIR}/include"
PACK_COMMON_OPTIONS=-B "${DFP_DIR}/gcc/dev/atmega16u2"



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/IC_Library.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega16U2
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/IC_4021.o: IC_4021.cpp  .generated_files/flags/default/5c48e81333361507593c90a3d17080ad2716dadf .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/IC_4021.o.d 
	@${RM} ${OBJECTDIR}/IC_4021.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega16u2 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/IC_4021.o.d" -MT "${OBJECTDIR}/IC_4021.o.d" -MT ${OBJECTDIR}/IC_4021.o  -o ${OBJECTDIR}/IC_4021.o IC_4021.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Led.o: Led.cpp  .generated_files/flags/default/6dcc6c7bcd9f761934cc8704dc04f54c9b75e49f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Led.o.d 
	@${RM} ${OBJECTDIR}/Led.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega16u2 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/Led.o.d" -MT "${OBJECTDIR}/Led.o.d" -MT ${OBJECTDIR}/Led.o  -o ${OBJECTDIR}/Led.o Led.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/IC_4022.o: IC_4022.cpp  .generated_files/flags/default/1b8cdebb44d703cecc70b157f1d66beb3a90cf6c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/IC_4022.o.d 
	@${RM} ${OBJECTDIR}/IC_4022.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega16u2 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/IC_4022.o.d" -MT "${OBJECTDIR}/IC_4022.o.d" -MT ${OBJECTDIR}/IC_4022.o  -o ${OBJECTDIR}/IC_4022.o IC_4022.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/IC_4056.o: IC_4056.cpp  .generated_files/flags/default/e1b595f523206d162be182f569b1af92c17eb585 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/IC_4056.o.d 
	@${RM} ${OBJECTDIR}/IC_4056.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega16u2 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/IC_4056.o.d" -MT "${OBJECTDIR}/IC_4056.o.d" -MT ${OBJECTDIR}/IC_4056.o  -o ${OBJECTDIR}/IC_4056.o IC_4056.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/IC_2024.o: IC_2024.cpp  .generated_files/flags/default/9aaf8bf0b0e5006dfff377f693a01968c696566e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/IC_2024.o.d 
	@${RM} ${OBJECTDIR}/IC_2024.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega16u2 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/IC_2024.o.d" -MT "${OBJECTDIR}/IC_2024.o.d" -MT ${OBJECTDIR}/IC_2024.o  -o ${OBJECTDIR}/IC_2024.o IC_2024.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Switch.o: Switch.cpp  .generated_files/flags/default/68bccf79f404034490f47bbdf8b4a9e4668935e4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Switch.o.d 
	@${RM} ${OBJECTDIR}/Switch.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega16u2 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/Switch.o.d" -MT "${OBJECTDIR}/Switch.o.d" -MT ${OBJECTDIR}/Switch.o  -o ${OBJECTDIR}/Switch.o Switch.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/IC_4051.o: IC_4051.cpp  .generated_files/flags/default/822f41cb7e341f5cc4680b08ccab6b756635ed83 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/IC_4051.o.d 
	@${RM} ${OBJECTDIR}/IC_4051.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega16u2 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/IC_4051.o.d" -MT "${OBJECTDIR}/IC_4051.o.d" -MT ${OBJECTDIR}/IC_4051.o  -o ${OBJECTDIR}/IC_4051.o IC_4051.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/IC_4094.o: IC_4094.cpp  .generated_files/flags/default/7eb543d835f9c6498e5e4e7266d52b6542c93caf .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/IC_4094.o.d 
	@${RM} ${OBJECTDIR}/IC_4094.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega16u2 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS} -g -DDEBUG  -gdwarf-2  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/IC_4094.o.d" -MT "${OBJECTDIR}/IC_4094.o.d" -MT ${OBJECTDIR}/IC_4094.o  -o ${OBJECTDIR}/IC_4094.o IC_4094.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/IC_4021.o: IC_4021.cpp  .generated_files/flags/default/5a470329b077dc5d713a6088cce1560d060d00e8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/IC_4021.o.d 
	@${RM} ${OBJECTDIR}/IC_4021.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega16u2 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/IC_4021.o.d" -MT "${OBJECTDIR}/IC_4021.o.d" -MT ${OBJECTDIR}/IC_4021.o  -o ${OBJECTDIR}/IC_4021.o IC_4021.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Led.o: Led.cpp  .generated_files/flags/default/b83ff33fc016ba7948605d045218b110ab79c360 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Led.o.d 
	@${RM} ${OBJECTDIR}/Led.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega16u2 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/Led.o.d" -MT "${OBJECTDIR}/Led.o.d" -MT ${OBJECTDIR}/Led.o  -o ${OBJECTDIR}/Led.o Led.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/IC_4022.o: IC_4022.cpp  .generated_files/flags/default/1234910b88203c98de1a090076c5fce990aa6975 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/IC_4022.o.d 
	@${RM} ${OBJECTDIR}/IC_4022.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega16u2 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/IC_4022.o.d" -MT "${OBJECTDIR}/IC_4022.o.d" -MT ${OBJECTDIR}/IC_4022.o  -o ${OBJECTDIR}/IC_4022.o IC_4022.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/IC_4056.o: IC_4056.cpp  .generated_files/flags/default/8f185c36e99b33101c6daff6124b2fe35e7b75e4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/IC_4056.o.d 
	@${RM} ${OBJECTDIR}/IC_4056.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega16u2 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/IC_4056.o.d" -MT "${OBJECTDIR}/IC_4056.o.d" -MT ${OBJECTDIR}/IC_4056.o  -o ${OBJECTDIR}/IC_4056.o IC_4056.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/IC_2024.o: IC_2024.cpp  .generated_files/flags/default/edf34a6983b000bd07e529a55b8fc9b1ec0543d5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/IC_2024.o.d 
	@${RM} ${OBJECTDIR}/IC_2024.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega16u2 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/IC_2024.o.d" -MT "${OBJECTDIR}/IC_2024.o.d" -MT ${OBJECTDIR}/IC_2024.o  -o ${OBJECTDIR}/IC_2024.o IC_2024.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/Switch.o: Switch.cpp  .generated_files/flags/default/4320cf319b0c72f2183ad865feb07ad8a26f5b60 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Switch.o.d 
	@${RM} ${OBJECTDIR}/Switch.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega16u2 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/Switch.o.d" -MT "${OBJECTDIR}/Switch.o.d" -MT ${OBJECTDIR}/Switch.o  -o ${OBJECTDIR}/Switch.o Switch.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/IC_4051.o: IC_4051.cpp  .generated_files/flags/default/cb3f52c7c06b9206591f0b55709e59d777adfdf6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/IC_4051.o.d 
	@${RM} ${OBJECTDIR}/IC_4051.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega16u2 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/IC_4051.o.d" -MT "${OBJECTDIR}/IC_4051.o.d" -MT ${OBJECTDIR}/IC_4051.o  -o ${OBJECTDIR}/IC_4051.o IC_4051.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/IC_4094.o: IC_4094.cpp  .generated_files/flags/default/568207c1a153f81b5f5bcd303fc0e8a0d3050197 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/IC_4094.o.d 
	@${RM} ${OBJECTDIR}/IC_4094.o 
	 ${MP_CPPC} $(MP_EXTRA_CC_PRE) -mmcu=atmega16u2 ${PACK_COMPILER_OPTIONS} ${PACK_COMMON_OPTIONS}  -x c++ -c -D__$(MP_PROCESSOR_OPTION)__  -funsigned-char -funsigned-bitfields -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -Wall -MD -MP -MF "${OBJECTDIR}/IC_4094.o.d" -MT "${OBJECTDIR}/IC_4094.o.d" -MT ${OBJECTDIR}/IC_4094.o  -o ${OBJECTDIR}/IC_4094.o IC_4094.cpp  -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: archive
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/IC_Library.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_AR} $(MP_EXTRA_AR_PRE) -r -o ${DISTDIR}/IC_Library.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}   
else
${DISTDIR}/IC_Library.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_AR} $(MP_EXTRA_AR_PRE) -r -o ${DISTDIR}/IC_Library.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}   
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
