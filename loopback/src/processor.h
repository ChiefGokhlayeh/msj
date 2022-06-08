/***********************************************************************

 processor.h

 Steuerdatei für Wetterdaten_Antenne Projekt

 author    Uli Sauvagerd
 date      15-Dez-19, revised 13-Mar-22
 revision  1.0

 hardware  D.Module.ADDA8M12 +  D.Module2.C6747

 compiler  CCS 5.50

 history   1.0 initial release 17-Jun-19 by US

 13-Mar-22 : DAC EDMA can now be turned on/off, default ON

***********************************************************************/

//#define USE_HARDWARE_ADDA8M12_C6747
//#define USE_MSVC_ANSI_C_SIM
#define USE_GCC_ANSI_C_SIM

// dieses Macro erstmal verwenden, spaeter wird die EDMA fuer den DAC damit abgeschaltet#ifdef
#ifdef USE_HARDWARE_ADDA8M12_C6747
#define USE_DAC_EDMA_C6747
#endif

#ifdef USE_MSVC_ANSI_C_SIM
#define _CRT_SECURE_NO_WARNINGS
#endif

// #define USE_HILBERT
#define USE_COMB
