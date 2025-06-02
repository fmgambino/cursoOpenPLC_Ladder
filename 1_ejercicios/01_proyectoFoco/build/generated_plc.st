PROGRAM proyectoFoco
  VAR
    P_Start AT %IX0.0 : BOOL;
    Foco AT %QX0.1 : BOOL;
  END_VAR

  Foco := P_Start;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : proyectoFoco;
  END_RESOURCE
END_CONFIGURATION
