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
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/RealFinalProject.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/RealFinalProject.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../Main.c ../Button.c ../ButtonLibrary.c ../LCD_Lib.c ../MorseCodeLib.c ../UART_Adafruit.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1472/Main.o ${OBJECTDIR}/_ext/1472/Button.o ${OBJECTDIR}/_ext/1472/ButtonLibrary.o ${OBJECTDIR}/_ext/1472/LCD_Lib.o ${OBJECTDIR}/_ext/1472/MorseCodeLib.o ${OBJECTDIR}/_ext/1472/UART_Adafruit.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1472/Main.o.d ${OBJECTDIR}/_ext/1472/Button.o.d ${OBJECTDIR}/_ext/1472/ButtonLibrary.o.d ${OBJECTDIR}/_ext/1472/LCD_Lib.o.d ${OBJECTDIR}/_ext/1472/MorseCodeLib.o.d ${OBJECTDIR}/_ext/1472/UART_Adafruit.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1472/Main.o ${OBJECTDIR}/_ext/1472/Button.o ${OBJECTDIR}/_ext/1472/ButtonLibrary.o ${OBJECTDIR}/_ext/1472/LCD_Lib.o ${OBJECTDIR}/_ext/1472/MorseCodeLib.o ${OBJECTDIR}/_ext/1472/UART_Adafruit.o

# Source Files
SOURCEFILES=../Main.c ../Button.c ../ButtonLibrary.c ../LCD_Lib.c ../MorseCodeLib.c ../UART_Adafruit.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/RealFinalProject.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ64GA002
MP_LINKER_FILE_OPTION=,--script=p24FJ64GA002.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1472/Main.o: ../Main.c  .generated_files/flags/default/15658dba79ac95c4133005c552978360e43b58d7 .generated_files/flags/default/872955d66890500c2e764fa2ba671a156326d720
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Main.c  -o ${OBJECTDIR}/_ext/1472/Main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/Main.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/Button.o: ../Button.c  .generated_files/flags/default/23fa9179c102daa475d022ef9b45f6dcf495d690 .generated_files/flags/default/872955d66890500c2e764fa2ba671a156326d720
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Button.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Button.c  -o ${OBJECTDIR}/_ext/1472/Button.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/Button.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/ButtonLibrary.o: ../ButtonLibrary.c  .generated_files/flags/default/80193d2b56ede92d4e72fe316be073355a5ba3d3 .generated_files/flags/default/872955d66890500c2e764fa2ba671a156326d720
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ButtonLibrary.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ButtonLibrary.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ButtonLibrary.c  -o ${OBJECTDIR}/_ext/1472/ButtonLibrary.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/ButtonLibrary.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/LCD_Lib.o: ../LCD_Lib.c  .generated_files/flags/default/5284a3c89f4303b06c2af63ed75de549a913f988 .generated_files/flags/default/872955d66890500c2e764fa2ba671a156326d720
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/LCD_Lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/LCD_Lib.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../LCD_Lib.c  -o ${OBJECTDIR}/_ext/1472/LCD_Lib.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/LCD_Lib.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/MorseCodeLib.o: ../MorseCodeLib.c  .generated_files/flags/default/38113cae8e7bc6454f9d8bf34d0a651ee25cbb25 .generated_files/flags/default/872955d66890500c2e764fa2ba671a156326d720
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/MorseCodeLib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/MorseCodeLib.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../MorseCodeLib.c  -o ${OBJECTDIR}/_ext/1472/MorseCodeLib.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/MorseCodeLib.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/UART_Adafruit.o: ../UART_Adafruit.c  .generated_files/flags/default/870f14ff232a3d236ba613008f5af8af3933822d .generated_files/flags/default/872955d66890500c2e764fa2ba671a156326d720
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/UART_Adafruit.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/UART_Adafruit.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../UART_Adafruit.c  -o ${OBJECTDIR}/_ext/1472/UART_Adafruit.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/UART_Adafruit.o.d"      -g -D__DEBUG     -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/_ext/1472/Main.o: ../Main.c  .generated_files/flags/default/7b57387e68405d9bee9e7a869bf70850228f8f14 .generated_files/flags/default/872955d66890500c2e764fa2ba671a156326d720
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Main.c  -o ${OBJECTDIR}/_ext/1472/Main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/Main.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/Button.o: ../Button.c  .generated_files/flags/default/f396f2ae66baffdc690b84f5b2b25b993c711252 .generated_files/flags/default/872955d66890500c2e764fa2ba671a156326d720
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/Button.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Button.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../Button.c  -o ${OBJECTDIR}/_ext/1472/Button.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/Button.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/ButtonLibrary.o: ../ButtonLibrary.c  .generated_files/flags/default/f5c68d6d19558ab0ed333e54faebdfb463461116 .generated_files/flags/default/872955d66890500c2e764fa2ba671a156326d720
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/ButtonLibrary.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ButtonLibrary.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../ButtonLibrary.c  -o ${OBJECTDIR}/_ext/1472/ButtonLibrary.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/ButtonLibrary.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/LCD_Lib.o: ../LCD_Lib.c  .generated_files/flags/default/25f8fd487c74d945801458742c73febd11f8f834 .generated_files/flags/default/872955d66890500c2e764fa2ba671a156326d720
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/LCD_Lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/LCD_Lib.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../LCD_Lib.c  -o ${OBJECTDIR}/_ext/1472/LCD_Lib.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/LCD_Lib.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/MorseCodeLib.o: ../MorseCodeLib.c  .generated_files/flags/default/e0bcd94453df160cd0325c3923df695444266d7b .generated_files/flags/default/872955d66890500c2e764fa2ba671a156326d720
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/MorseCodeLib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/MorseCodeLib.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../MorseCodeLib.c  -o ${OBJECTDIR}/_ext/1472/MorseCodeLib.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/MorseCodeLib.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/_ext/1472/UART_Adafruit.o: ../UART_Adafruit.c  .generated_files/flags/default/d8cb4ef884172130dcfa22d23b9ac4ffacfe2b79 .generated_files/flags/default/872955d66890500c2e764fa2ba671a156326d720
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/UART_Adafruit.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/UART_Adafruit.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../UART_Adafruit.c  -o ${OBJECTDIR}/_ext/1472/UART_Adafruit.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1472/UART_Adafruit.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/RealFinalProject.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/RealFinalProject.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/RealFinalProject.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/RealFinalProject.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/RealFinalProject.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
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

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
