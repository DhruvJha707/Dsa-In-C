// length of longest palindrome 

#include <stdio.h>
#include <string.h>

int longestPalindrome(char s[]) {
    int freq[128] = {0};
    int len = strlen(s);
    int length = 0;

    for(int i = 0; i < len; i++)
        freq[s[i]]++;

    int odd = 0;

    for(int i = 0; i < 128; i++) {
        if(freq[i] % 2 == 0)
            length += freq[i];
        else {
            length += freq[i] - 1;
            odd = 1;
        }
    }

    if(odd)
        length++;

    return length;
}

int main() {
    char str[] = "abccccdd";

    printf("Length of Longest Palindrome: %d", longestPalindrome(str));

    return 0;
}