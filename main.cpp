#include "System.h"

int main()
{
    System system = System();
    system.signup();
    system.currentMember->displayInformation();
    system.listHouse();
    system.members[0].displayInformation();
}