
# TP_0130_ASW_PUS_TC_2_1_ONOFF_DEV_ADDRESS_0x60000001

The test checks that telecommand TC(2,1) to control device with address
0x60000001 is executed correctly and the TM (1,1) and TM (1,7) are received.

| STEPS | | | | |
|-------|-|-|-|-|
| **TO + 1** | **STEP0** | | | |
| | | **INPUTS** | **TC** | **App Data** |
| | Send the TC (2,1) to control device address 0x60000001 | | TC(2,1) | N = 1, Device Address = 0x60000001 |
| | | **OUTPUTS** | **TM** | **App Data Filter** |
| | Check that the received sequence is TM (1,1), TM (1,7) | | TM(1,1)<br>TM(1,7) | N/A | 