#ifndef _ACTIVITY2_H_
#define _ACTIVITY2_H_


/**
 * @brief Function to initialize ADC
 *
 */
void InitializeADC();

/**
 * @brief Function to read values from a channel
 * @param[in] channel channel number
 */
uint16_t ReadADC(uint8_t channel);

#endif /* _ACTIVITY2_H_ */