#include <bits/stdc++.h>
using namespace std;

struct node {
    int x;
    int y;
    node* ptr;
};

node* head = NULL;

void AddFirst(int a, int b) {
    node* temp;
    temp = new node();
    temp->ptr = NULL;
    temp->x = a;
    temp->y = b;
    if(head != NULL) {
        temp->ptr = head;
        head = temp;
    }
    else head = temp;
}

void DelFirst() {
    if(head == NULL) cout<<"-1"<<endl;
    else {
        node* temp;
        temp = head;
        head = temp->ptr;
        free(temp);
    }
}

void Del(int a, int b) {
    node* temp = head;
    node* prev = NULL;
    while(temp != NULL) {
        if(temp->x == a && temp->y == b && prev != NULL) {
            prev->ptr = temp->ptr;
            free(temp);
            break;
        }
        else if(temp->x == a && temp->y == b && prev == NULL) {
            DelFirst();
            break;
        }
        else {
            prev = temp;
            temp = temp->ptr;
        }
    }
    if(temp == NULL) cout<<"-1"<<endl;
}

void Search(float d) {
    node* temp;
    temp = head;
    int i = 0;
    while(temp != NULL) {
        float a, b;
        a = temp->x;
        b = temp->y;
        if(a*a + b*b <= d*d) i++;
        temp = temp->ptr;
    }
    if(i) cout<<i<<endl;
    else cout<<"-1"<<endl;
}

void Search(int a, int b) {
    node* temp;
    temp = head;
    int n=0;
    while(temp != NULL) {
        if(temp->x == a && temp->y == b) n++;
        temp = temp->ptr;
    }
    if(n) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}

void Length() {
    node* temp;
    temp = head;
    int n=0;
    while(temp != NULL) {
        n++;
        temp = temp->ptr;
    }
    cout<<n<<endl;
}

int main() {
    int t, n, a, b;
    cin>>t;
    while(t--) {
        cin>>n;
        if(n == 1) {
            cin>>a>>b;
            AddFirst(a, b);
        }
        if(n == 2) {
            DelFirst();
        }
        if(n == 3) {
            cin>>a>>b;
            Del(a, b);
        }
        if(n == 4) {
            float d;
            cin>>d;
            Search(d);
        }
        if(n == 5) {
            cin>>a>>b;
            Search(a, b);
        }
        if(n == 6) {
            Length();
        }
    }    
    return 0;
}
