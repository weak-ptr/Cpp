#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void KillChild(pid_t child_pid)
{
    if (!kill(child_pid, SIGKILL))
    {
        std::cout << "child pid: " << child_pid << " was killed\n";
    }
    else
        std::cout << "call kill failure\n";
}

#if 0
int main()
{
    pid_t id = 0;

    if ((id = fork()) == 0)
    {
        while(true)
        {
            std::cout << "child process group id: " << getpgrp() << std::endl;
            std::cout << "endless child\n";
            sleep(1);
        }
    } 
    else
    {
        while(true)
        {
            std::cout << "child process group id: " << getpgrp() << std::endl;
            std::cout << "endless parent\n";
            sleep(2);
        }
    }

    return 0;
}
#endif

#if 0
int main()
{
    pid_t cid = 0;

    if ( (cid = fork()) == 0)
    {
        while(true)
        {
            std::cout << "child...\n";
            sleep(1);
        }
    }
    else
    {
        sleep(10);
        KillChild(cid);
    }

    return 0;
}
#endif

#if 0
int main()
{
    unsigned int alarm_retval;

    //  first, should return zero
    alarm_retval = alarm(10);
    std::cout << "first return value: " << alarm_retval << std::endl;
    sleep(5);
    alarm_retval = alarm(8);
    std::cout << "second return value: " << alarm_retval << std::endl;

    return 0;
}
#endif

/*  caught Ctrl C  */
void signalHandler(int sig)
{
    printf("\nGaught SIGINT!\n");
    exit(0);
}

int main()
{
    /*  Install the SIGINT handler  */
    if (signal(SIGINT, signalHandler) == SIG_ERR)
    {
        printf("signal error\n");
        exit(0);
    }

    pause();

    return 0;
}