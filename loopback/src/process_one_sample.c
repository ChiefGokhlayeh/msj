/***********************************************************************

 process_one_sample.c

 author    Uli Sauvagerd
 date      20-Apr-20
 revision  1.0

 hardware  D.Module.ADDA8M12 +  D.Module2.C6747

 compiler  CCS 5.50

 history   1.0 initial release 20-Apr-20 by US

 allows to process ADC signal left_in sample-based

           Errors:
           Corrections:
           Comments:

***********************************************************************/

#include <stdio.h>  // for printf
#include <math.h>   // for sin/cos
#include <stdlib.h> // for FILE*
#include "gen/bandpass.h"
//#include "hilbert_coeff.h"
#include "processor.h"

// Alle Variablen sind i.d.Regel global, daher über "extern" bekannt machen
extern FILE *fid_DAC_data;
extern short left_in;
extern short y_cpfsk_out; // Extern zu main();

static short fir_delays[sizeof(bp_coeff_num[0]) / sizeof(bp_coeff_num[0][0])] = {0};

// prototype
void process_one_sample();
// Diese Variable werden nur in dieser Funktion verwendet

short FIR_filter_sc(short *, const short *, int, short, short);

// function body
void process_one_sample()
{
#if defined(USE_GCC_ANSI_C_SIM) || defined(USE_MSVC_ANSI_C_SIM)
    y_cpfsk_out = FIR_filter_sc(fir_delays,
                                bp_coeff_num[0],
                                sizeof(bp_coeff_num[0]) / sizeof(bp_coeff_num[0][0]),
                                left_in, 8);
#else
    y_cpfsk_out = left_in;
#endif
}
