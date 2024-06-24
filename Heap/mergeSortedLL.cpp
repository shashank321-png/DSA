// Merge K sorted Linked List
class compare{
    public:
    bool operator()(Node* a,Node* b){
        return a->data>b->data;
    }
};
Node* mergeKSortedLL(vector<Node*>& list ){
    priority_queue<Node*,vector<Node*>, compare> pq;

    int k=list.size();
    if(k==0){
        return NULL;
    }
    for(int i=0;i<k;i++){
        if(list[i]!=NULL){
            pq.push(list[i]);
        }
    }
    Node* head=NULL;
    Node* tail=NULL;
    while(!pq.empty()){
        Node* tmp=pq.top();
        pq.pop();

        if(head==NULL){
            head=tmp;
            tail=tmp;
            if(tail->next1=NULL){
                pq.push(tail->next);
            }
        }else{
            tail->next=tmp;
            tail=tmp;
            if(tail->next!=NULL){
                pq.push(tail->next);
            }
        }
    }
    return head;
}