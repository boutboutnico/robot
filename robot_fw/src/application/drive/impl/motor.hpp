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
/// \file	motor.hpp
/// \brief
/// \date	29/10/2015
/// \author	nboutin
///
/// ================================================================================================
#ifndef APPLICATION_DRIVE_IMPL_MOTOR_HPP_
#define APPLICATION_DRIVE_IMPL_MOTOR_HPP_

/// === Includes	================================================================================

#include "stm32f4xx_hal.h"

/// === Namespaces	================================================================================

namespace application
{

namespace drive
{
/// === Forward Declarations	====================================================================
/// === Enumerations	============================================================================
/// === Class Declarations	========================================================================

class Motor
{
public:
	/// === Public Constants	====================================================================
	/// === Public Declarations	====================================================================

	Motor();

	bool initialize();

private:
	///	=== Private Constants	====================================================================
	/// === Private Declarations	================================================================
	/// === Private Attributes	====================================================================

	TIM_HandleTypeDef TIM_handle_;
	TIM_OC_InitTypeDef TIM_OC_config_;
};

/// === Inlines Definitions	========================================================================

///	=== Non-Members Definitions	====================================================================

/// ------------------------------------------------------------------------------------------------
}/// name
}    /// sub_name

#endif
/// === END OF FILE	================================================================================
