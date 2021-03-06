/*
 Femtin V0.0.1 - Copyright (C) 2015 Nicolas Boutin.
 All rights reserved

 This file is part of the Femtin distribution.

 Femtin is free software; you can redistribute it and/or modify it under
 the terms of the GNU General Public License (version 2) as published by the
 Free Software Foundation.

 Femtin is distributed in the hope that it will be useful, but WITHOUT ANY
 WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.
 */

/// ================================================================================================
///
/// \file	motor.cpp
///	\brief	
///	\date	29/10/2015
/// \author	nboutin
///
/// ================================================================================================
#include "motor.hpp"
using namespace application::drive;

/// === Includes	================================================================================

#include "portable/pinout_mapping.hpp"

/// === Namespaces	================================================================================

using namespace board;

/// === Constants	================================================================================
/// === Public Definitions	========================================================================

Motor::Motor()
		: TIM_handle_(), TIM_OC_config_()
{

}

///	------------------------------------------------------------------------------------------------

bool Motor::initialize()
{
	/// --- Clocks
	MOTOR_PWM_CLK_ENABLE();

	///	--- GPIOs

	/// Motor right enable
	GPIO_InitTypeDef GPIO_init;
	GPIO_init.Pin = MOTOR_RIGHT_ENABLE_PIN;
	GPIO_init.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_init.Pull = GPIO_PULLUP;
	GPIO_init.Speed = GPIO_SPEED_LOW;
	HAL_GPIO_Init(const_cast<GPIO_TypeDef*>(MOTOR_RIGHT_ENABLE_GPIO_PORT), &GPIO_init);
	forward();

	/// Motor right PWM
	GPIO_init.Mode = GPIO_MODE_AF_PP;
	GPIO_init.Pull = GPIO_PULLUP;
	GPIO_init.Speed = GPIO_SPEED_HIGH;
	GPIO_init.Alternate = GPIO_AF2_TIM3;
	GPIO_init.Pin = MOTOR_PWM_RIGHT_PIN;
	HAL_GPIO_Init(const_cast<GPIO_TypeDef*>(MOTOR_PWM_RIGHT_GPIO_PORT), &GPIO_init);

	///	--- Timer

	/// timer_tick_frequency = Timer_default_frequency / (prescaller_set + 1)
	/// timer_tick_frequency = 84000000 / (0 + 1) = 84000000
	/// PWM_frequency = timer_tick_frequency / (TIM_Period + 1)
	///	TIM_Period = timer_tick_frequency / PWM_frequency - 1
	/// In our case, for 10Khz PWM_frequency, set Period to
	/// TIM_Period = 84000000 / 10000 - 1 = 8399

	TIM_handle_.Instance = const_cast<TIM_TypeDef*>(MOTOR_PWM_TIMER);
	TIM_handle_.Init.Prescaler = 0;
	TIM_handle_.Init.Period = 8399;    /// 10kHz
	TIM_handle_.Init.ClockDivision = 0;
	TIM_handle_.Init.CounterMode = TIM_COUNTERMODE_UP;

	if (HAL_TIM_PWM_Init(&TIM_handle_) != HAL_OK)
	{
		return false;
	}

	///	--- PWM Channel

	TIM_OC_config_.OCMode = TIM_OCMODE_PWM1;
	TIM_OC_config_.OCPolarity = TIM_OCPOLARITY_HIGH;
	TIM_OC_config_.OCFastMode = TIM_OCFAST_DISABLE;

	/// Motor right pulse value
	/// pulse_length = ((TIM_Period + 1) * DutyCycle) / 100 - 1
	TIM_OC_config_.Pulse = 0;
	if (HAL_TIM_PWM_ConfigChannel(&TIM_handle_, &TIM_OC_config_, MOTOR_PWM_RIGHT_TIMER_CHANNEL) != HAL_OK)
	{
		return false;
	}

	///	--- Start

	if (HAL_TIM_PWM_Start(&TIM_handle_, MOTOR_PWM_RIGHT_TIMER_CHANNEL) != HAL_OK)
	{
		return false;
	}

	return true;
}

/// ------------------------------------------------------------------------------------------------

void Motor::duty_cycle(uint8_t _duty)
{
	HAL_TIM_PWM_Stop(&TIM_handle_, MOTOR_PWM_RIGHT_TIMER_CHANNEL);

	if (_duty == 0) TIM_OC_config_.Pulse = 0;
	else TIM_OC_config_.Pulse = ((8399 + 1) * _duty) / 100 - 1;
	HAL_TIM_PWM_ConfigChannel(&TIM_handle_, &TIM_OC_config_, MOTOR_PWM_RIGHT_TIMER_CHANNEL);

	HAL_TIM_PWM_Start(&TIM_handle_, MOTOR_PWM_RIGHT_TIMER_CHANNEL);
}

/// === Private Definitions	========================================================================
/// ------------------------------------------------------------------------------------------------
/// === END OF FILE	================================================================================
