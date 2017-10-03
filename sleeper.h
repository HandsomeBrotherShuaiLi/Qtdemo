#ifndef SLEEPER_H
#define SLEEPER_H
#include<QThread>

class sleeper : public QThread
{
public:
    static void sleep(unsigned long secs){QThread::sleep(secs);}
 };

#endif // SLEEPER_H
