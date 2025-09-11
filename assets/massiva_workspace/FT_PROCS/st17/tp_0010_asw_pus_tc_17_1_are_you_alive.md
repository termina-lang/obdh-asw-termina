
# TP_0010_ASW_PUS_TC_17_1_ARE_YOU_ALIVE

The test checks that telecommand TC(17,1) is executed correctly and the TM
(1,1), TM (17,2) and TM(1,7) are received.

| STEPS | | | | |
|-------|-|-|-|-|
| **TO + 1** | **STEP0** | | | |
| | | **INPUTS** | **TC** | **App Data** |
| | Send the TC (17,1) | | TC(17,1) | N/A |
| | | **OUTPUTS** | **TM** | **App Data Filter** |
| | Check that the received sequence is TM (1,1), TM (17,2) and TM (1,7) | | TM(1,1)<br>TM(17,2)<br>TM(1,7) | |
