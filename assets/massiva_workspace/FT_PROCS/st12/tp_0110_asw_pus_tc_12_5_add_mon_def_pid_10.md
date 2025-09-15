
# TP_0110_ASW_PUS_TC_12_5_ADD_MON_DEF_PID_10

The test checks that a monitoring definition for Parameter 10 is added using
TC(12,5), enabled using TC(12,1), and that the monitoring system correctly
detects limit violations and generates the appropriate events.

| STEPS | | | | |
|-------|-|-|-|-|
| **TO + 1** | **STEP0** | | | |
| | | **INPUTS** | **TC** | **App Data** |
| | Send the TC (20,3) to set Parameter 10 to 99 | | TC(20,3) | N = 1, Parameter ID = 10, Parameter Value = 99 |
| | | **OUTPUTS** | **TM** | **App Data Filter** |
| | Check that the received sequence is TM (1,1), TM (1,7) | | TM(1,1)<br>TM(1,7) | N/A |
| **TO + 8** | **STEP1** | | | |
| | | **INPUTS** | **TC** | **App Data** |
| | Send the TC (12,5) to add monitoring definition for Parameter 10 | | TC(12,5) | N = 1, Param. Monitoring ID = 0, Parameter ID = 10, Monitoring Interval = 8, Repetition = 2, Type = 1, Low Limit = 1, Low-limit Event ID = 0x4000, High Limit = 10, High-limit Event ID = 0x4001 |
| | | **OUTPUTS** | **TM** | **App Data Filter** |
| | Check that the received sequence is TM (1,1), TM (1,7) | | TM(1,1)<br>TM(1,7) | N/A |
| **TO + 14** | **STEP2** | | | |
| | | **INPUTS** | **TC** | **App Data** |
| | Send the TC (12,1) to enable monitoring for Param. Monitoring 0 | | TC(12,1) | Param. Monitoring ID = 0 |
| | | **OUTPUTS** | **TM** | **App Data Filter** |
| | Check that the received sequence is TM (1,1), TM (1,7) | | TM(1,1)<br>TM(1,7) | N/A |
| **TO + 20** | **STEP3** | | | |
| | | **INPUTS** | **TC** | **App Data** |
| | Send the TC (20,3) to set PID 10 to 99 to force event 0x4001 | | TC(20,3) | N = 1, Parameter ID = 10, Parameter Value = 99 |
| | | **OUTPUTS** | **TM** | **App Data Filter** |
| | Check that monitoring transition and event are generated | | TM(1,1)<br>TM(1,7)<br>TM(12,12)<br>TM(5,4) | Param. Monitoring ID = 0, Parameter ID = 10, Event ID = 0x4001 |