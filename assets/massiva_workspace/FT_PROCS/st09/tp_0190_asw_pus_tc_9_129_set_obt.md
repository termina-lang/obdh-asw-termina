
# TP_0190_ASW_PUS_TC_9_129_SET_OBT

The test checks that telecommand TC(9,129) to set the On-Board Time (OBT) to
6000 seconds is executed correctly and the TM (1,1), TM (1,3), and TM (1,7) are
received.

| STEPS | | | | |
|-------|-|-|-|-|
| **TO + 1** | **STEP0** | | | |
| | | **INPUTS** | **TC** | **App Data** |
| | Send the TC (9,129) to set OBT to 6000 seconds | | TC(9,129) | Next OBT Seconds = 6000, Next OBT Finetime = 0 |
| | | **OUTPUTS** | **TM** | **App Data Filter** |
| | Check that the received sequence is TM (1,1), TM (1,3), TM (1,7) | | TM(1,1)<br>TM(1,3)<br>TM(1,7) | N/A |