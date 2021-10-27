#include <stdio.h>
main()
{
    int rooster,hen,chickens;
    for(rooster=1;rooster<15;rooster++)
    {
        for(chickens=3;chickens<97;chickens=chickens+3)
        {
            hen=100-rooster-chickens;
            if( 7*rooster+5*hen+chickens/3==100 && hen>0)
            {
                printf("%d  %d  %d \n", rooster, hen, chickens);
            }
        }
    }
}
