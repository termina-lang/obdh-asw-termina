
# TP_0040_ASW_PUS_TC_3_31_SET_HK_PERIOD_SID_0_TO_0x05

The test checks that telecommand TC(3,31) to set housekeeping period for SID 0
to 5 is executed correctly and the TM (1,1) and TM (1,7) are received.

| STEPS | | | | |
|-------|-|-|-|-|
| **TO + 1** | **STEP0** | | | |
| | | **INPUTS** | **TC** | **App Data** |
| | Send the TC (3,31) to set HK period SID 0 to 5  | | TC(3,31) | N = 1<br>SID = 0<br>Period = 5 |
| | | **OUTPUTS** | **TM** | **App Data Filter** |
| | Check that the received sequence is TM (1,1), TM (1,7) | | TM(1,1)<br>TM(1,7) | N/A |
