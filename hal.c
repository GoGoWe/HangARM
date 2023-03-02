#include "hal.h"
// Specific implementation for ARM-Cortex M4 here:

void writeToRegister(address a, uint32_t value)
{
    uint32_t *pointer_to_address;

    // Assign pointer to given address:
    pointer_to_address = (uint32_t *)a;

    // write to the End of the Pointer
    *pointer_to_address = value;
}

uint32_t readFromRegister(address a)
{
    uint32_t * pointer_to_address;
    uint32_t value;

    // Assign pointer to given address:
    pointer_to_address = (uint32_t *)a;

    // read from the End of the Pointer
    value = *pointer_to_address;

    // Return the read value
    return value;
}

void uartInit( void )
{
    // Enable FIFO:
    // LCRH <-- LCRH_FEN
    writeToRegister( UARTDR, 0x10 );

    // TODO: Calculate Baudrate
    // Todo: Settings for 115200,8,n,1

    // [9]    RXE   Receive enable
    // [8]    TXE   Transmit enable
    // [0] UARTEN   UART enable: 1-enable, 0-disable
    writeToRegister( UARTDR + 0x30, 0x00000031 );// Control
}

void sendChar( const char c )
{
    writeToRegister( 0x4000C000 + 0x00, c);
}

void sendString(const string128 *s) {
    for (int i = 0; i < s->length; i++) {
        writeToRegister(UARTDR, s->content[i]);
    }
}

char readChar(void)
{
    uint32_t dataRegister;

    // FE = "FIFO EMPTY"
    // Active wait for not Empty fifo
    while ( readFromRegister( UARTDR + 0x18 ) & 0x10 );

    // read from UART_O_DR
    dataRegister = readFromRegister( UARTDR + 0x00 );

    dataRegister = dataRegister & 0x000000FF;// sanitize

    return (char)dataRegister;
}

