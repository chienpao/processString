//
//  main.c
//  StringSkill
//
//  Created by Chien-Pao Chueh on 1/11/15.
//  Copyright (c) 2015 Chien-Pao Chueh. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int myAtoi(char *str)
{
    int flag = 0;
    int res = 0; // Initialize result
    if (str[0]== '-') {
        printf("-\n");
        flag = 1;
        for (int i = 1; str[i] != '\0'; i++){
            if(str[i] >= 'a' && str[i] <='z')
                continue;
            res = res*10 + str[i] - '0';
        }
    }else{
    // Iterate through all characters of input string and update result
    for (int i = 0; str[i] != '\0'; i++){
    res = res*10 + str[i] - '0';
    }
    }
    if (flag) {
        res = -res;
    }
    
    // return result.
    return res;
}

void reverse(char str[], int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        //swap(*(str+start), *(str+end));
        start++;
        end--;
    }
}

char* myItoa(int num, char* str, int base)
{
    int i = 0;
    int isNegative = 0;//false
    
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    
    // In standard itoa(), negative numbers are handled only with
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = 1;
        num = -num;
    }
    
    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
    
    // If number is negative, append '-'
    if (isNegative)
    str[i++] = '-';
    
    str[i] = '\0'; // Append string terminator
    
    // Reverse the string
    reverse(str, i);
    
    return str;
}

void myReverse(){
    //要memory
    char str[] = "abcdefg";
    char *a, *b, c;
    a = b = str;
    
    while (*b)
    b++;
    
    --b;
    
    while (b > a) {
        c = *a;
        *a++ = *b;
        *b-- = c;
    }
    
    printf("%s\n", str);
}

int main(int argc, const char * argv[]) {

    char *str = "-A331acxz2123\0";
    int temp;
    temp = myAtoi(str);
    printf("myAtoi=%d\n", temp);
    
    int test = 4;
    char *ptr = NULL;
    //myItoa(test, ptr, 10);
    //printf("ptr=%s\n", ptr);
    
    //char *str2 = "456";
    //myReverse();
    
    return 0;
}
