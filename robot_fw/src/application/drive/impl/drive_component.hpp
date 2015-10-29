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
/// \file	drive_component.hpp
/// \brief
/// \date	28/10/2015
/// \author	nboutin
///
/// ================================================================================================
#ifndef APPLICATION_DRIVE_IMPL_DRIVE_COMPONENT_HPP_
#define APPLICATION_DRIVE_IMPL_DRIVE_COMPONENT_HPP_

/// === Includes	================================================================================

#include "femtin/core/system_controller/icomponent.hpp"
#include "drive_service.hpp"
#include "drive_task.hpp"

/// === Namespaces	================================================================================

namespace application
{

namespace drive
{
/// === Forward Declarations	====================================================================
/// === Enumerations	============================================================================
/// === Class Declarations	========================================================================

class Drive_Component : public femtin::system_controller::IComponent
{
public:
	/// === Constants	============================================================================
	/// === Public Declarations	====================================================================

	Drive_Component();

	/// --- Component interface	--------------------------------------------------------------------

	virtual const femtin::String<COMPONENT_NAME_LEN_MAX>& name() const;

	virtual void* get_API_service();

	virtual const femtin::os::Task& get_task() const;

	virtual bool initialize(femtin::system_controller::Component_Registry& _comp_reg);

	virtual bool start();

private:
	/// === Private Declarations	================================================================
	/// === Private Attributs	====================================================================

	Drive_Service service_;
	Drive_Task task_;
};

/// === Inlines Declarations	====================================================================

inline const femtin::os::Task& Drive_Component::get_task() const
{
	return task_;
}

/// ------------------------------------------------------------------------------------------------
}
}

#endif
/// === END OF FILE	================================================================================
