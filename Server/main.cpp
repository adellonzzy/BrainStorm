#include <iostream>
using namespace std;
#include "thread.h"
#include "tcpserver.h"
#include "myserver.h"

int main()
{
    MyServer s;
    s.listen(9999);
    s.start();
    return 0;
}
