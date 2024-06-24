// Return size of Longest Bst in Binary Tree

class NodeData{
    public:
    int size;
    int maxVal;
    int minVal;
    bool validBst;
    NodeData(int size,int max,int min,bool valid){
        this->size=size;
        maxVal=max;
        minVal=min;
        validBst=valid;
    }
};
NodeData solve(Node* root,int& ans){
    if(root==NULL){
        NodeData tmp(0,INT_MIN,INT_MAX,true);
        return true;
    }
    NodeData leftAns=solve(root->left,ans);
    NodeData rightAns=solve(root->right,ans);

    NodeData currAns;
    currAns.size=leftAns.size+rightAns.size+1;
    currAns.maxVal=max(root->data,rightAns.maxVal);
    currAns.minVal=min(root->data,leftAns.minVal);

    if(leftAns.validBst && rightAns.validBst && (root->data>leftAns.maxVal && root->data<rightAns.minVal)){
        currAns.validBst=true;
    }else{
        currAns.validBst=false;
    }
    if(currAns.validBst){
    ans=max(ans,currAns.size);
    }
    return currAns;
}