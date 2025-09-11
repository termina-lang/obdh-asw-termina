
# TP_0030_ASW_PUS_TC_REJECT_INVALID_CRC

The test sends a telecommand TC(17,1) with invalid CRC and checks that it is
effectively rejected and the TM (1,2) is received with error code 2 (invalid
CRC).

| STEPS | | | | |
|-------|-|-|-|-|
| **TO + 1** | **STEP0** | | | |
| | | **INPUTS** | **TC** | **App Data** |
| | Send the TC (17,1) with invalid CRC  | | TC(17,1) with CRC forced to 0xFADE | N/A |
| | | **OUTPUTS** | **TM** | **App Data Filter** |
| | Check that the telecommand is rejected and the TM (1,2) telemetry packet is received with error code 2 (invalid CRC) | | TM(1,2) | Error Code = 2<br>Received CRC = 0xFAD<br>Expected CRC = 0xA91E |
