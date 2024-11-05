## Bit Diagram

- 0-1       RES         Control Flow Reserved
- 2-4       S_CONN      LHost Connected (Always 101)
- 5-7       R_CONN      RHost Connected (Always 101)
- 8         S_CLK       Send Clock
- 9         R_CLK       Recv Clock
- 10-15     ECC         6-Bit Error Detection
- 16-63     DATA        Data

## Message Procedure

### RECEIVER_LOGIC

while true:
    scan
    if S_CONN
