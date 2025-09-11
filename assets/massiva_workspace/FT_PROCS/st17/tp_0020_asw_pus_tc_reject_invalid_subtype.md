
# TP_0020_ASW_PUS_TC_REJECT_INVALID_SUBTYPE

The test checks that unsupported telecommand TC(17,3) is effectively rejected and the TM
(1,2) is received with error code 6 (invalid subtype).

| STEPS | | | | |
|-------|-|-|-|-|
| **TO + 1** | **STEP0** | | | |
| | | **INPUTS** | **TC** | **App Data** |
| | Send the TC (17,3)  | | TC(17,3) | APID = 0x0090 |
| | | **OUTPUTS** | **TM** | **App Data Filter** |
| | Check that the telecommand is rejected and the TM (1,2) telemetry packet is received with error code 6 (invalid subtype) | | TM(1,2) | Error Code = 0x06<br>Error Data = 0x03 |
