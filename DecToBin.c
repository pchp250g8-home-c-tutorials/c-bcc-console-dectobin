#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>


int _tmain(int argc, _TCHAR* argv[]) 
{
    long long uDecNumber, uTempVal;
    unsigned int nBinaryDigits = 0;
    char* szBinaryNum;
    printf("Input an unsigned integer number\r\n");
    scanf("%lld", &uDecNumber);
    if (uDecNumber < 0 || uDecNumber > UINT32_MAX)
    {
        printf("Incorrect number format\r\n");
        getchar();
        getc(stdin);
        return 0;
    }
    uTempVal = uDecNumber;
    while (uTempVal > 0)
    {
        nBinaryDigits++;
        uTempVal /= 2;
    }
    if (nBinaryDigits > 0)
    {
        uTempVal = uDecNumber;
        szBinaryNum = (char*)calloc(nBinaryDigits + 1, sizeof(char));
        if (szBinaryNum == NULL) return -1;
        _strset(szBinaryNum, 0);
        for (unsigned int i = 0; i < nBinaryDigits; i++)
        {
            int nBinDigit = uTempVal % 2;
            char chBinDighit = '0' + nBinDigit;
            szBinaryNum[nBinaryDigits - 1 - i] = chBinDighit;
            uTempVal /= 2;
        }
        printf
        (
        	"The binary equivalent of the decimal numner %lld is %s\r\n",
            uDecNumber,szBinaryNum
        );
        free(szBinaryNum);
    }
    else
    {
        char szBinaryNum[] = "0";
        printf
        (
        	"The binary equivalent of the decimal number %lld is %s\r\n",
            uDecNumber,szBinaryNum
        );
    }
    getchar();
    getc(stdin);
    return 0;
}