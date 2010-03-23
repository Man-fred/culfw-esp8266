#ifndef _BOARD_H
#define _BOARD_H

#include <avr/io.h>
#include <avr/power.h>

#define CUL_V2

#ifdef CUL_V3

#ifndef __AVR_ATmega32U4__

#error "CUL version 3 is supposed to run on ATMEGA32U4 processor - please change MCU line in makefile!"

#else
// not sure why libc is missing those ...

#define PB0 PORTB0
#define PB1 PORTB1
#define PB2 PORTB2
#define PB3 PORTB3
#define PB6 PORTB6
#define PD2 PORTD2
#define PD3 PORTD3

#ifndef clock_prescale_set
#warning "avr/power.h needs patching for prescaler functions to work on m32u4 ... (just add __AVR_ATmega32U4__ for cpu types on prescale block)"
#endif

#endif

#endif

#define SPI_PORT		PORTB
#define SPI_DDR			DDRB
#define SPI_SS			PB0
#define SPI_MISO		PB3
#define SPI_MOSI		PB2
#define SPI_SCLK		PB1

#ifdef CUL_V3

#define CC1100_CS_DDR		SPI_DDR
#define CC1100_CS_PORT          SPI_PORT
#define CC1100_CS_PIN		SPI_SS
#define CC1100_OUT_DDR		DDRD
#define CC1100_OUT_PORT         PORTD
#define CC1100_OUT_PIN          PD3
#define CC1100_IN_DDR		DDRD
#define CC1100_IN_PORT          PIND
#define CC1100_IN_PIN           PD2
#define CC1100_INT		INT2
#define CC1100_INTVECT          INT2_vect
#define CC1100_ISC		ISC20
#define CC1100_EICR             EICRA

#define LED_DDR                 DDRE
#define LED_PORT                PORTE
#define LED_PIN                 6

#else

#define CC1100_CS_DDR		DDRC
#define CC1100_CS_PORT          PORTC
#define CC1100_CS_PIN		PC5
#define CC1100_IN_DDR		DDRC
#define CC1100_IN_PORT          PINC
#define CC1100_IN_PIN           PC7
#define CC1100_OUT_DDR		DDRC
#define CC1100_OUT_PORT         PORTC
#define CC1100_OUT_PIN          PC6
#define CC1100_INT		INT4
#define CC1100_INTVECT          INT4_vect
#define CC1100_ISC		ISC40
#define CC1100_EICR             EICRB

#define LED_DDR                 DDRC
#define LED_PORT                PORTC
#define LED_PIN                 PC4

#endif

#define USB_MAX_POWER		100

#define BOARD_ID_STR            "CUL868"
#define BOARD_ID_STR433         "CUL433"
#define BOARD_ID_USTR           L"CUL868"
#define BOARD_ID_USTR433        L"CUL433"

#define HAS_USB                 1

#define TTY_BUFSIZE             32      // Must be a supported USB endpoint size
#define HAS_FHT_8v                      // PROGMEM:  586b, RAM: 23b
#define HAS_FHT_80b                     // PROGMEM: 1374b, RAM: 90b
#define FHTBUF_SIZE             74      //                 RAM: 74b
#define HAS_RF_ROUTER           1       // PROGMEM: 1248b, RAM: 44b
#define RCV_BUCKETS             2       //                 RAM: 25b / bucket

//#define  FULL_CC1100_PA                 // PROGMEM:  108b
//#define  HAS_RAWSEND                    // PROGMEM:  198b     RAM:  4b
//#define  HAS_FASTRF                     // PROGMEM:  362+106  RAM:  1b

#define BUSWARE_CUL

#include "compileconfig.h"

#endif
