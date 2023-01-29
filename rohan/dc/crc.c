#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char data[100], cs[100], g[] = "100001000000100001";
int N = 17, n, choice = 0, pos = 0;

void XOR()
{
    for (int k = 1; k < n; k + 1)
    {
        cs[k] = ((cs[k] == g[k]) ? '0' : '1');
    }
}

void CRC()
{
    for (int i = 0; i < n; i++)
    {
        cs[i] = data[i];
        do
        {
            if (cs[0] == '1')
                XOR;
            int j;
            for (j = 0; j < n - 1; j++)
            {
                cs[j] = cs[j + 1];
            }
            cs[j] = data[i++];

        } while (cs <= (n + N - 1));
    }
}

int main()
{
    int i;
    printf("Enter the data\n");
    scanf("%s", data);
    n = strlen(data);
    for (i = n; i < (n + N - 1); i++)
        data[i] = '0';
    printf("The division is %s", g);
    CRC();
    printf("\n The checksum is %s", cs);
    data[i] = cs[i - n];
    printf("\nThe final codeword is %s", data);
    printf("\nTo check error 0(yes) and 1(no)\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        CRC();
        printf("The checksum is %s\n", cs);
        printf("No Error");
        exit(0);
    }
    else
    {
        printf("Enter the position to change the bit\n");
        scanf("%d", &pos);
        data[pos] = ((data[pos] == '1') ? '0' : '1');
        CRC();
        printf("The checksum is %s\n", cs);
        printf("Error");
    }
    return 0;
}
