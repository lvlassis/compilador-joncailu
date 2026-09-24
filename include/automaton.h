typedef enum {
    Start,
    Id,
    Comment,
    Numeric,
    GreatherThan,
    LessThan,
    Equal,
    Different,
    Error,
    StateEOF,
    GenericBinop,
    Markup,
    Ign,
    Unknown
} StateType;

TokenType handle_state_transition(StateType *state, char caracter);