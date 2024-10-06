#ifndef CONFIG_H
#define	CONFIG_H

//-----------------------------------------------------------------------------------------------------------------------------------
// ATmega16U2 Configuration Bit Settings

// 'C' source line config statements

#include <avr/io.h>

FUSES = {
	.low = 0xFF, // LOW {SUT_CKSEL=EXTXOSC_8MHZ_XX_16KCK_65MS, CKOUT=CLEAR, CKDIV8=CLEAR}
	//.high = 0xDB, // HIGH {BOOTRST=CLEAR, BOOTSZ=1024W_1C00, EESAVE=CLEAR, WDTON=CLEAR, SPIEN=SET, RSTDISBL=CLEAR, DWEN=CLEAR}
    .high = 0x5B, // HIGH {BOOTRST=CLEAR, BOOTSZ=1024W_1C00, EESAVE=CLEAR, WDTON=CLEAR, SPIEN=SET, RSTDISBL=CLEAR, DWEN=SET}
	.extended = 0xF4, // EXTENDED {BODLEVEL=3V0, HWBE=SET}
};

LOCKBITS = 0xFF; // {LB=NO_LOCK, BLB0=NO_LOCK, BLB1=NO_LOCK}
//----------------------------------------------------------------------------------------------------------------------------------

#endif	/* CONFIG_H */