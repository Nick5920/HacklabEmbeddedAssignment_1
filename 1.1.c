#include <stdio.h>
#include <unistd.h>
enum TrafficLight {GREEN=0,YELLOW,RED};
void delay(int seconds)
{
    sleep(seconds);
}

void main()
{
    enum TrafficLight signal = GREEN;
    while (1)
    {
        switch (signal)
        {
            case GREEN:
                printf("Green light\n");
                delay(360);
                signal = YELLOW;
                break;
            case YELLOW:
                printf("Yellow light\n");
                delay(10);
                signal = RED;
                break;
            case RED:
                printf("Red light\n");
                delay(120);
                signal = GREEN;
                break;
        }
    }
}