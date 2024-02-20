/*
 * nexys_gpio_drv.h
 *
 *  Created on: Dec 22, 2022
 *      Author: user
 */

#ifndef NEXYS_GPIO_DRV_H_
#define NEXYS_GPIO_DRV_H_

#include "public/basic_types.h"

#ifdef __cplusplus

extern "C" {

#endif
enum gpio_irq_pol_t {
	irq_active_low = 0, irq_active_high = 1
};
enum gpio_irq_edge_t {
	irq_level = 0, irq_edge = 1
};

enum gpio_buttons_t {
	buttonCentre = 0,
	buttonUp = 1,
	buttonLeft = 2,
	buttonRight = 3,
	buttonDown = 4
};

/** \brief GPIO Registers */
struct nexys_srg_gpio_regs_t {

	volatile uint32_t gp_input;
	volatile uint32_t gp_output;
	volatile uint32_t gp_direction;
	volatile uint32_t gp_imask;
	volatile uint32_t gp_polarity;
	volatile uint32_t gp_edge;
};

/** \brief Init buttons and switches
 *
 */
void nexys_srg_gpio_init_buttons_switches();

/** \brief Init leds and 7segs displays
 *
 */
void nexys_srg_gpio_init_leds_7segs_displays();

/** \brief Turn on led
 *
 *	\param led_number led number
 *
 */
void nexys_srg_gpio_turn_on_led(uint8_t led_number);

/** \brief Turn off led
 *
 *	\param led_number led number
 *
 */
void nexys_srg_gpio_turn_off_led(uint8_t led_number);

/** \brief Set the segments of a 7seg display to show a digit
 *
 *	\param index index of the 7seg display
 *	\param digit digit to display
 *
 */
void nexys_srg_gpio_set_7seg_digit(uint8_t index, uint8_t digit);

/** \brief Set the segments of a 7seg display to show a digit in hexadecimal
 *
 *	\param index index of the 7seg display
 *	\param digit digit to display
 *
 */
void nexys_srg_gpio_set_7seg_hexdigit(uint8_t seg_index, uint8_t digit);

/** \brief Set the segments of the 7seg displays to show an array of digits
 *   in hexadecimal. Maximum of digits is 4.
 *
 *	\param digit_number is the number of digits to show
 *	\param digit is the array of digits
 *
 */
void nexys_srg_gpio_seg_7seg_hexdigit_array(uint8_t digit_number,
		uint8_t digit[4]);

/** \brief Set the segments of the 7seg displays to show an array of digits
 *   Maximum of digits is 8.
 *
 *	\param digit_number is the number of digits to show
 *	\param digit is the array of digits
 *
 */
void nexys_srg_gpio_seg_7seg_array(uint8_t digit_number,
		uint8_t digit[8]);

/** \brief Clear the values of an array of digits
 *
 *	\param digit_array is the array of digits
 *
 */
void nexys_srg_gpio_clear_seg_7seg_array(uint8_t digit_array[8]);

/** \brief Increase the values of an array of digits
 *
 *	\param digit_array is the array of digits
 *
 */
void nexys_srg_gpio_increase_seg_7seg_array(uint8_t digit_array[8]);

/** \brief config button interrupt
 *
 *	\param button_id button identifier
 *	\param pol polarity. See enum gpio_irq_pol_t
 *	\param edge edge that triggers the interrupt. See gpio_irq_edge_t
 *
 *	\return 0 if there is no error, 1 if not
 */
uint8_t nexys_srg_gpio_config_button_irq(enum gpio_buttons_t button_id,
		enum gpio_irq_pol_t pol, enum gpio_irq_edge_t edge);

/** \brief config switch interrupt
 *
 *	\param button_id button identifier
 *	\param pol polarity. See enum gpio_irq_pol_t
 *	\param edge edge that triggers the interrupt. See gpio_irq_edge_t
 *
 *	\return 0 if there is no error, 1 if not
 */
uint8_t nexys_srg_gpio_config_switch_irq(uint8_t switch_number,
		enum gpio_irq_pol_t pol, enum gpio_irq_edge_t edge);

/** \brief enable button irq
 *
 *	\param button_id button identifier
 *
 *	\return 0 if there is no error, 1 if not
 */
uint8_t nexys_srg_gpio_enable_button_irq(enum gpio_buttons_t button_id);

//disable button irq
/** \brief disable button irq
 *
 *	\param button_id button identifier
 *
 *	\return 0 if there is no error, 1 if not
 */
uint8_t nexys_srg_gpio_disable_button_irq(enum gpio_buttons_t button_id);

//enable switch irq
uint8_t nexys_srg_gpio_enable_switch_irq(uint8_t switch_number);
//disable switch irq
uint8_t nexys_srg_gpio_disable_switch_irq(uint8_t switch_number);

uint8_t nexys_srg_gpio_is_switch_on(uint8_t switch_number);

#ifdef __cplusplus

}

#endif
#endif /* NEXYS_GPIO_DRV_H_ */
