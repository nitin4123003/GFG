#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct word
{
    char *str;
    int index;
};

struct dupArray
{
    struct word* array;
    int size;
};

struct dupArray* createDupArray(char *words[],int size)
{
    //printf("%d",size);
    struct dupArray* wordArray=(struct dupArray*) malloc(sizeof(struct dupArray));
    wordArray->size=size;
    wordArray->array=(struct word*)malloc(size*sizeof(struct word));

    //Copy words from words array to dupArray
    int i;
    for(i=0;i<size;i++)
    {
        wordArray->array[i].index=i;
        wordArray->array[i].str=(char*)malloc(strlen(words[i])+1);
        strcpy(wordArray->array[i].str,words[i]);
    }

    return wordArray;
}

int compChar(const void* a,const void* b)
{
    return (*(char*)a - *(char*)b);
}

int compWord(const void* a,const void* b)
{
    struct word* a1=(struct word*)a;
    struct word* b1=(struct word*)b;
    return strcmp(a1->str,b1->str);
}

void printAnagrams(char* words[],int size)
{
    //Step1:Create a duplicate array of words
    struct dupArray* wordArray=createDupArray(words,size);
    int i;

    //Step2:Sort characters within words
    //printf("%d",wordArray->size);
    for(i=0;i<wordArray->size;i++)
    {
        qsort(wordArray->array[i].str,strlen(wordArray->array[i].str),sizeof(char),compChar);
    }

    //Step3:Sort words in the array
    qsort(wordArray->array,size,sizeof(wordArray->array[0]),compWord);

    //Step4:Now print all the anagrams together using their indexes in the sorted array
    for(i=0;i<size;i++)
    printf("%s  ",words[wordArray->array[i].index]);
}

int main()
{
    char* words[]={"cat", "dog", "tac", "god", "act"};
    int size=sizeof(words)/sizeof(words[0]);
    printAnagrams(words,size);
    return 0;
}
