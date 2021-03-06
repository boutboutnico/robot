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
/// \file	drive_task.hpp
/// \brief
/// \date	28/10/2015
/// \author	nboutin
///
/// ================================================================================================
#ifndef APPLICATION_DRIVE_IMPL_DRIVE_TASK_HPP_
#define APPLICATION_DRIVE_IMPL_DRIVE_TASK_HPP_

/// === Includes	================================================================================

#include "femtin/freeRTOS_wrapper/task/task.hpp"
#include "femtin/core/system_controller/component_registry.hpp"
#include "motor.hpp"

/// === Namespaces	================================================================================

namespace application
{
namespace drive
{

/// === Class Declarations	========================================================================

class Drive_Task : public femtin::os::Task
{
public:
	/// === Public Constants	====================================================================
	/// === Public Declarations	====================================================================

	Drive_Task();

	bool initialize(femtin::system_controller::Component_Registry& _comp_reg);

	virtual void run();

private:
	/// === Private Constants	====================================================================
	/// === Private Declarations	================================================================
	/// === Private Attributes	====================================================================

	Motor motor_;
};

/// === Inlines Definitions	========================================================================

/// ------------------------------------------------------------------------------------------------
}
}
#endif
/// === END OF FILE	================================================================================
