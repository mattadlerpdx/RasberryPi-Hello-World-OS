#pragma once

#include "common.h"

#include "peripherals/base.h"

struct AuxRegs{
    reg32 irq_status;
    reg32 enables;
    reg32 reserved [14];
    reg32 mu_io;
    reg32 mu_iir;
    reg32 mu_icr;
    reg32 mu_mcr;
    reg32 mu_lsr;
    reg32 mu_msr;
    reg32 mu_scratch;
    reg32 mu_control;
    reg32 mu_status;
    reg32 mu_baud_rate;

};
