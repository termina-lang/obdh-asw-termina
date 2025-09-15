
# TP_0160_ASW_PUS_TC_6_9_CHECKSUM_FROM_0x40000090_TO_0x400000BF

The test checks that telecommand TC(6,9) calculates checksum for 48 bytes from
memory address 0x40000090 to 0x400000BF and returns the expected checksum value
0x41BE in TM (6,10).

| STEPS | | | | |
|-------|-|-|-|-|
| **TO + 1** | **STEP0** | | | |
| | | **INPUTS** | **TC** | **App Data** |
| | Send the TC (6,9) to calculate checksum from memory address 0x40000090 | | TC(6,9) | N = 1, Memory ID = 0, Start Address = 0x90, Length = 48 |
| | | **OUTPUTS** | **TM** | **App Data Filter** |
| | Check that checksum calculation is executed and TM (6,10) contains expected checksum | | TM(1,1)<br>TM(6,10)<br>TM(1,7) | N = 1, Memory ID = 0, Start Address = 0x90, Length = 48, Checksum = 0x41BE |