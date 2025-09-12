
# TP_0070_ASW_PUS_TC_3_31_REJECT_INVALID_N

The test checks that telecommand TC(3,31) with invalid N parameter is effectively rejected and the TM (1,1) and TM (1,4) are received with error code 2 (invalid N).

| STEPS | | | | |
|-------|-|-|-|-|
| **TO + 1** | **STEP0** | | | |
| | | **INPUTS** | **TC** | **App Data** |
| | Send the TC (3,31) with invalid N parameter | | TC(3,31) | N = 4<br>SID = 0<br>Period = 0x05 |
| | | **OUTPUTS** | **TM** | **App Data Filter** |
| | Check that the telecommand is rejected and the TM (1,1) and TM (1,4) telemetry packets are received with error code 2 | | TM(1,1)<br>TM(1,4) | Error Code = 2<br>Error Data = 4 |