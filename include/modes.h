// Copyright [Year] [Your Name]
// Distributed under the BSD 3-Clause License.
// See LICENSE file for details.
//
// Mode handling module for Rolex Ice watch.
// Manages different operation modes and transitions.

#ifndef ROLEX_ICE_INCLUDE_MODES_H_
#define ROLEX_ICE_INCLUDE_MODES_H_

#include <stdbool.h>

// Button 4 state flag.
extern bool button_4_getter;

// Main mode handler - dispatches to appropriate mode function.
void HandleMode(void);

// Mode 1 handler (display time).
void HandleMode1(void);

// Mode 2 handler.
void HandleMode2(void);

// Mode 3 handler.
void HandleMode3(void);

// Mode 4 handler.
void HandleMode4(void);

#endif  // ROLEX_ICE_INCLUDE_MODES_H_