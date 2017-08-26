#include<stdio.h>
#include<stdlib.h>

#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])

#define CHAR_TO_INDEX(c) ((int)c-(int)'a')

typedef struct trie_node trie_node_t;

struct trie_node
{
    int value;
    trie_node_t *children[26];
};

typedef struct trie trie_t;
struct trie
{
    int count;
    trie_node_t *root;
};

trie_node_t* getNode()
{
	trie_node_t *nd=(trie_node_t*)malloc(sizeof(trie_node_t));

	if(nd)
	{
		int i;

		nd->value=0;

		for(i=0;i<26;i++)
			nd->children[i]=NULL;
	}

	return nd;
}

void insert(trie_t *pTrie,char key[])
{
	int level;
	int length=strlen(key);
	int index;

	trie_node_t *pCrawl;

	pTrie->count++;
	pCrawl=pTrie->root;

	for(level=0;level<length;level++)
	{
		index=CHAR_TO_INDEX(key[level]);

		if(!pCrawl->children[index])
			pCrawl->children[index]=getNode();
		pCrawl=pCrawl->children[index];
	}

	pCrawl->value=pTrie->count;
}

int search(trie_t *pTrie,char key[])
{
	int level;
	int index;
	int length=strlen(key);
	trie_node_t *pCrawl;

	pCrawl=pTrie->root;

	for(level=0;level<length;level++)
	{
		index=CHAR_TO_INDEX(key[level]);

		if(!pCrawl->children[index])
			return 0;

		pCrawl=pCrawl->children[index];
	}

	return(pCrawl!=0 && pCrawl->value);
}

void initialize(trie_t *pTrie)
{
	pTrie->root=getNode();
	pTrie->count=0;
}

int main()
{
	char keys[][32]={"the", "a", "there", "answer", "any", "by", "bye", "their"};
    trie_t trie;

    char output[][32] = {"Not present in trie", "Present in trie"};

    initialize(&trie);
    int i;
    for(i = 0; i < ARRAY_SIZE(keys); i++)
    insert(&trie, keys[i]);

	printf("%s --- %s\n", "the", output[search(&trie, "the")] );
    printf("%s --- %s\n", "these", output[search(&trie, "these")] );
    printf("%s --- %s\n", "their", output[search(&trie, "their")] );
    printf("%s --- %s\n", "thaw", output[search(&trie, "thaw")] );
}
