/*
 * nexys_gpio_drv.c
 *
 *  Created on: Dec 22, 2022
 *      Author: user
 */

#include "public/nexys_gpio_drv_v1.h"
#include "public/edroombp.h"

Pr_Mutex GPIO_LEDS_Mutex;

volatile struct nexys_srg_gpio_regs_t *const p_nexys_gpio_buttons_switches =
		(struct nexys_srg_gpio_regs_t*) 0x80000900;

volatile struct nexys_srg_gpio_regs_t *const p_nexys_gpio_leds_7segs =
		(struct nexys_srg_gpio_regs_t*) 0x80000A00;

uint8_t digit7segCode[16] = { 0x03, 0x9F, 0x25, 0x0D, 0x99, 0x49, 0x41, 0x1F,
		0x01, 0x09, 0x11, 0xC1, 0xE5, 0x85, 0x61, 0x71 };

void nexys_srg_gpio_set_7seg_digit(uint8_t seg_index, uint8_t digit) {

	if (seg_index < 8) {
		seg_index = 7 - seg_index;
		if (digit < 10) {
			uint32_t digit_ctrl = digit7segCode[digit]; //Digit in 7seg
			uint32_t current_val, next_val;
			digit_ctrl = (digit_ctrl << 8) | ((~(0x01 << seg_index)) & 0xFF);
			GPIO_LEDS_Mutex.Wait();
			current_val = p_nexys_gpio_leds_7segs->gp_output & 0xFFC00000;
			next_val = current_val | digit_ctrl;
			p_nexys_gpio_leds_7segs->gp_output = next_val;
			GPIO_LEDS_Mutex.Signal();
		}
	}

}

void nexys_srg_gpio_set_7seg_hexdigit(uint8_t seg_index, uint8_t digit) {

	if (seg_index < 8) {
		seg_index = 7 - seg_index;
		if (digit < 16) {
			uint32_t digit_ctrl = digit7segCode[digit]; //Digit in 7seg
			uint32_t current_val, next_val;
			digit_ctrl = (digit_ctrl << 8) | ((~(0x01 << seg_index)) & 0xFF);

			GPIO_LEDS_Mutex.Wait();
			current_val = p_nexys_gpio_leds_7segs->gp_output & 0xFFC00000;
			next_val = current_val | digit_ctrl;
			p_nexys_gpio_leds_7segs->gp_output = next_val;
			GPIO_LEDS_Mutex.Signal();
		}
	}

}

void nexys_srg_gpio_seg_7seg_hexdigit_array(uint8_t digit_number,
		uint8_t digit[4]) {

	uint8_t i;

	if (digit_number > 4)
		digit_number = 4;

	for (i = 0; i < digit_number; i++) {

		nexys_srg_gpio_set_7seg_hexdigit(i * 2, (digit[i] >> 4));
		nexys_srg_gpio_set_7seg_hexdigit(i * 2 + 1, digit[i] & 0x0F);

	}

}

void nexys_srg_gpio_seg_7seg_array(uint8_t digit_number, uint8_t digit[8]) {

	uint8_t i;
	int first_digit = 0;
	//static uint8_t refresh_ctrl=8;
	//Valor de los displays
	for (i = 0; i < 8; i++) {
		if (digit[i] != 0)
			first_digit = i;
		if (first_digit)
			nexys_srg_gpio_set_7seg_digit(i, digit[i]);
	}
	//refresh_ctrl=(refresh_ctrl + 1)%9;
}

void nexys_srg_gpio_clear_seg_7seg_array(uint8_t digit_array[8]) {

	uint8_t i;

	for (i = 0; i < 8; i++) {

		digit_array[0] = 0;

	}

}

void nexys_srg_gpio_increase_seg_7seg_array(uint8_t digit_array[8]) {

	uint8_t end = 0;
	uint8_t index = 7;
	while (!end) {
		if (digit_array[index] < 9) {
			digit_array[index]++;
			end = 1;
		} else {
			digit_array[index] = 0;
			if (0 == index) {
				nexys_srg_gpio_clear_seg_7seg_array(digit_array);
				end = 1;
			} else {
				index--;
			}

		}
	}

}

void nexys_srg_gpio_init_buttons_switches() {

	GPIO_LEDS_Mutex.Wait();
	p_nexys_gpio_buttons_switches->gp_direction = 0x0; //All Buttons and switches
	//GPIO pines are inputs
	p_nexys_gpio_buttons_switches->gp_imask = 0x0; //All Buttons and switches
	//GPIO interrupts are masked

	p_nexys_gpio_buttons_switches->gp_edge = 0x0; //Level sensitive by default

	p_nexys_gpio_buttons_switches->gp_polarity = 0xFFFFFFFF; //Positive level by default
	GPIO_LEDS_Mutex.Signal();

}

void nexys_srg_gpio_init_leds_7segs_displays() {

	GPIO_LEDS_Mutex.Wait();

	p_nexys_gpio_leds_7segs->gp_direction = 0xFFFFFFFF; //All Leds and 7 SegsDisplays
	//GPIO pines are outputs
	p_nexys_gpio_leds_7segs->gp_imask = 0x0; //All GPIO interrupts are masked

	p_nexys_gpio_leds_7segs->gp_output = 0x00; //All are off at init.

	p_nexys_gpio_leds_7segs->gp_edge = 0; //Level sensitive

	p_nexys_gpio_leds_7segs->gp_polarity = 0; //Negative level by default

	GPIO_LEDS_Mutex.Signal();

}

void nexys_srg_gpio_turn_on_led(uint8_t led_number) {

	if (led_number < 10) {
		uint32_t mask = 0x01 << (led_number + 22);
		GPIO_LEDS_Mutex.Wait();
		p_nexys_gpio_leds_7segs->gp_output |= mask;
		GPIO_LEDS_Mutex.Signal();
	}
}
void nexys_srg_gpio_turn_off_led(uint8_t led_number) {

	if (led_number < 10) {
		uint32_t mask = 0x01 << (led_number + 22);
		GPIO_LEDS_Mutex.Wait();
		p_nexys_gpio_leds_7segs->gp_output &= (~mask);
		GPIO_LEDS_Mutex.Signal();
	}
}

uint8_t nexys_srg_gpio_config_button_irq(enum gpio_buttons_t button_id,
		enum gpio_irq_pol_t pol, enum gpio_irq_edge_t edge) {

	uint8_t error = 0;
	uint32_t mask = 0x01 << (button_id + 16);

	GPIO_LEDS_Mutex.Wait();
	if (0 == pol)
		p_nexys_gpio_buttons_switches->gp_polarity &= (~mask);
	else
		p_nexys_gpio_buttons_switches->gp_polarity |= (mask);

	if (0 == edge)
		p_nexys_gpio_buttons_switches->gp_edge &= (~mask);
	else
		p_nexys_gpio_buttons_switches->gp_edge |= (mask);

	GPIO_LEDS_Mutex.Signal();

	return error;
}

uint8_t nexys_srg_gpio_config_switch_irq(uint8_t switch_number,
		enum gpio_irq_pol_t pol, enum gpio_irq_edge_t edge) {

	uint8_t error = 0;
	uint32_t mask = 0x01 << switch_number;

	if (switch_number > 15)
		error = 1;
	else {
		GPIO_LEDS_Mutex.Wait();
		if (0 == pol)
			p_nexys_gpio_buttons_switches->gp_polarity &= (~mask);
		else
			p_nexys_gpio_buttons_switches->gp_polarity |= (mask);

		if (0 == edge)
			p_nexys_gpio_buttons_switches->gp_edge &= (~mask);
		else
			p_nexys_gpio_buttons_switches->gp_edge |= (mask);
		GPIO_LEDS_Mutex.Signal();
	}
	return error;

}

uint8_t nexys_srg_gpio_enable_button_irq(enum gpio_buttons_t button_id) {

	uint8_t error = 0;
	uint32_t mask = 0x01 << (button_id + 16);

	GPIO_LEDS_Mutex.Wait();
	p_nexys_gpio_buttons_switches->gp_imask |= (mask);
	GPIO_LEDS_Mutex.Signal();
	return error;
}

uint8_t nexys_srg_gpio_disable_button_irq(enum gpio_buttons_t button_id) {

	uint8_t error = 0;
	uint32_t mask = 0x01 << (button_id + 16);

	GPIO_LEDS_Mutex.Wait();
	p_nexys_gpio_buttons_switches->gp_imask &= (~mask);
	GPIO_LEDS_Mutex.Signal();

	return error;
}

uint8_t nexys_srg_gpio_enable_switch_irq(uint8_t switch_number) {

	uint8_t error = 0;
	uint32_t mask = 0x01 << switch_number;

	if (switch_number > 15)
		error = 1;
	else {
		GPIO_LEDS_Mutex.Wait();
		p_nexys_gpio_buttons_switches->gp_imask |= (mask);
		GPIO_LEDS_Mutex.Signal();
	}

	return error;
}

uint8_t nexys_srg_gpio_disable_switch_irq(uint8_t switch_number) {

	uint8_t error = 0;
	uint32_t mask = 0x01 << switch_number;

	if (switch_number > 15)
		error = 1;
	else {
		GPIO_LEDS_Mutex.Wait();
		p_nexys_gpio_buttons_switches->gp_imask &= (~mask);
		GPIO_LEDS_Mutex.Signal();
	}

	return error;

}

uint8_t nexys_srg_gpio_is_switch_on(uint8_t switch_number) {

	uint8_t is_on = 0;

	if (switch_number <= 15) {
		uint32_t mask = 0x01 << switch_number;
		GPIO_LEDS_Mutex.Wait();
		is_on = (p_nexys_gpio_buttons_switches->gp_input & mask) != 0;
		GPIO_LEDS_Mutex.Signal();
	}

	return is_on;

}
