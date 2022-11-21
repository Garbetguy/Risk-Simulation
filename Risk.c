/* Project #2
** Written by Matthew Garrett Pigg
In a trial of 50, the attacker won 30 games giving them a winning percentage
of 60% meaning the defender's winning percentage is 40%.
** First written March 2, 2022 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    int p, Aarmy, Darmy;
    Aarmy = 10;
    Darmy = 10;
    srand(time(NULL));

    for (p = 0; p < 30; ++p)
    {

        int a = 1 + rand() % 6, b = 1 + rand() % 6, c = 1 + rand() % 6, d = 1 + rand() % 6, e = 1 + rand() % 6;
        int number[30], i, j, case1, case2, case3, case4, case5;
        number[0] = a, number[1] = b, number[2] = c, number[3] = d, number[4] = e;

        for (i = 0; i < 3; ++i) { /* Written with descending order in mind for Attacker*/
            for (j = i + 1; j < 3; ++j) {
                if (number[i] < number[j])
                {
                    a = number[i];
                    number[i] = number[j];
                    number[j] = a;
                }
            }
        }

        for (i = 3; i < 6; ++i) { /* Written with descending order in mind for Defender*/
            for (j = i + 1; j < 6; ++j) {
                if (number[i] < number[j]) {
                    a = number[i];
                    number[i] = number[j];
                    number[j] = a;
                }
            }
        }

        if(Darmy <= 0)
        {
            printf("Attacker wins the round!");
            return 0;
        }

        if(Aarmy <= 1)
        {
            printf("Defender wins the round!");
            return 0;
        }





        if(Aarmy > 3)
        {
            printf("Attacker:   ");
            printf("%d   %d   %d\n", number[0], number[1], number[2]);

        }

        else if(Aarmy == 3)
        {
            number[2]=0;
            case1 = 5;  /* 5 meaning true or on */
            printf("Attacker:   ");
            printf("%d   %d\n", number[0], number[1]);
        }
        else
        {
            number[1]=0;
            number[2]=0;
            number[4]=0;
            case4 = 5;  /* 5 meaning true or on */
            printf("Attacker:   ");
            printf("%d \n", number[0]);
        }

        if (Darmy < 0)
        {
            Darmy=0;
        }

        if (Aarmy < 0)
        {
            Aarmy=0;
        }


        if (Darmy > 1 && case4 != 5)
        {
            printf("Defender:   ");
            printf("%d   %d\n", number[3], number[4]);
        }
        else if(Darmy == 1 || case4 == 5)
        {
            number[4]=0;
            case3 = 5;  /* 5 meaning true or on */
            printf("Defender:   ");
            printf("%d\n", number[3]);
        }


        if (case1 == 5 && case3 == 5)
        {
            case5 = 5;  /* 5 meaning true or on */
        }


        if(case5 == 5)
        {
            if(number[0]>number[3] || number[1]>number[3])
            {
                printf("The defender loses one army.\n");
                Darmy = --Darmy;
                printf("Attacker has %d armies; ", Aarmy);
                printf("Defender has %d armies \n", Darmy);
            }
            else if(number[3]>=number[0] || number[3]>=number[1])
            {
                printf("The attacker loses one army.\n");
                Aarmy = --Aarmy;
                printf("Attacker has %d armies; ", Aarmy);
                printf("Defender has %d armies \n", Darmy);
            }
        }
        else if (case4 == 5)
        {
            if(number[0]>number[3])
            {
                printf("The defender loses one army.\n");
                Darmy = --Darmy;
                printf("Attacker has %d armies; ", Aarmy);
                printf("Defender has %d armies \n", Darmy);
            }
            else if(number[3]>=number[0])
            {
                printf("The attacker loses one army.\n");
                Aarmy = --Aarmy;
                printf("Attacker has %d armies; ", Aarmy);
                printf("Defender has %d armies \n", Darmy);
            }
        }
        else if (case3 == 5)
        {
            if(number[3]>=number[0] || number[3]>=number[1] || number[3]>=number[2])
            {
                printf("The attacker loses one army.\n");
                Aarmy = --Aarmy;
                printf("Attacker has %d armies; ", Aarmy);
                printf("Defender has %d armies \n", Darmy);
            }
            else if(number[3]<number[0] || number[3]<number[1] || number[3]<number[2])
            {
                printf("The defender loses one army.\n");
                Darmy = --Darmy;
                printf("Attacker has %d armies; ", Aarmy);
                printf("Defender has %d armies \n", Darmy);
            }
        }
        else if (((number[0] > number[3]) && (number[1] <= number[4])) || ((number[0] <= number[3]) && (number[1] > number[4])) )
        {
            printf("Both players lose one army.\n");
            Aarmy = --Aarmy;
            Darmy = --Darmy;
            printf("Attacker has %d armies; ", Aarmy);
            printf("Defender has %d armies \n", Darmy);
        }
        else
        {
            if (number[0] <= number[3] && number[1] <= number[4])
            {
                printf("The attacker loses two army.\n");
                Aarmy = Aarmy-2;
                printf("Attacker has %d armies; ", Aarmy);
                printf("Defender has %d armies \n", Darmy);
            }
            else if (number[0] > number[3] && number[1] > number[4])
            {
                printf("The defender loses two army.\n");
                Darmy = Darmy-2;
                printf("Attacker has %d armies; ", Aarmy);
                printf("Defender has %d armies \n", Darmy);
            }

        }

    } return 0;

}

