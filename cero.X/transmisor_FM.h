/* 
 * File:   transmisor_FM.h
 * Author: franco
 *
 * Created on August 4, 2016, 10:20 AM
 */

#ifndef TRANSMISOR_FM_H
#define	TRANSMISOR_FM_H

#ifdef	__cplusplus
extern "C" {
#endif

    //*************************************************************************************************
    // Includes
    //*************************************************************************************************    
        #include <dsp.h>
        #include "defines.h"

        extern FIRStruct NotchFilter;  /*Contains filter structures for FIR-LPF*/
    //*************************************************************************************************
    // Prototipos
    //*************************************************************************************************    
       

        extern void IIRTransposedInit(IIRTransposedStruct* filter);

        extern fractional* FIR(int numSamps,fractional* dstSamps,fractional* srcSamps,FIRStruct* filter);
        extern fractional* IIRTransposed(int numSamps, fractional* dstSamps, fractional* srcSamps, IIRTransposedStruct* filter);
        //    IIRTransposed (numSamps,*dstSamps,*srcSamps,*filter) || biquad filtering
        //                                        
        //    numSamps || number of input samples (N)
        //    dstSamps || ptr to output samples (y[n], 0 <= n < N)
        //    srcSamps || ptr to input samples (x[n], 0 <= n < N)
        //    filter   || Transposed biquad filter structure
        //    returns dstSamps

        extern fractional* VectorAdd (int numElems, fractional* dstV, fractional* srcV1, fractional* srcV2);
        //fractional* VectorAdd (int numElems, fractional* dstV, fractional* srcV1, fractional* srcV2);
        //
        //numElems number of elements in source vector
        //dstV pointer to destination vector
        //srcV1 pointer to source one vector
        //srcV2 pointer to source two vector

        extern fractional* VectorMultiply (int numElems, fractional* dstV, fractional* srcV1, fractional* srcV2);
        //fractional* VectorMultiply (int numElems, fractional* dstV, fractional* srcV1, fractional* srcV2)
        //
        //numElems number of elements in source vector
        //dstV pointer to destination vector
        //srcV1 pointer to source one vector
        //srcV2 pointer to source two vector

        extern fractional* VectorCopy (int numElems,fractional* dstV,fractional* srcV);
        //extern fractional* VectorCopy (int numElems,fractional* dstV,fractional* srcV);
        //
        //numElems number of elements in source vector
        //dstV pointer to destination vector
        //srcV pointer to source one vector

        extern fractional* VectorScale (int numElems,fractional* dstV,fractional* srcV,fractional sclVal);
        //extern fractional* VectorScale (int numElems,fractional* dstV,fractional* srcV,fractional sclVal);
        //
        //numElems number of elements in source vector
        //dstV pointer to destination vector
        //srcV pointer to source one vector
//        sclVal value by which to scale vector elements

        

        void ArmadoMPX(int numElements, fractional*Dest_samples, fractional*L_channel, fractional*R_channel);
        //extern void ArmadoMPX (int numElements, fractional*Dest_samples, fractional*L_channel, fractional*R_channel);
        // Arma la trama FM estereo  aggguuuuaaaannnntiiiiiaaaaaa!!
        //numElements number of elements in source vector
        //Dest_samples pointer to destination vector
        //L_channel pointer to source one vector
        //R_channel pointer to source one vector
        
        void Init_DSP(void);
        // Inicializa el DSP con frecuencia de 40MHz 
    
#ifdef	__cplusplus
}
#endif

#endif	/* TRANSMISOR_FM_H */

