#include <stdio.h>

#define ADC_MAX 4095
#define V_REF 3.3f

int main(void) {
    int adc_raw = 2048;

    // #region snippet1
    float wrong = adc_raw / ADC_MAX * V_REF;          // 2048 / 4095 is 0
    float right = (float)adc_raw / ADC_MAX * V_REF;   // real division
    // #endregion snippet1

    printf("Raw value: %d\n", adc_raw);
    printf("Wrong voltage: %.2f V\n", wrong);
    printf("Right voltage: %.2f V\n", right);
    return 0;
}
