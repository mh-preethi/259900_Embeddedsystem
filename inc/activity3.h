#ifndef _ACTIVITY3_H_
#define _ACTIVITY3_H_
/**
 * @brief Function to initialize PWM
 *
 */
void InitializePWM(void);

/**
 * @brief Function to Generate PWM
 *
 * @param[in] Temperature input temperature obtained from ADC
 * @return TempToCAN
 */
char GeneratePWM(uint16_t);
#endif  /* _ACTIVITY3_H_ */