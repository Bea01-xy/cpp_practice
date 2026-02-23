#include <iostream>
#include <csignal>
#include <unistd.h>

void signal_handler(int signum)
{
    std::cout << "signal(" << signum << ") received.\nshutting down." << std::endl;
    exit(signum);
}

int main (int argc, char *argv[]) {
    signal(SIGINT, signal_handler);
    int i = 0;

    while (1) {
        std::cout << "about to sleep..." << std::endl;
        if(i == 3){
            raise(SIGINT);
        }
        sleep(1);
        i++;
    }

    return 0;
}

//output:
//[22:02:25]alt_bea ~/Documents/code/cpp $ g++ src/signal.cpp -o build/signal && build/signal
//about to sleep...
//about to sleep...
//about to sleep...
//^Csignal(2) received.
//shutting down.
//[22:04:42]alt_bea ~/Documents/code/cpp $ echo $?
//2
