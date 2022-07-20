// Mandatory settings 
# define IR_RECIVER_PIN PIN0
# define IR_TRANSMITER_PIN PIN1
# define IR_FREQUENCY_KHZ 36
# define MODE_SWITCH_PIN PIN2


/* Define the input buttons
 * You need to specify the pins with buttons connected
 * Button inputs are not mandatory
 *
 * IMPORTANT: the buttons need an external PULL_DOWN
 * Separate the pins with comma, ex:
 * # define BUTTON_PINS PIN_NUM0, PIN_NUM1 */
# define BUTTON_PINS PIN3, PIN4, PIN5, PIN6, PIN7, A0

/* Define the pins with variable voltage input
 * this can be a potentiometer or any other peripheral
 * Variable voltage inputs are not necesary
 * 
 * IMPORTANT: every input requires it's own reset button,
 *  defined in separate list; n-th button is assigned to n-th voltage input
 * 
 * Example of definitions:
 * # define POTENTIOMETER_PINS PIN_NUM0, PIN_NUM1
 * # define POTENTIOMETER_RESET_PINS PIN_NUM2, PIN_NUM3 */
# define POTENTIOMETER_PINS A2
# define POTENTIOMETER_RESET_PINS A3


// Check if mandatory settings are defined
# ifndef IR_RECIVER_PIN
    # error "IR_RECIVER_PIN is not defined"
# endif
# ifndef IR_TRANSMITER_PIN
    # error "IR_TRANSMITER_PIN is not defined"
# endif
# ifndef IR_FREQUENCY_KHZ
    # error "IR_FREQUENCY_KHZ is not defined"
# endif
# ifndef MODE_SWITCH_PIN
    # error "MODE_SWITCH_PIN is not defined"
# endif

// Create a list with all defined button pins
# ifdef BUTTON_PINS
    const uint8_t BUTTON_PINS_LIST[] = {BUTTON_PINS};
# else
    # warning BUTTON_PINS_LIST is not defined or empty
# endif

// Create a list of potentiometer pins
# if defined(POTENTIOMETER_PINS) && defined(POTENTIOMETER_RESET_PINS)
    const uint8_t POTENTIOMETER_PINS_LIST[] = {POTENTIOMETER_PINS};
    const uint8_t POTENTIOMETER_RESET_PINS_LIST[] = {POTENTIOMETER_RESET_PINS};
# elif !defined(POTENTIOMETER_PINS) || !defined(POTENTIOMETER_RESET_PINS)
    # warning POTENTIOMETER_PINS_LIST and POTENTIOMETER_RESET_PINS_LIST is not defined
# elif !defined(POTENTIOMETER_PINS)
    # warning POTENTIOMETER_PINS_LIST is not defined
# elif !defined(POTENTIOMETER_RESET_PINS)
    # warning POTENTIOMETER_RESET_PINS_LIST is not defined
# endif

