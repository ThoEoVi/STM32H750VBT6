#include "Dsp_if.h"
#include "usbd_cdc_if.h"
#include "Data_if.h"

void vog_Dsp_CalSignalMean(float *pf32_Signal, uint16_t u16_Length, float *pf32_Mean)
{
    uint16_t SamplePointIdx;
    float f32_Sum;

    /* Init variables */
    f32_Sum = 0.0f;

    /* Cal sum */
    for ( SamplePointIdx = 0; SamplePointIdx < u16_Length; SamplePointIdx++ )
    {
        f32_Sum += pf32_Signal[SamplePointIdx];
    }

    /* Calculate the mean value */
    *pf32_Mean = f32_Sum / (float)u16_Length;

    return;
}

void vog_Dsp_CalVariance(float *pf32_Signal, uint16_t u16_Length, float f32_Mean, float *pf32_Variance)
{
    uint16_t SamplePointIdx;
    float f32_Sum;

    /* Init variables */
    f32_Sum = 0.0f;

    /* Cal sum */
    for ( SamplePointIdx = 0; SamplePointIdx < u16_Length; SamplePointIdx++ )
    {
        f32_Sum += (pf32_Signal[SamplePointIdx] - f32_Mean) * (pf32_Signal[SamplePointIdx] - f32_Mean);
    }

    /* Calculate the variance */
    *pf32_Variance = f32_Sum / ((float)u16_Length - 1.0f);

    return;
}

void vog_Dsp_CalStandardDeviation(float *pf32_Signal, uint16_t u16_Length, float f32_Mean, float *pf32_StandardDeviation)
{
    float f32_Variance;

    /* Calculate variance */
    vog_Dsp_CalVariance(pf32_Signal, u16_Length, f32_Mean, &f32_Variance);

    /* Calculate standard deviation */
    *pf32_StandardDeviation = sqrtf(f32_Variance);

    return;
}

/* EOF */

/*
uint8_t u1a_Data[255U];
    uint8_t u1a_Data_1[255U];
    for (uint16_t i = 0; i < U1L_DATA_f32_1kHz_15kHz_LENGTH; i++)
    {
      for (uint16_t j = 0; j < 255U; j++)
      {
        u1a_Data[j] = '\0';
        u1a_Data_1[j] = '\0';
      }
      sprintf( (char*)u1a_Data, "%.2f,", inputSignal_f32_1kHz_15kHz[i] );
      (void)CDC_Transmit_FS(u1a_Data, strlen((char*)u1a_Data));
      sprintf( (char*)u1a_Data_1, "%.2f\r\n", inputSignal_f32_1kHz_15kHz[i]+10.0f );
      (void)CDC_Transmit_FS(u1a_Data_1, strlen((char*)u1a_Data)+2);
      HAL_Delay(10);
    }

*/
