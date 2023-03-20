#include <stdio.h>
#include <stdlib.h>

typedef struct s_NODE{
    struct s_NODE *pre, *nxt;
    char ch;
}   t_NODE;

int main()
{
    char str[100001];
    int n;
    char cmd;
    char text_ch;
    t_NODE *cur;
    t_NODE *head;
    t_NODE *new_node;
	t_NODE *tmp_NODE;

    scanf("%s", str);
    getchar();
    scanf("%d", &n);
    getchar();
    
	if(!(new_node = (t_NODE *)malloc(sizeof(t_NODE))))
		return (1);
	cur = new_node;

	cur->pre = 0;
	cur->nxt = 0;
	cur->ch = 0;
	head = cur;
	
    unsigned int i = 0;
    while(str[i])
    {
        if(!(new_node = (t_NODE *)malloc(sizeof(t_NODE))))
            return (1);
        new_node->ch = str[i];
        
		cur->nxt = new_node;
		new_node->pre = cur;
		new_node->nxt = 0;
        cur = new_node;
        i++;
    }
    while(n--)
    {
        scanf("%c", &cmd);
        getchar();
        if(cmd == 'P')
        {
            scanf("%c", &text_ch);
            getchar();
            if(!(new_node = (t_NODE *)malloc(sizeof(t_NODE))))
                return (1);
            new_node->ch = text_ch;
			tmp_NODE = cur->nxt;
			cur->nxt = new_node;
			new_node->pre = cur;
			new_node->nxt = tmp_NODE;
            if(tmp_NODE != 0)
				tmp_NODE->pre = new_node;
			cur = new_node;      
        }
        else if(cmd == 'L')
        {
            if(cur != head)
                cur = cur->pre;
        }
        else if(cmd == 'D')
        {
            if(cur->nxt != 0)
                cur = cur->nxt;
        }
        else if(cmd == 'B')
        {
			if(cur != head)
			{
				tmp_NODE = cur;
				cur->pre->nxt = cur->nxt;
				if(cur->nxt != 0)
					cur->nxt->pre = cur->pre;
				cur = cur->pre;
				free(tmp_NODE);
			}
        }
    }
	cur = head->nxt;
    while(cur)
    {
        printf("%c", cur->ch);
        cur = cur->nxt;
    }
}
