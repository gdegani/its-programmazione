#include <stdio.h>

// #region snippet1
typedef enum { STATE_IDLE, STATE_RUNNING, STATE_FAULT } State;
typedef enum { EVENT_START, EVENT_STOP, EVENT_FAULT, EVENT_RESET } Event;
// #endregion snippet1

// #region snippet3
State next_state(State state, Event event) {
    switch (state) {
        case STATE_IDLE:
            if (event == EVENT_START) return STATE_RUNNING;
            break;
        case STATE_RUNNING:
            if (event == EVENT_STOP) return STATE_IDLE;
            if (event == EVENT_FAULT) return STATE_FAULT;
            break;
        case STATE_FAULT:
            if (event == EVENT_RESET) return STATE_IDLE;
            break;
    }
    return state;   // event not valid in this state: stay where we are
}
// #endregion snippet3

static const char *state_name(State state) {
    switch (state) {
        case STATE_IDLE:    return "IDLE";
        case STATE_RUNNING: return "RUNNING";
        case STATE_FAULT:   return "FAULT";
    }
    return "?";
}

int main(void) {
    // #region snippet2
    Event events[] = {
        EVENT_START, EVENT_FAULT, EVENT_START,
        EVENT_RESET, EVENT_START, EVENT_STOP
    };
    int count = sizeof(events) / sizeof(events[0]);

    State state = STATE_IDLE;
    printf("start: %s\n", state_name(state));
    for (int i = 0; i < count; i++) {
        state = next_state(state, events[i]);
        printf("event %d -> %s\n", i + 1, state_name(state));
    }
    // #endregion snippet2

    return 0;
}
