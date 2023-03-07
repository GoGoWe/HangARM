#include "hal.h"
// Specific implementation for ARM-Cortex M4 here:

#define FREQ_MHZ 80
#define SYST_CSR    0xE000E010
#define SYST_RL     0xE000E014
#define SYST_CVR    0xE000E018
#define SYST_CALIB  0xE000E01C

static ms10 ticks;

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

void SysTick_Handler() {
    ticks++;
}

void timerInit(void) {
    long clockTicks = FREQ_MHZ * 10000; //100ms
    writeToRegister(SYST_RL, clockTicks);
    writeToRegister(SYST_CVR, 0);
    writeToRegister(SYST_CSR, 0x00000007);
}

void sleep(const ms10 s) {
    ms10 endTime = ticks + s;
    while(endTime > ticks);
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

