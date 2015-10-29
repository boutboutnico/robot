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
/// \file	robot.cpp
///	\brief	
///	\date	29/10/2015
/// \author	nboutin
///
/// ================================================================================================
#include "robot_registry.hpp"
using namespace application::system_controller;

/// === Includes	================================================================================

#include "../drive/impl/drive_component.hpp"

/// === Namespaces	================================================================================
/// === Constants	================================================================================

const uint8_t Drive_id = static_cast<uint8_t>(Component_Name_e::Drive);

/// === Public Definitions	========================================================================

Robot_Registry::Robot_Registry()
{
	static drive::Drive_Component drive;

	components_[Drive_id] = &drive;
}

/// ------------------------------------------------------------------------------------------------
/// === Private Definitions	========================================================================
/// ------------------------------------------------------------------------------------------------
/// === END OF FILE	================================================================================
