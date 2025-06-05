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
    CTU0 : CTU;
    TOF0 : TOF;
    TON0 : TON;
    R_TRIG1 : R_TRIG;
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
  TON_T3(IN := aux_Y, PT := T#3s);
  IF TON_T3.Q THEN
    MG := FALSE; (*reset*)
  END_IF;
  P_START := MG;
  LR := MR;
  LY := MY;
  LG := MG;
  TON0(IN := NOT(MY), PT := T#500ms);
  TOF0(IN := TON0.Q);
  MY := TOF0.Q;
  R_TRIG1(CLK := MY);
  CTU0(CU := R_TRIG1.Q, R := aux_Y, PV := 3);
  aux_Y := CTU0.Q;
  IF aux_Y THEN
    MY := FALSE; (*reset*)
  END_IF;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : semaforo;
  END_RESOURCE
END_CONFIGURATION
