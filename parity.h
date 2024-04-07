

#ifdef _WIN32

#include <windows.h>

void clearscr(){
    system("cls");
}

void disableecho(){

    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE); 
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

}

void enableecho(){

    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE); 
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & (ENABLE_ECHO_INPUT));
}

#endif

#if defined(unix) || defined(__unix__) || defined(__unix)
#include <unistd.h>
#include <termios.h>

void clearscr(){
    system("clear");
    //printf("hi");
}

void Sleep(int timems){
    sleep(timems/1000);
}

void disableecho(){
    struct termios term;
    tcgetattr(fileno(stdin), &term);

    term.c_lflag &= ~ECHO;
    //term.c_lflag &= ~(ICANON);
    tcsetattr(fileno(stdin), 0, &term);

}


void enableecho(){
    struct termios term;
    tcgetattr(fileno(stdin), &term);

    term.c_lflag |= ECHO;
    //term.c_lflag |= ICANON;
    tcsetattr(fileno(stdin), 0, &term);
}

#endif