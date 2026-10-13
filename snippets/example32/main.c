#include <stdint.h>
#include <stdio.h>

// #region snippet1
// 16-bit frame from a sensor board:
// bits 15..12 = sensor id (4 bits), bits 11..0 = ADC value (12 bits)
#define ID_SHIFT 12
#define ID_MASK  0x0Fu
#define VAL_MASK   0x0FFFu
// #endregion snippet1

int main(void) {
    // #region snippet2
    uint16_t frame = 0x5A3C;

    uint8_t id = (frame >> ID_SHIFT) & ID_MASK;
    uint16_t raw = frame & VAL_MASK;
    double volts = raw * 3.3 / 4095.0;

    printf("frame     = 0x%04X\n", frame);
    printf("sensor id = %u\n", id);
    printf("raw value = %u\n", raw);
    printf("voltage   = %.3f V\n", volts);

    // build a frame from its fields
    uint16_t new_frame = (2u << ID_SHIFT) | raw;
    printf("new frame = 0x%04X\n", new_frame);
    // #endregion snippet2

    return 0;
}
