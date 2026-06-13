// Copyright [Year] [Your Name]
// Distributed under the BSD 3-Clause License.
// See LICENSE file for details.
//
// Sleep mode management module for Rolex Ice watch.
// Handles low-power sleep modes to reduce power consumption.

#ifndef ROLEX_ICE_INCLUDE_SLEEP_MODE_H_
#define ROLEX_ICE_INCLUDE_SLEEP_MODE_H_

// Initializes sleep mode configuration.
void InitSleepMode(void);

// Manages sleep mode transitions and power management.
void ManageSleepMode(void);

#endif  // ROLEX_ICE_INCLUDE_SLEEP_MODE_H_