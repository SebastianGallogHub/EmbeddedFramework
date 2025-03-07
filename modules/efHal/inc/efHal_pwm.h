/*
###############################################################################
#
# Copyright 2022, Gustavo Muro
# All rights reserved
#
# This file is part of EmbeddedFirmware.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice,
#    this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
#
# 3. Neither the name of the copyright holder nor the names of its
#    contributors may be used to endorse or promote products derived from this
#    software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#                                                                             */
#ifndef EF_HAL_PWM_H_
#define EF_HAL_PWM_H_

/*==================[inclusions]=============================================*/
#include "stdint.h"
#include "stdbool.h"
#include "FreeRTOS.h"

/*==================[cplusplus]==============================================*/
#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros and typedef]=====================================*/

typedef int32_t efHal_pwm_id_t;

typedef enum
{
    EF_HAL_PWM_DUTY_PERCENT = 0,
    EF_HAL_PWM_DUTY_COUNT,
    EF_HAL_PWM_DUTY_NS,
}efHal_pwm_dutyUnit_t;

typedef void (*efHal_pwm_callBackInt_t)(efHal_pwm_id_t id);

/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/
extern void efHal_pwm_init(void);
extern void efHal_pwm_setDuty(efHal_pwm_id_t id, uint32_t duty, efHal_pwm_dutyUnit_t dutyUnit);
extern void efHal_pwm_setPeriod(efHal_pwm_id_t id, uint32_t period_nS);
extern void efHal_pwm_confIntCount(efHal_pwm_id_t id, uint32_t count);
extern bool efHal_pwm_waitForInt(efHal_pwm_id_t id, TickType_t xBlockTime);
extern void efHal_pwm_setCallBackInt(efHal_pwm_id_t id, efHal_pwm_callBackInt_t cb);

/*==================[cplusplus]==============================================*/
#ifdef __cplusplus
}
#endif

/*==================[end of file]============================================*/
#endif /* EF_HAL_PWM_H_ */
