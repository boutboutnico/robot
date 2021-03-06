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
/// \file	com2_component.cpp
/// \brief
/// \date	28/10/2015
/// \author	nboutin
///
/// ================================================================================================
#include "drive_component.hpp"
using namespace application::drive;

/// === Includes	================================================================================
/// === Namespaces	================================================================================

using namespace femtin;
using namespace femtin::system_controller;
using namespace application;

/// === Constants	================================================================================
/// === Public Definitions	========================================================================

Drive_Component::Drive_Component()
		: service_(), task_()
{

}

/// ------------------------------------------------------------------------------------------------

const String<COMPONENT_NAME_LEN_MAX>& Drive_Component::name() const
{
	return DRIVE_TASK_NAME;
}

/// ------------------------------------------------------------------------------------------------

void* Drive_Component::get_API_service()
{
	return &service_;
}

/// ------------------------------------------------------------------------------------------------

bool Drive_Component::initialize(Component_Registry& _comp_reg)
{
	return task_.initialize(_comp_reg);
}

/// ------------------------------------------------------------------------------------------------

bool Drive_Component::start()
{
	task_.resume();
	return true;
}

/// ------------------------------------------------------------------------------------------------
/// === Private Definitions	========================================================================
/// ------------------------------------------------------------------------------------------------
/// === END OF FILE	================================================================================
