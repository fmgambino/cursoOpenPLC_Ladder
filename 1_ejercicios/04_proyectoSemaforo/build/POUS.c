void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void SEMAFORO_init__(SEMAFORO *data__, BOOL retain) {
  __INIT_VAR(data__->P_START,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AUX_Y,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MY,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MG,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TON_T1,retain);
  TON_init__(&data__->TON_T3,retain);
  CTU_init__(&data__->CTU0,retain);
  TOF_init__(&data__->TOF0,retain);
  TON_init__(&data__->TON0,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
}

// Code part
void SEMAFORO_body__(SEMAFORO *data__) {
  // Initialise TEMP variables

  if (!(__GET_VAR(data__->P_START,))) {
    __SET_VAR(data__->,MR,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->TON_T1.,IN,,__GET_VAR(data__->MR,));
  __SET_VAR(data__->TON_T1.,PT,,__time_to_timespec(1, 0, 3, 0, 0, 0));
  TON_body__(&data__->TON_T1);
  if (__GET_VAR(data__->TON_T1.Q,)) {
    __SET_VAR(data__->,MR,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->TON_T1.Q,)) {
    __SET_VAR(data__->,MY,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->TON_T3.,IN,,__GET_VAR(data__->AUX_Y,));
  __SET_VAR(data__->TON_T3.,PT,,__time_to_timespec(1, 0, 3, 0, 0, 0));
  TON_body__(&data__->TON_T3);
  if (__GET_VAR(data__->TON_T3.Q,)) {
    __SET_VAR(data__->,MG,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,P_START,,__GET_VAR(data__->MG,));
  __SET_VAR(data__->,LR,,__GET_VAR(data__->MR,));
  __SET_VAR(data__->,LY,,__GET_VAR(data__->MY,));
  __SET_VAR(data__->,LG,,__GET_VAR(data__->MG,));
  __SET_VAR(data__->TON0.,IN,,!(__GET_VAR(data__->MY,)));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 500, 0, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->TOF0.,IN,,__GET_VAR(data__->TON0.Q,));
  TOF_body__(&data__->TOF0);
  __SET_VAR(data__->,MY,,__GET_VAR(data__->TOF0.Q,));
  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->MY,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->CTU0.,CU,,__GET_VAR(data__->R_TRIG1.Q,));
  __SET_VAR(data__->CTU0.,R,,__GET_VAR(data__->AUX_Y,));
  __SET_VAR(data__->CTU0.,PV,,3);
  CTU_body__(&data__->CTU0);
  __SET_VAR(data__->,AUX_Y,,__GET_VAR(data__->CTU0.Q,));
  if (__GET_VAR(data__->AUX_Y,)) {
    __SET_VAR(data__->,MY,,__BOOL_LITERAL(FALSE));
  };

  goto __end;

__end:
  return;
} // SEMAFORO_body__() 





