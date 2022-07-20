// Mandatory settings 
# define IR_RECIVER_PIN PIN0
# define IR_TRANSMITER_PIN PIN1
# define IR_FREQUENCY_KHZ 36
# define MODE_SWITCH_PIN PIN2


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
