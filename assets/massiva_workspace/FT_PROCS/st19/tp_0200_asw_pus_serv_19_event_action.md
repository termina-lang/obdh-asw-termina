
# TP_0200_ASW_PUS_SERV_19_EVENT_ACTION

The test checks that PUS service 19 (event-action) functionality works correctly
by setting up parameter monitoring, programming an automated action, and
verifying that the action is triggered when a limit violation occurs. 

| STEPS | | | | |
|-------|-|-|-|-|
| **TO + 1** | **STEP0** | | | |
| | | **INPUTS** | **TC** | **App Data** |
| | Send the TC (20,3) to set Parameter 15 to 5 | | TC(20,3) | N = 1, Parameter ID = 15, Parameter Value = 5 |
| | | **OUTPUTS** | **TM** | **App Data Filter** |
| | Check that the received sequence is TM (1,1), TM (1,7) | | TM(1,1)<br>TM(1,7) | N/A |
| **TO + 7** | **STEP1** | | | |
| | | **INPUTS** | **TC** | **App Data** |
| | Send the TC (12,5) to add monitoring definition for Parameter 15 | | TC(12,5) | N = 1, Param. Monitoring ID = 2, Parameter ID = 15, Monitoring Interval = 6, Repetition = 1, Type = 1, Low Limit = 1, Low-limit Event ID = 0x2000, High Limit = 20, High-limit Event ID = 0x2002 |
| | | **OUTPUTS** | **TM** | **App Data Filter** |
| | Check that the received sequence is TM (1,1), TM (1,7) | | TM(1,1)<br>TM(1,7) | N/A |
| **TO + 12** | **STEP2** | | | |
| | | **INPUTS** | **TC** | **App Data** |
| | Send the TC (19,1) to program TC(2,1) action for event 0x2002 | | TC(19,1) | N = 1, Event ID = 0x2002, TC Packet = [5B2CC000 .. 000030C7] |
| | | **OUTPUTS** | **TM** | **App Data Filter** |
| | Check that the received sequence is TM (1,1), TM (1,7) | | TM(1,1)<br>TM(1,7) | N/A |
| **TO + 17** | **STEP3** | | | |
| | | **INPUTS** | **TC** | **App Data** |
| | Send the TC (19,4) to enable action for event 0x2002 | | TC(19,4) | N = 1, Event ID = 0x2002 |
| | | **OUTPUTS** | **TM** | **App Data Filter** |
| | Check that the received sequence is TM (1,1), TM (1,7) | | TM(1,1)<br>TM(1,7) | N/A |
| **TO + 23** | **STEP4** | | | |
| | | **INPUTS** | **TC** | **App Data** |
| | Send the TC (12,1) to enable monitoring for Param. Monitoring 2 | | TC(12,1) | N = 1, Param. Monitoring ID = 2 |
| | | **OUTPUTS** | **TM** | **App Data Filter** |
| | Check that monitoring is enabled and transition is detected | | TM(1,1)<br>TM(1,7)<br>TM(12,12) | Param. Monitoring ID = 2, Parameter ID = 15 |
| **TO + 70** | **STEP5** | | | |
| | | **INPUTS** | **TC** | **App Data** |
| | Send the TC (5,5) to enable event ID 0x2002 | | TC(5,5) | N = 1, Event ID = 0x2002 |
| | | **OUTPUTS** | **TM** | **App Data Filter** |
| | Check that the received sequence is TM (1,1), TM (1,7) | | TM(1,1)<br>TM(1,7) | N/A |
| **TO + 100** | **STEP6** | | | |
| | | **INPUTS** | **TC** | **App Data** |
| | Send the TC (20,3) to set Parameter 15 to 99 to force event 0x2002 | | TC(20,3) | N = 1, Parameter ID = 15, Parameter Value = 99 |
| | | **OUTPUTS** | **TM** | **App Data Filter** |
| | Check that limit violation triggers monitoring transition, event, and automated action | | TM(1,1)<br>TM(1,7)<br>TM(12,12)<br>TM(5,2)<br>TM(1,7) | Param. Monitoring ID = 2, Parameter ID = 15, Event ID = 0x2002, Automated action executed |