// Mandatory settings 
# define IR_RECIVER_PIN PIN0
# define IR_TRANSMITER_PIN PIN1
# define IR_FREQUENCY_KHZ 36
# define MODE_SWITCH_PIN PIN2

/* Define the delay after transmitting a code in ms
 * Default value is 500ms */
# define IR_DEAD_TIME_MS 500

/* Define the wait time while recording a signal in ms
 * Default time is 5s */
# define IR_RECORD_TIME_MS 5000

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

/* Define the debud led diode pin
 * The diode will flash when recording a signal or transmitting */
# define DEBUG_LED_PIN A4

/* Define the raw-buffer length
 * The raw-buffer is used to store the states of the signal
 * the default value is 112 */
# define RAW_BUFFER_LENGTH 112

/* Define the pins for mode switches
 * For every switch, different signals can be recorded
 * IMPORTANT: the swiches require an external PULL_DOWN
 * 
 * Example of definitions:
 * # define MODE_SWITCH_PINS PIN_NUM0, PIN_NUM1 */
# define MODE_SWITCH_PINS A5, A6, A7


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

// Check if dead time is defined, if not, set it to 500ms
# ifndef IR_DEAD_TIME_MS
    # warning "IR_DEAD_TIME_MS is not defined, setting it to 500ms"
    # define IR_DEAD_TIME_MS 500
# endif

// Check if record time is defined, if not, set it to 5000ms
# ifndef IR_RECORD_TIME_MS
    # warning "IR_RECORD_TIME_MS is not defined, setting it to 5000ms"
    # define IR_RECORD_TIME_MS 5000
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

// Check if debug led pin is defined
# ifdef DEBUG_LED_PIN
    const bool USED_DEBUG_LED = true;
# else
    const bool USED_DEBUG_LED = false;
# endif

// Check the raw buffer length
# if RAW_BUFFER_LENGTH < 64
    # warning "RAW_BUFFER_LENGTH is short and may not capture all signals"
# elif RAW_BUFFER_LENGTH > 512
    # warning "RAW_BUFFER_LENGTH is long, this may cause memory issues"
# endif
// Check if raw buffer length is defined, if not, set it to default value [112]
# ifndef RAW_BUFFER_LENGTH
    # warning "RAW_BUFFER_LENGTH is not defined, setting it to 112"
    # define RAW_BUFFER_LENGTH 112
# endif

// Check if mode switch pins are defined, if not, use only one mode
# ifdef MODE_SWITCH_PINS
    const bool USED_MODE_SWITCHES = true;
    const uint8_t MODE_SWITCH_PINS_LIST[] = {MODE_SWITCH_PINS};
# else
    const bool USED_MODE_SWITCHES = false;
    const uint8_t MODE_SWITCH_PINS_LIST[] = {MODE_SWITCH_PIN};
# endif
