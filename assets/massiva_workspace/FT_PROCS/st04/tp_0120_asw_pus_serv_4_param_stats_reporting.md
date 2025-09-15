
# TP_0120_ASW_PUS_SERV_4_PARAM_STATS_REPORTING

The test checks that parameter statistics can be defined for Parameters 1 and 3
using TC(4,6), retrieved using TC(4,1), and that Parameter 3 statistics can be
deleted using TC(4,7), verifying the complete parameter statistics reporting
functionality. 

| STEPS | | | | |
|-------|-|-|-|-|
| **TO + 1** | **STEP0** | | | |
| | | **INPUTS** | **TC** | **App Data** |
| | Send the TC (4,6) to define statistics for Parameter 1 | | TC(4,6) | N = 1, Parameter ID = 0x0001 |
| | | **OUTPUTS** | **TM** | **App Data Filter** |
| | Check that the received sequence is TM (1,1), TM (1,7) | | TM(1,1)<br>TM(1,7) | N/A |
| **TO + 8** | **STEP1** | | | |
| | | **INPUTS** | **TC** | **App Data** |
| | Send the TC (4,6) to define statistics for Parameter 3 | | TC(4,6) | N = 1, Parameter = 0x0003 |
| | | **OUTPUTS** | **TM** | **App Data Filter** |
| | Check that the received sequence is TM (1,1), TM (1,7) | | TM(1,1)<br>TM(1,7) | N/A |
| **TO + 14** | **STEP2** | | | |
| | | **INPUTS** | **TC** | **App Data** |
| | Send the TC (4,1) to request statistics report | | TC(4,1) | No parameters |
| | | **OUTPUTS** | **TM** | **App Data Filter** |
| | Check that TM (1,1) packet is received, that statistics reports are received for both parameters, and that TM (1,7) packet is received. | | TM(1,1)<br>TM(4,2)<br>TM(4,2)<br>TM(1,7) | Parameter 1 statistics, Parameter 3 statistics |
| **TO + 20** | **STEP3** | | | |
| | | **INPUTS** | **TC** | **App Data** |
| | Send the TC (4,7) to delete statistics for Parameter 3 | | TC(4,7) | N = 1, Parameter ID = 0x0003 |
| | | **OUTPUTS** | **TM** | **App Data Filter** |
| | Check that the received sequence is TM (1,1), TM (1,7) | | TM(1,1)<br>TM(1,7) | N/A |
| **TO + 50** | **STEP4** | | | |
| | | **INPUTS** | **TC** | **App Data** |
| | Send the TC (4,1) to request statistics report | | TC(4,1) | No parameters |
| | | **OUTPUTS** | **TM** | **App Data Filter** |
| | Check that TM (1,1) packet is received, that statistics reports are received for only Parameter 1 (Parameter 3 deleted), and that TM (1,7) packet is received. | | TM(1,1)<br>TM(4,2)<br>TM(1,7) | Parameter 1 statistics |