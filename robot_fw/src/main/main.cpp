///
/// \file	main.cpp
///	\brief
///	\date	22/10/2015
/// \author	nboutin
///

/// === Includes	================================================================================

#include "FreeRTOS.h"
#include "femtin/freeRTOS_wrapper/task/task.hpp"
//#include "system_controller/component_registry.hpp"
#include "bsp/trace_uart/trace_uart.hpp"

/// === Namespaces	================================================================================

//using namespace application::system_controller;

/// === Public Definitions	========================================================================

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

int main(int argc, char* argv[])
{
	/// At this stage the system clock should have already been configured at high speed.

	board::mcu::trace.initialize(115200);

	board::mcu::trace << "Trace is ready" << femtin::endl;

//	static ComponentRegistry comp_reg;

	vTaskStartScheduler();    /// should never return
}

#pragma GCC diagnostic pop

/// === END OF FILE	================================================================================

