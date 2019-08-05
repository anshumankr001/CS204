#include <bits/stdc++.h>
using namespace std;

struct node {
    int x;
    int y;
    struct node* ptr;
};

void AddFirst(int a, int b, struct node** head) {
    struct node* temp;
    temp = new node();
    temp->ptr = NULL;
    temp->x = a;
    temp->y = b;
    if(*head != NULL) {
        temp->ptr = *head;
        *head = temp;
    }
    else *head = temp;
}

void DelFirst(struct node** head) {
    if(*head == NULL) cout<<"-1"<<endl;
    else {
        struct node* temp;
        temp = *head;
        *head = temp->ptr;
        free(temp);
    }
}

void Del(int a, int b, struct node** head) {
    struct node* temp = *head;
    struct node* prev = NULL;
    while(temp != NULL) {
        if(temp->x == a && temp->y == b && prev != NULL) {
            prev->ptr = temp->ptr;
            free(temp);
            break;
        }
        else if(temp->x == a && temp->y == b && prev == NULL) {
            DelFirst(head);
            break;
        }
        else {
            prev = temp;
            temp = temp->ptr;
        }
    }
    if(temp == NULL) cout<<"-1"<<endl;
}

void Search(float d, struct node** head) {
    struct node* temp;
    temp = *head;
    while(temp != NULL) {
        float a, b;
        a = temp->x;
        b = temp->y;
        if(a*a + b*b <= d*d) {
            cout<<"("<<a<<","<<b<<")"<<" ";
        }
        temp = temp->ptr;
    } cout<<endl;
}

void Search(int a, int b, struct node** head) {
    struct node* temp;
    temp = *head;
    int n=0;
    while(temp != NULL) {
        if(temp->x == a && temp->y == b) n++;
        temp = temp->ptr;
    }
    if(n) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}

void Length(struct node** head) {
    struct node* temp;
    temp = *head;
    int n=0;
    while(temp != NULL) {
        n++;
        temp = temp->ptr;
    }
    cout<<n<<endl;
}

int main() {
    int t, n, a, b;
    struct node* head;
    head = NULL;
    cin>>t;
    while(t--) {
        cin>>n;
        if(n == 1) {
            cin>>a>>b;
            AddFirst(a, b, &head);
        }
        if(n == 2) {
            DelFirst(&head);
        }
        if(n == 3) {
            cin>>a>>b;
            Del(a, b, &head);
        }
        if(n == 4) {
            float d;
            cin>>d;
            Search(d, &head);
        }
        if(n == 5) {
            cin>>a>>b;
            Search(a, b, &head);
        }
        if(n == 6) {
            Length(&head);
        }
    }    
    return 0;
}
