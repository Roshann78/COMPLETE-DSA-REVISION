class MyLinkedList {
public:
    struct Node{
        int val;
        Node*next;
        Node(int x){
            val=x;
            next=nullptr;
        }
    };
    Node*head;
    int sz;
    MyLinkedList() {
        head=nullptr;
        sz=0;
    }
    
    int get(int index) {
        Node*temp=head;
        if(index<0 || index>=sz){
            return -1;
        }
        for(int i=0;i<index;i++){
            temp=temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node*temp=new Node(val);
        temp->next=head;
        head=temp;
        sz++;
    }
    
    void addAtTail(int val) {
        Node*temp=head;
        if(!head){
            head=new Node(val);
            sz++;
            return;
        }
        while(temp->next){
            temp=temp->next;
        }
        temp->next=new Node(val);
        sz++;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 || index>sz){
            return;
        }
        if(index==0){
            addAtHead(val);
            return ;
        }
        if(index==sz){
            addAtTail(val);
            return;
        }
        Node*temp=head;
        for(int i=0;i<index-1;i++){
            temp=temp->next;
        }
        Node*temp1=temp->next;
        temp->next=new Node(val);
        temp=temp->next;
        temp->next=temp1;
        sz++;
    }
    
    void deleteAtIndex(int index) {
        if(!sz){
            return;
        }
        if(index<0 || index>=sz){
            return;
        }
        if(index==0){
            head=head->next;
            sz--;
            return;
        }
        Node*temp=head;
        for(int i=0;i<index-1;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        sz--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */