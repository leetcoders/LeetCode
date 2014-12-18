/*
 Author:     King, wangjingui@outlook.com
 Date:       Dec 17, 2014
 Problem:    Implement strStr()
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/implement-strstr/
 Notes:
 Implement strStr().
 Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.

 Solution: 1. Check in the haystack one by one. If not equal to needle, reset the pointer.(TLE)
           2. Classice KMP solution.
           3. Simplified RK Soluiton. Thanks for [wenyuanhust, wenyuanhust@gmail.com]
 */
class Solution {
public:
    int strStr_1(char *haystack, char *needle) {
        int sLen = strlen(haystack);
        const int tLen = strlen(needle);
        if (tLen == 0) return 0;
        if(haystack==NULL || needle==NULL || sLen==0) return -1;
        int i = 0, j =0;
        while (i < sLen) {
            j = 0;
            int k = i;
            while (j < tLen && haystack[k] == needle[j]) {
                ++k, ++j;
            }
            if (j == tLen) return k - j;
            ++i;
        }
        return -1;
    }
    void getNext(char * T, int next[], int n){
        int i=0, j=-1;
        next[0]=-1;
        while(i<n){
            while(j>-1&&T[j]!=T[i]) j = next[j];
            i++,j++;
            if(T[j]==T[i]) next[i]=next[j];
            else next[i]=j;
        }
    }
    int strStr_2(char *haystack, char *needle) {
        int sLen = strlen(haystack);
        const int tLen = strlen(needle);
        if (tLen == 0) return 0;
        if(haystack==NULL || needle==NULL || sLen==0) return -1;
        
        int next[tLen+1];
        getNext(needle,next,tLen);
        
        int i=0, j=0;
        while(i<sLen){
            while(j>-1&&needle[j]!=haystack[i]) j = next[j];
            i++,j++;
            if(j==tLen){
                return i - j;
            }
        }
        return -1;
    }
    int strStr_3(char *haystack, char *needle) {
        if (needle && *needle == '\0') return 0;
        if (haystack == NULL || needle == NULL || *haystack == '\0') return -1;
        long long fh = 0, fn = 0;
        char *n = needle, *tail = haystack, *head = haystack;
        while (*n) {
            if (*tail == '0') return -1;
            fh += *tail;
            fn += *n;
            ++n, ++tail;
        }
        --tail;
        while (*tail) {
            if (fn == fh) {
                char *pTemp = head,*nTemp = needle;
                while (*nTemp && *nTemp == *pTemp) {
                    ++nTemp; ++pTemp;
                }
                if (*nTemp == '\0') return head - haystack;
            }
            fh -= *head;
            ++tail;
            ++head;
            fh += *tail;
        }
        return -1;
    }
};