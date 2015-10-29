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

	/// Enable TIM clock
	MOTOR_PWM_TIM_CLK_ENABLE();

	/// Enable TIM4 GPIO PWM
	MOTOR_PWM_GPIO_CLK_ENABLE();

	///	--- GPIOs

	GPIO_InitTypeDef GPIO_init;
	GPIO_init.Mode = GPIO_MODE_AF_PP;
	GPIO_init.Pull = GPIO_PULLUP;
	GPIO_init.Speed = GPIO_SPEED_HIGH;
	GPIO_init.Alternate = GPIO_AF2_TIM3;

	/// Motor right
	GPIO_init.Pin = MOTOR_PWM_RIGHT_PIN;
	HAL_GPIO_Init(const_cast<GPIO_TypeDef*>(MOTOR_PWM_RIGHT_GPIO_PORT), &GPIO_init);

	///	--- Timer

	TIM_handle_.Instance = const_cast<TIM_TypeDef*>(MOTOR_PWM_TIMER);
	TIM_handle_.Init.Prescaler = 0;
	TIM_handle_.Init.Period = 8399;
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
	TIM_OC_config_.Pulse = 2099;
	if (HAL_TIM_PWM_ConfigChannel(&TIM_handle_, &TIM_OC_config_, TIM_CHANNEL_1) != HAL_OK)
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
/// === Private Definitions	========================================================================
/// ------------------------------------------------------------------------------------------------
/// === END OF FILE	================================================================================
