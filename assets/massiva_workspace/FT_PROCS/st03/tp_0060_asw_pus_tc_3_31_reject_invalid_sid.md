
# TP_0060_ASW_PUS_TC_3_31_REJECT_INVALID_SID

The test checks that telecommand TC(3,31) with invalid SID is effectively
rejected and the TM (1,1), and TM (1,4) with error code 5 (invalid SID), are
received.

| STEPS | | | | |
|-------|-|-|-|-|
| **TO + 1** | **STEP0** | | | |
| | | **INPUTS** | **TC** | **App Data** |
| | Send the TC (3,31) with invalid SID | | TC(3,31) | N = 1<br>SID = 0x0F<br>Period = 0x10 |
| | | **OUTPUTS** | **TM** | **App Data Filter** |
| | Check that the telecommand is rejected and the TM (1,1), and TM (1,4) with error code 5, telemetry packets are received | | TM(1,1)<br>TM(1,4) | Error Code = 5<br>SID = 0x0F |