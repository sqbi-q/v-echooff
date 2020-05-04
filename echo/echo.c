#include "echo.h"


#if defined(_WIN32) || defined(_WIN64) || defined(WIN32) || defined(WIN64)

#include <windows.h>

void displayInput(bool display) {
    HANDLE hStdIn = GetStdHandle(STD_INPUT_HANDLE);
    if(hStdIn == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "GetStdHandle failed (error %lu)\n", GetLastError());
        return;
    }

    /* Get console mode */
    DWORD mode;
    if(!GetConsoleMode(hStdIn, &mode)) {
        fprintf(stderr, "GetConsoleMode failed (error %lu)\n", GetLastError());
        return;
    }

    if(display) {
        /* Add echo input to the mode */
        if(!SetConsoleMode(hStdIn, mode | ENABLE_ECHO_INPUT)) {
            fprintf(stderr, "SetConsoleMode failed (error %lu)\n", GetLastError());
            return;
        }
    }
    else {
        /* Remove echo input to the mode */
        if(!SetConsoleMode(hStdIn, mode & ~((DWORD) ENABLE_ECHO_INPUT))) {
            fprintf(stderr, "SetConsoleMode failed (error %lu)\n", GetLastError());
            return;
        }
    }
}

#else

#include <termios.h>


void displayInput(bool display) {
    struct termios t;

    /* Get console mode */
    int errno = 0; 
    if (tcgetattr(0, &t)) {
        fprintf(stderr, "tcgetattr failed (%s)\n", strerror(errno));
        return;
    }
    /* Set console mode to echo or no echo */
    if (display) {
        t.c_lflag |= ECHO;
    } else {
        t.c_lflag &= ~((tcflag_t) ECHO);
    }
    errno = 0;
    if (tcsetattr(0, TCSANOW, &t)) {
        fprintf(stderr, "tcsetattr failed (%s)\n", strerror(errno));
        return;
    }
}

#endif