#include "stm32h750xx.h"

extern void vog_Dsp_CalSignalMean(float *pf32_Signal, uint16_t u16_Length, float *pf32_Mean);
extern void vog_Dsp_CalVariance(float *pf32_Signal, uint16_t u16_Length, float f32_Mean, float *pf32_Deviation);
extern void vog_Dsp_CalStandardDeviation(float *pf32_Signal, uint16_t u16_Length, float f32_Mean, float *pf32_StandardDeviation);

/* EOF */
