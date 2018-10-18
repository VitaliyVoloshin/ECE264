//=============================================================================
//== FILENAME:          "october_18.c"
//== WRITTEN BY:        Andrew St. Pierre
//== LAST MODIFIED:     18/10/2018 14:03:32
//=============================================================================

//===========================
//== Linked Lists
//===========================
// Inserting at the beginning of linked list
// Option 1:
Node * List_insert(Node * h, int v)
{
    // ...
}

Node * head = NULL;
head = List_insert(head,264);
// Option 2:
void List_insert(Node ** h, int v)
{
    Node * p = malloc();
    p->next = *h;
    *h=p;
}
Node * head = NULL;
List_insert(&head,264);

// Insert at end of linked list
Node * List_insert2(Node * h, int n)
{
    Node * p = malloc();
    p->value = v;
    p->next = NULL;

    // If empty...
    if(h==NULL) return p;
    Node * q = h;
    
    // Traversing the linked list
    while((q->next) != NULL) q = q->next;
    
    // q is the last node now
    q->next = p;

    // Return the head
    return h;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Inserting in a sorted linked list
if((v<(h->value))) // New node at beginning
{
    p->next = h;
    return p;
}
Node * r = h->next;
while((r != NULL) && ((r->value)<v)) 
{  r = r->next; q = q->next  }
// q is the node before p
q->next = p;
p->next = r;
return h;

// Searching a linked list
Node * List_search(Node * h, v)
{
    // Search the list for value v
    // If found, return the pointer of the node
    // If not, return NULL
    // If u appears multiple times, return the first

    // Note: h is a second node pointer that does not change head
    //       only changes the pointer location of h
    while((h != NULL) && ((h->value) != v)) h=h->next;

    return h;
}

// How are we going to use this? 
Node * head = NULL;
Node * p;
// By creating another pointer p, you will not lose the list
p = List_search(head, 264);

// How about deleting from a Linked List?
Node * List_delete(Node * h, v)
{
    // If noting in list, do nothing, return
    if(h == NULL) return NULL;

    // If the node is the very first node case
    if((h->value) == v)
    {  Node * p = h->next; free(h); return p;  }

    // Normal case
    Node * q = h;
    Node * r = h->next;

    // Traversing
    while((r != NULL) && ((r->value) != v))
    {
        q = q->next;
        r = r->next;
    }

    if(r == NULL) return h;

    // Order is important here
    // will get segmentation fault
    q->next = r->next;
    free(r);

    return h;
}







    


    return;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
