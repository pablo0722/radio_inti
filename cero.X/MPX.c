
// *******************************
// Trama FM estereo
// *******************************
//           
//    _____  |  _____  :  _____
// |_/ L+R \_|_/ L-R \_:_/ L-R \_
// 0        19KHz     38KHz
// *******************************
#include "transmisor_FM.h"

//*************************************************************************************************
// Variables globales declaradas en el main
//*************************************************************************************************        
 extern fractional* piloto_pablo;
 extern fractional* subportadora;

void ArmadoMPX(int numElements, fractional*Dest_samples, fractional*L_channel, fractional*R_channel){
    
    fractional dst_L_sum_R[numElements],dst_L_res_R[numElements],trama_sin_port[numElements];
    
    // ARMADO DE MPX
    
    // suma L+R
    VectorAdd(numElements,dst_L_sum_R,L_channel,R_channel);
    
    // resta, aclaración: a - b = a + (-1)*b
    VectorScale(numElements,dst_L_res_R,R_channel,-1);
    
    // suma L-R
    
    VectorAdd(numElements,dst_L_res_R,L_channel,R_channel);
    
    // L-R transladado en frecuencia
    
    VectorMultiply(numElements,dst_L_res_R,subportadora,dst_L_res_R);
    
    // Sumamos los canales transladados en frecuencia
    
    VectorAdd(numElements,trama_sin_port,dst_L_sum_R,dst_L_res_R);
    
    // agregamos la portadora a la trama de FM
    
    VectorAdd(numElements,Dest_samples,piloto_pablo,trama_sin_port);

        
}