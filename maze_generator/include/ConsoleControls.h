//
// Created by Jakub Kosmaty on 20/12/2020.
//

#ifndef MAZE_GENERATOR_CONSOLECONTROLS_H
#define MAZE_GENERATOR_CONSOLECONTROLS_H

#define CONSOLE_CLEAR               printf("\033c")
#define CONSOLE_DEF                 printf("\033[0m\033[m")
#define CONSOLE_POS(x, y)           printf("\033[%d;%dH", x, y)
#define CONSOLE_BOLD_TEXT(s)        printf("\033[1m%s\033[m", s)
#define CONSOLE_COLOR_TEXT(c, s)    printf("\033[%dm%s\033[m", c, s)

enum textColors {
    BLACK = 30,
    RED,
    GREEN,
    BROWN,
    BLUE,
    MAGENTA,
    CYAN,
    LIGHTGRAY,
};

enum DIRECTIONS {
    TOP = 0, RIGHT, BOTTOM, LEFT
};

#endif //MAZE_GENERATOR_CONSOLECONTROLS_H
