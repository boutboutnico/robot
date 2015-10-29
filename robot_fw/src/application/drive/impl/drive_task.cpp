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
/// \file	drive_task.cpp
/// \brief
/// \date	28/10/2015
/// \author	nboutin
///
/// ================================================================================================
#include "drive_task.hpp"
using namespace application::drive;

/// === Includes	================================================================================

#include "femtin/freeRTOS_wrapper/delay.hpp"
#include "appli_conf.hpp"
#include "bsp/trace_uart/trace_uart.hpp"

/// === Namespaces	================================================================================

using namespace femtin;
using namespace femtin::os;
using namespace board::mcu;

/// === Public Definitions	========================================================================

Drive_Task::Drive_Task()
		: Task(application::DRIVE_TASK_NAME.c_str(), application::DRIVE_TASK_STACK_SIZE,
				application::DRIVE_TASK_PRIO)
{
	suspend();
}

/// ------------------------------------------------------------------------------------------------

bool Drive_Task::initialize(femtin::system_controller::Component_Registry& _comp_reg)
{
	(void) _comp_reg;
	return true;
}

/// ------------------------------------------------------------------------------------------------

void Drive_Task::run()
{
	for (;;)
	{
		trace << "[Drive] I am alive" << endl;

		task_delay_until(unit::millisecond(5000));
	}
}

/// === END OF FILE	================================================================================
