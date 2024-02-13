/* Write a cross-refgerence that prints a list of all words in a document and, for each word, a list of the line numbers on which ir occurs. Remove noise words like "the", "and" and so on */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXWORD 100

struct linkList {
  int lnum;
  struct linkList *ptr;
};

struct tnode *addTreex(struct tnode *, char *, int);
void treexPrint(struct tnode *);
int getWord(char *, int);
int noiseWord(char *);

struct tnode{
  char *word;
  struct linkList *lines;
  struct tnode *left;
  struct tnode *right;
};

int main ()
{
  struct tnode *root;
  char word[MAXWORD];
  int lineNum = 1;

  root = NULL;
  while (getWord(word, MAXWORD) != EOF)
    if(isalpha(word[0]) && noiseWord(word) == -1)
      root = addTreex(root, word, lineNum);
    else if (word[0] == '\n') {
      lineNum++;
    } 
  treexPrint(root);
  return 0;
}

struct tnode *talloc(void);
struct linkList *lalloc(void);
void addln(struct tnode *, int);

struct tnode *addTreex(struct tnode *p, char *w, int lineNum){
  int cond;

  if (p == NULL) {
    p = talloc();
    p->word = strdup(w);
    p->lines = lalloc();
    p->lines->lnum = lineNum;
    p->lines->ptr = NULL;
    p->left = p->right = NULL;
  }
  else if ((cond = strcmp(w, p->word)) == 0)
    addln(p, lineNum);
  else if(cond < 0)
      p->left = addTreex(p->left, w, lineNum);
  else 
    p->right = addTreex(p->right, w, lineNum);
  return p;
}

void addln(struct tnode *p, int lineNum){
  struct linkList *temp;
  temp = p->lines;
  while (temp->ptr != NULL && temp->lnum != lineNum)
    temp = temp->ptr;
  if(temp->lnum != lineNum){
    temp->ptr = lalloc();
    temp->ptr->lnum = lineNum;
    temp->ptr->ptr = NULL;
  }
}



int getWord(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    while (isspace(c = getch()) && c != '\n')
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c))
    {
        *w = '\0';
        return c;
    }

    for (; --lim > 0; w++)
        if (!isalnum(*w = getch()))
        {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

#define BUFFSIZE 99

char buf[BUFFSIZE];
int bufp = 0;

int getch(void)
{
    // printf("%d\n", bufp);
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFFSIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}

struct tnode *talloc(void);
char *strDup(char *);

void treexPrint(struct tnode *p){
  struct linkList *temp;
  if (p != NULL){
    treexPrint(p->left);
    printf("%10s: ", p->word);
    for(temp = p->lines; temp != NULL; temp = temp->ptr)
      printf("%4d ", temp->lnum);
    printf("\n");
    treexPrint(p->right);
  }
}

struct linkList *lalloc(void){
  return (struct linkList *) malloc(sizeof(struct linkList));
}

int noiseWord(char *w){
  static char *nw[] = {
    "a", "an", "and", "are", "in",
    "is", "of", "or", "that", "the",
    "this", "to"
  };
  int cond, mid;
  int low = 0;
  int high = sizeof(nw) / sizeof(char *) - 1;
  while (low <= high){
    mid = (low + high) / 2;
    if((cond = strcmp(w, nw[mid]) < 0))
      high = mid - 1;
    else if (cond > 0)
      low = mid + 1;
    else 
      return mid;
  }
  return -1;
}

#include <stdlib.h>

struct tnode *talloc(void){
  return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strDup(char *s){
  char *p;

  p = (char *) malloc(strlen(s)+1);
  if(p != NULL)
    strcpy(p, s);
  return p;
}
