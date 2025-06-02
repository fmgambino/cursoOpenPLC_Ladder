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





void MEMORIAS_init__(MEMORIAS *data__, BOOL retain) {
  __INIT_LOCATED(BOOL,__IX0_0,data__->I_NA0,retain)
  __INIT_LOCATED_VALUE(data__->I_NA0,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__IX0_1,data__->I_NA1,retain)
  __INIT_LOCATED_VALUE(data__->I_NA1,__BOOL_LITERAL(FALSE))
  __INIT_VAR(data__->M0,__BOOL_LITERAL(FALSE),retain)
  __INIT_LOCATED(BOOL,__QX0_1,data__->Q_NA,retain)
  __INIT_LOCATED_VALUE(data__->Q_NA,__BOOL_LITERAL(FALSE))
}

// Code part
void MEMORIAS_body__(MEMORIAS *data__) {
  // Initialise TEMP variables

  __SET_LOCATED(data__->,Q_NA,,__GET_VAR(data__->M0,));
  if (__GET_LOCATED(data__->I_NA1,)) {
    __SET_VAR(data__->,M0,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_LOCATED(data__->I_NA0,)) {
    __SET_VAR(data__->,M0,,__BOOL_LITERAL(TRUE));
  };

  goto __end;

__end:
  return;
} // MEMORIAS_body__() 





