TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK


PROGRAM semaforo
  VAR
    P_START : BOOL;
    LR : BOOL;
    LY : BOOL;
    LG : BOOL;
    MR : BOOL;
    aux_Y : BOOL;
    MY : BOOL;
    MG : BOOL;
    TON_T1 : TON;
    TON_T3 : TON;
    TOM_T2 : TON;
  END_VAR

  IF NOT(P_START) THEN
    MR := TRUE; (*set*)
  END_IF;
  TON_T1(IN := MR, PT := T#3s);
  IF TON_T1.Q THEN
    MR := FALSE; (*reset*)
  END_IF;
  IF TON_T1.Q THEN
    MY := TRUE; (*set*)
  END_IF;
  TON_T3(IN := MG, PT := T#3s);
  IF TON_T3.Q THEN
    MG := FALSE; (*reset*)
  END_IF;
  P_START := MG;
  LR := MR;
  LY := MY;
  LG := MG;
  TOM_T2(IN := MY, PT := T#3s);
  IF TOM_T2.Q THEN
    MY := FALSE; (*reset*)
  END_IF;
  IF TOM_T2.Q THEN
    MG := TRUE; (*set*)
  END_IF;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : semaforo;
  END_RESOURCE
END_CONFIGURATION
