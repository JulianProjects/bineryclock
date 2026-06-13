#include <stdbool.h>

extern int entpreller_first_press;
extern int entpreller_second_press;
extern bool button_4_getter;    

void initButton(void);

bool button_4_pressed(void);
bool button_3_pressed(void);
bool button_2_pressed(void);
bool entprellt(void);
int button_pressed(void);