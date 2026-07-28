#include <stdio.h>

int compress(char* chars, int charsSize)
 {
    int writeIdx = 0;
    int readIdx = 0;
    
    while (readIdx < charsSize)
     {
        char currentChar = chars[readIdx];
        int count = 0;
        
        while (readIdx < charsSize && chars[readIdx] == currentChar)
         {
            readIdx++;
            count++;
        }
        
        chars[writeIdx++] = currentChar;
        
        if (count > 1)
         {
            char digits[10];
            int numDigits = 0;
            
            while (count > 0) {
                digits[numDigits++] = (count % 10) + '0';
                count /= 10;
            }
            
            for (int i = numDigits - 1; i >= 0; i--)
             {
                chars[writeIdx++] = digits[i];
            }
        }
    }
    
    return writeIdx;
}