#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// PROGRAM SEMAFORO
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,P_START)
  __DECLARE_VAR(BOOL,LR)
  __DECLARE_VAR(BOOL,LY)
  __DECLARE_VAR(BOOL,LG)
  __DECLARE_VAR(BOOL,MR)
  __DECLARE_VAR(BOOL,AUX_Y)
  __DECLARE_VAR(BOOL,MY)
  __DECLARE_VAR(BOOL,MG)
  TON TON_T1;
  TON TON_T3;
  TON TOM_T2;

} SEMAFORO;

void SEMAFORO_init__(SEMAFORO *data__, BOOL retain);
// Code part
void SEMAFORO_body__(SEMAFORO *data__);
#endif //__POUS_H
