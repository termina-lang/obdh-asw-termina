
# TP_0100_ASW_PUS_TC_20_3_INVALID_PID

The test checks that telecommand TC(20,3) with invalid PID is effectively
rejected and the TM (1,1) and TM (1,4) are received with error code 22 (invalid
PID).

| STEPS | | | | |
|-------|-|-|-|-|
| **TO + 1** | **STEP0** | | | |
| | Send the TC (20,3) with invalid PID | | TC(20,3) | N = 1, PID = 0x80, PID Value = 0x00 |
| | | **OUTPUTS** | **TM** | **App Data Filter** |
| | Check that the telecommand is rejected and the TM (1,1) and TM (1,4) telemetry packets are received with error code 22 | | TM(1,1)<br>TM(1,4) | Error Code = 22, Error Data = 0x80 |