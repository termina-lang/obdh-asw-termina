
# TP_0100_ASW_PUS_TC_20_3_INVALID_PID

The test checks that telecommand TC(20,3) with invalid Parameter ID is
effectively rejected and the TM (1,1), and TM (1,4) with error code 22 (invalid
Parameter ID), are received.

| STEPS | | | | |
|-------|-|-|-|-|
| **TO + 1** | **STEP0** | | | |
| | Send the TC (20,3) with invalid Parameter ID | | TC(20,3) | N = 1, Parameter ID = 0x80, Parameter Value = 0x00 |
| | | **OUTPUTS** | **TM** | **App Data Filter** |
| | Check that the telecommand is rejected and the TM (1,1), and TM (1,4) with error code 22, telemetry packets are received | | TM(1,1)<br>TM(1,4) | Error Code = 22, Parameter ID = 0x80 |