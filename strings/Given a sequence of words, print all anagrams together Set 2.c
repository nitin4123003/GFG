#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct indexNode
{
    int index;
    struct indexNode *next;
};

struct trieNode
{
    int isEnd;
    struct indexNode *head;
    char child[26];
};

struct trieNode* newTrieNode()
{
    struct trieNode *nd=(struct trieNode*)malloc(sizeof(struct trieNode));
    nd->isEnd=0;
    int i;
    for(i=0;i<26;i++)
        nd->child[i]=NULL;
    nd->head=NULL;
    return nd;
};

struct indexNode* newIndexNode(int index)
{
    struct indexNode* nd=(struct indexNode*)malloc(sizeof(struct indexNode));
    nd->index=index;
    nd->next=NULL;
    return nd;
};

int compare(const void *a,const void *b)
{
    return (*(char*)a-*(char*)b);
}

void insert(struct trieNode **root,char *word,int index)
{
    if(*root==NULL)
    *root=newTrieNode();

    if(*word!='\0')
        insert(&((*root)->child[tolower(*word)-'a']),word+1,index);
    else
    {
        if((*root)->isEnd)
        {
            struct indexNode *pCrawl=(*root)->head;
            while(pCrawl->next)
                pCrawl=pCrawl->next;
            pCrawl->next=newIndexNode(index);
        }
        else
        {
            (*root)->isEnd=1;
            (*root)->head=newIndexNode(index);
        }
    }
}

void printAnagramsUtil(struct trieNode *root,char *wordArr[])
{
    if(root==NULL)
        return;

    if(root->isEnd)//if the root contains a word
    {
        struct indexNode *pCrawl=root->head;
        while(pCrawl!=NULL)
        {
            printf("%s\n",wordArr[pCrawl->index]);
            pCrawl=pCrawl->next;
        }
    }
    int i;
    for(i=0;i<26;i++)
        printAnagramsUtil(root->child[i],wordArr);
}

void printAnagramsTogether(char *wordArr[],int size)
{
    struct trieNode *root=NULL;
    int i,j;
    for(i=0;i<size;i++)
    {
        int len=strlen(wordArr[i]);
        char *buffer=(char*)malloc((len)*sizeof(char));
        for(j=0;j<len;j++)
            buffer[j]=wordArr[i][j];

        qsort((void*)buffer,strlen(buffer),sizeof(char),compare);
        printf("%s\n",buffer);
        insert(&root,buffer,i);
    }

    //printAnagramsUtil(root,wordArr);
}

int main()
{
    char* wordArr[] = {"cat", "dog", "tac", "god", "act", "gdo"};
    int size = sizeof(wordArr) / sizeof(wordArr[0]);
    printAnagramsTogether(wordArr, size);
    return 0;
}
