
# TP_0170_ASW_PUS_TC_6_5_REJECT_READ_BYTES_FROM_INVALID_MEMORY_ID

The test checks that telecommand TC(6,5) with invalid memory ID is effectively
rejected and the TM (1,1) and TM (1,4) are received with error code 8 (invalid
memory ID).

| STEPS | | | | |
|-------|-|-|-|-|
| **TO + 1** | **STEP0** | | | |
| | | **INPUTS** | **TC** | **App Data** |
| | Send the TC (6,5) with invalid memory ID | | TC(6,5) | N = 1, Memory ID = 0xF0, Start Address = 0x400, Length = 0x10 |
| | | **OUTPUTS** | **TM** | **App Data Filter** |
| | Check that the telecommand is rejected and the TM (1,1) and TM (1,4) telemetry packets are received with error code 8 | | TM(1,1)<br>TM(1,4) | Error Code = 8, Memory ID = 0xF0, Start Address = 0x400 |